//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

#include"GameHead.h"
#include"Objstaminagaugeframe.h"

//使用するネームスペース
using namespace GameL;

//スタミナ→酸素変更

//イニシャライズ
void CObjstaminagaugeframe::Init()
{
	m_px = 694.0f;
	m_py = 570.0f;
}

//アクション
void CObjstaminagaugeframe::Action()
{

}
//ドロー
void CObjstaminagaugeframe::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"酸素残量", 460, 570, 30, c);

	//背景
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 84.0f;
	src.m_bottom = 8.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px;
	dst.m_right = 105.0f + m_px;
	dst.m_bottom = 30.0f + m_py;

	//描画
	Draw::Draw(21, &src, &dst, c, 0.0f);

}
