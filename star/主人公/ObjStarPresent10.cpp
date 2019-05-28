//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameL\Audio.h"
#include "GameHead.h"
#include "ObjStarPresent10.h"
extern int lever;
extern int crick;
extern int cenge;


void CObjStarPresent10::Init()
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

void CObjStarPresent10::Action()
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

void CObjStarPresent10::Draw()
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
	Font::StrDraw(L"スピカ", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"サヴィヤヴァ", 20, 330 + t * l, 30, c);
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
	Font::StrDraw(L"ポリマ", 20, 330 + t * l, 30, c);
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
	Font::StrDraw(L"ミネラウバ", 20, 330 + t * l, 30, c);
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
	Font::StrDraw(L"ヴィンデミアトリックス", 20 + 180, 330 + t * l, 18, c);
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
	Font::StrDraw(L"ザニア", 20 + 220, 330 + t * l, 30, c);
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
	Font::StrDraw(L"シュルマ", 20 + 220, 340 + t * l, 30, c);
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
	
	Font::StrDraw(L"カング", 20 + 220, 340 + t * l, 30, c);
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
	Font::StrDraw(L"カンボリア", 20 + 400, 320 + t * l, 30, c);
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
	Font::StrDraw(L"エレガラファ", 20 + 400, 330 + t * l, 30, c);
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
		page_max = 2; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"おとめ座に属する最も明るい恒星で全天21の1等星の1つ。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"春の夜に青白く輝く。共にB型のスペクトルを持つ0.98等と", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"10.5等の恒星からなる連星系である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"0.17日の周期で0.015等変光している。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[連星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2つの恒星が両者の重心の周りを軌道運動している天体", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"である。双子星（ふたごぼし）とも呼ばれる。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[変光とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"明るさ（等級）が変化するもののことである。", left_end, IO_y + Interval_y * ver, font_size, c);
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
		page_max = 2; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"おとめ座に属するおとめ座の方角にある恒星で4等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"太陽よりも大きく重く、比較的金属量に富んでいる黄道に", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"かなり近い位置にあるため、月や時には惑星による掩蔽が", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"観測される。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[黄道(こうどう)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"天球上における太陽の見かけ上の通り道（大円）をいう。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
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
		else if (page > 1)
		{
			page = 1;
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
			Font::StrDraw(L"おとめ座に属するおとめ座にある3等級の連星である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"F型主系列星同士からなる連星である。伴星は主星の周りを", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"168.93年で公転している。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ポリマは、黄道の近くにあるので、稀に惑星や月による掩蔽が", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"発生する。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"恒星磁場の強さを示すX線の観測値から、年齢は", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"約11億4000万年と見られている。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[F型主系列星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"スペクトル型がF、光度階級がVの水素を燃やして燃える", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"主系列星である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[連星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2つの恒星が両者の重心の周りを軌道運動している天体", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"である。双子星（ふたごぼし）とも呼ばれる。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 2)
		{
			Font::StrDraw(L"[掩蔽(えんぺい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ある天体が観測者と他の天体の間を通過するために、その天体が", left_end, IO_y + Interval_y * ver, font_size, c);
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
	else if (crick == 4)
	{
		page_max = 2; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"おとめ座に属する恒星で3等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"この星は赤色巨星分岐 (RGB) の段階にある。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"地球から観測して80秒離れた位置に見える11等星は伴星の", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"可能性があるとされる。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"主星の位置から見た伴星は金星の2倍の明るさに見え、伴星の", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"位置から見た主星は満月の4倍の明るさに見える。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[赤色巨星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"恒星が主系列星を終えたあとの進化段階である大気が膨張し", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"その大きさは地球の公転軌道半径から火星のそれに相当する。", left_end, IO_y + Interval_y * ver, font_size, c);
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
			Font::StrDraw(L"おとめ座に属する恒星である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"3等星の黄色巨星で、おとめ座ではα星のスピカ、γ星のポリマに", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"次いで明るい年に0.2秒という高速で移動して見える。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"中心部では水素からヘリウムへの核融合を終え、ヘリウムの燃焼", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"(CNOサイクル)が始まっているものと考えられている。", left_end, IO_y + Interval_y * ver, font_size, c);
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
			Font::StrDraw(L"[CNOサイクルとは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"恒星内部で水素がヘリウムに変換される核融合反応過程の一種", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"である。", left_end, IO_y + Interval_y * ver, font_size, c);
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
		page_max = 3; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"おとめ座に属する恒星で4等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"分光連星で、3つの星から成る連星系であると考えられている。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"伴星の1つは、平均約10au離れた軌道を13.12年を", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"掛けて周回している。さらに主星には約0.5auの軌道を", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"72日の周期で回る伴星があると見られる。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
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
		else if (page == 2)
		{
			Font::StrDraw(L"[連星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2つの恒星が両者の重心の周りを軌道運動している天体", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"である。双子星（ふたごぼし）とも呼ばれる。", left_end, IO_y + Interval_y * ver, font_size, c);
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
	else if (crick == 7)
	{
		page_max = 2; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"おとめ座に属するおとめ座の方角にある恒星で4等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2010年に周囲を55年で公転する伴星を発見したとする", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"研究結果が発表された。伴星の直接検出には成功していないが", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"太陽の0.6倍の質量を持つ主系列星か白色矮星であると", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"考えられている。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
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
			Font::StrDraw(L"[白色矮星(はくしょくわいせい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"恒星が進化の終末期にとりうる形態の一つ。", left_end, IO_y + Interval_y * ver, font_size, c);
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
		page_max = 2; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"おとめ座に属する恒星で4等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"中国の二十八宿の１つ「亢 (Kang)」の距星とされる", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"、国際天文学連合の恒星の命名に関するワーキンググループ", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"(WGSN)は、おとめ座κ星の固有名として、カングを正式に", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"承認した。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[二十八宿(にじゅうはっしゅく)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"天球を、28のエリア(星宿)に不均等分割したもの。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"二十八舎（にじゅうはっしゃ）ともいう。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[月宿(げっしゅく)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"天球上の天の赤道付近（本来は月の通り道である白道）を", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"27ないし28のエリアに分割したものいずれも「月の宿り」を", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"意味するが日本や中国では一般に星宿と呼んでいる。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"月宿は世界各地に見られる。", left_end, IO_y + Interval_y * ver, font_size, c);
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
			Font::StrDraw(L"おとめ座に属する恒星で5等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"5.00等の主星と5.63等の伴星による分光連星である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2017年9月5日、国際天文学連合の恒星の命名に関する", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ワーキンググループ(WGSN)は、カンボリアを", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"おとめ座λ星Aの固有名として正式に承認した。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
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
			Font::StrDraw(L"おとめ座に属する恒星で5等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"4.92等の黄色巨星または準巨星のA星と10.02等の", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"橙色矮星のB星からなる連星系でA星自身も分光連星である", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"可能性を示唆されている。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2018年6月1日、国際天文学連合の恒星の命名に関する", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ワーキンググループ(WGSN)は、エレガラファを", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"おとめ座φ星Aの固有名として正式に承認した。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"", left_end, IO_y + Interval_y * ver, font_size, c);
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
		else if (page > 2)
		{
			page = 2;
		}
	}

}
