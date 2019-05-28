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

	float m_mou_x;//マウスの位置X
	float m_mou_y;//マウスの位置X
	bool m_mou_r;//マウスの右ボタン
	bool m_mou_l;//マウスの左ボタン
	bool starpresent_flag;
	bool page_flag;
	bool page_flag_b;
	int page;//次のページへ行くための変数
	int page_max; //最大ページ数
	int page_b;
	int time;
	wchar_t str[256];
	wchar_t see[256];
	wchar_t strp[256]; //ページ表示用
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
	int VER_start; //バー初期化
	int fy;//星の名前の横幅
	int font_size;//文字の大きさ
	int Interval_y;//文字の立幅間隔35
	int IO_y; //y座標開始地点25
	int pagex; //ページ座標x
	int pagey; //ページ座標y
	int pagesize; //ページサイズ
	int  left_end;//説明文の左の限界を決める
	int pagemax;//ページ数の限界

	float start_time; //マウス操作開始時間
	bool start_flag; //マウス操作開始フラグ

	int a_time;
	bool time_flag;

	float m_mou_time; //連続選択防止タイム
private:
	

};


