//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

#include"GameHead.h"
#include"Objstaminagaugeframe.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjstaminagaugeframe::Init()
{
	Aitem_flag = true;
	Aitem_co_max = 5;
	Aitem_co = 1;
	m_px = 700.0f;
	m_py = 550.0f;
}

//アクション
void CObjstaminagaugeframe::Action()
{
	/*
	//アイテム使用
	if (Input::GetVKey('A') == true)
	{
		//画像候補3つ
		if (Aitem_co_max > 0)
		{
			if (Aitem_flag == true)
			{
				Aitem_co_max -= Aitem_co;
				Aitem_flag = false;
			}
		}
		else
		{
			;
		}
	}
	else
	{
		Aitem_flag = true;
	}
	*/

}
//ドロー
void CObjstaminagaugeframe::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//背景
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 84.0f;
	src.m_bottom = 8.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px;
	dst.m_right = 100.0f + m_px;
	dst.m_bottom = 30.0f + m_py;

	//描画
	Draw::Draw(17, &src, &dst, c, 0.0f);

}
