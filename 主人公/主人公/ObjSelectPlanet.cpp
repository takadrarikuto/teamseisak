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
	
}

//アクション
void CObjSelectPlanet::Action()
{

}

//ドロー
void CObjSelectPlanet::Draw()
{

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の位置
	src.m_top = 220.0;
	src.m_left = 70.0f;
	src.m_right = 750.0f;
	src.m_bottom = 450.0f;

	//表示位置の設定
	dst.m_top = 100.0f;
	dst.m_left = 50.0f;
	dst.m_right = 750.0f;
	dst.m_bottom = 500.0f;

	Draw::Draw(12, &src, &dst, c, 0.0f);
}