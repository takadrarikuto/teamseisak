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
	
	for (int i = 0; i <= 7; i++)
	{
		//星の名前を描画
			Draw::Draw(9, &src, &dst, c, 0.0f);
			dst.m_left = dst.m_right + 0.0f;
			dst.m_right = dst.m_right + 100.0f;
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

	//マウスの位置とクリックする場所で当たり判定
	
	//枠を描画
	dst.m_top = 0.0f;
	dst.m_left = 5.0f;
	dst.m_right = 110.0f;
	dst.m_bottom = 50.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);

	if (m_mou_x > 110 || m_mou_y > 50)
	{
		//Font::StrDraw(L"戻る", 10, 0, 50, c);
	}
	Font::StrDraw(L"戻る", 10, 0, 50, c);
	// left				 right            top            bottom               
	if (m_mou_x > 5 && m_mou_x < 110 && m_mou_y>0 && m_mou_y <50)
	{
		if (m_mou_l == true)
		{
			//Font::StrDraw(L"成功", 10, 0, 50, c);
			Scene::SetScene(new CSceneStageselect());
		}
		else
		{
			//Font::StrDraw(L"当たり判定", 10, 0, 50, c);
		}
	}

	//仮マウス位置表示
	/*wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 20, 20, 12, c);*/


}