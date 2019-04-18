#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト　タイトル
class CObjAitem :public CObj
{
public:
	CObjAitem() {};
	~CObjAitem() {};
	void Init();
	void Action();
	void Draw();

private:
	bool Aitem_flag; //アイテムフラグ

	float m_px; //画像用座標
	float m_py;

	wchar_t str[256];

};