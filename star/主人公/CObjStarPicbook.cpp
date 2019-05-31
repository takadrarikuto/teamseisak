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

	Spaceship_back = false;
	StarPicbook = false;
	StarPicbook2 = false;
	StarPicbook3 = false;
	StarPicbook4 = false;
	StarPicbook5 = false;
	StarPicbook6 = false;
	StarPicbook7 = false;
	StarPicbook8 = false;
	StarPicbook9 = false;
	StarPicbook10 = false;
	StarPicbook11 = false;
	StarPicbook12 = false;
	Starmodel = false;
	Starmodel2 = false;
	Starmodel3 = false;
	Starmodel4 = false;
	Starmodel5 = false;
	Starmodel6 = false;
	Starmodel7 = false;
	Starmodel8 = false;
	Starmodel9 = false;
	Starmodel10 = false;
	Starmodel11 = false;
	Starmodel12 = false;

	m_mou_time = 0.0f;

	a_time = 0;
	a_time_max = 8;
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

	Spaceship_back = false;

	

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


	//宇宙船へボタン
	// left				 right            top            bottom         
	if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>0 && m_mou_y < 100)
	{
		Spaceship_back = true;
		if (m_mou_l == true)
		{
			time_flag = true;			
		}
	}
	else
	{
		Spaceship_back = false;
	}

	//ｂを押すと戻る
	if (Input::GetVKey('B') == true && Back_time > 60.0f)
	{
		lever = 0;
		a_time = 0;
		Back_time = 0.0f;
		time_flag = false;
		Scene::SetScene(new CSceneStageselect());
	}

	if (Spaceship_back == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 0;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStageselect());
		}
	}
	else if (StarPicbook == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 1;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			starmodel_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (StarPicbook2 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 2;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			starmodel_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (StarPicbook3 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 3;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			starmodel_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (StarPicbook4 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 4;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			starmodel_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (StarPicbook5 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 5;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (StarPicbook6 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 6;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (StarPicbook7 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 7;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (StarPicbook8 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 8;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (StarPicbook9 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 9;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}		
	}
	else if (StarPicbook10 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 10;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			starmodel_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}	
	}
	else if (StarPicbook11 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 11;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}		
	}
	else if (StarPicbook12 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 12;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (Starmodel == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 13;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			starmodel_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}

	}
	else if (Starmodel2 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 14;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			starmodel_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (Starmodel3 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 15;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			starmodel_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (Starmodel4 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 16;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			starmodel_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (Starmodel5 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 17;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (Starmodel6 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 18;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (Starmodel7 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 19;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (Starmodel8 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 20;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (Starmodel9 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 21;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}

	}
	else if (Starmodel10 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 22;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			starmodel_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (Starmodel11 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 23;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (Starmodel12 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 24;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}

	//SE発生処理
	if (m_mou_l == true)
	{
		time_flag = true;
	}
	else if (m_mou_l == false)
	{
		time_flag = false;
		if (a_time > 1)
		{
			a_time++;
		}
		else
		{
			a_time = 0;
		}
	}



	if (time_flag == true)
	{
		a_time++;
	}
	else if (time_flag == false)
	{
		a_time = 0;
	}

	//SE発生処理
	if (a_time == 1)
	{
		Audio::Start(1);
	}


	Back_time++;



}

void CObjStarPicbook::Draw()
{
	int g = 200.0f;//星枠の横幅 200.0f
	int k = 75;//星枠の立幅 75.0f
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


	//宇宙船への文字を描画する
	//					　　X　Y　大きさ
	Font::StrDraw(L"宇宙", 10, 25, 25, c);
	Font::StrDraw(L"船へ", 10, 50, 25, c);

	Font::StrDraw(L"水瓶座", 30 + fy * std, 330 + t*l, 30, c);
	l++;         
	//水瓶座の範囲
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>290 + k * (l - 1) && m_mou_y < 295 + k * l)
	{
		if (star_count < 200)
		{
			time_flag = false;
			StarPicbook = false;
			Font::StrDraw(L"この星々を閲覧するには合計で星を200個集めてください", left_end, 260, font_size, c);
		}
		else if (star_count >= 200)
		{
			StarPicbook = true;
		}
		

		if (m_mou_l == true && star_count >= 200)
		{	
			time_flag = true;
		}
	}
	else
	{
		StarPicbook = false;
	}


	if (m_mou_x > 150 && m_mou_x < 197 * (std + 1) && m_mou_y>290 + k * (l - 1) && m_mou_y < 290 + k * l)
	{
		if (star_count < 200)
		{
			time_flag = false;
			Starmodel = false;
			Font::StrDraw(L"この星々を閲覧するには合計で星を200個集めてください", left_end, 260, font_size, c);
		}
		else if (star_count >= 200)
		{
			Starmodel = true;
		}

		if (m_mou_l == true && star_count >= 200)
		{
			time_flag = true;
		}
	}
	else
	{
		Starmodel = false;
	}

	
	Font::StrDraw(L"魚座", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	//魚座の範囲
    if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>290 + k * (l - 1) && m_mou_y < 290 + k * l)
	{
		if (star_count < 800 && g_first_star < 3)
		{
			time_flag = false;
			StarPicbook2 = false;
			Font::StrDraw(L"この星々を閲覧するには合計で星を800個、1等星を3個", left_end, 240, font_size, c);
			Font::StrDraw(L"集めてください", left_end, 270, font_size, c);
		}

		if (star_count >= 800 && g_first_star >= 3)
		{
			StarPicbook2 = true;
		}

		if (m_mou_l == true && star_count >= 800 && g_first_star >= 3)
		{
			time_flag = true;				
		}
	}
	else
	{
		StarPicbook2 = false;
	}

	if (m_mou_x >150&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k*(l - 1) && m_mou_y < 300 + 73 * l)
	  {
		if (star_count <800 && g_first_star < 3)
		{
			time_flag = false;
			Starmodel2 = false;
			Font::StrDraw(L"この星々を閲覧するには合計で星を800個、1等星を3個集めてください", left_end, 260, font_size, c);
		}

		if (star_count >= 800 && g_first_star >= 3)
		{
			Starmodel2 = true;
		}

		if (m_mou_l == true && star_count >= 800 && g_first_star >= 3)
		{
			time_flag = true;
		}
	}
	else
	{
		Starmodel2 = false;
	}

	//牡羊座
	Font::StrDraw(L"牡羊座", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>290 + k * (l - 1) && m_mou_y < 290 + k * l)
	{
		if (star_count <140 )
		{
			time_flag = false;
			StarPicbook3 = false;
			Font::StrDraw(L"この星々を閲覧するには合計で星を140個集めてください", left_end, 260, font_size, c);
		}

		if (star_count >= 140)
		{
			StarPicbook3 = true;
		}

		if (m_mou_l == true && star_count >= 140)
		{
			time_flag = true;				
		}
	}
	else
	{
		StarPicbook3 = false;
	}

	if (m_mou_x > 150&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (star_count < 140)
		{
			time_flag = false;
			Starmodel3 = false;
			Font::StrDraw(L"この星々を閲覧するには合計で星を140個集めてください", left_end, 260, font_size, c);
		}

		if (star_count >= 140)
		{
			Starmodel3 = true;
		}


		if (m_mou_l == true && star_count >= 140)
		{
			time_flag = true;
		}
	}
	else
	{
		Starmodel3 = false;
	}

	//牡牛座
	Font::StrDraw(L"牡牛座", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>290 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (star_count <200)
		{
			time_flag = false;
			StarPicbook4 = false;
			Font::StrDraw(L"この星々を閲覧するには合計で星を200個集めてください", left_end, 260, font_size, c);
		}

		if (star_count >= 200)
		{
			StarPicbook4 = true;
		}

		if (m_mou_l == true&&star_count>=200)
		{
			time_flag = true;
		}
	}
	else
	{
		StarPicbook4 = false;
	}

	if (m_mou_x > 150&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (star_count < 200)
		{
			time_flag = false;
			Starmodel4 = false;
			Font::StrDraw(L"この星々を閲覧するには合計で星を200個集めてください", left_end, 260, font_size, c);
		}

		if (star_count >= 200)
		{
			Starmodel4 = true;
		}

		if (m_mou_l == true && star_count >= 200)
		{
			time_flag = true;
		}
	}
	else
	{
		Starmodel4 = false;
	}

	t -= 4;
	l -= 4;
	std=1;

	//双子座
	Font::StrDraw(L"双子座", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70*std+side_c*(std + 1) && m_mou_y>290 + k * (l - 1) && m_mou_y < 290 + k * l)
	{
		if (star_count < 260)
		{
			time_flag = false;
			StarPicbook5 = false;
			Font::StrDraw(L"この星々を閲覧するには合計で星を260個集めてください", left_end, 260, font_size, c);
		}

		if (star_count >= 260)
		{
			StarPicbook5 = true;
		}

		if (m_mou_l == true && star_count >= 260)
		{
			time_flag = true;
		}
	}
	else
	{
		StarPicbook5 = false;
	}

	if (m_mou_x > 325&& m_mou_x < 197 * (std + 1) && m_mou_y>290 + k * (l - 1) && m_mou_y < 290 + k * l)
	{
		if (star_count < 260)
		{
			time_flag = false;
			Starmodel5 = false;
			Font::StrDraw(L"この星々を閲覧するには合計で星を260個集めてください", left_end, 260, font_size, c);
		}

		if (star_count >= 260)
		{
			Starmodel5 = true;
		}

		if (m_mou_l == true && star_count >= 260)
		{
			time_flag = true;
		}
	}
	else
	{
		Starmodel5 = false;
	}

	//蟹座
	Font::StrDraw(L"蟹座", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>295 + k * (l - 1) && m_mou_y < 295 + k * l)
	{
		if (star_count < 400)
		{
			time_flag = false;
			StarPicbook6 = false;
			Font::StrDraw(L"この星々を閲覧するには合計で星を400個集めてください", left_end, 260, font_size, c);
		}

		if (star_count >= 400)
		{
			StarPicbook6 = true;
		}

		if (m_mou_l == true&&star_count >= 400)
		{
			time_flag = true;
		}
	}
	else
	{
		StarPicbook6 = false;
	}
	if (m_mou_x > 325 && m_mou_x < 197 * (std + 1) && m_mou_y>295 + k * (l - 1) && m_mou_y < 290 + k * l)
	{
		if (star_count < 400)
		{
			time_flag = false;
			Starmodel6 = false;
			Font::StrDraw(L"この星々を閲覧するには合計で星を400個集めてください", left_end, 260, font_size, c);
		}

		if (star_count >= 400)
		{
			Starmodel6 = true;
		}

		if (m_mou_l == true && star_count >= 400)
		{
			time_flag = true;
		}
	}
	else
	{
		Starmodel6 = false;
	}

	//獅子座
	Font::StrDraw(L"獅子座", 30 + fy * std, 350 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>290 + k * (l - 1) && m_mou_y < 290 + k * l)
	{
		if (star_count < 450)
		{
			time_flag = false;
			StarPicbook7 = false;
			Font::StrDraw(L"この星々を閲覧するには合計で星を450個集めてください", left_end, 260, font_size, c);
		}

		if (star_count >= 450)
		{
			StarPicbook7 = true;
		}

		if (m_mou_l == true && star_count >= 450)
		{
			time_flag = true;
		}
	}
	else
	{
		StarPicbook7 = false;
	}

	if (m_mou_x > 325 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (star_count < 450)
		{
			time_flag = false;
			Starmodel7 = false;
			Font::StrDraw(L"この星々を閲覧するには合計で星を450個集めてください", left_end, 260, font_size, c);
		}

		if (star_count >= 450)
		{
			Starmodel7 = true;
		}

		if (m_mou_l == true && star_count >= 450)
		{
			time_flag = true;
		}
	}
	else
	{
		Starmodel7 = false;
	}

	//乙女座
	Font::StrDraw(L"乙女座", 30 + fy * std, 350 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>290 + k * (l - 1) && m_mou_y < 290 + k * l)
	{
		if (star_count <500)
		{
			time_flag = false;
			StarPicbook8 = false;
			Font::StrDraw(L"この星々を閲覧するには合計で星を500個集めてください", left_end, 260, font_size, c);
		}

		if (star_count >= 500)
		{
			StarPicbook8 = true;
		}

		if (m_mou_l == true && star_count >= 500)
		{
			time_flag = true;
		}
	}
	else
	{
		StarPicbook8 = false;
	}

	if (m_mou_x > 325 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (star_count < 500)
		{
			time_flag = false;
			Starmodel8 = false;
			Font::StrDraw(L"この星々を閲覧するには合計で星を500個集めてください", left_end, 260, font_size, c);
		}

		if (star_count >= 500)
		{
			Starmodel8 = true;
		}

		if (m_mou_l == true && star_count >= 500)
		{
			time_flag = true;
		}
	}
	else
	{
		Starmodel8 = false;
	}

	t -= 4;
	l -= 4;
	std = 2;
	//天秤座
	Font::StrDraw(L"天秤座", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>290 + k * (l - 1) && m_mou_y < 295 + k * l)
	{
		if (star_count <150 )
		{
			time_flag = false;
			StarPicbook9 = false;
			Font::StrDraw(L"この星々を閲覧するには合計で星を150個集めてください", left_end, 260, font_size, c);
		}

		if (star_count >= 150)
		{
			StarPicbook9 = true;
		}

		if (m_mou_l == true && star_count >= 150)
		{
			time_flag = true;			
		}
	}
	else
	{
		StarPicbook9 = false;
	}
	if (m_mou_x > 500 && m_mou_x < 197 * (std + 1) && m_mou_y>290 + k * (l - 1) && m_mou_y < 290 + k * l)
	{
		if (star_count < 150)
		{
			time_flag = false;
			Starmodel9 = false;
			Font::StrDraw(L"この星々を閲覧するには合計で星を150個集めてください", left_end, 260, font_size, c);
		}

		if (star_count >= 150)
		{
			Starmodel9 = true;
		}

		if (m_mou_l == true)
		{
			time_flag = true;
		}
	}
	else
	{
		Starmodel9 = false;
	}

	Font::StrDraw(L"蠍座", 30 + fy * std, 330 + t*l, 30, c);
	l++;

	//蠍座				left		     right							 top						 bottom       
	if (m_mou_x > side_a + side_b * std && m_mou_x < 70 * std+side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 295 + k * l)
	{
		// 閲覧の制限
		if (star_count < 50 || g_other_star < 50)
		{
			time_flag = false;
			StarPicbook10 = false;
			Font::StrDraw(L"この星々を閲覧するには合計で五等星を50個集めてください", left_end, 260, font_size, c);
		}
	
		if (star_count >= 50)
		{
			StarPicbook10 = true;
		}

		if (m_mou_l == true&& star_count >= 50&& g_other_star>=50)
		{
			time_flag = true;
		}

	}
	else
	{
		StarPicbook10 = false;
	}

	//   left				  right			  top			 bottom                
	if (m_mou_x > 130+200*std&& m_mou_x < 197*(std+1) && m_mou_y>302+k*(l-1) && m_mou_y < 300+73*l)
	{
		if (g_other_star < 50)
		{
			time_flag = false;
			Starmodel10 = false;
			Font::StrDraw(L"この星々を閲覧するには合計で五等星を50個集めてください", left_end, 260, font_size, c);
		}

		if (star_count >= 50)
		{
			Starmodel10 = true;
		}

		if (m_mou_l == true && star_count >= 50 && g_other_star >= 50)
		{
			time_flag = true;
		}
	}
	else
	{
		Starmodel10 = false;
	}

	//射手座
	Font::StrDraw(L"射手座", 30 + fy * std, 350 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>290 + k * (l - 1) && m_mou_y < 290 + k * l)
	{
		if (star_count < 550)
		{
			time_flag = false;
			StarPicbook11 = false;
			Font::StrDraw(L"この星々を閲覧するには合計で星を550個集めてください", left_end, 260, font_size, c);
		}
		if (star_count >= 550)
		{
			StarPicbook11 = true;
		}

		if (m_mou_l == true && star_count >= 550)
		{
			time_flag = true;
		}
	}
	else
	{
		StarPicbook11 = false;
	}

	if (m_mou_x > 520 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (star_count < 550)
		{
			time_flag = false;
			Starmodel11 = false;
			Font::StrDraw(L"この星々を閲覧するには合計で星を550個集めてください", left_end, 260, font_size, c);
		}

		if (star_count >= 550)
		{
			Starmodel11 = true;
		}

		if (m_mou_l == true && star_count >= 550)
		{
			time_flag = true;
		}
	}
	else
	{
		Starmodel11 = false;
	}

	//山羊座
	Font::StrDraw(L"山羊座", 30 + fy * std, 360 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>290 + k * (l - 1) && m_mou_y < 290 + k * l)
	{
		if (star_count < 680)
		{
			time_flag = false;
			StarPicbook12 = false;
			Font::StrDraw(L"この星々を閲覧するには合計で星を100個集めてください", left_end, 260, font_size, c);
		}
		if (star_count >= 680)
		{
			StarPicbook12 = true;
		}

		if (m_mou_l == true && star_count >= 680)
		{
			time_flag = true;
		}
	}
	else
	{
		StarPicbook12 = false;
	}
	if (m_mou_x > 500 && m_mou_x < 197 * (std + 1) && m_mou_y>290 + k * (l - 1) && m_mou_y < 290 + k * l)
	{
		if (star_count < 740)
		{
			time_flag = false;
			Starmodel12 = false;
			Font::StrDraw(L"この星々を閲覧するには合計で星を100個集めてください", left_end, 260, font_size, c);
		}

		if (star_count >= 740)
		{
			Starmodel12 = true;
		}

		if (m_mou_l == true && star_count >= 740)
		{
			time_flag = true;
		}
	}
	else
	{
		Starmodel12 = false;
	}
	std = 0;

	Font::StrDraw(L"星の名前にカーソル合わせて左クリックするとその星座にある", 80, 25, 25, c);
	Font::StrDraw(L"主な星の説明がされます。", 80, 50, 25, c);
	Font::StrDraw(L"星座の絵にカーソルを合わせてクリックすると星座そのものの", 80, 100, 25, c);
	Font::StrDraw(L"説明に入ります。", 80, 125, 25, c);
	Font::StrDraw(L"ページをめくるには左にある次へをクリックします。", 80, 170,25, c);
	Font::StrDraw(L"一つ前のページにしたい場合は戻るをクリックします。", 80, 195, 25, c);
	
	/*swprintf_s(strmous, L"x=%d,y=%d", (int)m_mou_x, (int)m_mou_y);
	Font::StrDraw(strmous, 600, 290, 30, c);*/

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