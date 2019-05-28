//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameL\Audio.h"
#include "GameHead.h"
#include "ObjStarPresent7.h"
extern int lever;
extern int crick;
extern int cenge;


void CObjStarPresent7::Init()
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

void CObjStarPresent7::Action()
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

void CObjStarPresent7::Draw()
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
	Font::StrDraw(L"カストル", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"ポルックス", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"アルヘナ", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"ワサト", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"メブスタ", 20 + 220, 320 + t * l, 30, c);
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
	Font::StrDraw(L"メクブダ", 20 + 220, 330 + t * l, 30, c);
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
	Font::StrDraw(L"プロプス", 20 + 220, 340 + t * l, 30, c);
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
	
	//					　　	  X　        Y　    大きさ
	Font::StrDraw(L"テジェット", 20 + 220, 350 + t * l, 30, c);
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
	std=2;
	//					　　	  X　        Y　    大きさ
	Font::StrDraw(L"アルズラ", 20 + 420, 320 + t * l, 30, c);
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

	//					  　　	    X　        Y　    大きさ
	Font::StrDraw(L"チシュエイ", 20 + 420, 330 + t * l, 30, c);
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



	if (crick == 1)
	{
		page_max = 3; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"ふたご座に属する2番目に明るい恒星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"バイエル符号ではα星とされてはいるが", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ふたご座β星（1等星、ポルックス）よりもやや暗い。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"カストルはポルックスとあわせて、天球上で見かけ上いわゆる", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ふたご星のように見え、星座のひとつであるふたご座を", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"形成する。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"三大流星群の一つに数えられるふたご座流星群は", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"カストル付近を放射点としている。", left_end, IO_y + Interval_y * ver, font_size, c);
			//8行目まで、改行
		}
		else if (page == 1)
		{
			//8行まで
			Font::StrDraw(L"[ふたご座流星群(ふたござりゅうせいぐん)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ふたご座α星(カストル)付近を放射点として出現する", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"流星群である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ふたご座α流星群（ふたござアルファりゅうせいぐん）とも", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"呼ばれる。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[流星群（りゅうせいぐん）とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"その軌跡が天球上のある一点（放射点または輻射点という）を", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"中心に放射状に広がるように出現する一群の流星のことをいう。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 2)
		{
			Font::StrDraw(L"[放射点（ほうしゃてん）とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"流星群に属する流星（群流星）が放射状に飛び出してくるように", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"見える、天球上の1点のことである。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"輻射点（ふくしゃてん）ともいう。", left_end, IO_y + Interval_y * ver, font_size, c);
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
	else if (crick == 2)
	{
		page_max = 1; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		Font::StrDraw(L"ふたご座に属する最も明るい恒星。", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"全天21の1等星の1つ冬のダイヤモンドを形成する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"恒星の1つでもある。", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"黄みの橙色をした恒星。α星のカストルとともに、ふたご座の", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"兄弟の頭に見立てられている。", left_end, IO_y + Interval_y * ver, font_size, c);	

		//ページ制限
		if (page < 0 || page > 0)
		{
			page = 0;
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
			Font::StrDraw(L"ふたご座に属する3番目に明るい恒星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"分光連星で、主星はA型の準巨星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"伴星は太陽とほぼ同じ質量を持ち、主星を平均8.5au離れた", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"離心率の平均8.5au離れた離心率の高い軌道を12.6年の", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"周期で周回している。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[分光連星（ぶんこうれんせい）とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"望遠鏡を使用して分離できなくとも、スペクトルの特徴の", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"周期的な変化によって2つ以上の天体からなることを", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"検出できる連星のこと。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"これに対し、望遠鏡で分離できるものを実視連星という。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[準巨星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"同じスペクトル型の通常の主系列星よりやや明るく", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"巨星ほどは明るくない恒星の分類の1つである。", left_end, IO_y + Interval_y * ver, font_size, c);
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
			Font::StrDraw(L"[au(天文単位)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"長さの単位で正確に 149597870700 mである。", left_end, IO_y + Interval_y * ver, font_size, c);
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
		page_max = 3; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"ふたご座に属する恒星で4等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"F型の準巨星で4等級のA星とK型主系列星で8等級の", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"B星による連星系で、B星はA星から100auの距離をおよそ", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"1,200年かけて周回している。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"A星はさらに分光連星とされるが詳細はわかっていない。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[準巨星(じゅんきょせい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"同じスペクトル型の通常の主系列星よりやや明るく、巨星ほどは", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"明るくない恒星の分類の1つである。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[K型主系列星(Kがたしゅけいれつせい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"中心部での水素の核融合で輝いている。質量は太陽の", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"0.46倍から0.8倍、表面温度は3,900Kから", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"5,200Kである。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[連星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2つの恒星が両者の重心の周りを軌道運動している天体で", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ある。双子星（ふたごぼし）とも呼ばれる。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
		}
		else if (page == 2)
		{
			Font::StrDraw(L"[分光連星（ぶんこうれんせい）とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"望遠鏡を使用して分離できなくとも、周期的なスペクトル線の", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"移動やパルス周期の変動など、スペクトルの特徴の周期的な", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"変化によって2つ以上の天体からなることを", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"検出できる連星のこと。", left_end, IO_y + Interval_y * ver, font_size, c);
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
	else if (crick == 5)
	{
		page_max = 2; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"ふたご座に属する恒星で3等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"超巨星で、月に掩蔽される際に詳細な観測が成されている。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"110秒離れた位置に見えるK2型の10等星とは見かけの", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"二重星の関係にあり、連星ではない。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[超巨星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"太陽よりはるかに大きく明るい恒星のこと。明るさは青色超巨星の", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"場合は太陽の1万倍（全エネルギー放射で太陽の10万倍）以上", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"赤色超巨星の場合は太陽の数千倍（同3万倍）以上ある。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[角度の単位としての秒とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"分の1/60の角度である。1秒は1度の1/3600である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[二重星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"地球上から見る恒星が同じ方向に近接して見える物を", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"指す。", left_end, IO_y + Interval_y * ver, font_size, c);
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
	else if (crick == 6)
	{
		page_max = 2; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"ふたご座に属する恒星で4等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"10.15日の周期で3.62等から4.18等まで変光する", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ケフェイド変光星の超巨星である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"。また分光連星でもあるが、伴星の詳細はわかっていない。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[ケフェイド変光星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"等級が変わることこの星の変光範囲は1～2等周期は2～50日", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ほどである。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[分光連星（ぶんこうれんせい）とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"望遠鏡を使用して分離できなくとも、周期的なスペクトル線の", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"移動やパルス周期の変動など、スペクトルの特徴の周期的な", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"変化によって2つ以上の天体からなることを", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"検出できる連星のこと。", left_end, IO_y + Interval_y * ver, font_size, c);
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
		page_max = 4; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"ふたご座に属する恒星で3等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"およそ232.9日の周期で3.15等から3.9等まで", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"変光する半規則型変光星の巨星であり、また伴星による", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"掩蔽で変光するアルゴル型変光星でもある。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"1781年にウィリアム・ハーシェルが天王星を発見したのは", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"この恒星の近くである。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[半規則型変光星(はんきそくがたへんこうせい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"かなり周期的に変光することもある一方時々不規則な光度変化を", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"することもある、中期から晩期のスペクトル型を持つ", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"巨星または超巨星である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[スペクトル分類とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"恒星の分類法の一つ。スペクトル分類によって細分された星の", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"タイプをスペクトル型と呼ぶ。恒星から放射された電磁波を", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"捉え、スペクトルを観察することによって分類する。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
		}
		else if (page == 2)
		{
			Font::StrDraw(L"[巨星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"半径および明るさが非常に大きい恒星。巨星の半径は", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"太陽の10倍から100倍、明るさは10倍から1000倍で", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ある。巨星より明るい恒星は、超巨星や極超巨星と呼ばれる。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[超巨星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"太陽よりはるかに大きく明るい恒星のこと。明るさは青色超巨星の", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"場合は太陽の1万倍（全エネルギー放射で太陽の10万倍）以上", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"赤色超巨星の場合は太陽の数千倍（同3万倍）以上ある。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
		}
		else if (page == 3)
		{
			Font::StrDraw(L"[アルゴル型変光星(アルゴルがたへんこうせい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"食変光星の分類の1つで、軌道平面が地球からの方角と", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"一致している。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[ウィリアム・ハーシェルとは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ドイツのハノーファー出身のイギリスの天文学者・音楽家", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"・望遠鏡製作者。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
		}
		//ページ制限
		else if (page < 1)
		{
			page = 0;
		}
		else if (page > 3)
		{
			page = 3;
		}
	}
	else if (crick == 8)
	{
		page_max = 2; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"ふたご座に属する恒星で3等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"太陽に比べ1,540倍以上のエネルギーを放出している。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"視直径は0.0135秒。地球から見た場合、他の恒星よりも", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"5倍以上の速度で移動しているように見える。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"地球から見て2分離れて位置する9等級の星は、近くに", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"見えているだけであり、実際にはμ星とは関連性は無いと", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"推測されている。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[角度の単位としての秒とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"分の1/60の角度である。1秒は1度の1/3600である。", left_end, IO_y + Interval_y * ver, font_size, c);
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
	else if (crick == 9)
	{
		page_max = 2; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"ふたご座に属する3等星の恒星である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"地球から約60光年離れた、F型主系列星あるいは準巨星で", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"太陽の1.7倍の質量と2.7倍の半径を持つ。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"年齢は15億年と若く、金属量は太陽とほぼ同程度と", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"されている。", left_end, IO_y + Interval_y * ver, font_size, c);
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
	else if (crick == 10)
	{
		page_max = 2; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"ふたご座に属する恒星で5等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"固有名の積水は、古代中国の天文学において二十八宿の", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"1つの井宿という星宿に含まれる星官で、水を貯えること", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"転じて用水池や海などを意味する。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2017年6月30日、国際天文学連合の恒星の固有名に関する", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ワーキンググループは、積水をふたご座ο星の固有名", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"として正式に承認した。", left_end, IO_y + Interval_y * ver, font_size, c);

		}
		else if (page == 1)
		{
			Font::StrDraw(L"[二十八宿(にじゅうはっしゅく)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"天球を、28のエリア(星宿)に不均等分割したもの。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"二十八舎（にじゅうはっしゃ）ともいう。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[天球とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"惑星や恒星がその上に張り付き運動すると考えられた", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"地球を中心として取り巻く球体のこと。", left_end, IO_y + Interval_y * ver, font_size, c);
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

}