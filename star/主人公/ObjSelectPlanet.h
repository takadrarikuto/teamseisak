#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//シーンメイン
class CObjSelectPlanet :public CObj
{
public:
	CObjSelectPlanet() {};
	~CObjSelectPlanet() {};
	void Init();
	void Action();
	void Draw();

private:
	bool m_mous_l;
	bool m_start_flag;
	float m_mous_x; //マウスの位置X
	float m_mous_y; //マウスの位置Y
};