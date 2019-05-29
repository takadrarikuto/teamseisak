//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

#include "CObjStarPicbook.h"
#include "GameHead.h"
extern int lever;
extern int star_count;//星総数カウント用

extern int g_first_star;
extern int g_second_star;
extern int g_third_star;
extern int g_fouth_star;
extern int g_other_star;

void CObjStarPicbook::Init()
{
	starmodel_flag = false;
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;

	Audio_co = 0;
	m_mou_time = 0.0f;

	Back_time = 0.0f;

	Audio::LoadAudio(1, L"効果音.wav", EFFECT);
}

void CObjStarPicbook::Action()
{
	int	ver = 0;
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	//連続移動防止
	if (m_mou_time == 60.0f)
	{
		;
	}
	else if(m_mou_time < 60.0f)
	{
		m_mou_time++;
		m_mou_l = false;
	}

	//SE発生処理
	if (m_mou_l == true)
	{
		Audio_co++;
	}
	else if (m_mou_l == false)
	{
		Audio_co = 0;
	}

	//SE発生処理
	if (Audio_co == 1)
	{
		Audio::Start(1);
	}
	else if (Audio_co > 1)
	{
		Audio_co = 2;
	}

	//宇宙船へボタン
	// left				 right            top            bottom         
	if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>0 && m_mou_y < 100)
	{
		if (m_mou_l == true)
		{
			time_flag = true;
			if (a_time == 10)
			{
				lever = 0;
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
				Scene::SetScene(new CSceneStageselect());
			}
			
		}

	}

	

	if (m_mou_l == true)
	{
		time_flag = true;
	}
	else if (m_mou_l == false)
	{
		a_time = 0;
		time_flag = false;
	}


	if (time_flag == true)
	{
		a_time++;
	}

	if (a_time == 1)
	{
	Audio::Start(1);
	}

	Back_time++;

	//ｂを押すと戻る
	if (Input::GetVKey('B') == true && Back_time > 60.0f)
	{
		lever = 0;
		a_time = 0;
		Back_time = 0.0f;
		time_flag = false;
		Scene::SetScene(new CSceneStageselect());
	}


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

	dst.m_top = 376.0f;
	dst.m_left = 530.0f;
	dst.m_right =600.0f;
	dst.m_bottom = 450.0f;
	
	//さそり座画像
	Draw::Draw(2, &src, &dst, c, 0.0f);
	
	Dc += 1;
	
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1104.0f;
	src.m_bottom = 844.0f;

	dst.m_top = 300.0f;
	dst.m_bottom = 374.0f;

	//てんびん座画像
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 400.0f;
	src.m_bottom = 400.0f;

	dst.m_top = 300.0f;
	dst.m_bottom = 374.0f;
	dst.m_left = 330.0f;
	dst.m_right = 400.0f;


	//ふたご座画像
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 654.0f;
	src.m_bottom = 578.0f;

	dst.m_left = 130.0f;
	dst.m_right = 200.0f;
	
	//みずがめ座画像
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;
	
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 764.0f;
	src.m_bottom = 578.0f;

	dst.m_top = 450.0f;
	dst.m_left = 530.0f;
	dst.m_right =600.0f;
	dst.m_bottom = 524.0f;

	//いて座画像
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1192.0f;
	src.m_bottom = 872.0f;

	dst.m_top = 450.0f;
	dst.m_bottom = 524.0f;
	dst.m_left = 330.0f;
	dst.m_right = 400.0f;

	//しし座画像
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 764.0f;
	src.m_bottom = 578.0f;

	dst.m_top = 523.0f;
	dst.m_left = 530.0f;
	dst.m_right = 600.0f;
	dst.m_bottom = 600.0f;

	//やぎ座画像
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 2;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1360.0f;
	src.m_bottom = 880.0f;

	dst.m_top = 376.0f;
	dst.m_bottom = 450.0f;
	dst.m_left = 130.0f;
	dst.m_right = 200.0f;

	//うお座画像
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 884.0f;
	src.m_bottom = 624.0f;

	dst.m_top = 376.0f;
	dst.m_bottom = 450.0f;
	dst.m_left = 330.0f;
	dst.m_right = 400.0f;

	//かに座画像
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1308.0f;
	src.m_bottom = 776.0f;

	dst.m_top = 523.0f;
	dst.m_bottom = 600.0f;
	dst.m_left = 330.0f;
	dst.m_right = 400.0f;

	//おとめ座画像
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 424.0f;
	src.m_bottom = 320.0f;

	dst.m_top = 450.0f;
	dst.m_bottom = 524.0f;
	dst.m_left = 130.0f;
	dst.m_right = 200.0f;

	//おひつじ座画像
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 424.0f;
	src.m_bottom = 320.0f;

	dst.m_left = 130.0f;
	dst.m_right = 200.0f;
	dst.m_top = 526.0f;
	dst.m_bottom = 600.0f;

	//おうし座画像
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);

	if (m_mou_l == true)
	{
		time_flag = true;
	}
	else if (m_mou_l == false)
	{
		a_time = 0;
		time_flag = false;
	}


	if (time_flag == true)
	{
		a_time++;
	}

	if (a_time == 1)
	{
		Audio::Start(1);
	}

	//宇宙船への文字を描画する
	//					　　X　Y　大きさ
	Font::StrDraw(L"宇宙", 10, 25, 25, c);
	Font::StrDraw(L"船へ", 10, 50, 25, c);

	Font::StrDraw(L"水瓶座", 30 + fy * std, 330 + t*l, 30, c);
	l++;         
	//水瓶座の範囲
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (star_count <200 )
		{
			Font::StrDraw(L"この星々を閲覧するには合計で星を200個集めてください", left_end, 260, font_size, c);
		}

		if (m_mou_l == true && star_count >= 200)
		{	
			//    top            bottom  
			//文字
			if (starmodel_flag == true)
			{
				
					lever = 1;
					a_time = 0;
					Back_time = 0.0f;
					time_flag = false;
					starmodel_flag = false;
					//シーン再作成防止(仮)
					/*this->SetStatus(false);
					CObjStarPresent4* p = new CObjStarPresent4();
					Objs::InsertObj(p, OBJ_STARPRESENT4, 9);*/
					Scene::SetScene(new CSceneStarPicbook());
			
			}
			
			//画像
			else 
			{
				starmodel_flag = true;
			}

		}

	}

	if (m_mou_x > 130 * 1 * std&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k*(l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (star_count < 200)
		{
			Font::StrDraw(L"この星々を閲覧するには合計で星を200個集めてください", left_end, 260, font_size, c);
		}

		if (m_mou_l == true && star_count >= 200)
		{
			//    top            bottom  
			//文字
			if (starmodel_flag == true)
			{

				lever = 13;
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
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
	
	
	Font::StrDraw(L"魚座", 30 + fy * std, 330 + t*l, 30, c);
	l++;
	//魚座の範囲
    if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (star_count < 250)
		{
			Font::StrDraw(L"この星々を閲覧するには合計で星を250個集めてください", left_end, 260, font_size, c);
		}

		if (m_mou_l == true && star_count >= 250)
		{
			if (starmodel_flag = true)
			{
				
					lever = 2;
					a_time = 0;
					Back_time = 0.0f;
					time_flag = false;
					starmodel_flag = false;
					Scene::SetScene(new CSceneStarPicbook());
				
			}
			
		}
		else
		{
			starmodel_flag = true;
		}
	}

	if (m_mou_x > 130 * 1 * std&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k*(l - 1) && m_mou_y < 300 + 73 * l)
	  {
		if (star_count < 250)
		{
			Font::StrDraw(L"この星々を閲覧するには合計で星を250個集めてください", left_end, 260, font_size, c);
		}

		if (m_mou_l == true && star_count >= 250)
		{
			if (starmodel_flag = true)
			{

				lever = 14;
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
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
		if (star_count <300 )
		{
			Font::StrDraw(L"この星々を閲覧するには合計で星を300個集めてください", left_end, 260, font_size, c);
		}

		if (m_mou_l == true && star_count >= 300)
		{
			if (starmodel_flag == true)
			{
				
					lever = 3;
					a_time = 0;
					Back_time = 0.0f;
					time_flag = false;
					starmodel_flag = false;
					Scene::SetScene(new CSceneStarPicbook());
				
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}

	if (m_mou_x > 60+130 * 1 * std&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (star_count < 300)
		{
			Font::StrDraw(L"この星々を閲覧するには合計で星を300個集めてください", left_end, 260, font_size, c);
		}

		if (m_mou_l == true && star_count >= 300)
		{
			if (starmodel_flag == true)
			{

				lever = 15;
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
				starmodel_flag = false;
				Scene::SetScene(new CSceneStarPicbook());

			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	
	//牡牛座
	Font::StrDraw(L"牡牛座", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (star_count < 100)
		{
			Font::StrDraw(L"この星々を閲覧するには合計で星を100個集めてください", left_end, 260, font_size, c);
		}

		if (m_mou_l == true&&star_count>=100)
		{
			if (starmodel_flag = true)
			{
			
					lever = 4;
					a_time = 0;
					Back_time = 0.0f;
					time_flag = false;
					starmodel_flag = false;
					Scene::SetScene(new CSceneStarPicbook());
				
				
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}

	if (m_mou_x > 130 * 1 * std&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (star_count < 100)
		{
			Font::StrDraw(L"この星々を閲覧するには合計で星を100個集めてください", left_end, 260, font_size, c);
		}

		if (m_mou_l == true && star_count >= 100)
		{
			if (starmodel_flag = true)
			{

				lever = 16;
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
				starmodel_flag = false;
				Scene::SetScene(new CSceneStarPicbook());


			}
			else
			{
				starmodel_flag = true;
			}
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
		if (star_count < 350)
		{
			Font::StrDraw(L"この星々を閲覧するには合計で星を350個集めてください", left_end, 260, font_size, c);
		}

		if (m_mou_l == true && star_count >= 350)
		{
			if (starmodel_flag = true)
			{
				
					lever = 5;
					a_time = 0;
					Back_time = 0.0f;
					time_flag = false;
					Scene::SetScene(new CSceneStarPicbook());
				
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}

	if (m_mou_x > 325&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (star_count < 350)
		{
			Font::StrDraw(L"この星々を閲覧するには合計で星を350個集めてください", left_end, 260, font_size, c);
		}

		if (m_mou_l == true && star_count >= 350)
		{
			if (starmodel_flag = true)
			{

				lever = 17;
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
				Scene::SetScene(new CSceneStarPicbook());

			}
			else
			{
				starmodel_flag = true;
			}
		}
	}

	//蟹座
	Font::StrDraw(L"蟹座", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (star_count < 400)
		{
			Font::StrDraw(L"この星々を閲覧するには合計で星を400個集めてください", left_end, 260, font_size, c);
		}
		if (m_mou_l == true&&star_count >= 400)
		{
			if (starmodel_flag = true)
			{
				
					lever = 6;
					a_time = 0;
					Back_time = 0.0f;
					time_flag = false;
					Scene::SetScene(new CSceneStarPicbook());
				
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	if (m_mou_x > 325 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (star_count < 400)
		{
			Font::StrDraw(L"この星々を閲覧するには合計で星を400個集めてください", left_end, 260, font_size, c);
		}
		if (m_mou_l == true && star_count >= 400)
		{
			if (starmodel_flag == true)
			{
				
					lever = 18;
					a_time = 0;
					Back_time = 0.0f;
					time_flag = false;
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
		if (star_count < 450)
		{
			Font::StrDraw(L"この星々を閲覧するには合計で星を450個集めてください", left_end, 260, font_size, c);
		}
		if (m_mou_l == true && star_count >= 450)
		{
			if (starmodel_flag = true)
			{
				
					lever = 7;
					a_time = 0;
					Back_time = 0.0f;
					time_flag = false;					
					Scene::SetScene(new CSceneStarPicbook());
				
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	if (m_mou_x > 325 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (star_count < 450)
		{
			Font::StrDraw(L"この星々を閲覧するには合計で星を450個集めてください", left_end, 260, font_size, c);
		}
		if (m_mou_l == true && star_count >= 450)
		{
			if (starmodel_flag = true)
			{

				lever = 19;
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
				Scene::SetScene(new CSceneStarPicbook());

			}
			else
			{
				starmodel_flag = true;
			}
		}
	}

	//乙女座
	Font::StrDraw(L"乙女座", 30 + fy * std, 350 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (star_count <500)
		{
			Font::StrDraw(L"この星々を閲覧するには合計で星を500個集めてください", left_end, 260, font_size, c);
		}

		if (m_mou_l == true && star_count >= 500)
		{
			if (starmodel_flag = true)
			{
				
					lever = 8;
					a_time = 0;
					Back_time = 0.0f;
					time_flag = false;
					Scene::SetScene(new CSceneStarPicbook());
				
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	if (m_mou_x > 325 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (star_count < 500)
		{
			Font::StrDraw(L"この星々を閲覧するには合計で星を500個集めてください", left_end, 260, font_size, c);
		}

		if (m_mou_l == true && star_count >= 500)
		{
			if (starmodel_flag = true)
			{

				lever = 20;
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
				Scene::SetScene(new CSceneStarPicbook());

			}
			else
			{
				starmodel_flag = true;
			}
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
		if (star_count <150 )
		{
			Font::StrDraw(L"この星々を閲覧するには合計で星を150個集めてください", left_end, 260, font_size, c);
		}
		if (m_mou_l == true)
		{
			if (m_mou_l == true && star_count >= 150)
			{
				
					lever = 9;
					a_time = 0;
					Back_time = 0.0f;
					time_flag = false;
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
		if (star_count < 150)
		{
			Font::StrDraw(L"この星々を閲覧するには合計で星を150個集めてください", left_end, 260, font_size, c);
		}
		if (m_mou_l == true)
		{
			if (m_mou_l == true && star_count >= 150)
			{

				lever = 21;
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
				Scene::SetScene(new CSceneStarPicbook());

			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	
Font::StrDraw(L"蠍座", 30 + fy * std, 330 + t*l, 30, c);
l++;

	//蠍座				left		     right							 top						 bottom       
if (m_mou_x > side_a + side_b * std && m_mou_x < 70 * std+side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
{// 閲覧の制限
	if (star_count < 50 && g_other_star < 50)
	{
		Font::StrDraw(L"この星々を閲覧するには合計で五等星を50個集めてください", left_end, 260, font_size, c);
	}
	
	if (m_mou_l == true&& star_count >= 50&& g_other_star>=50)
	{
		

			if (starmodel_flag == true)
			{

				lever = 10;
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
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
	if (star_count < 50 && g_other_star < 50)
	{
		Font::StrDraw(L"この星々を閲覧するには合計で五等星を50個集めてください", left_end, 260, font_size, c);
	}

	if (m_mou_l == true && star_count >= 50 && g_other_star >= 50)
	{


		if (starmodel_flag == true)
		{

			lever = 22;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
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
	if (star_count < 550)
	{
		Font::StrDraw(L"この星々を閲覧するには合計で星を550個集めてください", left_end, 260, font_size, c);
	}
	if (m_mou_l == true && star_count >= 550)
	{
		if (starmodel_flag = true)
		{
		
				lever = 11;
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
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
	if (star_count < 550)
	{
		Font::StrDraw(L"この星々を閲覧するには合計で星を550個集めてください", left_end, 260, font_size, c);
	}
	if (m_mou_l == true && star_count >= 550)
	{
		if (starmodel_flag = true)
		{

			lever = 23;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());


		}
		else
		{
			starmodel_flag = true;
		}
	}
}
	//山羊座
	Font::StrDraw(L"山羊座", 30 + fy * std, 360 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (star_count < 600)
		{
			Font::StrDraw(L"この星々を閲覧するには合計で星を100個集めてください", left_end, 260, font_size, c);
		}
		if (m_mou_l == true && star_count >= 600)
		{
			if (starmodel_flag = true)
			{
				
					lever = 12;
					a_time = 0;
					Back_time = 0.0f;
					time_flag = false;
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
		if (star_count < 600)
		{
			Font::StrDraw(L"この星々を閲覧するには合計で星を100個集めてください", left_end, 260, font_size, c);
		}
		if (m_mou_l == true && star_count >= 600)
		{
			if (starmodel_flag = true)
			{

				lever = 24;
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
				Scene::SetScene(new CSceneStarPicbook());

			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	
	Font::StrDraw(L"星の名前にカーソル合わせて左クリックするとその星座にある", 80, 25, 25, c);
	Font::StrDraw(L"主な星の説明がされます。", 80, 50, 25, c);
	Font::StrDraw(L"星座の絵にカーソルを合わせてクリックすると星座そのものの", 80, 100, 25, c);
	Font::StrDraw(L"説明に入ります。", 80, 125, 25, c);
	Font::StrDraw(L"ページをめくるには左にある次へをクリックします。", 80, 170,25, c);
	Font::StrDraw(L"一つ前のページにしたい場合は戻るをクリックします。", 80, 195, 25, c);

	//次への文字をループして出す
	wchar_t next[2][2]{ L"次",L"へ" };
	for (int i = 0; i <= 1; i++)
	{
		int l = 25;
		swprintf_s(str, L"%s", next[i]);
		//				　　X　 Y　 大きさ
		Font::StrDraw(str, 20, 130 + l * i, 25, c);
	}

	//戻すの文字をループして出す
	wchar_t before[2][2]{ L"戻",L"る" };
	for (int i = 0; i <= 1; i++)
	{
		int l = 25;
		swprintf_s(str, L"%s", before[i]);

		//				　　X　 Y　 大きさ
		Font::StrDraw(str, 20, 230 + l * i, 25, c);
	}
}