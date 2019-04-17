//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"

//コンストラクタ
CSceneMain::CSceneMain()
{

}

//デストラクタ
CSceneMain::~CSceneMain()
{

}

//初期化メゾット
void CSceneMain::InitScene()
{
	//グラフィック読み込み
	Draw::LoadImage(L"主人公（仮）.png", 10, TEX_SIZE_512);

	//仮主人公オブジェクト生成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//外部グラフィック読み込み
	Draw::LoadImage(L"操作説明.png", 10, TEX_SIZE_512);

	CObjOperation* obj_o = new CObjOperation();
	Objs::InsertObj(obj_o, OBJ_OPERATION, 8);


}

//実行中メゾット
void CSceneMain::Scene()
{

}