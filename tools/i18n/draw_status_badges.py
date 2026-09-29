"""Redraw the healthbox/party status badges as single hanzi glyphs.

The status slot is a fixed 3-tile (24x8) healthbox strip / 32x8 party icon
row, so a full word cannot fit; one hand-hinted 9x7 character is stamped in
the existing knockout colour (palette index 2) over the existing badge fill.
Only existing palette indices are used; palettes and dimensions are untouched.

Battle sheet geometry (verified pixel dump): fill interior x=1..18 on text
rows y=1..6 (x=2..17 on y=0/7); English knockout lives in y=1..6.
Party sheet: fill x=7..26; same vertical layout.
"""

from collections import Counter
from pathlib import Path

from PIL import Image

ROOT = Path(__file__).resolve().parents[2]

# Structurally hinted 9x7 glyphs: keep the radical skeleton readable at
# tiny sizes instead of faithful stroke counts.
BADGES = {
    '毒': ('·#####···', '···#·····', '#########', '·#··#··#·', '·#·###·#·', '·#·#···#·', '·#######·'),
    '麻': ('·#·······', '#########', '#········', '#··#···#·', '·###·###·', '··#···#··', '·#·#·#·#·'),
    '眠': ('·##···###', '·#·#··#·#', '·##···###', '·#·#··#·#', '·##···###', '·#·#··#·#', '·##···###'),
    '冻': ('#·····###', '#·····#·#', '······###', '#···#####', '·····#·#·', '#·····#··', '·······##'),
    '灼': ('·#·······', '·#···####', '·##···#··', '·#·#·#·##', '#··#···#·', '#·······#', '#·····##·'),
    '霜': ('#########', '·#·#·#·#·', '#########', '·#·······', '·###·####', '··#··#·#·', '·#·#·#·#·'),
    '菌': ('·#····#··', '#########', '····#····', '·#######·', '·#···#·#·', '·#···#·#·', '·#######·'),
    '濒': ('#·····##·', '#·····##·', '#·····##·', '#········', '#·····###', '#·····#··', '#·····###'),
}
BATTLE_ORDER = '毒麻眠冻灼霜'    # PSN PRZ SLP FRZ BRN FRB (battle_interface.c)
PARTY_ORDER = '毒麻眠冻灼菌濒霜'  # PSN PRZ SLP FRZ BRN PKRS FNT FRB (party_menu.h)

BATTLE_SHEETS = [f'graphics/battle_interface/{style}/status{suffix}.png'
                 for style in ('hns', 'gen4') for suffix in ('', '2', '3', '4')]
PARTY_SHEET = 'graphics/interface/status_icons.png'
INK = 2  # existing white knockout index in every sheet


def stamp(path, order, interior, badge_x0):
    x_lo, x_hi = interior
    im = Image.open(ROOT / path)
    assert im.mode == 'P', path
    assert im.height == len(order) * 8, path
    px = im.load()
    for row, char in enumerate(order):
        counts = Counter(px[x, y] for y in range(row * 8, row * 8 + 8)
                         for x in range(x_lo, x_hi + 1))
        fill = max((c for c in counts if c != INK), key=counts.get)
        # erase the English knockout text (text rows only), keep edges/borders
        for y in range(row * 8 + 1, row * 8 + 7):
            for x in range(x_lo, x_hi + 1):
                if px[x, y] == INK:
                    px[x, y] = fill
        for gy, line in enumerate(BADGES[char]):
            for gx, c in enumerate(line):
                if c != '·':
                    assert px[badge_x0 + gx, row * 8 + gy] == fill, (path, row, gy, gx)
                    px[badge_x0 + gx, row * 8 + gy] = INK
    im.save(ROOT / path)
    print(f'{path}: stamped {"".join(order)}')


for sheet in BATTLE_SHEETS:
    stamp(sheet, BATTLE_ORDER, (1, 18), 5)
stamp(PARTY_SHEET, PARTY_ORDER, (7, 26), 11)
