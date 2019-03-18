#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:タイトル
class CObjFirstStar : public CObj
{
public:
	CObjFirstStar() {};
	~CObjFirstStar() {};
	void Init();      //イニシャライズ
	void Action();    //アクション
	void Draw();      //ドロー

private:
	float m_move;//左右スクロール用
	float m_px;
	float m_py;
	float m_vx; //移動ベクトル
};