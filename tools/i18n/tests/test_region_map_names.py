"""Regression audit for localized region-map names and generated/runtime tables."""

import hashlib
import json
import re
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[3]
MAP_JSON = REPO_ROOT / "src/data/region_map/region_map_sections.json"
REGION_MAP_C = REPO_ROOT / "src/region_map.c"

# These fingerprints cover enum order without duplicating a 300-entry fixture.
EXPECTED_ID_ORDER_SHA256 = {
    "map_sections": "ac07785bc9fd59eb5cf799bf4eb562d6144b354f526e01b6c50cb641ff21b94d",
    "hns_map_sections": "815cee211fc2fee1fe789a438363519f566d6db8024d81c2bc0e8d2f582f3e4a",
}


def _id_order_digest(entries):
    ids = "\n".join(entry["id"] for entry in entries).encode("ascii")
    return hashlib.sha256(ids).hexdigest()


def _ascii_names(entries):
    return [(entry["id"], entry.get("name", "")) for entry in entries if re.search(r"[A-Za-z]", entry.get("name", ""))]


def _johto_runtime_names():
    source = REGION_MAP_C.read_text(encoding="utf-8")
    table = source.split("static const struct RegionMapLocation sRegionMapEntries_Johto[]", 1)[1]
    table = table.split("};", 1)[0]
    return dict(re.findall(r"\[(MAPSEC_[A-Z0-9_]+)\][^\n]*COMPOUND_STRING\(\"([^\"]*)\"\)", table))


def test_region_map_names_are_localized_and_id_order_is_stable():
    data = json.loads(MAP_JSON.read_text(encoding="utf-8"))

    for section in ("map_sections", "hns_map_sections"):
        entries = data[section]
        assert _ascii_names(entries) == [], f"English map names remain in {section}"
        assert len({entry["id"] for entry in entries}) == len(entries)
        assert _id_order_digest(entries) == EXPECTED_ID_ORDER_SHA256[section]


def test_johto_runtime_names_match_json_source():
    data = json.loads(MAP_JSON.read_text(encoding="utf-8"))
    source_names = {entry["id"]: entry.get("name", "") for entry in data["hns_map_sections"]}
    runtime_names = _johto_runtime_names()

    assert all(not re.search(r"[A-Za-z]", name) for name in runtime_names.values())
    for map_id, name in runtime_names.items():
        assert source_names[map_id] == name, f"runtime name differs from JSON for {map_id}"
