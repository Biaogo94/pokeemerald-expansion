# -*- coding: utf-8 -*-
"""Tests for the Heart & Soul HGSS alignment engine.

Covers the three hard requirements of Task 2:
  (a) skeleton normalization strips whitespace, ``\\n``, ``\\l``, ``\\p`` and ``$``;
  (b) exact-match alignment against the dialogue dataset;
  (c) base-dictionary term substitution (POKéMON -> 宝可梦, POKé BALL -> 精灵球).

Plus the global invariants of the pipeline: placeholders (``{PLAYER}``,
``{RIVAL}``, ``{STR_VAR_1}``, ``{KUN}``, ...), the ``$`` terminator and the
``\\p`` page breaks in the source must survive into the translation.  Line
breaks (``\\n`` / ``\\l``) are layout only and may be re-flowed -- see
``TestControlCodePreservation``.
"""

import json
import os
import unittest

from tools.i18n.aligner import (
    ALIGNED_CORPUS_PATH,
    AlignerEngine,
    AlignmentResult,
    BASE_DICT_PATH,
    RAW_CORPUS_PATH,
    UNMATCHED_CORPUS_PATH,
    extract_placeholders,
    find_terms,
    load_base_dict,
    normalize_skeleton,
    repair_terminator,
    substitute_terms,
    validate_control_codes_preserved,
    validate_placeholders_preserved,
)

NL = "\\n"
LP = "\\p"
LL = "\\l"
END = "$"


class TestSkeletonNormalization(unittest.TestCase):
    """(a) skeleton normalization strips whitespace and control codes."""

    def test_strips_control_codes_and_terminator(self):
        text = "Hello!" + NL + "Welcome to the world" + LP + "of POKéMON!" + END
        self.assertEqual(normalize_skeleton(text), "hello!welcometotheworldofpokémon!")

    def test_strips_line_scroll_code(self):
        self.assertEqual(normalize_skeleton("abc" + LL + "def" + END), "abcdef")

    def test_strips_whitespace_tabs_and_terminator(self):
        text = "  ELM:   {PLAYER}!  " + LP + " There you are! " + END + " "
        self.assertEqual(normalize_skeleton(text), "elm:{player}!thereyouare!")

    def test_bare_terminator_is_empty(self):
        self.assertEqual(normalize_skeleton(END), "")
        self.assertEqual(normalize_skeleton("  " + NL + " "), "")

    def test_case_insensitive(self):
        self.assertEqual(normalize_skeleton("POKéMON"), normalize_skeleton("pokémon"))

    def test_placeholders_survive_normalization(self):
        skeleton = normalize_skeleton("{PLAYER} got {STR_VAR_1}!")
        self.assertIn("{player}", skeleton)
        self.assertIn("{str_var_1}", skeleton)


class TestPlaceholderExtraction(unittest.TestCase):
    def test_extract_in_order(self):
        text = "Hello {PLAYER}! Are you {STR_VAR_1} with {KUN}?"
        self.assertEqual(extract_placeholders(text), ["{PLAYER}", "{STR_VAR_1}", "{KUN}"])

    def test_extract_none(self):
        self.assertEqual(extract_placeholders("plain text"), [])

    def test_extract_with_spaces_inside_braces(self):
        text = "{COLOR DARK_GRAY}hi{CLEAR_TO 0x58}{PAUSE 0x0F}"
        self.assertEqual(
            extract_placeholders(text),
            ["{COLOR DARK_GRAY}", "{CLEAR_TO 0x58}", "{PAUSE 0x0F}"],
        )

    def test_validate_rejects_missing_placeholder(self):
        src = "Hello {PLAYER}! You have {STR_VAR_1}."
        self.assertTrue(validate_placeholders_preserved(src, "你好，{PLAYER}！你有{STR_VAR_1}。"))
        self.assertFalse(validate_placeholders_preserved(src, "你好，{PLAYER}！你有了。"))

    def test_validate_rejects_extra_placeholder(self):
        src = "Hello {PLAYER}! You have {STR_VAR_1}."
        trans = "你好，{PLAYER}！{RIVAL}在这里，你有{STR_VAR_1}。"
        self.assertFalse(validate_placeholders_preserved(src, trans))

    def test_validate_rejects_duplicate_mismatch(self):
        self.assertFalse(
            validate_placeholders_preserved("{PLAYER} and {PLAYER}", "{PLAYER}来了")
        )


class TestControlCodePreservation(unittest.TestCase):
    def test_valid_translation_passes(self):
        src = "ELM: Wait!" + NL + "Where are you going?" + END
        trans = "空木：等等！" + NL + "你要去哪里？" + END
        self.assertTrue(validate_control_codes_preserved(src, trans))

    def test_missing_terminator_fails(self):
        src = "ELM: This?" + END
        self.assertFalse(validate_control_codes_preserved(src, "空木：这个？"))

    def test_missing_paragraph_break_fails(self):
        src = "A" + LP + "B" + END
        self.assertFalse(validate_control_codes_preserved(src, "甲乙" + END))

    def test_extra_paragraph_break_fails(self):
        src = "A" + END
        self.assertFalse(validate_control_codes_preserved(src, "甲" + LP + "乙" + END))

    def test_line_breaks_are_layout_only_by_default(self):
        # Chinese wraps differently from English: a re-flow is not corruption.
        src = "abc" + NL + "def" + END
        self.assertTrue(validate_control_codes_preserved(src, "甲乙丙丁" + END))
        self.assertTrue(validate_control_codes_preserved(src, "甲乙" + LL + "丙丁" + END))
        # ...but dropping the terminator or a page break never is.
        self.assertFalse(validate_control_codes_preserved(src, "甲乙丙丁"))
        self.assertFalse(validate_control_codes_preserved("A" + LP + "B" + END, "甲乙" + END))

    def test_strict_line_breaks_audit_mode(self):
        src = "abc" + NL + "def" + END
        self.assertTrue(
            validate_control_codes_preserved(src, "甲乙" + NL + "丙丁" + END, strict_line_breaks=True)
        )
        self.assertFalse(
            validate_control_codes_preserved(src, "甲乙丙丁" + END, strict_line_breaks=True)
        )
        self.assertFalse(
            validate_control_codes_preserved(src, "甲乙" + LL + "丙丁" + END, strict_line_breaks=True)
        )

    def test_missing_placeholder_fails_control_check(self):
        src = "{PLAYER} got it!" + END
        self.assertFalse(validate_control_codes_preserved(src, "得到了！" + END))

    def test_repair_terminator(self):
        self.assertEqual(repair_terminator("POKé BALL" + END, "精灵球"), "精灵球" + END)
        self.assertEqual(repair_terminator("POKé BALL", "精灵球"), "精灵球")
        self.assertEqual(repair_terminator("A" + END, "甲" + END), "甲" + END)


class TestTermSubstitution(unittest.TestCase):
    """(c) base-dictionary term substitution."""

    TERMS = {
        "POKéMON": "宝可梦",
        "POKé BALL": "精灵球",
        "POTION": "伤药",
        "TACKLE": "撞击",
        "BULBASAUR": "妙蛙种子",
        "PIKACHU": "皮卡丘",
    }

    def test_substitute_whole_string(self):
        self.assertEqual(substitute_terms("POKéMON", self.TERMS), "宝可梦")
        self.assertEqual(substitute_terms("POKé BALL", self.TERMS), "精灵球")

    def test_substitute_longest_match_wins(self):
        # "POKé BALL" must win over "POKéMON"-style partial matches.
        self.assertEqual(substitute_terms("POKé BALL", self.TERMS), "精灵球")

    def test_substitute_inside_sentence(self):
        self.assertEqual(
            substitute_terms("The POKéMON used TACKLE!", self.TERMS),
            "The 宝可梦 used 撞击!",
        )

    def test_substitute_preserves_control_codes_and_placeholders(self):
        text = "{PLAYER} sent out PIKACHU!" + NL + "POKéMON" + END
        out = substitute_terms(text, self.TERMS)
        self.assertEqual(out, "{PLAYER} sent out 皮卡丘!" + NL + "宝可梦" + END)
        self.assertTrue(validate_control_codes_preserved(text, out))

    def test_substitute_does_not_touch_words(self):
        # Word-boundary aware: must not rewrite inside a larger word.
        self.assertEqual(substitute_terms("POTIONS", self.TERMS), "POTIONS")

    def test_substitute_returns_input_when_nothing_matches(self):
        self.assertEqual(substitute_terms("nothing here", self.TERMS), "nothing here")


class TestDialogueAlignment(unittest.TestCase):
    """(b) exact-match alignment against the dialogue dataset."""

    BASE = {
        "terms": {"POKéMON": "宝可梦", "POKé BALL": "精灵球"},
        "dialogues": [
            {"en": "And you are?" + END, "zh": "那么，你是？" + END},
            {
                "en": "ELM: {PLAYER}! There you are!" + LP + "I needed to ask you a favor." + END,
                "zh": "空木：{PLAYER}！你来啦！" + LP + "我有件事想拜托你。" + END,
            },
        ],
    }

    def setUp(self):
        self.engine = AlignerEngine(self.BASE)

    def test_exact_match(self):
        res = self.engine.align("And you are?" + END)
        self.assertIsNotNone(res)
        self.assertIsInstance(res, AlignmentResult)
        self.assertEqual(res.translation, "那么，你是？" + END)
        self.assertEqual(res.match_type, "exact")
        self.assertEqual(res.confidence, 1.0)

    def test_skeleton_match_ignores_line_wrapping(self):
        query = "ELM: {PLAYER}!" + NL + "There you are!" + LP + "I needed to ask you a favor." + END
        res = self.engine.align(query)
        self.assertIsNotNone(res)
        self.assertEqual(res.match_type, "dialogue_skeleton")
        self.assertEqual(
            res.translation, "空木：{PLAYER}！你来啦！" + LP + "我有件事想拜托你。" + END
        )

    def test_term_match_whole_string(self):
        res = self.engine.align("POKéMON")
        self.assertIsNotNone(res)
        self.assertEqual(res.translation, "宝可梦")
        self.assertEqual(res.match_type, "term")
        self.assertEqual(res.matched_key, "POKéMON")

    def test_term_match_is_case_insensitive(self):
        for variant in ("Pokémon", "pokémon", "POKéMON"):
            res = self.engine.align(variant)
            self.assertIsNotNone(res, variant)
            self.assertEqual(res.translation, "宝可梦")

    def test_term_match_repairs_missing_terminator(self):
        res = self.engine.align("POKé BALL" + END)
        self.assertIsNotNone(res)
        self.assertEqual(res.translation, "精灵球" + END)
        self.assertTrue(
            validate_control_codes_preserved("POKé BALL" + END, res.translation)
        )

    def test_exclamation_is_not_treated_as_bare_term(self):
        # Regression: corpus defeat lines such as "No!$", "Splash!$" and
        # "FLASH!$" are exclamations, not the menu answer or the move, so only
        # whole-string term equality may auto-align.
        engine = AlignerEngine({"terms": {"NO": "否", "SPLASH": "跃起", "FLASH": "闪光"}})
        self.assertIsNone(engine.align("No!" + END))
        self.assertIsNone(engine.align("Splash!" + END))
        self.assertIsNone(engine.align("FLASH!" + END))
        self.assertEqual(engine.align("NO" + END).translation, "否" + END)
        self.assertEqual(engine.align("Splash" + END).translation, "跃起" + END)

    def test_ambiguous_terms_are_hints_only(self):
        engine = AlignerEngine(
            {
                "terms": {"RETURN": "报恩", "CANCEL": "取消"},
                "ambiguous_terms": ["RETURN"],
            }
        )
        # "RETURN$" is the Game Corner menu command here, not the move.
        self.assertIsNone(engine.align("RETURN" + END))
        self.assertEqual(engine.lookup_term("RETURN"), "报恩")
        self.assertEqual(find_terms("RETURN" + END, engine.terms), [("RETURN", "报恩")])
        # Non-ambiguous terms are unaffected.
        self.assertEqual(engine.align("CANCEL" + END).translation, "取消" + END)

    def test_no_match_returns_none(self):
        self.assertIsNone(self.engine.align("Random unknown text$"))
        self.assertIsNone(self.engine.align(""))

    def test_placeholder_mismatch_is_rejected(self):
        # Source carries {RIVAL}; the dialogue candidate has {PLAYER}.
        res = self.engine.align(
            "ELM: {RIVAL}! There you are!" + LP + "I needed to ask you a favor." + END
        )
        self.assertIsNone(res)

    def test_dialogue_exact_takes_precedence_over_skeleton(self):
        res = self.engine.align("ELM: {PLAYER}! There you are!" + LP + "I needed to ask you a favor." + END)
        self.assertEqual(res.match_type, "exact")

    def test_engine_from_empty_dict(self):
        engine = AlignerEngine({})
        self.assertIsNone(engine.align("POKéMON"))
        self.assertEqual(engine.term_count, 0)


class TestBaseDictionaryFile(unittest.TestCase):
    """The shipped dictionary must contain real, official Chinese terms."""

    @classmethod
    def setUpClass(cls):
        cls.base = load_base_dict()
        cls.engine = AlignerEngine(cls.base)

    def test_file_exists_and_is_valid_json(self):
        self.assertTrue(os.path.exists(BASE_DICT_PATH), BASE_DICT_PATH)
        with open(BASE_DICT_PATH, "r", encoding="utf-8") as fp:
            json.load(fp)

    def test_section_sizes(self):
        self.assertGreaterEqual(len(self.base["species"]), 30)
        self.assertGreaterEqual(len(self.base["moves"]), 20)
        self.assertGreaterEqual(len(self.base["items"]), 20)
        self.assertGreaterEqual(len(self.base["game_terms"]), 10)
        self.assertGreaterEqual(len(self.base["dialogues"]), 10)

    def test_spot_check_official_terminology(self):
        expectations = {
            "BULBASAUR": "妙蛙种子",
            "CHIKORITA": "菊草叶",
            "CYNDAQUIL": "火球鼠",
            "TOTODILE": "小锯鳄",
            "PIKACHU": "皮卡丘",
            "TACKLE": "撞击",
            "EMBER": "火花",
            "POTION": "伤药",
            "POKé BALL": "精灵球",
            "POKéMON": "宝可梦",
            "POKéDEX": "宝可梦图鉴",
        }
        for key, expected in expectations.items():
            self.assertEqual(self.engine.lookup_term(key), expected, key)

    def test_dictionary_declares_ambiguous_terms(self):
        self.assertIn("RETURN", self.base["ambiguous_terms"])
        self.assertIsNone(self.engine.align("RETURN" + END))
        # A skipped term is still offered to the translation stage as a hint.
        self.assertEqual(
            find_terms("RETURN" + END, self.engine.terms), [("RETURN", "报恩")]
        )

    def test_all_terms_are_non_empty_strings(self):
        for section in ("species", "moves", "items", "abilities", "game_terms"):
            for key, value in self.base[section].items():
                self.assertTrue(key.strip(), section)
                self.assertIsInstance(value, str)
                self.assertTrue(value.strip(), f"{section}:{key}")
                # No control codes belong in a dictionary term.
                self.assertNotIn("\\", value, key)
                self.assertNotIn("$", value, key)

    def test_dialogue_entries_are_control_code_clean(self):
        for pair in self.base["dialogues"]:
            self.assertIn("en", pair)
            self.assertIn("zh", pair)
            self.assertNotIn("\n", pair["en"], pair["en"])
            self.assertNotIn("\n", pair["zh"], pair["zh"])
            self.assertTrue(pair["en"].endswith(END), pair["en"])
            self.assertTrue(pair["zh"].endswith(END), pair["zh"])
            self.assertTrue(
                pair["en"].count(LP) == pair["zh"].count(LP),
                f"paragraph break mismatch: {pair['en']!r}",
            )
            self.assertTrue(validate_placeholders_preserved(pair["en"], pair["zh"]), pair["en"])
            self.assertTrue(validate_control_codes_preserved(pair["en"], pair["zh"]), pair["en"])

    def test_dictionary_terms_never_contain_placeholders(self):
        for section in ("species", "moves", "items", "abilities", "game_terms"):
            for key, value in self.base[section].items():
                self.assertEqual(extract_placeholders(value), [], f"{section}:{key}")


class TestCorpusAlignmentIntegration(unittest.TestCase):
    """End-to-end: align the real corpus and enforce the global invariants."""

    @classmethod
    def setUpClass(cls):
        with open(RAW_CORPUS_PATH, "r", encoding="utf-8") as fp:
            cls.corpus = json.load(fp)
        cls.engine = AlignerEngine(load_base_dict())
        cls.aligned, cls.unmatched = cls.engine.align_corpus(cls.corpus)

    def test_corpus_was_loaded(self):
        # Change-detector for the extractor: update it whenever the scan roots
        # or the C macro set in ``tools/i18n/extractor.py`` change.
        self.assertEqual(len(self.corpus), 30012)

    def test_every_entry_is_accounted_for(self):
        self.assertEqual(len(self.aligned) + len(self.unmatched), len(self.corpus))

    def test_alignment_produced_matches(self):
        self.assertGreater(len(self.aligned), 0)

    def test_aligned_entries_keep_identity_and_control_codes(self):
        by_id = {e["id"]: e for e in self.corpus}
        for entry in self.aligned:
            self.assertIn("translation", entry)
            self.assertTrue(entry["translation"])
            src = by_id[entry["id"]]["source"]
            self.assertTrue(validate_placeholders_preserved(src, entry["translation"]), src)
            self.assertTrue(validate_control_codes_preserved(src, entry["translation"]), src)

    def test_unmatched_entries_are_pending_translation(self):
        for entry in self.unmatched:
            self.assertIsNone(entry.get("translation"))
            self.assertIn("source", entry)

    def test_alignment_is_deterministic(self):
        again = self.engine.align_corpus(self.corpus)
        self.assertEqual(len(again[0]), len(self.aligned))

    def test_committed_artifacts_are_in_sync_with_the_engine(self):
        """The generated corpora must match what the current engine produces.

        Task 3 translates ``unmatched_corpus.json``; a stale artifact would
        silently feed it the wrong set of strings.
        """
        with open(ALIGNED_CORPUS_PATH, "r", encoding="utf-8") as fp:
            aligned = json.load(fp)
        with open(UNMATCHED_CORPUS_PATH, "r", encoding="utf-8") as fp:
            unmatched = json.load(fp)

        self.assertEqual(len(aligned), len(self.aligned))
        self.assertEqual(len(unmatched), len(self.unmatched))
        self.assertEqual(
            {entry["id"] for entry in aligned} | {entry["id"] for entry in unmatched},
            {entry["id"] for entry in self.corpus},
        )

        for entry in aligned:
            result = self.engine.align(entry["source"])
            self.assertIsNotNone(result, entry["source"])
            self.assertEqual(result.translation, entry["translation"], entry["source"])

        for entry in unmatched:
            self.assertIsNone(self.engine.align(entry["source"]), entry["source"])


if __name__ == "__main__":
    unittest.main()
