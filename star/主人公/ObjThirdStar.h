#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:タイトル
class CObjThirdStar : public CObjFirstStar
{
public:
	CObjThirdStar() {};
	~CObjThirdStar() {};
	CObjThirdStar(float x); //コンストラクタ
	void Init();      //イニシャライズ
	void Action();    //アクション
	void Draw();      //ドロー

private:


};