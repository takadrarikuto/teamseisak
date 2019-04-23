//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"


#include "CObjStarPicbook.h"
#include "GameHead.h"
extern int lever;

void CObjStarPicbook::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
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
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//カーソル表示(完成したら消す)
	swprintf_s(strmous, L"x=%d,y=%d", (int)m_mou_x, (int)m_mou_y);
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

	int Dc = 0; //描画優先度増加用

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 215.0f;
	src.m_bottom = 240.0f;

	dst.m_top = 500.0f;
	dst.m_left = 0.0f;
	dst.m_right = 67.0f;
	dst.m_bottom = 600.0f;
	
	//さそり座画像
	Draw::Draw(2, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 215.0f;
	src.m_bottom = 240.0f;

	dst.m_top = 500.0f;
	dst.m_left = 67.0f;
	dst.m_right = 132.0f;
	dst.m_bottom = 600.0f;

	//てんびん座画像
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 215.0f;
	src.m_bottom = 240.0f;

	dst.m_top = 500.0f;
	dst.m_left = 132.0f;
	dst.m_right = 202.0f;
	dst.m_bottom = 600.0f;

	//ふたご座画像
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 215.0f;
	src.m_bottom = 240.0f;

	dst.m_top = 500.0f;
	dst.m_left = 202.0f;
	dst.m_right = 269.0f;
	dst.m_bottom = 600.0f;

	//みずがめ座画像
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 215.0f;
	src.m_bottom = 240.0f;

	dst.m_top = 500.0f;
	dst.m_left = 269.0f;
	dst.m_right = 338.0f;
	dst.m_bottom = 600.0f;

	//いて座画像
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 215.0f;
	src.m_bottom = 240.0f;

	dst.m_top = 500.0f;
	dst.m_left = 338.0f;
	dst.m_right = 405.0f;
	dst.m_bottom = 600.0f;

	//おうし座画像
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 215.0f;
	src.m_bottom = 240.0f;

	dst.m_top = 500.0f;
	dst.m_left = 405.0f;
	dst.m_right = 468.0f;
	dst.m_bottom = 600.0f;

	//やぎ座画像
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 2;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 215.0f;
	src.m_bottom = 240.0f;

	dst.m_top = 500.0f;
	dst.m_left = 468.0f;
	dst.m_right = 536.0f;
	dst.m_bottom = 600.0f;

	//うお座画像
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 215.0f;
	src.m_bottom = 240.0f;

	dst.m_top = 500.0f;
	dst.m_left = 536.0f;
	dst.m_right = 603.0f;
	dst.m_bottom = 600.0f;

	//かに座画像
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 215.0f;
	src.m_bottom = 240.0f;

	dst.m_top = 500.0f;
	dst.m_left = 603.0f;
	dst.m_right = 670.0f;
	dst.m_bottom = 600.0f;

	//おとめ座画像
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 145.0f;
	src.m_bottom = 240.0f;

	dst.m_top = 500.0f;
	dst.m_left = 670.0f;
	dst.m_right = 738.0f;
	dst.m_bottom = 600.0f;

	//おひつじ座画像
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 215.0f;
	src.m_bottom = 240.0f;

	dst.m_top = 500.0f;
	dst.m_left = 738.0f;
	dst.m_right = 800.0f ;
	dst.m_bottom = 600.0f;

	//おうし座画像
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);


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
	

	wchar_t test[2][2]{ L"蠍",L"座" }; //さそり
	wchar_t test2[3][2]{ L"天",L"秤",L"座" }; //てんびん
	wchar_t test3[3][2]{ L"双",L"子",L"座" }; //ふたご
	wchar_t test4[3][2]{ L"水",L"瓶",L"座" }; //みずがめ
	wchar_t test5[3][2]{ L"射",L"手",L"座" }; //いて
	wchar_t test6[3][2]{ L"獅",L"子",L"座" }; //しし
	wchar_t test7[3][2]{ L"山",L"羊",L"座" }; //やぎ
	wchar_t test8[2][2]{ L"魚",L"座" }; //うお
	wchar_t test9[2][2]{ L"蟹",L"座" }; //かに
	wchar_t test10[3][2]{ L"乙",L"女",L"座" }; //おとめ
	wchar_t test11[3][2]{ L"牡",L"羊",L"座" }; //ひつじ
	wchar_t test12[3][2]{ L"牡",L"牛",L"座" }; //うし


		//ループして出す
		for (int i = 0; i <= 1; i++)
		{
			swprintf_s(str, L"%s", test8[i]);
			swprintf_s(str2, L"%s", test9[i]);
			swprintf_s(str3, L"%s", test[i]);


			//Yは一回目はiは0なので0に50を掛けている
			//2回目はiは1なので50を100に足す。
			//				　　X　 Y　 大きさ
			Font::StrDraw(str, 75, 320 + l * i, 50, c); //test8
			Font::StrDraw(str2, 342, 320 + l * i, 50, c); //test9
			Font::StrDraw(str3, 610, 320 + l * i, 50, c); //test
			


		}
		
		for (int i = 0; i <= 2; i++)
		{
			swprintf_s(str, L"%s", test4[i]);
			swprintf_s(str2, L"%s", test11[i]);
			swprintf_s(str3, L"%s", test12[i]);
			swprintf_s(str4, L"%s", test3[i]);
			swprintf_s(str5, L"%s", test6[i]);
			swprintf_s(str6, L"%s", test10[i]);
			swprintf_s(str7, L"%s", test2[i]);
			swprintf_s(str8, L"%s", test5[i]);
			swprintf_s(str9, L"%s", test7[i]);

			//				　　X　 Y　 大きさ
			Font::StrDraw(str, 10, 320 + l * i, 50, c); 
			Font::StrDraw(str2, 140, 320 + l * i, 50, c); 
			Font::StrDraw(str3, 208, 320 + l * i, 50, c); 
			Font::StrDraw(str4, 275, 320 + l * i, 50, c); 
			Font::StrDraw(str5, 410, 320 + l * i, 50, c); 
			Font::StrDraw(str6, 480, 320 + l * i, 50, c); 
			Font::StrDraw(str7, 545, 320 + l * i, 50, c); 
			//二文字の星座が2つ入るので2つぶん空ける
			Font::StrDraw(str8, 680, 320 + l * i, 50, c); 
			Font::StrDraw(str9, 745, 320 + l * i, 50, c); 
		}

	// left				 right             
	//水瓶座の範囲
	if (m_mou_x > 0 && m_mou_x < 67)
	{
		if (m_mou_l == true)
		{	
			//    top            bottom  
			//文字
			if (m_mou_y > 300 && m_mou_y < 490)
			{
				
			}
			//画像
			else if (m_mou_y > 500 && m_mou_y < 600)
			{
				
			}
		}
	}
	//魚座の範囲
	else if (m_mou_x > 67 && m_mou_x < 130)
	{
		if (m_mou_l == true)
		{
			if (m_mou_y > 300 && m_mou_y < 490)
			{

			}
			else if (m_mou_y > 500 && m_mou_y < 600)
			{

			}
		}
	}
	//牡羊座
	else if (m_mou_x > 130 && m_mou_x < 200)
	{
		if (m_mou_l == true)
		{
			if (m_mou_y > 300 && m_mou_y < 490)
			{

			}
			else if (m_mou_y > 500 && m_mou_y < 600)
			{

			}
		}
	}
	//牡牛座
	else if (m_mou_x > 200 && m_mou_x < 265)
	{
		if (m_mou_l == true)
		{
			if (m_mou_y > 300 && m_mou_y < 490)
			{

			}
			else if (m_mou_y > 500 && m_mou_y < 600)
			{

			}
		}
	}
	//双子座
	else if (m_mou_x > 265 && m_mou_x < 330)
	{
		if (m_mou_l == true)
		{
			if (m_mou_y > 300 && m_mou_y < 490)
			{

			}
			else if (m_mou_y > 500 && m_mou_y < 600)
			{

			}
		}
	}
	//蟹座
	else if (m_mou_x > 330 && m_mou_x < 396)
	{
		if (m_mou_l == true)
		{
			if (m_mou_y > 300 && m_mou_y < 490)
			{

			}
			else if (m_mou_y > 500 && m_mou_y < 600)
			{

			}
		}
	}
	//獅子座
	else if (m_mou_x > 396 && m_mou_x < 463)
	{
		if (m_mou_l == true)
		{
			if (m_mou_y > 300 && m_mou_y < 490)
			{

			}
			else if (m_mou_y > 500 && m_mou_y < 600)
			{

			}
		}
	}
	//乙女座
	else if (m_mou_x > 463 && m_mou_x < 530)
	{
		if (m_mou_l == true)
		{
			if (m_mou_y > 300 && m_mou_y < 490)
			{

			}
			else if (m_mou_y > 500 && m_mou_y < 600)
			{

			}
		}
	}
	//天秤座
	else if (m_mou_x > 530 && m_mou_x < 594)
	{
		if (m_mou_l == true)
		{
			if (m_mou_y > 300 && m_mou_y < 490)
			{

			}
			else if (m_mou_y > 500 && m_mou_y < 600)
			{

			}
		}
	}
	//蠍座
	else if (m_mou_x > 594 && m_mou_x < 662)
	{
		if (m_mou_l == true)
		{
			if (m_mou_y > 300 && m_mou_y < 490)
			{
				lever = 1;
				Scene::SetScene(new CSceneStarPicbook());
			}
			else if (m_mou_y > 500 && m_mou_y < 600)
			{
				lever = 11;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}
	}
	//射手座
	else if (m_mou_x > 662 && m_mou_x < 727)
	{
		if (m_mou_l == true)
		{
			if (m_mou_y > 300 && m_mou_y < 490)
			{

			}
			else if (m_mou_y > 500 && m_mou_y < 600)
			{

			}
		}
	}
	//山羊座
	else
	{
		if (m_mou_l == true)
		{
			if (m_mou_y > 300 && m_mou_y < 490)
			{

			}
			else if (m_mou_y > 500 && m_mou_y < 600)
			{

			}
		}
	}
}