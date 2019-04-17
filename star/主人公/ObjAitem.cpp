//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\UserData.h"


#include"GameHead.h"
#include"ObjAitem.h"

//使用するネームスペース
using namespace GameL;

bool Aitem_on = false;

//イニシャライズ
void CObjAitem::Init()
{
	//アイテムフラグ初期化
	Aitem_flag = true;

	//画像用座標初期化
	m_px = 780;
	m_py = 530;

	((UserData*)Save::GetData())->Aitem_co_max;

}

//アクション
void CObjAitem::Action()
{
	//アイテム使用
	if (Input::GetVKey('I') == true)
	{
		//使用回数処理
		if (((UserData*)Save::GetData())->Aitem_co_max > 0)
		{
			if (Aitem_flag == true)
			{
				((UserData*)Save::GetData())->Aitem_co_max -= 1; //使用回数を減らす
				Aitem_on = true; //スタミナを増やす
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

	swprintf_s(str, L"ドリンクの数×%d個", ((UserData*)Save::GetData())->Aitem_co_max);
	Font::StrDraw(str, 530, 540, 30, c);

	//背景
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 90.0f;
	src.m_right = 160.0f;
	src.m_bottom = 194.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px;
	dst.m_right = 20.0f + m_px;
	dst.m_bottom = 40.0f + m_py;

	//描画
	Draw::Draw(8, &src, &dst, c, 0.0f);

}
