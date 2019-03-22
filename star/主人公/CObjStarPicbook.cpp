//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "CObjStarPicbook.h"
#include "GameHead.h"

void CObjStarPicbook::Init()
{
	
}

void CObjStarPicbook::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	
}

void CObjStarPicbook::Draw()
{
	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 300.0f;
	src.m_bottom = 461.0f;

	//表示位置の設定
	dst.m_top = 300.0f;
	dst.m_left = 0.0f;
	dst.m_right = 100.0f;
	dst.m_bottom = 600.0f;

	//星の名前を描画
	for (int i = 0; i = 6; i++)
	{
		dst.m_left = dst.m_right +0.0f;
		dst.m_right = dst.m_right +100.0f;
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}

	//マウスの位置とクリックする場所で当たり判定
	if (m_mou_x > 230 && m_mou_x < 450 && m_mou_y>400 && m_mou_y < 430)
	{
	Font::StrDraw(L"◆test", 230, 400, 30, c);
	}

	//切り取り位置の設定
	src.m_top = 1.9f;
	src.m_left = 0.0f;
	src.m_right = 300.0f;
	src.m_bottom = 28.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 300.0f;

	//説明文を描画
	Draw::Draw(9, &src, &dst, c, 0.0f);

	//仮マウス位置表示
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 20, 20, 12, c);


}