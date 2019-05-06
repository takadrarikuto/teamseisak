//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

#include"GameHead.h"
#include "ObjExclamationMark.h"

//使用するネームスペース
using namespace GameL;

bool EM_flag = false; //ビックリマーク出現フラグ

//イニシャライズ
void CObjExclamationMark::Init()
{
	//ビックリマーク位置x初期化
	m_pemx = 0.0f;
	//ビックリマーク位置y初期化
	m_pemy = 0.0f;


}

//アクション
void CObjExclamationMark::Action()
{
	//アンカーの位置の取得
	CObjHero* Hero = (CObjHero*)Objs::GetObj(OBJ_EM);
	float hx = Hero->GetX();
	float hy = Hero->GetY();

	//主人公の上に起き続ける
	m_pemx = hx;
	m_pemy = hy - 40.0f;


}
//ドロー
void CObjExclamationMark::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//背景
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 270.0f;
	src.m_left = 200.0f;
	src.m_right = 1240.0f;
	src.m_bottom = 1200.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_pemy;
	dst.m_left = 0.0f + m_pemx;
	dst.m_right = 30.0f + m_pemx;
	dst.m_bottom = 30.0f + m_pemy;

	if (EM_flag == true)
	{
		//描画
		Draw::Draw(23, &src, &dst, c, 0.0f);
	}


}
