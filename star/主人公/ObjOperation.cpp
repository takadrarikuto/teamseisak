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

}

void CObjOperation::Action()
{
	
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
	src.m_right = 1052.0f;
	src.m_bottom = 432.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(8, &src, &dst, c, 0.0f);

}
