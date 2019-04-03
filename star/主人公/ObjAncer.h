#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

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
private:

	//位置
	float m_px; //本体
	float m_py;
	float m_pax; //アンカー
	float m_pay;
	float m_prx; //ロープ
	float m_pry;

	//移動ベクトル
	float m_vx;
	float m_vy;

	bool m_mous_l;
	float time; //ロープ描画用
	int time_co; //画面移動時起動防止用
	int ancer_time; //飛距離調整

	bool ancer_flag; //アンカー移動フラグ

};