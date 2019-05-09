#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：イベント
class CObjStarPresent7 : public CObjStarPresent
{
public:
	CObjStarPresent7() {};	//コンストラクタ
	~CObjStarPresent7() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:

};
