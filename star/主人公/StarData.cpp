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

unique_ptr<wchar_t>p;//ステージ情報ポインター
int size;			//ステージ情報の大きさ
p = Save::ExternalDataOpen(L"Book1.csv", &size);//外部データ読み込み

int map[56][56];
int count = 1;
for (int i = 0; i < 56; i++)
{
	for (int j = 0; j < 56; j++)
	{
		int w = 0;
		swscanf_s(&p.get()[count], L"%d", &w);

		map[i][j] = w;

		if (w >= 10)
		{
			count += 1;
		}

		count += 2;
	}
}