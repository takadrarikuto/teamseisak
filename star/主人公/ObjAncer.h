#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

#define Event_Time (130) //イベント時間カウント用
#define Ancer_Rope_InitialTime (0.0f) //アンカー・ロープ共通初期値


//使用するネームスペース
using namespace GameL;

//オブジェクト　アンカー
class CObjAncer : public CObj
{
public:
	CObjAncer() {};
	~CObjAncer() {};

	void Init();
	void Action();
	void Draw();

	float GetX() { return m_pax; }
	float GetY() { return m_pay; }
	float GetAncerFlag() { return ancer_flag; }

private:

	//位置
	float m_px; //本体
	float m_py;
	float m_pax; //アンカー
	//アンカーサイズ変更用
	float m_sizex;
	float m_sizey;
	float size;
	float m_pay;
	float m_prx; //ロープ
	float m_pry;

	//移動ベクトル
	float m_vx;
	float m_vy;
	float m_vancer;
	float m_vrope;

	bool m_mous_l;
	float rope; //ロープ描画用
	int time_co; //画面移動時起動防止用
	float ancer_time; //アンカー飛距離調整
	float rope_time; //ロープ飛距離調整

	bool ancer_flag; //アンカー移動フラグ
	bool ancer_Prevent_doublepress; //連続発射防止フラグ
	bool ancer_Donot_Stop; //途中停止防止フラグ

	int A_event; //イベントタイム処理
	int Ev_ancer; //イベント時アンカー処理
};