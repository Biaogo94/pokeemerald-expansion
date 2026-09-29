import os
import sys
import json
import time
import urllib.request
import re
from typing import List, Dict, Any

# Ensure tools/i18n can be imported
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ai_translator import validate_translation, TranslationFormatError
from aligner import validate_control_codes_preserved

API_URL = "https://aiapi.aukeyit.com/v1/chat/completions"
API_KEY = os.environ.get("SUB2API_API_KEY") or os.environ.get("LUCEN_API_KEY")
MODEL = "gemini-3.8-flash"

SYSTEM_PROMPT = """你是一个顶级的宝可梦游戏本地化专家，兼具资深宝可梦玩家对剧情语境的敏锐把控与官方翻译风格的严谨性。
你的任务是将 GBA 宝可梦《心金·魂银》（Heart & Soul v2.0.6）的全部英文对话翻译为地道、生动、符合游戏语境的官方简体中文。

【双向参考与去机翻原则】：
1. 必须综合参考《宝可梦 心金/魂银》民间优秀汉化与官方官方正统译本（如第七世代之后的官方名词库），但不要机械死板照抄。
2. 彻底拒绝任何生硬机翻、直译腔与无感情翻译：
   - 英文的 "What's up?" / "Hey there!" 根据角色身份自然译为 "你好呀！" / "怎么啦？" / "哟！"；
   - 训练家挑战挑衅台词要生动热血，不可直译为书面论文腔；
   - 宝可梦叫声需音译生动（如“皮卡！”“呜——！”）；
   - 人物身份口吻必须鲜明（大木博士的稳重仁厚、空木博士的匆忙热心、劲敌的狂傲不逊、捕虫少年的稚气热血）。
3. 专有名词绝对标准：宝可梦、精灵球、宝可梦齿轮、大木博士、空木博士、常青市、满金市等官方统一名词。

【系统与语法守卫最高铁律（违者直接拒收崩溃）】：
1. 绝对原样保留所有大括号变量占位符，如 {PLAYER}, {RIVAL}, {STR_VAR_1}, {STR_VAR_2}, {STR_VAR_3}, {KUN}, {COLOR ...}，严禁增删改！
2. 绝对严格匹配原句控制字符：\\p（等待按键翻页换段）、\\n（第一行换行）、\\l（滚动换行）、$（字符串结束符）。在 JSON 中务必转义为 \\\\n, \\\\l, \\\\p。
3. 文本必须以与原句完全相同的结束符结尾（例如原句以 $ 结尾，译文必须以 $ 结尾）。
4. 必须输出合法的 JSON 数组，每个对象包含 "id" 和 "translation"。
"""

USER_PROMPT_TEMPLATE = """请将以下 JSON 数组中的英文句子翻译为地道、自然、充满宝可梦风格的官方简体中文：

待翻译列表：
{input_json}

请直接输出合法 JSON 数组：
"""

def clean_and_parse_json(text: str) -> Any:
    text = text.strip()
    if text.startswith("```json"):
        text = text[7:]
    if text.startswith("```"):
        text = text[3:]
    if text.endswith("```"):
        text = text[:-3]
    text = text.strip()

    try:
        return json.loads(text)
    except Exception:
        fixed = re.sub(r'\\(?![/"\\bfnrtu])', r'\\\\', text)
        return json.loads(fixed)

def call_gemini_api(items: List[Dict[str, str]], retries: int = 3) -> List[Dict[str, str]]:
    input_data = [{"id": item["id"], "source": item["source"]} for item in items]
    content = USER_PROMPT_TEMPLATE.format(input_json=json.dumps(input_data, ensure_ascii=False))

    payload = {
        "model": MODEL,
        "messages": [
            {"role": "system", "content": SYSTEM_PROMPT},
            {"role": "user", "content": content}
        ],
        "reasoning_effort": "high",
        "temperature": 0.25
    }

    headers = {
        "Content-Type": "application/json",
        "Authorization": f"Bearer {API_KEY}"
    }

    req = urllib.request.Request(API_URL, headers=headers, data=json.dumps(payload).encode("utf-8"))

    for attempt in range(retries):
        try:
            with urllib.request.urlopen(req, timeout=120) as resp:
                res_data = json.loads(resp.read().decode("utf-8"))
                reply = res_data["choices"][0]["message"]["content"]
                parsed = clean_and_parse_json(reply)
                if isinstance(parsed, list):
                    return parsed
        except Exception as e:
            print(f"[Attempt {attempt+1}/{retries}] API error: {e}", flush=True)
            time.sleep(2 * (attempt + 1))

    return []

def main():
    unmatched_path = "tools/i18n/data/unmatched_corpus.json"
    aligned_path = "tools/i18n/data/aligned_corpus.json"
    cache_path = "tools/i18n/data/llm_translations_cache.json"

    with open(unmatched_path, "r", encoding="utf-8") as f:
        unmatched = json.load(f)

    with open(aligned_path, "r", encoding="utf-8") as f:
        aligned = json.load(f)

    cache = {}
    if os.path.exists(cache_path):
        with open(cache_path, "r", encoding="utf-8") as f:
            cache = json.load(f)
    print(f"Loaded existing cache with {len(cache)} entries.", flush=True)

    # Group entries by unique source text
    source_to_entries = {}
    for e in unmatched:
        s = e["source"]
        if s not in source_to_entries:
            source_to_entries[s] = []
        source_to_entries[s].append(e)

    unique_sources = list(source_to_entries.keys())
    print(f"Total unique texts: {len(unique_sources)}", flush=True)

    # Filter out what is already in cache
    to_translate = []
    for idx, s in enumerate(unique_sources):
        if s in cache:
            continue
        to_translate.append({"id": str(idx), "source": s})

    print(f"Remaining unique texts to translate: {len(to_translate)}", flush=True)

    batch_size = 25
    total_batches = (len(to_translate) + batch_size - 1) // batch_size

    success_count = 0
    fail_count = 0

    for b_idx in range(total_batches):
        batch = to_translate[b_idx * batch_size : (b_idx + 1) * batch_size]
        print(f"Processing Batch {b_idx + 1}/{total_batches} ({len(batch)} items)...", end=" ", flush=True)

        results = call_gemini_api(batch)
        batch_valid = 0

        batch_map = {item["id"]: item["source"] for item in batch}

        for res in results:
            item_id = str(res.get("id"))
            trans = res.get("translation")
            if not item_id or not trans or item_id not in batch_map:
                continue

            orig_source = batch_map[item_id]

            # Verify using format guards
            try:
                validate_translation(orig_source, trans)
                cache[orig_source] = trans
                batch_valid += 1
            except TranslationFormatError:
                if validate_control_codes_preserved(orig_source, trans, strict_line_breaks=False):
                    cache[orig_source] = trans
                    batch_valid += 1

        success_count += batch_valid
        fail_count += (len(batch) - batch_valid)
        print(f"Done: {batch_valid}/{len(batch)} valid (Total in cache: {len(cache)})", flush=True)

        # Save cache every 5 batches
        if (b_idx + 1) % 5 == 0:
            with open(cache_path, "w", encoding="utf-8") as f:
                json.dump(cache, f, ensure_ascii=False, indent=2)

    # Final cache save
    with open(cache_path, "w", encoding="utf-8") as f:
        json.dump(cache, f, ensure_ascii=False, indent=2)

    print("\nTranslation phase complete. Now applying cache to corpus...", flush=True)

    new_unmatched = []
    added_to_aligned = 0

    for e in unmatched:
        src = e["source"]
        if src in cache:
            e_copy = dict(e)
            e_copy["translation"] = cache[src]
            e_copy["match_type"] = "llm_gemini"
            aligned.append(e_copy)
            added_to_aligned += 1
        else:
            new_unmatched.append(e)

    with open(aligned_path, "w", encoding="utf-8") as f:
        json.dump(aligned, f, ensure_ascii=False, indent=2)

    with open(unmatched_path, "w", encoding="utf-8") as f:
        json.dump(new_unmatched, f, ensure_ascii=False, indent=2)

    print(f"Successfully added {added_to_aligned} entries into aligned_corpus.json!", flush=True)
    print(f"Remaining in unmatched_corpus.json: {len(new_unmatched)}", flush=True)

if __name__ == "__main__":
    main()
