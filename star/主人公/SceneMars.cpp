//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneMars.h"
#include"GameHead.h"

//ゲームメイン初期化メソッド
void CSceneMars::InitScene()
{
	//グラフィック読み込み
	Draw::LoadImage(L"主人公（仮）.png", 10, TEX_SIZE_512);

	//仮主人公オブジェクト生成
	CObjHero* hero = new CObjHero();
	Objs::InsertObj(hero, OBJ_HERO, 10);

	//外部グラフィックを読み込み4番に登録(512×512ピクセル)
	Draw::LoadImage(L"火星.png", 4, TEX_SIZE_512);

	//火星オブジェクト作成
	CObjMars* mars = new CObjMars();       //タイトルオブジェクト作成
	Objs::InsertObj(mars, OBJ_MARS, 4);    //タイトルオブジェクト登録
}

//ゲームメイン実行中メソッド
void CSceneMars::Scene()
{

}