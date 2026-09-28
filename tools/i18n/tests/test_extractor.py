import os
import tempfile
import unittest

from tools.i18n.extractor import (
    ExtractedEntry,
    extract_strings_from_c,
    extract_strings_from_inc,
    is_meaningful_string,
    scan_repository,
)


def _c(*lines: str) -> str:
    """Join C source lines, so multi-line fixtures stay readable."""
    return "\n".join(lines) + "\n"


class TestMeaningfulString(unittest.TestCase):
    """``is_meaningful_string`` behaviour must not drift: downstream mirrors it."""

    def test_drops_terminator_only(self):
        self.assertFalse(is_meaningful_string("$"))

    def test_drops_control_only(self):
        self.assertFalse(is_meaningful_string("{}"))
        self.assertFalse(is_meaningful_string("{} $"))

    def test_keeps_escape_only_text(self):
        """``\\n`` is two plain characters here, so it still counts as content."""
        self.assertTrue(is_meaningful_string("\\n\\p$"))

    def test_drops_empty(self):
        self.assertFalse(is_meaningful_string(""))

    def test_keeps_real_text(self):
        self.assertTrue(is_meaningful_string("Hello$"))


class TestExtractorInc(unittest.TestCase):
    def test_extract_inc_basic(self):
        inc_content = '''
NewBarkTown_Lab_Text_AideGiveBalls:
\t.string "{PLAYER}!\\p"
\t.string "Use these on your POKéDEX\\n"
\t.string "quest!$"

Empty_Text:
\t.string "$"
'''
        entries = extract_strings_from_inc("data/maps/Test/scripts.inc", inc_content)
        self.assertEqual(len(entries), 1)
        self.assertEqual(entries[0].label, "NewBarkTown_Lab_Text_AideGiveBalls")
        self.assertEqual(entries[0].source, "{PLAYER}!\\pUse these on your POKéDEX\\nquest!$")
        self.assertEqual(entries[0].file, "data/maps/Test/scripts.inc")
        self.assertEqual(entries[0].category, "map_script")

    def test_extract_inc_index_restarts_per_label(self):
        inc_content = _c(
            "Label_A:",
            '\t.string "one$"',
            "Label_B:",
            '\t.string "two$"',
        )
        entries = extract_strings_from_inc("data/maps/Test/scripts.inc", inc_content)
        self.assertEqual([e.label for e in entries], ["Label_A", "Label_B"])
        self.assertEqual([e.index for e in entries], [0, 0])

    # -- D: extractor and injector must agree on block boundaries ------------

    def test_inc_block_ends_at_preprocessor_directive(self):
        """A ``#if`` between two ``.string`` lines ends the first block.

        The injector refuses any block that spans or abuts an ``#if``, and it
        numbers blocks per maximal run of ``.string`` lines.  Merging across the
        directive here made ``(label, index)`` mean something different to the
        two modules, so the entry could never be injected.
        """
        inc_content = _c(
            "SomeLabel:",
            '\t.string "first part\\n"',
            "#if B_SOMETHING",
            '\t.string "second part$"',
            "#endif",
        )
        entries = extract_strings_from_inc("data/maps/Test/scripts.inc", inc_content)
        self.assertEqual([e.source for e in entries], ["first part\\n", "second part$"])
        self.assertEqual([e.index for e in entries], [0, 1])
        self.assertEqual([e.label for e in entries], ["SomeLabel", "SomeLabel"])

    def test_inc_block_ends_at_else_and_endif(self):
        inc_content = _c(
            "SomeLabel:",
            '\t.string "alpha$"',
            "#else",
            '\t.string "beta$"',
            "#endif",
            '\t.string "gamma$"',
        )
        entries = extract_strings_from_inc("data/maps/Test/scripts.inc", inc_content)
        self.assertEqual([e.source for e in entries], ["alpha$", "beta$", "gamma$"])
        self.assertEqual([e.index for e in entries], [0, 1, 2])

    def test_inc_block_ends_at_plain_non_string_line(self):
        """Any non-``.string`` line ends the run, exactly like the injector."""
        inc_content = _c(
            "SomeLabel:",
            '\t.string "first\\n"',
            "\t.byte 0",
            '\t.string "second$"',
        )
        entries = extract_strings_from_inc("data/maps/Test/scripts.inc", inc_content)
        self.assertEqual([e.source for e in entries], ["first\\n", "second$"])
        self.assertEqual([e.index for e in entries], [0, 1])

    def test_inc_directive_only_label_is_ignored(self):
        inc_content = _c(
            "#if B_SOMETHING",
            '\t.string "orphan$"',
            "#endif",
        )
        self.assertEqual(extract_strings_from_inc("data/maps/Test/scripts.inc", inc_content), [])

    def test_inc_text_data_category(self):
        entries = extract_strings_from_inc("data/text/trainers.inc", 'T:\n\t.string "hi$"\n')
        self.assertEqual(entries[0].category, "text_data")


class TestExtractorC(unittest.TestCase):
    def test_extract_c_basic(self):
        c_content = '''
static const u8 sText_Option[] = _("SETTING");
const u8 gText_Empty[] = _("");
const u8 gText_Welcome[] = _("Welcome to POKéMON!");
'''
        entries = extract_strings_from_c("src/data/text/test.h", c_content)
        self.assertEqual(len(entries), 2)
        self.assertEqual(entries[0].label, "sText_Option")
        self.assertEqual(entries[0].source, "SETTING")
        self.assertEqual(entries[1].label, "gText_Welcome")
        self.assertEqual(entries[1].source, "Welcome to POKéMON!")
        self.assertEqual(entries[0].category, "c_source")

    def test_skip_still_advances_index(self):
        """Legacy ``src/data/text`` entries keep the file-global macro ordinal.

        ``injector._inject_c`` counts ``_("...")`` arrays the same way, so this
        numbering is what the committed injection corpus is keyed on.
        """
        entries = extract_strings_from_c(
            "src/data/text/x.h",
            'const u8 a[] = _("");\nconst u8 b[] = _("B");\n',
        )
        self.assertEqual(len(entries), 1)
        self.assertEqual(entries[0].label, "b")
        self.assertEqual(entries[0].index, 1)

    def test_engine_c_index_counts_occurrences_of_the_label(self):
        """Engine entries number per label, like ``.inc`` blocks do.

        A file-global ordinal would shift every entry whenever an unrelated
        macro call is added above it, which breaks joining two refs of a file.
        """
        c_content = _c(
            'const u8 gText_C[] = _("C");',
            'const u8 gText_A[] = _("A");',
            'const u8 gText_B[] = _("B");',
        )
        entries = extract_strings_from_c("src/strings.c", c_content)
        self.assertEqual([e.label for e in entries], ["gText_C", "gText_A", "gText_B"])
        self.assertEqual([e.index for e in entries], [0, 0, 0])

    # -- A: adjacent C string literal concatenation -------------------------

    def test_compound_string_concatenates_adjacent_literals(self):
        c_content = _c(
            "const struct Item gItems[] =",
            "{",
            "    [ITEM_STRANGE_BALL] =",
            "    {",
            '        .name = ITEM_NAME("STRANGE BALL"),',
            "        .description = COMPOUND_STRING(",
            '            "An unusual Ball\\n"',
            '            "warped through\\n"',
            '            "space and time."),',
            "    },",
            "};",
        )
        entries = extract_strings_from_c("src/data/items.h", c_content)
        by_label = {e.label: e for e in entries}
        self.assertEqual(
            by_label["ITEM_STRANGE_BALL.description"].source,
            "An unusual Ball\\nwarped through\\nspace and time.",
        )
        self.assertEqual(by_label["ITEM_STRANGE_BALL.name"].source, "STRANGE BALL")
        self.assertEqual(len(entries), 2)

    def test_underscore_macro_concatenates_across_lines(self):
        c_content = _c(
            "static const u8 sGMaxOneBlowDescription[] = _(",
            '    "G-max Urshifu attack.\\n"',
            '    "Ignores Max Guard.");',
        )
        entries = extract_strings_from_c("src/data/moves_info.h", c_content)
        self.assertEqual(len(entries), 1)
        self.assertEqual(entries[0].label, "sGMaxOneBlowDescription")
        self.assertEqual(
            entries[0].source, "G-max Urshifu attack.\\nIgnores Max Guard."
        )

    def test_backslash_continuation_inside_define(self):
        c_content = _c(
            "#define sLongText \\",
            "    COMPOUND_STRING( \\",
            '        "first part\\n" \\',
            '        "second part")',
            "",
            "const u8 *const gUses[] = { sLongText };",
        )
        entries = extract_strings_from_c("src/data/items.h", c_content)
        self.assertEqual(len(entries), 1)
        self.assertEqual(entries[0].label, "sLongText")
        self.assertEqual(entries[0].source, "first part\\nsecond part")

    def test_adjacent_literals_are_one_logical_string_not_two(self):
        """The single-literal regex bug: items.h lost 790 of 792 strings."""
        c_content = _c(
            "    [ITEM_POKE_BALL] =",
            "    {",
            "        .description = COMPOUND_STRING(",
            '            "A tool used for\\n"',
            '            "catching wild\\n"',
            '            "POKéMON."),',
            "    },",
        )
        entries = extract_strings_from_c("src/data/items.h", c_content)
        self.assertEqual(len(entries), 1)
        self.assertEqual(
            entries[0].source, "A tool used for\\ncatching wild\\nPOKéMON."
        )

    # -- B: new macros ------------------------------------------------------

    def test_item_name_and_plural_name(self):
        c_content = _c(
            "    [ITEM_POKE_BALL] =",
            "    {",
            '        .name = ITEM_NAME("POKé BALL"),',
            '        .pluralName = ITEM_PLURAL_NAME("POKé BALLS"),',
            "    },",
        )
        entries = extract_strings_from_c("src/data/items.h", c_content)
        by_label = {e.label: e.source for e in entries}
        self.assertEqual(by_label["ITEM_POKE_BALL.name"], "POKé BALL")
        self.assertEqual(by_label["ITEM_POKE_BALL.pluralName"], "POKé BALLS")

    def test_compound_string_size_limit(self):
        c_content = _c(
            'static const u8 sShort[] = COMPOUND_STRING_SIZE_LIMIT("A tool.", ITEM_DESCRIPTION_LENGTH);'
        )
        entries = extract_strings_from_c("src/data/items.h", c_content)
        self.assertEqual(len(entries), 1)
        self.assertEqual(entries[0].label, "sShort")
        self.assertEqual(entries[0].source, "A tool.")

    def test_size_limit_is_not_mistaken_for_compound_string(self):
        c_content = _c('static const u8 sShort[] = COMPOUND_STRING_SIZE_LIMIT("hi", LIMIT);')
        entries = extract_strings_from_c("src/data/items.h", c_content)
        self.assertEqual([e.source for e in entries], ["hi"])

    def test_macro_template_definitions_yield_no_entries(self):
        """``#define ITEM_NAME(str) COMPOUND_STRING_SIZE_LIMIT(str, ...)`` is a
        template, not text.  Extracting it would invent an untranslatable entry."""
        c_content = _c(
            "#define ITEM_NAME(str) COMPOUND_STRING_SIZE_LIMIT(str, ITEM_NAME_LENGTH)",
            "#define ITEM_PLURAL_NAME(str) COMPOUND_STRING_SIZE_LIMIT(str, ITEM_NAME_PLURAL_LENGTH)",
        )
        self.assertEqual(extract_strings_from_c("src/data/items.h", c_content), [])

    def test_empty_compound_string_is_dropped(self):
        c_content = _c(
            "    [MOVE_NONE] =",
            "    {",
            '        .name = COMPOUND_STRING("None"),',
            '        .description = COMPOUND_STRING(""),',
            "    },",
        )
        entries = extract_strings_from_c("src/data/moves_info.h", c_content)
        self.assertEqual([e.source for e in entries], ["None"])
        self.assertEqual([e.label for e in entries], ["MOVE_NONE.name"])

    def test_no_alnum_string_is_still_dropped(self):
        """``is_meaningful_string`` is shared with the injector: it stays as is.

        ``[MOVE_NONE].name`` is the literal ``"-"``, which has no alphanumeric
        character and so is filtered out exactly as it was before.
        """
        c_content = _c('static const u8 sDash[] = COMPOUND_STRING("-");')
        self.assertEqual(extract_strings_from_c("src/data/moves_info.h", c_content), [])

    # -- E: usable, unique labels -------------------------------------------

    def test_sized_array_declaration_label(self):
        c_content = _c('const u8 gText_EggNickname[POKEMON_NAME_LENGTH + 1] = _("EGG");')
        entries = extract_strings_from_c("src/strings.c", c_content)
        self.assertEqual(entries[0].label, "gText_EggNickname")

    def test_struct_field_labels_are_unique_and_addressable(self):
        c_content = _c(
            "const struct Item gItems[] =",
            "{",
            "    [ITEM_POKE_BALL] =",
            "    {",
            '        .name = COMPOUND_STRING("POKé BALL"),',
            '        .description = COMPOUND_STRING("A Ball."),',
            "    },",
            "    [ITEM_GREAT_BALL] =",
            "    {",
            '        .name = COMPOUND_STRING("GREAT BALL"),',
            '        .description = COMPOUND_STRING("A better Ball."),',
            "    },",
            "};",
        )
        entries = extract_strings_from_c("src/data/items.h", c_content)
        labels = [e.label for e in entries]
        self.assertEqual(
            labels,
            [
                "ITEM_POKE_BALL.name",
                "ITEM_POKE_BALL.description",
                "ITEM_GREAT_BALL.name",
                "ITEM_GREAT_BALL.description",
            ],
        )
        self.assertEqual(len(set(labels)), len(labels))
        self.assertEqual(len({e.id for e in entries}), len(entries))

    def test_move_field_label_uses_designator(self):
        c_content = _c(
            "const struct MoveInfo gMovesInfo[] =",
            "{",
            "    [MOVE_POUND] =",
            "    {",
            '        .name = COMPOUND_STRING("POUND"),',
            "        .description = COMPOUND_STRING(",
            '            "Pounds the foe with\\n"',
            '            "forelegs or tail."),',
            "    },",
            "};",
        )
        entries = extract_strings_from_c("src/data/moves_info.h", c_content)
        by_label = {e.label: e.source for e in entries}
        self.assertEqual(by_label["MOVE_POUND.name"], "POUND")
        self.assertEqual(
            by_label["MOVE_POUND.description"], "Pounds the foe with\\nforelegs or tail."
        )

    def test_species_field_labels(self):
        c_content = _c(
            "const struct SpeciesInfo gSpeciesInfo[] =",
            "{",
            "    [SPECIES_BULBASAUR] =",
            "    {",
            '        .speciesName = _("Bulbasaur"),',
            '        .categoryName = _("Seed"),',
            "        .description = COMPOUND_STRING(",
            '            "A strange seed was\\n"',
            '            "planted on its back."),',
            "    },",
            "};",
        )
        entries = extract_strings_from_c("src/data/pokemon/species_info/gen_1_families.h", c_content)
        labels = [e.label for e in entries]
        self.assertEqual(
            labels,
            ["SPECIES_BULBASAUR.speciesName", "SPECIES_BULBASAUR.categoryName", "SPECIES_BULBASAUR.description"],
        )

    def test_labels_are_unique_when_no_name_is_available(self):
        c_content = _c(
            "static const u8 *const gList[] =",
            "{",
            '    _("one"),',
            '    _("two"),',
            "};",
        )
        entries = extract_strings_from_c("src/strings.c", c_content)
        self.assertEqual([e.source for e in entries], ["one", "two"])
        self.assertEqual(len({e.label for e in entries}), 2)

    def test_wrapped_designator_uses_the_inner_identifier(self):
        """``[EC_INDEX(EC_WORD_DARK)]`` names the row ``EC_WORD_DARK``.

        Taking the whole bracket text would give ``EC_INDEX``, and giving up
        would collide every row in the file on ``gEasyChatGroup_Status.text``.
        """
        c_content = _c(
            "const struct EasyChatWordInfo gEasyChatGroup_Status[] = {",
            "    [EC_INDEX(EC_WORD_DARK)] =",
            "    {",
            '        .text = COMPOUND_STRING("DARK"),',
            "    },",
            "    [EC_INDEX(EC_WORD_STENCH)] =",
            "    {",
            '        .text = COMPOUND_STRING("STENCH"),',
            "    },",
            "};",
        )
        entries = extract_strings_from_c("src/data/easy_chat/easy_chat_group_status.h", c_content)
        self.assertEqual(
            [e.label for e in entries], ["EC_WORD_DARK.text", "EC_WORD_STENCH.text"]
        )

    def test_array_declaration_sharing_a_line_with_the_brace(self):
        """``gFoo[] = { ... }`` puts the container name and the brace together."""
        c_content = _c(
            "const u8 *const gList[] = {",
            '    _("one"),',
            '    _("two"),',
            "};",
        )
        entries = extract_strings_from_c("src/strings.c", c_content)
        self.assertEqual([e.label for e in entries], ["gList[0]", "gList[1]"])

    def test_index_keeps_running_across_nested_entry_braces(self):
        c_content = _c(
            "static const struct MenuAction MultichoiceList_Bike[] =",
            "{",
            '    {COMPOUND_STRING("MACH")},',
            '    {COMPOUND_STRING("ACRO")},',
            "};",
        )
        entries = extract_strings_from_c("src/data/script_menu.h", c_content)
        self.assertEqual(
            [e.label for e in entries],
            ["MultichoiceList_Bike[0]", "MultichoiceList_Bike[1]"],
        )

    def test_multi_dimensional_array_declaration_label(self):
        c_content = _c('ALIGNED(4) const u8 gText_123Dot[][3] = {_("1."), _("2."), _("3.")};')
        entries = extract_strings_from_c("src/strings.c", c_content)
        self.assertEqual([e.label for e in entries], ["gText_123Dot[0]", "gText_123Dot[1]", "gText_123Dot[2]"])

    def test_array_brackets_win_over_designator_brackets(self):
        """``gText[LIMIT] =`` is a declaration, not a designator."""
        c_content = _c(
            "const u8 *const gBattleStringsTable[STRINGID_COUNT] = {",
            '    [STRINGID_INTRO] = _("intro"),',
            "};",
        )
        entries = extract_strings_from_c("src/battle_message.c", c_content)
        self.assertEqual([e.label for e in entries], ["gBattleStringsTable.STRINGID_INTRO"])

    def test_conditional_redefinition_keeps_a_unique_id(self):
        """``src/`` redefines some labels in ``#if``/``#else`` branches."""
        c_content = _c(
            "    [MOVE_HAIL] =",
            "    {",
            "#if SNOW",
            "        .description = COMPOUND_STRING(",
            '            "Summons a snowstorm."),',
            "#else",
            "        .description = COMPOUND_STRING(",
            '            "Summons a hailstorm."),',
            "#endif",
            "    },",
        )
        entries = extract_strings_from_c("src/data/moves_info.h", c_content)
        self.assertEqual([e.label for e in entries], ["MOVE_HAIL.description"] * 2)
        self.assertEqual([e.index for e in entries], [0, 1])
        self.assertEqual(len({e.id for e in entries}), 2)

    def test_same_source_in_two_labels_keeps_its_own_index(self):
        """Numbering per label keeps an entry unique without a file-global ordinal."""
        c_content = _c(
            'const u8 gText_A[] = _("SAME");',
            'const u8 gText_B[] = _("SAME");',
        )
        entries = extract_strings_from_c("src/strings.c", c_content)
        self.assertEqual([(e.label, e.index) for e in entries], [("gText_A", 0), ("gText_B", 0)])
        self.assertEqual(len({e.id for e in entries}), 2)

    def test_category_is_engine_c_for_new_roots(self):
        entries = extract_strings_from_c("src/strings.c", 'const u8 gText_A[] = _("A");\n')
        self.assertEqual(entries[0].category, "engine_c")

    def test_string_in_comment_is_not_extracted(self):
        c_content = _c(
            "// const u8 gText_Commented[] = _(\"COMMENTED\");",
            'const u8 gText_Real[] = _("REAL");',
        )
        entries = extract_strings_from_c("src/strings.c", c_content)
        self.assertEqual([e.source for e in entries], ["REAL"])

    def test_entry_fields_are_the_public_schema(self):
        entries = extract_strings_from_c("src/strings.c", 'const u8 gText_A[] = _("A");\n')
        self.assertEqual(
            sorted(vars(entries[0]).keys()),
            ["category", "file", "id", "index", "label", "source"],
        )
        self.assertEqual(entries[0].id, "src/strings.c:gText_A:0")


class TestScanRepository(unittest.TestCase):
    """The scan set is explicit: engine text files in, debug tooling out."""

    def _write(self, root: str, relpath: str, text: str) -> None:
        path = os.path.join(root, *relpath.split("/"))
        os.makedirs(os.path.dirname(path), exist_ok=True)
        with open(path, "w", encoding="utf-8") as handle:
            handle.write(text)

    def _scan_into_temp_tree(self) -> list:
        with tempfile.TemporaryDirectory() as tmp:
            self._write(tmp, "data/maps/Test/scripts.inc", 'L:\n\t.string "map text$"\n')
            self._write(tmp, "data/text/trainers.inc", 'T:\n\t.string "trainer text$"\n')
            self._write(tmp, "data/scripts/common.inc", 'L:\n\t.string "common text$"\n')
            self._write(tmp, "src/strings.c", 'const u8 gTextA[] = _("A");\n')
            self._write(tmp, "src/battle_message.c", 'const u8 gTextB[] = _("B");\n')
            self._write(tmp, "src/data/text/x.h", 'const u8 gTextC[] = _("C");\n')
            self._write(
                tmp,
                "src/data/items.h",
                _c(
                    "    [ITEM_POKE_BALL] =",
                    "    {",
                    '        .name = ITEM_NAME("POKé BALL"),',
                    "    },",
                ),
            )
            self._write(
                tmp,
                "src/data/moves_info.h",
                _c(
                    "    [MOVE_POUND] =",
                    "    {",
                    '        .name = COMPOUND_STRING("POUND"),',
                    "    },",
                ),
            )
            self._write(
                tmp,
                "src/data/pokemon/species_info.h",
                'const u8 gTextD[] = _("D");\n',
            )
            self._write(
                tmp,
                "src/data/pokemon/species_info/gen_1_families.h",
                'const u8 gTextE[] = _("E");\n',
            )
            # Debug tooling must stay out of the corpus.
            self._write(tmp, "src/debug.c", 'const u8 gTextDebug[] = _("DEBUG");\n')
            self._write(tmp, "src/battle_debug.c", 'const u8 gTextDebug2[] = _("DEBUG2");\n')
            self._write(tmp, "src/random_other.c", 'const u8 gTextOther[] = _("OTHER");\n')
            return scan_repository(tmp)

    def test_scan_covers_engine_text_roots(self):
        entries = self._scan_into_temp_tree()
        sources = {e.source for e in entries}
        for expected in ["map text$", "trainer text$", "common text$", "A", "B", "C", "POKé BALL", "POUND", "D", "E"]:
            self.assertIn(expected, sources)

    def test_scan_skips_debug_and_unlisted_sources(self):
        entries = self._scan_into_temp_tree()
        sources = {e.source for e in entries}
        for unexpected in ["DEBUG", "DEBUG2", "OTHER"]:
            self.assertNotIn(unexpected, sources)

    def test_scan_categories(self):
        entries = self._scan_into_temp_tree()
        by_source = {e.source: e.category for e in entries}
        self.assertEqual(by_source["map text$"], "map_script")
        self.assertEqual(by_source["trainer text$"], "text_data")
        self.assertEqual(by_source["common text$"], "text_data")
        self.assertEqual(by_source["C"], "c_source")
        self.assertEqual(by_source["A"], "engine_c")

    def test_scan_labels_for_scanned_roots(self):
        entries = self._scan_into_temp_tree()
        by_source = {e.source: e.label for e in entries}
        self.assertEqual(by_source["A"], "gTextA")
        self.assertEqual(by_source["POKé BALL"], "ITEM_POKE_BALL.name")
        self.assertEqual(by_source["POUND"], "MOVE_POUND.name")

    def test_scan_ids_are_unique(self):
        entries = self._scan_into_temp_tree()
        self.assertEqual(len({e.id for e in entries}), len(entries))


class TestExtractedEntrySchema(unittest.TestCase):
    def test_inc_entry_fields(self):
        entry = extract_strings_from_inc("data/maps/X/scripts.inc", 'L:\n\t.string "hi$"\n')[0]
        self.assertIsInstance(entry, ExtractedEntry)
        self.assertEqual(
            sorted(vars(entry).keys()),
            ["category", "file", "id", "index", "label", "source"],
        )


if __name__ == '__main__':
    unittest.main()
