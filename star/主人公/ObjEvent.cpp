//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjEvent.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjEvent::Init()
{
	I_Start = false;
	I_co = 0;
	I_Start_co = 0;

	m_px = 0.0f;
	m_py = 0.0f;

	m_x1 = 0.0f;
	m_x2 = 800.0f;

	Hits::SetHitBox(this, m_px, m_py, 800, 400, OBJ_EVENT, ELEMENT_FIELD, 9);

}

//アクション
void CObjEvent::Action()
{

	//背景移動処理
	m_x1 -= 10.0f;
	if (m_x1 < -800.0f)
	{
		m_x1 = 790.0f;
	}

	m_x2 -= 10.0f;
	if (m_x2 < -800.0f)
	{
		m_x2 = 790.0f;
	}

	I_Start_co++;

	//イベント開始処理
	if (I_Start_co == 360)
	{
		I_Start = true;
		I_co++;

		//イベント終了処理
		if (I_co == 30)
		{
			I_Start = false;
			I_Start_co = 0;
			I_co = 0;

			this->SetStatus(false); //自身に削除命令を出す
			Hits::DeleteHitBox(this); //HitBox削除
		}
	}

}
//ドロー
void CObjEvent::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//背景
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 640.0f;
	src.m_bottom = 480.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x1;
	dst.m_right = 800.0f + m_x1;
	dst.m_bottom = 500.0f;

	if (I_Start == true)
	{
		//描画
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}
	
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 640.0f;
	src.m_bottom = 480.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x2;
	dst.m_right = 800.0f + m_x2;
	dst.m_bottom = 500.0f;

	if (I_Start == true)
	{
		//描画
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}
}
