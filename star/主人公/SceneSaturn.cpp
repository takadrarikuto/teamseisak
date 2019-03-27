//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneSaturn.h"
#include "GameHead.h"


//初期化メゾット
void CSceneSaturn::InitScene()
{
	//グラフィック読み込み
	//背景
	Draw::LoadImage(L"フィールド背景火星(透過済み).png", 8, TEX_SIZE_512);
	Draw::LoadImage(L"イベント背景(火星).png", 9, TEX_SIZE_512);
	Draw::LoadImage(L"火星.png", 10, TEX_SIZE_512);

	//主人公
	Draw::LoadImage(L"主人公.png", 11, TEX_SIZE_512);
	//アンカー
	Draw::LoadImage(L"アンカー（仮　透過済み）.png", 12, TEX_SIZE_512);

	//外部グラフィックを読み込み5番に登録(512×512ピクセル)
	Draw::LoadImage(L"星(透過済み).png", 13, TEX_SIZE_512);

	//背景オブジェクト生成
	CObjMars* obj_m = new CObjMars();
	Objs::InsertObj(obj_m, OBJ_MARS, 8);
	CObjIbent* obj_i = new CObjIbent();
	Objs::InsertObj(obj_i, OBJ_IBENT, 9); //イベント背景	
	CObjstage* obj_h = new CObjstage();
	Objs::InsertObj(obj_h, OBJ_STAGE, 10);


	//仮主人公オブジェクト生成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 11);

	//アンカーオブジェクト作成
	CObjAncer* obj_a = new CObjAncer();
	Objs::InsertObj(obj_a, OBJ_ANCER, 12);

	//スターオブジェクト作成
	CObjFirstStar* star = new CObjFirstStar();
	Objs::InsertObj(star, OBJ_MARS, 13);    //スターオブジェクト登録

	//アイテムオブジェクト生成
	CObjAitem* obj_ai = new CObjAitem();
	Objs::InsertObj(obj_ai, OBJ_AITEM, 14);

	//スターカウントオブジェクト作成
	CObjStarCount* obj_sc = new CObjStarCount();
	Objs::InsertObj(obj_sc, OBJ_STARCOUNT, 15);

	//星生成時間初期化
	time_star = 0;

	//星生成フラグ初期化
	star_flag = false;

}

//実行中メゾット
void CSceneSaturn::Scene()
{

	if (time_star == 30)
	{
		star_flag = true;
	}

	if (star_flag == false)
	{
		time_star++;
	}
	else if (star_flag == true)
	{
		//スターオブジェクト作成
		CObjFirstStar* star = new CObjFirstStar();
		Objs::InsertObj(star, OBJ_MARS, 13);    //スターオブジェクト登録

		time_star = 0;
		star_flag = false;
	}

	

}