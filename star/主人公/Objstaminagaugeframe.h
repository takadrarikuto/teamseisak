#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト　タイトル
class CObjstaminagaugeframe :public CObj
{
public:
	CObjstaminagaugeframe() {};
	~CObjstaminagaugeframe() {};
	void Init();
	void Action();
	void Draw();

private:
	bool Aitem_flag; //アイテムフラグ
	int Aitem_co_max; //個数
	int Aitem_co; //個数を減らすよう

	float m_px;
	float m_py;
};