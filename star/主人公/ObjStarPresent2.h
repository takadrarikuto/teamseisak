#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：イベント
class CObjStarPresent2 : public CObjStarPresent
{
public:
	CObjStarPresent2() {};	//コンストラクタ
	~CObjStarPresent2() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:


};
