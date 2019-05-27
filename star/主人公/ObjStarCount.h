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

	wchar_t str[256];

	wchar_t strFis[256]; //1等星獲得数確認用
	wchar_t strFos[256]; //2等星獲得数確認用
	wchar_t strOts[256]; //3等星獲得数確認用

	int FiStar_Reco_max; //1等星獲得数確認用最大数
	int SeStar_Reco_max; //2等星獲得数確認用最大数
	int ThStar_Reco_max; //3等星獲得数確認用最大数

	float m_px;
	float m_py;
};