"""Audit linked HnS text using the artifact's symbols and actual ROM bytes.

This is a candidate report, not a proof of runtime reachability or full coverage.
Raw ASCII scanning is deliberately not used for game text.
"""
import argparse
import hashlib
import json
import re
from pathlib import Path

BASE = 0x08000000
PUNCT = (0x30, 0x37, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F)
EXT_ARGS = {1:1,2:1,3:1,4:3,5:1,6:1,7:0,8:1,9:0,10:0,11:2,12:1,13:1,14:1,15:0,16:2,17:1,18:1,19:1,20:1,21:0,22:0,23:0,24:0,25:1,26:1,27:1,28:3}

def read_charmap(path):
    chars, macros, inverse = {}, {}, {}
    for line in Path(path).read_text('utf8').splitlines():
        m = re.match(r"^'(.+)'\s*=\s*([0-9A-F ]+)", line)
        if m:
            char, raw = m.groups()
            data = bytes.fromhex(raw)
            chars[char] = data
            # Latin mappings precede Japanese aliases. CJK overrides only
            # genuine double-byte/punctuation slots, not Japanese aliases.
            if data not in inverse or ord(char[0]) >= 0x4E00 or char in '・。～、，！？：—':
                inverse[data] = char
        else:
            m = re.match(r'^([A-Z_0-9]+)\s*=\s*([0-9A-F ]+)', line)
            if m:
                macros[m[1]] = bytes.fromhex(m[2])
    return chars, macros, inverse

def encode(text, chars, macros):
    result = bytearray()
    for token in re.findall(r'\{[^}]*\}|\\.|.', text):
        if token in (r'\n', r'\l', r'\p'):
            result.append({r'\n':254,r'\l':250,r'\p':251}[token])
        elif token.startswith('{'):
            for word in token[1:-1].split():
                if word in macros:
                    result.extend(macros[word])
                else:
                    number = int(word, 0)
                    result.extend(number.to_bytes(2 if number > 255 else 1, 'little'))
        else:
            result.extend(chars[token])
    return bytes(result)

def read_symbols(path):
    result = {}
    for line in Path(path).read_text().splitlines():
        fields = line.split()
        if len(fields) == 4 and fields[2] in 'rRdD':
            address, size = int(fields[0],16), int(fields[1],16)
            if BASE <= address < BASE + 0x2000000:
                result[fields[3]] = (address, size)
    return result

def decode(data, inverse):
    out, i, terminated = [], 0, False
    while i < len(data):
        code = data[i]
        if code == 255:
            terminated = True
            break
        if code in (250,251,254):
            out.append({250:r'\l',251:r'\p',254:r'\n'}[code]); i += 1; continue
        if code == 252:
            if i+1 >= len(data): break
            count = EXT_ARGS.get(data[i+1])
            if count is None or i+2+count > len(data): break
            out.append('{CTRL ' + data[i+1:i+2+count].hex() + '}'); i += 2+count; continue
        if code in (247,248,249,253):
            if i+1 >= len(data): break
            out.append('{TOKEN ' + data[i:i+2].hex() + '}'); i += 2; continue
        length = 2 if 1 <= code <= 30 and code not in (6,27) and i+1 < len(data) and data[i+1] <= 246 else 1
        value = data[i:i+length]
        out.append(inverse.get(value, '<' + value.hex() + '>'))
        i += length
    return ''.join(out), terminated

def audit(root, artifact):
    chars, macros, inverse = read_charmap(root/'charmap.txt')
    symbols = read_symbols(artifact/'pokehns.symbols.txt')
    rom = (artifact/'pokehns.gba').read_bytes()
    checksums = {}
    for line in (artifact/'SHA256SUMS').read_text().splitlines():
        expected, filename = line.split()
        actual = hashlib.sha256((artifact/filename).read_bytes()).hexdigest()
        checksums[filename] = {'expected':expected,'actual':actual,'matches':actual == expected}
    texts, candidates = [], []
    for name,(address,size) in symbols.items():
        if not re.search(r'Text|String|Description',name,re.I) or not 1 <= size <= 8192: continue
        text, ended = decode(rom[address-BASE:address-BASE+size],inverse)
        if not ended: continue
        record = {'symbol':name,'address':hex(address),'size':size,'text':text}
        texts.append(record)
        plain = re.sub(r'\{[^}]*\}|\\[nlp]', ' ', text)
        if re.search(r'[A-Za-z]{3}',plain): candidates.append(record)
    glyphs = []
    for font in ['Normal','Small']:
        address,size = symbols['gFont'+font+'LatinGlyphs']
        for code in PUNCT:
            data=rom[address-BASE+code*64:address-BASE+(code+1)*64]
            # Each 2bpp slot is four 8x8 tiles, 64 bytes in total.
            glyphs.append({'font':font,'code':hex(code),'address':hex(address+code*64),'sha256':hashlib.sha256(data).hexdigest(),'nonzero_bytes':sum(x!=0 for x in data)})
    address,size=symbols['gText_YesNo']
    yesno=rom[address-BASE:address-BASE+size]
    expected=encode('是'+r'\n'+'否$',chars,macros)
    return {'revision':(artifact/'build-revision.txt').read_text().strip(),'rom_size':len(rom),'header':rom[160:172].decode('ascii').rstrip('\0'),'checksums':checksums,'yes_no':{'symbol':'gText_YesNo','address':hex(address),'bytes':yesno.hex(),'expected':expected.hex(),'matches':yesno==expected},'punctuation_glyphs':glyphs,'decoded_symbol_count':len(texts),'english_candidate_count':len(candidates),'english_candidates':candidates,'decoded_texts':texts,'limitations':['Linked symbols do not prove a screen is reachable.','Unnamed or embedded struct strings require separate source/byte correlation.','Font bytes and widths do not replace emulator screenshots.','Graphics containing baked-in English are not covered.']}

def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('artifact',type=Path)
    parser.add_argument('--root',type=Path,default=Path('.'))
    parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args()
    report=audit(args.root,args.artifact)
    args.output.write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps({key:report[key] for key in ['revision','rom_size','yes_no','decoded_symbol_count','english_candidate_count']},ensure_ascii=False))

if __name__=='__main__': main()
