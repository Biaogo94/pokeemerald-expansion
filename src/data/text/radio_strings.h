// Radio station strings ported from pokecrystal
// Lines fit ~32 char width for 28-tile window

#ifndef GUARD_DATA_TEXT_RADIO_STRINGS_H
#define GUARD_DATA_TEXT_RADIO_STRINGS_H

// ==========================================================
// Station Names (displayed at top of radio UI)
// ==========================================================

static const u8 sRadioStationName_OaksPkmnTalk[]    = _("大木博士的宝可梦讲座");
static const u8 sRadioStationName_PokedexShow[]     = _("宝可梦图鉴秀");
static const u8 sRadioStationName_PokemonMusic[]    = _("宝可梦音乐");
static const u8 sRadioStationName_LuckyChannel[]    = _("幸运号码频道");
static const u8 sRadioStationName_BuenasPassword[]  = _("葵的密码");
static const u8 sRadioStationName_Unown[]           = _("?????");
static const u8 sRadioStationName_PlacesAndPeople[] = _("城镇与人物");
static const u8 sRadioStationName_LetsAllSing[]     = _("大家一起来唱歌！");
static const u8 sRadioStationName_PokeFlute[]       = _("宝可梦之笛");

static const u8 sRadioStationName_HoennSound[]  = _("丰缘之声");

// ==========================================================
// Hoenn Sound
// ==========================================================

static const u8 sRadioText_Hoenn1[] = _("来自名为丰缘的");
static const u8 sRadioText_Hoenn2[] = _("遥远地区的宝可梦旋律！");
static const u8 sRadioText_Hoenn3[] = _("来自该地区的野生宝可梦");
static const u8 sRadioText_Hoenn4[] = _("可能会在附近出现！");

// ==========================================================
// POKéDEX Show
// ==========================================================

static const u8 sRadioText_PokedexShow_Intro[] = _("大木博士的图鉴秀！");
static const u8 sRadioText_PokedexShow_TodaysPrefix[] = _("大木：今天的宝可梦是");

// ==========================================================
// Oak's POKéMON Talk
// ==========================================================

static const u8 sRadioText_OPT_Intro[] = _("玛丽：大木博士的宝可梦讲座！");
static const u8 sRadioText_OPT_WithMeMary[] = _("还有我玛丽！");
static const u8 sRadioText_OPT_OakPrefix[] = _("大木：");
static const u8 sRadioText_OPT_SeenAround[] = _("可能会出没在");
static const u8 sRadioText_OPT_MaryPrefix[] = _("玛丽：");
static const u8 sRadioText_OPT_MaryIs[] = _("真是");

// Pokemon Channel interlude
static const u8 sRadioText_OPT_PokemonChannel[] = _("宝可梦频道");

// Adverbs (randomly selected)
static const u8 sRadioText_OPT_Adverb_SweetAdorably[]      = _("甜美又惹人怜爱地");
static const u8 sRadioText_OPT_Adverb_WigglySlickly[]      = _("扭来扭去，挺");
static const u8 sRadioText_OPT_Adverb_AptlyNamed[]         = _("名副其实，相当");
static const u8 sRadioText_OPT_Adverb_UndeniablyKindOf[]   = _("怎么看都觉得");
static const u8 sRadioText_OPT_Adverb_Unbearably[]         = _("让人欲罢不能地");
static const u8 sRadioText_OPT_Adverb_WowImpressively[]    = _("非常非常");
static const u8 sRadioText_OPT_Adverb_AlmostPoisonously[]  = _("简直让人神魂颠倒般");
static const u8 sRadioText_OPT_Adverb_Sensually[]          = _("总感觉有点");
static const u8 sRadioText_OPT_Adverb_Mischievously[]      = _("淘气得格外");
static const u8 sRadioText_OPT_Adverb_Topically[]          = _("紧跟潮流般");
static const u8 sRadioText_OPT_Adverb_Addictively[]        = _("让人彻底着迷般");
static const u8 sRadioText_OPT_Adverb_LooksInWater[]       = _("在水里的样子");
static const u8 sRadioText_OPT_Adverb_EvolutionMustBe[]    = _("进化后肯定会");
static const u8 sRadioText_OPT_Adverb_Provocatively[]      = _("耐人寻味地");
static const u8 sRadioText_OPT_Adverb_FlippedOut[]         = _("超级无敌");
static const u8 sRadioText_OPT_Adverb_HeartMeltingly[]     = _("让人怦然心动般");

static const u8 *const sRadioText_OPT_Adverbs[] =
{
    sRadioText_OPT_Adverb_SweetAdorably,
    sRadioText_OPT_Adverb_WigglySlickly,
    sRadioText_OPT_Adverb_AptlyNamed,
    sRadioText_OPT_Adverb_UndeniablyKindOf,
    sRadioText_OPT_Adverb_Unbearably,
    sRadioText_OPT_Adverb_WowImpressively,
    sRadioText_OPT_Adverb_AlmostPoisonously,
    sRadioText_OPT_Adverb_Sensually,
    sRadioText_OPT_Adverb_Mischievously,
    sRadioText_OPT_Adverb_Topically,
    sRadioText_OPT_Adverb_Addictively,
    sRadioText_OPT_Adverb_LooksInWater,
    sRadioText_OPT_Adverb_EvolutionMustBe,
    sRadioText_OPT_Adverb_Provocatively,
    sRadioText_OPT_Adverb_FlippedOut,
    sRadioText_OPT_Adverb_HeartMeltingly,
};

// Adjectives (randomly selected)
static const u8 sRadioText_OPT_Adj_Cute[]           = _("可爱。");
static const u8 sRadioText_OPT_Adj_Weird[]          = _("奇怪。");
static const u8 sRadioText_OPT_Adj_Pleasant[]       = _("令人愉快。");
static const u8 sRadioText_OPT_Adj_BoldSortOf[]     = _("挺大胆的吧。");
static const u8 sRadioText_OPT_Adj_Frightening[]    = _("让人害怕。");
static const u8 sRadioText_OPT_Adj_SuaveDebonair[]  = _("潇洒又风度翩翩！");
static const u8 sRadioText_OPT_Adj_Powerful[]        = _("威力十足。");
static const u8 sRadioText_OPT_Adj_Exciting[]        = _("令人兴奋。");
static const u8 sRadioText_OPT_Adj_Groovy[]          = _("太带劲了！");
static const u8 sRadioText_OPT_Adj_Inspiring[]       = _("鼓舞人心。");
static const u8 sRadioText_OPT_Adj_Friendly[]        = _("亲切友善。");
static const u8 sRadioText_OPT_Adj_HotHotHot[]       = _("火热，火热，太火热了！");
static const u8 sRadioText_OPT_Adj_Stimulating[]     = _("充满刺激。");
static const u8 sRadioText_OPT_Adj_Guarded[]         = _("充满戒备。");
static const u8 sRadioText_OPT_Adj_Lovely[]          = _("惹人喜爱。");
static const u8 sRadioText_OPT_Adj_Speedy[]          = _("神速敏捷。");

static const u8 *const sRadioText_OPT_Adjectives[] =
{
    sRadioText_OPT_Adj_Cute,
    sRadioText_OPT_Adj_Weird,
    sRadioText_OPT_Adj_Pleasant,
    sRadioText_OPT_Adj_BoldSortOf,
    sRadioText_OPT_Adj_Frightening,
    sRadioText_OPT_Adj_SuaveDebonair,
    sRadioText_OPT_Adj_Powerful,
    sRadioText_OPT_Adj_Exciting,
    sRadioText_OPT_Adj_Groovy,
    sRadioText_OPT_Adj_Inspiring,
    sRadioText_OPT_Adj_Friendly,
    sRadioText_OPT_Adj_HotHotHot,
    sRadioText_OPT_Adj_Stimulating,
    sRadioText_OPT_Adj_Guarded,
    sRadioText_OPT_Adj_Lovely,
    sRadioText_OPT_Adj_Speedy,
};

// ==========================================================
// POKéMON Music Channel (Ben & Fern)
// ==========================================================

static const u8 sRadioText_BenIntro[] = _("本：宝可梦音乐频道！");
static const u8 sRadioText_BenIntro2[] = _("我是DJ本！");
static const u8 sRadioText_FernIntro[] = _("百合花：宝可梦音乐！");
static const u8 sRadioText_FernIntro2[] = _("由DJ百合花主持！");
// "Today's {DAY}," built dynamically
static const u8 sRadioText_BenFern_TodayIs[] = _("今天是");
static const u8 sRadioText_BenFern_JamTo[] = _("一起来听");
static const u8 sRadioText_BenFern_ChillTo[] = _("就静静放松听这首");
static const u8 sRadioText_BenFern_March[] = _("宝可梦进行曲！");
static const u8 sRadioText_BenFern_Lullaby[] = _("宝可梦摇篮曲！");

// ==========================================================
// Lucky Channel
// ==========================================================

static const u8 sRadioText_LC1[] = _("里德：呀吼！大家最近");
static const u8 sRadioText_LC2[] = _("过得如何？无论你现在是意气风发，");
static const u8 sRadioText_LC3[] = _("千万不要错过");
static const u8 sRadioText_LC4[] = _("幸运号码秀！");
static const u8 sRadioText_LC5[] = _("本周的幸运号码是");
// "{number}!" built dynamically
static const u8 sRadioText_LC_Repeat[] = _("我再重复一遍！");
static const u8 sRadioText_LC_Match[] = _("要是对中了就去");
static const u8 sRadioText_LC_Tower[] = _("广播电台吧！");
static const u8 sRadioText_LC_Drag1[] = _("......一直重复念");
static const u8 sRadioText_LC_Drag2[] = _("真是麻烦死了......");

// ==========================================================
// Places and People
// ==========================================================

static const u8 sRadioText_PnP_Intro[] = _("《地点与人物！》由");
static const u8 sRadioText_PnP_Intro2[] = _("DJ莉莉为您带来！");
static const u8 sRadioText_PnP_Space[] = _(" ");

// People adjectives
static const u8 sRadioText_PnP_Cute[]       = _("很可爱。");
static const u8 sRadioText_PnP_Lazy[]       = _("有点懒散。");
static const u8 sRadioText_PnP_Happy[]      = _("总是开开心心的。");
static const u8 sRadioText_PnP_Noisy[]      = _("相当吵闹。");
static const u8 sRadioText_PnP_Precocious[] = _("很早熟。");
static const u8 sRadioText_PnP_Bold[]       = _("挺大胆的。");
static const u8 sRadioText_PnP_Picky[]      = _("太挑剔了！");
static const u8 sRadioText_PnP_SortOfOK[]   = _("感觉还行。");
static const u8 sRadioText_PnP_SoSo[]       = _("也就一般般吧。");
static const u8 sRadioText_PnP_Great[]       = _("其实很棒呢。");
static const u8 sRadioText_PnP_MyType[]      = _("正是我的菜。");
static const u8 sRadioText_PnP_Cool[]        = _("真是太帅了，对吧？");
static const u8 sRadioText_PnP_Inspiring[]   = _("真令人振奋！");
static const u8 sRadioText_PnP_Weird[]       = _("有点怪怪的。");
static const u8 sRadioText_PnP_RightForMe[]  = _("适合我吗？");
static const u8 sRadioText_PnP_Odd[]         = _("肯定不太对劲！");

static const u8 *const sRadioText_PnP_PeopleAdj[] =
{
    sRadioText_PnP_Cute,
    sRadioText_PnP_Lazy,
    sRadioText_PnP_Happy,
    sRadioText_PnP_Noisy,
    sRadioText_PnP_Precocious,
    sRadioText_PnP_Bold,
    sRadioText_PnP_Picky,
    sRadioText_PnP_SortOfOK,
    sRadioText_PnP_SoSo,
    sRadioText_PnP_Great,
    sRadioText_PnP_MyType,
    sRadioText_PnP_Cool,
    sRadioText_PnP_Inspiring,
    sRadioText_PnP_Weird,
    sRadioText_PnP_RightForMe,
    sRadioText_PnP_Odd,
};

// ==========================================================
// Rocket Radio
// ==========================================================

static const u8 sRadioStationName_Rocket[] = _("火箭队");
static const u8 sRadioText_Rocket1[]  = _("......咳咳，我们是");
static const u8 sRadioText_Rocket2[]  = _("火箭队！");
static const u8 sRadioText_Rocket3[]  = _("历经三年");
static const u8 sRadioText_Rocket4[]  = _("的精心筹备，我们");
static const u8 sRadioText_Rocket5[]  = _("如今终于在此");
static const u8 sRadioText_Rocket6[]  = _("浴火重生了！");
static const u8 sRadioText_Rocket7[]  = _("坂木老大！");
static const u8 sRadioText_Rocket8[]  = _("您听得见吗？");
static const u8 sRadioText_Rocket9[]  = _("");
static const u8 sRadioText_Rocket10[] = _("");

// ==========================================================
// Buena's Password
// ==========================================================

static const u8 sRadioText_Buena1[] = _("葵：我是葵！");
static const u8 sRadioText_Buena2[] = _("今天的暗号是！");
static const u8 sRadioText_Buena3[] = _("让我想想......是");
// "{password}!" built dynamically with STR_VAR_1
static const u8 sRadioText_Buena4[] = _("{STR_VAR_1}！");
static const u8 sRadioText_Buena5[] = _("千万别忘记哦！我在");
static const u8 sRadioText_Buena6[] = _("满金市的广播电台！");


// ==========================================================
// Buena's Password Categories & Options
// ==========================================================

static const u8 sRadioBuenaPassword_NewBarkTown[]     = _("若叶镇");
static const u8 sRadioBuenaPassword_CherrygroveCity[]  = _("吉花市");
static const u8 sRadioBuenaPassword_AzaleaTown[]      = _("桧皮镇");
static const u8 sRadioBuenaPassword_Flying[]          = _("飞行");
static const u8 sRadioBuenaPassword_Bug[]             = _("虫");
static const u8 sRadioBuenaPassword_Grass[]           = _("草");
static const u8 sRadioBuenaPassword_PkmnTalk[]        = _("宝可梦讲座");
static const u8 sRadioBuenaPassword_PkmnMusic[]       = _("宝可梦音乐");
static const u8 sRadioBuenaPassword_LuckyChannel[]    = _("幸运号码频道");

// ==========================================================
// Oak's POKéMON Talk - Special Reports
// ==========================================================

static const u8 sOPT_Report_Clefairy_0[]  = _("玛琪：今晚将为您带来");
static const u8 sOPT_Report_Clefairy_1[]  = _("一刻，尽在《宝可梦漫谈》！");
static const u8 sOPT_Report_Clefairy_2[]  = _("大木：今天我们要聚焦");
static const u8 sOPT_Report_Clefairy_3[]  = _("神秘的皮皮！");
static const u8 sOPT_Report_Clefairy_4[]  = _("它们聚集在月见山，");
static const u8 sOPT_Report_Clefairy_5[]  = _("沐浴着满月的光辉。");
static const u8 sOPT_Report_Clefairy_6[]  = _("玛莉：它们还会围成圈跳舞呢！");
static const u8 sOPT_Report_Clefairy_7[]  = _("真是又奇妙又可爱！");
static const u8 sOPT_Report_Clefairy_8[]  = _("大木：这不仅是自古以来的谜团，");
static const u8 sOPT_Report_Clefairy_9[]  = _("更是一大奇景啊！");

static const u8 sOPT_Report_Lapras_0[]  = _("玛莉：今天节目登场的，");
static const u8 sOPT_Report_Lapras_1[]  = _("是一位温柔的庞然大物！");
static const u8 sOPT_Report_Lapras_2[]  = _("大木：它就是海上的渡轮，");
static const u8 sOPT_Report_Lapras_3[]  = _("深受喜爱的拉普拉斯！");
static const u8 sOPT_Report_Lapras_4[]  = _("虽然在互连洞能见到它，");
static const u8 sOPT_Report_Lapras_5[]  = _("别处却无处可寻。真奇妙！");
static const u8 sOPT_Report_Lapras_6[]  = _("玛莉：既稀有又温顺！");
static const u8 sOPT_Report_Lapras_7[]  = _("而且它还会唱歌呢！");
static const u8 sOPT_Report_Lapras_8[]  = _("大木：据说它的歌声");
static const u8 sOPT_Report_Lapras_9[]  = _("能抚慰大海的心灵。");

static const u8 sOPT_Report_Ampharos_0[]  = _("玛莉：欢迎大家收听！");
static const u8 sOPT_Report_Ampharos_1[]  = _("《宝可梦漫谈》时间到！");
static const u8 sOPT_Report_Ampharos_2[]  = _("大木：今天就让我们来看看");
static const u8 sOPT_Report_Ampharos_3[]  = _("我们的好朋友电龙！");
static const u8 sOPT_Report_Ampharos_4[]  = _("它明亮的尾巴能穿透浓雾，");
static const u8 sOPT_Report_Ampharos_5[]  = _("为迷路的人指引方向。");
static const u8 sOPT_Report_Ampharos_6[]  = _("玛莉：强大又优雅，");
static const u8 sOPT_Report_Ampharos_7[]  = _("而且毫无疑问非常亲切友善！");
static const u8 sOPT_Report_Ampharos_8[]  = _("大木：在很多关于灯塔的");
static const u8 sOPT_Report_Ampharos_9[]  = _("故事里，它都是主角呢！");

static const u8 sOPT_Report_Sudowoodo_0[]  = _("玛丽：接下来介绍的，是出现在");
static const u8 sOPT_Report_Sudowoodo_1[]  = _("36号道路上的大怪咖......");
static const u8 sOPT_Report_Sudowoodo_2[]  = _("大木：树才怪！虽然看起来像");
static const u8 sOPT_Report_Sudowoodo_3[]  = _("一棵树，但其实根本不是！");
static const u8 sOPT_Report_Sudowoodo_4[]  = _("它挡在路中央，");
static const u8 sOPT_Report_Sudowoodo_5[]  = _("不浇水的话可是一动不动。");
static const u8 sOPT_Report_Sudowoodo_6[]  = _("玛丽：它只对");
static const u8 sOPT_Report_Sudowoodo_7[]  = _("杰尼龟喷壶有反应！");
static const u8 sOPT_Report_Sudowoodo_8[]  = _("大木：那可不是什么灌木，");
static const u8 sOPT_Report_Sudowoodo_9[]  = _("而是伪装成树的岩石属性宝可梦！");

static const u8 sOPT_Report_RedGyarados_0[]  = _("玛丽：今天的话题，");
static const u8 sOPT_Report_RedGyarados_1[]  = _("可是来自城都地区的惊人消息！");
static const u8 sOPT_Report_RedGyarados_2[]  = _("大木：有训练家在愤怒之湖");
static const u8 sOPT_Report_RedGyarados_3[]  = _("目击到了红色的暴鲤龙！");
static const u8 sOPT_Report_RedGyarados_4[]  = _("和通常的蓝色暴鲤龙不同，");
static const u8 sOPT_Report_RedGyarados_5[]  = _("这只可是鲜艳的深红色！");
static const u8 sOPT_Report_RedGyarados_6[]  = _("玛丽：有人说这和某些");
static const u8 sOPT_Report_RedGyarados_7[]  = _("奇怪的电波有关呢！");
static const u8 sOPT_Report_RedGyarados_8[]  = _("大木：神秘的进化......");
static const u8 sOPT_Report_RedGyarados_9[]  = _("恐怕并非自然演变。");

static const u8 sOPT_Report_Unown_0[]  = _("玛丽：各位去过阿露福");
static const u8 sOPT_Report_Unown_1[]  = _("遗迹吗？真是令人毛骨悚然呢！");
static const u8 sOPT_Report_Unown_2[]  = _("大木：墙壁上刻满了奇异符号，");
static const u8 sOPT_Report_Unown_3[]  = _("仿佛古代的符文。");
static const u8 sOPT_Report_Unown_4[]  = _("在里面你会发现未知图腾.....\n.");
static const u8 sOPT_Report_Unown_5[]  = _("每一只都长得像文字一样！");
static const u8 sOPT_Report_Unown_6[]  = _("胡桃：它们是不是拼出了什么呢？");
static const u8 sOPT_Report_Unown_7[]  = _("还是单纯为了吓唬我们？！");
static const u8 sOPT_Report_Unown_8[]  = _("大木：这真是大自然的奥秘，");
static const u8 sOPT_Report_Unown_9[]  = _("至今仍未被解开。");

static const u8 sOPT_Report_Snubbull_0[]  = _("胡桃：满金市的市民们");
static const u8 sOPT_Report_Snubbull_1[]  = _("正在到处搜寻呢！");
static const u8 sOPT_Report_Snubbull_2[]  = _("大木：有一只布鲁离家出走，");
static const u8 sOPT_Report_Snubbull_3[]  = _("正在四处逃窜！");
static const u8 sOPT_Report_Snubbull_4[]  = _("平时胆小又爱撒娇的它，");
static const u8 sOPT_Report_Snubbull_5[]  = _("有人在车站附近看到了它的身影。");
static const u8 sOPT_Report_Snubbull_6[]  = _("胡桃：也许它是在追寻真爱....\n..");
static const u8 sOPT_Report_Snubbull_7[]  = _("或者只是一场大冒险！");
static const u8 sOPT_Report_Snubbull_8[]  = _("大木：请大家擦亮眼睛，");
static const u8 sOPT_Report_Snubbull_9[]  = _("并随时准备好牵引绳。");

static const u8 sOPT_Report_Slowpoke_0[]  = _("胡桃：本周来自桧皮镇的");
static const u8 sOPT_Report_Slowpoke_1[]  = _("重大新闻！");
static const u8 sOPT_Report_Slowpoke_2[]  = _("大木：呆呆兽们历经危机后，");
static const u8 sOPT_Report_Slowpoke_3[]  = _("终于回到了呆呆兽之井！");
static const u8 sOPT_Report_Slowpoke_4[]  = _("火箭队竟然割下了");
static const u8 sOPT_Report_Slowpoke_5[]  = _("它们的尾巴！真是太恶劣了！");
static const u8 sOPT_Report_Slowpoke_6[]  = _("胡桃：不过，多亏了一位勇敢年轻的");
static const u8 sOPT_Report_Slowpoke_7[]  = _("训练家制止了他们！");
static const u8 sOPT_Report_Slowpoke_8[]  = _("大木：呆呆兽们都很平安，");
static const u8 sOPT_Report_Slowpoke_9[]  = _("又开开心心地打起瞌睡了。");

static const u8 sOPT_Report_LavenderTower_0[]  = _("胡桃：紫苑镇的那座塔");
static const u8 sOPT_Report_LavenderTower_1[]  = _("可是改头换面了呢！");
static const u8 sOPT_Report_LavenderTower_2[]  = _("大木：以前的幽灵之塔，");
static const u8 sOPT_Report_LavenderTower_3[]  = _("如今变成了广播电台！");
static const u8 sOPT_Report_LavenderTower_4[]  = _("不过有些当地人说，");
static const u8 sOPT_Report_LavenderTower_5[]  = _("感觉还是......阴森森的。");
static const u8 sOPT_Report_LavenderTower_6[]  = _("胡桃：我发誓，我真的在");
static const u8 sOPT_Report_LavenderTower_7[]  = _("录音间麦克风旁看到鬼斯了！");
static const u8 sOPT_Report_LavenderTower_8[]  = _("大木：说不定只是杂音干扰....\n..");
static const u8 sOPT_Report_LavenderTower_9[]  = _("抑或是真的幽灵！");

static const u8 sOPT_Report_Tentacruel_0[]  = _("胡桃：今天漩涡列岛那边");
static const u8 sOPT_Report_Tentacruel_1[]  = _("传来了奇怪的新闻！");
static const u8 sOPT_Report_Tentacruel_2[]  = _("大木：有群毒刺水母");
static const u8 sOPT_Report_Tentacruel_3[]  = _("包围了洞窟入口！");
static const u8 sOPT_Report_Tentacruel_4[]  = _("它们个头巨大，看起来");
static const u8 sOPT_Report_Tentacruel_5[]  = _("极具领地意识。");
static const u8 sOPT_Report_Tentacruel_6[]  = _("胡桃：它们挡住了去路，");
static const u8 sOPT_Report_Tentacruel_7[]  = _("却并没有发动攻击......");
static const u8 sOPT_Report_Tentacruel_8[]  = _("大木：就仿佛是在守护着");
static const u8 sOPT_Report_Tentacruel_9[]  = _("深海之下的某种东西。");

#define OPT_REPORT_LINES 10
#define NUM_OPT_REPORTS 10

static const u8 *const sOPT_Reports[NUM_OPT_REPORTS][OPT_REPORT_LINES] =
{
    { sOPT_Report_Clefairy_0, sOPT_Report_Clefairy_1, sOPT_Report_Clefairy_2, sOPT_Report_Clefairy_3, sOPT_Report_Clefairy_4, sOPT_Report_Clefairy_5, sOPT_Report_Clefairy_6, sOPT_Report_Clefairy_7, sOPT_Report_Clefairy_8, sOPT_Report_Clefairy_9 },
    { sOPT_Report_Lapras_0, sOPT_Report_Lapras_1, sOPT_Report_Lapras_2, sOPT_Report_Lapras_3, sOPT_Report_Lapras_4, sOPT_Report_Lapras_5, sOPT_Report_Lapras_6, sOPT_Report_Lapras_7, sOPT_Report_Lapras_8, sOPT_Report_Lapras_9 },
    { sOPT_Report_Ampharos_0, sOPT_Report_Ampharos_1, sOPT_Report_Ampharos_2, sOPT_Report_Ampharos_3, sOPT_Report_Ampharos_4, sOPT_Report_Ampharos_5, sOPT_Report_Ampharos_6, sOPT_Report_Ampharos_7, sOPT_Report_Ampharos_8, sOPT_Report_Ampharos_9 },
    { sOPT_Report_Sudowoodo_0, sOPT_Report_Sudowoodo_1, sOPT_Report_Sudowoodo_2, sOPT_Report_Sudowoodo_3, sOPT_Report_Sudowoodo_4, sOPT_Report_Sudowoodo_5, sOPT_Report_Sudowoodo_6, sOPT_Report_Sudowoodo_7, sOPT_Report_Sudowoodo_8, sOPT_Report_Sudowoodo_9 },
    { sOPT_Report_RedGyarados_0, sOPT_Report_RedGyarados_1, sOPT_Report_RedGyarados_2, sOPT_Report_RedGyarados_3, sOPT_Report_RedGyarados_4, sOPT_Report_RedGyarados_5, sOPT_Report_RedGyarados_6, sOPT_Report_RedGyarados_7, sOPT_Report_RedGyarados_8, sOPT_Report_RedGyarados_9 },
    { sOPT_Report_Unown_0, sOPT_Report_Unown_1, sOPT_Report_Unown_2, sOPT_Report_Unown_3, sOPT_Report_Unown_4, sOPT_Report_Unown_5, sOPT_Report_Unown_6, sOPT_Report_Unown_7, sOPT_Report_Unown_8, sOPT_Report_Unown_9 },
    { sOPT_Report_Snubbull_0, sOPT_Report_Snubbull_1, sOPT_Report_Snubbull_2, sOPT_Report_Snubbull_3, sOPT_Report_Snubbull_4, sOPT_Report_Snubbull_5, sOPT_Report_Snubbull_6, sOPT_Report_Snubbull_7, sOPT_Report_Snubbull_8, sOPT_Report_Snubbull_9 },
    { sOPT_Report_Slowpoke_0, sOPT_Report_Slowpoke_1, sOPT_Report_Slowpoke_2, sOPT_Report_Slowpoke_3, sOPT_Report_Slowpoke_4, sOPT_Report_Slowpoke_5, sOPT_Report_Slowpoke_6, sOPT_Report_Slowpoke_7, sOPT_Report_Slowpoke_8, sOPT_Report_Slowpoke_9 },
    { sOPT_Report_LavenderTower_0, sOPT_Report_LavenderTower_1, sOPT_Report_LavenderTower_2, sOPT_Report_LavenderTower_3, sOPT_Report_LavenderTower_4, sOPT_Report_LavenderTower_5, sOPT_Report_LavenderTower_6, sOPT_Report_LavenderTower_7, sOPT_Report_LavenderTower_8, sOPT_Report_LavenderTower_9 },
    { sOPT_Report_Tentacruel_0, sOPT_Report_Tentacruel_1, sOPT_Report_Tentacruel_2, sOPT_Report_Tentacruel_3, sOPT_Report_Tentacruel_4, sOPT_Report_Tentacruel_5, sOPT_Report_Tentacruel_6, sOPT_Report_Tentacruel_7, sOPT_Report_Tentacruel_8, sOPT_Report_Tentacruel_9 },
};

#endif // GUARD_DATA_TEXT_RADIO_STRINGS_H
