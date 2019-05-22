#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：イベント
class CObjStarmodel : public CObj
{
public:
	CObjStarmodel() {};	//コンストラクタ
	~CObjStarmodel() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	float m_mou_x;//マウスの位置X
	float m_mou_y;//マウスの位置X
	bool m_mou_r;//マウスの右ボタン
	bool m_mou_l;//マウスの左ボタン

	wchar_t str[256];

	int size;
	int size_y;
	int m_y;
	int font;
	int ver;
	int VER_start; //バー初期化
	bool starmodel_flag;

};
