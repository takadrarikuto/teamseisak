#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト　タイトル
class CObjSaturn :public CObj
{
public:
	CObjSaturn() {};
	~CObjSaturn() {};
	void Init();
	void Action();
	void Draw();

private:


};