//使用するヘッダーファイル
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

#include "GameHead.h"
#include "ObjTitle.h"
#include "SceneStageselect.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTitle::Init()
{
	m_mous_l = false;
	m_start_flag = false;
	m_mous_x = 0.0f;
	m_mous_y = 0.0f;
	a_time = 0;
	time_flag = false;
}

//アクション
void CObjTitle::Action()
{
	m_mous_l = Input::GetMouButtonL();

	//マウスの位置の取得
	m_mous_x = (float)Input::GetPosX();
	m_mous_y = (float)Input::GetPosY();

	if (m_mous_x > 300 && m_mous_x < 480 && m_mous_y>450 && m_mous_y < 475)
	{
		if (m_mous_l == true)
		{
			time_flag = true;
				//Audio::Start(1);
				//a_time++;
				//300秒後に画面移動
				
				//if(a_time<=300){
			Scene::SetScene(new CSceneOperation()); //操作説明選択画面に移動
					
				//}
			
		}
	}

	if (time_flag == true)
	{
		a_time++;
	}

	if (a_time == 300)
	{
		Scene::SetScene(new CSceneOperation()); //操作説明選択画面に移動
	}
	else if (a_time == 1)
	{
		//Audio::Start(1);
	}
	else
	{
		//Audio::Stop(1);
	}

}

//ドロー
void CObjTitle::Draw()
{

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の位置
	src.m_top = 0.0;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(11, &src, &dst, c, 0.0f);
}