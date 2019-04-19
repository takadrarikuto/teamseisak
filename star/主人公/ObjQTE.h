#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト　主人公
class CObjQTE :public CObj
{
public:
	CObjQTE() {};
	~CObjQTE() {};
	void Init();
	void Action();
	void Draw();

private:
	int i;
	int time;

};