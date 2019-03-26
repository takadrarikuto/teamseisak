#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト　タイトル
class CObjVenus :public CObj
{
public:
	CObjVenus() {};
	~CObjVenus() {};
	void Init();
	void Action();
	void Draw();

private:


};