//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneStageselect.h"
#include "GameHead.h"

//コンストラクタ
CSceneStageselect::CSceneStageselect()
{

}

//デストラクタ
CSceneStageselect::~CSceneStageselect()
{

}

//初期化メゾット
void CSceneStageselect::InitScene()
{
	//音楽情報読み込み
	Audio::LoadAudio(0, L"ステージ選択画面BGM.wav", BACK_MUSIC);


	//バックミュージックスタート
	Audio::Start(0);

	//グラフィック読み込み
	Draw::LoadImage(L"宇宙船背景.png", 11, TEX_SIZE_512);
	Draw::LoadImage(L"惑星(透過済み).png", 12, TEX_SIZE_512);
	Draw::LoadImage(L"yellow_star.png", 13, TEX_SIZE_512);
	Draw::LoadImage(L"red_star.png", 14, TEX_SIZE_512);
	Draw::LoadImage(L"pink_star.png", 15, TEX_SIZE_512);
	Draw::LoadImage(L"green_star.png", 16, TEX_SIZE_512);
	Draw::LoadImage(L"brown_star.png", 17, TEX_SIZE_512);


	//ステージ選択画面オブジェクト生成
	CObjStageselect* obj_ss = new CObjStageselect();
	Objs::InsertObj(obj_ss, OBJ_STAGESELECT, 11);

	//星選択オブジェクト作成
	CObjSelectPlanet* obj_sp = new CObjSelectPlanet();
	Objs::InsertObj(obj_sp, OBJ_STAGESELECTPLANET, 12);

}

//実行中メゾット
void CSceneStageselect::Scene()
{

}
