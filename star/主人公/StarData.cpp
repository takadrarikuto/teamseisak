#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include"GameL\DrawFont.h"
#include"GameL\Audio.h"
#include"GameL\UserData.h"
#include"GameHead.h"

int g_Aries[5] = {};//牡羊座：6種
int g_Taurus[17] = {};//牡牛座：16種
int g_Gemini[29] = {};//双子座：10種
int g_Cancer[5] = {};//蟹座：9種
int g_Leo[17] = {};//獅子座：9種
int g_Virgo[29] = {};//乙女座：10種
int g_Libra[5] = {};//天秤座：4種
int g_Scorpio[17] = {};//蠍座：15種
int g_Sagittarius[29] = {};//射手座：13種
int g_Capricorn[5] = {};//山羊座：5種
int g_Aquarius[17] = {};//水瓶座：7種
int g_Pisces[29] = {};//魚座：4種

int g_debris;//はずれ枠

int star_count;//星総数カウント用

int g_first_star[5];
int g_fouth_star[16];
int g_other_star[15];
int g_second_star[40];
int g_third_star[17];
