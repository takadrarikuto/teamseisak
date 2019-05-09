#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：イベント
class CObjStarPresent8 : public CObjStarPresent
{
public:
	CObjStarPresent8() {};	//コンストラクタ
	~CObjStarPresent8() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:

};
