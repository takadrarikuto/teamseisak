#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーンメイン
class CSceneSpaceShip :public CScene
{
public:
	CSceneSpaceShip();
	~CSceneSpaceShip();
	void InitScene(); //初期化メゾット
	void Scene(); //実行中メゾット
private:
	bool m_key_flag;//キーフラグ
};