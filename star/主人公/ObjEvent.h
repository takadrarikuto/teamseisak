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
	bool I_Start; //イベントスタートフラグ
	int I_co; //イベントカウント
	int I_Start_co; //イベントカウント

	float m_px;
	float m_py;

	float m_x1; //背景操作用
	float m_x2;
};