//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameL\Audio.h"
#include "GameHead.h"
#include "ObjStarPresent11.h"
extern int lever;
extern int crick;
extern int cenge;


void CObjStarPresent11::Init()
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
	Audio::LoadAudio(1, L"効果音.wav", EFFECT);
}

void CObjStarPresent11::Action()
{
	


	if (m_mou_l == true)
	{
		time_flag = true;
	}
	else if (m_mou_l == false)
	{
		a_time = 0;
		time_flag = false;
	}


	if (time_flag == true)
	{
		a_time++;
	}

	if (a_time == 1)
	{
		Audio::Start(1);
	}

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

void CObjStarPresent11::Draw()
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
	Font::StrDraw(L"ルクバト", 20, 320 + t * l, 30, c);
	l++;

	if (start_flag == true) 
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 1;
				page = 0; //ページ初期化
			}
		}
	}
	

	//					　　	    X　 Y　 大きさ
	Font::StrDraw(L"アルカブ・プリオル", 17, 330 + t * l, 18, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 2;
				page = 0; //ページ初期化
			}
		}
	}
	

	//					　　	    X　        Y　    大きさ
	Font::StrDraw(L"アルカブ・ポステリオル", 3, 340 + t * l, 18, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 3;
				page = 0; //ページ初期化
			}
		}
	}
	
	//					　　	  X　        Y　    大きさ
	Font::StrDraw(L"アルナスル", 20, 335 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 4;
				page = 0; //ページ初期化
			}
		}
	}
	

	t -= 4;
	l -= 4;
	std = 1;

	//					　　	  X　        Y　    大きさ
	Font::StrDraw(L"カウス・メディア", 10 + 220, 330 + t * l, 18, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 5;
				page = 0; //ページ初期化
			}
		}
	}
	
	//					　　	  X　        Y　    大きさ
	Font::StrDraw(L"カウス・アウストラリス", 20 + 180, 335 + t * l, 18, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 6;
				page = 0; //ページ初期化
			}
		}
	}
	
	//					  　　	    X　        Y　    大きさ
	Font::StrDraw(L"アスケラ", 20 + 220, 340 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 7;
				page = 0; //ページ初期化
			}
		}
	}
	
	Font::StrDraw(L"カウス・ボレアリス", 20 + 200, 355 + t * l, 18, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 8;
				page = 0; //ページ初期化
			}
		}
	}
	

	t -= 4;
	l -= 4;
	std = 2;

	//					　　	  X　        Y　    大きさ
	Font::StrDraw(L"ポリス", 20 + 400, 320 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 9;
				page = 0; //ページ初期化
			}
		}
	}
	
	//					　　	  X　        Y　    大きさ
	Font::StrDraw(L"アイン・アル・ラーミー", 1 + 400, 340 + t * l, 18, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 10;
				page = 0; //ページ初期化
			}
		}
	}
	
	//					  　　	    X　        Y　    大きさ
	Font::StrDraw(L"アルバルダ", 20 + 400, 350 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 11;
				page = 0; //ページ初期化
			}
		}
	}
	
	Font::StrDraw(L"ヌンキ", 20 + 400, 360 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 12;
				page = 0; //ページ初期化
			}
		}
	}
	

	t -= 4;
	l -= 4;
	std = 3;

	//					　　	  X　        Y　    大きさ
	Font::StrDraw(L"テレビルム", 20 + 600, 320 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 13;
				page = 0; //ページ初期化
			}
		}
	}
	


	if (crick == 1)
	{
		page_max = 1; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		Font::StrDraw(L"いて座に属する4等星。", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"いて座の星の中では16番目の明るさであり他の星座で見られる", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"規則性からは大きく外れているように見える。", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"2016年7月20日、国際天文学連合の恒星の命名に関する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"ワーキンググループ(WGSN)は、ルクバトをいて座α星の", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"固有名として正式に承認した。", left_end, IO_y + Interval_y * ver, font_size, c);
		
		//ページ制限
		if (page < 0 || page  > 0)
		{
			page = 0;
		}

	}
	else if (crick == 2)
	{
		page_max = 3; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"いて座に属する恒星で4等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"アルカブ・ポステリオルとは見かけの二重星の関係だが", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"この恒星自体はB型主系列星で4等星の主星AとF型主系列星で", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"7等星の伴星Bからなる連星である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[二重星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"地球上から見る恒星が同じ方向に近接して見える物を", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"指す。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[B型主系列星（Bがたしゅけいれっせい）とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"水素の核融合で燃える主系列星である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"太陽の2倍から16倍の質量を持ち、表面温度は", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"10,000Kから30,000Kの間である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[F型主系列星(Fがたしゅけいれっせい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"水素を燃やして燃える主系列星である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"太陽質量の1.0倍から1.4倍の質量を持ち、表面温度は", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"6000Kから7600Kの間である。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 2)
		{
			Font::StrDraw(L"[主系列星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"恒星の有効温度と明るさを示した図である", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ヘルツシュプルング・ラッセル図 (HR図) 上で", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"明るく高温から暗く低温に延びる線である主系列に", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"位置する恒星をいう。矮星ともいう。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[連星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2つの恒星が両者の重心の周りを軌道運動している天体", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"である。双子星（ふたごぼし）とも呼ばれる。", left_end, IO_y + Interval_y * ver, font_size, c);
		}	
		//ページ制限
		else if (page < 1)
		{
			page = 0;
		}
		else if (page > 2)
		{
			page = 2;
		}
	}
	else if (crick == 3)
	{
		page_max = 3; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"いて座に属する恒星で4等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"アルカブ・プリオルとは見かけの二重星の関係で、連星では", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ない。F型主系列星で水素の核融合を終えて準巨星になろうか", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"という段階である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[二重星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"地球上から見る恒星が同じ方向に近接して見える物を", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"指す。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[F型主系列星(Fがたしゅけいれっせい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"水素を燃やして燃える主系列星である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"太陽質量の1.0倍から1.4倍の質量を持ち、表面温度は", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"6000Kから7600Kの間である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[連星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2つ以上の恒星が両者の重心の周りを軌道運動している天体", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"である。双子星（ふたごぼし）とも呼ばれる。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 2)
		{
			Font::StrDraw(L"[準巨星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"同じスペクトル型の通常の主系列星よりやや明るく", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"巨星ほどは明るくない恒星の分類の1つである。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[巨星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"半径および明るさが非常に大きい恒星。巨星の半径は", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"太陽の10倍から100倍、明るさは10倍から1000倍で", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ある。巨星より明るい恒星は、超巨星や極超巨星と呼ばれる。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		//ページ制限
		else if (page < 1)
		{
			page = 0;
		}
		else if (page > 2)
		{
			page = 2;
		}
	}
	else if (crick == 4)
	{
		page_max = 2; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"いて座に属する恒星で3等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"K型の巨星で既に中心核では水素の核融合を終えてヘリウムの", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"核融合が進んでいる段階である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"分光法による観測結果から伴星の存在が示唆されているが", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"詳しいことは何もわかっていない。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"近くに見える5等星のアルカブ・ポステリオルは、太陽系から", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"1,500光年以上とこの星の15倍以上遠くにあり、見かけの", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"二重星の関係である。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[巨星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"半径および明るさが非常に大きい恒星。巨星の半径は", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"太陽の10倍から100倍、明るさは10倍から1000倍で", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ある。巨星より明るい恒星は、超巨星や極超巨星と呼ばれる。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[二重星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"地球上から見る恒星が同じ方向に近接して見える物を指す。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"肉眼では1つの星に見えるが、望遠鏡などで観測する事によって", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2つに分解する。", left_end, IO_y + Interval_y * ver, font_size, c);
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
		page_max = 2; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"いて座に属する恒星で3等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"星間物質がどの程度あるかわかっていないため不確かでは", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"あるが観測されているよりも光度は30%半径は15%ほど", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"大きいものと考えられている。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2016年7月20日に国際天文学連合の恒星の命名に関する", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ワーキンググループ(WGSN)は、カウス・メディアを", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"いて座δ星の固有名として承認した。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[星間物質とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"恒星間の宇宙空間に分布する希薄物質の総称である。", left_end, IO_y + Interval_y * ver, font_size, c);
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
	else if (crick == 6)
	{
		page_max = 2; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"いて座に属する最も明るい恒星で2等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"B型のスペクトルを持つ巨星に分類されているがA型の輝巨星", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"とされることもある。現在では太陽の70倍以上という自転速度", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"によるガス殻星であると考えられている。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[輝巨星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"極めて明るい巨星に分類される。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[ガス殻星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"赤道周囲にガスの円盤を持つことが示される恒星である。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[巨星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"半径および明るさが非常に大きい恒星。巨星の半径は", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"太陽の10倍から100倍、明るさは10倍から1000倍で", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ある。巨星より明るい恒星は、超巨星や極超巨星と呼ばれる。", left_end, IO_y + Interval_y * ver, font_size, c);
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
	else if (crick == 7)
	{
		page_max = 2; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"いて座に属する3番目に明るい恒星で3等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"+3.26等級のA2型巨星と+3.47等級のA4型準巨星", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"から構成される連星系で2つの星は平均距離13.4auの", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"軌道を21.075年の周期で互いを周回している。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"100年余りの固有運動の観測結果から見かけの二重星であると", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"考えられている。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[巨星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"半径および明るさが非常に大きい恒星。巨星の半径は", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"太陽の10倍から100倍、明るさは10倍から1000倍で", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ある。巨星より明るい恒星は、超巨星や極超巨星と呼ばれる。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[準巨星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"同じスペクトル型の通常の主系列星よりやや明るく", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"巨星ほどは明るくない恒星の分類の1つである。", left_end, IO_y + Interval_y * ver, font_size, c);
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
	else if (crick == 8)
	{
		page_max = 3; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"いて座に属する恒星で3等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"いわゆるレッドクランプに分類される準巨星で中心核では", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ヘリウムから酸素や炭素の核融合が進んでいる。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"016年7月20日に国際天文学連合の恒星の命名に関する", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ワーキンググループ(WGSN)は、カウス・ボレアリスを", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"いて座λ星の固有名として正式に承認した。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[レッドクランプとは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ヘルツシュプルング・ラッセル図上で見られる特徴の一つ", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"である。表面温度が同じ主系列星と比べて光度が大きい。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[ヘルツシュプルング・ラッセル図(HR図)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"縦軸に絶対等級もしくは光度、横軸にスペクトル型(表面温度)", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"や有効温度をとった恒星の分布図のことである。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 2)
		{
			Font::StrDraw(L"[主系列星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"恒星の有効温度と明るさを示した図である", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ヘルツシュプルング・ラッセル図 (HR図) 上で", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"明るく高温から暗く低温に延びる線である主系列に", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"位置する恒星をいう。矮星ともいう。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[準巨星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"同じスペクトル型の通常の主系列星よりやや明るく", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"巨星ほどは明るくない恒星の分類の1つである。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		//ページ制限
		else if (page < 1)
		{
			page = 0;
		}
		else if (page > 2)
		{
			page = 2;
		}
	}
	else if (crick == 9)
	{
		page_max = 2; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"いて座に属する4等星。南斗六星の柄の端に位置する。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"五重星でそのうち4つの恒星は実際に連星系を成している。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"太陽系からの距離はおよそ3,600光年となる四重星系は", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"重力的に不安定なためいずれは1個か2個か弾き出されるもの", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"と考えられている。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[南斗六星(なんとろくせい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"いて座の上半身と弓の一部からなる6つの明るい星の集まり", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"である。位置とその形から北斗七星に対してこの名前が付いた。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[連星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2つ以上の恒星が両者の重心の周りを軌道運動している天体", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"である。双子星（ふたごぼし）とも呼ばれる。", left_end, IO_y + Interval_y * ver, font_size, c);
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
	else if (crick == 10)
	{
		page_max = 3; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"いて座に属する5等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"「ティースプーン」と呼ばれるアステリズムの一部を成す。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"クラウディオス・プトレマイオス（トレミー）は、14分離れた", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"いて座v1星とv2星のペアを二重星と呼んでいたとされる。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2017年9月5日、IAUの恒星の命名に関する", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ワーキンググループ(WGSN)は、アイン・アル・ラーミーを", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"いて座v星1Aの固有名として正式に承認した。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[アステリズムあるいは星群(せいぐん)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"複数の恒星が天球上に形作るパターンである。星座の星の並び", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"同様地球からの距離は同じとは限らず、空間的には", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"まとまっていない。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[クラウディオス・プトレマイオスとは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"数学、天文学、占星学、音楽学、光学、地理学、地図製作学", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"など幅広い分野にわたる業績を残した古代ローマの学者。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 2)
		{
			Font::StrDraw(L"[二重星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"地球上から見る恒星が同じ方向に近接して見える物を指す。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"肉眼では1つの星に見えるが、望遠鏡などで観測する事によって", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2つに分解する。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		//ページ制限
		else if (page < 1)
		{
			page = 0;
		}
		else if (page > 2)
		{
			page = 2;
		}
	}
	else if (crick == 11)
	{
		page_max = 1; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);


		Font::StrDraw(L"いて座に属する恒星系である。", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"3つの恒星からなる連星系で黄道面に近いため、いて座π星は", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"月、ごくまれに惑星による掩蔽が観測される。", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"[黄道(こうどう)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"天球上における太陽の見かけ上の通り道（大円）をいう。", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"[掩蔽(えんぺい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"ある天体が観測者と他の天体の間を通過するためにその天体が", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"隠される現象である。", left_end, IO_y + Interval_y * ver, font_size, c);

		//ページ制限
		if (page < 0 || page  > 0)
		{
			page = 0;
		}

	}
	else if (crick == 12)
	{
		page_max = 3; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"いて座に属する2番目に明るい恒星で2等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"南斗六星を作る星の1つ。太陽の7倍もの質量を持つため", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"中心核での核融合が早く進み、誕生からおよそ5000万年ほど", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"で寿命を迎えるだろうと推測される。そのときには、太陽と", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"同じ程度の質量を持つ白色矮星になるだろうと考えられている。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"黄道に近いため、月による掩蔽が起こり得る。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[南斗六星(なんとろくせい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"いて座の上半身と弓の一部からなる6つの明るい星の集まり", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"である。位置とその形から北斗七星に対してこの名前が付いた。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[白色矮星(はくしょくわいせい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"恒星が進化の終末期にとりうる形態の一つ。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[黄道(こうどう)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"天球上における太陽の見かけ上の通り道（大円）をいう。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 2)
		{
			Font::StrDraw(L"[掩蔽(えんぺい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ある天体が観測者と他の天体の間を通過するためにその天体が", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"隠される現象である。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		//ページ制限
		else if (page < 1)
		{
			page = 0;
		}
		else if (page > 2)
		{
			page = 2;
		}
	}
	else if (crick == 13)
	{
		page_max = 2; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"いて座に属する恒星で5等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"同じいて座にあるオメガ星雲とは名前が似ているだけで", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"異なる天体である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2017年9月5日、国際天文学連合の恒星の命名に関する", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ワーキンググループ(WGSN)は、いて座ω星Aの固有名", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"として、テレビルムを正式に承認した。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[オメガ星雲とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"いて座に位置する散光星雲である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"星雲の中にループ状の構造が見えることから", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"これをいろいろな物に見立てて「オメガ星雲」「白鳥星雲」", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"などいろいろな呼び名を持つ散光星雲である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"また、内部には電波源があり強力な電波が放射されている。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"明るい星雲であるため小口径の望遠鏡でも楽しめる。", left_end, IO_y + Interval_y * ver, font_size, c);
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


}