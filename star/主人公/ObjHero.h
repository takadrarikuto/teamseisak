#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト　主人公
class CObjHero :public CObj
{
public:
	CObjHero() {};
	~CObjHero() {};
	float GetX() { return m_px; }
	float GetY() { return m_py; }
	void Init();
	void Action();
	void Draw();

private:
	float m_px; //主人公描画位置
	float m_py;
	float m_ax; //アンカー描画位置
	float m_ay;
	float m_vx; //移動ベクトル
	float m_pos; //主人公向き

	int m_ani_time;		//アニメーションフレーム動作間隔
	int m_ani_frame;	//描画フレーム

	bool m_return_flag;

	bool m_mous_l;

};