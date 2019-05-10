//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjStarPresent4.h"
extern int lever;
extern int crick;
extern int cenge;


void CObjStarPresent4::Init()
{

}

void CObjStarPresent4::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();


}

void CObjStarPresent4::Draw()
{
	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置
	//パステルブルータイルの切り取り
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 130.0f;
	src.m_bottom = 67.0f;

	//星座の枠を描画
	dst.m_top = 300.0f;
	dst.m_left = 0.0f;
	dst.m_right = 200.0f;
	dst.m_bottom = 350.0f;


	//ループして描画する
	for (int i = 0; i <= 3; i++)
	{
		//星の名前の枠を描画
		dst.m_top = 300.0f;
		dst.m_left = 0.0f + g * i;
		dst.m_right = 200.0f + g * i;
		dst.m_bottom = 300.0f + k;
		Draw::Draw(1, &src, &dst, c, 0.0f);

		for (int l = 0; l <= 2; l++)
		{

			dst.m_top = 375.0f + k * l;
			dst.m_bottom = 450.0f + k * l;
			Draw::Draw(1, &src, &dst, c, 0.0f);
		}

	}

	//説明文の背景部分を描画
	dst.m_top = 0.0f;
	dst.m_left = 67.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 300.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);

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

	Font::StrDraw(L"星座", 10, 25, 25, c);
	Font::StrDraw(L"選択", 10, 50, 25, c);
	Font::StrDraw(L"へ", 10, 75, 25, c);

	//星座選択へボタン
	// left				 right            top            bottom         
	if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>0 && m_mou_y < 100)
	{
		if (m_mou_l == true)
		{
			lever = 0;
			Scene::SetScene(new CSceneStarPicbook());

		}
	}
	//ｂを押すと戻る
	else if (Input::GetVKey('B') == true)
	{
		lever = 0;
		Scene::SetScene(new CSceneStarPicbook());
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


	//					　　	    X　 Y　 大きさ
	Font::StrDraw(L"サダルメリク", 20, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 1;
		}
	}

	//					　　	    X　 Y　 大きさ
	Font::StrDraw(L"サダルスウド", 20, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 2;
		}
	}

	//					　　	    X　        Y　    大きさ
	Font::StrDraw(L"サダクビア", 20, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 3;
		}
	}
	//					　　	  X　        Y　    大きさ
	Font::StrDraw(L"スカトム", 20, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 4;
		}
	}

	t -= 4;
	l -= 4;
	std = 1;

	//					　　	  X　        Y　    大きさ
	Font::StrDraw(L"アルバリ", 20 + 220, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 5;
		}
	}
	//					　　	  X　        Y　    大きさ
	Font::StrDraw(L"アンカ", 20 + 220, 330 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 6;
		}
	}
	//					  　　	    X　        Y　    大きさ
	Font::StrDraw(L"シュチュラ", 20 + 220, 340 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 7;
		}
	}

	if (crick == 1)
	{
		ver = 0;
		Font::StrDraw(L"みずがめ座に属する", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"みずがめ座の恒星で3等星。みずがめ座で2番目に明るい恒星。", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"ほぼ天の赤道上にある。見かけの二重星である", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"サダルスウド、ペガスス座ε星と同じ場所で同時期に生まれた", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"ものと考えられている", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"見かけの二重星…地球上から見る方向は同じだが、実際には", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"引力などの影響を及ぼさない見かけ上の2つの星", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 2)
	{
		ver = 0;
		Font::StrDraw(L"みずがめ座に属する", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"みずがめ座で最も明るい恒星で3等星。3連星で、主星は", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"黄色超巨星である", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"サダルメリク、ペガスス座ε星と同じ場所で同時期に生まれた", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"ものと考えられている", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"連星…2つ以上の恒星が両者の重心の周りを軌道運動している", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"天体である", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"超巨星…太陽よりはるかに大きく明るい恒星のこと", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 3)
	{
		ver = 0;
		Font::StrDraw(L"みずがめ座に属する", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"恒星で4等星。分光連星で、A型主系列星の主星の周りを", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"58日の周期で周っている", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"A型主系列星…水素を燃やして燃える主系列星である", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"au(天文単位)…長さの単位で", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"正確に 149597870700 m である", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"分光連星…スペクトルの特徴の周期的な変化によって", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"2つ以上の天体からなることを検出できる連星のこと", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"連星…2つ以上の恒星が両者の重心の周りを軌道運動している", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"天体である", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 4)
	{
		ver = 0;
		Font::StrDraw(L"みずがめ座に属する", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"みずがめ座で3番目に明るい恒星", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"おおぐま座運動星団の星の一つと考えられている", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"おおぐま座運動星団…地球の最も近くにある運動星団である", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"星団…お互いの重力によって生まれた恒星の集団。主な星は", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"約80光年の距離にある。", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 5)
	{
		ver = 0;
		Font::StrDraw(L"みずがめ座に属する", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"恒星で4等星変光、化学組成、惑星は発見されていないなど", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"不確かな点が多い", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"惑星は発見されていないが、赤外線の放射が観測されていること", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"から周囲を円盤状の塵に覆われている可能性がある", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"アルバリは、アラビア語で「飲み込む者」を意味する", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"bāli‘ に由来する", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 6)
	{
		ver = 0;
		Font::StrDraw(L"みずがめ座に属する", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"恒星で4等星。近くに見えるρ星と二重星を成しているが", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"連星ではない。将来は白色矮星になると予測されている", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"二重星…地球上から見る恒星が同じ方向に近接して見える物を", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"指す", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"連星…2つ以上の恒星が両者の重心の周りを軌道運動している", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"天体である", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"白色矮星(はくしょくわいせい)…恒星が進化の終末期に", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"とりうる形態の一つ", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 7)
	{
		ver = 0;
		Font::StrDraw(L"みずがめ座に属する", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"恒星で5等星、スペクトル分類K型の巨星", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"固有名のシュチュラは、ラテン語で「バケツ」を意味する言葉を", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"由来とする。これは、ルネサンス期にアラビア語でみずがめ座を", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"指していた「井戸の釣瓶」を意味する al-dalw の訳語として", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"充てられたものが、κ星の名称として使われるように", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"なったものである", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"スペクトル分類…恒星の分類法の一つ", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"巨星…半径および明るさが非常に大きい恒星", font, size_y* ver, size, c);
		ver++;
	}


}