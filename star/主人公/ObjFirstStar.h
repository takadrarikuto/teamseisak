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
	CObjFirstStar(float x); //コンストラクタ
	void Init();      //イニシャライズ
	void Action();    //アクション
	void Draw();      //ドロー

	float m_move;//左右スクロール用
	float m_px;
	float m_py;
	float m_vx; //移動ベクトル
	float m_vy;

	bool hero_flag; //主人公フラグ
	bool ancer_flag; //アンカーフラグ
	bool stop_flag;//ストップフラグ
	bool m_Sf;


	wchar_t str[256];
	int star_num;//星番号

private:


};