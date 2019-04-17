//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMars.h"
#include "GameHead.h"



//初期化メゾット
void CSceneMars::InitScene()
{
	occur = 0;
	m_Pf = false;
	m_key_f = false;//行動制御

	//グラフィック読み込み
	//背景
	Draw::LoadImage(L"通常時背景.png", 8, TEX_SIZE_512);
	Draw::LoadImage(L"イベント背景(火星).png", 9, TEX_SIZE_512);
	Draw::LoadImage(L"火星地表.png", 10, TEX_SIZE_512);

	//主人公
	Draw::LoadImage(L"主人公.png", 11, TEX_SIZE_512);
	//アンカー
	Draw::LoadImage(L"アンカー（仮　透過済み）.png", 12, TEX_SIZE_512);

	//外部グラフィックを読み込み5番に登録(512×512ピクセル)
	Draw::LoadImage(L"星(透過済み).png", 13, TEX_SIZE_512);
	Draw::LoadImage(L"ドリンク候補2.png", 14, TEX_SIZE_512);
	Draw::LoadImage(L"brown_star.png", 16, TEX_SIZE_512);
	Draw::LoadImage(L"green_star.png", 19, TEX_SIZE_512);

	//ゲージ関係
	//体力
	Draw::LoadImage(L"ゲージ枠.png", 17, TEX_SIZE_512);
	Draw::LoadImage(L"ゲージ.png", 18, TEX_SIZE_512);

	//背景オブジェクト生成
	CObjBackground* obj_h = new CObjBackground();
	Objs::InsertObj(obj_h, OBJ_BACKGROUND, 8);
	CObjEvent* obj_i = new CObjEvent();
	Objs::InsertObj(obj_i, OBJ_EVENT, 9); //イベント背景	
	CObjMars* obj_m = new CObjMars();
	Objs::InsertObj(obj_m, OBJ_MARS, 10);

	//仮主人公オブジェクト生成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 11);

	//アンカーオブジェクト作成
	CObjAncer* obj_a = new CObjAncer();
	Objs::InsertObj(obj_a, OBJ_ANCER, 12);

	//アイテムオブジェクト生成
	CObjAitem* obj_ai = new CObjAitem();
	Objs::InsertObj(obj_ai, OBJ_AITEM, 14);

	//スターカウントオブジェクト作成
	CObjStarCount* obj_sc = new CObjStarCount();
	Objs::InsertObj(obj_sc, OBJ_STARCOUNT, 15);

	//ゲージ関係
	//スタミナオブジェクト作成
	CObjstaminagaugeframe* obj_stf = new CObjstaminagaugeframe();
	Objs::InsertObj(obj_stf, OBJ_STRENGTHGAUGEFRAME1, 17);
	CObjstaminagauge* obj_st = new CObjstaminagauge();
	Objs::InsertObj(obj_st, OBJ_STRENGTHGAUGE, 18);
	

	//星生成時間初期化
	time_star = 0;

}

//実行中メゾット
void CSceneMars::Scene()
{
	CObjPose* pob = (CObjPose*)Objs::GetObj(OBJ_POSE);

	//ポーズ
	if (pob == nullptr)
		m_Pf = false;

	while (1)
	{
		if (Input::GetVKey('P') == true)//Mキー入力時
		{

			if (m_Pf == true) {//m_fがtrueの場合
							   //コマンド用SEを鳴らす					
				while (1)
				{
					if (Input::GetVKey('Z') == true)
					{
						Scene::SetScene(new CSceneTitle());
						break;
					}

					if (Input::GetVKey('X') == true)//Xキー入力時
					{
						if (m_Pf == true) 
						{
							Sleep(1);
							//ポーズオブジェクトを削除
							if (pob != nullptr)
								pob->SetAf(true);
							break;
						}
					}
				}
			
			}

			if (m_Pf == false) {
				//ポーズオブジェクト作成
				CObjPose* po = new CObjPose();       //ポーズオブジェクト作成
				Objs::InsertObj(po, OBJ_POSE, 11);    //ポーズオブジェクト登録
				m_Pf = true;

			}
			else {}
		}
		break;
	}
	occur++;
	arise = rand() % 10;

	if (occur == 60)
	{
		if (arise < 2 && arise > 0)
		{
			//スターオブジェクト作成
			CObjFirstStar* star = new CObjFirstStar();
			Objs::InsertObj(star, OBJ_FIRSTSTAR, 13);    //スターオブジェクト登録
		}


		if (arise < 3 && arise > 1)
		{
			//スターオブジェクト作成
			CObjSecondStar* star2 = new CObjSecondStar();
			Objs::InsertObj(star2, OBJ_SECONDSTAR, 16);    //スターオブジェクト登録
		}
		if (arise < 4 && arise > 2)
		{
			//スターオブジェクト作成
			CObjOtherStar* star3 = new CObjOtherStar();
			Objs::InsertObj(star3, OBJ_OTHERSTAR, 19);    //スターオブジェクト登録
		}
		occur = 0;
	}

}