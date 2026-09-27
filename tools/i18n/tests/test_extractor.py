import unittest
from tools.i18n.extractor import extract_strings_from_inc, extract_strings_from_c, ExtractedEntry

class TestExtractor(unittest.TestCase):
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

if __name__ == '__main__':
    unittest.main()
