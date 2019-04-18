#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト　主人公
class CObjStageselect :public CObj
{
public:
	CObjStageselect() {};
	~CObjStageselect() {};
	void Init();
	void Action();
	void Draw();

private:
	

};