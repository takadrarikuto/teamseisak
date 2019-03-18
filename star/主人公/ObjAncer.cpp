//使用するヘッダーファイル
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjAncer.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjAncer::Init()
{
	//アンカー位置初期化
	//本体
	m_px = 420.0f;
	m_py = 520.0f;
	//アンカー
	m_pax = 428.5f;
	m_pay = 505.0f;
	//ロープ
	m_prx = 446.0f;
	m_pry = 480.0f;

	//移動ベクトル初期化
	m_vx = 0.0f;
	m_vy = 0.0f;

	//左クリック操作初期化
	m_mous_l = false;
	
	//当たり判定用のHitBoxを作成

	//アンカー
	//Hits::SetHitBox(this, m_px, m_py, 20, 50, ELEMENT_ANCER, OBJ_ANCER, 11);

}

//アクション
void CObjAncer::Action()
{
	/*
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float ax = hero->GetX();
	float ay = hero->GetY();

	//位置更新
	m_px +=  ax + 50.0f;
	m_py +=  ay;
	*/

	m_mous_l = Input::GetMouButtonL();

	//移動ベクトル破棄
	m_vx = 0.0f;
	m_vy = 0.0f;

	//移動
	//左
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= 4.0f;
	}
	//右
	else if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += 4.0f;
	}

	//アンカー発射
	if (Input::GetMouButtonL() == true)
	{
		m_vy -= 6.0f;
	}
	else if(Input::GetMouButtonL() == false && m_pay < 505.0f)
	{
		m_vy += 3.0f;
	}


	//画面外に出ない処理
	//本体
	if (m_px < 20.0f)
	{
		m_px = 20.0f; 
	}
	else if (m_px + 54.0f  > 800.0f)
	{
		m_px = 800.0f - 54.0f; 
	}
	//アンカー
	if (m_pax < 29.0f)
	{
		m_pax = 29.0f; 
	}
	else if (m_pax + 46.0f > 800.0f)
	{
		m_pax = 800.0f -46.0f; 
	}
	//ロープ
	if (m_prx < 46.0f)
	{
		m_prx = 46.0f;
	}
	else if (m_prx + 28.0f > 800.0f)
	{
		m_prx = 800.0f - 28.0f;
	}

	//位置更新
	m_px += m_vx;
	m_pax += m_vx;
	m_pay += m_vy;
	m_prx += m_vx;
	m_pry += m_vy;
	
	//自身のHitBoxを持ってくる
	//CHitBox* hit_a = Hits::GetHitBox(this);

	//HitBoxの位置の変更
	//hit_a->SetPos(m_px, m_py);

}

//ドロー
void CObjAncer::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//本体
	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置
	//アンカー
	RECT_F srca; //描画元切り取り位置
	RECT_F dsta; //描画先表示位置
	//ロープ
	RECT_F srcr; //描画元切り取り位置
	RECT_F dstr; //描画先表示位置

	//切り取り位置の位置
	srcr.m_top = 0.0f;
	srcr.m_left = 70.0f;
	srcr.m_right = 80.0f;
	srcr.m_bottom = 30.0f;

	//表示位置の設定
	dstr.m_top = 0.0f + m_pry;
	dstr.m_left = 0.0f + m_prx;
	dstr.m_right = 20.0f + m_prx;
	dstr.m_bottom = 100.0f + m_pry;

	Draw::Draw(11, &srcr, &dstr, c, 0.0f);

	
	//切り取り位置の位置
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 30.0f;
	src.m_bottom = 100.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px;
	dst.m_right = 50.0f + m_px;
	dst.m_bottom = 100.0f + m_py;

	Draw::Draw(11, &src, &dst, c, 0.0f);
	

	//切り取り位置の位置
	srca.m_top = 0.0f;
	srca.m_left = 30.0f;
	srca.m_right = 70.0f;
	srca.m_bottom = 100.0f;

	//表示位置の設定
	dsta.m_top = 0.0f + m_pay;
	dsta.m_left = 0.0f + m_pax;
	dsta.m_right = 50.0f + m_pax;
	dsta.m_bottom = 100.0f + m_pay;

	Draw::Draw(11, &srca, &dsta, c, 0.0f);

}
