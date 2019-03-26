#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト　アンカー
class CObjstage : public CObj
{
public:
	CObjstage() {};
	~CObjstage() {};

	void Init();
	void Action();
	void Draw();

private:
	int stageselect;

};