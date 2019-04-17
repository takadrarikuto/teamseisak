#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト　タイトル
class CObjstaminagauge :public CObj
{
public:
	CObjstaminagauge() {};
	~CObjstaminagauge() {};
	void Init();
	void Action();
	void Draw();

private:
	bool Aitem_flag; //アイテムフラグ
	int Aitem_co_max; //個数

	float m_px;
	float m_py;

	float m_vx; //自然消費、アイテム使用時用
	float m_vax; //アンカー使用時用

	bool m_mous_l;
	bool stamina_flag;

	int stamina_back; //スタミナ消費用
	int stamina_co; //秒数カウント
	int time_co; //画面移動時起動防止用
};