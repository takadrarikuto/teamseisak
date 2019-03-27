//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjIbent.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjIbent::Init()
{
	I_Start = false;
	I_co = 0;
	I_Start_co = 0;

	Hits::SetHitBox(this, m_px, m_py, 800, 400, OBJ_IBENT, ELEMENT_FIELD, 9);

}

//アクション
void CObjIbent::Action()
{
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
void CObjIbent::Draw()
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
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 400.0f;

	if (I_Start == true)
	{
		//描画
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}
	

}
