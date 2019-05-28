#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：イベント
class CObjStarPresent3 : public CObjStarPresent
{
public:
	CObjStarPresent3() {};	//コンストラクタ
	~CObjStarPresent3() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	int a_time;
	bool time_flag;


};
