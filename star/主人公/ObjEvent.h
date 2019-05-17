#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト　タイトル
class CObjEvent :public CObj
{
public:
	CObjEvent() {};
	~CObjEvent() {};
	void Init();
	void Action();
	void Draw();

private:
	bool E_Start; //イベントスタートフラグ
	int E_Start_co; //イベントカウント


	float m_x1; //背景操作用x
	float m_x2;
	float m_y1; //背景操作用y
	float m_y2;
};