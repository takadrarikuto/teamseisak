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
extern bool FoStar_Recovery;
extern bool OtStar_Recovery;
extern int g_mars_star[33];
extern int star_count;
int FiStar_Reco = 0; //1等星を一定の数数える
int FoStar_Reco = 0; //2等星を一定の数数える
int OtStar_Reco = 0; //3等星を一定の数数える


//イニシャライズ
void CObjStarCount::Init()
{	
	
	FiStar_Reco_max = 5; //1等星獲得数確認用最大数設定
	FoStar_Reco_max = 25; //2等星獲得数確認用最大数設定
	OtStar_Reco_max = 50; //3等星獲得数確認用最大数設定

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
	else if (FoStar_Reco >= FoStar_Reco_max)
	{
		FoStar_Recovery = true;
		FoStar_Reco = 0;
	}
	else if (OtStar_Reco >= OtStar_Reco_max)
	{
		OtStar_Recovery = true;
		OtStar_Reco = 0;
	}


	//クリア画面移動
	if (star_count >= 100)
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

	swprintf_s(strFos, L"2等星の数×%2d/%d個", FoStar_Reco, FoStar_Reco_max);
	Font::StrDraw(strFos, 200, 10, 20, c);

	swprintf_s(strOts, L"3等星の数×%2d/%d個", OtStar_Reco, OtStar_Reco_max);
	Font::StrDraw(strOts, 400, 10, 20, c);



}
