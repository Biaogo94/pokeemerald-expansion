"""Pixel-level tests for the compact Chinese move-type badges."""
from collections import Counter
from pathlib import Path
import re

from PIL import Image

ROOT = Path(__file__).resolve().parents[3]
EXPECTED = {
    "none": "无", "normal": "一般", "fight": "格斗", "flying": "飞行",
    "poison": "毒", "ground": "地面", "rock": "岩石", "bug": "虫",
    "ghost": "幽灵", "steel": "钢", "mystery": "???", "fire": "火",
    "water": "水", "grass": "草", "electric": "电", "psychic": "超能",
    "ice": "冰", "dragon": "龙", "dark": "恶", "fairy": "妖精",
    "stellar": "星晶",
}


def glyph(char):
    charmap = (ROOT / "charmap.txt").read_text(encoding="utf-8")
    match = re.search(r"^'" + re.escape(char) + r"' = ([0-9A-F]{4})$", charmap, re.M)
    code = int(match.group(1), 16)
    hi, lo = code >> 8, code & 255
    hi -= hi > 0x1B
    hi -= hi > 0x06
    index = ((hi - 1) << 8) | lo
    x, y = index % 16 * 16, index // 16 * 16
    font = Image.open(ROOT / "graphics/fonts/chinese_small.png").convert("L")
    glyph = font.crop((x, y, x + 10, y + 13))
    mask = glyph.point(lambda value: 255 if value <= 160 else 0)
    bbox = mask.getbbox()
    assert bbox is not None, char
    return glyph.crop(bbox).resize((8, 8), Image.Resampling.LANCZOS)


def test_move_type_badges_have_chinese_labels_and_preserve_sprite_geometry():
    for name, label in EXPECTED.items():
        image = Image.open(ROOT / f"graphics/types/{name}.png")
        assert image.mode == "P", name
        assert image.size == (32, 16), name
        assert max(image.get_flattened_data()) < 16, name
        fill = Counter(image.getpixel((x, y)) for y in range(4, 12) for x in range(2, 30)).most_common(1)[0][0]
        palette = image.getpalette()
        bg = palette[fill * 3:fill * 3 + 3]
        strongest = max(
            range(1, 16),
            key=lambda color: sum((palette[color * 3 + channel] - bg[channel]) ** 2 for channel in range(3)),
        )
        # Match the configured font's ink to the badge's highest-contrast color.
        x0 = (32 - 8 * len(label)) // 2
        ink_pixels = []
        for index, char in enumerate(label):
            if char == "?":
                continue
            font_glyph = glyph(char)
            for y in range(8):
                for x in range(8):
                    if font_glyph.getpixel((x, y)) <= 160:
                        ink_pixels.append(image.getpixel((x0 + index * 8 + x, y + 4)))
        if ink_pixels:
            assert max(ink_pixels.count(color) for color in set(ink_pixels)) >= len(ink_pixels) // 2, name


def test_move_type_badge_renderer_exists_and_lists_all_assets():
    script = ROOT / "tools/i18n/draw_move_type_badges.py"
    assert script.is_file()
    text = script.read_text(encoding="utf-8")
    names = set(re.findall(r'"([a-z]+)": "', text))
    assert set(EXPECTED) <= names
    assert "charmap.txt" in text
    assert "chinese_small.png" in text
