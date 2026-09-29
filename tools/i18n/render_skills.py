"""Render the HnS summary skills page with real palettes for visual check."""

import struct
from pathlib import Path

from PIL import Image

ROOT = Path(__file__).resolve().parents[2]
GFX = ROOT / 'graphics/summary_screen'
sheet = Image.open(GFX / 'hns/tiles.png')
entries = struct.unpack(f'<{(GFX / "hns/page_skills.bin").stat().st_size // 2}H',
                        (GFX / 'hns/page_skills.bin').read_bytes())
tw = sheet.width // 8

pal = (GFX / 'hns/tiles.gbapal')
banks = []
if pal.exists():
    raw = pal.read_bytes()
    for b in range(len(raw) // 32):
        colors = []
        for c in range(16):
            v = struct.unpack('<H', raw[b * 32 + c * 2:b * 32 + c * 2 + 2])[0]
            colors.append(((v & 31) * 8, ((v >> 5) & 31) * 8, ((v >> 10) & 31) * 8))
        banks.append(colors)
else:
    gray = [(i * 16, i * 16, i * 16) for i in range(16)]
    banks = [gray] * 16

rgb = Image.new('RGB', (240, 160))
rp = rgb.load()
for i, e in enumerate(entries[:600]):
    t = e & 1023
    bank = banks[min(e >> 12, len(banks) - 1)]
    sx, sy = (i % 30) * 8, (i // 30) * 8
    for y in range(8):
        for x in range(8):
            v = sheet.getpixel(((t % tw) * 8 + x, (t // tw) * 8 + y))
            rp[sx + x, sy + y] = bank[v & 15]
rgb.resize((720, 480), Image.NEAREST).save(ROOT / 'tools/i18n/data/skills_screen.png')
print('rendered; banks:', len(banks))
