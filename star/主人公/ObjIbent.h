#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト　タイトル
class CObjIbent :public CObj
{
public:
	CObjIbent() {};
	~CObjIbent() {};
	void Init();
	void Action();
	void Draw();

private:
	bool I_Start; //イベントスタートフラグ
	int I_co; //イベントカウント
	int I_Start_co; //イベントカウント

	float m_px;
	float m_py;
};