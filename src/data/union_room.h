ALIGNED(4) static const u8 sText_EmptyString[] = _("");
ALIGNED(4) static const u8 sText_Colon[] = _(":");
ALIGNED(4) static const u8 sText_ID[] = _("{ID}");
ALIGNED(4) static const u8 sText_PleaseStartOver[] = _("请重新再试一次。");
ALIGNED(4) static const u8 sText_WirelessSearchCanceled[] = _("无线连接系统搜索已取消。");
ALIGNED(4) static const u8 sText_AwaitingCommunucation2[] = _("正在等待其他玩家连接。"); // Unused
ALIGNED(4) static const u8 sText_AwaitingCommunication[] = _("{STR_VAR_1}！正在等待\n其他玩家连接。");
ALIGNED(4) static const u8 sText_AwaitingLinkPressStart[] = _("{STR_VAR_1}！等待连接！所有玩家准备完毕后请按START键。");
ALIGNED(4) static const u8 sJPText_SingleBattle[] = _("举办单打对战");
ALIGNED(4) static const u8 sJPText_DoubleBattle[] = _("举办双打对战");
ALIGNED(4) static const u8 sJPText_MultiBattle[] = _("举办多人对战");
ALIGNED(4) static const u8 sJPText_TradePokemon[] = _("举办宝可梦交换");
ALIGNED(4) static const u8 sJPText_Chat[] = _("发起聊天");
ALIGNED(4) static const u8 sJPText_DistWonderCard[] = _("分发神秘卡片");
ALIGNED(4) static const u8 sJPText_DistWonderNews[] = _("分发神秘新闻");
ALIGNED(4) static const u8 sJPText_DistMysteryEvent[] = _("举办神秘活动"); // Unused
ALIGNED(4) static const u8 sJPText_HoldPokemonJump[] = _("举办跳绳");
ALIGNED(4) static const u8 sJPText_HoldBerryCrush[] = _("举办树果捣碎机");
ALIGNED(4) static const u8 sJPText_HoldBerryPicking[] = _("举办采树果");
ALIGNED(4) static const u8 sJPText_HoldSpinTrade[] = _("举办转转交换");
ALIGNED(4) static const u8 sJPText_HoldSpinShop[] = _("举办转转商店");

// Unused
static const u8 *const sJPLinkGroupActionTexts[] = {
    sJPText_SingleBattle,
    sJPText_DoubleBattle,
    sJPText_MultiBattle,
    sJPText_TradePokemon,
    sJPText_Chat,
    sJPText_DistWonderCard,
    sJPText_DistWonderNews,
    sJPText_DistWonderCard,
    sJPText_HoldPokemonJump,
    sJPText_HoldBerryCrush,
    sJPText_HoldBerryPicking,
    sJPText_HoldBerryPicking,
    sJPText_HoldSpinTrade,
    sJPText_HoldSpinShop
};

static const u8 sText_1PlayerNeeded[] = _("需要1名玩家。");
static const u8 sText_2PlayersNeeded[] = _("需要2名玩家。");
static const u8 sText_3PlayersNeeded[] = _("需要3名玩家。");
static const u8 sText_4PlayersNeeded[] = _("需要4名玩家。");
static const u8 sText_2PlayerMode[] = _("2名玩家模式");
static const u8 sText_3PlayerMode[] = _("3名玩家模式");
static const u8 sText_4PlayerMode[] = _("4名玩家模式");
static const u8 sText_5PlayerMode[] = _("5名玩家模式");

static const u8 *const sPlayersNeededOrModeTexts[][5] = {
    // 2 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode
    },
    // 4 players required
    {
        sText_3PlayersNeeded,
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_4PlayerMode
    },
    // 2-5 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    },
    // 3-5 players required
    {
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    },
    // 2-4 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode,
        sText_3PlayerMode,
        sText_4PlayerMode
    }
};

ALIGNED(4) static const u8 sText_BButtonCancel[] = _("{B_BUTTON}取消");
ALIGNED(4) static const u8 sJPText_SearchingForParticipants[] = _("而正在招募参加者！"); // Unused, may have been cut off
ALIGNED(4) static const u8 sText_PlayerContactedYouForXAccept[] = _("收到了来自{STR_VAR_2}\n的联络！要同意\l{STR_VAR_1}吗？");
ALIGNED(4) static const u8 sText_PlayerContactedYouShareX[] = _("收到了来自{STR_VAR_2}\n的联络！要开始\l{STR_VAR_1}吗？");
ALIGNED(4) static const u8 sText_PlayerContactedYouAddToMembers[] = _("收到了来自{STR_VAR_2}\n的联络！要将其加为成员吗？");
ALIGNED(4) static const u8 sText_AreTheseMembersOK[] = _("{STR_VAR_1}！以现有的\n成员开始，可以吗？");
ALIGNED(4) static const u8 sText_CancelModeWithTheseMembers[] = _("要放弃以当前成员进行\n{STR_VAR_1}模式吗？");
ALIGNED(4) static const u8 sText_AnOKWasSentToPlayer[] = _("OK联络已发送给\n{STR_VAR_1}！");
ALIGNED(4) static const u8 sText_OtherTrainerUnavailableNow[] = _("对方训练家现在好像不方便……\p");
ALIGNED(4) static const u8 sText_CantTransmitTrainerTooFar[] = _(" 无法与距离太远的训练家进行连接。\p");
ALIGNED(4) static const u8 sText_TrainersNotReadyYet[] = _("对方训练家尚未准备好。\p");

static const u8 *const sCantTransmitToTrainerTexts[] = {
    [UR_TRADE_PLAYER_NOT_READY - 1]  = sText_CantTransmitTrainerTooFar,
    [UR_TRADE_PARTNER_NOT_READY - 1] = sText_TrainersNotReadyYet
};

ALIGNED(4) static const u8 sText_ModeWithTheseMembersWillBeCanceled[] = _("与当前成员的\n{STR_VAR_1}模式即将中\l止。{PAUSE 60}");
ALIGNED(4) static const u8 sText_MemberNoLongerAvailable[] = _("对方好像不方便……\p");

static const u8 *const sPlayerUnavailableTexts[] = {
    sText_OtherTrainerUnavailableNow,
    sText_MemberNoLongerAvailable
};

ALIGNED(4) static const u8 sText_TrainerAppearsUnavailable[] = _("有成员不便进行……\p");
ALIGNED(4) static const u8 sText_PlayerSentBackOK[] = _("收到了来自{STR_VAR_1}\n的OK回复！");
ALIGNED(4) static const u8 sText_PlayerOKdRegistration[] = _("收到了来自{STR_VAR_1}\n的OK联络，同意加您为成员！");
ALIGNED(4) static const u8 sText_PlayerRepliedNo[] = _("收到了来自{STR_VAR_1}\n的NO回复……\p");
ALIGNED(4) static const u8 sText_AwaitingOtherMembers[] = _("{STR_VAR_1}！正在等待\n其他成员！");
ALIGNED(4) static const u8 sText_QuitBeingMember[] = _("要退出成员吗？");
ALIGNED(4) static const u8 sText_StoppedBeingMember[] = _("您已退出成员。\p");

static const u8 *const sPlayerDisconnectedTexts[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = sText_MemberNoLongerAvailable,
    [RFU_STATUS_CONNECTION_ERROR]    = sText_TrainerAppearsUnavailable,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = sText_StoppedBeingMember
};

ALIGNED(4) static const u8 sText_WirelessLinkEstablished[] = _("无线连接系统已连接。");
ALIGNED(4) static const u8 sText_WirelessLinkDropped[] = _("无线连接系统断开了……");
ALIGNED(4) static const u8 sText_LinkWithFriendDropped[] = _("与好友的连接断开了……");
ALIGNED(4) static const u8 sText_PlayerRepliedNo2[] = _("收到了来自{STR_VAR_1}\n的NO回复……");

static const u8 *const sLinkDroppedTexts[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = sText_LinkWithFriendDropped,
    [RFU_STATUS_CONNECTION_ERROR]    = sText_LinkWithFriendDropped,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo2,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = NULL
};

ALIGNED(4) static const u8 sText_DoYouWantXMode[] = _("您想要参加{STR_VAR_2}\n模式吗？");
ALIGNED(4) static const u8 sText_DoYouWantXMode2[] = _("您想要参加{STR_VAR_2}\n模式吗？");

// Unused
static const u8 *const sDoYouWantModeTexts[] = {
    sText_DoYouWantXMode,
    sText_DoYouWantXMode2
};

ALIGNED(4) static const u8 sText_CommunicatingPleaseWait[] = _("正在连接……请稍等片刻。"); // Unused
ALIGNED(4) static const u8 sText_AwaitingPlayersResponseAboutTrade[] = _("正在等待{STR_VAR_1}的\n交换回复……");
ALIGNED(4) static const u8 sText_Communicating[] = _("正在连接{PAUSE 15}.\n{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l"
                                                     "{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.");
ALIGNED(4) static const u8 sText_CommunicatingWithPlayer[] = _("正在与{STR_VAR_1}连接\n……{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l"
                                                               "{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.");
ALIGNED(4) static const u8 sText_PleaseWaitAWhile[] = _("请稍等……{PAUSE 15}.\n{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l"
                                                        "{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.\l{PAUSE 15}.");

static const u8 *const sCommunicatingWaitTexts[] = {
    sText_Communicating,
    sText_CommunicatingWithPlayer,
    sText_PleaseWaitAWhile
};

ALIGNED(4) static const u8 sText_HiDoSomethingMale[] = _("嘿！有什么想做的事吗？");
ALIGNED(4) static const u8 sText_HiDoSomethingFemale[] = _("你好！要做点什么呢？");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainMale[] = _("{STR_VAR_1}：嘿，我们\n又见面了！这次打算做什么？");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainFemale[] = _("{STR_VAR_1}：哦！\n{PLAYER}，你好！要做点什\l么呢？");

static const u8 *const sHiDoSomethingTexts[][GENDER_COUNT] = {
    {
        sText_HiDoSomethingMale,
        sText_HiDoSomethingFemale
    }, {
        sText_HiDoSomethingAgainMale,
        sText_HiDoSomethingAgainFemale
    }
};

ALIGNED(4) static const u8 sText_DoSomethingMale[] = _("想做点什么？");
ALIGNED(4) static const u8 sText_DoSomethingFemale[] = _("想做点什么？");
ALIGNED(4) static const u8 sText_DoSomethingAgainMale[] = _("{STR_VAR_1}：现在要做\n些什么呢？");
ALIGNED(4) static const u8 sText_DoSomethingAgainFemale[] = _("{STR_VAR_1}：想做点其\n他的不？"); // Unused

// Unused
static const u8 *const sDoSomethingTexts[][GENDER_COUNT] = {
    {
        sText_DoSomethingMale,
        sText_DoSomethingFemale
    }, {
        sText_DoSomethingAgainMale,
        sText_DoSomethingAgainMale // was probably supposed to be sText_DoSomethingAgainFemale
    }
};

ALIGNED(4) static const u8 sText_SomebodyHasContactedYou[] = _("收到了来自某人的联络！\n{PAUSE 60}");
ALIGNED(4) static const u8 sText_PlayerHasContactedYou[] = _("收到了来自{STR_VAR_1}\n的联络！{PAUSE 60}");

static const u8 *const sPlayerContactedYouTexts[] = {
    sText_SomebodyHasContactedYou,
    sText_PlayerHasContactedYou
};

ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer[] = _("等待对方训练家的回复……");
ALIGNED(4) static const u8 sText_AwaitingResponseFromPlayer[] = _("等待{STR_VAR_1}的回复\n……");

static const u8 *const sAwaitingResponseTexts[] = {
    sText_AwaitingResponseFromTrainer,
    sText_AwaitingResponseFromPlayer
};

ALIGNED(4) static const u8 sText_ShowTrainerCard[] = _("对方训练家亮出了训练家卡。\p要向对方亮出自己的训练家卡吗？");
ALIGNED(4) static const u8 sText_BattleChallenge[] = _("对方训练家想要和您对战。\p要同意对战吗？");
ALIGNED(4) static const u8 sText_ChatInvitation[] = _("对方训练家邀请您聊天。\p要接受聊天邀请吗？");
ALIGNED(4) static const u8 sText_OfferToTradeMon[] = _("有人愿意用一只等级\n{DYNAMIC 0}的\l{DYNAMIC 1}\p与您登记的等级\n{DYNAMIC 2}的\l{DYNAMIC 3}交换。\p要同意交换吗？");
ALIGNED(4) static const u8 sText_OfferToTradeEgg[] = _("有人想要交换您登记的蛋。要同意交\n换吗？");
ALIGNED(4) static const u8 sText_ChatDropped[] = _("聊天断开了。\p");
ALIGNED(4) static const u8 sText_OfferDeclined1[] = _("拒绝了对方的邀请。\p");
ALIGNED(4) static const u8 sText_OfferDeclined2[] = _(" 拒绝了对方的邀请。\p");
ALIGNED(4) static const u8 sText_ChatEnded[] = _("聊天中止了。\p");

// Unused
static const u8 *const sInvitationTexts[] = {
    sText_ShowTrainerCard,
    sText_BattleChallenge,
    sText_ChatInvitation,
    sText_OfferToTradeMon
};

ALIGNED(4) static const u8 sText_JoinChatMale[] = _("嘿！我们正在聊天。要加入我们吗？");
ALIGNED(4) static const u8 sText_PlayerJoinChatMale[] = _("{STR_VAR_1}：嘿，\n{PLAYER}！我们正在聊天。\l要加入我们吗？");
ALIGNED(4) static const u8 sText_JoinChatFemale[] = _(" 哦，你好！我们正在聊天。要加入\n我们吗？");
ALIGNED(4) static const u8 sText_PlayerJoinChatFemale[] = _("{STR_VAR_1}：你好，\n{PLAYER}！我们在聊天。要\l加入我们吗？");

static const u8 *const sJoinChatTexts[][GENDER_COUNT] = {
    {
        sText_JoinChatMale,
        sText_JoinChatFemale
    }, {
        sText_PlayerJoinChatMale,
        sText_PlayerJoinChatFemale
    }
};

ALIGNED(4) static const u8 sText_TrainerAppearsBusy[] = _("……现在好像正在忙……\p");
ALIGNED(4) static const u8 sText_WaitForBattleMale[] = _("你想对战啊！没问题，稍等一下啊！");
ALIGNED(4) static const u8 sText_WaitForChatMale[] = _("你想聊天吗？好的，稍等一下啊！");
ALIGNED(4) static const u8 sText_ShowTrainerCardMale[] = _("作为见面问候，就给你看一下我的训\n练家卡吧。");
ALIGNED(4) static const u8 sText_WaitForBattleFemale[] = _("你想对战啊！没问题，请稍等一下！");
ALIGNED(4) static const u8 sText_WaitForChatFemale[] = _("你想聊天吗？好的，请稍等一下！");
ALIGNED(4) static const u8 sText_ShowTrainerCardFemale[] = _("那作为见面问候，就给你看一下我的\n训练家卡吧。");

static const u8 *const sText_WaitOrShowCardTexts[GENDER_COUNT][4] = {
    {
        sText_WaitForBattleMale,
        sText_WaitForChatMale,
        NULL,
        sText_ShowTrainerCardMale
    }, {
        sText_WaitForBattleFemale,
        sText_WaitForChatFemale,
        NULL,
        sText_ShowTrainerCardFemale
    }
};

ALIGNED(4) static const u8 sText_WaitForChatMale2[] = _("想聊天，嗯？好，等下。"); // Unused
ALIGNED(4) static const u8 sText_DoneWaitingBattleMale[] = _("让你久等了！我们开始对战吧！\n{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatMale[] = _("让你久等了！我们开始聊天吧！\n{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingBattleFemale[] = _("让你久等了！我们开始对战吧！\n{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatFemale[] = _("让你久等了！我们开始聊天吧！\n{PAUSE 60}");
ALIGNED(4) static const u8 sText_TradeWillBeStarted[] = _("即将开始交换。\n{PAUSE 60}");
ALIGNED(4) static const u8 sText_BattleWillBeStarted[] = _("即将开始对战。\n{PAUSE 60}");
ALIGNED(4) static const u8 sText_EnteringChat[] = _("正在进入聊天……\n{PAUSE 60}");

static const u8 *const sStartActivityTexts[][GENDER_COUNT][3] = {
    {
        {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }, {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }
    }, {
        {
            sText_DoneWaitingBattleMale,
            sText_DoneWaitingChatMale,
            sText_TradeWillBeStarted
        }, {
            sText_DoneWaitingBattleFemale,
            sText_DoneWaitingChatFemale,
            sText_TradeWillBeStarted
        }
    }
};

ALIGNED(4) static const u8 sText_BattleDeclinedMale[] = _("对不起！我的宝可梦好像有点不在状\n态。我们下次再对战吧。\p");
ALIGNED(4) static const u8 sText_BattleDeclinedFemale[] = _("实在抱歉，我的宝可梦现在状态不太\n好......\p我们下次再对战吧。\p");

static const u8 *const sBattleDeclinedTexts[GENDER_COUNT] = {
    sText_BattleDeclinedMale,
    sText_BattleDeclinedFemale
};

ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedMale[] = _("哎？我的训练家卡......跑哪\n儿去了？抱歉！下次再给你看吧！\p");
ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedFemale[] = _("哎呀？我把训练家卡放到哪里去了？\n......抱歉！等会儿再给你看\l吧！\p");

static const u8 *const sShowTrainerCardDeclinedTexts[GENDER_COUNT] = {
    sText_ShowTrainerCardDeclinedMale,
    sText_ShowTrainerCardDeclinedFemale
};

ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingMale[] = _("如果还想到什么事，就尽管找我。\p");
ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingFemale[] = _("如果还有什么事的话，就再来找我吧！\p");

static const u8 *const sIfYouWantToDoSomethingTexts[GENDER_COUNT] = {
    sText_IfYouWantToDoSomethingMale,
    sText_IfYouWantToDoSomethingFemale
};

ALIGNED(4) static const u8 sText_TrainerBattleBusy[] = _("对不起！我现在有点不太方便。我们\n下次再说吧！\p");
ALIGNED(4) static const u8 sText_NeedTwoMonsOfLevel30OrLower1[] = _("要对战的话，2只宝可梦都需要在等\n级30以内。\p");
ALIGNED(4) static const u8 sText_NeedTwoMonsOfLevel30OrLower2[] = _("要对战的话，宝可梦需要在等级30\n以内。\p");

ALIGNED(4) static const u8 sText_DeclineChatMale[] = _("好吧，但随时欢迎你来！\p");
ALIGNED(4) static const u8 stext_DeclineChatFemale[] = _("好吧……但随时欢迎你来！\p");

// Response from partner when player declines chat
static const u8 *const sDeclineChatTexts[GENDER_COUNT] = {
    sText_DeclineChatMale,
    stext_DeclineChatFemale
};

ALIGNED(4) static const u8 sText_ChatDeclinedMale[] = _("对不起！我现在有点不太方便。我们\n下次再说吧！\p");
ALIGNED(4) static const u8 sText_ChatDeclinedFemale[] = _("对不起！我们下次再说吧！\p");

// Response from partner when they decline chat
static const u8 *const sChatDeclinedTexts[GENDER_COUNT] = {
    sText_ChatDeclinedMale,
    sText_ChatDeclinedFemale
};

ALIGNED(4) static const u8 sText_YoureToughMale[] = _("哦！水平不错嘛！\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveMale[] = _("居然使出了这招？看来你很懂嘛！\p");
ALIGNED(4) static const u8 sText_BattleSurpriseMale[] = _("真厉害！原来还有这种战法啊！\p");
ALIGNED(4) static const u8 sText_SwitchedMonsMale[] = _("真没想到你会在这种情况下派出这只\n宝可梦！\p");
ALIGNED(4) static const u8 sText_YoureToughFemale[] = _("这只宝可梦被你培育得实在是太好了！\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveFemale[] = _("这就对了！这里就该出这招嘛！！\p");
ALIGNED(4) static const u8 sText_BattleSurpriseFemale[] = _("好厉害！原来还有这种战法啊！\p");
ALIGNED(4) static const u8 sText_SwitchedMonsFemale[] = _("替换宝可梦的时机可谓绝妙啊！\p");

static const u8 *const sBattleReactionTexts[GENDER_COUNT][4] = {
    {
        sText_YoureToughMale,
        sText_UsedGoodMoveMale,
        sText_BattleSurpriseMale,
        sText_SwitchedMonsMale
    },
    {
        sText_YoureToughFemale,
        sText_UsedGoodMoveFemale,
        sText_BattleSurpriseFemale,
        sText_SwitchedMonsFemale
    }
};

ALIGNED(4) static const u8 sText_LearnedSomethingMale[] = _("哦，我明白了！真是受益匪浅！\p");
ALIGNED(4) static const u8 sText_ThatsFunnyMale[] = _("别说搞笑的事了！笑得我肚子都疼了！\p");
ALIGNED(4) static const u8 sText_RandomChatMale1[] = _("哦？还有这种事啊。\p");
ALIGNED(4) static const u8 sText_RandomChatMale2[] = _("嗯……什么？原来是这样啊。\p");
ALIGNED(4) static const u8 sText_LearnedSomethingFemale[] = _("是这样吗？我以前都不知道。\p");
ALIGNED(4) static const u8 sText_ThatsFunnyFemale[] = _("啊哈哈！是那样吗？\p");
ALIGNED(4) static const u8 sText_RandomChatFemale1[] = _("对，就是这个意思！我就是想说这个。\p");
ALIGNED(4) static const u8 sText_RandomChatFemale2[] = _("也就是说……对！就是这样！\p");

static const u8 *const sChatReactionTexts[GENDER_COUNT][4] = {
    {
        sText_LearnedSomethingMale,
        sText_ThatsFunnyMale,
        sText_RandomChatMale1,
        sText_RandomChatMale2
    },
    {
        sText_LearnedSomethingFemale,
        sText_ThatsFunnyFemale,
        sText_RandomChatFemale1,
        sText_RandomChatFemale2
    }
};

ALIGNED(4) static const u8 sText_ShowedTrainerCardMale1[] = _("我正在给对方看训练家卡以示问候。\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardMale2[] = _("今后也请多指教！\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale1[] = _("我正在给对方看训练家卡以示问候呢。\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale2[] = _("今后也请多指教！\p");

static const u8 *const sTrainerCardReactionTexts[GENDER_COUNT][2] = {
    {
        sText_ShowedTrainerCardMale1,
        sText_ShowedTrainerCardMale2
    },
    {
        sText_ShowedTrainerCardFemale1,
        sText_ShowedTrainerCardFemale2
    }
};

ALIGNED(4) static const u8 sText_MaleTraded1[] = _("太棒了！我正想要这只宝可梦！\p");
ALIGNED(4) static const u8 sText_MaleTraded2[] = _("这只宝可梦我找了好久了，终于换到\n了。\p");
ALIGNED(4) static const u8 sText_FemaleTraded1[] = _("我现在正在交换宝可梦呢！\p");
ALIGNED(4) static const u8 sText_FemaleTraded2[] = _("终于换到我想要的宝可梦了！\p");

static const u8 *const sTradeReactionTexts[GENDER_COUNT][4] = {
    {
        sText_MaleTraded1,
        sText_MaleTraded2
    },
    {
        sText_FemaleTraded1,
        sText_FemaleTraded2
    }
};

ALIGNED(4) static const u8 sText_XCheckedTradingBoard[] = _("{STR_VAR_1}确认了交换\n公告板。\p");
ALIGNED(4) static const u8 sText_RegisterMonAtTradingBoard[] = _("欢迎来到交换公告板。\p您可以登记宝可梦来进行交换。\p要登记一只宝可梦吗？");
ALIGNED(4) static const u8 sText_TradingBoardInfo[] = _("这个交换公告板是用于发布宝可梦进\n"
                                                        "行交换的。\p"
                                                        "您只需在这里登记一只想要交换的宝\n"
                                                        "可梦。\p"
                                                        "其他训练家可能会提供同行队伍里的\n"
                                                        "宝可梦来交换。\p"
                                                        "希望您能在这里登记宝可梦，并与许\n"
                                                        "许多多其他训练家进行交换！\p"
                                                        "要登记一只您的宝可梦吗？");
ALIGNED(4) static const u8 sText_ThankYouForRegistering[] = _("我们已经登记了您的宝可梦放在交换\n公告板用来交换。\p感谢使用这项服务！\p"); // unused
ALIGNED(4) static const u8 sText_NobodyHasRegistered[] = _("没人登记宝可梦在交换公告板用来交\n换。\p"); // unused
ALIGNED(4) static const u8 sText_ChooseRequestedMonType[] = _("请选择你想用于交换的宝可梦类型。");
ALIGNED(4) static const u8 sText_WhichMonWillYouOffer[] = _("您想用队伍中的哪只宝可梦作为交换？\p");
ALIGNED(4) static const u8 sText_RegistrationCanceled[] = _("登记已取消。\p");
ALIGNED(4) static const u8 sText_RegistrationCompleted[] = _("登记完成。\p");
ALIGNED(4) static const u8 sText_TradeCanceled[] = _("交换已取消。\p");
ALIGNED(4) static const u8 sText_CancelRegistrationOfMon[] = _("要取消您登记的等级\n{STR_VAR_2}的\l{STR_VAR_1}吗？");
ALIGNED(4) static const u8 sText_CancelRegistrationOfEgg[] = _("要取消您登记的蛋吗？");
ALIGNED(4) static const u8 sText_RegistrationCanceled2[] = _("登记已取消。\p");
ALIGNED(4) static const u8 sText_TradeTrainersWillBeListed[] = _("训练家想要进行的交换会用表格列出\n来。"); // unused
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith2[] = _("请选择训练家用来交换宝可梦。"); // unused
ALIGNED(4) static const u8 sText_AskTrainerToMakeTrade[] = _("要和{STR_VAR_1}进行交\n换吗？");
ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer2[] = _("等待训练家的回复……"); // unused
ALIGNED(4) static const u8 sText_NotRegisteredAMonForTrade[] = _("还没有登记宝可梦用于交换。\p"); // unused
ALIGNED(4) static const u8 sText_DontHaveTypeTrainerWants[] = _("您没有{STR_VAR_1}想要\n的{STR_VAR_2}类型的宝\l可梦。\p");
ALIGNED(4) static const u8 sText_DontHaveEggTrainerWants[] = _("您没有{STR_VAR_1}想要\n的蛋。\p");
ALIGNED(4) static const u8 sText_PlayerCantTradeForYourMon[] = _("{STR_VAR_1}目前无法交\n换您的宝可梦。\p");
ALIGNED(4) static const u8 sText_CantTradeForPartnersMon[] = _("您目前无法交换\n{STR_VAR_1}的宝可梦。\p");

// Unused
static const u8 *const sCantTradeMonTexts[] = {
    sText_PlayerCantTradeForYourMon,
    sText_CantTradeForPartnersMon
};

ALIGNED(4) static const u8 sText_TradeOfferRejected[] = _("您的交换请求被拒绝了。\p");
ALIGNED(4) static const u8 sText_EggTrade[] = _("蛋交换");
ALIGNED(4) static const u8 sText_ChooseJoinCancel[] = _("{DPAD_UPDOWN}选择\n{A_BUTTON}加入\l{B_BUTTON}取消");
ALIGNED(4) static const u8 sText_ChooseTrainer[] = _("请选择1位训练家。");
ALIGNED(4) static const u8 sText_ChooseTrainerSingleBattle[] = _("请选择1位训练家进行单打对战。");
ALIGNED(4) static const u8 sText_ChooseTrainerDoubleBattle[] = _("请选择1位训练家进行双打对战。");
ALIGNED(4) static const u8 sText_ChooseLeaderMultiBattle[] = _("请选择组长进行多人对战。");
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith[] = _("请选择训练家进行交换。");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderCards[] = _("请选择训练家共享神秘卡片。");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderNews[] = _("请选择训练家共享神秘新闻。");
ALIGNED(4) static const u8 sText_ChooseLeaderPokemonJump[] = _("和宝可梦一起跳！请选择组长。");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryCrush[] = _("混合粉碎！请选择组长。");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryPicking[] = _("嘟嘟利摘树果！请选择组长。");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryBlender[] = _("树果混合器！请选择组长。");
ALIGNED(4) static const u8 sText_ChooseLeaderRecordCorner[] = _("记录角！请选择组长。");
ALIGNED(4) static const u8 sText_ChooseLeaderCoolContest[] = _("帅气华丽大赛！请选择组长。");
ALIGNED(4) static const u8 sText_ChooseLeaderBeautyContest[] = _("美丽华丽大赛！请选择组长。");
ALIGNED(4) static const u8 sText_ChooseLeaderCuteContest[] = _("可爱华丽大赛！请选择组长。");
ALIGNED(4) static const u8 sText_ChooseLeaderSmartContest[] = _("聪明华丽大赛！请选择组长。");
ALIGNED(4) static const u8 sText_ChooseLeaderToughContest[] = _("强壮华丽大赛！请选择组长。");
ALIGNED(4) static const u8 sText_ChooseLeaderBattleTowerLv50[] = _("对战塔Lv. 50级！请选择组长。");
ALIGNED(4) static const u8 sText_ChooseLeaderBattleTowerOpenLv[] = _("对战塔自由等级！请选择组长。");

static const u8 *const sChooseTrainerTexts[NUM_LINK_GROUP_TYPES] =
{
    [LINK_GROUP_SINGLE_BATTLE]     = sText_ChooseTrainerSingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE]     = sText_ChooseTrainerDoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]      = sText_ChooseLeaderMultiBattle,
    [LINK_GROUP_TRADE]             = sText_ChooseTrainerToTradeWith,
    [LINK_GROUP_POKEMON_JUMP]      = sText_ChooseLeaderPokemonJump,
    [LINK_GROUP_BERRY_CRUSH]       = sText_ChooseLeaderBerryCrush,
    [LINK_GROUP_BERRY_PICKING]     = sText_ChooseLeaderBerryPicking,
    [LINK_GROUP_WONDER_CARD]       = sText_ChooseTrainerToShareWonderCards,
    [LINK_GROUP_WONDER_NEWS]       = sText_ChooseTrainerToShareWonderNews,
    [LINK_GROUP_UNION_ROOM_RESUME] = NULL,
    [LINK_GROUP_UNION_ROOM_INIT]   = NULL,
    [LINK_GROUP_UNK_11]            = NULL,
    [LINK_GROUP_RECORD_CORNER]     = sText_ChooseLeaderRecordCorner,
    [LINK_GROUP_BERRY_BLENDER]     = sText_ChooseLeaderBerryBlender,
    [LINK_GROUP_UNK_14]            = NULL,
    [LINK_GROUP_COOL_CONTEST]      = sText_ChooseLeaderCoolContest,
    [LINK_GROUP_BEAUTY_CONTEST]    = sText_ChooseLeaderBeautyContest,
    [LINK_GROUP_CUTE_CONTEST]      = sText_ChooseLeaderCuteContest,
    [LINK_GROUP_SMART_CONTEST]     = sText_ChooseLeaderSmartContest,
    [LINK_GROUP_TOUGH_CONTEST]     = sText_ChooseLeaderToughContest,
    [LINK_GROUP_BATTLE_TOWER]      = sText_ChooseLeaderBattleTowerLv50,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = sText_ChooseLeaderBattleTowerOpenLv
};

ALIGNED(4) static const u8 sText_SearchingForWirelessSystemWait[] = _("正在搜索无线连接系统。请稍等……");
ALIGNED(4) static const u8 sText_MustHaveTwoMonsForDoubleBattle[] = _("要进行双打对战的话，需要至少有2\n只宝可梦。\p"); // Unused
ALIGNED(4) static const u8 sText_AwaitingPlayersResponse[] = _("正在等待{STR_VAR_1}的\n回复……");
ALIGNED(4) static const u8 sText_PlayerHasBeenAskedToRegisterYouPleaseWait[] = _("正在请{STR_VAR_1}添加\n您为成员，请稍等！");
ALIGNED(4) static const u8 sText_AwaitingResponseFromWirelessSystem[] = _("正在等待无线连接系统的响应。");
ALIGNED(4) static const u8 sText_PleaseWaitForOtherTrainersToGather[] = _("请等待对方训练家加入并准备完毕。"); // Unused
ALIGNED(4) static const u8 sText_NoCardsSharedRightNow[] = _("目前好像没有共享中的卡片。");
ALIGNED(4) static const u8 sText_NoNewsSharedRightNow[] = _("目前好像没有共享中的新闻。");

static const u8 *const sNoWonderSharedTexts[] = {
    sText_NoCardsSharedRightNow,
    sText_NoNewsSharedRightNow
};

ALIGNED(4) static const u8 sText_Battle[] = _("对战");
ALIGNED(4) static const u8 sText_Chat2[] = _("聊天");
ALIGNED(4) static const u8 sText_Greetings[] = _("问候");
ALIGNED(4) static const u8 sText_Exit[] = _("退出");
ALIGNED(4) static const u8 sText_Exit2[] = _("退出");
ALIGNED(4) static const u8 sText_Info[] = _("听说明");
ALIGNED(4) static const u8 sText_NameWantedOfferLv[] = _("名字{CLEAR_TO 60}想\n要{CLEAR_TO 110}给\l出{CLEAR_TO 198}等\l级");
ALIGNED(4) static const u8 sText_SingleBattle[] = _("单打对战");
ALIGNED(4) static const u8 sText_DoubleBattle[] = _("双打对战");
ALIGNED(4) static const u8 sText_MultiBattle[] = _("多人对战");
ALIGNED(4) static const u8 sText_PokemonTrades[] = _("宝可梦交换");
ALIGNED(4) static const u8 sText_Chat[] = _("聊天");
ALIGNED(4) static const u8 sText_Cards[] = _("卡片");
ALIGNED(4) static const u8 sText_WonderCards[] = _("神秘卡片");
ALIGNED(4) static const u8 sText_WonderNews[] = _("神秘新闻");
ALIGNED(4) static const u8 sText_PokemonJump[] = _("宝可梦跳跃");
ALIGNED(4) static const u8 sText_BerryCrush[] = _("树果粉碎");
ALIGNED(4) static const u8 sText_BerryPicking[] = _("摘树果");
ALIGNED(4) static const u8 sText_Search[] = _("搜索");
ALIGNED(4) static const u8 sText_BerryBlender[] = _("树果混合器");
ALIGNED(4) static const u8 sText_RecordCorner[] = _("记录角");
ALIGNED(4) static const u8 sText_CoolContest[] = _("帅气华丽大赛");
ALIGNED(4) static const u8 sText_BeautyContest[] = _("美丽华丽大赛");
ALIGNED(4) static const u8 sText_CuteContest[] = _("可爱华丽大赛");
ALIGNED(4) static const u8 sText_SmartContest[] = _("聪明华丽大赛");
ALIGNED(4) static const u8 sText_ToughContest[] = _("强壮华丽大赛");
ALIGNED(4) static const u8 sText_BattleTowerLv50[] = _("对战塔Lv. 50级");
ALIGNED(4) static const u8 sText_BattleTowerOpenLv[] = _("对战塔自由等级");
ALIGNED(4) static const u8 sText_ItsNormalCard[] = _("是普通卡。");
ALIGNED(4) static const u8 sText_ItsBronzeCard[] = _("是青铜卡！");
ALIGNED(4) static const u8 sText_ItsCopperCard[] = _("是紫铜卡！");
ALIGNED(4) static const u8 sText_ItsSilverCard[] = _("是白银卡！");
ALIGNED(4) static const u8 sText_ItsGoldCard[] = _("是黄金卡！");

static const u8 *const sCardColorTexts[] = {
    sText_ItsNormalCard,
    sText_ItsBronzeCard,
    sText_ItsCopperCard,
    sText_ItsSilverCard,
    sText_ItsGoldCard
};

ALIGNED(4) static const u8 sText_TrainerCardInfoPage1[] = _("这是{DYNAMIC 0} \n{DYNAMIC 1}的训练家卡\l……{DYNAMIC 2}\p图鉴：{DYNAMIC 3}时间：{DYNAMIC 4}：\l{DYNAMIC 5}\p");
ALIGNED(4) static const u8 sText_TrainerCardInfoPage2[] = _(" 对战：胜：\n{DYNAMIC 0} 负：\l{DYNAMIC 2}交换次数：\l{DYNAMIC 3}\p“{DYNAMIC 4} {DYNAMIC 5}\n{DYNAMIC 6} {DYNAMIC 7}”\p");
ALIGNED(4) static const u8 sText_GladToMeetYouMale[] = _("{DYNAMIC 1}：很高兴认\n识你！{PAUSE 60}");
ALIGNED(4) static const u8 sText_GladToMeetYouFemale[] = _("{DYNAMIC 1}：很高兴认\n识你！{PAUSE 60}");

static const u8 *const sGladToMeetYouTexts[GENDER_COUNT] = {
    sText_GladToMeetYouMale,
    sText_GladToMeetYouFemale
};

ALIGNED(4) static const u8 sText_FinishedCheckingPlayersTrainerCard[] = _("{DYNAMIC 1}的训练家卡\n确认完毕。{PAUSE 60}");

static const u8 *const sLinkGroupActivityNameTexts[] = {
    [ACTIVITY_NONE]              = sText_EmptyString,
    [ACTIVITY_BATTLE_SINGLE]     = sText_SingleBattle,
    [ACTIVITY_BATTLE_DOUBLE]     = sText_DoubleBattle,
    [ACTIVITY_BATTLE_MULTI]      = sText_MultiBattle,
    [ACTIVITY_TRADE]             = sText_PokemonTrades,
    [ACTIVITY_CHAT]              = sText_Chat,
    [ACTIVITY_WONDER_CARD_DUP]   = sText_WonderCards,
    [ACTIVITY_WONDER_NEWS_DUP]   = sText_WonderNews,
    [ACTIVITY_CARD]              = sText_Cards,
    [ACTIVITY_POKEMON_JUMP]      = sText_PokemonJump,
    [ACTIVITY_BERRY_CRUSH]       = sText_BerryCrush,
    [ACTIVITY_BERRY_PICK]        = sText_BerryPicking,
    [ACTIVITY_SEARCH]            = sText_Search,
    [ACTIVITY_SPIN_TRADE]        = sText_EmptyString,
    [ACTIVITY_BATTLE_TOWER_OPEN] = sText_BattleTowerOpenLv,
    [ACTIVITY_RECORD_CORNER]     = sText_RecordCorner,
    [ACTIVITY_BERRY_BLENDER]     = sText_BerryBlender,
    [ACTIVITY_ACCEPT]            = sText_EmptyString,
    [ACTIVITY_DECLINE]           = sText_EmptyString,
    [ACTIVITY_NPCTALK]           = sText_EmptyString,
    [ACTIVITY_PLYRTALK]          = sText_EmptyString,
    [ACTIVITY_WONDER_CARD]       = sText_WonderCards,
    [ACTIVITY_WONDER_NEWS]       = sText_WonderNews,
    [ACTIVITY_CONTEST_COOL]      = sText_CoolContest,
    [ACTIVITY_CONTEST_BEAUTY]    = sText_BeautyContest,
    [ACTIVITY_CONTEST_CUTE]      = sText_CuteContest,
    [ACTIVITY_CONTEST_SMART]     = sText_SmartContest,
    [ACTIVITY_CONTEST_TOUGH]     = sText_ToughContest,
    [ACTIVITY_BATTLE_TOWER]      = sText_BattleTowerLv50
};

static const struct WindowTemplate sWindowTemplate_BButtonCancel = {
    .bg = 0,
    .tilemapLeft = 0,
    .tilemapTop = 0,
    .width = 30,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x0008
};

// Minimum and maximum number of players for a link group
// A minimum of 0 means the min and max are equal
#define LINK_GROUP_CAPACITY(min, max) (((min) << 12) | ((max) << 8))
#define GROUP_MAX(capacity) (capacity & 0x0F)
#define GROUP_MIN(capacity) (capacity >> 4)
#define GROUP_MIN2(capacity) (capacity & 0xF0) // Unnecessary to have both, but needed to match

static const u32 sLinkGroupToActivityAndCapacity[NUM_LINK_GROUP_TYPES] = {
    [LINK_GROUP_SINGLE_BATTLE]     = ACTIVITY_BATTLE_SINGLE     | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_DOUBLE_BATTLE]     = ACTIVITY_BATTLE_DOUBLE     | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_MULTI_BATTLE]      = ACTIVITY_BATTLE_MULTI      | LINK_GROUP_CAPACITY(0, 4),
    [LINK_GROUP_TRADE]             = ACTIVITY_TRADE             | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_POKEMON_JUMP]      = ACTIVITY_POKEMON_JUMP      | LINK_GROUP_CAPACITY(2, 5),
    [LINK_GROUP_BERRY_CRUSH]       = ACTIVITY_BERRY_CRUSH       | LINK_GROUP_CAPACITY(2, 5),
    [LINK_GROUP_BERRY_PICKING]     = ACTIVITY_BERRY_PICK        | LINK_GROUP_CAPACITY(3, 5),
    [LINK_GROUP_WONDER_CARD]       = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_WONDER_NEWS]       = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNION_ROOM_RESUME] = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNION_ROOM_INIT]   = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNK_11]            = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_RECORD_CORNER]     = ACTIVITY_RECORD_CORNER     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BERRY_BLENDER]     = ACTIVITY_BERRY_BLENDER     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_UNK_14]            = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_COOL_CONTEST]      = ACTIVITY_CONTEST_COOL      | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BEAUTY_CONTEST]    = ACTIVITY_CONTEST_BEAUTY    | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_CUTE_CONTEST]      = ACTIVITY_CONTEST_CUTE      | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_SMART_CONTEST]     = ACTIVITY_CONTEST_SMART     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_TOUGH_CONTEST]     = ACTIVITY_CONTEST_TOUGH     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BATTLE_TOWER]      = ACTIVITY_BATTLE_TOWER      | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_BATTLE_TOWER_OPEN] = ACTIVITY_BATTLE_TOWER_OPEN | LINK_GROUP_CAPACITY(0, 2)
};

static const struct WindowTemplate sWindowTemplate_PlayerList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 13,
    .height = 8,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_5PlayerList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 13,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_NumPlayerMode = {
    .bg = 0,
    .tilemapLeft = 16,
    .tilemapTop = 3,
    .width = 7,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x00c6
};

static const struct ListMenuItem sPossibleGroupMembersListMenuItems[] = {
    { sText_EmptyString, 0 },
    { sText_EmptyString, 1 },
    { sText_EmptyString, 2 },
    { sText_EmptyString, 3 },
    { sText_EmptyString, 4 }
};

static const struct ListMenuTemplate sListMenuTemplate_PossibleGroupMembers = {
    .items = sPossibleGroupMembersListMenuItems,
    .moveCursorFunc = NULL,
    .itemPrintFunc = ItemPrintFunc_PossibleGroupMembers,
    .totalItems = ARRAY_COUNT(sPossibleGroupMembersListMenuItems),
    .maxShowed = 5,
    .windowId = 0,
    .header_X = 0,
    .item_X = 0,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_INVISIBLE
};

static const struct WindowTemplate sWindowTemplate_GroupList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 17,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_PlayerNameAndId = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 3,
    .width = 7,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x00ee
};

static const struct ListMenuItem sUnionRoomGroupsMenuItems[] = {
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_EmptyString,  8 },
    { sText_EmptyString,  9 },
    { sText_EmptyString, 10 },
    { sText_EmptyString, 11 },
    { sText_EmptyString, 12 },
    { sText_EmptyString, 13 },
    { sText_EmptyString, 14 },
    { sText_EmptyString, 15 }
};

static const struct ListMenuTemplate sListMenuTemplate_UnionRoomGroups = {
    .items = sUnionRoomGroupsMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = ListMenuItemPrintFunc_UnionRoomGroups,
    .totalItems = ARRAY_COUNT(sUnionRoomGroupsMenuItems),
    .maxShowed = 5,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_MULTIPLE_SCROLL_DPAD,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_InviteToActivity = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 5,
    .width = 16,
    .height = 8,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sInviteToActivityMenuItems[] = {
    { sText_Greetings, ACTIVITY_CARD | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Battle,    ACTIVITY_BATTLE_SINGLE | IN_UNION_ROOM | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Chat2,     ACTIVITY_CHAT | IN_UNION_ROOM | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Exit,      ACTIVITY_NONE | IN_UNION_ROOM }
};

static const struct ListMenuTemplate sListMenuTemplate_InviteToActivity = {
    .items = sInviteToActivityMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sInviteToActivityMenuItems),
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_RegisterForTrade = {
    .bg = 0,
    .tilemapLeft = 18,
    .tilemapTop = 7,
    .width = 16,
    .height = 6,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sRegisterForTradeListMenuItems[] = {
    { gText_Register, 1 },
    { sText_Info, 2 },
    { sText_Exit, 3 }
};

static const struct ListMenuTemplate sListMenuTemplate_RegisterForTrade = {
    .items = sRegisterForTradeListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sRegisterForTradeListMenuItems),
    .maxShowed = 3,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_TradingBoardRequestType = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 1,
    .width = 16,
    .height = 12,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

// Subtract two from the total type count to handle in-battle types not for display
static const struct ListMenuItem sTradingBoardTypes[NUMBER_OF_MON_TYPES - 2] = {
    { gTypesInfo[TYPE_NORMAL].name,   TYPE_NORMAL         },
    { gTypesInfo[TYPE_FIRE].name,     TYPE_FIRE           },
    { gTypesInfo[TYPE_WATER].name,    TYPE_WATER          },
    { gTypesInfo[TYPE_ELECTRIC].name, TYPE_ELECTRIC       },
    { gTypesInfo[TYPE_GRASS].name,    TYPE_GRASS          },
    { gTypesInfo[TYPE_ICE].name,      TYPE_ICE            },
    { gTypesInfo[TYPE_GROUND].name,   TYPE_GROUND         },
    { gTypesInfo[TYPE_ROCK].name,     TYPE_ROCK           },
    { gTypesInfo[TYPE_FLYING].name,   TYPE_FLYING         },
    { gTypesInfo[TYPE_PSYCHIC].name,  TYPE_PSYCHIC        },
    { gTypesInfo[TYPE_FIGHTING].name, TYPE_FIGHTING       },
    { gTypesInfo[TYPE_POISON].name,   TYPE_POISON         },
    { gTypesInfo[TYPE_BUG].name,      TYPE_BUG            },
    { gTypesInfo[TYPE_GHOST].name,    TYPE_GHOST          },
    { gTypesInfo[TYPE_DRAGON].name,   TYPE_DRAGON         },
    { gTypesInfo[TYPE_STEEL].name,    TYPE_STEEL          },
    { gTypesInfo[TYPE_DARK].name,     TYPE_DARK           },
    { gTypesInfo[TYPE_FAIRY].name,    TYPE_FAIRY          },
    { sText_Exit,                NUMBER_OF_MON_TYPES }
};

static const struct ListMenuTemplate sMenuTemplate_TradingBoardRequestType = {
    .items = sTradingBoardTypes,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sTradingBoardTypes),
    .maxShowed = 6,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_TradingBoardHeader = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 28,
    .height = 2,
    .paletteNum = 13,
    .baseBlock = 0x0001
};

static const struct WindowTemplate sWindowTemplate_TradingBoardMain = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 5,
    .width = 28,
    .height = 12,
    .paletteNum = 13,
    .baseBlock = 0x0039
};

static const struct ListMenuItem sTradeBoardListMenuItems[] = {
    { sText_EmptyString, LIST_HEADER },
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_Exit2,  8 }
};

static const struct ListMenuTemplate sTradeBoardListMenuTemplate = {
    .items = sTradeBoardListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = TradeBoardListMenuItemPrintFunc,
    .totalItems = ARRAY_COUNT(sTradeBoardListMenuItems),
    .maxShowed = 6,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 14,
    .fillValue = 15,
    .cursorShadowPal = 13,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

// Unused
static const struct WindowTemplate sWindowTemplate_Unused = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 5,
    .width = 28,
    .height = 12,
    .paletteNum = 13,
    .baseBlock = 0x0039
};

static const struct ListMenuItem sEmptyListMenuItems[] = {
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_EmptyString,  8 },
    { sText_EmptyString,  9 },
    { sText_EmptyString, 10 },
    { sText_EmptyString, 11 },
    { sText_EmptyString, 12 },
    { sText_EmptyString, 13 },
    { sText_EmptyString, 14 },
    { sText_EmptyString, 15 }
};

// Unused
static const struct ListMenuTemplate sEmptyListMenuTemplate = {
    .items = sEmptyListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = ItemPrintFunc_EmptyList,
    .totalItems = ARRAY_COUNT(sEmptyListMenuItems),
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_MULTIPLE_SCROLL_DPAD,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct RfuPlayerData sUnionRoomPlayer_DummyRfu = {0};

ALIGNED(4) static const u8 sAcceptedActivityIds_SingleBattle[]    = {ACTIVITY_BATTLE_SINGLE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_DoubleBattle[]    = {ACTIVITY_BATTLE_DOUBLE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_MultiBattle[]     = {ACTIVITY_BATTLE_MULTI, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Trade[]           = {ACTIVITY_TRADE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_PokemonJump[]     = {ACTIVITY_POKEMON_JUMP, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryCrush[]      = {ACTIVITY_BERRY_CRUSH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryPicking[]    = {ACTIVITY_BERRY_PICK, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_WonderCard[]      = {ACTIVITY_WONDER_CARD, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_WonderNews[]      = {ACTIVITY_WONDER_NEWS, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Resume[]          = {
    IN_UNION_ROOM | ACTIVITY_NONE,
    IN_UNION_ROOM | ACTIVITY_BATTLE_SINGLE,
    IN_UNION_ROOM | ACTIVITY_TRADE,
    IN_UNION_ROOM | ACTIVITY_CHAT,
    IN_UNION_ROOM | ACTIVITY_CARD,
    IN_UNION_ROOM | ACTIVITY_ACCEPT,
    IN_UNION_ROOM | ACTIVITY_DECLINE,
    IN_UNION_ROOM | ACTIVITY_NPCTALK,
    IN_UNION_ROOM | ACTIVITY_PLYRTALK,
    0xff
};
ALIGNED(4) static const u8 sAcceptedActivityIds_Init[]            = {ACTIVITY_SEARCH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Unk11[]           = {
    ACTIVITY_BATTLE_SINGLE,
    ACTIVITY_BATTLE_DOUBLE,
    ACTIVITY_BATTLE_MULTI,
    ACTIVITY_TRADE,
    ACTIVITY_POKEMON_JUMP,
    ACTIVITY_BERRY_CRUSH,
    ACTIVITY_BERRY_PICK,
    ACTIVITY_WONDER_CARD,
    ACTIVITY_WONDER_NEWS,
    ACTIVITY_SPIN_TRADE,
    0xff
};
ALIGNED(4) static const u8 sAcceptedActivityIds_RecordCorner[]    = {ACTIVITY_RECORD_CORNER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryBlender[]    = {ACTIVITY_BERRY_BLENDER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_CoolContest[]     = {ACTIVITY_CONTEST_COOL, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BeautyContest[]   = {ACTIVITY_CONTEST_BEAUTY, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_CuteContest[]     = {ACTIVITY_CONTEST_CUTE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_SmartContest[]    = {ACTIVITY_CONTEST_SMART, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_ToughContest[]    = {ACTIVITY_CONTEST_TOUGH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BattleTower[]     = {ACTIVITY_BATTLE_TOWER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BattleTowerOpen[] = {ACTIVITY_BATTLE_TOWER_OPEN, 0xff};

static const u8 *const sAcceptedActivityIds[NUM_LINK_GROUP_TYPES] = {
    [LINK_GROUP_SINGLE_BATTLE]     = sAcceptedActivityIds_SingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE]     = sAcceptedActivityIds_DoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]      = sAcceptedActivityIds_MultiBattle,
    [LINK_GROUP_TRADE]             = sAcceptedActivityIds_Trade,
    [LINK_GROUP_POKEMON_JUMP]      = sAcceptedActivityIds_PokemonJump,
    [LINK_GROUP_BERRY_CRUSH]       = sAcceptedActivityIds_BerryCrush,
    [LINK_GROUP_BERRY_PICKING]     = sAcceptedActivityIds_BerryPicking,
    [LINK_GROUP_WONDER_CARD]       = sAcceptedActivityIds_WonderCard,
    [LINK_GROUP_WONDER_NEWS]       = sAcceptedActivityIds_WonderNews,
    [LINK_GROUP_UNION_ROOM_RESUME] = sAcceptedActivityIds_Resume,
    [LINK_GROUP_UNION_ROOM_INIT]   = sAcceptedActivityIds_Init,
    [LINK_GROUP_UNK_11]            = sAcceptedActivityIds_Unk11,
    [LINK_GROUP_RECORD_CORNER]     = sAcceptedActivityIds_RecordCorner,
    [LINK_GROUP_BERRY_BLENDER]     = sAcceptedActivityIds_BerryBlender,
    [LINK_GROUP_UNK_14]            = NULL,
    [LINK_GROUP_COOL_CONTEST]      = sAcceptedActivityIds_CoolContest,
    [LINK_GROUP_BEAUTY_CONTEST]    = sAcceptedActivityIds_BeautyContest,
    [LINK_GROUP_CUTE_CONTEST]      = sAcceptedActivityIds_CuteContest,
    [LINK_GROUP_SMART_CONTEST]     = sAcceptedActivityIds_SmartContest,
    [LINK_GROUP_TOUGH_CONTEST]     = sAcceptedActivityIds_ToughContest,
    [LINK_GROUP_BATTLE_TOWER]      = sAcceptedActivityIds_BattleTower,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = sAcceptedActivityIds_BattleTowerOpen
};

static const u8 sLinkGroupToURoomActivity[NUM_LINK_GROUP_TYPES + 2] =
{
    [LINK_GROUP_SINGLE_BATTLE]     = ACTIVITY_BATTLE_SINGLE,
    [LINK_GROUP_DOUBLE_BATTLE]     = ACTIVITY_BATTLE_DOUBLE,
    [LINK_GROUP_MULTI_BATTLE]      = ACTIVITY_BATTLE_MULTI,
    [LINK_GROUP_TRADE]             = ACTIVITY_TRADE,
    [LINK_GROUP_POKEMON_JUMP]      = ACTIVITY_POKEMON_JUMP,
    [LINK_GROUP_BERRY_CRUSH]       = ACTIVITY_BERRY_CRUSH,
    [LINK_GROUP_BERRY_PICKING]     = ACTIVITY_BERRY_PICK,
    [LINK_GROUP_WONDER_CARD]       = ACTIVITY_WONDER_CARD,
    [LINK_GROUP_WONDER_NEWS]       = ACTIVITY_WONDER_NEWS,
    [LINK_GROUP_UNION_ROOM_RESUME] = ACTIVITY_NONE,
    [LINK_GROUP_UNION_ROOM_INIT]   = ACTIVITY_NONE,
    [LINK_GROUP_UNK_11]            = ACTIVITY_NONE,
    [LINK_GROUP_RECORD_CORNER]     = ACTIVITY_RECORD_CORNER,
    [LINK_GROUP_BERRY_BLENDER]     = ACTIVITY_BERRY_BLENDER,
    [LINK_GROUP_UNK_14]            = ACTIVITY_NONE,
    [LINK_GROUP_COOL_CONTEST]      = ACTIVITY_CONTEST_COOL,
    [LINK_GROUP_BEAUTY_CONTEST]    = ACTIVITY_CONTEST_BEAUTY,
    [LINK_GROUP_CUTE_CONTEST]      = ACTIVITY_CONTEST_CUTE,
    [LINK_GROUP_SMART_CONTEST]     = ACTIVITY_CONTEST_SMART,
    [LINK_GROUP_TOUGH_CONTEST]     = ACTIVITY_CONTEST_TOUGH,
    [LINK_GROUP_BATTLE_TOWER]      = ACTIVITY_BATTLE_TOWER,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = ACTIVITY_BATTLE_TOWER_OPEN
};
