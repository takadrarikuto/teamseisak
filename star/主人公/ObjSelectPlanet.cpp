//使用するヘッダーファイル
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

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
	time_back = 0;
}

//アクション
void CObjSelectPlanet::Action()
{
	m_mous_l = Input::GetMouButtonL();

	//マウスの位置の取得
	m_mous_x = (float)Input::GetPosX();
	m_mous_y = (float)Input::GetPosY();

	time_back++;

	if (m_mous_x > 60 && m_mous_x < 190 && m_mous_y>130 && m_mous_y < 325)
	{
		if (m_mous_l == true)
		{
			if (m_start_flag == true)
			{
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
				Scene::SetScene(new CSceneStarPicbook()); //星図鑑
			}
		}
	}
	else
	{
		m_start_flag = true;
	}


	if (time_back > 30)
	{
		//bを押すとタイトル画面に移動
		if (Input::GetVKey('B') == true)
		{
			if (m_start_flag == true)
			{
				Scene::SetScene(new CSceneTitle());
			}
			else
			{
				m_start_flag = true;
			}
		}
	}

}

//ドロー
void CObjSelectPlanet::Draw()
{

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//仮マウス位置
	wchar_t str[256];
	swprintf_s(str, L"x=%d,y=%d", (int)m_mous_x,(int) m_mous_y);
	Font::StrDraw(str, 10, 20, 30, c);
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