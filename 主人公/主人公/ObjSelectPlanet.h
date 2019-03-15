#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//シーンメイン
class CObjSelectPlanet :public CObj
{
public:
	CObjSelectPlanet() {};
	~CObjSelectPlanet() {};
	void Init();
	void Action();
	void Draw();

private:

};