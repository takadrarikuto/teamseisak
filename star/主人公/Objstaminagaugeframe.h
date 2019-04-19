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

	float m_px;
	float m_py;
};