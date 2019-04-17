//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

#include"GameHead.h"
#include"Objstaminagauge.h"

//使用するネームスペース
using namespace GameL;

extern bool Ancer_on;
extern bool Aitem_on;

//イニシャライズ
void CObjstaminagauge::Init()
{
	Aitem_flag = true;
	Aitem_co_max = 5;

	m_px = 702.0f;
	m_py = 551.0f;

	m_vx = 0.0f;
	m_vax = 0.0f;

	stamina_co = 0;
	time_co = 0;
	stamina_back = 0;

	m_mous_l = false;
	stamina_flag = false;
}

//アクション
void CObjstaminagauge::Action()
{
	m_mous_l = Input::GetMouButtonL();
	
	time_co++;

	//アンカーの位置を持ってくる
	CObjAncer* Ancer = (CObjAncer*)Objs::GetObj(OBJ_ANCER);
	float ay = Ancer->GetY();


	//スタミナ回復
	if (Input::GetVKey('A') == true)
	{
		if (Aitem_co_max > 0)
		{
			if (Aitem_flag == true)
			{
				Aitem_co_max -= 1;
				m_vx -= 30.0f;
				Aitem_flag = false;
			}
		}
		else
		{
			;
		}
	}
	else
	{
		Aitem_flag = true;
	}

	if (time_co > 30)
	{
		//左クリックでスタミナ5消費 
		if (m_mous_l == true && ay > 535.0f)
		{		
			stamina_flag = true;
			m_vax = 5.0f;
		}
		else
		{
			m_mous_l = false;
		}
	}

	if (stamina_flag == true)
	{
		stamina_back += 1;
		m_vax *= stamina_back;
		stamina_flag = false;
	}

	
	//体力減少処理
	stamina_co += 1;

	//5秒で1スタミナ減少
	if (stamina_co == 300)
	{
		m_vx += 1.0f;
		stamina_co = 0;
	}
	
	//スタミナが最大値、最小値を超えないようにする処理
	if (m_vx < 0)
	{
		m_vx = 0.0f;
	}
	else if (m_vx > 96.0f || m_vax > 96.0f)
	{
		m_vx = 96.0f;
		m_vax = 96.0f;
	}
	
	//スタミナが無くなると宇宙船へ
	if (m_vx == 96.0f || m_vax == 96.0f)
	{
		Scene::SetScene(new CSceneStageselect());
	}


}
//ドロー
void CObjstaminagauge::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//背景
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 70.0;
	src.m_right = 80.0f;
	src.m_bottom = 4.0f;

	//表示位置の設定
	dst.m_top = 6.0f + m_py;
	dst.m_left = 0.0f + m_px + m_vx + m_vax;
	dst.m_right = 96.0f + m_px;
	dst.m_bottom = 22.0f + m_py;

	//描画
	Draw::Draw(18, &src, &dst, c, 0.0f);

}
