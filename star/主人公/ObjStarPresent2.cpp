//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjStarPresent.h"
extern int lever;


void CObjStarPresent::Init()
{
	page = 0;//次のページへ行くための変数
	page_flag = false;
	ver = 0;
	g = 200.0f;//星枠の横幅
	k = 75.0f;//星枠の立幅
	t = 70;//星の名前の位置
	l = 0;//tと掛ける用の変数
	s = 0;//星のクリックの鍵
	std = 0;
	side_a = 0;
	side_b = 200;
	size = 25;
	size_y = 30;
	font = 80;
	fy = 200;//星の名前の横幅
	font_size = 25;//文字の大きさ
	Interval_y = 35;//文字の立幅間隔
	left_end = 80;//説明文の左の限界を決める

}

void CObjStarPresent::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
}

void CObjStarPresent::Draw()
{
	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	wchar_t test[3][2]{ L"牡",L"牛",L"座"};

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//					　　	 X　 Y　 大きさ
	Font::StrDraw(L"アルデバラン", 10, 305, 15, c);

	// left				 right            top            bottom               
	if (m_mou_x > 0 && m_mou_x < 100 && m_mou_y>300 && m_mou_y <325)
	{
		Font::StrDraw(L"おうし座にに属する", 110, 0, 30, c);
		Font::StrDraw(L"一番明るい星", 110, 50, 30, c);
		//ループして出す
		for (int i = 0; i <=2; i++)
		{
			int l = 50;
			swprintf_s(str, L"%s", test[i]);
			//				　　X　 Y　 大きさ
			Font::StrDraw(str, 20, 100 + l*i, 50, c);
		}
	}

}