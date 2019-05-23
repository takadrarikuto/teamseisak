#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:タイトル
class CObjOtherStar : public CObjFirstStar
{
public:
	CObjOtherStar() {};
	~CObjOtherStar() {};
	CObjOtherStar(float x); //コンストラクタ
	void Init();      //イニシャライズ
	void Action();    //アクション
	void Draw();      //ドロー

private:



};