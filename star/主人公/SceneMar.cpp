//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMar.h"
#include "GameHead.h"

//コンストラクタ
CSceneMar::CSceneMar()
{

}

//デストラクタ
CSceneMar::~CSceneMar()
{

}

//初期化メゾット
void CSceneMar::InitScene()
{
	//グラフィック読み込み
	//背景
	Draw::LoadImage(L"火星.png", 8, TEX_SIZE_512);
	Draw::LoadImage(L"フィールド背景火星(透過済み).png", 9, TEX_SIZE_512);
	//主人公
	Draw::LoadImage(L"主人公（仮）.png", 10, TEX_SIZE_512);
	//アンカー
	Draw::LoadImage(L"アンカー（仮　透過済み）.png", 11, TEX_SIZE_512);

	//仮主人公オブジェクト生成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//アンカーオブジェクト作成
	CObjAncer* obj_a = new CObjAncer();
	Objs::InsertObj(obj_a, OBJ_ANCER, 11);

	//背景オブジェクト生成
	CObjMars* obj_m = new CObjMars();
	Objs::InsertObj(obj_m, OBJ_MARS, 8);
	CObjstage* obj_h = new CObjstage();
	Objs::InsertObj(obj_h, OBJ_STAGE, 9);
}

//実行中メゾット
void CSceneMar::Scene()
{

}