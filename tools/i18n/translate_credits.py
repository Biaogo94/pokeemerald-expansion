"""Translate the FRLG credits role labels, preserving \\n layout exactly."""

from pathlib import Path

P = Path(__file__).resolve().parents[2] / 'src/credits_frlg.c'
src = P.read_text(encoding='utf-8')

ROLES = {
    'Pokémon FireRed Version\\nStaff': '宝可梦 火红\\n制作人员',
    'Pokémon LeafGreen Version\\nStaff': '宝可梦 叶绿\\n制作人员',
    'Director': '导演',
    'Art Director': '美术总监',
    'Battle Director': '战斗总监',
    'Program Leader': '程序负责人',
    'Planning Leader': '策划负责人',
    'Graphic Design Leader': '美术设计负责人',
    'Programmers': '程序',
    'System Programmers': '系统程序',
    'Graphic Designers': '美术设计',
    'Music Composition': '音乐作曲',
    'Sound Effects': '音效',
    'Game Designers': '游戏设计',
    'Game Scenario': '游戏剧本',
    'Script Designer': '脚本设计',
    'Map Designer': '地图设计',
    'Parametric Designers': '参数设计',
    'POKéDEX Text': '图鉴文本',
    'POKéMON Designers': '宝可梦设计',
    'Supporting Programmers': '程序支援',
    'NCL Product Testing': 'NCL 产品测试',
    'Special Thanks': '特别感谢',
    'Braille Code Check': '点字监修',
    'Japan Braille Library': '日本点字图书馆',
    'Information Supervisors': '资料监修',
    'Coordinators': '协调人员',
    'Task Managers': '项目管理',
    'Producers': '制作人',
    'Executive Director': '执行总监',
    'Executive Producer': '执行制作人',
    'English Version Coordinators': '英文版协调',
    'Translator': '翻译',
    'Text Editor': '文本编辑',
    'Environment & Tool Programmers': '环境与工具程序',
    'NOA Product Testing': 'NOA 产品测试',
    'Graphic Designer': '美术设计',
    'National Federation\\n{CLEAR_TO 0x13}of the Blind': '全美盲人\\n{CLEAR_TO 0x13}联合会',
    'National Information Library\\n{CLEAR_TO 0x2D}Service': '国家信息\\n{CLEAR_TO 0x2D}图书馆服务',
    'The Royal New Zealand\\nFoundation of the Blind': '新西兰皇家\\n盲人基金会',
}

count = 0
for en, zh in ROLES.items():
    old = f'_("{en}'
    new = f'_("{zh}'
    n = src.count(old)
    if n:
        src = src.replace(old, new)
        count += n
    # roles on their own \\n-delimited line inside compound credit strings
    if '\\' not in en:
        old2 = f'\\n{en}\\n'
        n2 = src.count(old2)
        if n2:
            src = src.replace(old2, f'\\n{zh}\\n')
            count += n2
P.write_text(src, encoding='utf-8')
print(f'{count} credit role labels translated')
