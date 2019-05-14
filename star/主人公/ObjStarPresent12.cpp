//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjStarPresent12.h"
extern int lever;
extern int crick;
extern int cenge;


void CObjStarPresent12::Init()
{
	page = 0;//次のページへ行くための変数
	page_flag = false;
	ver = 0;
	g = 200;//星枠の横幅
	k = 75;//星枠の立幅	
	s = 0;//星のクリックの鍵	
	side_a = 0;
	side_b = 200;
	size = 25;
	size_y = 30;
	font = 80;
	fy = 200.0f;//星の名前の横幅
	font_size = 25;//文字の大きさ
	IO_y = 25; //y座標開始地点
	Interval_y = 35;//文字の立幅間隔
	left_end = 80;//説明文の左の限界を決める
	pagex = 680; //ページ座標x
	pagey = 10; //ページ座標y
	pagesize = 20; //ページサイズ

}

void CObjStarPresent12::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();


}

void CObjStarPresent12::Draw()
{
	//これはここに残す
	t = 70;//星の名前の位置 
	l = 0;//tと掛ける用の変数 
	std = 0;


	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };
	float p[4] = { 1.0f,1.0f,1.0f,0.6f, };
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//サイバー背景の切り取り
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 513.0f;
	src.m_bottom = 289.0f;

	//背景を描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(15, &src, &dst, c, 0.0f);

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
		Draw::Draw(1, &src, &dst, p, 0.0f);
		Draw::Draw(9, &src, &dst, c, 0.0f);

		for (int l = 0; l <= 2; l++)
		{
			dst.m_top = 375.0f + k * l;
			dst.m_bottom = 450.0f + k * l;
			Draw::Draw(1, &src, &dst, p, 0.0f);
			Draw::Draw(9, &src, &dst, c, 0.0f);
		}

	}

	//説明文の背景部分を描画
	dst.m_top = 0.0f;
	dst.m_left = 67.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 300.0f;
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.f);

	//戻るボタンの枠を描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 67.0f;
	dst.m_bottom = 100.0f;
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.0f);

	//次のページに行くためのボタンの枠を描画
	dst.m_top = 200.0f;
	dst.m_bottom = 300.0f;

	//次への枠
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.0f);

	dst.m_top = 100.0f;
	dst.m_bottom = 200.0f;

	//戻すの枠
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.0f);

	//星座選択への文字を描画する
	//					　　X　Y　大きさ
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

	//戻すの文字をループして出す
	wchar_t before[2][2]{ L"戻",L"る" };
	for (int i = 0; i <= 1; i++)
	{
		int l = 25;
		swprintf_s(str, L"%s", before[i]);

		//				　　X　 Y　 大きさ
		Font::StrDraw(str, 20, 230 + l * i, 25, c);
	}

	//戻るを押したらStarPresentに切り替える
	// left				 right            top            bottom       
	if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>190 && m_mou_y < 300)
	{
		if (m_mou_l == true)
		{
			if (page_flag == true)
			{
				page--;
				page_flag = false;
			}
		}
		else
		{
			page_flag = true;
		}
	}

	//次へを押したらStarPresent2に切り替える
	// left				 right            top            bottom       
	if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>100 && m_mou_y < 200)
	{
		if (m_mou_l == true)
		{
			if (page_flag == true)
			{
				page++;
				page_flag = false;
			}
		}
		else
		{
			page_flag = true;
		}
	}


	//					　　	    X　 Y　 大きさ
	Font::StrDraw(L"アルゲディ", 20, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 1;
		}
	}

	//					　　	    X　 Y　 大きさ
	Font::StrDraw(L"ダビー", 20, 325 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 2;
		}
	}

	//					　　	    X　        Y　    大きさ
	Font::StrDraw(L"ナシラ", 20, 330 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 3;
		}
	}
	//					　　	  X　        Y　    大きさ
	Font::StrDraw(L"デネブ・アルゲディ", 18, 340 + t * l, 20, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
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
	Font::StrDraw(L"アルシャト", 20 + 200, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 5;
		}
	}

	if (crick == 1)
	{
		ver = 0;
		Font::StrDraw(L"やぎ座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"肉眼でもアルゲディ1星とアルゲディ2星に分離できる二重星", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"6.6分離れたアルゲディ1星とアルゲディ2星は連星ではなく", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"見かけの二重星の関係にある", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"分…角度の単位としての分。1度の60分の1の角度である", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"連星…2つの恒星が両者の重心の周りを軌道運動している天体", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"である。双子星（ふたごぼし）とも呼ばれる。", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"二重星…地球上から見る恒星が同じ方向に近接して", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"見える物を指す", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
	}
	else if (crick == 2)
	{
		ver = 0;
		Font::StrDraw(L"やぎ座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"やぎ座にある3等星のダビー1星と6等星のダビー2星からなる", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"連星系である。ダビー1星と6等星のダビー2星は地球からは", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"少し離れており、双眼鏡を使えば容易に分離して見ることが", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"できる。また、ダビー1星、ダビー2星のそれぞれが", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"また連星系を成しており全体として少なくとも", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"5つ以上の恒星から構成されている", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
	}
	else if (crick == 3)
	{
		ver = 0;
		Font::StrDraw(L"やぎ座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"やぎ座の恒星で4等星。近年の観測結果からは", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"スペクトル型A7の初期の巨星ではないかと考えられている", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"自転速度が遅いため、対流と重力の影響によって様々な", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"金属元素が大気中に見られるAm星であるとも考えられている", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"巨星…同じ表面温度を持つ主系列星よりも半径および明るさが", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"非常に大きい恒星のことである", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"Am星…化学特異星である", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"特異星…少なくともその表面において、金属量の組成が", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"他の恒星とかなり異なっている星である", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
	}
	else if (crick == 4)
	{
		ver = 0;
		Font::StrDraw(L"やぎ座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"やぎ座で最も明るい恒星で3等星。黄道付近にあるため", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"月や惑星による掩蔽が起きる", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"黄道…天球上における太陽の見かけ上の通り道（大円）をいう", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"掩蔽…ある天体が観測者と他の天体の間を通過するために", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"その天体が隠される現象である", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
	}
	else if (crick == 5)
	{
		ver = 0;
		Font::StrDraw(L"やぎ座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"やぎ座の恒星で5等星。地球からは4.74等のA星と", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"11.80等のB星の二重星に見える", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"重力的に関係のない見かけの二重星と思われるが、もし連星系を", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"成していた場合は4,000天文単位以上離れた軌道を14万年掛けて", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"周回していると考えられる", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"二重星…地球上から見る恒星が同じ方向に近接して見える物を", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"指す", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"天文単位…長さの単位で、正確に 149597870700 m", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"である", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
	}


}