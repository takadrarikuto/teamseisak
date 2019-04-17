#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト　アンカー
class CObjBackground : public CObj
{
public:
	CObjBackground() {};
	~CObjBackground() {};

	void Init();
	void Action();
	void Draw();

private:


};