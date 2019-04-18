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
	//アイテムオブジェクトから引用
	bool Aitem_flag; //アイテムフラグ
	int Aitem_co_max; //個数

	float m_px;
	float m_py;

	int m_stamina_max; //スタミナ最大値
	int m_stamina; //表示用スタミナ

	float m_vx; //全ての消費用
	float m_vstamina;//自然消費用
	float m_vancer; //アンカー使用時用

	int stamina_back; //スタミナ消費用
	int stamina_co; //秒数カウント
	int time_co; //画面移動時起動防止用

	int Ev_time; //イベントカウント

	wchar_t str[256];

};