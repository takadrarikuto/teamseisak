#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：イベント
class CObjStarPresent5 : public CObjStarPresent
{
public:
	CObjStarPresent5() {};	//コンストラクタ
	~CObjStarPresent5() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:

};
