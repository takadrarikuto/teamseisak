#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:タイトル
class CObjStarCount : public CObj
{
public:
	CObjStarCount() {};
	~CObjStarCount() {};
	void Init();      //イニシャライズ
	void Action();    //アクション
	void Draw();      //ドロー

private:
	
	bool star_flag; //星フラグ

	wchar_t str[256];

	float m_px;
	float m_py;
};