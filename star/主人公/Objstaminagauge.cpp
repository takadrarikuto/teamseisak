//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

#include"GameHead.h"
#include"Objstaminagauge.h"

//使用するネームスペース
using namespace GameL;

extern bool Event_on;
extern bool Aitem_on;
extern bool Star_Recovery;

//スタミナ→酸素変更

//イニシャライズ
void CObjstaminagauge::Init()
{
	Aitem_flag = true; //アイテムオブジェクトから引用初期化
	Aitem_co_max = 5;

	m_px = 697.0f;
	m_py = 571.0f;

	//表示用酸素初期化
	m_stamina = 100;

	//酸素最大値初期化
	m_stamina_max = 100;

	//全ての消費用初期化
	m_vx = 0.0f;

	//自然消費初期化
	m_vstamina = 0.0f;

	//アンカー使用時用初期化
	m_vancer = 0.0f;

	//秒数カウント初期化
	stamina_co = 0;
	//画面移動時起動防止用初期化
	time_co = 0;
	//酸素消費用初期化
	stamina_back = 0;

	//イベントカウント初期化
	Ev_time = 0;
}

//アクション
void CObjstaminagauge::Action()
{	
	time_co++;

	//酸素回復
	if (Aitem_on == true)
	{
		m_vx -= 30.0f; //酸素を30増やす
		m_stamina += 30;
		Aitem_on = false;
	}
	
	//体力減少処理
	stamina_co += 1;

	//5秒で1酸素減少
	if (stamina_co == 300)
	{
		m_vstamina += 1.0f;
		m_stamina -= 1;
		stamina_co = 0;
	}
	else
	{
		m_vstamina = 0.0f;
	}

	//特定の星を確保した時酸素回復
	if (Star_Recovery == true)
	{
		m_vx -= 10.0f;
		m_stamina += 10.0f;
		Star_Recovery = false;
	}

	//イベント時
	Ev_time = rand() % 5;

	//特定の条件で酸素の10%を減少
	if (Event_on == true && Ev_time == 4 && stamina_co == 150)
	{
		m_vstamina += m_px / m_stamina_max;
		m_stamina -= m_px / m_stamina_max;
	}
	
	//消費酸素が最大値、最小値を超えないようにする処理
	if (m_vx < 0.0f)
	{
		m_vx = 0.0f;
	}
	else if (m_vx > m_stamina_max)
	{
		m_vx = m_stamina_max;
	}

	//表示酸素が最大値、最小値を超えないようにする処理
	if (m_stamina < 0)
	{
		m_stamina = 0;
	}
	else if (m_stamina > m_stamina_max)
	{
		m_stamina = m_stamina_max;
	}
	
	//酸素が無くなると宇宙船へ
	if (m_vx == m_stamina_max)
	{
		Scene::SetScene(new CSceneTitle());
	}

	//酸素消費処理
	m_vx += m_vstamina + m_vancer;

}
//ドロー
void CObjstaminagauge::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	swprintf_s(str, L"%d/%d", m_stamina, m_stamina_max);
	Font::StrDraw(str, 580, 570, 30, c);

	//背景
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 70.0;
	src.m_right = 80.0f;
	src.m_bottom = 4.0f;

	//表示位置の設定
	dst.m_top = 6.0f + m_py;
	dst.m_left = 0.0f + m_px + m_vx;
	dst.m_right = 100.0f + m_px;
	dst.m_bottom = 22.0f + m_py;

	//描画
	Draw::Draw(22, &src, &dst, c, 0.0f);

}
