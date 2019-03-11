#pragma once
//ヘッダー
#include"GameL\SceneManager.h"
//ネームス
using namespace GameL;

//シーン：メイン
class CSceneMain :public  CScene
{
	public:
		CSceneMain();
		~CSceneMain();
		void InitScene();
		void Scene();
	private:

};