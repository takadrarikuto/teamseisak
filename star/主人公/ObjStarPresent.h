#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：イベント
class CObjStarPresent : public CObj
{
public:
	CObjStarPresent() {};	//コンストラクタ
	~CObjStarPresent() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	float m_mou_x;//マウスの位置X
	float m_mou_y;//マウスの位置X
	bool m_mou_r;//マウスの右ボタン
	bool m_mou_l;//マウスの左ボタン
	bool page_flag;
	bool page_flag_b;
	int page ;//次のページへ行くための変数
	int page_b;
	int time;
	wchar_t str[256];
	wchar_t see[256];
	int g;//星枠の横幅
	int k;//星枠の立幅
	int t;//星の名前の位置
	int l;//tと掛ける用の変数
	int s;//星のクリックの鍵
	int std;
	int side_a;
	int side_b;
	int size;
	int size_y;
	int font;
	int ver;
	int fy;//星の名前の横幅
	int font_size;//文字の大きさ
	int  Interval_y;//文字の立幅間隔
	int  left_end;//説明文の左の限界を決める

};
