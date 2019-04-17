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
#include <random>
#include <stdlib.h> // rand()関数用
#include <time.h>   // time()関数用

std::random_device rd{};

/**
 * 重み付けで抽選を行う
 * @param pArray 抽選する対象の配列
 * @param Length 配列のサイズ
 */
int WeightedPick(int* pArray, int Length) {
	int totalWeight = 0;
	int pick = 0;

	// トータルの重みを計算する
	for (int i = 0; i < Length; i++) {
		totalWeight += pArray[i];
	}


	// 抽選する
	int rnd = rd() % totalWeight;

	for (int i = 0; i < Length; i++) {
		if (rnd < pArray[i]) {
			// 抽選対象決定
			pick = i;
			break;
		}

		// 次の対象を調べる
		rnd -= pArray[i];
	}

	return pick;
}

//初期化メゾット
void CSceneMars::InitScene()
{
	occur = 0;
	m_Pf = false;
	m_key_f = false;//行動制御

	//グラフィック読み込み
	//背景
	Draw::LoadImage(L"通常時背景.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"イベント背景(火星).png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"火星地表.png", 3, TEX_SIZE_512);

	//主人公
	Draw::LoadImage(L"主人公.png", 4, TEX_SIZE_512);
	//アンカー
	Draw::LoadImage(L"アンカー（仮　透過済み）.png", 5, TEX_SIZE_512);

	//ゲージ関係
	//体力
	Draw::LoadImage(L"ゲージ枠.png", 6, TEX_SIZE_512);
	Draw::LoadImage(L"ゲージ.png", 7, TEX_SIZE_512);
	//外部グラフィックを読み込み5番に登録(512×512ピクセル)
	Draw::LoadImage(L"ドリンク候補2.png", 8, TEX_SIZE_512);
	Draw::LoadImage(L"yellow_star.png", 10, TEX_SIZE_512);
	Draw::LoadImage(L"red_star.png", 11, TEX_SIZE_512);
	Draw::LoadImage(L"pink_star.png", 12, TEX_SIZE_512);
	Draw::LoadImage(L"green_star.png", 13, TEX_SIZE_512);
	Draw::LoadImage(L"brown_star.png", 14, TEX_SIZE_512);




	//背景オブジェクト生成
	CObjBackground* obj_h = new CObjBackground();
	Objs::InsertObj(obj_h, OBJ_BACKGROUND, 1);
	CObjEvent* obj_i = new CObjEvent();
	Objs::InsertObj(obj_i, OBJ_EVENT, 2); //イベント背景	
	CObjMars* obj_m = new CObjMars();
	Objs::InsertObj(obj_m, OBJ_MARS, 3);

	//仮主人公オブジェクト生成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 4);

	//アンカーオブジェクト作成
	CObjAncer* obj_a = new CObjAncer();
	Objs::InsertObj(obj_a, OBJ_ANCER, 5);

	//アイテムオブジェクト生成
	CObjAitem* obj_ai = new CObjAitem();
	Objs::InsertObj(obj_ai, OBJ_AITEM, 6);

	//スターカウントオブジェクト作成
	CObjStarCount* obj_sc = new CObjStarCount();
	Objs::InsertObj(obj_sc, OBJ_STARCOUNT, 7);

	//ゲージ関係
	//スタミナオブジェクト作成
	CObjstaminagaugeframe* obj_stf = new CObjstaminagaugeframe();
	Objs::InsertObj(obj_stf, OBJ_STRENGTHGAUGEFRAME1, 8);
	CObjstaminagauge* obj_st = new CObjstaminagauge();
	Objs::InsertObj(obj_st, OBJ_STRENGTHGAUGE, 9);
	

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

	if (occur == 180)
	{
		int Items[] = { 1, 5, 20,40,60 };
		int result = WeightedPick(Items, 5);


		//1等星作成0.7%
		if (result == 0)
		{
			
			CObjFirstStar* star = new CObjFirstStar();
			Objs::InsertObj(star, OBJ_FIRSTSTAR, 10);    //スターオブジェクト登録
		}
		
		//2等星作成 3.9%
		if (result == 1)
		{
			//スターオブジェクト作成
			CObjSecondStar* star2 = new CObjSecondStar();
			Objs::InsertObj(star2, OBJ_SECONDSTAR, 11);    //スターオブジェクト登録
		}
		//3等星作成 15.8%
		if (result == 2)
		{
			//スターオブジェクト作成
			CObjThirdStar* star3 = new CObjThirdStar();
			Objs::InsertObj(star3, OBJ_THIRDSTAR, 12);    //スターオブジェクト登録
		}
		 //4等星作成 31.7%
		if (result == 3)
		{
			//スターオブジェクト作成
			CObjFourthStar* star4 = new CObjFourthStar();
			Objs::InsertObj(star4, OBJ_FOURTHSTAR, 13);    //スターオブジェクト登録
		}
		//5等星以下作成 47.6%
		if (result == 4)
		{
			//スターオブジェクト作成
			CObjOtherStar* star5 = new CObjOtherStar();
			Objs::InsertObj(star5, OBJ_OTHERSTAR, 14);    //スターオブジェクト登録
		}
		occur = 0;
	}

}