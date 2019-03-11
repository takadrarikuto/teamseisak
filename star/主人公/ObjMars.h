#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:タイトル
class CObjMars : public CObj
{
public:
	CObjMars() {};
	~CObjMars() {};
	void Init();      //イニシャライズ
	void Action();    //アクション
	void Draw();      //ドロー

private:
	bool m_key_flag;//キーフラグ
	float m_scroll;//左右スクロール用
};