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
	int Aitem_co_max; //個数
	int Aitem_co; //個数を減らすよう

	wchar_t str[256];
};