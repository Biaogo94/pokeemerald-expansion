"""Sweep active text for machine-translation tells: half-width punctuation
inside Chinese sentences, doubled particles, and stray ASCII fragments."""

import re
from pathlib import Path

files = list(Path('data/maps').rglob('*_hns/scripts.inc')) \
    + list(Path('data/text').glob('*.inc')) \
    + list(Path('data/scripts').glob('*.inc'))

CH = r'[一-鿿]'
tells = {
    '半角句号': re.compile(CH + r'\.(?=\s|\\|"|$)'),
    '半角逗号': re.compile(CH + r',' + CH),
    '半角叹号': re.compile(CH + r'!(?=\s|\\|"|$)'),
    '半角问号': re.compile(CH + r'\?(?=\s|\\|"|$)'),
    '双句号': re.compile(r'。。'),
    '的了了': re.compile(r'的了了'),
    '的字叠用': re.compile(CH + r'的的' + CH),
    '空格句读': re.compile(CH + r' {2,}'),
}

hits = 0
for p in files:
    text = p.read_text(encoding='utf-8', errors='replace')
    if 'Frlg' in p.name:
        continue
    for i, line in enumerate(text.splitlines(), 1):
        if '.string' not in line:
            continue
        for name, pat in tells.items():
            m = pat.search(line)
            if m:
                hits += 1
                print(f'{p.name}:{i} [{name}]: {line.strip()[:70]}')
print(f'-- {hits} tell(s) found')
