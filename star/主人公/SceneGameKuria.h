#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーンメイン
class CSceneGameKuria :public CScene
{
public:
	CSceneGameKuria();
	~CSceneGameKuria();
	void InitScene(); //初期化メゾット
	void Scene(); //実行中メゾット
private:

};