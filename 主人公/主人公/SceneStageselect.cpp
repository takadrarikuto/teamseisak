//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

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
	//グラフィック読み込み
	Draw::LoadImage(L"宇宙船背景.png", 11, TEX_SIZE_512);

	//タイトルオブジェクト生成
	CObjStageselect* obj_ss = new CObjStageselect();
	Objs::InsertObj(obj_ss, OBJ_STAGESELECT, 11);

}

//実行中メゾット
void CSceneStageselect::Scene()
{

}