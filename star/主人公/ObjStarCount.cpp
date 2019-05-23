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
	((UserData*)Save::GetData())->star_co;
	

}

//アクション
void CObjStarCount::Action()
{
	
	//酸素回復処理
	if (FiStar_Reco == 5)
	{
		FiStar_Recovery = true;
		FiStar_Reco = 0;
	}
	else if (FoStar_Reco == 25)
	{
		FoStar_Recovery = true;
		FoStar_Reco = 0;
	}
	else if (OtStar_Reco == 50)
	{
		OtStar_Recovery = true;
		OtStar_Reco = 0;
	}


	if (star_flag == true)
	{
		((UserData*)Save::GetData())->star_co += 1;
		star_flag = false;
	}

	if (((UserData*)Save::GetData())->star_co == 500)
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

}
