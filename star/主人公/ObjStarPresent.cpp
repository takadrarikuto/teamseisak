//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjStarPresent.h"
extern int lever;
int crick = 0;
int cenge = 0;


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
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置
	//ブラックタイルの切り取り
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1039.0f;
	src.m_bottom = 469.0f;

	//星座の枠を描画
	dst.m_top = 300.0f;
	dst.m_left = 0.0f;
	dst.m_right = 200.0f;
	dst.m_bottom = 350.0f;
	int g = 200.0f;//星枠の横幅
	int k = 75.0f;//星枠の立幅
	int t = 70;//星の名前の位置
	int l = 0;//tと掛ける用の変数
	int s = 0;//星のクリックの鍵
	int std = 0;
	int side_a = 0;
	int side_b = 200;

	//ループして描画する
	for (int i = 0; i <= 3; i++)
	{
	//星の名前の枠を描画
	dst.m_top = 300.0f;
	dst.m_left = 0.0f +g*i;
	dst.m_right = 200.0f + g*i;
	dst.m_bottom = 300.0f+k;
	Draw::Draw(1, &src, &dst, c, 0.0f);

	for (int l = 0; l <=2; l++)
	{
		
		dst.m_top = 375.0f+k*l;
		dst.m_bottom =450.0f+k*l;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}
	
	}
	
	//戻るボタンの枠を描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 67.0f;
	dst.m_bottom = 100.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);

	//次のページに行くためのボタンの枠を描画
	dst.m_top = 200.0f;
	dst.m_bottom = 300.0f;

	//次への枠
	Draw::Draw(1, &src, &dst, c, 0.0f);
	dst.m_top = 100.0f;
	dst.m_bottom = 200.0f;

	//戻すの枠
	Draw::Draw(1, &src, &dst, c, 0.0f);

	//宇宙船への文字を描画する
	//					　　X　Y　大きさ
	Font::StrDraw(L"宇宙", 10, 25, 25, c);
	Font::StrDraw(L"船へ", 10, 50, 25, c);

	//戻るボタン
	// left				 right            top            bottom         
	if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>0 && m_mou_y < 100)
	{
		if (m_mou_l == true)
		{
			lever = 0;
			Scene::SetScene(new CSceneStageselect());
		}
	}
	//ｂを押すと戻る
	else if (Input::GetVKey('B') == true)
	{
		lever = 0;
		Scene::SetScene(new CSceneStageselect());
	}

	//次への文字をループして出す
	wchar_t next[2][2]{ L"次",L"へ" };
	for (int i = 0; i <= 1; i++)
	{
		int l = 25;
		swprintf_s(str, L"%s", next[i]);
		//				　　X　 Y　 大きさ
		Font::StrDraw(str, 20, 130 + l * i, 25, c);
	}
	//戻るを押したらStarPresentに切り替える
	// left				 right            top            bottom       
	if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>190 && m_mou_y < 300)
	{
	if (m_mou_l == true)
	{
	lever = 0;
	Scene::SetScene(new CSceneStarPicbook());
	}
	}
	//戻すの文字をループして出す
	wchar_t before[2][2]{ L"戻",L"る" };
	for (int i = 0; i <= 1; i++)
	{
		int l = 25;
		swprintf_s(str, L"%s", before[i]);

		//				　　X　 Y　 大きさ
		Font::StrDraw(str, 20, 230 + l * i, 25, c);
	}
	//次へを押したらStarPresent2に切り替える
	// left				 right            top            bottom       
	/*if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>100 && m_mou_y <200)
	{
		if (m_mou_l == true)
		{
			lever =1;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}*/

	//					　　	 X　 Y　 大きさ
	Font::StrDraw(L"アンタレス", 30, 330+t*l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
	if (m_mou_l == true)
	{
		
	crick = 1;
	}
	}

	if (crick == 1)
	{
		Font::StrDraw(L"さそり座に属する", 110, 0, 30, c);
		Font::StrDraw(L"一番明るい星", 110, 50, 30, c);
	}

	//					　　	 X　 Y　 大きさ
	Font::StrDraw(L"アクラブ", 30, 330+t*l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 2;
		}
	}

	if (crick == 2)
	{
		Font::StrDraw(L"さそり座に属する", 110, 0, 30, c);
		Font::StrDraw(L"六重連星で、小型望遠鏡で3等星のβ1星と5等星のβ2星の2星に見える。", 110, 50, 30, c);
		Font::StrDraw(L"β2星はβ星Cとβ星Eから形成され、さらにβ星Eはβ星Eaとβ星Ebから形成される", 110, 100, 30, c);
	}

	Font::StrDraw(L"ジュバ", 30+220, 330 + t * l, 30, c);
	l++;
	std = 1;
	// left				 right            top            bottom               
	if (m_mou_x > side_a+side_b*std && m_mou_x < side_b*(std+1) && m_mou_y>300 + k * (l-1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 3;
		}
	}

	if (crick == 3)
	{
		Font::StrDraw(L"さそり座に属する", 110, 0, 30, c);
		Font::StrDraw(L"通常のB型の恒星と考えられていたが、2000年6月頃に増光し、", 110, 50, 30, c);
		Font::StrDraw(L"そのスペクトルがBe星のものへと変貌したことが観測された。", 110, 100, 30, c);
	}
}