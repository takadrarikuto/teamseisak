//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjStarPresent2.h"
extern int lever;


void CObjStarPresent2::Init()
{

}

void CObjStarPresent2::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
}

void CObjStarPresent2::Draw()
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