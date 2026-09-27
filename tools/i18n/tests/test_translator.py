# -*- coding: utf-8 -*-
"""Tests for the Heart & Soul format guard and dictionary translation processor.

Task 3 turns the still-unmatched corpus strings into ``data/translated_corpus.json``.
No external LLM is available in CI, so the processor only emits what the base
dictionary can *prove* and what the format guard can *verify*; everything else
stays ``"translation": null``.

The guard is the load-bearing part of that promise.  A single dropped
``{PLAYER}``, a lost ``$`` or one extra ``\\p`` silently corrupts the ROM:

* a missing ``$`` swallows the next string in the same file;
* a missing ``\\p`` merges two text boxes into one;
* a dropped ``{STR_VAR_1}`` prints the literal placeholder at runtime.

Every rejection is therefore pinned to a stable, machine-readable error code so
the pipeline (and the report) can say *why* a string was left untranslated.
"""

import json
import os
import subprocess
import sys
import tempfile
import unittest

from tools.i18n.ai_translator import (
    BASE_DICT_PATH,
    CODE_CONTROL_CODE_MISMATCH,
    CODE_EMPTY_TRANSLATION,
    CODE_PLACEHOLDER_MISMATCH,
    CODE_TERMINATOR_COUNT_MISMATCH,
    CODE_TERMINATOR_MISSING,
    CODE_TERMINATOR_UNEXPECTED,
    CODE_TYPE_ERROR,
    CODE_UNEXPECTED_TEXT,
    DICTIONARY_CONFIDENCE,
    DictionaryTranslator,
    FREE_TEXT_UNSAFE_KEYS,
    MATCH_DICTIONARY,
    REASON_GUARD_REJECTED,
    REASON_NO_TERM,
    TranslationFormatError,
    TRANSLATED_CORPUS_PATH,
    UNMATCHED_CORPUS_PATH,
    find_terms_outside_placeholders,
    main as translator_main,
    substitute_terms_outside_placeholders,
    translate_corpus,
    validate_translation,
)

NL = "\\n"
LP = "\\p"
LL = "\\l"
END = "$"

REPO_ROOT = os.path.dirname(
    os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
)


def load_json(path):
    with open(path, "r", encoding="utf-8") as fp:
        return json.load(fp)


# ---------------------------------------------------------------------------
# 1. Format guard -- accepted translations
# ---------------------------------------------------------------------------


class TestFormatGuardAccepts(unittest.TestCase):
    """A translation that preserves every control is allowed through."""

    def test_valid_translation_passes(self):
        source = "Hello, {PLAYER}!" + LP + "Welcome to POKéMON." + NL + "Enjoy!" + END
        translation = "你好，{PLAYER}！" + LP + "欢迎来到宝可梦。" + NL + "尽情享受！" + END
        self.assertIsNone(validate_translation(source, translation))

    def test_identical_text_passes(self):
        text = "POKéMON" + NL + "CENTER" + END
        self.assertIsNone(validate_translation(text, text))

    def test_reordered_line_breaks_pass(self):
        """Chinese re-flows lines; only the *volume* of each control is fixed."""
        source = "A" + NL + "B" + LP + "C" + NL + "D" + END
        translation = "甲" + LP + "乙" + NL + "丙" + NL + "丁" + END
        self.assertIsNone(validate_translation(source, translation))

    def test_source_without_terminator_passes(self):
        """``c_source`` strings (menus, labels) carry no ``$`` -- neither may theirs."""
        source = "{STR_VAR_1} is happy but shy."
        self.assertIsNone(validate_translation(source, "{STR_VAR_1} 很开心，但很害羞。"))

    def test_placeholder_only_translation_is_not_empty(self):
        self.assertIsNone(validate_translation("{PLAYER}" + END, "{PLAYER}" + END))

    def test_repeated_placeholder_order_may_change(self):
        source = "{PLAYER} gave {RIVAL} a POKé BALL" + END
        translation = "{RIVAL} 拿到了 {PLAYER} 给的精灵球" + END
        self.assertIsNone(validate_translation(source, translation))

    def test_multiline_body_passes(self):
        source = "Line one" + NL + "line two" + LL + "line three" + LP + "para two" + END
        translation = "第一行" + NL + "第二行" + LL + "第三行" + LP + "第二段" + END
        self.assertIsNone(validate_translation(source, translation))


# ---------------------------------------------------------------------------
# 2. Format guard -- rejected translations
# ---------------------------------------------------------------------------


class TestFormatGuardRejects(unittest.TestCase):
    """Every way a translation can corrupt the source."""

    def assertRejects(self, source, translation, code):
        with self.assertRaises(TranslationFormatError) as ctx:
            validate_translation(source, translation)
        self.assertEqual(ctx.exception.code, code)
        return ctx.exception

    # -- placeholders ------------------------------------------------------

    def test_dropped_placeholder_raises(self):
        self.assertRejects(
            "Hello, {PLAYER}!" + END,
            "你好！" + END,
            CODE_PLACEHOLDER_MISMATCH,
        )

    def test_dropped_str_var_raises(self):
        self.assertRejects(
            "{STR_VAR_1} is coming along happily.",
            "{STR_VAR_2} 一路走来很开心。",
            CODE_PLACEHOLDER_MISMATCH,
        )

    def test_injected_unknown_placeholder_raises(self):
        self.assertRejects(
            "Hello, {PLAYER}!" + END,
            "你好，{PLAYER}，{RIVAL}！" + END,
            CODE_PLACEHOLDER_MISMATCH,
        )

    def test_collapsed_duplicate_placeholder_raises(self):
        self.assertRejects(
            "{PLAYER} and {PLAYER}" + END,
            "{PLAYER} 和" + END,
            CODE_PLACEHOLDER_MISMATCH,
        )

    def test_invented_kun_placeholder_raises(self):
        self.assertRejects("Yes!" + END, "是！{KUN}" + END, CODE_PLACEHOLDER_MISMATCH)

    # -- terminator --------------------------------------------------------

    def test_missing_terminator_raises(self):
        self.assertRejects("Hi!" + END, "你好！", CODE_TERMINATOR_MISSING)

    def test_unexpected_terminator_raises(self):
        self.assertRejects("Hi!", "你好！" + END, CODE_TERMINATOR_UNEXPECTED)

    def test_extra_internal_terminator_raises(self):
        """A second ``$`` truncates the string mid-text -- counts must match."""
        self.assertRejects("Hello there" + END, "你好" + END + "世界" + END, CODE_TERMINATOR_COUNT_MISMATCH)

    # -- line breaks and page breaks ---------------------------------------

    def test_paragraph_break_count_mismatch_raises(self):
        self.assertRejects("A" + LP + "B" + END, "甲乙" + END, CODE_CONTROL_CODE_MISMATCH)

    def test_extra_paragraph_break_raises(self):
        self.assertRejects("A" + END, "甲" + LP + "乙" + END, CODE_CONTROL_CODE_MISMATCH)

    def test_newline_count_mismatch_raises(self):
        self.assertRejects("A" + NL + "B" + END, "甲乙" + END, CODE_CONTROL_CODE_MISMATCH)

    def test_scroll_count_mismatch_raises(self):
        self.assertRejects("A" + LL + "B" + END, "甲乙" + END, CODE_CONTROL_CODE_MISMATCH)

    def test_scroll_cannot_stand_in_for_newline(self):
        """``\\n`` and ``\\l`` behave differently in a text box: counts are per code."""
        self.assertRejects("A" + NL + "B" + END, "甲" + LL + "乙" + END, CODE_CONTROL_CODE_MISMATCH)

    def test_page_break_replaced_by_newline_raises(self):
        """Paging changes if a ``\\p`` becomes a plain ``\\n``."""
        self.assertRejects("A" + LP + "B" + END, "甲" + NL + "乙" + END, CODE_CONTROL_CODE_MISMATCH)

    # -- emptiness ---------------------------------------------------------

    def test_empty_translation_raises(self):
        self.assertRejects("Hello" + END, END, CODE_EMPTY_TRANSLATION)

    def test_whitespace_only_translation_raises(self):
        self.assertRejects("Hello" + END, "  " + END, CODE_EMPTY_TRANSLATION)

    def test_control_only_translation_raises(self):
        self.assertRejects("Hello" + LP + "World" + END, LP + END, CODE_EMPTY_TRANSLATION)

    def test_text_for_empty_source_raises(self):
        self.assertRejects(END, "一些文字" + END, CODE_UNEXPECTED_TEXT)

    def test_empty_source_with_empty_translation_passes(self):
        self.assertIsNone(validate_translation(END, END))

    # -- bad types ---------------------------------------------------------

    def test_none_translation_raises(self):
        self.assertRejects("Hello" + END, None, CODE_TYPE_ERROR)

    def test_none_source_raises(self):
        self.assertRejects(None, "你好" + END, CODE_TYPE_ERROR)

    # -- error object ------------------------------------------------------

    def test_error_is_a_value_error_with_context(self):
        with self.assertRaises(TranslationFormatError) as ctx:
            validate_translation("Hi {PLAYER}" + END, "你好" + END)
        err = ctx.exception
        self.assertIsInstance(err, ValueError)
        self.assertEqual(err.code, CODE_PLACEHOLDER_MISMATCH)
        self.assertEqual(err.source, "Hi {PLAYER}" + END)
        self.assertEqual(err.translation, "你好" + END)
        self.assertIn(CODE_PLACEHOLDER_MISMATCH, str(err))


# ---------------------------------------------------------------------------
# 3. Dictionary substitution
# ---------------------------------------------------------------------------


class TestDictionarySubstitution(unittest.TestCase):
    """Term substitution reaches the prose but never the placeholders."""

    TERMS = {"POKé BALL": "精灵球", "POKéMON": "宝可梦", "BALL": "球"}

    def test_longest_match_wins(self):
        self.assertEqual(
            substitute_terms_outside_placeholders("A POKé BALL here" + END, self.TERMS),
            "A 精灵球 here" + END,
        )

    def test_case_insensitive_whole_word_match(self):
        self.assertEqual(
            substitute_terms_outside_placeholders("pokémon!" + END, self.TERMS),
            "宝可梦!" + END,
        )

    def test_partial_word_is_not_substituted(self):
        text = "POKéMONS!" + END
        self.assertEqual(substitute_terms_outside_placeholders(text, self.TERMS), text)

    def test_placeholder_body_is_never_substituted(self):
        text = "{COLOR BALL} BALL" + END
        self.assertEqual(
            substitute_terms_outside_placeholders(text, self.TERMS),
            "{COLOR BALL} 球" + END,
        )

    def test_placeholder_is_preserved_byte_for_byte(self):
        text = "{PLAYER} threw a POKé BALL" + END
        result = substitute_terms_outside_placeholders(text, self.TERMS)
        self.assertTrue(result.startswith("{PLAYER}"))
        self.assertIn("精灵球", result)

    def test_unknown_text_is_returned_unchanged(self):
        text = "Nothing to see here" + END
        self.assertEqual(substitute_terms_outside_placeholders(text, self.TERMS), text)

    def test_find_terms_outside_placeholders_reports_keys(self):
        keys = find_terms_outside_placeholders("{PLAYER} threw a POKé BALL" + END, self.TERMS)
        self.assertEqual(keys, ["POKé BALL"])

    def test_find_terms_ignores_placeholders(self):
        self.assertEqual(find_terms_outside_placeholders("{BALL}" + END, self.TERMS), [])


# ---------------------------------------------------------------------------
# 4. Processor
# ---------------------------------------------------------------------------


def make_entry(source, index=0, label="Text_Test"):
    return {
        "id": "data/maps/Test/scripts.inc:" + label + ":" + str(index),
        "file": "data/maps/Test/scripts.inc",
        "label": label,
        "index": index,
        "source": source,
        "category": "map_script",
        "translation": None,
        "match_type": None,
        "matched_key": None,
        "confidence": None,
        "reason": "NO_MATCH",
    }


class TestDictionaryTranslator(unittest.TestCase):
    def setUp(self):
        self.translator = DictionaryTranslator({"game_terms": {"POKéMON": "宝可梦", "NO": "否"}})

    def test_term_sentence_is_translated(self):
        translation, keys = self.translator.translate("I love POKéMON!" + END)
        self.assertIsNotNone(translation)
        self.assertIn("宝可梦", translation)
        self.assertEqual(keys, ["POKéMON"])

    def test_zero_hits_returns_none(self):
        translation, keys = self.translator.translate("Nothing here" + END)
        self.assertIsNone(translation)
        self.assertEqual(keys, [])

    def test_unsafe_english_homograph_is_not_substituted(self):
        self.assertIn("NO", FREE_TEXT_UNSAFE_KEYS)
        translation, keys = self.translator.translate("There is no time" + END)
        self.assertIsNone(translation)
        self.assertEqual(keys, [])

    def test_ambiguous_terms_from_base_dict_are_not_substituted(self):
        translator = DictionaryTranslator({"game_terms": {"RETURN": "报恩"}, "ambiguous_terms": ["RETURN"]})
        translation, _ = translator.translate("RETURN" + END)
        self.assertIsNone(translation)

    def test_skip_keys_extend_the_exclusions(self):
        translator = DictionaryTranslator(
            {"game_terms": {"POKéMON": "宝可梦"}}, skip_keys=["POKéMON"]
        )
        self.assertIsNone(translator.translate("I love POKéMON!" + END)[0])

    def test_substitution_is_idempotent_on_written_chinese(self):
        translator = DictionaryTranslator({"game_terms": {"POKéMON": "宝可梦"}})
        translation, _ = translator.translate("宝可梦" + END)
        self.assertIsNone(translation)


class TestTranslateCorpus(unittest.TestCase):
    BASE_DICT = {"game_terms": {"POKéMON": "宝可梦"}}

    def test_known_term_entry_is_translated_and_valid(self):
        entries = [make_entry("I love POKéMON!" + NL + "Yes!" + END)]
        translated, stats = translate_corpus(entries, self.BASE_DICT)
        self.assertEqual(len(translated), 1)
        out = translated[0]
        self.assertIsNotNone(out["translation"])
        self.assertIn("宝可梦", out["translation"])
        self.assertEqual(out["match_type"], MATCH_DICTIONARY)
        self.assertEqual(out["matched_key"], "POKéMON")
        self.assertEqual(out["confidence"], DICTIONARY_CONFIDENCE)
        self.assertEqual(stats.translated, 1)
        # The guard itself must accept what the processor emitted.
        validate_translation(out["source"], out["translation"])

    def test_entry_without_dictionary_term_stays_null(self):
        entries = [make_entry("Totally unknown sentence" + END)]
        translated, stats = translate_corpus(entries, self.BASE_DICT)
        self.assertIsNone(translated[0]["translation"])
        self.assertEqual(translated[0]["reason"], REASON_NO_TERM)
        self.assertEqual(translated[0]["match_type"], None)
        self.assertEqual(stats.untranslated, 1)
        self.assertEqual(stats.translated, 0)

    def test_translation_failing_the_guard_is_dropped_to_null(self):
        """A term whose Chinese carries an unbalanced placeholder must be rejected."""
        base_dict = {"game_terms": {"MAGIC": "宝可梦{RIVAL}"}}
        entries = [make_entry("MAGIC!" + END)]
        translated, stats = translate_corpus(entries, base_dict)
        self.assertIsNone(translated[0]["translation"])
        self.assertEqual(translated[0]["reason"], REASON_GUARD_REJECTED)
        self.assertEqual(stats.guard_rejected, 1)
        self.assertEqual(stats.translated, 0)

    def test_control_codes_survive_translation(self):
        source = "{PLAYER} loves POKéMON!" + NL + "Really!" + LP + "Truly!" + END
        translated, _ = translate_corpus([make_entry(source)], self.BASE_DICT)
        out = translated[0]["translation"]
        self.assertIsNotNone(out)
        self.assertTrue(out.endswith(END))
        self.assertEqual(out.count(LP), 1)
        self.assertEqual(out.count(NL), 1)
        self.assertEqual(out.count("{PLAYER}"), 1)

    def test_source_identity_fields_are_preserved(self):
        """Provenance must survive; only the verdict fields may change."""
        entry = make_entry("I love POKéMON!" + END)
        translated, _ = translate_corpus([entry], self.BASE_DICT)
        for key in ("id", "file", "label", "index", "source", "category"):
            self.assertEqual(translated[0][key], entry[key], key)

    def test_stats_account_for_every_entry(self):
        entries = [
            make_entry("I love POKéMON!" + END, 0),
            make_entry("Totally unknown sentence" + END, 1),
        ]
        translated, stats = translate_corpus(entries, self.BASE_DICT)
        self.assertEqual(stats.total, 2)
        self.assertEqual(stats.translated + stats.untranslated + stats.guard_rejected, stats.total)
        self.assertEqual(len(translated), 2)

    def test_empty_corpus(self):
        translated, stats = translate_corpus([], self.BASE_DICT)
        self.assertEqual(translated, [])
        self.assertEqual(stats.total, 0)


# ---------------------------------------------------------------------------
# 5. Real corpus integration
# ---------------------------------------------------------------------------


@unittest.skipUnless(
    os.path.exists(UNMATCHED_CORPUS_PATH) and os.path.exists(BASE_DICT_PATH),
    "corpus artefacts not built",
)
class TestRealCorpus(unittest.TestCase):
    """The shipped artefacts, not a toy dictionary."""

    @classmethod
    def setUpClass(cls):
        cls.entries = load_json(UNMATCHED_CORPUS_PATH)
        cls.base_dict = load_json(BASE_DICT_PATH)
        cls.translator = DictionaryTranslator(cls.base_dict)
        # One pass over the real corpus; every test below asserts on its output.
        cls.translated, cls.stats = translate_corpus(
            cls.entries, translator=cls.translator
        )

    def test_every_emitted_translation_passes_the_guard(self):
        for entry in self.translated:
            if entry["translation"] is None:
                continue
            validate_translation(entry["source"], entry["translation"])

    def test_control_codes_are_identical_in_every_emitted_translation(self):
        for entry in self.translated:
            translation = entry["translation"]
            if translation is None:
                continue
            for code in (NL, LL, LP, END):
                self.assertEqual(
                    entry["source"].count(code),
                    translation.count(code),
                    (entry["id"], code),
                )

    def test_corpus_produces_some_translations_and_some_nulls(self):
        self.assertGreater(self.stats.translated, 0)
        self.assertGreater(self.stats.untranslated, 0)
        self.assertEqual(
            self.stats.translated + self.stats.untranslated + self.stats.guard_rejected,
            len(self.entries),
        )
        self.assertEqual(len(self.translated), len(self.entries))

    def test_untranslated_entries_are_explicitly_reasoned(self):
        """Every null carries a reason -- nothing is silently empty."""
        for entry in self.translated:
            if entry["translation"] is None:
                self.assertIn(entry["reason"], (REASON_NO_TERM, REASON_GUARD_REJECTED))

    def test_known_term_sentence_from_the_real_corpus(self):
        translation, keys = self.translator.translate("I like POKéMON." + END)
        self.assertIn("宝可梦", translation)
        self.assertIn("POKéMON", keys)


# ---------------------------------------------------------------------------
# 6. CLI
# ---------------------------------------------------------------------------


class TestCli(unittest.TestCase):
    def _corpus(self):
        return [
            make_entry("I love POKéMON!" + NL + "Yes!" + END, 0),
            make_entry("Totally unknown sentence" + END, 1),
        ]

    def test_cli_writes_translated_corpus(self):
        with tempfile.TemporaryDirectory() as tmp:
            in_path = os.path.join(tmp, "in.json")
            out_path = os.path.join(tmp, "out.json")
            with open(in_path, "w", encoding="utf-8") as fp:
                json.dump(self._corpus(), fp, ensure_ascii=False)

            rc = translator_main(
                [
                    "--input", in_path,
                    "--output", out_path,
                    "--base-dict", BASE_DICT_PATH,
                ]
            )
            self.assertEqual(rc, 0)
            self.assertTrue(os.path.exists(out_path))

            with open(out_path, "r", encoding="utf-8") as fp:
                written = json.load(fp)
            self.assertEqual(len(written), 2)
            self.assertIsNotNone(written[0]["translation"])
            self.assertIn("宝可梦", written[0]["translation"])
            self.assertIsNone(written[1]["translation"])

    def test_cli_output_is_real_utf8_not_escapes(self):
        with tempfile.TemporaryDirectory() as tmp:
            in_path = os.path.join(tmp, "in.json")
            out_path = os.path.join(tmp, "out.json")
            with open(in_path, "w", encoding="utf-8") as fp:
                json.dump(self._corpus(), fp, ensure_ascii=False)
            translator_main(["--input", in_path, "--output", out_path, "--base-dict", BASE_DICT_PATH])

            with open(out_path, "rb") as fp:
                raw = fp.read()
            self.assertIn("宝可梦".encode("utf-8"), raw)
            self.assertNotIn(b"\\u", raw)

    def test_cli_runs_as_a_script(self):
        """``python tools/i18n/ai_translator.py`` must work from the repo root."""
        with tempfile.TemporaryDirectory() as tmp:
            in_path = os.path.join(tmp, "in.json")
            out_path = os.path.join(tmp, "out.json")
            with open(in_path, "w", encoding="utf-8") as fp:
                json.dump(self._corpus(), fp, ensure_ascii=False)

            result = subprocess.run(
                [
                    sys.executable,
                    os.path.join("tools", "i18n", "ai_translator.py"),
                    "--input", in_path,
                    "--output", out_path,
                ],
                cwd=REPO_ROOT,
                capture_output=True,
                text=True,
                encoding="utf-8",
            )
            self.assertEqual(result.returncode, 0, result.stderr)
            self.assertTrue(os.path.exists(out_path))


@unittest.skipUnless(os.path.exists(UNMATCHED_CORPUS_PATH), "corpus artefact not built")
class TestShippedArtefactPaths(unittest.TestCase):
    def test_translated_corpus_path_sits_next_to_the_others(self):
        self.assertEqual(
            os.path.basename(TRANSLATED_CORPUS_PATH), "translated_corpus.json"
        )
        self.assertEqual(
            os.path.dirname(TRANSLATED_CORPUS_PATH), os.path.dirname(UNMATCHED_CORPUS_PATH)
        )


if __name__ == "__main__":
    unittest.main()
