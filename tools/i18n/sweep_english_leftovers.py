"""Sweep every active HnS text source for untranslated English prose.

Scans C string literals (_()/COMPOUND_STRING()) and assembler .string blocks,
strips control codes and placeholders, and reports any line still containing
Latin-letter words outside the known-legitimate allowlist.
"""

import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
ALLOWED_WORDS = {'DNA', 'UFO', 'X', 'Y', 'KO', 'Lv'}
PLACEHOLDER = re.compile(r'\{[^}]*\}|\\[a-zA-Z]|\{DYNAMIC \d\}')
WORD = re.compile(r'[A-Za-z]{2,}|[A-Za-z]')


def scan_file(path, extractor, pattern):
    results = []
    try:
        text = path.read_text(encoding='utf-8')
    except UnicodeDecodeError:
        return results
    for m in extractor.finditer(text):
        content = m.group(1)
        clean = PLACEHOLDER.sub('', content)
        words = [w for w in WORD.findall(clean) if w not in ALLOWED_WORDS and not w.isdigit()]
        cjk = re.search(r'[一-鿿]', clean)
        if words and not cjk:
            line = text[:m.start()].count('\n') + 1
            snippet = ' '.join(content.split())[:100]
            results.append((path, line, snippet, words[:6]))
    return results


C_PATTERN = re.compile(r'(?:_|COMPOUND_STRING)\(\s*"((?:\\.|[^"\\])*)"', re.S)
INC_PATTERN = re.compile(r'\.string\s+"((?:\\.|[^"\\])*)"', re.S)

findings = []
for path in (ROOT / 'src').rglob('*.c'):
    findings += scan_file(path, C_PATTERN, 'c')
for path in (ROOT / 'data').rglob('*.inc'):
    findings += scan_file(path, INC_PATTERN, 'inc')

print(f'{len(findings)} untranslated literals in {len({f[0] for f in findings})} files')
by_file = {}
for p, line, snippet, words in findings:
    by_file.setdefault(p, []).append((line, snippet, words))
for p in sorted(by_file):
    print(f'\n== {p.relative_to(ROOT)} ({len(by_file[p])}) ==')
    for line, snippet, words in by_file[p][:8]:
        print(f'  L{line}: {snippet}   <<{",".join(words)}>>')
    if len(by_file[p]) > 8:
        print(f'  ... +{len(by_file[p]) - 8} more')
