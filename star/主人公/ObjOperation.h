#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:タイトル
class CObjOperation : public CObj
{
public:
	CObjOperation() {};
	~CObjOperation() {};
	void Init();      //イニシャライズ
	void Action();    //アクション
	void Draw();      //ドロー

private:
	bool m_mous_l; //左クリックフラグ
	bool m_start_flag;
	float m_mous_x; //マウスの位置X
	float m_mous_y; //マウスの位置Y

};