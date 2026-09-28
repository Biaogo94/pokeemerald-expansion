# -*- coding: utf-8 -*-
"""Tests for the Heart & Soul GBA text formatter and code injector (Task 4).

Covers the four hard requirements of the task brief:

  1. ``wrap_chinese`` re-flows a translation into the game's control-code
     layout: ``\\n`` after the first line of a paragraph, ``\\l`` after every
     subsequent non-final line, ``\\p`` / ``$`` terminating the paragraph.
  2. ``inject_into_file`` writes a translation back into a ``.inc`` ``.string``
     block or a ``.h``/``.c`` ``_("...")`` literal without disturbing anything
     else, and is idempotent.
  3. The injection filter (MANDATORY) drops ``match_type == "dictionary"``
     entries -- those are English sentences with Chinese terms spliced in, not
     translations -- while keeping ``"exact"`` and ``"term"`` entries.
  4. The CLI reports injected vs. filtered-out counts under ``--dry-run`` and
     writes nothing.

Global invariants enforced throughout: control codes and ``{...}``
placeholders are never split or dropped, and re-running the injector on
already-injected content produces no further diff.
"""

import contextlib
import io
import json
import os
import re
import shutil
import tempfile
import unittest

from tools.i18n.extractor import extract_strings_from_inc
from tools.i18n.injector import (
    DEFAULT_MAX_CHARS,
    ALIGNED_CORPUS_PATH,
    TRANSLATED_CORPUS_PATH,
    InjectionPlan,
    InjectionResult,
    build_plan,
    emit_string_lines,
    filter_entries,
    inject_into_file,
    is_injectable,
    load_corpus,
    main,
    split_paragraphs,
    wrap_chinese,
)

NL = "\\n"
LL = "\\l"
LP = "\\p"
END = "$"

# 40 distinct CJK ideographs, so an off-by-one in the wrap is visible.
KANJI40 = "".join(chr(0x4E00 + i) for i in range(40))
KANJI16 = KANJI40[0:16]
KANJI16B = KANJI40[16:32]
KANJI8 = KANJI40[32:40]


def strip_line_codes(text):
    """Split a wrapped string into its visible lines (layout codes removed)."""
    parts = re.split(r"\\[nlp]", text)
    if parts and parts[-1].endswith(END):
        parts[-1] = parts[-1][:-1]
    return parts


class TestWrapChinese(unittest.TestCase):
    """Requirement 1: Chinese line wrapping."""

    def test_default_max_chars_is_16(self):
        self.assertEqual(DEFAULT_MAX_CHARS, 16)

    def test_wraps_40_char_paragraph_into_lines_of_at_most_16(self):
        out = wrap_chinese(KANJI40 + END)
        self.assertEqual(out, KANJI16 + NL + KANJI16B + LL + KANJI8 + END)

    def test_first_line_uses_newline_subsequent_use_line_scroll(self):
        out = wrap_chinese(KANJI40 + END)
        self.assertIn(NL, out)
        self.assertIn(LL, out)
        # Line 1 is followed by \n; line 2 by \l; line 3 (final) by $.
        self.assertLess(out.index(NL), out.index(LL))
        self.assertTrue(out.endswith(END))

    def test_every_emitted_line_is_within_max_chars(self):
        out = wrap_chinese(KANJI40 + END)
        lines = strip_line_codes(out)
        self.assertEqual([len(line) for line in lines], [16, 16, 8])
        for line in lines:
            self.assertLessEqual(len(line), DEFAULT_MAX_CHARS)

    def test_respects_custom_max_chars(self):
        out = wrap_chinese(KANJI40 + END, max_chars=10)
        self.assertEqual(
            out,
            KANJI40[0:10] + NL
            + KANJI40[10:20] + LL
            + KANJI40[20:30] + LL
            + KANJI40[30:40] + END,
        )

    def test_paragraph_break_is_preserved_and_never_merged(self):
        out = wrap_chinese(KANJI40 + LP + KANJI40 + END)
        self.assertEqual(out.count(LP), 1)
        first, second = out.split(LP)
        self.assertEqual(first, KANJI16 + NL + KANJI16B + LL + KANJI8)
        self.assertEqual(second, KANJI16 + NL + KANJI16B + LL + KANJI8 + END)

    def test_single_line_paragraph_has_no_trailing_newline(self):
        out = wrap_chinese("你好！" + END)
        self.assertEqual(out, "你好！" + END)
        self.assertNotIn(NL, out)
        self.assertNotIn(LL, out)

    def test_missing_terminator_is_preserved_as_missing(self):
        out = wrap_chinese("你好！")
        self.assertEqual(out, "你好！")
        self.assertFalse(out.endswith(END))

    def test_original_line_breaks_are_discarded_and_reflowed(self):
        # The authored English layout must not survive into the Chinese wrap.
        out = wrap_chinese(KANJI16 + NL + KANJI16B + LL + KANJI8 + END)
        self.assertEqual(out, KANJI16 + NL + KANJI16B + LL + KANJI8 + END)

    def test_short_paragraph_is_left_on_one_line(self):
        out = wrap_chinese(KANJI16 + END)
        self.assertEqual(out, KANJI16 + END)

    # -- ASCII passthrough -------------------------------------------------

    def test_pure_ascii_string_is_returned_byte_identical(self):
        for text in (
            "Thank you for playing!" + END,
            "Hello" + NL + "world" + END,
            "A" + LP + "B" + END,
            "{PLAYER} got {STR_VAR_1}!" + END,
            "I'm investigating this ship on behalf" + NL
            + "of CAPT. STERN." + LP
            + "He also asked me to find a SCANNER," + NL
            + "but I haven't had any success…" + END,
            "",
            END,
        ):
            with self.subTest(text=text):
                self.assertEqual(wrap_chinese(text), text)

    def test_long_ascii_sentence_is_not_reflowed(self):
        # English wraps at a much wider column; re-wrapping it at 16 chars
        # would produce garbage.  No CJK -> untouched.
        text = "This English sentence is far longer than sixteen characters." + END
        self.assertEqual(wrap_chinese(text), text)

    def test_latin_accented_text_is_not_cjk(self):
        # POKéMON is Latin-1, not CJK: it must keep its authored layout.
        text = "POKéMON LEAGUE is a very long string indeed" + END
        self.assertEqual(wrap_chinese(text), text)

    def test_ascii_paragraph_inside_chinese_document_keeps_its_layout(self):
        text = "你好" + LP + "Hello" + NL + "world" + END
        self.assertEqual(wrap_chinese(text), text)

    # -- placeholder / control-code atomicity ------------------------------

    def test_placeholder_is_never_split_across_a_boundary(self):
        text = KANJI8 + "{PLAYER}" + KANJI8 + END
        out = wrap_chinese(text, max_chars=8)
        self.assertEqual(out.count("{PLAYER}"), 1)
        for line in strip_line_codes(out):
            # A line either carries the whole placeholder or none of it.
            self.assertIn(line.count("{"), (0, 1))
            self.assertIn(line.count("}"), (0, 1))
            if "{" in line:
                self.assertIn("{PLAYER}", line)

    def test_placeholder_kept_intact_at_exact_boundary(self):
        text = KANJI8 + "{PLAYER}" + KANJI8 + END
        out = wrap_chinese(text, max_chars=8)
        lines = strip_line_codes(out)
        self.assertIn("{PLAYER}", lines)
        self.assertEqual(lines[0], KANJI8)

    def test_long_control_macro_is_not_split(self):
        text = "{CLEAR_TO 0x58}" + KANJI8 + END
        out = wrap_chinese(text, max_chars=4)
        self.assertEqual(out.count("{CLEAR_TO 0x58}"), 1)
        lines = strip_line_codes(out)
        self.assertIn("{CLEAR_TO 0x58}", lines)
        for line in lines:
            # Never a dangling brace: the macro is emitted whole or not at all.
            self.assertEqual(line.count("{"), line.count("}"))

    def test_all_placeholders_survive_wrapping(self):
        text = "{COLOR RED}" + KANJI8 + "{PLAYER}" + KANJI8 + "{STR_VAR_1}" + END
        out = wrap_chinese(text, max_chars=6)
        for token in ("{COLOR RED}", "{PLAYER}", "{STR_VAR_1}"):
            self.assertEqual(out.count(token), 1, token)

    # -- idempotence -------------------------------------------------------

    def test_wrap_chinese_is_idempotent(self):
        for text in (
            KANJI40 + END,
            KANJI40 + LP + KANJI40 + END,
            KANJI8 + "{PLAYER}" + KANJI8 + END,
            "你好！" + END,
            "Thank you for playing!" + END,
            KANJI16 + END,
            "",
        ):
            with self.subTest(text=text):
                once = wrap_chinese(text)
                self.assertEqual(wrap_chinese(once), once)

    def test_invalid_max_chars_raises(self):
        with self.assertRaises(ValueError):
            wrap_chinese(KANJI40 + END, max_chars=0)


class TestSplitParagraphs(unittest.TestCase):
    def test_splits_on_page_break(self):
        self.assertEqual(split_paragraphs("A" + LP + "B"), ["A", "B"])

    def test_no_page_break_is_one_paragraph(self):
        self.assertEqual(split_paragraphs("A" + NL + "B"), ["A" + NL + "B"])

    def test_empty_paragraphs_are_kept(self):
        self.assertEqual(split_paragraphs("A" + LP + LP + "B"), ["A", "", "B"])


class TestEmitStringLines(unittest.TestCase):
    """.string block emission: one line per control-code-terminated chunk."""

    def test_split_at_each_control_code(self):
        lines = emit_string_lines("你好呀" + LP + "祝你玩得开心！" + END)
        self.assertEqual(
            lines,
            ['\t.string "你好呀' + LP + '"', '\t.string "祝你玩得开心！' + END + '"'],
        )

    def test_newline_and_line_scroll_split_too(self):
        lines = emit_string_lines(KANJI16 + NL + KANJI16B + LL + KANJI8 + END)
        self.assertEqual(
            lines,
            [
                '\t.string "' + KANJI16 + NL + '"',
                '\t.string "' + KANJI16B + LL + '"',
                '\t.string "' + KANJI8 + END + '"',
            ],
        )

    def test_single_chunk(self):
        self.assertEqual(
            emit_string_lines("Thank you for playing!" + END),
            ['\t.string "Thank you for playing!' + END + '"'],
        )

    def test_indent_override(self):
        self.assertEqual(emit_string_lines("你好" + END, indent="  "), ['  .string "你好' + END + '"'])

    def test_round_trip_through_the_extractor(self):
        text = wrap_chinese(KANJI40 + LP + KANJI16 + END)
        body = "\n".join(emit_string_lines(text))
        block = "Test_Label:\n" + body + "\n"
        entries = extract_strings_from_inc("sample.inc", block)
        self.assertEqual(len(entries), 1)
        self.assertEqual(entries[0].source, text)


class TestInjectionFilter(unittest.TestCase):
    """Requirement 3 (MANDATORY): dictionary scaffold must never be injected."""

    def test_keeps_exact_and_term(self):
        self.assertTrue(is_injectable({"translation": "你好$", "match_type": "exact"}))
        self.assertTrue(is_injectable({"translation": "取消$", "match_type": "term"}))

    def test_drops_dictionary(self):
        self.assertFalse(
            is_injectable(
                {
                    "translation": "Hello our 宝可梦" + END,
                    "match_type": "dictionary",
                }
            )
        )

    def test_drops_untranslated(self):
        self.assertFalse(is_injectable({"translation": None, "match_type": None}))
        self.assertFalse(is_injectable({"translation": "", "match_type": "exact"}))

    def test_filter_entries_mixed(self):
        entries = [
            {"id": "a", "translation": "甲$", "match_type": "exact"},
            {"id": "b", "translation": "English 宝可梦$", "match_type": "dictionary"},
            {"id": "c", "translation": None, "match_type": None},
            {"id": "d", "translation": "乙$", "match_type": "term"},
        ]
        kept = filter_entries(entries)
        self.assertEqual([e["id"] for e in kept], ["a", "d"])


class TestInjectionFilterOnRealCorpora(unittest.TestCase):
    """The shipped corpora must filter down to genuine translations only."""

    @classmethod
    def setUpClass(cls):
        cls.aligned = load_corpus(ALIGNED_CORPUS_PATH)
        cls.translated = load_corpus(TRANSLATED_CORPUS_PATH)
        cls.plan = build_plan(cls.aligned, cls.translated)

    def test_corpus_sizes(self):
        self.assertEqual(len(self.aligned), 128)
        self.assertEqual(len(self.translated), 17286)

    def test_aligned_corpus_is_entirely_injectable(self):
        self.assertEqual(self.plan.injectable, 128)

    def test_all_dictionary_entries_are_filtered_out(self):
        dictionaries = [e for e in self.translated if e.get("match_type") == "dictionary"]
        self.assertEqual(len(dictionaries), 6425)
        self.assertEqual(self.plan.dropped_dictionary, 6425)

    def test_untranslated_entries_are_filtered_out(self):
        self.assertEqual(self.plan.dropped_untranslated, 10861)

    def test_no_dictionary_entry_reaches_the_plan(self):
        real_ids = {e["id"] for e in self.aligned}
        for entries in self.plan.by_file.values():
            for entry in entries:
                self.assertIn(entry["id"], real_ids)
                self.assertNotEqual(entry.get("match_type"), "dictionary")

    def test_no_injected_translation_looks_like_scaffold(self):
        """A dictionary scaffold keeps long ASCII runs; a real translation does not."""
        dictionary_ids = {
            e["id"] for e in self.translated if e.get("match_type") == "dictionary"
        }
        for entries in self.plan.by_file.values():
            for entry in entries:
                self.assertNotIn(entry["id"], dictionary_ids)

    def test_plan_counts_are_consistent(self):
        self.assertEqual(
            self.plan.total,
            self.plan.injectable
            + self.plan.dropped_dictionary
            + self.plan.dropped_untranslated
            + self.plan.dropped_other,
        )

    def test_plan_files_all_exist(self):
        for path in self.plan.by_file:
            self.assertTrue(os.path.exists(path), path)


SAMPLE_INC = (
    "TestMap_EventScript_Intro::\n"
    "\tmsgbox TestMap_Text_Intro, MSGBOX_DEFAULT\n"
    "\trelease\n"
    "\tend\n"
    "\n"
    "TestMap_Text_Intro:\n"
    '\t.string "Hello there!\\n"\n'
    '\t.string "Welcome to the world of POKéMON.\\p"\n'
    '\t.string "Have fun!$"\n'
    "\n"
    "TestMap_EventScript_Outro::\n"
    "\tmsgbox TestMap_Text_Outro, MSGBOX_DEFAULT\n"
    "\tend\n"
    "\n"
    "TestMap_Text_Outro:\n"
    '\t.string "Goodbye!$"\n'
    "\n"
    "TestMap_Text_Untouched:\n"
    '\t.string "Untouched line one\\n"\n'
    '\t.string "untouched line two$"\n'
)

INTRO_TRANSLATION = "你好呀，欢迎来到宝可梦的世界！" + LP + "祝你玩得开心！" + END

SAMPLE_H = (
    "static const u8 sTestGreeting[] = _(\"Hello there!\\nHave fun!$\");\n"
    "static const u8 sTestFarewell[] = _(\"Goodbye!$\");\n"
    "static const u8 sTestUnrelated[] = _(\"Leave me alone please$\");\n"
)


class InjectorTestBase(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.mkdtemp(prefix="hns_inject_")
        self.addCleanup(shutil.rmtree, self.tmp, ignore_errors=True)

    def write(self, relpath, content):
        path = os.path.join(self.tmp, relpath)
        os.makedirs(os.path.dirname(path), exist_ok=True)
        with open(path, "w", encoding="utf-8", newline="") as fp:
            fp.write(content)
        return path

    def read(self, path):
        with open(path, "r", encoding="utf-8", newline="") as fp:
            return fp.read()


class TestInjectInc(InjectorTestBase):
    """Requirement 2: .inc injection."""

    def setUp(self):
        super().setUp()
        self.path = self.write("data/maps/TestMap/scripts.inc", SAMPLE_INC)
        self.update = {
            "id": "x:TestMap_Text_Intro:0",
            "file": "./data/maps/TestMap/scripts.inc",
            "label": "TestMap_Text_Intro",
            "index": 0,
            "source": 'Hello there!\\nWelcome to the world of POKéMON.\\pHave fun!$',
            "translation": INTRO_TRANSLATION,
            "match_type": "exact",
        }

    def test_injects_translation_into_target_label(self):
        result = inject_into_file(self.path, [self.update])
        self.assertIsInstance(result, InjectionResult)
        self.assertTrue(result.changed)
        self.assertEqual(result.applied, 1)
        content = self.read(self.path)
        self.assertIn('\t.string "你好呀，欢迎来到宝可梦的世界！' + LP + '"', content)
        self.assertIn('\t.string "祝你玩得开心！' + END + '"', content)
        self.assertNotIn("Hello there!", content)

    def _strip_string_block(self, content, label):
        """Return the file's lines with ``label``'s .string lines removed."""
        kept, inside, found = [], False, False
        for line in content.split("\n"):
            if line.startswith(label + ":"):
                inside, found = True, True
                kept.append(line)
                continue
            if inside:
                if line.startswith("\t.string "):
                    continue
                inside = False
            kept.append(line)
        self.assertTrue(found, label)
        return kept

    def test_neighbouring_labels_are_untouched(self):
        before = self.read(self.path)
        inject_into_file(self.path, [self.update])
        content = self.read(self.path)

        self.assertIn('\t.string "Goodbye!' + END + '"', content)
        self.assertIn('\t.string "Untouched line one' + NL + '"', content)
        self.assertIn('\t.string "untouched line two' + END + '"', content)
        self.assertIn("\tmsgbox TestMap_Text_Outro, MSGBOX_DEFAULT", content)
        self.assertIn("TestMap_Text_Untouched:", content)
        # Outside the target label's .string block the file is byte-identical.
        self.assertEqual(
            self._strip_string_block(before, "TestMap_Text_Intro"),
            self._strip_string_block(content, "TestMap_Text_Intro"),
        )

    def test_label_line_and_surrounding_structure_are_preserved(self):
        inject_into_file(self.path, [self.update])
        content = self.read(self.path)
        self.assertIn("TestMap_Text_Intro:", content)
        self.assertIn("\tmsgbox TestMap_Text_Intro, MSGBOX_DEFAULT", content)
        self.assertIn("TestMap_EventScript_Intro::", content)

    def test_untargeted_labels_produce_no_change(self):
        other = dict(
            self.update,
            label="TestMap_Text_Outro",
            source="Goodbye!" + END,
            translation="再见！" + END,
        )
        result = inject_into_file(self.path, [other])
        self.assertTrue(result.changed)
        content = self.read(self.path)
        self.assertIn('\t.string "再见！' + END + '"', content)
        # The Intro block was not the target and keeps its English text.
        self.assertIn("Hello there!", content)

    def test_injection_is_idempotent(self):
        inject_into_file(self.path, [self.update])
        first = self.read(self.path)
        result = inject_into_file(self.path, [self.update])
        second = self.read(self.path)
        self.assertEqual(first, second)
        self.assertFalse(result.changed)

    def test_injected_content_re_wraps_to_itself(self):
        inject_into_file(self.path, [self.update])
        content = self.read(self.path)
        entries = extract_strings_from_inc("scripts.inc", content)
        texts = {e.label: e.source for e in entries}
        injected = texts["TestMap_Text_Intro"]
        self.assertEqual(injected, wrap_chinese(INTRO_TRANSLATION))
        self.assertEqual(wrap_chinese(injected), injected)
        # Untouched neighbours still round-trip byte-for-byte.
        self.assertEqual(texts["TestMap_Text_Untouched"], "Untouched line one" + NL + "untouched line two" + END)

    def test_ascii_only_translation_keeps_authored_layout(self):
        untouched = "Untouched line one" + NL + "untouched line two" + END
        update = dict(
            self.update,
            label="TestMap_Text_Untouched",
            index=0,
            source=untouched,
            translation=untouched,
        )
        result = inject_into_file(self.path, [update])
        self.assertEqual(result.skipped, 0)
        self.assertFalse(result.changed)

    def test_missing_label_is_skipped_not_fatal(self):
        update = dict(self.update, label="Does_Not_Exist")
        before = self.read(self.path)
        result = inject_into_file(self.path, [update])
        self.assertEqual(result.applied, 0)
        self.assertEqual(result.skipped, 1)
        self.assertFalse(result.changed)
        self.assertEqual(self.read(self.path), before)

    def test_index_selects_the_right_block_when_a_label_repeats(self):
        path = self.write(
            "data/maps/TestMap/dup.inc",
            'Test_Text_Dup:\n\t.string "first$"\n\t.string "second$"\n',
        )
        update = {
            "id": "x:Test_Text_Dup:1",
            "file": "./data/maps/TestMap/dup.inc",
            "label": "Test_Text_Dup",
            "index": 1,
            "source": "second$",
            "translation": "第二个" + END,
            "match_type": "exact",
        }
        inject_into_file(path, [update])
        content = self.read(path)
        self.assertIn('\t.string "first' + END + '"', content)
        self.assertIn('\t.string "第二个' + END + '"', content)

    def test_dry_run_does_not_write(self):
        before = self.read(self.path)
        result = inject_into_file(self.path, [self.update], dry_run=True)
        self.assertTrue(result.changed)
        self.assertEqual(self.read(self.path), before)
        self.assertIn("你好呀", result.after)

    def test_batch_of_files_and_labels(self):
        path_b = self.write("data/maps/Other/scripts.inc", SAMPLE_INC)
        update_b = dict(
            self.update,
            label="TestMap_Text_Outro",
            source="Goodbye!" + END,
            translation="再见！" + END,
        )
        inject_into_file(self.path, [self.update])
        inject_into_file(path_b, [update_b])
        self.assertIn("你好呀", self.read(self.path))
        self.assertIn("再见！", self.read(path_b))
        self.assertIn("Hello there!", self.read(path_b))

    def test_crlf_file_is_injected_without_mixing_line_endings(self):
        # Git on Windows may hand Task 5 CRLF sources; injecting must not
        # silently convert the file, lose the target block, or mix endings.
        path = self.write("data/maps/TestMap/crlf.inc", SAMPLE_INC.replace("\n", "\r\n"))
        result = inject_into_file(path, [self.update])
        self.assertTrue(result.changed)
        self.assertEqual(result.applied, 1)

        with open(path, "rb") as handle:
            raw = handle.read().decode("utf-8")
        self.assertIn("你好呀", raw)
        self.assertIn("Goodbye!" + END, raw)
        self.assertIn("TestMap_Text_Intro:", raw)
        # Every newline is CRLF -- never a mixture.
        self.assertEqual(raw.count("\r\n"), raw.count("\n"))

        # And it still converges on a second run.
        inject_into_file(path, [self.update])
        with open(path, "rb") as handle:
            self.assertEqual(handle.read().decode("utf-8"), raw)


class TestInjectC(InjectorTestBase):
    """Requirement 2: .h/.c injection into ``_("...")``."""

    def setUp(self):
        super().setUp()
        self.path = self.write("src/data/text/test_strings.h", SAMPLE_H)
        self.update = {
            "id": "y:sTestGreeting:0",
            "file": "./src/data/text/test_strings.h",
            "label": "sTestGreeting",
            "index": 0,
            "source": "Hello there!" + NL + "Have fun!" + END,
            "translation": "你好呀，欢迎来到宝可梦的世界！" + END,
            "match_type": "exact",
        }

    def test_injects_into_matching_array(self):
        result = inject_into_file(self.path, [self.update])
        self.assertTrue(result.changed)
        content = self.read(self.path)
        self.assertIn('sTestGreeting[] = _("你好呀，欢迎来到宝可梦的世界！' + END + '");', content)

    def test_neighbouring_arrays_are_untouched(self):
        inject_into_file(self.path, [self.update])
        content = self.read(self.path)
        self.assertIn('sTestFarewell[] = _("Goodbye!' + END + '");', content)
        self.assertIn('sTestUnrelated[] = _("Leave me alone please' + END + '");', content)
        self.assertEqual(len(content.splitlines()), len(SAMPLE_H.splitlines()))

    def test_c_injection_is_idempotent(self):
        inject_into_file(self.path, [self.update])
        first = self.read(self.path)
        result = inject_into_file(self.path, [self.update])
        self.assertEqual(self.read(self.path), first)
        self.assertFalse(result.changed)

    def test_c_dry_run_does_not_write(self):
        before = self.read(self.path)
        result = inject_into_file(self.path, [self.update], dry_run=True)
        self.assertTrue(result.changed)
        self.assertEqual(self.read(self.path), before)


class TestCli(InjectorTestBase):
    """Requirement 4: the CLI, and the visible exclusion it must report."""

    def setUp(self):
        super().setUp()
        self.inc = self.write("data/maps/TestMap/scripts.inc", SAMPLE_INC)
        self.aligned_path = os.path.join(self.tmp, "aligned.json")
        self.translated_path = os.path.join(self.tmp, "translated.json")

        aligned = [
            {
                "id": "x:TestMap_Text_Intro:0",
                "file": "./data/maps/TestMap/scripts.inc",
                "label": "TestMap_Text_Intro",
                "index": 0,
                "source": "Hello there!" + NL + "Welcome to the world of POKéMON." + LP + "Have fun!" + END,
                "category": "map_script",
                "translation": INTRO_TRANSLATION,
                "match_type": "exact",
            },
            {
                "id": "x:TestMap_Text_Outro:0",
                "file": "./data/maps/TestMap/scripts.inc",
                "label": "TestMap_Text_Outro",
                "index": 0,
                "source": "Goodbye!" + END,
                "category": "map_script",
                "translation": "再见！" + END,
                "match_type": "term",
            },
        ]
        translated = [
            {
                "id": "x:TestMap_Text_Untouched:0",
                "file": "./data/maps/TestMap/scripts.inc",
                "label": "TestMap_Text_Untouched",
                "index": 0,
                "source": "Untouched line one" + NL + "untouched line two" + END,
                "category": "map_script",
                "translation": "Untouched line one" + NL + "untouched 宝可梦 two" + END,
                "match_type": "dictionary",
            },
            {
                "id": "x:pending",
                "file": "./data/maps/TestMap/scripts.inc",
                "label": "Pending_Label",
                "index": 0,
                "source": "Pending" + END,
                "category": "map_script",
                "translation": None,
                "match_type": None,
            },
        ]
        self.write_json(self.aligned_path, aligned)
        self.write_json(self.translated_path, translated)

    def write_json(self, path, data):
        with open(path, "w", encoding="utf-8") as fp:
            json.dump(data, fp, ensure_ascii=False, indent=2)

    def run_cli(self, extra):
        argv = [
            "--aligned", self.aligned_path,
            "--translated", self.translated_path,
            "--root", self.tmp,
        ] + extra
        buf = io.StringIO()
        with contextlib.redirect_stdout(buf):
            code = main(argv)
        return code, buf.getvalue()

    def test_dry_run_writes_nothing_but_reports_counts(self):
        before = self.read(self.inc)
        code, out = self.run_cli(["--dry-run"])
        self.assertEqual(code, 0)
        self.assertEqual(self.read(self.inc), before)
        self.assertIn("injectable", out.lower())
        self.assertIn("2", out)
        self.assertIn("dictionary", out.lower())

    def test_dry_run_reports_the_dictionary_exclusion(self):
        code, out = self.run_cli(["--dry-run"])
        self.assertEqual(code, 0)
        self.assertRegex(out, r"(?i)filtered[^\n]*dictionary")
        self.assertRegex(out, r"(?i)dictionary[^\n]*1")

    def test_dry_run_shows_a_diff_summary(self):
        code, out = self.run_cli(["--dry-run"])
        self.assertEqual(code, 0)
        self.assertIn("scripts.inc", out)
        self.assertRegex(out, r"(?i)(dry[- ]run|no files written)")

    def test_real_run_modifies_files(self):
        before = self.read(self.inc)
        code, out = self.run_cli([])
        self.assertEqual(code, 0)
        after = self.read(self.inc)
        self.assertNotEqual(before, after)
        self.assertIn("你好呀", after)
        self.assertIn("再见！", after)
        # The dictionary scaffold entry must not have been injected.
        self.assertNotIn("untouched 宝可梦 two", after)
        self.assertIn("untouched line two" + END, after)

    def test_second_real_run_is_a_no_op(self):
        self.run_cli([])
        first = self.read(self.inc)
        code, out = self.run_cli([])
        self.assertEqual(code, 0)
        self.assertEqual(self.read(self.inc), first)

    def test_real_corpora_plan_is_built(self):
        plan = build_plan(
            load_corpus(ALIGNED_CORPUS_PATH), load_corpus(TRANSLATED_CORPUS_PATH)
        )
        self.assertIsInstance(plan, InjectionPlan)
        self.assertEqual(plan.injectable, 128)


# ---------------------------------------------------------------------------
# Write-back hardening.
#
# The injector originally trusted the corpus: it matched a ``(label, index)``
# pair, wrapped whatever translation the entry carried, and wrote it.  Every
# failure mode below was therefore silent -- the wrong string, or a string on
# top of another string, reached ``data/`` while the run reported success.  The
# corpus is about to grow from 128 strings to ~25,000, and
# ``#if / #else / #endif`` blocks wrap ``.string`` blocks in real files
# (``data/text/battle_tent.inc``, ``data/text/event_ticket_*.inc``, ...), so
# each of these is now either a verified write or a reported skip.
# ---------------------------------------------------------------------------


def run_capturing_stderr(func, *args, **kwargs):
    """Call ``func`` and return ``(result, stderr_text)``."""
    buf = io.StringIO()
    with contextlib.redirect_stderr(buf):
        result = func(*args, **kwargs)
    return result, buf.getvalue()


PREPROC_INC = (
    "#if IS_HNS\n"
    "Dup_Text:\n"
    '\t.string "Alpha!$"\n'
    "#else\n"
    "Dup_Text:\n"
    '\t.string "Beta!$"\n'
    "#endif\n"
    "\n"
    "#if IS_HNS\n"
    "Guarded_Text:\n"
    '\t.string "Guarded one$"\n'
    "#endif\n"
    "\n"
    "Clean_Text:\n"
    '\t.string "Clean one$"\n'
)

ABUT_INC = (
    "#if IS_HNS\n"
    "Inner_Text:\n"
    '\t.string "Inner$"\n'
    "#endif\n"
    "Abutting_Text:\n"
    '\t.string "Abutting$"\n'
)

DIVERGENT_INC = (
    "Split_Text:\n"
    "#if IS_HNS\n"
    '\t.string "In the ARENA BATTLE TENT,\\n"\n'
    "#else\n"
    '\t.string "In the FALLARBOR BATTLE TENT,\\n"\n'
    "#endif\n"
    '\t.string "we undertake the Set KO Tourney.$"\n'
)

GUARD_INC = (
    "Guard_Text:\n"
    '\t.string "First paragraph.\\p"\n'
    '\t.string "Second paragraph.$"\n'
    "\n"
    "Placeholder_Text:\n"
    '\t.string "Hello {PLAYER}!$"\n'
)

GUARD_SOURCE = "First paragraph." + LP + "Second paragraph." + END


class TestPreprocessorBlocks(InjectorTestBase):
    """Findings 1 and 2: ``#if`` / ``#else`` / ``#endif`` are never written through."""

    def setUp(self):
        super().setUp()
        self.path = self.write("data/text/preproc.inc", PREPROC_INC)

    def update(self, label, source, translation="甲！" + END):
        return {
            "id": "x:%s:0" % label,
            "file": "./data/text/preproc.inc",
            "label": label,
            "index": 0,
            "source": source,
            "translation": translation,
            "match_type": "exact",
        }

    def before(self):
        return self.read(self.path)

    def test_same_label_in_both_branches_is_skipped_not_overwritten(self):
        """The old injector wrote one translation over BOTH branches."""
        before = self.before()
        result, err = run_capturing_stderr(
            inject_into_file, self.path, [self.update("Dup_Text", "Alpha!$")]
        )
        self.assertEqual(result.applied, 0)
        self.assertEqual(result.skipped, 1)
        self.assertFalse(result.changed)
        self.assertEqual(self.read(self.path), before)
        content = self.read(self.path)
        self.assertIn('\t.string "Alpha!$"', content)
        self.assertIn('\t.string "Beta!$"', content)
        self.assertIn("Dup_Text", err)

    def test_a_skipped_update_is_reported_and_never_makes_the_count_negative(self):
        updates = [
            self.update("Dup_Text", "Alpha!$"),
            self.update("Guarded_Text", "Guarded one$"),
            self.update("Clean_Text", "Clean one$", "干净$"),
        ]
        result = inject_into_file(self.path, updates)
        self.assertEqual(result.applied, 1)
        self.assertEqual(result.skipped, 2)
        self.assertGreaterEqual(result.skipped, 0)

    def test_label_inside_a_preprocessor_block_is_skipped(self):
        before = self.before()
        result, err = run_capturing_stderr(
            inject_into_file, self.path, [self.update("Guarded_Text", "Guarded one$")]
        )
        self.assertEqual(result.applied, 0)
        self.assertEqual(result.skipped, 1)
        self.assertEqual(self.read(self.path), before)
        self.assertIn("Guarded_Text", err)

    def test_label_after_endif_with_a_blank_line_is_still_injected(self):
        result = inject_into_file(
            self.path, [self.update("Clean_Text", "Clean one$", "干净$")]
        )
        self.assertEqual(result.applied, 1)
        self.assertEqual(result.skipped, 0)
        self.assertIn("干净" + END, self.read(self.path))
        # The preprocessor branches themselves are untouched.
        self.assertIn('\t.string "Alpha!$"', self.read(self.path))
        self.assertIn('\t.string "Beta!$"', self.read(self.path))

    def test_label_abutting_endif_is_skipped(self):
        """No blank line between ``#endif`` and the label: refuse to guess."""
        path = self.write("data/text/abut.inc", ABUT_INC)
        before = self.read(path)
        update = {
            "id": "x:Abutting_Text:0",
            "file": "./data/text/abut.inc",
            "label": "Abutting_Text",
            "index": 0,
            "source": "Abutting$",
            "translation": "相邻$",
            "match_type": "exact",
        }
        result, err = run_capturing_stderr(inject_into_file, path, [update])
        self.assertEqual(result.applied, 0)
        self.assertEqual(result.skipped, 1)
        self.assertEqual(self.read(path), before)
        self.assertIn("Abutting_Text", err)


class TestExtractorInjectorBoundary(InjectorTestBase):
    """Finding 2: the extractor merges across ``#if``; the injector must not guess."""

    def setUp(self):
        super().setUp()
        self.path = self.write("data/text/divergent.inc", DIVERGENT_INC)

    def test_extractor_merges_the_branches_into_one_entry(self):
        entries = extract_strings_from_inc("divergent.inc", DIVERGENT_INC)
        self.assertEqual(len(entries), 1)
        self.assertIn("ARENA", entries[0].source)
        self.assertIn("FALLARBOR", entries[0].source)
        self.assertTrue(entries[0].source.endswith("Set KO Tourney." + END))

    def test_divergent_entry_is_skipped_rather_than_written_to_the_wrong_block(self):
        entries = extract_strings_from_inc("divergent.inc", DIVERGENT_INC)
        entry = entries[0]
        update = {
            "id": entry.id,
            "file": entry.file,
            "label": entry.label,
            "index": entry.index,
            "source": entry.source,
            "translation": "宝可梦竞技场，" + NL + "我们举办击倒淘汰赛。" + END,
            "match_type": "exact",
        }
        before = self.read(self.path)
        result, err = run_capturing_stderr(inject_into_file, self.path, [update])
        self.assertEqual(result.applied, 0)
        self.assertEqual(result.skipped, 1)
        self.assertFalse(result.changed)
        self.assertEqual(self.read(self.path), before)
        self.assertIn(entry.label, err)


class TestWriteBackGuards(InjectorTestBase):
    """Finding 4 and 5: the format guard runs at the write-back boundary."""

    def setUp(self):
        super().setUp()
        self.path = self.write("data/text/guarded.inc", GUARD_INC)

    def update(self, source, translation):
        return {
            "id": "x:Guard_Text:0",
            "file": "./data/text/guarded.inc",
            "label": "Guard_Text",
            "index": 0,
            "source": source,
            "translation": translation,
            "match_type": "exact",
        }

    def assert_skipped(self, update, code):
        before = self.read(self.path)
        result, err = run_capturing_stderr(inject_into_file, self.path, [update])
        self.assertEqual(result.applied, 0)
        self.assertEqual(result.skipped, 1)
        self.assertFalse(result.changed)
        self.assertEqual(self.read(self.path), before)
        self.assertIn(code, err)

    def test_translation_missing_a_page_break_is_skipped(self):
        self.assert_skipped(
            self.update(GUARD_SOURCE, "第一段。" + "第二段。" + END),
            "CONTROL_CODE_MISMATCH",
        )

    def test_translation_missing_the_terminator_is_skipped(self):
        self.assert_skipped(
            self.update(GUARD_SOURCE, "第一段。" + LP + "第二段。"),
            "TERMINATOR_MISSING",
        )

    def test_translation_dropping_a_placeholder_is_skipped(self):
        update = dict(
            self.update("Hello {PLAYER}!" + END, "你好！" + END),
            label="Placeholder_Text",
        )
        self.assert_skipped(update, "PLACEHOLDER_MISMATCH")

    def test_intact_translation_still_passes_the_guard(self):
        result = inject_into_file(
            self.path, [self.update(GUARD_SOURCE, "第一段。" + LP + "第二段。" + END)]
        )
        self.assertEqual(result.applied, 1)
        self.assertEqual(result.skipped, 0)

    def test_wrap_chinese_honours_a_terminator_behind_trailing_space(self):
        # Every other module uses ``rstrip().endswith("$")``; wrap_chinese must
        # agree, or a stray trailing space silently drops the terminator.
        self.assertEqual(wrap_chinese("你好！" + END + " "), "你好！" + END)
        self.assertEqual(wrap_chinese("你好！" + END), "你好！" + END)

    def test_aligner_and_injector_agree_that_a_moved_terminator_is_corruption(self):
        from tools.i18n.aligner import validate_control_codes_preserved

        self.assertFalse(validate_control_codes_preserved("Hello" + END, END + "Hello"))
        self.assertTrue(validate_control_codes_preserved("Hello" + END, "你好" + END))

    def test_a_hand_edited_corpus_entry_never_reaches_disk(self):
        """The whole point of the boundary guard."""
        before = self.read(self.path)
        broken = self.update(GUARD_SOURCE, "第一段。第二段。")
        inject_into_file(self.path, [broken])
        self.assertEqual(self.read(self.path), before)
        self.assertIn("First paragraph." + LP, self.read(self.path))


class TestIncSourceVerification(InjectorTestBase):
    """The central fix: a block is only replaced when it holds the expected text."""

    def setUp(self):
        super().setUp()
        self.path = self.write("data/maps/TestMap/scripts.inc", SAMPLE_INC)
        self.update = {
            "id": "x:TestMap_Text_Intro:0",
            "file": "./data/maps/TestMap/scripts.inc",
            "label": "TestMap_Text_Intro",
            "index": 0,
            "source": "Hello there!" + NL + "Welcome to the world of POKéMON." + LP + "Have fun!" + END,
            "translation": INTRO_TRANSLATION,
            "match_type": "exact",
        }

    def test_mismatching_source_is_skipped_not_written(self):
        before = self.read(self.path)
        stale = dict(self.update, source="Some other text entirely" + END)
        result, err = run_capturing_stderr(inject_into_file, self.path, [stale])
        self.assertEqual(result.applied, 0)
        self.assertEqual(result.skipped, 1)
        self.assertFalse(result.changed)
        self.assertEqual(self.read(self.path), before)
        self.assertIn("TestMap_Text_Intro", err)

    def test_two_blocks_with_the_same_label_and_index_are_skipped(self):
        path = self.write(
            "data/maps/TestMap/dup3.inc",
            'Test_Text_Dup::\n\t.string "same$"\nTest_Text_Dup::\n\t.string "same$"\n',
        )
        before = self.read(path)
        update = {
            "id": "x:Test_Text_Dup:0",
            "file": "./data/maps/TestMap/dup3.inc",
            "label": "Test_Text_Dup",
            "index": 0,
            "source": "same$",
            "translation": "相同$",
            "match_type": "exact",
        }
        result, err = run_capturing_stderr(inject_into_file, path, [update])
        self.assertEqual(result.applied, 0)
        self.assertEqual(result.skipped, 1)
        self.assertEqual(self.read(path), before)

    def test_injected_block_holds_exactly_the_corpus_source_before_the_write(self):
        inject_into_file(self.path, [self.update])
        entries = extract_strings_from_inc("scripts.inc", self.read(self.path))
        by_label = {entry.label: entry.source for entry in entries}
        self.assertEqual(
            by_label["TestMap_Text_Intro"], wrap_chinese(INTRO_TRANSLATION)
        )
        self.assertEqual(
            by_label["TestMap_Text_Outro"], "Goodbye!" + END
        )


class TestInjectCSourceVerification(InjectorTestBase):
    """Finding 3: ``_inject_c`` must skip, like the ``.inc`` path, not guess."""

    def setUp(self):
        super().setUp()
        self.path = self.write("src/data/text/test_strings.h", SAMPLE_H)

    def update(self, **overrides):
        base = {
            "id": "y:sTestGreeting:0",
            "file": "./src/data/text/test_strings.h",
            "label": "sTestGreeting",
            "index": 0,
            "source": "Hello there!" + NL + "Have fun!" + END,
            "translation": "你好呀，欢迎来到宝可梦的世界！" + END,
            "match_type": "exact",
        }
        base.update(overrides)
        return base

    def test_index_with_no_matching_array_is_skipped_not_redirected(self):
        """The old code fell back to the first array with that label."""
        before = self.read(self.path)
        update = self.update(index=1, source="Goodbye!" + END, translation="回头见！" + END)
        result, err = run_capturing_stderr(inject_into_file, self.path, [update])
        self.assertEqual(result.applied, 0)
        self.assertEqual(result.skipped, 1)
        self.assertFalse(result.changed)
        self.assertEqual(self.read(self.path), before)
        self.assertIn("sTestGreeting", err)

    def test_mismatching_source_is_skipped_not_overwritten(self):
        before = self.read(self.path)
        update = self.update(source="A completely different string" + END)
        result, err = run_capturing_stderr(inject_into_file, self.path, [update])
        self.assertEqual(result.applied, 0)
        self.assertEqual(result.skipped, 1)
        self.assertEqual(self.read(self.path), before)
        self.assertIn("sTestGreeting", err)

    def test_guard_rejects_a_broken_c_translation(self):
        before = self.read(self.path)
        update = self.update(translation="你好呀")  # dropped the $ terminator
        result, err = run_capturing_stderr(inject_into_file, self.path, [update])
        self.assertEqual(result.applied, 0)
        self.assertEqual(result.skipped, 1)
        self.assertEqual(self.read(self.path), before)
        self.assertIn("TERMINATOR_MISSING", err)


class TestEmitStringLinesRejectsBrokenEscapes(unittest.TestCase):
    """Finding 6: a trailing lone backslash escapes the closing quote."""

    def test_trailing_lone_backslash_is_rejected(self):
        with self.assertRaises(ValueError):
            emit_string_lines("hello\\")

    def test_trailing_lone_backslash_after_a_terminator_is_rejected(self):
        with self.assertRaises(ValueError):
            emit_string_lines("你好" + END + "\\")

    def test_paired_trailing_backslashes_are_allowed(self):
        # An even run of backslashes escapes itself; the closing quote is safe.
        text = "hello" + "\\\\" + END
        self.assertEqual(emit_string_lines(text), ['\t.string "hello\\\\' + END + '"'])

    def test_ordinary_escapes_are_still_emitted(self):
        lines = emit_string_lines("你好" + NL + "世界" + END)
        self.assertEqual(
            lines, ['\t.string "你好' + NL + '"', '\t.string "世界' + END + '"']
        )


class TestPlanGuard(unittest.TestCase):
    """Finding 9: a corpus entry without ``file`` must not crash the plan."""

    def entry(self, **overrides):
        base = {
            "label": "L",
            "index": 0,
            "source": "x" + END,
            "translation": "甲" + END,
            "match_type": "exact",
        }
        base.update(overrides)
        return base

    def test_entry_without_file_key_is_dropped_not_fatal(self):
        plan = build_plan([self.entry()])
        self.assertEqual(plan.injectable, 0)
        self.assertEqual(plan.by_file, {})
        self.assertEqual(plan.dropped_other, 1)
        self.assertEqual(plan.total, 1)

    def test_entry_with_null_file_is_dropped_not_fatal(self):
        plan = build_plan([self.entry(file=None)])
        self.assertEqual(plan.injectable, 0)
        self.assertEqual(plan.by_file, {})
        self.assertEqual(plan.dropped_other, 1)

    def test_entry_with_empty_file_is_dropped_not_fatal(self):
        plan = build_plan([self.entry(file="")])
        self.assertEqual(plan.injectable, 0)
        self.assertEqual(plan.by_file, {})
        self.assertEqual(plan.dropped_other, 1)


class TestCliReportsSkips(InjectorTestBase):
    """A skip must be visible in the run report, not silent."""

    def setUp(self):
        super().setUp()
        self.inc = self.write("data/maps/TestMap/scripts.inc", SAMPLE_INC)
        self.aligned_path = os.path.join(self.tmp, "aligned.json")
        self.translated_path = os.path.join(self.tmp, "translated.json")
        aligned = [
            {
                "id": "x:TestMap_Text_Intro:0",
                "file": "./data/maps/TestMap/scripts.inc",
                "label": "TestMap_Text_Intro",
                "index": 0,
                "source": "A stale source that no longer matches" + END,
                "translation": "你好呀" + END,
                "match_type": "exact",
            }
        ]
        with open(self.aligned_path, "w", encoding="utf-8") as fp:
            json.dump(aligned, fp, ensure_ascii=False, indent=2)
        with open(self.translated_path, "w", encoding="utf-8") as fp:
            json.dump([], fp)

    def test_dry_run_reports_the_skip_and_writes_nothing(self):
        before = self.read(self.inc)
        buf = io.StringIO()
        with contextlib.redirect_stdout(buf):
            code = main(
                [
                    "--aligned", self.aligned_path,
                    "--translated", self.translated_path,
                    "--root", self.tmp,
                    "--dry-run",
                ]
            )
        out = buf.getvalue()
        self.assertEqual(code, 0)
        self.assertEqual(self.read(self.inc), before)
        self.assertRegex(out, r"(?i)skipped[^\n]*1")

    def test_real_run_writes_nothing_for_a_skipped_entry(self):
        before = self.read(self.inc)
        buf = io.StringIO()
        with contextlib.redirect_stdout(buf):
            code = main(
                [
                    "--aligned", self.aligned_path,
                    "--translated", self.translated_path,
                    "--root", self.tmp,
                ]
            )
        self.assertEqual(code, 0)
        self.assertEqual(self.read(self.inc), before)


if __name__ == "__main__":
    unittest.main()
