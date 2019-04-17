//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

#include"GameHead.h"
#include"ObjQTE.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjQTE::Init()
{
	i = rand() % 36;

	time = 0;

}

//アクション
void CObjQTE::Action()
{
	time++;

	if(time == 10)
	this->SetStatus(false); //自身に削除命令を出す
}
//ドロー
void CObjQTE::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

	switch (i)
	{
	case 1:
		Font::StrDraw(L"A", 150, 150, 30, c2);
		break;
	case 2:
		Font::StrDraw(L"B", 150, 150, 30, c2);
		break;
	}
	//背景
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 15.0f;
	src.m_left = 12.0f;
	src.m_right = 437.0f;
	src.m_bottom = 270.0f;

	//表示位置の設定
	dst.m_top = 100.0f;
	dst.m_left = 100.0f;
	dst.m_right = 200.0f;
	dst.m_bottom = 200.0f;

	//描画
	Draw::Draw(20, &src, &dst, c, 0.0f);

}
