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
#include "SceneTitle.h"
#include "GameHead.h"

//コンストラクタ
CSceneTitle::CSceneTitle()
{

}

//デストラクタ
CSceneTitle::~CSceneTitle()
{

}

//初期化メゾット
void CSceneTitle::InitScene()
{
	//音楽情報読み込み
	/*Audio::LoadAudio(0, L"ゲームプレイBGMTitle.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(1, L"SETrigger.wav", EFFECT);

	//バックミュージックスタート
	float Volume = Audio::VolumeMaster(-0.8f);
	Audio::Start(0);*/

	//グラフィック読み込み
	Draw::LoadImage(L"タイトル(修正版).png", 11, TEX_SIZE_512);

	//タイトルオブジェクト生成
	CObjTitle* obj_t = new CObjTitle();
	Objs::InsertObj(obj_t, OBJ_TITLE, 11);

}

//実行中メゾット
void CSceneTitle::Scene()
{

}