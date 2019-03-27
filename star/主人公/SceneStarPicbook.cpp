//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneStarPicbook.h"
#include "GameHead.h"

//コンストラクタ
CSceneStarPicbook::CSceneStarPicbook()
{

}

//デストラクタ
CSceneStarPicbook::~CSceneStarPicbook()
{

}

//ゲームタイトル初期化メソッド
void CSceneStarPicbook::InitScene()
{	
	//グラフィック読み込み
	Draw::LoadImage(L"テキストボックス.png", 9, TEX_SIZE_512);
	
	//星図鑑オブジェクト生成
	CObjStarPicbook* p = new CObjStarPicbook();
	Objs::InsertObj(p, OBJ_STARPICBOOK,9);

}

//ゲームタイトル実行メソッド
void CSceneStarPicbook::Scene()
{

}