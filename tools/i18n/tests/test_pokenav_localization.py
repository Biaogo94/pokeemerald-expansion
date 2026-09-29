"""Pixel-level HnS Pokégear checks; PNG sources are compiled as indexed GBA tiles.

Layout facts (verified against the engine):
- Option labels are 32x16 sprites (SPRITE_SIZE(32x16) in pokenav_menu_handler_gfx.c),
  so only the top strip of each 32x64 sheet is ever displayed. Chinese labels
  are two 9x7 font-downscaled glyphs right-aligned to x29 in rows y4..13.
- Left headers carry their word in y4..13 (32px wide) or y7..16 (64px wide).
- hns/left_headers/hoenn_map.png is deliberately blank; do not paint it.
- hns/header.png is a 53-tile sheet composed by hns/header.bin; the label is
  stamped centred in the former "POKéMON GEAR" span.
"""

import re
import struct
from pathlib import Path

from PIL import Image


ROOT = Path(__file__).resolve().parents[3]
NAV = ROOT / 'graphics/pokenav'
CHARMAP = (ROOT / 'charmap.txt').read_text(encoding='utf-8')
FONT = Image.open(ROOT / 'graphics/fonts/chinese_small.png')

OPTIONS = {
    'hns/options/hoenn_map.png': '地图',
    'options/condition.png': '状况',
    'hns/options/match_call.png': '电话',
    'options/ribbons.png': '奖章',
    'options/switch_off.png': '关闭',
    'options/party.png': '同行',
    'options/search.png': '搜索',
    'options/cool.png': '帅气',
    'options/beauty.png': '美丽',
    'options/cute.png': '可爱',
    'options/smart.png': '聪明',
    'options/tough.png': '强壮',
    'options/cancel.png': '返回',
    'hns/options/radio.png': '广播',
}
HEADERS = {
    'left_headers/main_menu.png': '宝可装置',
    'left_headers/condition.png': '状况',
    'left_headers/ribbons.png': '奖章',
    'hns/left_headers/match_call.png': '电话',
    'left_headers/party.png': '同行',
    'left_headers/search.png': '搜索',
    'left_headers/cool.png': '帅气',
    'left_headers/beauty.png': '美丽',
    'left_headers/cute.png': '可爱',
    'left_headers/smart.png': '聪明',
    'left_headers/tough.png': '强壮',
}
FILL, OUTLINE = 2, 1
INK = (FILL, OUTLINE)


def glyph(char):
    m = re.search(r"'" + re.escape(char) + r"' = ([0-9A-F]+)", CHARMAP)
    code = int(m.group(1), 16)
    hi, lo = code >> 8, code & 255
    if hi > 0x1B:
        hi -= 1
    if hi > 0x06:
        hi -= 1
    idx = ((hi - 1) << 8) | lo
    x, y = (idx % 16) * 16, (idx // 16) * 16
    ink = FONT.crop((x, y, x + 10, y + 13))
    small = ink.resize((9, 7), Image.LANCZOS)
    px = small.load()
    return [[1 if px[i, j] > 0 else 0 for i in range(9)] for j in range(7)]


def assert_label(im, label, x0, y0, band_top, band_bottom, advance=10):
    px = im.load()
    for n, char in enumerate(label):
        gl = glyph(char)
        for j in range(7):
            for i in range(9):
                p = px[x0 + advance * n + i, y0 + j]
                if gl[j][i]:
                    assert p in INK, (im, char, x0 + advance * n + i, y0 + j, p)
    # Nothing else in the text band: the English knockout is fully erased and
    # the label cannot overflow the displayed strip. The left outline extends
    # one pixel beyond the glyph boxes (x0-1 .. advance*n+8).
    for y in range(band_top, band_bottom + 1):
        for x in range(im.width):
            if px[x, y] in INK:
                inside = x0 - 1 <= x < x0 + advance * (len(label) - 1) + 9
                assert inside and y0 <= y < y0 + 7, (im, x, y)


def test_option_labels_are_chinese_and_fit_the_32x16_sprite():
    for path, label in OPTIONS.items():
        im = Image.open(NAV / path)
        assert im.size == (32, 64), path
        assert_label(im, label, 10, 5, 4, 13)
        assert im.width >= 10 + 10 * len(label) - 1  # no off-sheet pixels


def test_left_headers_are_chinese():
    for path, label in HEADERS.items():
        im = Image.open(NAV / path)
        if im.width == 64:
            assert_label(im, label, (64 - 10 * len(label)) // 2, 8, 7, 16)
        else:
            assert_label(im, label, (32 - 10 * len(label)) // 2, 5, 4, 13)


def test_blank_hns_map_header_stays_transparent():
    blank = Image.open(NAV / 'hns/left_headers/hoenn_map.png')
    assert blank.size == (64, 96)
    assert set(blank.getdata()) == {0}


def test_palette_indices_stay_gba_safe():
    for path in (*OPTIONS, *HEADERS, 'hns/header.png'):
        im = Image.open(NAV / path)
        assert im.mode == 'P', path
        assert max(im.getdata()) < 16, path


def _render_header():
    sheet = Image.open(NAV / 'hns/header.png')
    assert sheet.size == (424, 8)  # 53-tile budget from the gfx rule
    data = (NAV / 'hns/header.bin').read_bytes()
    entries = struct.unpack(f'<{len(data) // 2}H', data)
    out = Image.new('P', (256, 16))
    out.putpalette(sheet.getpalette())
    tw = sheet.width // 8
    for i, e in enumerate(entries[:64]):
        t = e & 1023
        assert t < 53
        part = sheet.crop(((t % tw) * 8, (t // tw) * 8, (t % tw) * 8 + 8, (t // tw) * 8 + 8))
        if e & 1024:
            part = part.transpose(Image.Transpose.FLIP_LEFT_RIGHT)
        if e & 2048:
            part = part.transpose(Image.Transpose.FLIP_TOP_BOTTOM)
        out.paste(part, ((i % 32) * 8, (i // 32) * 8))
    return out


def test_header_bar_shows_pokenav_name_and_no_english():
    out = _render_header()
    assert_label(out, '宝可装置', 56, 6, 4, 15)
    # tilemap sanity: indices in budget, palette banks valid
    data = (NAV / 'hns/header.bin').read_bytes()
    entries = struct.unpack(f'<{len(data) // 2}H', data)
    assert max(e & 1023 for e in entries) < 53
    assert all((e >> 12) < 16 for e in entries)


def test_live_pokenav_literals_match_labels():
    handler = (ROOT / 'src/pokenav_menu_handler_gfx.c').read_text(encoding='utf-8')
    main = (ROOT / 'src/pokenav_main_menu.c').read_text(encoding='utf-8')
    assert '收起宝可装置。' in handler
    assert '返回宝可装置菜单。' in handler
    for message in ('{A_BUTTON}奖章 {B_BUTTON}取消', '{A_BUTTON}查看 {B_BUTTON}取消'):
        assert message in main
    assert '宝可梦齿轮' not in handler
