#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：イベント
class CObjStarPresent6 : public CObjStarPresent
{
public:
	CObjStarPresent6() {};	//コンストラクタ
	~CObjStarPresent6() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	int a_time;
	bool time_flag;

};
