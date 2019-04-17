#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するヘッダーファイル
using namespace GameL;

//シーン：ゲームタイトル
class CSceneStarPicbook :public CScene
{
public:
	CSceneStarPicbook();
	~CSceneStarPicbook();
	void InitScene();//ゲームタイトルの初期化メソッド
	void Scene();//ゲームタイトルの実行中メソッド
private:

};