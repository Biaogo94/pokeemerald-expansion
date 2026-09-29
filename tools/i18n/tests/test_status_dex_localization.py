"""Source/asset regression checks; not a substitute for emulator screenshots."""
import re
from pathlib import Path

import pytest
from PIL import Image

ROOT = Path(__file__).resolve().parents[3]
DEX = ROOT / 'src/pokedex_plus_hgss.c'
# Hand-hinted, single-character 9x7 badges: an ordinary 10x13 Chinese
# font cannot fit the healthbox's immutable three-tile (24x8) status slot.
# Order follows HEALTHBOX_GFX_STATUS_* and the party/summary animation table.
BADGES = {
    '毒': ('011111000','000100000','111111111','010010010','010111010','010100010','011111110'),
    '麻': ('010000000','111111111','100000000','100100010','011101110','001000100','010101010'),
    '眠': ('011000111','010100101','011000111','010100101','011000111','010100101','011000111'),
    '冻': ('100000111','100000101','000000111','100011111','000001010','100000100','000000011'),
    '灼': ('010000000','010001111','011000100','010101011','100100010','100000001','100000110'),
    '霜': ('111111111','010101010','111111111','010000000','011101111','001001010','010101010'),
    '菌': ('010000100','111111111','000010000','011111110','010001010','010001010','011111110'),
    '濒': ('100000110','100000110','100000110','100000000','100000111','100000100','100000111'),
}
BATTLE_ORDER = '毒麻眠冻灼霜'
PARTY_ORDER = '毒麻眠冻灼菌濒霜'
STATUS_PATHS = [
    f'graphics/battle_interface/{style}/status{suffix}.png'
    for style in ('hns', 'gen4') for suffix in ('', '2', '3', '4')
] + ['graphics/interface/status_icons.png']
HEADERS = {'HP':'体力', 'Attack':'攻击', 'Defense':'防御',
           'Speed':'速度', 'SpAttack':'特攻', 'SpDefense':'特防'}
EVOLUTION = {
    '使用{STR_VAR_2}', '{UP_ARROW_2}亲密度', '攻击>防御', '攻击=防御',
    '攻击<防御', '{UP_ARROW_2}美丽', '{UP_ARROW_2}帅气',
    '{UP_ARROW_2}聪明', '{UP_ARROW_2}强壮', '{UP_ARROW_2}可爱', '不在',
}

def source():
    return DEX.read_text(encoding='utf-8')

@pytest.mark.parametrize('path', STATUS_PATHS)
def test_status_badge_pixels_are_chinese(path):
    im = Image.open(ROOT / path)
    party = 'interface/status_icons' in path
    assert im.mode == 'P'
    assert im.size == ((32, 64) if party else (24, 48))
    order = PARTY_ORDER if party else BATTLE_ORDER
    x0 = 11 if party else 5
    for row, char in enumerate(order):
        actual = tuple(''.join('1' if im.getpixel((x0+x, row*8+y)) % 16 == 2
                               else '0' for x in range(9)) for y in range(7))
        assert actual == BADGES[char], (path, char, actual)

def test_status_sheets_keep_palette_mode_and_geometry():
    for path in STATUS_PATHS:
        im = Image.open(ROOT / path)
        assert im.mode == 'P', path
        # English knockout fully erased inside the badge rect; the white
        # frame pixels at the sheet edges are original design, not text.
        party = 'interface/status_icons' in path
        order = PARTY_ORDER if party else BATTLE_ORDER
        x0, rect = (11, (7, 26)) if party else (5, (1, 18))
        for row in range(len(order)):
            stray = [(x, y) for y in range(row*8, row*8+8) for x in range(*rect)
                     if im.getpixel((x, y)) % 16 == 2 and not (x0 <= x < x0+9)]
            assert not stray, (path, row, stray[:4])

@pytest.mark.parametrize('key,text', HEADERS.items())
def test_dex_stat_headers_are_localized(key, text):
    assert f'sText_Stats_{key}[] = _("{text}");' in source()

@pytest.mark.parametrize('text', sorted(EVOLUTION))
def test_dex_evolution_conditions_are_localized(text):
    assert f'COMPOUND_STRING("{text}")' in source()

def test_hisui_is_not_sinjoh():
    assert re.search(r'case REGION_HISUI:.*COMPOUND_STRING\("洗翠"\)', source())

def test_stat_headers_fit_existing_columns_and_glyphs():
    text = source()
    # FONT_SMALL Chinese advances 10px; labels precede numbers by 23px.
    assert 'u8 base_x_first_row = 23;' in text
    assert 'u8 base_x_second_row = 43;' in text
    engine = (ROOT / 'src/chinese_text.c').read_text(encoding='utf-8')
    assert 'width = 10;' in engine
    charmap = dict(re.findall(r"^'(.)' = ([0-9A-F]{4})$",
                             (ROOT / 'charmap.txt').read_text(encoding='utf-8'), re.M))
    font = Image.open(ROOT / 'graphics/fonts/chinese_small.png')
    for label in HEADERS.values():
        assert len(label)*10 <= 23
        for char in label:
            value = int(charmap[char], 16)
            hi, lo = value >> 8, value & 255
            assert hi not in (6, 27) and lo <= 246
            hi -= hi > 27
            hi -= hi > 6
            idx = ((hi-1) << 8) | lo
            x, y = idx % 16 * 16, idx // 16 * 16
            assert y+16 <= font.height
            assert any(font.getpixel((x+dx,y+dy)) == 1
                       for dx in range(10) for dy in range(13))

def test_dex_descriptions_and_categories_have_no_english_prose():
    # All source branches, not a count of distinct obtainable HnS species.
    files = sorted((ROOT / 'src/data/pokemon/species_info').glob('gen_*_families.h'))
    descriptions, categories = [], []
    for path in files:
        text = path.read_text(encoding='utf-8')
        descriptions += re.findall(r'\.description\s*=\s*COMPOUND_STRING\((.*?)\)', text, re.S)
        categories += re.findall(r'\.categoryName\s*=\s*_\("(.*?)"\)', text)
    assert len(descriptions) >= 1315
    assert len(categories) >= 1343
    shared = (ROOT / 'src/data/pokemon/species_info/shared_dex_text.h').read_text(encoding='utf-8')
    shared_descriptions = re.findall(r'const u8 \w+\[\]\s*=\s*_\((.*?)\);', shared, re.S)
    assert len(shared_descriptions) >= 46
    def joined(raw):
        # The C compiler concatenates adjacent literals ("...UF" "O...").
        return re.sub(r'\{[^}]*\}', '', ''.join(re.findall(r'"((?:\\.|[^"\\])*)"', raw)))
    for raw in descriptions + shared_descriptions:
        text = joined(raw).replace('\\n', '')
        words = re.findall(r'[A-Za-z]+', text)
        # X字/Y字 shape symbols and official-style "将其KO" are not prose.
        assert set(words) <= {'DNA', 'UFO', 'X', 'Y', 'KO'}, text
        assert re.search(r'[一-鿿]', text), text
    for text in categories:
        text = re.sub(r'\{[^}]*\}', '', text)
        words = re.findall(r'[A-Za-z]+', text)
        assert set(words) <= {'DNA', 'UFO', 'X', 'Y', 'KO'}, text
