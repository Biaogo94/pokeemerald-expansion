"""Find English words split across adjacent C string literals (\n or \l)."""

import re
from pathlib import Path

PAT = re.compile(r'"((?:\\.|[^"\\])*)\\[nl]"\s*\n\s*"([A-Za-z]{1,3})(?![A-Za-z])')

for p in Path('src').rglob('*.c'):
    text = p.read_text(encoding='utf-8', errors='replace')
    for m in PAT.finditer(text):
        first, second = m.group(1), m.group(2)
        if first and re.search(r'[A-Za-z]$', first):
            line = text[:m.start()].count('\n') + 1
            print(f'{p}:{line}: ...{first[-12:]!r} | {second!r}')
