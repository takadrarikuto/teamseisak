//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjStarPresent2.h"
extern int lever;
extern int crick;
extern int cenge;


void CObjStarPresent2::Init()
{
	page = 0;//次のページへ行くための変数
	page_flag = false;
	ver = 0;
	VER_start = 0; //バー初期化
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

	start_time = 0.0f; //マウス操作開始時間
	start_flag = false; //マウス操作開始フラグ
}

void CObjStarPresent2::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	//星座選択へボタン
	// left				 right            top            bottom         
	if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>0 && m_mou_y < 100)
	{
		if (m_mou_l == true)
		{
			lever = 0;
			start_time = 0; //マウス操作開始時間
			Scene::SetScene(new CSceneStarPicbook());

		}
	}
	//ｂを押すと戻る
	else if (Input::GetVKey('B') == true)
	{
		lever = 0;
		start_time = 0; //マウス操作開始時間
		Scene::SetScene(new CSceneStarPicbook());
	}


	//30f後に表示
	start_time++;

	if (start_time > 30.0f)
	{
		start_flag = true;
	}
	else
	{
		m_mou_l = false;
		start_flag = false;
	}
}

void CObjStarPresent2::Draw()
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
	Font::StrDraw(L"アルデバラン", 15, 320 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 1;
			}
		}
	}


	//					　　	    X　 Y　 大きさ
	Font::StrDraw(L"エルナト", 20, 330 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 2;
			}
		}
	}


	//					　　	    X　        Y　    大きさ
	Font::StrDraw(L"プリマヒアデス", 15, 330 + t * l, 25, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 3;
			}
		}
	}

	//					　　	  X　        Y　    大きさ
	Font::StrDraw(L"セカンドヒアデス", 15, 340 + t * l, 20, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 4;
			}
		}
	}


	t -= 4;
	l -= 4;
	std = 1;

	//					　　	  X　        Y　    大きさ
	Font::StrDraw(L"アイン", 20 + 220, 320 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 5;
			}
		}
	}

	//					　　	  X　        Y　    大きさ
	Font::StrDraw(L"テンカン", 18 + 220, 330 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 6;
			}
		}
	}

	//					  　　	    X　        Y　    大きさ
	Font::StrDraw(L"アルキオネ", 10 + 220, 340 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 7;
			}
		}
	}

	//					  　　	    X　        Y　    大きさ
	Font::StrDraw(L"チャムクイ", 10 + 220, 340 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 8;
			}
		}
	}


	t -= 4;
	l -= 4;
	std = 2;

	//					　　	  X　        Y　    大きさ
	Font::StrDraw(L"ケラエノ", 25 + 400, 320 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 9;
			}
		}
	}

	//					　　	  X　        Y　    大きさ
	Font::StrDraw(L"エレクトラ", 20 + 400, 330 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 10;
			}
		}
	}

	//					  　　	    X　        Y　    大きさ
	Font::StrDraw(L"タイゲタ", 25 + 400, 350 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 11;
			}
		}
	}

	//					  　　	    X　        Y　    大きさ
	Font::StrDraw(L"マイア", 30 + 400, 360 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 12;
			}
		}
	}


	t -= 4;
	l -= 4;
	std = 3;

	//					　　	  X　        Y　    大きさ
	Font::StrDraw(L"アステローペ", 15 + 600, 320 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 13;
			}
		}
	}
	//					　　	  X　        Y　    大きさ
	Font::StrDraw(L"メローペ", 25 + 600, 340 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 14;
			}
		}
	}

	//					  　　	    X　        Y　    大きさ
	Font::StrDraw(L"アトラス", 25 + 600, 350 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 15;
			}
		}
	}

	//					  　　	    X　        Y　    大きさ
	Font::StrDraw(L"プレイオネ", 20 + 600, 370 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 16;
			}
		}
	}


	if (crick == 1)
	{
		ver = VER_start; //文字間隔初期化
		page_max = 2; //最大ページ数

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"おうし座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"おうし座で最も明るい恒星で全天21の1等星の1つ", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"冬のダイヤモンドを形成する恒星の1つでもある", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"木星の数倍の質量の惑星を持つ", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"惑星探査機パイオニア10号は現在、おおよそ、アルデバランの", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"方向へ飛行を続けているがアルデバランに最接近するのは", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"約200万年後と考えられている", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			//8行目まで、改行
		}
		else if (page == 1)
		{
			//8行まで
			Font::StrDraw(L"[冬のダイヤモンドとは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"6つの1等星を順に結ぶと大きなダイヤモンドの形となる", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"これを、冬のダイヤモンドまたは冬の大六角形と言う", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[パイオニア10号とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"アメリカ航空宇宙局の惑星探査機。世界初の木星探査機である", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		//ページ制限
		else if (page < 1)
		{
			page = 0;
		}
		else if (page > 1)
		{
			page = 1;
		}
	}
	else if (crick == 2)
	{
		ver = VER_start; //文字間隔初期化
		page_max = 2; //最大ページ数

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"おうし座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"おうし座で2番目に明るい恒星で2等星。かつてはぎょしゃ座", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"にも同時に属していた。特異星、中でも水銀・マンガン星に", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"分類されており、太陽にくらべてマンガンの含有率が20倍も", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"高く、またカルシウムとマグネシウムは8分の1と低い", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"中心核では水素による核融合が終わりに近づいており今後", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"200万年以内に主系列から進化して橙色の巨星になるものと", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"予測されている", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			//8行目まで、改行
		}
		else if (page == 1)
		{
			//8行まで
			Font::StrDraw(L"[ぎょしゃ座とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"北天の星座でトレミーの48星座の1つ", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[特異星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"少なくともその表面において、金属量の組成が", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"他の恒星とかなり異なっている星である", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		//ページ制限
		else if (page < 1)
		{
			page = 0;
		}
		else if (page > 1)
		{
			page = 1;
		}

	}
	else if (crick == 3)
	{
		ver = VER_start; //文字間隔初期化
		page_max = 2; //最大ページ数

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"おうし座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"おうし座の恒星で4等星。二重星とされているが伴星について", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"特にわかっていることはない。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"主星AはG9.5～K0のスペクトルを持つ巨星である", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
		}
		else if (page == 1)
		{
			//8行まで
			Font::StrDraw(L"[二重星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"地球上から見る恒星が同じ方向に近接して見える物を", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"指す", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[巨星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"同じ表面温度を持つ主系列星よりも半径および明るさが", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"非常に大きい恒星のことである", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		//ページ制限
		else if (page < 1)
		{
			page = 0;
		}
		else if (page > 1)
		{
			page = 1;
		}

	}
	else if (crick == 4)
	{
		ver = VER_start; //文字間隔初期化
		page_max = 2; //最大ページ数

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"おうし座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"おうし座の恒星で4等星。ヒアデス星団の一員で", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"セカンドヒアデスの1A星とδ1B星が見かけの二重星を", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"成している", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"セカンドヒアデスはG9.5～K0のスペクトルを持つ巨星で", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"これ自体が分光連星を成しており、主星はAa、伴星はAbという", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"符号で呼ばれる", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
		}
		else if (page == 1)
		{
			//8行まで
			Font::StrDraw(L"ヒアデス星団…おうし座に位置する散開星団である", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"散開星団…恒星の集団（星団）の一種である", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"", left_end, IO_y + Interval_y * ver, font_size, c);
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
		//ページ制限
		else if (page < 1)
		{
			page = 0;
		}
		else if (page > 1)
		{
			page = 1;
		}

	}
	else if (crick == 5)
	{
		ver = VER_start; //文字間隔初期化
		Font::StrDraw(L"おうし座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"おうし座の方角に位置する橙色巨星である。", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"年齢は6億2500万年と精度良く予測されている", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"189秒離れたところに見える11等級の恒星と連星であるか", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"見かけの二重星であるかは定かではない", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"連星…2つの恒星が両者の重心の周りを軌道運動している", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"天体である。双子星（ふたごぼし）とも呼ばれる", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"二重星…地球上から見る恒星が同じ方向に近接して見える物を", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"指す", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 6)
	{
		ver = VER_start; //文字間隔初期化
		Font::StrDraw(L"おうし座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"おうし座の恒星で3等星。太陽と比べると主星は", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"質量で11倍以上、半径で5－6倍という巨大な恒星である", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"125 km/sと高速で自転している。軌道周期は", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"ほぼ113日であると推定される", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 7)
	{
		ver = VER_start; //文字間隔初期化
		Font::StrDraw(L"おうし座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"おうし座の恒星で3等星。プレアデス星団で 最も明るい恒星で", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"ある。他の多くのBe星と同様に215km/sと速い自転速度を", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"持ち恒星の回りにガスの円盤を作っている。明るさは", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"1.13時間ごとに+8.25から+8.30まで変化する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"プレアデス星団…おうし座に位置する散開星団である", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"散開星団…恒星の集団（星団）の一種である", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 8)
	{
		ver = VER_start; //文字間隔初期化
		Font::StrDraw(L"おうし座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"おうし座の二重星であり、ヒアデス星団のメンバーである。", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"5.62′離れた2つの星から構成される。視差の測定から", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"おうし座θ1星は地球から約152光年、おうし座θ2星は", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"約157光年の距離に位置すると推定されている", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"二重星…地球上から見る恒星が同じ方向に近接して見える物を", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"指す", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 9)
	{
		ver = VER_start; //文字間隔初期化
		Font::StrDraw(L"おうし座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"おうし座の恒星でプレアデス星団に属する5等星", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"プレアデス星団の中では輝星の一つだが、5等星と暗く", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"肉眼で見つけるのは難しい", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"星間物質による減光が0.3等級ほどあると考えられている", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"星間物質…恒星間の宇宙空間に分布する希薄物質の総称である", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"大量の星間物質が凝縮して、星を構成する材料にもなる。", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"減光…観測者に到達する電磁波のエネルギー総量が減る現象", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"及びその減衰量を表す指標のことである", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 10)
	{
		ver = VER_start; //文字間隔初期化
		Font::StrDraw(L"おうし座に属する", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"おうし座の恒星でプレアデス星団に属する、青色巨星である", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"プレアデス星団の輝星の中でも明るいものの一つ。この星は", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"月により周期的に掩蔽され、また太陽系の他の惑星によっても", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"掩蔽されることがある。自転速度は181km/sと高速で", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"自転している高速の自転のため、極付近は平たくなり、赤道は", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"膨張している", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"青色巨星…高温のために青く見える恒星", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
	}
	else if (crick == 11)
	{
		ver = VER_start; //文字間隔初期化
		Font::StrDraw(L"おうし座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"おうし座の恒星でプレアデス星団に属する4等星。", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"月に掩蔽されることがあり、そのときの観測結果から主星と", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"伴星の詳細がわかっている。プレアデス星団の中では", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"明るいものの一つ主星と伴星は地球からは0.012秒離れて見え", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"1313日で公転している。", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"掩蔽…ある天体が観測者と他の天体の間を通過するために", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"その天体が隠される現象である", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 12)
	{
		ver = VER_start; //文字間隔初期化
		Font::StrDraw(L"おうし座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"おうし座の恒星でプレアデス星団に属する4等星。プレアデス", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"星団の中でも明るいものの一つ。自転速度が遅いことにより", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"大気中に水銀やマンガンの輝線が強く見られる", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"水銀・マンガン星に分類される", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"プレアデス星団…おうし座に位置する散開星団である", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"散開星団…恒星の集団（星団）の一種である", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 13)
	{
		ver = VER_start; //文字間隔初期化
		Font::StrDraw(L"おうし座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"おうし座の恒星でプレアデス星団に属している", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"固有名アステローペは、ギリシャ神話に登場する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"プレイアデスの一人の名前に因んでいる", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"プレアデス星団…おうし座に位置する散開星団である", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"散開星団…恒星の集団（星団）の一種である", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 14)
	{
		ver = VER_start; //文字間隔初期化
		Font::StrDraw(L"おうし座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"おうし座に位置する恒星でプレアデス星団に属している", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"プレアデス星団の輝星の中でも明るいものの一つ。", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"23番星の放射の影響で光を放っている", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"固有名メローペ は、ギリシャ神話に登場するプレイアデスの", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"一人の名前に因んでいる", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 15)
	{
		ver = VER_start; //文字間隔初期化
		Font::StrDraw(L"おうし座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"おうし座の恒星でプレアデス星団に属している。", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"プレアデス星団の輝星の中でも明るいものの一つで三重星", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"少なくとも52au離れた軌道を150年以上かけて周回している", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"au(天文単位)…長さの単位で正確に 149597870700 mである", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"三重星(多重星)…地球から見ると近接した位置に見える", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"3つ以上の恒星である", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 16)
	{
		ver = VER_start; //文字間隔初期化
		Font::StrDraw(L"おうし座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"おうし座の恒星でプレアデス星団に属す。プレアデス星団の", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"中では輝星の一つだが、視等級は5.09と暗く、また近くに", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"約4倍明るいおうし座27番星が見えるために裸眼で見つけるのは", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"難しい", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"プレアデス星団…おうし座に位置する散開星団である", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"散開星団…恒星の集団（星団）の一種である", left_end, IO_y + Interval_y * ver, font_size, c);
	}


}