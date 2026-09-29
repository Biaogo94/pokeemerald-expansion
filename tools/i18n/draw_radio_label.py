"""Replace the RADIO label on the HnS radio screen with 收音机.

The label spans two tile rows on screen (y24..39, x48..87): letter tops in
ui_tiles.png tiles 27-31 (sheet y8..15) and bottoms in tiles 38-42
(sheet y16..23). All ten tiles are uniquely referenced (bank 2, no flips),
so they can be edited in place. Letter pixels are palette 3/6 on panel 4;
the outer border columns (screen x94..95-equivalent sheet columns of tiles
27/31 and 38/42 edges) must survive.
"""

import re
from pathlib import Path

from PIL import Image

ROOT = Path(__file__).resolve().parents[2]
NAV = ROOT / 'graphics/pokenav/hns/radio'
CHARMAP = (ROOT / 'charmap.txt').read_text(encoding='utf-8')
FONT = Image.open(ROOT / 'graphics/fonts/chinese_small.png').convert('L')
LABEL = '收音机'
INK, PANEL = 6, 4

# screen-space label area
SX0, SX1, SY0, SY1 = 48, 87, 24, 39
# sheet columns to preserve (panel borders): tile27 x94..95, tile31 x126..127,
# tile42 x86..87
BORDER_SHEET = set(range(94, 96)) | set(range(126, 128)) | set(range(86, 88))

sheet = Image.open(NAV / 'ui_tiles.png')
px = sheet.load()

# map each screen pixel of the label band to its sheet coordinates
def sheet_pos(sx, sy):
    e = entries[(sy // 8) * 32 + sx // 8]
    t = e & 1023
    assert not (e & 3072), 'unexpected flip'
    return (t % 16) * 8 + sx % 8, (t // 16) * 8 + sy % 8


import struct
entries = struct.unpack(f'<{(NAV / "ui_map.bin").stat().st_size // 2}H',
                        (NAV / "ui_map.bin").read_bytes())

# erase letters (3/6) inside the band, keeping border columns
for sy in range(SY0, SY1 + 1):
    for sx in range(SX0, SX1 + 1):
        hx, hy = sheet_pos(sx, sx * 0 + sy)
        if hx in BORDER_SHEET:
            continue
        if px[hx, hy] in (INK, 3):
            px[hx, hy] = PANEL


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
    small = FONT.crop((x, y, x + 10, y + 13)).resize((9, 7), Image.LANCZOS)
    g = small.load()
    return [[1 if g[i, j] < 128 else 0 for i in range(9)] for j in range(7)]


# stamp centred: 3 chars x 9px advance in the 40px band; glyph rows y28..34
advance = 9
x_start = SX0 + (SX1 - SX0 + 1 - advance * len(LABEL)) // 2
y_start = SY0 + (SY1 - SY0 + 1 - 7) // 2
for n, char in enumerate(LABEL):
    gl = glyph(char)
    for j in range(7):
        for i in range(9):
            if gl[j][i]:
                hx, hy = sheet_pos(x_start + advance * n + i, y_start + j)
                px[hx, hy] = INK
sheet.save(NAV / 'ui_tiles.png')
print(f'radio label: {LABEL} at screen x{x_start}..{x_start + advance * len(LABEL) - 1}, y{y_start}..{y_start + 6}')
