//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameL\Audio.h"
#include "GameHead.h"
#include "ObjStarPresent3.h"
extern int lever;
extern int crick;
extern int cenge ;
extern int star_count;

void CObjStarPresent3::Init()
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

	a_time = 0;
	time_flag = false;	
	m_mou_time = 0.0f;

	Back_time = 0.0f;

	Audio::LoadAudio(1, L"効果音.wav", EFFECT);
}

void CObjStarPresent3::Action()
{

	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	//連続移動防止
	if (m_mou_time == 60.0f)
	{
		;
	}
	else if (m_mou_time < 60.0f)
	{
		m_mou_time++;
		m_mou_l = false;
	}

	//SE発生処理
	if (m_mou_l == true)
	{
		time_flag = true;
	}
	else if (m_mou_l == false)
	{
		a_time = 0;
		time_flag = false;
	}

	//SE発生処理
	if (time_flag == true)
	{
		a_time++;
	}
	if (a_time == 1)
	{
		Audio::Start(1);
	}
	
	Back_time++;

	//星座選択へボタン
	// left				 right            top            bottom         
	if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>0 && m_mou_y < 100)
	{
		if (m_mou_l == true)
		{
			time_flag = true;
			if (a_time == 5)
			{
				lever = 0;
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
				Scene::SetScene(new CSceneStarPicbook());
				return;
			}
		}
	}
	//ｂを押すと戻る
	else if (Input::GetVKey('B') == true && Back_time > 60.0f)
	{
		lever = 0;
		a_time = 0;
		Back_time = 0.0f;
		time_flag = false;
		Scene::SetScene(new CSceneStarPicbook());
	}


}

void CObjStarPresent3::Draw()
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

	if (star_count >=0)
	{
		//					　　	            X　 Y　 大きさ
		Font::StrDraw(L"ズベン・エル・ゲヌビ", 2, 330 + t * l, 20, c);
		l++;

		if (start_flag == true)
		{
			// left				 right            top            bottom               
			if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
			{
				if (m_mou_l == true)
				{
					crick = 1;
					page = 0;
				}
			}
		}


		//					　　			    X　 Y　 大きさ
		Font::StrDraw(L"ズベン・エス・カマリ", 2, 330 + t * l, 20, c);
		l++;

		if (start_flag == true)
		{
			// left				 right            top            bottom               
			if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
			{
				if (m_mou_l == true)
				{
					crick = 2;
					page = 0;
				}
			}
		}


		//					　　		       X　 Y　 大きさ
		Font::StrDraw(L"ズベンエルハクラビ", 10, 330 + t * l, 20, c);
		l++;

		if (start_flag == true)
		{
			// left				 right            top            bottom               
			if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
			{
				if (m_mou_l == true)
				{
					crick = 3;
					page = 0;
				}
			}
		}

		//					　　        X　        Y　    大きさ
		Font::StrDraw(L"ブラキウム", 25, 330 + t * l, 20, c);
		l++;

		if (start_flag == true)
		{
			// left				 right            top            bottom               
			if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
			{
				if (m_mou_l == true)
				{
					crick = 4;
					page = 0;
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
				Font::StrDraw(L"てんびん座に属する二重星である。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"α1星とα2星の2つの恒星は、地球から231秒離れて", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"見える。黄道がこの恒星にとても近いところを通っているため", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"月（ごくまれに惑星）による掩蔽（星食）が起こりやすい。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"この星は二重星で、空気が澄んでいれば肉眼で見わけられる。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"アラビア語で「南の爪」を意味する。", left_end, IO_y + Interval_y * ver, font_size, c);
				//8行目まで、改行
			}
			else if (page == 1)
			{
				//8行まで
				Font::StrDraw(L"[黄道(こうどう)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"天球上における太陽の見かけ上の通り道（大円）をいう。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[掩蔽(えんぺい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"ある天体が観測者と他の天体の間を通過するために、その天体が隠される現象である。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[二重星（にじゅうせい）とは]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"地球上から見る恒星が同じ方向に近接して見える物を指す。", left_end, IO_y + Interval_y * ver, font_size, c);
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
			page_max = 1; //最大ページ数
			ver = VER_start; //文字間隔初期化

			//ページ数表示
			swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
			Font::StrDraw(strp, pagex, pagey, pagesize, c);

			Font::StrDraw(L"てんびん座に属する最も明るい恒星で3等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"視差から、地球からの距離は185光年と推測される。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"この星の高温はシンプルなスペクトルの光を生成し、地球と", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"この星との間の星間ガスと塵を調査するのに理想的である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"同種の多くの星のように、高速で回転しており、太陽の100倍", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"以上の自転速度である。この種の星は通常は青白く見えるが", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"この星は緑色と表現される事がよくあり、これは肉眼で見える", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"唯一の緑色の恒星である。", left_end, IO_y + Interval_y * ver, font_size, c);
			//8行目まで、改行
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
				Font::StrDraw(L"てんびん座に属する恒星で4等星。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"二重星でおそらく連星であると考えられている。その場合", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"地球からは主星Aと42.5秒離れて見える伴星Bは", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"主星Aから少なくとも2,100au離れた軌道を", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"55,000年以上かけて回っている", left_end, IO_y + Interval_y * ver, font_size, c);
				//8行目まで、改行
			}
			else if (page == 1)
			{
				//8行まで
				Font::StrDraw(L"[二重星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"地球上から見る恒星が同じ方向に近接して見える物を指す。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"肉眼では1つの星に見えるが、望遠鏡などで観測する事によって", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"2つに分解する。", left_end, IO_y + Interval_y * ver, font_size, c);
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
				Font::StrDraw(L"[角度の単位としての秒とは]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"分の1/60の角度である。1秒は1度の1/3600である。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[天文単位(au)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"長さの単位で、正確に 149597870700 m である。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
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
				Font::StrDraw(L"てんびん座に属する恒星で3等星。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"さそり座の他の恒星と離れた位置にあることから", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"「さそり座y星」をてんびん座の一部とし、新たに", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"「てんびん座σ星」という符号を振り直した。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"この恒星は赤色巨星で、規則性の低いSRB型の半規則型の", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"脈動変光星に分類されており、20日前後の周期で", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"0.26等級の範囲で変光している。", left_end, IO_y + Interval_y * ver, font_size, c);
				//8行目まで、改行
				ver++;
			}
			else if (page == 1)
			{
				//8行まで
				Font::StrDraw(L"[赤色巨星(せきしょくきょせい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"恒星が主系列星を終えたあとの進化段階である。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[半規則型変光星(はんきそくがたへんこうせい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"一方時々不規則な光度変化をすることもあるスペクトル型を", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"持つ巨星または超巨星である。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[脈動変光星(みゃくどうへんこうせい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"膨張と収縮を繰り返すことにより、または星の形状が", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"変化することにより明るさが変化する変光星のこと。", left_end, IO_y + Interval_y * ver, font_size, c);
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
	else
	{
	ver = 0;
	Font::StrDraw(L"この星々を閲覧するには合計で星を150個集めてください", left_end, IO_y + Interval_y * ver, font_size, c);
	}
}