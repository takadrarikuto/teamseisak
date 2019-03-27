#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト　タイトル
class CObjMars :public CObj
{
public:
	CObjMars() {};
	~CObjMars() {};
	void Init();
	void Action();
	void Draw();

private:
	
};