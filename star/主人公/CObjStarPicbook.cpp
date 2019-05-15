//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"


#include "CObjStarPicbook.h"
#include "GameHead.h"
extern int lever;


void CObjStarPicbook::Init()
{
	starmodel_flag = false;
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
	int g = 200.0f;//星枠の横幅 200.0f
	int k = 75.0f;//星枠の立幅 75.0f
	int t = 70;//星の名前の位置 70
	int l = 0;//tと掛ける用の変数 0
	int s = 0;//星のクリックの鍵 0
	int std = 0;//文字を横に移す変数 0
	int side_a = 0;//左の枠範囲 0
	int side_b = 200;//右の枠範囲 200
	int side_c = 129;//129
	int fy = 200;//星の名前の横幅 200
	int font_size = 25;//文字の大きさ 25
	int  Interval_y = 35;//文字の立幅間隔 35
	int  left_end = 80;//説明文の左の限界を決める 80

	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float p[4] = { 1.0f,1.0f,1.0f,0.6f, };

	//カーソル表示(完成したら消す)
	swprintf_s(strmous, L"x=%d,y=%d", (int)m_mou_x, (int)m_mou_y);
	Font::StrDraw(strmous, 600, 20, 30, c);


	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//サイバー背景の切り取り
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 513.0f;
	src.m_bottom = 289.0f;

	//背景を描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(15, &src, &dst, c, 0.0f);

	//パステルブルータイルの切り取り
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 130.0f;
	src.m_bottom = 67.0f;

	//星図鑑の枠を描画
	dst.m_top = 300.0f;
	dst.m_left = 0.0f;
	dst.m_right = 67.0f;
	dst.m_bottom = 600.0f;

	//ループして描画する
	for (int i = 0; i <= 3; i++)
	{
		//星の名前の枠を描画
		dst.m_top = 300.0f;
		dst.m_left = 0.0f + g * i;
		dst.m_right = 200.0f + g * i;
		dst.m_bottom = 300.0f + k;
		Draw::Draw(1, &src, &dst, p, 0.0f);
		Draw::Draw(9, &src, &dst, c, 0.0f);
		for (int l = 0; l <= 2; l++)
		{

			dst.m_top = 375.0f + k * l;
			dst.m_bottom = 450.0f + k * l;
			Draw::Draw(1, &src, &dst, p, 0.0f);
			Draw::Draw(9, &src, &dst, c, 0.0f);
		}

	}

	//説明文の背景部分を描画
	dst.m_top = 0.0f;
	dst.m_left = 67.0f;
	dst.m_right =800.0f;
	dst.m_bottom = 300.0f;
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.0f);

	//戻るボタンの枠を描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 67.0f;
	dst.m_bottom = 100.0f;
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.0f);

	//次のページに行くためのボタンの枠を描画
	dst.m_top = 200.0f;
	dst.m_bottom = 300.0f;

	//次への枠
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.0f);

	dst.m_top = 100.0f;
	dst.m_bottom = 200.0f;

	//戻すの枠
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.0f);

	int Dc = 0; //描画優先度増加用

	//蠍座の画像位置
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 764.0f;
	src.m_bottom = 578.0f;

	dst.m_top = 380.0f;
	dst.m_left = 500.0f;
	dst.m_right =570.0f;
	dst.m_bottom = 450.0f;
	
	//さそり座画像
	Draw::Draw(2, &src, &dst, c, 0.0f);

	Dc += 1;
	/*
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
	*/
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 215.0f;
	src.m_bottom = 240.0f;

	dst.m_top = 300.0f;
	dst.m_left = 300.0f;
	dst.m_right = 367.0f;
	dst.m_bottom = 400.0f;

	//ふたご座画像
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	/*Dc += 1;

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
	*/

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
			if (starmodel_flag == true)
			{
				lever = 0;
				Scene::SetScene(new CSceneStageselect());
				starmodel_flag = false;
			}
		}
		else
		{
			starmodel_flag = true;
		}
		
		
	}
	//ｂを押すと戻る
	else if (Input::GetVKey('B') == true)
	{
		lever = 0;
		Scene::SetScene(new CSceneStageselect());
	}



	Font::StrDraw(L"水瓶座", 30 + fy * std, 330 + t*l, 30, c);
	l++;         
	//水瓶座の範囲
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{	
			//    top            bottom  
			//文字
			if (starmodel_flag == true)
			{
				lever = 1;
				starmodel_flag = false;
				Scene::SetScene(new CSceneStarPicbook());
			}
			//画像
			else 
			{
			starmodel_flag = true;
			}
		}
	}
	if (m_mou_x > 130 + 1 * std&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k*(l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				lever = 13;
				starmodel_flag = false;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}
		else
		{
			starmodel_flag = true;
		}
	}

	Font::StrDraw(L"魚座", 30 + fy * std, 330 + t*l, 30, c);
	l++;
	//魚座の範囲
    if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag = true)
			{
				lever = 2;
				starmodel_flag = false;
				Scene::SetScene(new CSceneStarPicbook());
			}
			
		}
		else
		{
			starmodel_flag = true;
		}
	}

	if (m_mou_x > 130 + 1 * std&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k*(l - 1) && m_mou_y < 300 + 73 * l)
	  {
		  if (m_mou_l == true)
		  {
			  if (starmodel_flag == true)
			  {
				  lever = 14;
				  starmodel_flag = false;
				  Scene::SetScene(new CSceneStarPicbook());
			  }
		  }
		  else
		  {
			  starmodel_flag = true;
		  }
	  }

	//牡羊座
	Font::StrDraw(L"牡羊座", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				lever = 3;
				starmodel_flag = false;
				Scene::SetScene(new CSceneStarPicbook());
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}

	if (m_mou_x > 130 + 1 * std&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				lever = 15;
				starmodel_flag = false;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}
		else
		{
			starmodel_flag = true;
		}
	}
	
	//牡牛座
	Font::StrDraw(L"牡牛座", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag = true)
			{
				lever = 4;
				starmodel_flag = false;
				Scene::SetScene(new CSceneStarPicbook());
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}

	if (m_mou_x > 130 + 1 * std&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				lever = 16;
				starmodel_flag = false;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}
		else
		{
			starmodel_flag = true;
		}
	}

	t -= 4;
	l -= 4;
	std=1;

	//双子座
	Font::StrDraw(L"双子座", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70*std+side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag = true)
			{
				lever = 5;
				Scene::SetScene(new CSceneStarPicbook());
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}

	if (m_mou_x > 300&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				lever = 17;
				starmodel_flag = false;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}
		else
		{
			starmodel_flag = true;
		}
	}

	//蟹座
	Font::StrDraw(L"蟹座", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag = true)
			{
				lever = 6;
				Scene::SetScene(new CSceneStarPicbook());
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	if (m_mou_x > 300 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				lever = 18;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}
		else
		{
			starmodel_flag = true;
		}
	}

	//獅子座
	Font::StrDraw(L"獅子座", 30 + fy * std, 350 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag = true)
			{
				lever = 7;
				Scene::SetScene(new CSceneStarPicbook());
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	if (m_mou_x > 300 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				lever = 19;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}
		else
		{
			starmodel_flag = true;
		}
	}

	//乙女座
	Font::StrDraw(L"乙女座", 30 + fy * std, 350 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag = true)
			{
				lever = 8;
				Scene::SetScene(new CSceneStarPicbook());
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	if (m_mou_x > 300 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				lever = 20;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}
		else
		{
			starmodel_flag = true;
		}
	}

	t -= 4;
	l -= 4;
	std = 2;
	//天秤座
	Font::StrDraw(L"天秤座", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag = true)
			{
				lever = 9;
				Scene::SetScene(new CSceneStarPicbook());
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	if (m_mou_x > 500 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				lever = 21;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}
		else
		{
			starmodel_flag = true;
		}
	}
	
Font::StrDraw(L"蠍座", 30 + fy * std, 330 + t*l, 30, c);
l++;

	//蠍座				left		     right							 top						 bottom       
if (m_mou_x > side_a + side_b * std && m_mou_x < 70 * std+side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
{
	if (m_mou_l == true)
	{
		if (starmodel_flag == true)
		{
			lever = 10;
			starmodel_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else
	{
		starmodel_flag = true;
	}
}

//   left				  right			  top			 bottom                
if (m_mou_x > 130+200*std&& m_mou_x < 197*(std+1) && m_mou_y>302+k*(l-1) && m_mou_y < 300+73*l)
{
	if (m_mou_l == true)
	{
		if (starmodel_flag == true)
		{
			lever = 22;
			starmodel_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else
	{
		starmodel_flag = true;
	}
}

	//射手座
Font::StrDraw(L"射手座", 30 + fy * std, 350 + t * l, 30, c);
l++;
if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
{
	if (m_mou_l == true)
	{
		if (starmodel_flag = true)
		{
			lever = 11;
			Scene::SetScene(new CSceneStarPicbook());
		}
		else
		{
			starmodel_flag = true;
		}
	}
}
if (m_mou_x > 520 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
{
	if (m_mou_l == true)
	{
		if (starmodel_flag == true)
		{
			lever = 23;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else
	{
		starmodel_flag = true;
	}
}
	//山羊座
	Font::StrDraw(L"山羊座", 30 + fy * std, 360 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag = true)
			{
				lever = 12;
				Scene::SetScene(new CSceneStarPicbook());
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	if (m_mou_x > 500 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				lever = 24;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}
		else
		{
			starmodel_flag = true;
		}
	}

}