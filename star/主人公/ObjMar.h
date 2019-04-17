#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//シーンメイン
class CObjMar :public CObj
{
public:
	CObjMar() {};
	~CObjMar() {};
	void Init();
	void Action();
	void Draw();

private:
	bool m_return_flag;

};