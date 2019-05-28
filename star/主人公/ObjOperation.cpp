//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include"GameL\SceneObjManager.h"

#include "CObjOperation.h"
#include "GameHead.h"

//使用するネームスペース
using namespace GameL;

void CObjOperation::Init()
{
	m_mous_l = false;
	m_start_flag = false;
	m_mous_x = 0.0f;
	m_mous_y = 0.0f;

}

void CObjOperation::Action()
{
m_mous_l = Input::GetMouButtonL();

	//マウスの位置の取得
	m_mous_x = (float)Input::GetPosX();
	m_mous_y = (float)Input::GetPosY();

	if (m_mous_x > 0 && m_mous_x < 800 && m_mous_y> 0 && m_mous_y < 600)
	{
		if (m_mous_l == true)
		{
			if (m_start_flag == true)
			{
				Scene::SetScene(new CSceneStageselect()); //宇宙船選択画面に移動
			}
		}
		else
		{
			m_start_flag = true;
		}
	}
	
}

void CObjOperation::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の位置
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(17, &src, &dst, c, 0.0f);

}
