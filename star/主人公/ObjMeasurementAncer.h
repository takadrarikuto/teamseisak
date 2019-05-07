#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

#define Ancer_InitialTime (0.0f) //アンカー・ロープ共通初期値


//使用するネームスペース
using namespace GameL;

//オブジェクト　アンカー
class CObjMeasurementAncer : public CObj
{
public:
	CObjMeasurementAncer() {};
	~CObjMeasurementAncer() {};

	void Init();
	void Action();
	void Draw();

private:

	//位置
	float m_pafx; //飛距離測定用アンカー
	float m_pafy;
	//アンカーサイズ変更用
	float m_sizex;
	float m_sizey;
	float size;
	float hitbox_size; //ヒットボックスサイズ調整用

	//移動ベクトル
	float m_vfx; //飛距離測定用アンカー
	float m_vfy;

	bool m_mous_l;
	int time_co; //画面移動時起動防止用
	float ancer_time; //アンカー飛距離調整

	bool ancer_flag; //アンカー移動フラグ
	bool ancer_Prevent_doublepress; //連続発射防止フラグ

	bool Ancer_flag; //飛距離測定用アンカー作成

};