//使用するヘッダーファイル
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameL\Audio.h"
#include "GameHead.h"
#include "ObjSelectPlanet.h"

//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CObjSelectPlanet::Init()
{
	m_mous_l = false;
	m_mous_x = 0.0f;
	m_mous_y = 0.0f;
	m_start_flag = false;

	Mars_up = false;
	Venus_up = false;
	Jupiter_up = false;
	Saturn_up = false;
	StarPic = false;

	time_flag = false;
	a_time = 0;

	Back_time = 0.0f;
	m_mou_time = 0.0f;

	Audio::LoadAudio(1, L"効果音.wav", EFFECT);
}

//アクション
void CObjSelectPlanet::Action()
{
	m_mous_l = Input::GetMouButtonL();

	//マウスの位置の取得
	m_mous_x = (float)Input::GetPosX();
	m_mous_y = (float)Input::GetPosY();

	Mars_up = false;
	Venus_up = false;
	Jupiter_up = false;
	Saturn_up = false;

	//連続移動防止
	if (m_mou_time == 60.0f)
	{
		;
	}
	else if (m_mou_time < 60.0f)
	{
		m_mou_time++;
		m_mous_l = false;
	}


	if (m_mous_x > 60 && m_mous_x < 190 && m_mous_y>130 && m_mous_y < 325)
	{
		Mars_up = true;
		if (m_mous_l == true)
		{
			time_flag = true;
		}
	}
	if (m_mous_x > 230 && m_mous_x < 379 && m_mous_y>180 && m_mous_y < 330)
	{
		Venus_up = true;
		if (m_mous_l == true)
		{
			time_flag = true;
		}
	}
	if (m_mous_x > 422 && m_mous_x < 542 && m_mous_y>135 && m_mous_y < 325)
	{
		Jupiter_up = true;
		if (m_mous_l == true)
		{
			time_flag = true;
		}
	}
	if (m_mous_x > 585 && m_mous_x < 722 && m_mous_y>135 && m_mous_y < 325)
	{
		Saturn_up = true;
		if (m_mous_l == true)
		{
			time_flag = true;
		}
	}
	if (m_mous_x > 600 && m_mous_y > 550)
	{
		StarPic = true;
		if (m_mous_l == true)
		{
			time_flag = true;
		}
	}

	//ステージ画面移動
	if (Mars_up == true)
	{
		//10秒後に画面移動
		if (a_time >= 10)
		{
			a_time = 0;
			Back_time = 0.0f;
			m_mou_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneMars()); //火星
		}
	}
	else if (Venus_up == true)
	{
		//10秒後に画面移動
		if (a_time >= 10)
		{
			a_time = 0;
			Back_time = 0.0f;
			m_mou_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneVenus()); //金星
		}
	}
	else if (Saturn_up == true)
	{
		//10秒後に画面移動
		if (a_time >= 10)
		{
			a_time = 0;
			Back_time = 0.0f;
			m_mou_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneSaturn()); //土星
		}
	}
	else if (Jupiter_up == true)
	{
		//10秒後に画面移動
		if (a_time >= 10)
		{
			a_time = 0;
			Back_time = 0.0f;
			m_mou_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneJupiter()); //木星
		}
	}
	else if (StarPic == true)
	{
		//10秒後に画面移動
		if (a_time >= 10)
		{
			a_time = 0;
			Back_time = 0.0f;
			m_mou_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook()); //星図鑑

		}
	}


	if (time_flag == true)
	{
		a_time++;
	}	
	if (m_mous_l == false && a_time > 1)
	{
		time_flag = false;
		a_time++;
	}


	if (a_time == 1)
	{
		Audio::Start(1);
	}


	Back_time++;

	//操作説明選択画面に移動
	if (Input::GetVKey('B') == true && Back_time > 60.0f)
	{
		a_time = 0;
		Back_time = 0.0f;
		m_mou_time = 0.0f;
		time_flag = false;
		Scene::SetScene(new CSceneOperation()); 
	}
}

//ドロー
void CObjSelectPlanet::Draw()
{

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"星図鑑へ", 600, 550, 50, c);
	Font::StrDraw(L"どの星へ行きますか？", 150, 120, 50, c);
	Font::StrDraw(L"火星", 100, 370, 30, c);
	Font::StrDraw(L"金星", 280, 370, 30, c);
	Font::StrDraw(L"木星", 460, 370, 30, c);
	Font::StrDraw(L"土星", 640, 370, 30, c);

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置
	RECT_F srcm; //描画元切り取り位置
	RECT_F dstm; //描画先表示位置
	RECT_F srcv; //描画元切り取り位置
	RECT_F dstv; //描画先表示位置
	RECT_F srcj; //描画元切り取り位置
	RECT_F dstj; //描画先表示位置
	RECT_F srcs; //描画元切り取り位置
	RECT_F dsts; //描画先表示位置


	//切り取り位置の位置
	src.m_top = 30.0;
	src.m_left = 70.0f;
	src.m_right = 1000.0f;
	src.m_bottom = 250.0f;

	//表示位置の設定
	dst.m_top = 170.0f;
	dst.m_left = 70.0f;
	dst.m_right = 760.0f;
	dst.m_bottom = 370.0f;

	Draw::Draw(12, &src, &dst, c, 0.0f);

	if (Mars_up == true)
	{
		//切り取り位置の位置
		srcm.m_top = 40.0f;
		srcm.m_left = 60.0f;
		srcm.m_right = 240.0f;
		srcm.m_bottom = 210.0f;

		//表示位置の設定
		dstm.m_top = 160.0f;
		dstm.m_left = 50.0f;
		dstm.m_right = 210.0f;
		dstm.m_bottom = 370.0f;

		Draw::Draw(12, &srcm, &dstm, c, 0.0f);

	}
	else if (Venus_up == true)
	{
		//切り取り位置の位置
		srcv.m_top = 40.0f;
		srcv.m_left = 290.0f;
		srcv.m_right = 490.0f;
		srcv.m_bottom = 210.0f;

		//表示位置の設定
		dstv.m_top = 160.0f;
		dstv.m_left = 220.0f;
		dstv.m_right = 400.0f;
		dstv.m_bottom = 370.0f;

		Draw::Draw(12, &srcv, &dstv, c, 0.0f);

	}
	else if (Jupiter_up == true)
	{
		//切り取り位置の位置
		srcj.m_top = 50.0f;
		srcj.m_left = 540.0f;
		srcj.m_right = 720.0f;
		srcj.m_bottom = 220.0f;

		//表示位置の設定
		dstj.m_top = 160.0f;
		dstj.m_left = 410.0f;
		dstj.m_right = 560.0f;
		dstj.m_bottom = 370.0f;

		Draw::Draw(12, &srcj, &dstj, c, 0.0f);

	}
	else if (Saturn_up == true)
	{
		//切り取り位置の位置
		srcs.m_top = 50.0f;
		srcs.m_left = 760.0f;
		srcs.m_right = 980.0f;
		srcs.m_bottom = 210.0f;

		//表示位置の設定
		dsts.m_top = 160.0f;
		dsts.m_left = 570.0f;
		dsts.m_right = 750.0f;
		dsts.m_bottom = 370.0f;

		Draw::Draw(12, &srcs, &dsts, c, 0.0f);

	}
}