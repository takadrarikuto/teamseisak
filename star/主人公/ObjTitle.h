#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト　タイトル
class CObjTitle :public CObj
{
public:
	CObjTitle() {};
	~CObjTitle() {};
	void Init();
	void Action();
	void Draw();

private:
	bool m_mous_l; //左クリックフラグ
	bool m_start_flag;
	float m_mous_x; //マウスの位置X
	float m_mous_y; //マウスの位置Y
	int a_time;
	bool time_flag;
	int font_size;//文字の大きさ

	float m_mou_time; //連続選択防止タイム
};