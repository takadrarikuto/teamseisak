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
	void Init();
	void Action();
	void Draw();

private:
	float m_px; //描画位置
	float m_py;
	float m_vx; //移動ベクトル

	float m_pos; //主人公向き
};