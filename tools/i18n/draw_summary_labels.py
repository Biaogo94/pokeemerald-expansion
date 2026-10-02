"""Redraw English labels baked into the summary-screen tile sheet as hanzi.

Each banner keeps its original palette: letter pixels are erased to the
tile's own background colour and the Chinese glyphs reuse the original
letter colour index. Both tiles.png copies (root + hns) stay identical.

Chinese glyphs are LANCZOS-downsampled 10x13 chinese_small font ink to 9x7,
which is the largest size that fits the fixed 8px-tall banners.
"""

import re
from collections import Counter
from pathlib import Path

from PIL import Image

ROOT = Path(__file__).resolve().parents[2]
SHEETS = [ROOT / 'graphics/summary_screen/tiles.png',
          ROOT / 'graphics/summary_screen/hns/tiles.png']
CHARMAP = (ROOT / 'charmap.txt').read_text(encoding='utf-8')
FONT = Image.open(ROOT / 'graphics/fonts/chinese_small.png').convert('L')

# (tile span, label, per-char sub-spans) — sub-spans handle banners whose
# tiles display split across two screen rows (page-switch ribbon wraps).
LABELS = [
    ((128, 133), '概况', [(128, 130), (131, 133)]),          # PROFILE
    ((137, 139), '道具', [(137, 138), (138, 139)]),          # ITEM
    ((144, 148), '特性', [(144, 145), (147, 148)]),          # ABILITIES
    ((153, 159), '奖章', [(153, 154), (156, 157)]),          # RIBBONS (159 erased)
    ((169, 175), '个体努力', [(169, 170), (171, 172), (173, 173), (174, 174)]),  # IVS / EVS
    ((185, 187), '经验', [(185, 186), (186, 187)]),          # EXP
    ((202, 206), '效果', [(202, 204), (204, 206)]),          # EFFECT
    ((208, 216), '说明', [(208, 212), (212, 216)]),          # DESCRIPTION
    ((176, 179), '取消', [(176, 177), (178, 179)]),          # CANCEL (egg)
    ((192, 196), '招式', [(193, 193), (194, 194)]),          # MOVES page title
]


def glyph_9x7(char):
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
    mask = ink.point(lambda value: 255 if value <= 160 else 0)
    bbox = mask.getbbox()
    if bbox is None:
        raise ValueError(f'empty glyph: {char}')
    small = ink.crop(bbox).resize((9, 7), Image.Resampling.LANCZOS)
    px = small.load()
    return [[1 if px[i, j] <= 160 else 0 for i in range(9)] for j in range(7)]


def tile_span(im, t0, t1):
    """Erase English letters inside a tile range; return (bg, ink) indices."""
    c0, r0 = t0 % 16, t0 // 16
    c1, r1 = t1 % 16, t1 // 16
    counts = Counter(im.getpixel((c * 8 + x, r * 8 + y))
                     for r in range(r0, r1 + 1) for c in range(c0, c1 + 1)
                     for y in range(8) for x in range(8))
    bg = counts.most_common(1)[0][0]
    ink = next((c for c, _ in counts.most_common() if c != bg), None)
    px = im.load()
    for r in range(r0, r1 + 1):
        for c in range(c0, c1 + 1):
            for y in range(8):
                for x in range(8):
                    if px[c * 8 + x, r * 8 + y] != bg:
                        px[c * 8 + x, r * 8 + y] = bg
    return bg, ink


def stamp(im, span, char, ink):
    t0, t1 = span
    width = (t1 - t0 + 1) * 8
    gl = glyph_9x7(char)
    x_start = (t0 % 16) * 8 + (width - 9) // 2
    y_start = (t0 // 16) * 8  # banner rows 0..7, glyph 7 rows -> y+0..6
    px = im.load()
    for j in range(7):
        for i in range(9):
            if gl[j][i]:
                px[x_start + i, y_start + j] = ink


def stamp_centered_label(im, span, label, ink):
    t0, t1 = span
    width = (t1 - t0 + 1) * 8
    x_start = (t0 % 16) * 8 + (width - len(label) * 9) // 2
    y_start = (t0 // 16) * 8
    px = im.load()
    for char_index, char in enumerate(label):
        glyph = glyph_9x7(char)
        for y in range(7):
            for x in range(9):
                if glyph[y][x]:
                    px[x_start + char_index * 9 + x, y_start + y] = ink


for sheet in SHEETS:
    im = Image.open(sheet)
    assert im.size == (128, 120)
    for (t0, t1), label, subspans in LABELS:
        bg, ink = tile_span(im, t0, t1)
        assert ink is not None, (sheet, t0)
        for char, (s0, s1) in zip(label, subspans):
            stamp(im, (s0, s1), char, ink)
    bg, ink = tile_span(im, 224, 232)
    assert ink is not None, (sheet, 224)
    stamp_centered_label(im, (224, 232), '训练家备忘录', ink)
    im.save(sheet)
    print(f'{sheet}: {len(LABELS)} banners redrawn')
