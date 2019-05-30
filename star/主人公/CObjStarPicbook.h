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
	int a_time_max;
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

	bool Spaceship_back;
	bool StarPicbook;
	bool StarPicbook2;
	bool StarPicbook3;
	bool StarPicbook4;
	bool StarPicbook5;
	bool StarPicbook6;
	bool StarPicbook7;
	bool StarPicbook8;
	bool StarPicbook9;
	bool StarPicbook10;
	bool StarPicbook11;
	bool StarPicbook12;
	bool Starmodel;
	bool Starmodel2;
	bool Starmodel3;
	bool Starmodel4;
	bool Starmodel5;
	bool Starmodel6;
	bool Starmodel7;
	bool Starmodel8;
	bool Starmodel9;
	bool Starmodel10;
	bool Starmodel11;
	bool Starmodel12;

	float m_mou_time; //連続選択防止タイム

	float Back_time; //連続移動防止タイム
};
