#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト　タイトル
class CObjExclamationMark :public CObj
{
public:
	CObjExclamationMark() {};
	~CObjExclamationMark() {};
	void Init();
	void Action();
	void Draw();

private:

	float m_pemx; //ビックリマーク位置x
	float m_pemy; //ビックリマーク位置y

};