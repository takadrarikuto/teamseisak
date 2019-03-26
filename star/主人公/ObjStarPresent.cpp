//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "ObjStarPresent.h"
#include "GameHead.h"

void CObjStarPresent::Init()
{

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
	char test[10]{'蠍','座'};
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	Font::StrDraw(L"アンタレス", 10, 305, 15, c);

	// left				 right            top            bottom               
	if (m_mou_x > 0 && m_mou_x < 100 && m_mou_y>300 && m_mou_y <325)
	{
		Font::StrDraw(L"さそり座に属する", 110, 0, 30, c);
		for (int i = 0; i <= 10; i++)
		{
			//Font::StrDraw(test[i], 110, 0, 30, c);
		}
	}

}