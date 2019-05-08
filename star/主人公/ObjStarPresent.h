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
	bool starpresent_flag;
	bool page_flag;
	int page ;//次のページへ行くための変数
	int page_b;
	int time;
	wchar_t str[256];
	wchar_t see[256];
	int ver;
};
