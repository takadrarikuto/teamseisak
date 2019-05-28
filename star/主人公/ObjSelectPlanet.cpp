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

	time_flag = false;
	a_time = 0;

	Back_time = 0.0f;

	Audio::LoadAudio(1, L"効果音.wav", EFFECT);
}

//アクション
void CObjSelectPlanet::Action()
{
	m_mous_l = Input::GetMouButtonL();

	//マウスの位置の取得
	m_mous_x = (float)Input::GetPosX();
	m_mous_y = (float)Input::GetPosY();


	if (m_mous_x > 60 && m_mous_x < 190 && m_mous_y>130 && m_mous_y < 325)
	{
		if (m_mous_l == true)
		{
			if (m_start_flag == true)
			{
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
				Scene::SetScene(new CSceneMars()); //火星
			}
		}
	}
	if (m_mous_x > 230 && m_mous_x < 379 && m_mous_y>180 && m_mous_y < 330)
	{
		if (m_mous_l == true)
		{
			if (m_start_flag == true)
			{
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
				Scene::SetScene(new CSceneVenus()); //金星
			}
		}
	}
	if (m_mous_x > 422 && m_mous_x < 542 && m_mous_y>135 && m_mous_y < 325)
	{
		if (m_mous_l == true)
		{
			if (m_start_flag == true)
			{
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
				Scene::SetScene(new CSceneJupiter()); //木星
			}
		}
	}
	if (m_mous_x > 585 && m_mous_x < 722 && m_mous_y>135 && m_mous_y < 325)
	{
		if (m_mous_l == true)
		{
			if (m_start_flag == true)
			{
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
				Scene::SetScene(new CSceneSaturn()); //土星
			}
		}
	}
	else
	{
		m_start_flag = true;
	}

	if (m_mous_x > 600 && m_mous_y > 550)
	{
		if (m_mous_l == true)
		{
			if (m_start_flag == true)
			{			
				time_flag = true;
			}
		}
	}
	else
	{
		m_start_flag = true;
	}


	//10秒後に画面移動
	if (a_time == 10)
	{
		a_time = 0;
		Back_time = 0.0f;
		time_flag = false;
		Scene::SetScene(new CSceneStarPicbook()); //星図鑑

	}
	else if (a_time == 1)
	{
		Audio::Start(1);
	}

	Back_time++;

	//操作説明選択画面に移動
	if (Input::GetVKey('B') == true && Back_time > 60.0f)
	{
		a_time = 0;
		Back_time = 0.0f;
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
}