"""Reletter 32x16 move-type badges with compact Chinese glyphs."""
from __future__ import annotations

import re
from collections import Counter
from pathlib import Path

from PIL import Image

ROOT = Path(__file__).resolve().parents[2]
ASSET_DIR = ROOT / "graphics/types"
LABELS = {
    "none": "无", "normal": "一般", "fight": "格斗", "flying": "飞行",
    "poison": "毒", "ground": "地面", "rock": "岩石", "bug": "虫",
    "ghost": "幽灵", "steel": "钢", "mystery": "???", "fire": "火",
    "water": "水", "grass": "草", "electric": "电", "psychic": "超能",
    "ice": "冰", "dragon": "龙", "dark": "恶", "fairy": "妖精",
    "stellar": "星晶",
}


def glyph_for(char, charmap, sheet):
    match = re.search(r"^'" + re.escape(char) + r"' = ([0-9A-F]{4})$", charmap, re.M)
    if match is None:
        raise ValueError(f"missing charmap glyph: {char}")
    code = int(match.group(1), 16)
    hi, lo = code >> 8, code & 255
    hi -= hi > 0x1B
    hi -= hi > 0x06
    index = ((hi - 1) << 8) | lo
    x, y = index % 16 * 16, index // 16 * 16
    # Remove the font cell's blank top/bottom rows before fitting its ink into
    # the badge's 8px-high text cell.
    glyph = sheet.crop((x, y, x + 10, y + 13))
    mask = glyph.point(lambda value: 255 if value <= 160 else 0)
    bbox = mask.getbbox()
    if bbox is None:
        raise ValueError(f"empty glyph: {char}")
    return glyph.crop(bbox).resize((8, 8), Image.Resampling.LANCZOS)


def draw_badge(path, label, charmap, font):
    image = Image.open(path)
    if image.mode != "P" or image.size != (32, 16):
        raise ValueError(f"unexpected badge format: {path}")
    if label == "???":
        return
    pixels = image.load()
    interior = [pixels[x, y] for y in range(4, 12) for x in range(2, 30)]
    fill = Counter(interior).most_common(1)[0][0]
    palette = image.getpalette()
    bg_rgb = palette[fill * 3:fill * 3 + 3]
    ink = max(
        range(1, 16),
        key=lambda color: sum((palette[color * 3 + channel] - bg_rgb[channel]) ** 2 for channel in range(3)),
    )
    for y in range(4, 12):
        for x in range(2, 30):
            pixels[x, y] = fill
    x0 = (32 - 8 * len(label)) // 2
    for index, char in enumerate(label):
        glyph = glyph_for(char, charmap, font)
        for y in range(8):
            for x in range(8):
                if glyph.getpixel((x, y)) <= 160:
                    pixels[x0 + index * 8 + x, y + 4] = ink
    image.save(path, optimize=False)


def main():
    charmap = (ROOT / "charmap.txt").read_text(encoding="utf-8")
    font = Image.open(ROOT / "graphics/fonts/chinese_small.png").convert("L")
    for stem, label in LABELS.items():
        draw_badge(ASSET_DIR / f"{stem}.png", label, charmap, font)
        print(f"{stem}: {label}")


if __name__ == "__main__":
    main()
