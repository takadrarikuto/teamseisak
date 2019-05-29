#pragma once
//使用するヘッダーファイル
#include"GameL\SceneManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CSceneVenus : public CScene
{
public:
	CSceneVenus() {};
	~CSceneVenus() {};
	void InitScene(); //ゲームタイトルの初期化メソッド
	void Scene();     //ゲームタイトルの実行中メソッド
	int WeightedPick(int* pArray, int Length);
private:
	int time_star; //星生成時間
	int occur;	//星生成用
	int arise;	//生成確率用
	bool m_Pf;
	bool m_key_f;//行動制御
	double probability;//確率

	float Star_time; //1等星作成警告用カウント
	bool Star_flag; //1等星作成警告用フラグ


};