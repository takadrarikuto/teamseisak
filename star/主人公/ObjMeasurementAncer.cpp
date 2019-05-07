//使用するヘッダーファイル
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

#include "GameHead.h"
#include "ObjMeasurementAncer.h"

//使用するネームスペース
using namespace GameL;

extern bool Event_on;
bool MAncer = false;

//イニシャライズ
void CObjMeasurementAncer::Init()
{
	//アンカー位置初期化
	//飛距離測定用アンカー初期化
	m_pafx = 430.0f;
	m_pafy = 535.0f;
	//アンカーサイズ変更
	m_sizex = 0;
	m_sizey = 0;
	size = 38;
	//ヒットボックスサイズ調整
	hitbox_size = 0.0f;

	//飛距離測定用アンカー移動ベクトル初期化
	m_vfx = 0.0f;
	m_vfy = 0.0f;


	//左クリック操作初期化
	m_mous_l = false;

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_pafx, m_pafy, size, size, ELEMENT_ANCER, OBJ_MANCER, 12);

	//アンカー移動フラグ初期化
	ancer_flag = false;

	//画面移動時起動防止用初期化
	time_co = 0;

	//連続発射防止フラグ初期化
	ancer_Prevent_doublepress = false;

	//飛距離測定用アンカー作成初期化
	Ancer_flag = false;
}

//アクション
void CObjMeasurementAncer::Action()
{
	m_mous_l = Input::GetMouButtonL();

	time_co++;

	//移動ベクトル破棄
	m_vfx = 0.0f;
	m_vfy = 0.0f;

	//移動
	//左
	if (Input::GetVKey('A') == true)
	{
		m_vfx -= 4.0f;
	}
	//右
	else if (Input::GetVKey('D') == true)
	{
		m_vfx += 4.0f;
	}


	//自身のHitBoxを持ってくる
	CHitBox* hit_a = Hits::GetHitBox(this);

	//画面移動時起動防止用
	if (time_co > 30)
	{
		if (m_mous_l == true && MAncer == false)
		{
			Ancer_flag = true;
		}
		else if (m_mous_l == false)
		{
			Ancer_flag = false;
		}
	}
	else
	{
		m_mous_l = false;
	}

	if (Ancer_flag == true)
	{
		m_vfy -= 10.0f;
	}
	else if (Ancer_flag == false)
	{
		m_pafy = 535.0f;
	}

	//画面外に出ない処理
	//飛距離測定用アンカー
	if (m_pafy < 0.0f)
	{
		m_pafy = 0.0f;
		Ancer_flag = false;
	}
	else if (m_pafy > 535.0f)
	{
		m_pafy = 535.0f;
	}


	//位置更新
	m_pafx += m_vfx;
	m_pafy += m_vfy;


	//HitBoxの位置の変更
	hit_a->SetPos(m_pafx + hitbox_size, m_pafy, size, size);


}

//ドロー
void CObjMeasurementAncer::Draw()
{

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//飛距離測定用アンカー
	//切り取り位置の位置
	src.m_top = 50.0f;
	src.m_left = 40.0f;
	src.m_right = 180.0f;
	src.m_bottom = 170.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_pafy;
	dst.m_left = 0.0f + m_pafx;
	dst.m_right = 40.0f + m_pafx;
	dst.m_bottom = 40.0f + m_pafy;

	if (Ancer_flag == true)
	{
		Draw::Draw(12, &src, &dst, c, 0.0f);
	}

}
