#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーンメイン
class CSceneStageselect :public CScene
{
public:
	CSceneStageselect();
	~CSceneStageselect();
	void InitScene(); //初期化メゾット
	void Scene(); //実行中メゾット
private:

};