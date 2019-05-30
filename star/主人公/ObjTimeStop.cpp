//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjTimeStop.h"

//使用するネームスペース
using namespace GameL;

extern bool Event_Star;//イベント時星の移動方向変更
extern int Event_Conversion; //イベントエリア切り替え
extern int star_count;


//イニシャライズ
void CObjTimeStop::Init()
{
	m_px = rand() % 650 + 50;
	m_py = 1;
	m_vx = 0.0f;
	m_vy = 2.0f;

	hero_flag = false;
	ancer_flag = false;


	Hits::SetHitBox(this, m_px, m_py, 32, 32, OBJ_TIMESTOP, ELEMENT_RED, 12);


}

//アクション
void CObjTimeStop::Action()
{


	m_px += m_vx;
	m_py += m_vy;


	//自身のHitBoxを持ってくる
	CHitBox* hit_s = Hits::GetHitBox(this);

	//HitBoxの位置の変更
	hit_s->SetPos(m_px, m_py);


		//主人公の当たり判定に当たると主人公フラグをtrueにし、星の数をカウント
		if (hit_s->CheckObjNameHit(OBJ_HERO) != nullptr || hit_s->CheckObjNameHit(OBJ_ANCER) != nullptr)
		{
			this->SetStatus(false); //自身に削除命令を出す
			Hits::DeleteHitBox(this); //HitBox削除

			stop_flag = true;
			hero_flag = false;
		}

	//アンカーに当たっていなければy軸が350の位置で停止

		if (m_py > 520.0f)
		{
			m_vy = 0;
		}



}
//ドロー
void CObjTimeStop::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	 //切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 100.0f;
	src.m_bottom = 100.0f;


	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px;
	dst.m_right = 32.0f + m_px;
	dst.m_bottom = 32.0f + m_py;

	//描画
	Draw::Draw(25, &src, &dst, c, 0.0f);
}
