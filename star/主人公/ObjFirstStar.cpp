//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

#include"GameHead.h"
#include"ObjFirstStar.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjFirstStar::Init()
{
	m_px = 0;
	m_py = 0;
	m_vx = 0.0f;


}

//アクション
void CObjFirstStar::Action()
{
	m_move = rand() % 50;

	if (m_move <= 90 && m_move <= 0)
		m_vx += 1.0f;

	m_px += m_vx;

}
//ドロー
void CObjFirstStar::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

			   //切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 190.0f;
	src.m_bottom = 200.0f;


	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px;
	dst.m_right = 64.0f + m_px;
	dst.m_bottom = 64.0f + m_py;

	//描画
	Draw::Draw(5, &src, &dst, c, 0.0f);
}
