//使用するヘッダーファイル
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"

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
	m_pax = 433.5f;
	m_pay = 535.0f;
	//ロープ
	//m_pry = 490.0f;
	m_prx = 448.0f;
	m_pry = 500.0f;

	//移動ベクトル初期化
	m_vx = 0.0f;
	m_vy = 0.0f;

	//左クリック操作初期化
	m_mous_l = false;
	
	//当たり判定用のHitBoxを作成

	//アンカー
	Hits::SetHitBox(this, m_pax, m_pay, 40, 40, ELEMENT_ANCER, OBJ_ANCER, 11);

	//ロープ描画用初期化
	time = 0.0f;

	//アンカー移動フラグ初期化
	ancer_flag = false;

	//画面移動時起動防止用初期化
	time_co = 0;
}

//アクション
void CObjAncer::Action()
{
	m_mous_l = Input::GetMouButtonL();

	time_co++;

	//移動ベクトル破棄
	m_vx = 0.0f;
	m_vy = 0.0f;

	//左クリックしている時またはアンカーのy位置が535以下の時移動禁止
	if (m_mous_l == false && m_pay > 535.0f)
	{
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
	}


	//自身のHitBoxを持ってくる
	CHitBox* hit_a = Hits::GetHitBox(this);

	//画面移動時起動防止用
	if (time_co > 30)
	{
		//アンカー発射
		if (hit_a->CheckObjNameHit(OBJ_FIRSTSTAR) != nullptr)
		{
			ancer_flag = false;
		}
		else if (Input::GetMouButtonL() == true && m_pay > 535.0f)
		{
			ancer_flag = true;
		}

		if (ancer_flag == true)
		{
			m_vy -= 9.0f;
			time += 13.0f; //ロープ長さ調整
		}
		else
		{
			m_vy += 6.0f;
			if (m_pry < 500.0f)
			{
				time -= 9.0f; //ロープ長さ調整
			}
			else
			{
				time = 0.0f; //ロープ長さ調整
			}
		}
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
	if (m_pax < 33.0f)
	{
		m_pax = 33.0f; 
	}
	else if (m_pax + 40.0f > 800.0f)
	{
		m_pax = 800.0f -40.0f; 
	}
	if (m_pay < 50.0f)
	{
		m_pay = 50.0f;
		ancer_flag = false;
	}
	else if (m_pay > 535.0f)
	{
		m_pay = 535.0f;
	}
	if (m_pay < 50.0f)
	{
		m_pay = 50.0f;
		ancer_flag = false;
	}
	else if (m_pay > 535.0f)
	{
		m_pay = 535.0f;
	}
	//ロープ
	if (m_prx < 49.0f)
	{
		m_prx = 49.0f;
	}
	else if (m_prx + 26.0f > 800.0f)
	{
		m_prx = 800.0f - 26.0f;
	}
	if (m_pry > 500.0f)
	{
		m_pry = 500.0f;
	}

	//位置更新
	m_px += m_vx; //本体
	m_pax += m_vx; //アンカー
	m_pay += m_vy;
	m_prx += m_vx; //ロープ
	m_pry += m_vy;
	

	//HitBoxの位置の変更
	hit_a->SetPos(m_pax, m_pay - 45);


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


	//ロープ
	//切り取り位置の位置
	srcr.m_top = 0.0f;
	srcr.m_left = 70.0f;
	srcr.m_right = 80.0f;
	srcr.m_bottom = 30.0f;

	//表示位置の設定
	dstr.m_top = 520.0f - time;
	dstr.m_left = 0.0f + m_prx;
	dstr.m_right = 20.0f + m_prx;
	dstr.m_bottom = 540.0f;

	Draw::Draw(12, &srcr, &dstr, c, 0.0f);

	//本体
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

	Draw::Draw(12, &src, &dst, c, 0.0f);
	
	//アンカー
	//切り取り位置の位置
	srca.m_top = 0.0f;
	srca.m_left = 90.0f;
	srca.m_right = 225.0f;
	srca.m_bottom = 200.0f;

	//表示位置の設定
	dsta.m_top = 0.0f + m_pay;
	dsta.m_left = 0.0f + m_pax;
	dsta.m_right = 50.0f + m_pax;
	dsta.m_bottom = -60.0f + m_pay;

	Draw::Draw(12, &srca, &dsta, c, 0.0f);

}
