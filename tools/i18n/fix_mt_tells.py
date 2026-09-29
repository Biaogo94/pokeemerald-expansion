"""Fix machine-translation tells: sentence-final ASCII periods after Chinese
characters become 。, and doubled 的的 collapses."""

import re
from pathlib import Path

CH = r'[一-鿿]'
RULES = [
    (re.compile('(' + CH + r')\.(?=\\[nlp]|"|\s*$)'), r'\1。'),
    (re.compile('(' + CH + r')的的(' + CH + r')'), r'\1的\2'),
]

files = list(Path('data/maps').rglob('*_hns/scripts.inc')) \
    + list(Path('data/text').glob('*.inc')) \
    + list(Path('data/scripts').glob('*.inc'))

fixed = 0
for p in files:
    if 'Frlg' in p.name or 'frlg' in p.name:
        continue
    text = p.read_text(encoding='utf-8', errors='replace')
    new = text
    n = 0
    for pat, rep in RULES:
        new, k = pat.subn(rep, new)
        n += k
    if n:
        p.write_text(new, encoding='utf-8')
        fixed += n
        print(f'{p}: {n} fixed')
print(f'-- total {fixed}')
