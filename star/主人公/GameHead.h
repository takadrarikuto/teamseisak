#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_HERO,
	OBJ_ANCER,
	OBJ_TIME,
	OBJ_TITLE,
	OBJ_STAGESELECT,
	OBJ_STAGESELECTPLANET,
	OBJ_ENEMY,
	OBJ_OBJECT,
	OBJ_STARPICBOOK,
	OBJ_MARS,
	OBJ_FIRSTSTAR,
	OBJ_SECONDSTAR,
	OBJ_OTHERSTAR,
	OBJ_OPERATION,
	OBJ_STAGE,
	OBJ_GAMEKURIA,
};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_ANCER,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
	
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include "ObjHero.h"
#include "ObjTitle.h"
#include "ObjStageselect.h"
#include "ObjSelectPlanet.h"
#include "CObjStarPicbook.h"
#include "ObjMars.h"
#include "ObjAncer.h"
#include "ObjFirstStar.h"
#include "Objstage.h"
#include "CObjOperation.h"
#include "ObjGamekuria.h"

//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "SceneMar.h"
#include "SceneTitle.h"
#include "SceneStageselect.h"
#include "SceneStarPicbook.h"
#include "SceneMars.h"
#include "SceneOperation.h"
#include "SceneGamekuria.h"
//------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
//#define SET_GAME_START  CSceneMain
//#define SET_GAME_START CSceneOperation
//#define SET_GAME_START  CSceneStarPicbook
//#define SET_GAME_START CSceneTitle
#define SET_GAME_START CSceneGameKuria
//-----------------------------------------------