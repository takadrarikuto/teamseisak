//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"


#include "CObjStarPicbook.h"
#include "GameHead.h"
extern int lever;

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
	
	//ループして描画する
	for (int i = 0; i <= 7; i++)
	{
		//星の名前の枠を描画
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
	dst.m_right = 700.0f;
	dst.m_bottom = 300.0f;

	//説明文を描画
	Draw::Draw(9, &src, &dst, c, 0.0f);

	//マウスの位置とクリックする場所で当たり判定
	
	//切り取り位置の設定
	src.m_top = 1.5f;
	src.m_left = 0.0f;
	src.m_right = 300.0f;
	src.m_bottom = 28.0f;

	//戻るボタンの枠を描画
	dst.m_top = 0.0f;
	dst.m_left = 5.0f;
	dst.m_right = 110.0f;
	dst.m_bottom = 50.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);

	//何座に属するかの枠を描画
	dst.m_top = 50.0f;
	dst.m_left = 5.0f;
	dst.m_right = 110.0f;
	dst.m_bottom = 300.0f;
    Draw::Draw(9, &src, &dst, c, 0.0f);
	
	//切り取り位置の設定
	src.m_top =0.0f;
	src.m_left = 5.0f;
	src.m_right = 202.0f;
	src.m_bottom = 470.0f;

	//次のページに行くためのボタンの枠を描画
	dst.m_top = 0.0f;
	dst.m_left = 700.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 150.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);
	dst.m_top = 140.0f;
	dst.m_bottom = 300.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);
	//					　　X　Y　大きさ
	Font::StrDraw(L"戻る", 10, 0, 50, c);
	
	//戻るボタン
	// left				 right            top            bottom         
	if (m_mou_x > 5 && m_mou_x < 110 && m_mou_y>0 && m_mou_y <50)
	{
		if (m_mou_l == true)
		{
			lever = 0;
			Scene::SetScene(new CSceneStageselect());
		}
	}
	//ｂを押すと戻る
	else if (Input::GetVKey('B') == true)
	{
		lever = 0;
		Scene::SetScene(new CSceneStageselect());
	}

	//次への文字をループして出す
	wchar_t next[2][2]{ L"次",L"へ" };
	for (int i = 0; i <= 1; i++)
	{
		int l = 50;
		swprintf_s(str, L"%s", next[i]);
		//				　　X　 Y　 大きさ
		Font::StrDraw(str, 720, 25 + l*i, 50, c);
	}

	//次へを押したらStarPresent2に切り替える
	// left				 right            top            bottom       
	if (m_mou_x > 700 && m_mou_x < 800 && m_mou_y>0 && m_mou_y <140)
	{
		if (m_mou_l == true)
		{
			lever = 1;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}

	//戻すの文字をループして出す
	wchar_t before[2][2]{ L"戻",L"す" };
	for (int i = 0; i <= 1; i++)
	{
		int l = 50;
		swprintf_s(str, L"%s", before[i]);

		//				　　X　 Y　 大きさ
		Font::StrDraw(str, 720, 160 + l*i, 50, c);
	}
	//次へを押したらStarPresentに切り替える
	// left				 right            top            bottom       
	if (m_mou_x > 700 && m_mou_x < 800 && m_mou_y>150 && m_mou_y <300)
	{
		if (m_mou_l == true)
		{
			lever = 0;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}

}