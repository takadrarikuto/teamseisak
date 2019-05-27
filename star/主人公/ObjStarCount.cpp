//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\UserData.h"

#include"GameHead.h"
#include"ObjStarCount.h"

//使用するネームスペース
using namespace GameL;

bool star_flag = false; //星フラグ
extern bool Star_Recovery;
extern bool FiStar_Recovery;
extern bool SeStar_Recovery;
extern bool ThStar_Recovery;
extern int g_mars_star[33];
extern int star_count;
int FiStar_Reco = 0; //1等星を一定の数数える
int SeStar_Reco = 0; //2等星を一定の数数える
int ThStar_Reco = 0; //3等星を一定の数数える


//イニシャライズ
void CObjStarCount::Init()
{	
	
	FiStar_Reco_max = 5; //1等星獲得数確認用最大数設定
	SeStar_Reco_max = 25; //2等星獲得数確認用最大数設定
	ThStar_Reco_max = 50; //3等星獲得数確認用最大数設定

}

//アクション
void CObjStarCount::Action()
{
	
	//酸素回復処理
	if (FiStar_Reco >= FiStar_Reco_max)
	{
		FiStar_Recovery = true;
		FiStar_Reco = 0;
	}
	else if (SeStar_Reco >= SeStar_Reco_max)
	{
		SeStar_Recovery = true;
		SeStar_Reco = 0;
	}
	else if (ThStar_Reco >= ThStar_Reco_max)
	{
		ThStar_Recovery = true;
		ThStar_Reco = 0;
	}


	//クリア画面移動
	if (star_count >= 300)
	{
		Scene::SetScene(new CSceneGameKuria());
	}

}

//ドロー
void CObjStarCount::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	swprintf_s(str, L"星の数×%3d個", star_count);
	Font::StrDraw(str, 10, 570, 30, c);


	//酸素確認用カウント表示
	swprintf_s(strFis, L"1等星の数×%2d/%d個", FiStar_Reco, FiStar_Reco_max);
	Font::StrDraw(strFis, 10, 10, 20, c);

	swprintf_s(strFos, L"2等星の数×%2d/%d個", SeStar_Reco, SeStar_Reco_max);
	Font::StrDraw(strFos, 200, 10, 20, c);

	swprintf_s(strOts, L"3等星の数×%2d/%d個", ThStar_Reco, ThStar_Reco_max);
	Font::StrDraw(strOts, 400, 10, 20, c);


}
