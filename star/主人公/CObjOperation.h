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
	
};