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

	Draw::LoadImage(L"パステルブルータイル.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"蠍座.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"天秤座.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"双子座.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"水瓶座.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"射手座.png", 6, TEX_SIZE_512);
	Draw::LoadImage(L"獅子座.png", 7, TEX_SIZE_512);
	Draw::LoadImage(L"山羊座.png", 8, TEX_SIZE_512);
	Draw::LoadImage(L"魚座.png", 10, TEX_SIZE_512);
	Draw::LoadImage(L"蟹座.png", 11, TEX_SIZE_512);
	Draw::LoadImage(L"乙女座.png", 12, TEX_SIZE_512);
	Draw::LoadImage(L"牡羊座.png", 13, TEX_SIZE_512);
	Draw::LoadImage(L"牡牛座.png", 14, TEX_SIZE_512);


	//星座図鑑オブジェクト生成

	//星図鑑オブジェクト生成
	if (lever == 0)
	{
		//星図鑑オブジェクト生成
		CObjStarPicbook* p = new CObjStarPicbook();
		Objs::InsertObj(p, OBJ_STARPICBOOK, 9);
	}
	else if (lever == 1)
	{
		//みずがめ
		CObjStarPresent4* a = new CObjStarPresent4();
		Objs::InsertObj(a, OBJ_STARPRESENT4, 11);
	}
	else if (lever == 2)
	{
		//うお
		CObjStarPresent* s = new CObjStarPresent();
		Objs::InsertObj(s, OBJ_STARPRESENT, 10);
	}
	else if (lever == 3)
	{
		//ひつじ
		CObjStarPresent* s = new CObjStarPresent();
		Objs::InsertObj(s, OBJ_STARPRESENT, 10);
	}
	else if (lever == 4)
	{
		//うし座
		CObjStarPresent* s = new CObjStarPresent();
		Objs::InsertObj(s, OBJ_STARPRESENT, 10);
	}
	else if (lever == 5)
	{
		//ふたご座
		CObjStarPresent* s = new CObjStarPresent();
		Objs::InsertObj(s, OBJ_STARPRESENT, 10);
	}
	else if (lever == 6)
	{
		//かに座
		CObjStarPresent* s = new CObjStarPresent();
		Objs::InsertObj(s, OBJ_STARPRESENT, 10);
	}
	else if (lever == 7)
	{
		//かに座
		CObjStarPresent* s = new CObjStarPresent();
		Objs::InsertObj(s, OBJ_STARPRESENT, 10);
	}
	else if (lever == 8)
	{
		//おとめ座
		CObjStarPresent* s = new CObjStarPresent();
		Objs::InsertObj(s, OBJ_STARPRESENT, 10);
	}
	else if (lever == 9)
	{
		//天秤座
		CObjStarPresent* s = new CObjStarPresent();
		Objs::InsertObj(s, OBJ_STARPRESENT, 10);
	}
	else if (lever == 10)
	{
		//蠍座
		CObjStarPresent* s = new CObjStarPresent();
		Objs::InsertObj(s, OBJ_STARPRESENT, 10);
	}
	else if (lever == 11)
	{
		//射手座
		CObjStarPresent* s = new CObjStarPresent();
		Objs::InsertObj(s, OBJ_STARPRESENT, 10);
	}
	else if (lever == 12)
	{
		//山羊座
		CObjStarPresent* s = new CObjStarPresent();
		Objs::InsertObj(s, OBJ_STARPRESENT, 10);
	}
	else if (lever == 13)
	{
		//みずがめ座
		CObjStarmodel* a = new CObjStarmodel();
		Objs::InsertObj(a, OBJ_STARMODEL, 12);
	}
	else if (lever == 14)
	{
		//うお座
		CObjStarmodel* a = new CObjStarmodel();
		Objs::InsertObj(a, OBJ_STARMODEL, 12);
	}
	else if (lever == 15)
	{
		//ひつじ座
		CObjStarmodel* a = new CObjStarmodel();
		Objs::InsertObj(a, OBJ_STARMODEL, 12);
	}
	else if (lever == 16)
	{
		//うし座
		CObjStarmodel* a = new CObjStarmodel();
		Objs::InsertObj(a, OBJ_STARMODEL, 12);
	}
	else if (lever == 17)
	{
		//ふたご
		CObjStarmodel* a = new CObjStarmodel();
		Objs::InsertObj(a, OBJ_STARMODEL, 12);
	}
	else if (lever == 18)
	{
		//かに
		CObjStarmodel* a = new CObjStarmodel();
		Objs::InsertObj(a, OBJ_STARMODEL, 12);
	}
	else if (lever == 19)
	{
		//しし
		CObjStarmodel* a = new CObjStarmodel();
		Objs::InsertObj(a, OBJ_STARMODEL, 12);
	}
	else if (lever == 20)
	{
		//おとめ
		CObjStarmodel* a = new CObjStarmodel();
		Objs::InsertObj(a, OBJ_STARMODEL, 12);
	}
	else if (lever == 21)
	{
		//てんびん
		CObjStarmodel* a = new CObjStarmodel();
		Objs::InsertObj(a, OBJ_STARMODEL, 12);
	}
	else if (lever == 22)
	{
		//さそり
		CObjStarmodel* a = new CObjStarmodel();
		Objs::InsertObj(a, OBJ_STARMODEL, 12);
	}
	else if (lever == 23)
	{
		//いて
		CObjStarmodel* a = new CObjStarmodel();
		Objs::InsertObj(a, OBJ_STARMODEL, 12);
	}
	else if (lever == 24)
	{
		//やぎ
		CObjStarmodel* a = new CObjStarmodel();
		Objs::InsertObj(a, OBJ_STARMODEL, 12);
	}

}

//ゲームタイトル実行メソッド
void CSceneStarPicbook::Scene()
{

}