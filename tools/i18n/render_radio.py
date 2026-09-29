"""Render the HnS radio screen faithfully: ui_tiles.png + per-bank palettes
from ui.pal + ui_map.bin tilemap."""

import struct
from pathlib import Path

from PIL import Image

ROOT = Path(__file__).resolve().parents[2]
NAV = ROOT / 'graphics/pokenav/hns/radio'
sheet = Image.open(NAV / 'ui_tiles.png')
entries = struct.unpack(f'<{(NAV / "ui_map.bin").stat().st_size // 2}H',
                        (NAV / 'ui_map.bin').read_bytes())
tw = sheet.width // 8

pal_raw = (NAV / 'ui.pal').read_bytes()
banks = []
for b in range(len(pal_raw) // 32):
    colors = []
    for c in range(16):
        v = struct.unpack('<H', pal_raw[b * 32 + c * 2:b * 32 + c * 2 + 2])[0]
        r, g, bl = (v & 31) * 8, ((v >> 5) & 31) * 8, ((v >> 10) & 31) * 8
        colors.append((r, g, bl))
    banks.append(colors)

W, H = 256, len(entries) // 32 * 8
rgb = Image.new('RGB', (W, H))
rp = rgb.load()
for i, e in enumerate(entries):
    t = e & 1023
    bank = banks[min(e >> 12, len(banks) - 1)]
    sx, sy = (i % 32) * 8, (i // 32) * 8
    for y in range(8):
        for x in range(8):
            px = sheet.getpixel(((t % tw) * 8 + x, (t // tw) * 8 + y))
            xx, yy = x, y
            if e & 1024:
                xx = 7 - x
            if e & 2048:
                yy = 7 - y
            rp[sx + x, sy + y] = bank[px & 15]
rgb = rgb.crop((0, 0, 240, min(H, 160)))
rgb.resize((rgb.width * 3, rgb.height * 3), Image.NEAREST).save(ROOT / 'tools/i18n/data/radio_screen.png')
print('rendered', rgb.size, 'banks:', len(banks))
