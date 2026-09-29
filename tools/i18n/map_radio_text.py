"""Decode the HnS radio UI: map ui_map.bin entries to ui_tiles.png, find
letter-bearing tiles, and compose their screen layout for identification."""

import struct
from collections import Counter
from pathlib import Path

from PIL import Image

ROOT = Path(__file__).resolve().parents[2]
NAV = ROOT / 'graphics/pokenav/hns/radio'
sheet = Image.open(NAV / 'ui_tiles.png')
entries = struct.unpack(f'<{(NAV / "ui_map.bin").stat().st_size // 2}H',
                        (NAV / 'ui_map.bin').read_bytes())
tw = sheet.width // 8

# letter tiles: >18 non-bg pixels within the tile
text_tiles = {}
for t in range(64):
    px = [sheet.getpixel(((t % tw) * 8 + x, (t // tw) * 8 + y)) for y in range(8) for x in range(8)]
    bg = max(set(px), key=px.count)
    if 64 - px.count(bg) > 18:
        text_tiles[t] = bg

print('letter tiles:', sorted(text_tiles))
print('screen placements (tile, screen_x, screen_y, pal):')
for i, e in enumerate(entries):
    t = e & 1023
    if t in text_tiles:
        print(f'  tile {t:2} at screen ({(i % 32) * 8:3},{(i // 32) * 8:3}) pal={e >> 12} flips={"" if not e & 3072 else hex(e & 3072)}')

# group into horizontal runs and ASCII-render each run
places = {}
for i, e in enumerate(entries):
    t = e & 1023
    if t in text_tiles:
        places.setdefault(i // 32, []).append((i % 32, t))
for row in sorted(places):
    cols = sorted(places[row])
    print(f'--- screen row y={row * 8}-{row * 8 + 7} ---')
    for y in range(8):
        line = ''
        for cx, t in cols:
            bg = text_tiles[t]
            for x in range(8):
                p = sheet.getpixel(((t % tw) * 8 + x, (t // tw) * 8 + y))
                line += '#' if p != bg else ' '
            line += '|'
        print(f'  {line}')
