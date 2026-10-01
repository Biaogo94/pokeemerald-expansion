// Add entries here
// These entries are example entries which you can replace, but they exist to get you started.
// Remember to modify include/constants/help_window.h to include identifiers so they can be used in event scripts.
const struct HelpWindow gHelpWindowInfo[] =
{
    [HELP_DEMO_WINDOW] =
    {
        .header = COMPOUND_STRING("提示：帮助窗口"),
        .desc = COMPOUND_STRING("这是一个帮助窗口。你可以在屏幕上\n"
                                "显示一大堆玩家根本不会读的文字！\l"
                                "很棒吧！"
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 4, 5},
    },
    [HELP_GAMESTART_WINDOW] =
    {
        .header = COMPOUND_STRING("提示：更多选项"),
        .desc = COMPOUND_STRING("在任何宝可梦中心都可以调整时间，\n"
                                "且不会受到任何惩罚。请务必查看背\l"
                                "包里的重要宝物以及设置菜单，探索\l"
                                "更多自定义游戏体验的方式。祝你玩\l"
                                "得开心！"
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_TRADE_WINDOW] =
    {
        .header = COMPOUND_STRING("警告：兼容性问题"),
        .desc = COMPOUND_STRING("不正确的联机可能会导致存档数据受\n"
                                "到永久损坏。仅在满足以下全部条件\l"
                                "时与其他玩家联机：双方都在游玩《\l"
                                "Heart & Soul》;双方\l"
                                "的游戏版本完全一致;双方的挑战难\l"
                                "度设置完全一致;双方均未开启任何\l"
                                "随机模式。"
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 4, 5},
    },
    [HELP_TELEPORTER_WINDOW] =
    {
        .header = COMPOUND_STRING("可选追加内容：传送机"),
        .desc = COMPOUND_STRING("传送机可以永久将宝可梦转变为它们\n"
                                "的伽勒尔形态。推进故事剧情或完成\l"
                                "全国图鉴都不强制需要伽勒尔形态。"
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_SINJOH_WINDOW] =
    {
        .header = COMPOUND_STRING("可选追加内容：神都"),
        .desc = COMPOUND_STRING("与这名NPC对话可体验可选的追加\n"
                                "内容：神都。通关剧情或集齐全国图\l"
                                "鉴均不需要该内容。这只是额外的奖\l"
                                "励内容，全看你想不想去。"
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_ALOLA_WINDOW] =
    {
        .header = COMPOUND_STRING("额外追加内容：群岛"),
        .desc = COMPOUND_STRING("与该NPC对话可体验额外追加内容"
                                "：群岛。此内容非主线通关或全国图\l"
                                "鉴收集所必需。仅作为额外要素供您\l"
                                "体验。"
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE1_WINDOW] =
    {
        .header = COMPOUND_STRING("幼年宝可梦的特性"),
        .desc = COMPOUND_STRING("皮丘的特性是静电。皮宝宝的特性是\n"
                                "迷人之躯。宝宝丁的特性是迷人之躯"
                                "。无畏小子的特性是毅力。迷唇娃的\l"
                                "特性是迟钝。电击怪的特性是静电。\l"
                                "鸭嘴宝宝的特性是火焰之躯。"
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE2_WINDOW] =
    {
        .header = COMPOUND_STRING("幼年宝可梦的属性"),
        .desc = COMPOUND_STRING("皮丘是电属性。皮宝宝是一般属性。\n"
                                "宝宝丁是一般属性。无畏小子是格斗\l"
                                "属性。迷唇娃是冰属性。电击怪是电\l"
                                "属性。鸭嘴宝宝是火属性。"
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE3_WINDOW] =
    {
        .header = COMPOUND_STRING("幼年宝可梦的叫声"),
        .desc = COMPOUND_STRING("皮丘：哇啊啊！\n"
                                "皮宝宝：咿！\n"
                                "宝宝丁：啦啦啦！\n"
                                "无畏小子：喝呀！\n"
                                "迷唇娃：嘿嘿！\n"
                                "电击怪：哟、哟、哟！\n"
                                "鸭嘴宝宝：啧！"
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE4_WINDOW] =
    {
        .header = COMPOUND_STRING("幼年宝可梦的习性"),
        .desc = COMPOUND_STRING("皮丘喜欢整天玩耍。皮宝宝喜欢眺望\n"
                                "月亮。宝宝丁能让大家入睡。无畏小\l"
                                "子总是不断修行。迷唇娃喜欢炫耀自\l"
                                "己。电击怪会积蓄电力。鸭嘴宝宝常\l"
                                "常容易生气。"
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_POKEBLOCK_WINDOW] =
    {
        .header = COMPOUND_STRING("喂食器：普通宝可方块"),
        .desc = COMPOUND_STRING("宝可方块颜色能吸引对应满个体值(\n"
                                "V)：红色：HP、攻击、速度  \l 蓝色：HP、特攻、速度粉色：攻\l"
                                "击、特攻、速度  绿色：HP、防\l"
                                "御、特防黄色：HP、攻击、防御 \l"
                                "  紫色：攻击、防御、特防靛色：\lHP、特攻、特防   褐色：防御"
                                "、速度、特防浅蓝：特攻、速度、特\l"
                                "防  橄榄：攻击、防御、速度灰色"
                                "：HP、攻击、特攻所有宝可方块均\l能吸引隐藏特性。"

                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_GOLD_POKEBLOCK_WINDOW] =
    {
        .header = COMPOUND_STRING("喂食器：金色宝可方块"),
        .desc = COMPOUND_STRING("金色宝可方块能吸引拥有5项满个体\n"
                                "值的宝可梦。口味决定了哪项个体值\l"
                                "不满：辣味：缺特攻    涩味：\l"
                                "缺攻击甜味：缺特防    苦味：\l"
                                "缺速度酸味：缺HP所有宝可方块均\l"
                                "能吸引隐藏特性。"
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    // Add more entries
};
