#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：イベント
class CObjStarPicbook : public CObj
{
public:
	CObjStarPicbook() {};	//コンストラクタ
	~CObjStarPicbook() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	float m_mou_x;//マウスの位置X
	float m_mou_y;//マウスの位置X
	bool m_mou_r;//マウスの右ボタン
	bool m_mou_l;//マウスの左ボタン
	bool starmodel_flag;
	int a_time;
	bool time_flag;

	wchar_t str[256];
	wchar_t str2[256];
	wchar_t str3[256];
	wchar_t str4[256];
	wchar_t str5[256];
	wchar_t str6[256];
	wchar_t str7[256];
	wchar_t str8[256];
	wchar_t str9[256];

	wchar_t strmous[256]; //マウスカーソル用

	int Audio_co;
	float m_mou_time; //連続選択防止タイム

	float Back_time; //連続移動防止タイム
};
