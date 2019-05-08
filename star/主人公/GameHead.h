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
	OBJ_SATURN,
	OBJ_VENUS,
	OBJ_JUPITER,
	OBJ_FIRSTSTAR,
	OBJ_SECONDSTAR,
	OBJ_THIRDSTAR,
	OBJ_FOURTHSTAR,
	OBJ_OTHERSTAR,
	OBJ_OPERATION,
	OBJ_BACKGROUND,
	OBJ_GAMEKURIA,
	OBJ_STARPRESENT,
	OBJ_STARPRESENT2,
	OBJ_STARPRESENT3,
	OBJ_STARPRESENT4,
	OBJ_STARPRESENT5,
	OBJ_STARPRESENT6,
	OBJ_STARPRESENT7,
	OBJ_STARPRESENT8,
	OBJ_STARPRESENT9,
	OBJ_STARPRESENT10,
	OBJ_AITEM,
	OBJ_EVENT,
	OBJ_IBENT,
	OBJ_STARCOUNT,
	OBJ_STRENGTHGAUGE,
	OBJ_STRENGTHGAUGEFRAME1,
	OBJ_STRENGTHGAUGEFRAME2,
	OBJ_POSE,
	OBJ_QTE,
	OBJ_STARMODEL,
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
	int star_co;//星の数カウント
	int Aitem_co_max = 5; //アイテム個数

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
#include "ObjMars.h"
#include "ObjJupiter.h"
#include "ObjVenus.h"
#include "ObjSaturn.h"
#include "ObjAncer.h"
#include "ObjFirstStar.h"
#include "ObjSecondStar.h"
#include "ObjThirdStar.h"
#include "ObjFourthStar.h"
#include "ObjOtherStar.h"
#include "ObjBackground.h"
#include "ObjOperation.h"
#include "ObjGamekuria.h"
#include "CObjStarPicbook.h"
#include "ObjStarPresent.h"
#include "ObjStarPresent2.h"
#include "ObjStarPresent3.h"
#include "ObjStarPresent4.h"
#include "ObjStarPresent5.h"
#include "ObjStarPresent6.h"
#include "ObjStarPresent7.h"
#include "ObjStarPresent8.h"
#include "ObjStarPresent9.h"
#include "ObjStarPresent10.h"
#include "ObjAitem.h"
#include "ObjEvent.h"
#include "ObjStarCount.h"
#include "Objstaminagauge.h"
#include "Objstaminagaugeframe.h"
#include "ObjPose.h"
#include "ObjStarmodel.h"

//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "SceneTitle.h"
#include "SceneStageselect.h"
#include "SceneStarPicbook.h"
#include "SceneMars.h"
#include "SceneJupiter.h"
#include "SceneVenus.h"
#include "SceneSaturn.h"
#include "SceneOperation.h"
#include "SceneGamekuria.h"
//------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START CSceneTitle

//-----------------------------------------------