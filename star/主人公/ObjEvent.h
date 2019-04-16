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
	int E_co; //イベントカウント
	int E_Start_co; //イベントカウント

	float m_px;
	float m_py;

	float m_x1; //背景操作用
	float m_x2;
};