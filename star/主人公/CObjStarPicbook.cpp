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

	//カーソル表示(完成したら消す)
	swprintf_s(strmous, L"x=%d,y=%d", (int)m_mou_r, (int)m_mou_l);
	Font::StrDraw(strmous, 600, 20, 30, c);


	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置
	//ブラックタイルの切り取り
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1039.0f;
	src.m_bottom = 469.0f;

	//星座の枠を描画
	dst.m_top = 300.0f;
	dst.m_left = 0.0f;
	dst.m_right = 67.0f;
	dst.m_bottom = 600.0f;

	//ループして描画する
	for (int i = 0; i <= 11; i++)
	{
		//星の名前の枠を描画
		Draw::Draw(1, &src, &dst, c, 0.0f);
		dst.m_left = dst.m_right + 0.0f;
		dst.m_right = dst.m_right + 67.0f;
	}

	//戻るボタンの枠を描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 67.0f;
	dst.m_bottom = 100.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);

	//次のページに行くためのボタンの枠を描画
	dst.m_top = 200.0f;
	dst.m_bottom = 300.0f;

	//次への枠
	Draw::Draw(1, &src, &dst, c, 0.0f);
	dst.m_top = 100.0f;
	dst.m_bottom = 200.0f;

	//戻すの枠
	Draw::Draw(1, &src, &dst, c, 0.0f);
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 215.0f;
	src.m_bottom = 240.0f;

	dst.m_top = 500.0f;
	dst.m_left = 0.0f;
	dst.m_right = 67.0f;
	dst.m_bottom = 600.0f;
	
	Draw::Draw(2, &src, &dst, c, 0.0f);
	
	//宇宙船への文字を描画する
	//					　　X　Y　大きさ
	Font::StrDraw(L"宇宙", 10, 25, 25, c);
	Font::StrDraw(L"船へ", 10, 50, 25, c);

	//宇宙船へボタン
	// left				 right            top            bottom         
	if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>0 && m_mou_y < 100)
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

	int l = 50;
	int vx = 0;

	wchar_t test[2][2]{ L"蠍",L"座" };
	wchar_t test2[3][2]{ L"天",L"秤",L"座" };
		//ループして出す
		for (int i = 0; i <= 1; i++)
		{
			swprintf_s(str, L"%s", test[i]);

			//Yは一回目はiは0なので0に50を掛けている
			//2回目はiは1なので50を100に足す。
			//				　　X　 Y　 大きさ
			Font::StrDraw(str, 10 + vx, 350 + l * i, 50, c);

		}
		for (int i = 0; i <= 2; i++)
		{
			swprintf_s(str, L"%s", test2[i]);
			l = 100;
			vx = 265;
			//				　　X　 Y　 大きさ
			Font::StrDraw(str, 10 + vx, 320 + l * i, 50, c);
		}

		// left				 right            top            bottom       
		if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>300 && m_mou_y < 490)
		{
			if (m_mou_l == true)
			{			
				lever = 1;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}
		//蠍座の範囲
		if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>500 && m_mou_y < 600)
		{
			if (m_mou_l == true)
			{
				lever = 11;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}

}