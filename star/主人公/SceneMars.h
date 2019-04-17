#pragma once
#pragma once
//使用するヘッダーファイル
#include"GameL\SceneManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CSceneMars : public CScene
{
public:
	CSceneMars() {};
	~CSceneMars() {};
	void InitScene(); //ゲームタイトルの初期化メソッド
	void Scene();     //ゲームタイトルの実行中メソッド
private:
	int time_star; //星生成時間
	int occur;	//星生成用
	int arise;	//生成確率用
	bool m_Pf;
	bool m_key_f;//行動制御

};