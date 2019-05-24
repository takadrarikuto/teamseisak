//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjSecondStar.h"

//使用するネームスペース
using namespace GameL;

extern bool Event_Star;//イベント時星の移動方向変更
extern int Event_Conversion; //イベントエリア切り替え
extern int g_other_star[15];
extern int star_count;
extern int OtStar_Reco;


CObjOtherStar::CObjOtherStar(float x)
{
	m_px = x;
}

//イニシャライズ
void CObjOtherStar::Init()
{
	m_py = rand() % 340 + 1;
	m_vx = 0.0f;
	m_vy = 0.0f;

	hero_flag = false;
	ancer_flag = false;
	
	star_num = rand() % 5;



	Hits::SetHitBox(this, m_px, m_py, 32, 32, OBJ_OTHERSTAR, ELEMENT_RED, 12);


}

//アクション
void CObjOtherStar::Action()
{

	//移動方向変更
	if (Event_Conversion == 0)
	{
		if (Event_Star == false)
		{
			m_vx = 2.0f;
		}
		else if (Event_Star == true)
		{
			m_vx = -2.0f;
		}
	}
	else if (Event_Conversion == 1)
	{
		if (Event_Star == false)
		{
			m_vx = 2.0f;
			m_vy = 0.0f;
		}
		else if (Event_Star == true)
		{
			m_vx = 2.0f;
			m_vy = 0.5f;
		}
	}
	else if (Event_Conversion == 2)
	{
		if (Event_Star == false)
		{
			m_vx = 2.0f;
			m_vy = 0.0f;
		}
		else if (Event_Star == true)
		{
			m_vx = -3.0f;
			m_vy = -0.5f;
		}
	}
	else if (Event_Conversion == 3)
	{
		if (Event_Star == false)
		{
			m_vx = 2.0f;
		}
		else if (Event_Star == true)
		{
			m_vx = 4.0f;
		}
	}

	
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
		m_px = ax - 13;
		m_py = ay - 50;
		ancer_flag = true;
		//主人公の当たり判定に当たると主人公フラグをtrueにし、星の数をカウント
		if (hit_s->CheckObjNameHit(OBJ_HERO) != nullptr)
		{
			hero_flag = true;

		}

	}

	//画面外に出たら星を削除
	if (m_px > 800.0f || m_px < 0.0f || m_py > 500.0f  || m_px < 0.0f)
	{
		this->SetStatus(false); //自身に削除命令を出す
		Hits::DeleteHitBox(this); //HitBox削除

	}
	//アンカーに当たっていなければy軸が350の位置で星を削除
	if (ancer_flag == false)
	{
		if (m_py > 350.0f || m_py < 0.0f || m_py > 500.0f)
		{
			this->SetStatus(false); //自身に削除命令を出す
			Hits::DeleteHitBox(this); //HitBox削除
		}
	}
	//アンカーに当たっている状態で主人公に当たると削除
	else if (ancer_flag == true && hero_flag == true)
	{
		this->SetStatus(false); //自身に削除命令を出す
		Hits::DeleteHitBox(this); //HitBox削除
		ancer_flag = false;
		hero_flag = false;

		OtStar_Reco += 1; //3等星酸素回復用カウント

		if (g_other_star[star_num] != 0)
		{
			g_other_star[32]++;
			star_count++;
		}
		else if (g_other_star[star_num] == 0)
		{
			star_count++;
			g_other_star[star_num]++;

		}
	}
	

}
//ドロー
void CObjOtherStar::Draw()
{
	//自身のHitBoxを持ってくる
	CHitBox* hit_s = Hits::GetHitBox(this);
	hit_s->SetPos(m_px, m_py);

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

			   //切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 100.0f;
	src.m_bottom = 100.0f;

	if (hit_s->CheckObjNameHit(OBJ_ANCER) != nullptr)
	{
		//表示位置の設定
		dst.m_top = 0.0f + m_py;
		dst.m_left = 0.0f + m_px;
		dst.m_right = 32.0f + m_px;
		dst.m_bottom = 32.0f + m_py;
	}
	else
	{
		//表示位置の設定
		dst.m_top = 0.0f + m_py;
		dst.m_left = 0.0f + m_px;
		dst.m_right = 32.0f + m_px;
		dst.m_bottom = 32.0f + m_py;
	}

	//描画
	Draw::Draw(20, &src, &dst, c, 0.0f);
}
