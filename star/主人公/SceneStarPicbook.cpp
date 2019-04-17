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
extern int lever;

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

	Draw::LoadImage(L"ブラックタイル.png", 1, TEX_SIZE_512);

	//星図鑑オブジェクト生成
	if(lever==0)
	{
		CObjStarPicbook* p = new CObjStarPicbook();
		Objs::InsertObj(p, OBJ_STARPICBOOK, 9);
	}
	if (lever == 1)
	{
		//星図鑑オブジェクト生成
		CObjStarPresent* s = new CObjStarPresent();
		Objs::InsertObj(s, OBJ_STARPRESENT, 10);
	}

	if (lever==2)
	{
		CObjStarPresent2* a = new CObjStarPresent2();
		Objs::InsertObj(a, OBJ_STARPRESENT2, 11);
	}

}

//ゲームタイトル実行メソッド
void CSceneStarPicbook::Scene()
{

}