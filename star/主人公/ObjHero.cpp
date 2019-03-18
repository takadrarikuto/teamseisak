//使用するヘッダーファイル
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjHero.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjHero::Init()
{
	//主人公位置初期化
	m_px = 400.0f;
	m_py = 520.0f;
	//アンカー位置初期化
	m_ax = 450.0f;
	m_ay = 520.0f;

	//移動ベクトル初期化
	m_vx = 0.0f;

	//主人公向き初期化
	m_pos = 3.0f;

	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレームを初期にする

	m_return_flag = false;

	//当たり判定用のHitBoxを作成

	//主人公
	Hits::SetHitBox(this, m_px, m_py, 50, 50, ELEMENT_PLAYER, OBJ_HERO, 10);
	//アンカー本体
	//Hits::SetHitBox(this, m_px + 50.0f, m_py, 20, 50, ELEMENT_ANCER, OBJ_ANCER, 10);

}

//アクション
void CObjHero::Action()
{
	//移動ベクトル破棄
	m_vx = 0.0f;

	//主人公向き固定
	m_pos = 3.0f;


	//移動処理
	//左
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= 4.0f;
		m_pos = 1.0f;
		m_ani_time += 1;
	}
	//右
	else if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += 4.0f;
		m_pos = 2.0f;
		m_ani_time += 1;
	}
	else
	{
		m_ani_time = 0; //アニメーション停止
		m_ani_frame = 1; //キー入力が無い場合は静止フレームにする
	}

	//ステージ選択画面に戻る
	if (Input::GetVKey('B') == true)
	{
		if (m_return_flag = true)
		{
			Scene::SetScene(new CSceneStageselect());
		}
	}
	else
	{
		m_return_flag = true;
	}

	//アイテム使用
	if (Input::GetVKey('A') == true)
	{

	}

	//現在所持している星の数確認画面に移動
	if (Input::GetVKey('S') == true)
	{

	}

	//ポーズへ移動
	if (Input::GetVKey(VK_SPACE) == true)
	{

	}

	if (m_ani_time > 4)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//位置更新
	m_px += m_vx;

	//画面外に出ない処理
	if (m_px < 0.0f)
	{
		m_px = 0.0f;
	}
	if (m_px + 50.0f > 777.0f)
	{
		m_px = 777.0f - 50.0f;
	}

	//自身のHitBoxを持ってくる
	CHitBox* hit = Hits::GetHitBox(this);

	//HitBoxの位置の変更
	hit->SetPos(m_px, m_py);

}

//ドロー
void CObjHero::Draw()
{
	//モーション
	int AniData[4]=
	{
		1,0,2,0,
	};

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の位置
	src.m_top = (65.0f* m_pos);
	src.m_left = 0.0f + AniData[m_ani_frame] * 64;
	src.m_right = 60.0f + AniData[m_ani_frame] * 64;
	src.m_bottom = (65 + 65.0f *m_pos);

	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f  + m_px;
	dst.m_right = 50.0f + m_px;
	dst.m_bottom = 50.0f + m_py;

	Draw::Draw(10, &src, &dst, c, 0.0f);
}