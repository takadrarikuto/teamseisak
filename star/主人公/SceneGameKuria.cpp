//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneGameKuria.h"
#include "GameHead.h"

//コンストラクタ
CSceneGameKuria::CSceneGameKuria()
{

}

//デストラクタ
CSceneGameKuria::~CSceneGameKuria()
{

}

//初期化メゾット
void CSceneGameKuria::InitScene()
{
	//音楽情報読み込み
	Audio::LoadAudio(0, L"ゲームクリア画面BGM.wav", BACK_MUSIC);


	//バックミュージックスタート
	Audio::Start(0);


	//外部グラフィック読み込み
	Draw::LoadImage(L"ゲームクリア.png", 11, TEX_SIZE_512);


	//タイトルオブジェクト生成
	CObjGameKuria* obj_t = new CObjGameKuria();
	Objs::InsertObj(obj_t, OBJ_GAMEKURIA, 11);
}

//実行中メゾット
void CSceneGameKuria::Scene()
{

}