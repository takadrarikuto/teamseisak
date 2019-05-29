// STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneOperation.h"
#include "GameHead.h"

//コンストラクタ
CSceneOperation::CSceneOperation()
{

}

//デストラクタ
CSceneOperation::~CSceneOperation()
{

}

//ゲームメイン初期化メソッド
void CSceneOperation::InitScene()
{
	//音楽情報読み込み
	Audio::LoadAudio(0, L"操作画面BGM .wav", BACK_MUSIC);


	//バックミュージックスタート
	Audio::Start(0);

	
	//外部グラフィック読み込み
	Draw::LoadImage(L"ゲーム操作.png", 17, TEX_SIZE_512);
	
	CObjOperation* obj_o = new CObjOperation();
	Objs::InsertObj(obj_o, OBJ_OPERATION, 17);

}

//ゲームメイン実行中メソッド
void CSceneOperation::Scene()
{

}