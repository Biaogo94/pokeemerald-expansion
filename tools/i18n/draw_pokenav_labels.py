"""Redraw Pokégear option icons, left headers and the header bar in Chinese.

Rules derived from the originals (all verified by pixel dumps):
- Option icons (32x64): only the top 32x16 strip is displayed
  (SPRITE_SIZE(32x16)); the English word sits right-aligned in y4..13,
  x16..29 using palette indices 1 (outline) and 2 (fill).
- Left headers 32x64: word in y4..13; decorations below share the palette,
  so erasing is restricted to the text rows.
- Left headers 64x64: word in y7..16; hns/hoenn_map stays blank.
- Header bar: header.bin places header.png tiles; "POKéMON GEAR" occupies
  screen x16..135 of the rendered strip.

Chinese glyphs reuse the chinese_small font ink downscaled to 9x7 (the only
size fitting these 8-10px tall bands).
"""

import re
import struct
from collections import Counter
from pathlib import Path

from PIL import Image

ROOT = Path(__file__).resolve().parents[2]
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
GLYPH_CACHE = {}


def glyph(char):
    if char not in GLYPH_CACHE:
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
        GLYPH_CACHE[char] = [[1 if px[i, j] > 0 else 0 for i in range(9)] for j in range(7)]
    return GLYPH_CACHE[char]


def erase_rows(im, y0, y1):
    """Blank letter pixels in the text rows; keep decoration below untouched."""
    px = im.load()
    for y in range(y0, y1 + 1):
        for x in range(im.width):
            if px[x, y] in (FILL, OUTLINE):
                px[x, y] = 8  # main pill background in every sheet


def stamp_text(im, label, x0, y0, advance=10):
    px = im.load()
    for n, char in enumerate(label):
        gl = glyph(char)
        for j in range(7):
            for i in range(9):
                if gl[j][i]:
                    px[x0 + advance * n + i, y0 + j] = FILL
        # left/top outline in index 1, echoing the original letter style
        for j in range(7):
            for i in range(9):
                x, y = x0 + advance * n + i, y0 + j
                if gl[j][i] and (i == 0 or not gl[j][i - 1]) and px[x - 1, y] not in (FILL, OUTLINE):
                    px[x - 1, y] = OUTLINE


def relabel(path, label, text_rows, x0):
    im = Image.open(NAV / path)
    assert im.size == (32, 64) or (im.size == (64, 64) and path in HEADERS), path
    erase_rows(im, *text_rows)
    stamp_text(im, label, x0, text_rows[0] + (text_rows[1] - text_rows[0] + 1 - 7) // 2)
    im.save(NAV / path)
    print(f'{path}: {label}')


for path, label in OPTIONS.items():
    relabel(path, label, (4, 13), 10)  # 2 chars * 10px, right edge x29

for path, label in HEADERS.items():
    im = Image.open(NAV / path)
    if im.width == 64:
        relabel(path, label, (7, 16), (64 - 10 * len(label)) // 2)
    else:
        relabel(path, label, (4, 13), (32 - 10 * len(label)) // 2)

# Header bar. Shared background tiles make a whole-screen rewrite unsafe:
# erase the letter tiles in place (every shared usage sits inside the text
# span), then give the ten stamp positions their own tile slots (the sheet
# budget is 53 tiles; only 41 are used) and patch header.bin accordingly.
sheet = Image.open(NAV / 'hns/header.png')
assert sheet.size == (424, 8)  # 53 tiles
bin_data = (NAV / 'hns/header.bin').read_bytes()
entries = list(struct.unpack(f'<{len(bin_data) // 2}H', bin_data))
tw = sheet.width // 8
usage = Counter(e & 1023 for e in entries)
next_free = max(usage) + 1
assert next_free + 8 <= 53, next_free

TEXT_TILES = {e & 1023 for c in range(2, 17) for e in (entries[c], entries[32 + c])}
for t in TEXT_TILES:
    for y in range(8):
        for x in range(8):
            if sheet.getpixel(((t % tw) * 8 + x, (t // tw) * 8 + y)) == 1:
                sheet.putpixel(((t % tw) * 8 + x, (t // tw) * 8 + y), 4)

# stamp screen x56..95, y6..12 — the 7px glyph rows cross the y8 tile boundary,
# so resolve the owning tile per pixel rather than per position

for c in range(7, 12):
    for r in (0, 1):
        i = r * 32 + c
        t = entries[i] & 1023
        if usage[t] > 1:
            fresh = next_free
            next_free += 1
            for y in range(8):
                for x in range(8):
                    v = sheet.getpixel(((t % tw) * 8 + x, (t // tw) * 8 + y))
                    sheet.putpixel(((fresh % tw) * 8 + x, (fresh // tw) * 8 + y), v)
            entries[i] = (entries[i] & 0xF800) | fresh
assert next_free <= 53
for j in range(7):
    for i2 in range(40):
        char, col = i2 // 10, i2 % 10
        if col < 9 and glyph('宝可装置'[char])[j][col]:
            x, y = 56 + i2, 6 + j
            c, r = x // 8, y // 8
            t = entries[r * 32 + c] & 1023
            sheet.putpixel(((t % tw) * 8 + x % 8, (t // tw) * 8 + y % 8), 1)
sheet.save(NAV / 'hns/header.png')
(NAV / 'hns/header.bin').write_bytes(struct.pack(f'<{len(entries)}H', *entries))
print(f'hns/header.png: 宝可装置 (fresh tiles 41..{next_free - 1}, header.bin patched)')
