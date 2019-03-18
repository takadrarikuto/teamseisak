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
}

//アクション
void CObjSelectPlanet::Action()
{
	m_mous_l = Input::GetMouButtonL();

	//マウスの位置の取得
	m_mous_x = (float)Input::GetPosX();
	m_mous_y = (float)Input::GetPosY();

	if (m_mous_x > 50 && m_mous_x < 190 && m_mous_y>115 && m_mous_y < 335)
	{
		if (m_mous_l == true)
		{
			if (m_start_flag == true)
			{
				Scene::SetScene(new CSceneMar());
			}
		}
		else
		{
			m_start_flag = true;
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
	swprintf_s(str, L"x=%f,y=%f", m_mous_x, m_mous_y);
	Font::StrDraw(str, 20, 20, 30, c);

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の位置
	src.m_top = 30.0;
	src.m_left = 70.0f;
	src.m_right = 1000.0f;
	src.m_bottom = 250.0f;

	//表示位置の設定
	dst.m_top = 100.0f;
	dst.m_left = 60.0f;
	dst.m_right = 760.0f;
	dst.m_bottom = 400.0f;

	Draw::Draw(12, &src, &dst, c, 0.0f);
}