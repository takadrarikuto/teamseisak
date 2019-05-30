#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:タイトル
class CObjBonusStar : public CObjFirstStar
{
public:
	CObjBonusStar() {};
	~CObjBonusStar() {};
	CObjBonusStar(float x); //コンストラクタ
	void Init();      //イニシャライズ
	void Action();    //アクション
	void Draw();      //ドロー

private:

};