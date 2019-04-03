//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

#include"GameHead.h"
#include"ObjAitem.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjAitem::Init()
{
	Aitem_flag = true;
	Aitem_co_max = 5;
	Aitem_co = 1;
}

//アクション
void CObjAitem::Action()
{
	//アイテム使用
	if (Input::GetVKey('A') == true)
	{
		//使用回数処理
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

}
//ドロー
void CObjAitem::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	swprintf_s(str, L"ドリンクの数×%d個", Aitem_co_max);
	Font::StrDraw(str, 540, 570, 30, c);

	//背景
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 0.0f;
	src.m_bottom = 0.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 0.0f;
	dst.m_bottom = 0.0f;

	//描画
	Draw::Draw(14, &src, &dst, c, 0.0f);

}
