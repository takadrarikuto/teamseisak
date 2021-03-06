//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

extern bool EM_flag;
extern bool Event_Star;//イベント時星の移動方向変更
extern int Event_Conversion; //イベントエリア切り替え
extern bool Increase_flag; //イベント時星発生率変更用

//使用ヘッダー
#include "SceneJupiter.h"
#include "GameHead.h"
#include <stdlib.h> // rand()関数用
#include <time.h>   // time()関数用
#include <random>

std::random_device jrd{};
/**
 * 重み付けで抽選を行う
 * @param pArray 抽選する対象の配列
 * @param Length 配列のサイズ
 */
int CSceneJupiter::WeightedPick(int* pArray, int Length) {
	int totalWeight = 0;
	int pick = 0;

	// トータルの重みを計算する
	for (int i = 0; i < Length; i++) {
		totalWeight += pArray[i];
	}


	// 抽選する
	int rnd = jrd() % totalWeight;

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
void CSceneJupiter::InitScene()
{
	//音楽情報読み込み
	Audio::LoadAudio(0, L"ステージ画面.wav", BACK_MUSIC);

	Audio::Start(0);

	occur = 0;
	m_Pf = false;
	m_key_f = false;//行動制御

					
	//グラフィック読み込み
	//背景
	Draw::LoadImage(L"通常時背景.png", 8, TEX_SIZE_512);
	Draw::LoadImage(L"嵐_雷.png", 9, TEX_SIZE_512);
	Draw::LoadImage(L"木星.png", 10, TEX_SIZE_512);

	//主人公
	Draw::LoadImage(L"主人公.png", 11, TEX_SIZE_512);
	//アンカー
	Draw::LoadImage(L"飛距離測定用アンカー.png", 12, TEX_SIZE_512);
	Draw::LoadImage(L"アンカー（仮　透過済み）.png", 13, TEX_SIZE_512);

	//外部グラフィックを読み込み5番に登録(512×512ピクセル)
	Draw::LoadImage(L"yellow_star.png", 16, TEX_SIZE_512);
	Draw::LoadImage(L"red_star.png", 17, TEX_SIZE_512);
	Draw::LoadImage(L"pink_star.png", 18, TEX_SIZE_512);
	Draw::LoadImage(L"green_star.png", 19, TEX_SIZE_512);
	Draw::LoadImage(L"brown_star.png", 20, TEX_SIZE_512);
	Draw::LoadImage(L"blue_star.png", 24, TEX_SIZE_512);


	//ゲージ関係
	//体力
	Draw::LoadImage(L"ゲージ枠.png", 21, TEX_SIZE_512);
	Draw::LoadImage(L"ゲージ.png", 22, TEX_SIZE_512);

	//ビックリマーク
	Draw::LoadImage(L"ビックリマーク.png", 23, TEX_SIZE_512);


	//ポーズ背景
	Draw::LoadImage(L"ポーズ背景.png", 25, TEX_SIZE_512);



	//背景オブジェクト生成
	CObjBackground* obj_h = new CObjBackground();
	Objs::InsertObj(obj_h, OBJ_BACKGROUND, 8);
	CObjEvent* obj_i = new CObjEvent();
	Objs::InsertObj(obj_i, OBJ_EVENT, 9); //イベント背景	
	CObjMars* obj_m = new CObjMars();
	Objs::InsertObj(obj_m, OBJ_MARS, 10);

	//主人公オブジェクト生成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 11);

	//アンカーオブジェクト作成
	CObjMeasurementAncer* obj_ma = new CObjMeasurementAncer();
	Objs::InsertObj(obj_ma, OBJ_MANCER, 12);
	CObjAncer* obj_a = new CObjAncer();
	Objs::InsertObj(obj_a, OBJ_ANCER, 13);

	//アイテムオブジェクト生成
	CObjAitem* obj_ai = new CObjAitem();
	Objs::InsertObj(obj_ai, OBJ_AITEM, 14);

	//スターカウントオブジェクト作成
	CObjStarCount* obj_sc = new CObjStarCount();
	Objs::InsertObj(obj_sc, OBJ_STARCOUNT, 15);

	//ゲージ関係
	//スタミナオブジェクト作成
	CObjstaminagaugeframe* obj_stf = new CObjstaminagaugeframe();
	Objs::InsertObj(obj_stf, OBJ_STRENGTHGAUGEFRAME1, 21);
	CObjstaminagauge* obj_st = new CObjstaminagauge();
	Objs::InsertObj(obj_st, OBJ_STRENGTHGAUGE, 22);

	//ビックリマークオブジェクト作成
	CObjExclamationMark* obj_em = new CObjExclamationMark();
	Objs::InsertObj(obj_em, OBJ_EM, 23);


	//星生成時間初期化
	time_star = 0;

	//1等星作成警告用カウント初期化
	Star_time = 0.0f;
	//1等星作成警告用フラグ初期化
	Star_flag = false;

	Event_Star = false;
	Event_Conversion = 2;

	EM_flag = false; //ビックリマーク出現フラグ初期化

}

//実行中メゾット
void CSceneJupiter::Scene()
{

	CObjPose* pob = (CObjPose*)Objs::GetObj(OBJ_POSE);

	//ポーズ
	if (pob == nullptr)
		m_Pf = false;

	while (1)
	{
		if (Input::GetVKey('P') == true)//Pキー入力時
		{

			if (m_Pf == true) {//m_fがtrueの場合
							   //コマンド用SEを鳴らす


				while (1)
				{
					if (Input::GetVKey('B') == true) //Bキー入力時
					{
						Scene::SetScene(new CSceneStageselect());
						break;
					}
					if (Input::GetVKey('N') == true) //Nキー入力時
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
				Objs::InsertObj(po, OBJ_POSE, 100);    //ポーズオブジェクト登録
				m_Pf = true;

			}
			else {}
		}
		break;
	}
	occur++;
	//　0.75秒ごとに星を出現させる・イベント時は発生率1.5倍
	if (occur % 45 == 0 || Increase_flag == true && occur % 22 == 0)
	{
		//重み付けで出現させる星を決める
		int Items[] = { 1, 5, 20,40,60 };
		int result = WeightedPick(Items, 5);


		//1等星作成0.7%
		if (result == 0)
		{
			Star_flag = true; //1等星作成警告用フラグ オン
		}

		//2等星作成 3.9%
		if (result == 1)
		{
			if (Event_Star == false)
			{
				//スターオブジェクト作成
				CObjSecondStar* star2 = new CObjSecondStar(-32.0f);
				Objs::InsertObj(star2, OBJ_SECONDSTAR, 11);    //スターオブジェクト登録
			}
			else if (Event_Star == true)
			{
				//スターオブジェクト作成
				CObjSecondStar* star2 = new CObjSecondStar(790.0f);
				Objs::InsertObj(star2, OBJ_SECONDSTAR, 11);    //スターオブジェクト登録
			}
		}
		//3等星作成 15.8%
		if (result == 2)
		{
			if (Event_Star == false)
			{
				//スターオブジェクト作成
				CObjThirdStar* star3 = new CObjThirdStar(-32.0f);
				Objs::InsertObj(star3, OBJ_THIRDSTAR, 12);    //スターオブジェクト登録
			}
			else if (Event_Star == true)
			{
				//スターオブジェクト作成
				CObjThirdStar* star3 = new CObjThirdStar(790.0f);
				Objs::InsertObj(star3, OBJ_THIRDSTAR, 12);    //スターオブジェクト登録
			}
		}
		//4等星作成 31.7%
		if (result == 3)
		{
			if (Event_Star == false)
			{
				//スターオブジェクト作成
				CObjFourthStar* star4 = new CObjFourthStar(-32.0f);
				Objs::InsertObj(star4, OBJ_FOURTHSTAR, 13);    //スターオブジェクト登録
			}
			else if (Event_Star == true)
			{
				//スターオブジェクト作成
				CObjFourthStar* star4 = new CObjFourthStar(790.0f);
				Objs::InsertObj(star4, OBJ_FOURTHSTAR, 13);    //スターオブジェクト登録
			}
		}
		//5等星以下作成 47.6%
		if (result == 4)
		{
			if (Event_Star == false)
			{
				//スターオブジェクト作成
				CObjOtherStar* star5 = new CObjOtherStar(-32.0f);
				Objs::InsertObj(star5, OBJ_OTHERSTAR, 14);    //スターオブジェクト登録
			}
			else if (Event_Star == true)
			{
				//スターオブジェクト作成
				CObjOtherStar* star5 = new CObjOtherStar(790.0f);
				Objs::InsertObj(star5, OBJ_OTHERSTAR, 14);    //スターオブジェクト登録
			}
		}
	}

	//1等星作成時警告処理
	if (Star_flag == true)
	{
		Star_time++;
		EM_flag = true; //ビックリマーク出現フラグ オン
	}

	//5秒後1等星作成
	if (Star_time == 300.0f)
	{
		if (Event_Star == false)
		{
			//スターオブジェクト作成
			CObjFirstStar* star = new CObjFirstStar(-32.0f);
			Objs::InsertObj(star, OBJ_FIRSTSTAR, 10);    //スターオブジェクト登録
		}
		else if (Event_Star == true)
		{
			//スターオブジェクト作成
			CObjFirstStar* star = new CObjFirstStar(790.0f);
			Objs::InsertObj(star, OBJ_FIRSTSTAR, 10);    //スターオブジェクト登録
		}

		Star_time = 0.0f; //1等星作成警告用カウント初期化	
		Star_flag = false; //1等星作成警告用フラグ初期化
		EM_flag = false; //ビックリマーク出現フラグ初期化
	}


	if (Increase_flag == true && occur % 450 == 0)
	{
		if (Event_Star == false)
		{
			//ボーナススターオブジェクト作成
			CObjBonusStar* star6 = new CObjBonusStar(-32.0f);
			Objs::InsertObj(star6, OBJ_BONUSSTAR, 24);    //スターオブジェクト登録
		}
		else if (Event_Star == true)
		{
			//ボーナススターオブジェクト作成
			CObjBonusStar* star6 = new CObjBonusStar(790.0f);
			Objs::InsertObj(star6, OBJ_BONUSSTAR, 24);    //スターオブジェクト登録
		}

	}
	if (occur == 9000)
		occur = 0;

	

}

