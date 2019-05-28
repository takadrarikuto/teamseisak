//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjStarPresent8.h"
extern int lever;
extern int crick;
extern int cenge;
extern int star_count;

void CObjStarPresent8::Init()
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

void CObjStarPresent8::Action()
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

void CObjStarPresent8::Draw()
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

	if (star_count >=400)
	{
	//					　　	            X　 Y　 大きさ
	Font::StrDraw(L"アクベンス ", 20, 330 + t * l, 30, c);
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
	

	//					　　			    X　 Y　 大きさ
	Font::StrDraw(L"アルタルフ", 20, 330 + t * l, 30, c);
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
	

	//					　　		       X　 Y　 大きさ
	Font::StrDraw(L"アセルス・ボレアリス ", 10, 335 + t * l, 18, c);
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
	
	//					　　        X　        Y　    大きさ
	Font::StrDraw(L"アセルス・アウストラリス", 10, 340 + t * l, 18, c);
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

	Font::StrDraw(L"ストール ", 20 + 220, 320 + t * l, 30, c);
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
	

	//					　　			    X　 Y　 大きさ
	Font::StrDraw(L"テグミン ", 20 + 220, 330 + t * l, 30, c);
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
	

	//					　　		       X　 Y　 大きさ
	Font::StrDraw(L"ピアトス ", 20 + 220, 340 + t * l, 30, c);
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
	
	//					　　        X　        Y　    大きさ
	Font::StrDraw(L"ナハ", 20 + 220, 350 + t * l, 30, c);
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

	Font::StrDraw(L"コペルニクス ", 20 + 400, 320 + t * l, 30, c);
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
	


	if (crick == 1)
	{
		page_max = 2; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"かに座に属するる恒星系である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"かに座の中では4番目に明るく、4.20等級で良い条件の下では", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"肉眼での観測が可能である光度は太陽の23倍以上である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"黄道面の近くにあるため月や、稀に惑星による掩蔽が", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"起こることがある。", left_end, IO_y + Interval_y * ver, font_size, c);
			//8行目まで、改行
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[黄道とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"天球上における太陽の見かけ上の通り道（大円）をいう。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[掩蔽(えんぺい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ある天体が観測者と他の天体の間を通過するために、その天体が", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"隠される現象である。", left_end, IO_y + Interval_y * ver, font_size, c);
			//8行まで
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
		page_max = 5; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"かに座に属する最も明るい4等星の恒星である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"実視連星であり、主星のかに座β星Aは橙色のK型巨星で", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"バリウム星としても知られている。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"視等級は3.50等、絶対等級は-1.25等伴星", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"かに座β星Bは赤色矮星、主星から29秒離れた軌道を", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"76,000年で公転している。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[実視連星(二重星)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"望遠鏡で両星に分離して観測され、両星が公転運動している事が", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"確認されている連星を言う。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[巨星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"半径および明るさが非常に大きい恒星。巨星の半径は", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"太陽の10倍から100倍、明るさは10倍から1000倍で", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ある。巨星より明るい恒星は、超巨星や極超巨星と呼ばれる。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 2)
		{
			Font::StrDraw(L"[バリウム星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"スペクトル型がG型またはK型の巨星であるスペクトルから", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"S過程が過剰に進み455.4nmの一価のバリウムが", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"存在することが示唆されている。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[赤色矮星(せきしょくわいせい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"主系列星の中で特に小さい恒星のグループ。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 3)
		{
			Font::StrDraw(L"[スペクトル分類とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"恒星の分類法の一つ。スペクトル分類によって細分された星の", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"タイプをスペクトル型と呼ぶ。恒星から放射された電磁波を", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"捉え、スペクトルを観察することによって分類する。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[巨星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"半径および明るさが非常に大きい恒星。巨星の半径は", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"太陽の10倍から100倍、明るさは10倍から1000倍で", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ある。巨星より明るい恒星は、超巨星や極超巨星と呼ばれる。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 4)
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
		}
		//ページ制限
		else if (page < 1)
		{
			page = 0;
		}
		else if (page > 4)
		{
			page = 4;
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
			Font::StrDraw(L"かに座に属する恒星で5等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"準巨星とされているが、理論からは主系列星と推測されている。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"10等星と12等星の恒星と三重星に見えるがいずれも", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"連星ではない。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"0等星と12等星の恒星と三重星に見えるが、いずれも連星", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ではない。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[準巨星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"同じスペクトル型の通常の主系列星よりやや明るく", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"巨星ほどは明るくない恒星の分類の1つである。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[三重星(多重星(たじゅうせい))とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"地球から見ると近接した位置に見える3つ以上の恒星である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[連星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2つ以上の恒星が両者の重心の周りを軌道運動している天体で", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ある。双子星（ふたごぼし）とも呼ばれる。", left_end, IO_y + Interval_y * ver, font_size, c);
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
		page_max = 2; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"かに座に属する恒星で4等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"黄道からわずか5分に位置しているため、太陽系の惑星を", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"掩蔽することがある。過去には連星である可能性が", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"疑われたが、現在ではおそらく伴星は存在しないものと", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"思われている。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[黄道(こうどう)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"天球上における太陽の見かけ上の通り道（大円）をいう。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[掩蔽(えんぺい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ある天体が観測者と他の天体の間を通過するために、その天体が", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"隠される現象である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[連星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2つ以上の恒星が両者の重心の周りを軌道運動している天体で", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ある。双子星（ふたごぼし）とも呼ばれる。", left_end, IO_y + Interval_y * ver, font_size, c);
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
		page_max = 3; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"かに座に属する恒星で6等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"白色のA型主系列星で、プレセペ星団で明るい星の1つである。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"かに座ε星というバイエル符号は、元々はプレセペ星団全体に", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"付けられたものであった。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[A型主系列星(Aがたしゅけいれっせい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"水素を燃やして燃える主系列星である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"太陽の1.4倍から2.1倍の質量を持ち、表面温度は", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"7600Kから10000Kの間である。", left_end, IO_y + Interval_y * ver, font_size, c);
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
		}
		else if (page == 2)
		{
			Font::StrDraw(L"[プレセペ星団(プレセペせいだん)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"かに座にある散開星団である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[散開星団(さんかいせいだん)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"恒星の集団（星団）の一種である。", left_end, IO_y + Interval_y * ver, font_size, c);
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
	else if (crick == 6)
	{
		page_max = 1; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);


		Font::StrDraw(L"かに座に属する少なくとも4つの恒星から構成される恒星系", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"である。黄道面の付近にあるため、月や稀に惑星による掩蔽が", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"観測されることがある。", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"固有名のテグミンは、ラテン語で「（カニの）殻」という", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"意味の言葉に由来する。", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"[掩蔽(えんぺい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"ある天体が観測者と他の天体の間を通過するために、その天体が", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"隠される現象である。", left_end, IO_y + Interval_y * ver, font_size, c);

		//ページ制限
		if (page < 0 || page  > 0)
		{
			page = 0;
		}

	}
	else if (crick == 7)
	{
		page_max = 3; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);


		if (page == 0)
		{
			Font::StrDraw(L"かに座に属する恒星で6等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"この星は青白いB型主系列星である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2018年6月1日に国際天文学連合の恒星の命名に関する", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ワーキンググループ(WGSN)は、ピアトスをかに座λ星の", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"固有名として正式に承認した。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[B型主系列星とは]…スペクトル型がB、光度階級がVの", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"水素の核融合で燃える主系列星である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"太陽の2倍から16倍の質量を持ち", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"表面温度は10,000Kから30,000Kの間である", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"B型主系列星は希な存在で、主系列星全体に占める割合は", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"0.1%程度に過ぎないと考えられている。", left_end, IO_y + Interval_y * ver, font_size, c);
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
	else if (crick == 8)
	{
		page_max = 1; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);


		Font::StrDraw(L"かに座に属する恒星で5等星。", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"固有名のハナは、ペルシア語で「鼻」という意味の言葉に", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"由来する。", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"2018年6月1日、国際天文学連合の恒星の命名に関する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"ワーキンググループ(WGSN)は、かに座ξ星Aの固有名", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"としてナハを正式に承認した。", left_end, IO_y + Interval_y * ver, font_size, c);

		//ページ制限
		if (page < 0 || page > 0)
		{
			page = 0;
		}

	}
	else if (crick == 9)
	{
		page_max = 3; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);		

		if (page == 0)
		{
			Font::StrDraw(L"かに座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"太陽系から41光年の距離にあるかに座の連星系である", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"太陽に似たG型主系列星（かに座55番星A）と", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"赤色矮星（かに座55番星B）から構成され、2つの天体は", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"1000天文単位以上離れている。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2008年までに、かに座55番星Aの周りには5つの太陽系外惑星が", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"発見されている", left_end, IO_y + Interval_y * ver, font_size, c);			
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[連星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2つ以上の恒星が両者の重心の周りを軌道運動している天体で", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ある。双子星（ふたごぼし）とも呼ばれる。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[G型主系列星(Gがたしゅけいれつせい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"スペクトル型がG型、光度階級がVの恒星（主系列星）のこと。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"中心部での水素の核融合をエネルギー源とする主系列星で", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"太陽はG型主系列星の一つである", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 2)
		{
			Font::StrDraw(L"[赤色矮星(せきしょくわいせい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"主系列星の中で特に小さい恒星のグループ。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[太陽系外惑星(たいようけいがいわくせい)または系外惑星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"太陽系の外にある惑星である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"019年5月1日時点で4,058個の太陽系外惑星が確認", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"されており、惑星系を持つことが確認されている恒星は", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"3,033個で、そのうち658個が複数の惑星を持っている。", left_end, IO_y + Interval_y * ver, font_size, c);
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
else
	{
	ver = 0;
	Font::StrDraw(L"この星々を閲覧するには合計で星を400個集めてください", left_end, IO_y + Interval_y * ver, font_size, c);
	}

}