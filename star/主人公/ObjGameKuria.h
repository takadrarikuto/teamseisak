#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:タイトル
class CObjGameKuria : public CObj
{
public:
	CObjGameKuria() {};
	~CObjGameKuria() {};
	void Init();      //イニシャライズ
	void Action();    //アクション
	void Draw();      //ドロー

private:
	bool m_mous_l; //左クリックフラグ
	bool m_start_flag;

};