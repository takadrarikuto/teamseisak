//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneSpaceShip.h"
#include "GameHead.h"

//コンストラクタ
CSceneSpaceShip::CSceneSpaceShip()
{

}

//デストラクタ
CSceneSpaceShip::~CSceneSpaceShip()
{

}

//初期化メゾット
void CSceneSpaceShip::InitScene()
{



}

//実行中メゾット
void CSceneSpaceShip::Scene()
{
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMars());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}