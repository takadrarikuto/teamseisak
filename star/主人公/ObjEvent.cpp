//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjEvent.h"

//使用するネームスペース
using namespace GameL;

bool Event_on = false; //イベント開始
bool Event_Star = false; //イベント時星の移動方向変更
int Event_Conversion = 0; //イベントエリア切り替え

//イニシャライズ
void CObjEvent::Init()
{
	//イベントスタートフラグ初期化
	E_Start = false;
	//イベントスタートカウント初期化
	E_Start_co = 0;

	//背景操作用初期化
	m_x1 = 0.0f;
	m_x2 = 800.0f;
	m_y1 = 0.0f;
	m_y2 = 600.0f;

}

//アクション
void CObjEvent::Action()
{

	//背景移動処理
	if (Event_Conversion == 0)
	{
		m_x1 -= 10.0f;
		if (m_x1 < -800.0f)
		{
			m_x1 = 790.0f;
		}

		m_x2 -= 10.0f;
		if (m_x2 < -800.0f)
		{
			m_x2 = 790.0f;
		}
	}
	else if (Event_Conversion == 1)
	{
		m_y1 += 10.0f;
		if (m_y1 > 500.0f)
		{
			m_y1 = -500.0f;
		}

		m_y2 += 10.0f;
		if (m_y2 > 500.0f)
		{
			m_y2 = -500.0f;
		}
	}
	else if (Event_Conversion == 2)
	{
		m_x1 -= 10.0f;
		if (m_x1 < -800.0f)
		{
			m_x1 = 790.0f;
		}

		m_x2 -= 10.0f;
		if (m_x2 < -800.0f)
		{
			m_x2 = 790.0f;
		}
	}
	else if (Event_Conversion == 3)
	{
		m_x1 += 10.0f;
		if (m_x1 > 800.0f)
		{
			m_x1 = -790.0f;
		}

		m_x2 += 10.0f;
		if (m_x2 > 800.0f)
		{
			m_x2 = -790.0f;
		}
	}
	
	E_Start_co++;

	//ステージ別で開始時間と終了時間を変更
	if (Event_Conversion == 0)
	{
		//イベント開始処理
		if (E_Start_co == 3600)
		{
			E_Start = true;
			Event_on = true;
			Event_Star = true;
			E_Start_co++;
		}
		//イベント終了処理
		else if (E_Start_co == 4200)
		{
			E_Start = false;
			Event_on = false;
			Event_Star = false;
			E_Start_co = 0;
		}
	}
	else if (Event_Conversion == 1)
	{
		//イベント開始処理
		if (E_Start_co == 3000)
		{
			E_Start = true;
			Event_on = true;
			Event_Star = true;
			E_Start_co++;
		}
		//イベント終了処理
		else if (E_Start_co == 3600)
		{
			E_Start = false;
			Event_on = false;
			Event_Star = false;
			E_Start_co = 0;
		}
	}
	else if (Event_Conversion == 2)
	{
		//イベント開始処理
		if (E_Start_co == 2400)
		{
			E_Start = true;
			Event_on = true;
			Event_Star = true;
			E_Start_co++;
		}
		//イベント終了処理
		else if (E_Start_co == 3600)
		{
			E_Start = false;
			Event_on = false;
			Event_Star = false;
			E_Start_co = 0;
		}
	}
	else if (Event_Conversion == 3)
	{
		//イベント開始処理
		if (E_Start_co == 900)
		{
			E_Start = true;
			Event_on = true;
			Event_Star = true;
			E_Start_co++;
		}
		//イベント終了処理
		else if (E_Start_co == 1800)
		{
			E_Start = false;
			Event_on = false;
			Event_Star = false;
			E_Start_co = 0;
		}
	}


	
}
//ドロー
void CObjEvent::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//背景
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//火星
	if (Event_Conversion == 0)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 640.0f;
		src.m_bottom = 480.0f;

		//表示位置の設定
		dst.m_top = 0.0f;
		dst.m_left = 0.0f + m_x1;
		dst.m_right = 800.0f + m_x1;
		dst.m_bottom = 500.0f;

		if (E_Start == true)
		{
			//描画
			Draw::Draw(9, &src, &dst, c, 0.0f);
		}

		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 640.0f;
		src.m_bottom = 480.0f;

		//表示位置の設定
		dst.m_top = 0.0f;
		dst.m_left = 0.0f + m_x2;
		dst.m_right = 800.0f + m_x2;
		dst.m_bottom = 500.0f;

		if (E_Start == true)
		{
			//描画
			Draw::Draw(9, &src, &dst, c, 0.0f);
		}
	}
	//金星
	else if (Event_Conversion == 1)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 640.0f;
		src.m_bottom = 480.0f;

		//表示位置の設定
		dst.m_top = 0.0f + m_y1;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 500.0f + m_y1;

		if (E_Start == true)
		{
			//描画
			Draw::Draw(9, &src, &dst, c, 0.0f);
		}

		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 640.0f;
		src.m_bottom = 480.0f;

		//表示位置の設定
		dst.m_top = 0.0f + m_y2;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 500.0f + m_y2;

		if (E_Start == true)
		{
			//描画
			Draw::Draw(9, &src, &dst, c, 0.0f);
		}

	}
	//木星
	else if (Event_Conversion == 2)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 1000.0f;
		src.m_bottom = 1000.0f;

		//表示位置の設定
		dst.m_top = 0.0f;
		dst.m_left = 0.0f + m_x1;
		dst.m_right = 800.0f + m_x1;
		dst.m_bottom = 500.0f;

		if (E_Start == true)
		{
			//描画
			Draw::Draw(9, &src, &dst, c, 0.0f);
		}

		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 1000.0f;
		src.m_bottom = 1000.0f;

		//表示位置の設定
		dst.m_top = 0.0f;
		dst.m_left = 0.0f + m_x2;
		dst.m_right = 800.0f + m_x2;
		dst.m_bottom = 500.0f;

		if (E_Start == true)
		{
			//描画
			Draw::Draw(9, &src, &dst, c, 0.0f);
		}

	}
	//土星
	else if (Event_Conversion == 3)
	{
		//切り取り位置の設定
		src.m_top = 90.0f;
		src.m_left = 0.0f;
		src.m_right = 400.0f;
		src.m_bottom = 310.0f;

		//表示位置の設定
		dst.m_top = 0.0f;
		dst.m_left = 0.0f + m_x1;
		dst.m_right = 800.0f + m_x1;
		dst.m_bottom = 500.0f;

		if (E_Start == true)
		{
			//描画
			Draw::Draw(9, &src, &dst, c, 0.0f);
		}

		//切り取り位置の設定
		src.m_top = 90.0f;
		src.m_left = 0.0f;
		src.m_right = 400.0f;
		src.m_bottom = 310.0f;

		//表示位置の設定
		dst.m_top = 0.0f;
		dst.m_left = 0.0f + m_x2;
		dst.m_right = 800.0f + m_x2;
		dst.m_bottom = 500.0f;

		if (E_Start == true)
		{
			//描画
			Draw::Draw(9, &src, &dst, c, 0.0f);
		}

	}
}
