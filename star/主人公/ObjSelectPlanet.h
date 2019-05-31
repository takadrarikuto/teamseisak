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
	int a_time;
	bool time_flag;

	bool Mars_up;
	bool Venus_up;
	bool Jupiter_up;
	bool Saturn_up;
	bool StarPic;

	bool Sart_flag;
	bool FiStar_flag;

	float Back_time; //連続移動防止タイム
	float m_mou_time; //連続選択防止タイム

	wchar_t str[256];
	wchar_t strFi_co[256];

	wchar_t strFi[256];
	wchar_t strSe[256];
	wchar_t strTh[256];
	wchar_t strFo[256];
	wchar_t strOt[256];


};