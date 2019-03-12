//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneTitle.h"
#include "GameHead.h"

//コンストラクタ
CSceneTitle::CSceneTitle()
{

}

//デストラクタ
CSceneTitle::~CSceneTitle()
{

}

//初期化メゾット
void CSceneTitle::InitScene()
{
	//グラフィック読み込み
	Draw::LoadImage(L"タイトル.png", 11, TEX_SIZE_512);

	//タイトルオブジェクト生成
	CObjTitle* obj_t = new CObjTitle();
	Objs::InsertObj(obj_t, OBJ_TITLE, 11);

}

//実行中メゾット
void CSceneTitle::Scene()
{

}