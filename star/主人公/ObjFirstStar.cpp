//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjFirstStar.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjFirstStar::CObjFirstStar(float x, float y)
{
	m_px = x;
	m_py = y;
}

//イニシャライズ
void CObjFirstStar::Init()
{
	m_px = 0.0f;
	m_py = 0.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;
	star_co = 0;

	Hits::SetHitBox(this, m_px, m_py, 64, 64, OBJ_FIRSTSTAR, ELEMENT_RED, 12);
}

//アクション
void CObjFirstStar::Action()
{
	m_move = rand() % 50;

	if (m_move <= 90 && m_move <= 0)
		m_vx += 1.0f;

	m_px += m_vx;
	m_py += m_vy;


	//自身のHitBoxを持ってくる
	CHitBox* hit_s = Hits::GetHitBox(this);

	//HitBoxの位置の変更
	hit_s->SetPos(m_px, m_py);

	//アンカーの位置の取得
	CObjAncer* Ancer = (CObjAncer*)Objs::GetObj(OBJ_ANCER);
	float ax = Ancer->GetX();
	float ay = Ancer->GetY();

	//アンカーと当たっているか
	if (hit_s->CheckObjNameHit(OBJ_ANCER) != nullptr)
	{
		m_px = ax - 10;
		m_py = ay - 80;
	}

	//画面外に出たら削除または主人公の当たり判定と当たると星を削除
	if (m_px > 800.0f)
	{
		this->SetStatus(false); //自身に削除命令を出す
		Hits::DeleteHitBox(this); //HitBox削除
	}
	else if (hit_s->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		this->SetStatus(false); //自身に削除命令を出す
		Hits::DeleteHitBox(this); //HitBox削除
		star_co += 1;
	}


}
//ドロー
void CObjFirstStar::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	wchar_t str[256];
	swprintf_s(str, L"星の数×%d個", star_co);
	Font::StrDraw(str, 10, 570, 30, c);

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 190.0f;
	src.m_bottom = 200.0f;


	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px;
	dst.m_right = 64.0f + m_px;
	dst.m_bottom = 64.0f + m_py;

	//描画
	Draw::Draw(12, &src, &dst, c, 0.0f);
}
