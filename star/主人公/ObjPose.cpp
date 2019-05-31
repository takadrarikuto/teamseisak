//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\Audio.h"
#include"GameHead.h"
#include"ObjPose.h"
#include "GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjPose::Init()
{
	m_Af = false;
	
}

//アクション
void  CObjPose::Action()
{
	if (Input::GetVKey('N') == true)
	{
		this->SetStatus(false);	//自身に削除命令を出す			

	}

			
	
}

//ドロー
void  CObjPose::Draw()
{
	float bc[4] = { 1.0f,1.0f,1.0f,0.6f };
	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の位置
	src.m_top = 0.0;
	src.m_left = 0.0f;
	src.m_right = 100.0f;
	src.m_bottom = 100.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(25, &src, &dst, bc, 0.0f);

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"宇宙船に戻りますか?キーを入力してください", 120, 120, 30, c);

	Font::StrDraw(L"戻らない(N)", 450, 300, 30, c);
	Font::StrDraw(L"戻る(B)", 250, 300, 30, c);



}
