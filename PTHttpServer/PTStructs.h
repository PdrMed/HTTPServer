#pragma once

#define	_SIN_MAX_USE_SKILL	16
#define	LAST_QUEST_MAX		32
#define	LAST_QUEST_MASK		31
#define	THROW_ITEM_INFO_MAX		64
#define	THROW_ITEM_INFO_MASK	63
#define	INVEN_ITEM_INFO_MAX		300
#define RECORD_ITEM_MAX		200
#define	RECORD_ITEM_INFO_HEAD_SIZE		44

struct sITEM_SPECIAL
{
    float	Add_fAbsorb;
    int     Add_Defence;
    float   Add_fSpeed;
    float   Add_fBlock_Rating;
    int     Add_Attack_Speed;
    int     Add_Critical_Hit;
    int     Add_Shooting_Range;
    float   Add_fMagic_Mastery;
    short	Add_Resistance[8];

    short	Lev_Attack_Resistance[8];
    int		Lev_Mana;
    int		Lev_Life;
    int     Lev_Attack_Rating;
    short	Lev_Damage[2];

    float	Per_Mana_Regen;
    float	Per_Life_Regen;
    float	Per_Stamina_Regen;

    DWORD	dwTemp[32];
};

struct	sITEM_CREATE
{
    DWORD	Head;
    DWORD	dwVersion;
    DWORD	dwTime;
    DWORD	dwChkSum;
};

struct	sTHROW_ITEM_INFO
{
    DWORD	dwCode;
    DWORD	dwKey;
    DWORD	dwSum;
};

struct	RECORD_SKILL
{
    BYTE	bSkillPoint[_SIN_MAX_USE_SKILL];
    WORD	wSkillMastery[_SIN_MAX_USE_SKILL];
    BYTE	bShortKey[_SIN_MAX_USE_SKILL];
    WORD	wSelectSkill[2];
};

struct	sQUEST_INFO
{
    WORD	wQuestCode[2];

    DWORD	Data[7];
};

struct	sLAST_QUEST_INFO
{
    WORD wLastQuest[LAST_QUEST_MAX];
    int	LastQuestCount;
};

struct	sGAME_SAVE_INFO
{
    DWORD	Head;

    int		PlayStageNum;
    int		CameraMode;
    int		PosX, PosZ;
    int		LastMoeny;

    DWORD	dwChkSum_CharInfo;

    RECORD_SKILL	SkillInfo;

    int		SaveTime;

    int		PCRNo;
    short	EventPlay[2];

    short	sPetInfo[2];

    short	sPotionUpdate[2];
    short	sPotionCount[3][4];
    WORD	wForceOrbUsing[2];

    DWORD	dwLevelQuestLog;

    int		ShortKey_NormalAttack;

    int		BlessCastleTax;
    DWORD	dwBlessCastleMaster;

    DWORD	dwElementaryQuestLog;

    DWORD	dwTime_PrimeItem_X2;
    DWORD	dwTime_PrimeItem_ExpUp;
    DWORD	dwTime_PrimeItem_VampCuspid;
    DWORD	dwTime_PrimeItem_ManaRecharg;
    DWORD	dwPrimeItem_PackageCode;
    DWORD	dwTime_PrimeItem_MightofAwell;
    DWORD	dwTime_PrimeItem_MightofAwell2;
    DWORD	dwTime_PrimeItem_ManaReduce;
    DWORD	dwTime_PrimeItem_PhenixPet;
    DWORD	dwTime_PrimeItem_HelpPet;
    DWORD	dwTime_PrimeItem_VampCuspid_EX;
    DWORD	dwTime_PrimeItem_StaminaReduce;

    DWORD   Unk[3];

    int		TotalSubExp;
    int		TotalMoney;
    int		TotalExp;

    char	szMasterID[32];

    sQUEST_INFO			QuestInfo;
    sLAST_QUEST_INFO	LastQuestInfo;

    DWORD	TT_ServerID;

    WORD	wLifeBoosterUsing[2];
    WORD	wManaBoosterUsing[2];
    WORD	wStaminaBoosterUsing[2];

    WORD	wSkillDelayUsing[2];

    DWORD	dwTemp2[45];
};

struct smCHAR_INFO
{
    char	szName[32];
    char	szModelName[64];
    char	szModelName2[60];
    DWORD	ModelNameCode2;

    DWORD	dwObjectSerial;

    int		ClassClan;
    int		State;
    int		SizeLevel;
    DWORD	dwCharSoundCode;

    DWORD JOB_CODE;
    int   Level;
    int   Strength;
    int   Spirit;
    int   Talent;
    int   Dexterity;
    int   Health;

    int	  Accuracy;
    int   Attack_Rating;
    int   Attack_Damage[2];
    int	  Attack_Speed;
    int	  Shooting_Range;
    int	  Critical_Hit;

    int   Defence;
    int   Chance_Block;
    int   Absorption;

    int   Move_Speed;
    int   Sight;
    short Weight[2];

    short	Resistance[8];
    short	Attack_Resistance[8];

    int     Life[2];
    int     Mana[2];
    int     Stamina[2];

    float	Life_Regen;
    float	Mana_Regen;
    float	Stamina_Regen;

    int		Exp;
    int		Next_Exp;

    int		Money;

    DWORD lpMonInfo;

    DWORD	Brood;

    int		StatePoint;
    BYTE	bUpdateInfo[4];
    short	ArrowPosi[2];
    int		Potion_Space;

    int     LifeFunction;
    int     ManaFunction;
    int     StaminaFunction;
    short   DamageFunction[2];

    DWORD	RefomCode;

    DWORD	ChangeJob;
    DWORD	JobBitMask;

    WORD	wPlayerKilling[2];
    WORD	wPlayClass[2];

    int		Exp_High;
    DWORD	dwEventTime_T;
    short	sEventParam[2];

    short	sPresentItem[2];

    short GravityScroolCheck[2];

    DWORD	dwTemp[11];

    DWORD	dwLoginServerIP;
    DWORD	dwLoginServerSafeKey;

    WORD	wVersion[2];
};

struct sITEMINFO
{
    DWORD	dwSize;

    sITEM_CREATE	ItemHeader;

    short	Durability[2];

    DWORD	CODE;
    char	ItemName[32];
    char	MixName[32];

    int     Weight;
    int     Price;

    int		Index;
    int		PotionCount;

    short	Resistance[8];

    int		Sight;

    DWORD	Temp0;

    short	Damage[2];
    int     Shooting_Range;
    int     Attack_Speed;
    int     Attack_Rating;
    int     Critical_Hit;

    float	fAbsorb;
    int     Defence;
    float   fBlock_Rating;

    float     fSpeed;

    int		Potion_Space;

    float   fMagic_Mastery;
    float   fMana_Regen;
    float   fLife_Regen;
    float   fStamina_Regen;
    float   fIncrease_Life;
    float   fIncrease_Mana;
    float   fIncrease_Stamina;

    int     Level;
    int     Strength;
    int     Spirit;
    int     Talent;
    int     Dexterity;
    int     Health;

    short   Mana[2];
    short   Life[2];
    short   Stamina[2];

    int		Money;
    int     NotUseFlag;

    DWORD	BackUpKey;
    DWORD	BackUpChkSum;

    short   ScaleBlink[2];
    DWORD	UniqueItem;
    short	EffectBlink[2];
    short	EffectColor[4];

    DWORD	DispEffect;

    DWORD			JobCodeMask;
    sITEM_SPECIAL	JobItem;

    DWORD   ItemKindCode;
    DWORD   ItemKindMask;

    short   ItemAgingNum[2];
    short   ItemAgingCount[2];
    short   ItemAgingProtect[2];

    short   SpecialItemFlag[2];

    DWORD	dwCreateTime;

    DWORD	dwTemp[33];

};

struct	sRECORD_ITEM
{
    int	ItemCount;
    int x, y;
    int	ItemPosition;

    sITEMINFO sItemInfo;
};

struct	TRANS_RECORD_DATA
{
    int size, code;

    char	szHeader[8];

    smCHAR_INFO smCharInfo;

    sGAME_SAVE_INFO	GameSaveInfo;

    sTHROW_ITEM_INFO	ThrowItemInfo[THROW_ITEM_INFO_MAX];
    int		ThrowItemCount;

    int		ItemCount;
    int		ItemSubStart;

    int		DataSize;
    BYTE	Data[sizeof(sRECORD_ITEM) * RECORD_ITEM_MAX];
};