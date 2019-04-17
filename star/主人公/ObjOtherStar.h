#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:タイトル
class CObjOtherStar : public CObj
{
public:
	CObjOtherStar() {};
	~CObjOtherStar() {};
	CObjOtherStar(float x, float y); //コンストラクタ
	void Init();      //イニシャライズ
	void Action();    //アクション
	void Draw();      //ドロー

					  //float GetX() { return m_px; }
					  //float GetY() { return m_py; }
private:
	float m_move;//左右スクロール用
	float m_px;
	float m_py;
	float m_vx; //移動ベクトル
	float m_vy;

	bool hero_flag; //主人公フラグ
	bool ancer_flag; //アンカーフラグ


};