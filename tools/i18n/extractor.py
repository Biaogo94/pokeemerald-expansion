import os
import re
import json
import argparse
from dataclasses import dataclass, asdict
from typing import List

@dataclass
class ExtractedEntry:
    id: str
    file: str
    label: str
    index: int
    source: str
    category: str

def is_meaningful_string(s: str) -> bool:
    cleaned = s.replace("$", "").strip()
    if not cleaned:
        return False
    # Check if contains letters or numbers
    if not any(c.isalnum() for c in cleaned):
        return False
    return True

def extract_strings_from_inc(file_path: str, content: str) -> List[ExtractedEntry]:
    entries = []
    lines = content.splitlines()

    current_label = None
    accumulated_parts = []
    string_index = 0
    label_pattern = re.compile(r"^([A-Za-z0-9_]+)::")
    single_label_pattern = re.compile(r"^([A-Za-z0-9_]+):")
    string_pattern = re.compile(r'^\s*\.string\s+"(.*)"\s*$')

    category = "map_script" if "maps" in file_path else "text_data"

    for line in lines:
        m_label = label_pattern.match(line) or single_label_pattern.match(line)
        if m_label:
            # If we had accumulated strings for previous label, commit it
            if current_label and accumulated_parts:
                combined = "".join(accumulated_parts)
                if is_meaningful_string(combined):
                    entry_id = f"{file_path}:{current_label}:{string_index}"
                    entries.append(ExtractedEntry(entry_id, file_path, current_label, string_index, combined, category))
                    string_index += 1
                accumulated_parts = []
            current_label = m_label.group(1)
            string_index = 0
            continue

        m_str = string_pattern.match(line)
        if m_str and current_label:
            val = m_str.group(1)
            accumulated_parts.append(val)
            if val.endswith("$"):
                combined = "".join(accumulated_parts)
                if is_meaningful_string(combined):
                    entry_id = f"{file_path}:{current_label}:{string_index}"
                    entries.append(ExtractedEntry(entry_id, file_path, current_label, string_index, combined, category))
                    string_index += 1
                accumulated_parts = []

    # Final trailing check
    if current_label and accumulated_parts:
        combined = "".join(accumulated_parts)
        if is_meaningful_string(combined):
            entry_id = f"{file_path}:{current_label}:{string_index}"
            entries.append(ExtractedEntry(entry_id, file_path, current_label, string_index, combined, category))

    return entries

def extract_strings_from_c(file_path: str, content: str) -> List[ExtractedEntry]:
    entries = []
    # Pattern to find: [type] [name][] = _("...");
    c_pattern = re.compile(r'(?:static\s+)?(?:const\s+)?(?:u8|char)\s+([A-Za-z0-9_]+)\s*\[\]\s*=\s*_\(\s*"([^"]*)"\s*\);')
    for idx, match in enumerate(c_pattern.finditer(content)):
        label = match.group(1)
        val = match.group(2)
        if is_meaningful_string(val):
            entry_id = f"{file_path}:{label}:{idx}"
            entries.append(ExtractedEntry(entry_id, file_path, label, idx, val, "c_source"))
    return entries

def scan_repository(root_dir: str = ".") -> List[ExtractedEntry]:
    all_entries = []

    # 1. Scan data/maps/
    maps_dir = os.path.join(root_dir, "data", "maps")
    if os.path.exists(maps_dir):
        for root, _, files in os.walk(maps_dir):
            for f in files:
                if f.endswith(".inc"):
                    p = os.path.join(root, f).replace("\\", "/")
                    try:
                        with open(p, "r", encoding="utf-8", errors="ignore") as fp:
                            all_entries.extend(extract_strings_from_inc(p, fp.read()))
                    except Exception as e:
                        print(f"Error reading {p}: {e}")

    # 2. Scan data/text/
    text_dir = os.path.join(root_dir, "data", "text")
    if os.path.exists(text_dir):
        for root, _, files in os.walk(text_dir):
            for f in files:
                if f.endswith(".inc"):
                    p = os.path.join(root, f).replace("\\", "/")
                    try:
                        with open(p, "r", encoding="utf-8", errors="ignore") as fp:
                            all_entries.extend(extract_strings_from_inc(p, fp.read()))
                    except Exception as e:
                        print(f"Error reading {p}: {e}")

    # 3. Scan src/data/text/
    src_text_dir = os.path.join(root_dir, "src", "data", "text")
    if os.path.exists(src_text_dir):
        for root, _, files in os.walk(src_text_dir):
            for f in files:
                if f.endswith(".h") or f.endswith(".c"):
                    p = os.path.join(root, f).replace("\\", "/")
                    try:
                        with open(p, "r", encoding="utf-8", errors="ignore") as fp:
                            all_entries.extend(extract_strings_from_c(p, fp.read()))
                    except Exception as e:
                        print(f"Error reading {p}: {e}")

    return all_entries

def main():
    parser = argparse.ArgumentParser(description="Extract localizable strings from pokeemerald repo.")
    parser.add_argument("--output", default="tools/i18n/data/raw_corpus.json", help="Path to output json file.")
    args = parser.parse_args()

    os.makedirs(os.path.dirname(args.output), exist_ok=True)
    entries = scan_repository(".")
    print(f"Extracted {len(entries)} strings from repository.")
    with open(args.output, "w", encoding="utf-8") as f:
        json.dump([asdict(e) for e in entries], f, ensure_ascii=False, indent=2)
    print(f"Saved to {args.output}")

if __name__ == "__main__":
    main()
