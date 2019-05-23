#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:タイトル
class CObjSecondStar : public CObjFirstStar
{
public:
	CObjSecondStar() {};
	~CObjSecondStar() {};
	CObjSecondStar(float x); //コンストラクタ
	void Init();      //イニシャライズ
	void Action();    //アクション
	void Draw();      //ドロー

private:


};