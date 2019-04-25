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

	//星図鑑オブジェクト生成
	if(lever==0)
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
		CObjStarPresent5* a = new CObjStarPresent5();
		Objs::InsertObj(a, OBJ_STARPRESENT5, 11);
	}
	else if (lever == 3)
	{
		//ひつじ
		CObjStarPresent6* a = new CObjStarPresent6();
		Objs::InsertObj(a, OBJ_STARPRESENT6, 11);
	}
	else if (lever== 4)
	{
		//うし座
		CObjStarPresent2* a = new CObjStarPresent2();
		Objs::InsertObj(a, OBJ_STARPRESENT2, 11);
	}
	else if (lever == 5)
	{
		//ふたご座
		CObjStarPresent7* a = new CObjStarPresent7();
		Objs::InsertObj(a, OBJ_STARPRESENT7, 11);
	}
	else if (lever == 6)
	{
		//かに座
		CObjStarPresent8* a = new CObjStarPresent8();
		Objs::InsertObj(a, OBJ_STARPRESENT8, 11);
	}
	else if (lever == 7)
	{
		//かに座
		CObjStarPresent9* a = new CObjStarPresent9();
		Objs::InsertObj(a, OBJ_STARPRESENT9, 11);
	}
	else if (lever == 8)
	{
		//おとめ座
		CObjStarPresent10* a = new CObjStarPresent10();
		Objs::InsertObj(a, OBJ_STARPRESENT10, 11);
	}
	else if (lever == 9)
	{
		//天秤座
		CObjStarPresent3* a = new CObjStarPresent3();
		Objs::InsertObj(a, OBJ_STARPRESENT3, 11);
	}
	else if (lever == 10)
	{
		//星図鑑オブジェクト生成
		CObjStarPresent* s = new CObjStarPresent();
		Objs::InsertObj(s, OBJ_STARPRESENT, 10);
	}
	else if (lever == 11)
	{
		CObjStarmodel* a = new CObjStarmodel();
		Objs::InsertObj(a, OBJ_STARMODEL, 12);
	}
	else if (lever == 13)
	{
		//みずがめ座
	}
	else if (lever == 14)
	{
		//うお座
	}
	else if (lever == 15)
	{
		//ひつじ座
	}
	else if (lever == 16)
	{
		//うし座
	}
	else if (lever == 17)
	{
		//ふたご
	}
	else if (lever == 18)
	{
		//かに
	}
	else if (lever == 19)
	{
		//しし
	}
	else if (lever == 20)
	{
		//おとめ
	}
}

//ゲームタイトル実行メソッド
void CSceneStarPicbook::Scene()
{

}