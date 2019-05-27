//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include "GameL\UserData.h"

#include"GameHead.h"
#include"ObjGamekuria.h"
#include"ObjFirstStar.h"

//使用するネームスペース
using namespace GameL;
extern int star_count;
extern int FiStar_Reco; //1等星を一定の数数える
extern int FoStar_Reco; //2等星を一定の数数える
extern int OtStar_Reco; //3等星を一定の数数える


//イニシャライズ
void CObjGameKuria::Init()
{
	m_mous_l = false;
	m_start_flag = false;

}

//アクション
void CObjGameKuria::Action()
{
	m_mous_l = Input::GetMouButtonL();

	//星カウント系初期化
	star_count = 0;
	FiStar_Reco = 0;
	FoStar_Reco = 0;
	OtStar_Reco = 0;

	if (m_mous_l == true)
	{
		if (m_start_flag == true)
		{
			Scene::SetScene(new CSceneTitle()); 
		}
	}
	else
	{
		m_start_flag = true;
	}

}
//ドロー
void CObjGameKuria::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"ゲームクリア", 240, 200, 50, c);
	Font::StrDraw(L"左クリックでタイトルへ", 130, 400, 50, c);

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 190.0f;
	src.m_bottom = 200.0f;


	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 64.0f;
	dst.m_bottom = 64.0f;

	//描画
	Draw::Draw(11, &src, &dst, c, 0.0f);
}
