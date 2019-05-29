#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：イベント
class CObjStarPresent12 : public CObjStarPresent
{
public:
	CObjStarPresent12() {};	//コンストラクタ
	~CObjStarPresent12() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	int a_time;
	bool time_flag;

};
