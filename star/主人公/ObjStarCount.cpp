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


//イニシャライズ
void CObjStarCount::Init()
{
	star_flag = false;

	//主人公と合わせる
	m_px = 400.0f;
	m_py = 520.0f;

	Hits::SetHitBox(this, m_px, m_py, 50, 50, OBJ_STARCOUNT, ELEMENT_RED, 21);
	
	((UserData*)Save::GetData())->star_co = 0;
}

//アクション
void CObjStarCount::Action()
{
	CObjHero* Hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float scx = Hero->GetX();
	float scy = Hero->GetY();

	m_px += scx;
	m_py += scy;


	//自身のHitBoxを持ってくる
	CHitBox* hit_sc = Hits::GetHitBox(this);	

	if (hit_sc->CheckObjNameHit(OBJ_FIRSTSTAR) != nullptr || hit_sc->CheckObjNameHit(OBJ_SECONDSTAR) != nullptr
		|| hit_sc->CheckObjNameHit(OBJ_THIRDSTAR) != nullptr || hit_sc->CheckObjNameHit(OBJ_FOURTHSTAR) != nullptr
		|| hit_sc->CheckObjNameHit(OBJ_OTHERSTAR) != nullptr)
	{
		star_flag = true;
	}

	if (star_flag == true)
	{
		((UserData*)Save::GetData())->star_co += 1;
		star_flag = false;
	}

	if (((UserData*)Save::GetData())->star_co > 10)
	{
		//Scene::SetScene(new CSceneGameKuria());
	}

	//HitBoxの位置の変更
	hit_sc->SetPos(m_px, m_py);

}

//ドロー
void CObjStarCount::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	swprintf_s(str, L"星の数×%3d個", ((UserData*)Save::GetData())->star_co);
	Font::StrDraw(str, 10, 570, 30, c);

}
