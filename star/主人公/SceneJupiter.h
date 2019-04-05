#pragma once
//使用するヘッダーファイル
#include"GameL\SceneManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CSceneJupiter : public CScene
{
public:
	CSceneJupiter() {};
	~CSceneJupiter() {};
	void InitScene(); //ゲームタイトルの初期化メソッド
	void Scene();     //ゲームタイトルの実行中メソッド
private:
	int time_star; //星生成時間
	int arise;
};