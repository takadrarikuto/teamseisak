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
	IO_y = 25; //y座標開始地点25
	Interval_y = 35;//文字の立幅間隔35
	left_end = 80;//説明文の左の限界を決める
	pagex = 680; //ページ座標x
	pagey = 10; //ページ座標y
	pagesize = 20; //ページサイズ

	 g = 200.0f;//星枠の横幅
	 k = 75.0f;//星枠の立幅
	 t = 70;//星の名前の位置
	 l = 0;//tと掛ける用の変数
	 s = 0;//星のクリックの鍵
	 std = 0;//文字を横に移す変数
	 side_a = 0;//左の枠範囲
	 side_b = 200;//右の枠範囲
	 fy = 200;//星の名前の横幅
	 font_size = 25;//文字の大きさ
	  Interval_y = 35;//文字の立幅間隔
	  left_end = 80;//説明文の左の限界を決める
	 page = 0;//現在のページ数
	 pagemax=0;//最大ページ数
}

void CObjStarPresent::Action()
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
			return;
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

	if (start_time >30.0f)
	{
		start_flag = true;
	}
	else
	{
		start_flag = false;
	}
}

void CObjStarPresent::Draw()
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

	//戻るを押したら
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

	
	//					　　	 X　		    Y　 大きさ
	Font::StrDraw(L"アンタレス", 30 + fy * std, 330 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left								right						top								　bottom                            
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 1;//ここはキーのようなもの
				page = 0; //ページ初期化
			}
		}
	}

	if (crick == 1)//上を変えたらここも変える
	{
		page_max = 1; //最大ページ数
		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);
		
		ver = VER_start; //文字間隔初期化
		Font::StrDraw(L"さそり座で最も明るい恒星で全天21の1等星の1つ。夏の南の空", left_end, IO_y + Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"に赤く輝くよく知られる恒星の1つである。", left_end, IO_y + Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"アンタレスはかつて直径が太陽の230倍とされ、「理科年表」も", left_end, IO_y + Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"長らくこの値を採用していたが、実際はもっと大きな星で、直", left_end, IO_y + Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"径は太陽の600倍ないし800倍である。", left_end, IO_y + Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"明るさは太陽の8000倍ないし1万倍と考えられている。なお、赤", left_end, IO_y + Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"外線を含めて計算すると明るさは太陽の6.5万倍である。", left_end, IO_y + Interval_y*ver, font_size, c);
	
		//ページ制限
		if (page < 0 || page > 0)
		{
			page = 0;
		}
	}
	
	//					　　	 X　 Y　 大きさ
	Font::StrDraw(L"アクラブ", 30 + fy * std, 330+t*l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left								right						top							　　　bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 2;//ここはキーのようなもの
				page = 0; //ページ初期化
			}
		}
	}


	if (crick == 2)//上を変えたらここも変える
	{
		page_max = 1; //最大ページ数
		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		ver = VER_start; //文字間隔初期化
		Font::StrDraw(L"さそり座の恒星で3等星かつ六重連星。", left_end, IO_y + Interval_y*ver, font_size,c);
		ver++;
		Font::StrDraw(L"[連星とは?]お互いの重力に引かれあったり離れたりを繰り返し", left_end, IO_y + Interval_y*ver, font_size,  c);
		ver++;
		Font::StrDraw(L"をしている。肉眼で見た場合は一つに見えるが、望遠鏡", left_end, IO_y + Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"など遠距離で見た場合二つに分裂する。", left_end, IO_y + Interval_y*ver, font_size, c);
	
		//ページ制限
		if (page < 0 || page > 0)
		{
			page = 0;
		}
	}
	

	Font::StrDraw(L"ジュバ", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	// left								right						top						bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			pagemax = 1;
			crick = 3;//ここはキーのようなもの
		
		}
	}

	if (crick == 3)
	{
		if (page == 0)//上を変えたらここも変える
		{
			ver = 0;
			Font::StrDraw(L"さそり座の恒星で2等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"Be星の中でも爆発型変光星のカシオペヤ座γ型変光星であると", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"考えられている。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[爆発型変光星とは？]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"爆発型変光星は変光星の一種。恒星の外層や大気の爆発によっ", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"て変光する星。", left_end, IO_y + Interval_y * ver, font_size, c);
			//7行目で、改行

		}
		else if (page == 1)
		{
			ver = 0;
			Font::StrDraw(L"[カシオペヤ座γ型変光星とは？]", left_end, IO_y + Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"ガス殻星のことであり、物質の流出のため、光度は不規則に", left_end, IO_y + Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"変化する。", left_end, IO_y + Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"ガス殻星は高速で自転し、その機構に一定の説明を与えている", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"が、未だ謎が残っている。変光星の場合、カシオペヤ座γ型変 ", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"光星に分類される。", left_end, IO_y + Interval_y * ver, font_size, c);
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


	Font::StrDraw(L"ララワグ", 30 + fy * std, 330 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left								right						top						bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 4;//ここはキーのようなもの
				page = 0; //ページ初期化
			}
		}
	}

		if (crick == 4)//上を変えたらここも変える
		{
			ver = 0;
			Font::StrDraw(L"さそり座の恒星で2等星。 ", left_end, Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"2017年11月17日、国際天文学連合の恒星の命名に関するワーキ", left_end, Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"ンググループ は、さそり座ε星の固有名として、ララワグを", left_end, Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"正式に定めた。", left_end, Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"これは、オーストラリアのノーザン・テリトリーに住むオース", left_end, Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"トラリア先住民のワルダマン族が使っていた呼称を採用したも ", left_end, Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"のである。", left_end, Interval_y*ver, font_size, c);
		}
	

	t -= 4;
	l -= 4;
	std++;//四つ星を表示したらstdを入れる
	Font::StrDraw(L"サルガス", 30 + fy * std, 330 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left								right						top						bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 5;//ここはキーのようなもの
				page = 0; //ページ初期化
			}
		}



		if (crick == 5)//上を変えたらここも変える
		{
			page_max = 1; //最大ページ数
			//ページ数表示
			swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
			Font::StrDraw(strp, pagex, pagey, pagesize, c);

			ver = VER_start; //文字間隔初期化
			Font::StrDraw(L"薄黄色の輝巨星。2等星のA星と6等星のB星の二重星である。 ", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[輝巨星とは？]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"輝巨星は、二等星ほどの明るさを持つ恒星である。これらは ", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"巨星から超巨星にまたがる大きさであるが、通常は超巨星ほ", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ど明るく重いわけではなく、極めて明るい巨星に分類される。", left_end, IO_y + Interval_y * ver, font_size, c);

			//ページ制限
			if (page < 0 || page > 0)
			{
				page = 0;
			}
		}


		//					　　	 X　		    Y　 大きさ
		Font::StrDraw(L"ギルタブ", 30 + fy * std, 330 + t * l, 30, c);
		l++;

		if (start_flag == true)
		{
			// left								right						top								　bottom                            
			if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
			{
				if (m_mou_l == true)
				{
					crick = 6;//ここはキーのようなもの
					page = 0; //ページ初期化
				}
			}
		}

		if (crick == 6)//上を変えたらここも変える
		{
			page_max = 1; //最大ページ数
			//ページ数表示
			swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
			Font::StrDraw(strp, pagex, pagey, pagesize, c);

			ver = VER_start; //文字間隔初期化
			Font::StrDraw(L"この恒星は分光連星で、主星はケフェウス座β型変光星である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"分光観測により、公転周期は195日と測定された。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"明るさの変化は、4.80時間、4.93時間である。", left_end, IO_y + Interval_y * ver, font_size, c);

		}


		//					　　	 X　 Y　 大きさ
		Font::StrDraw(L"シャウラ", 30 + fy * std, 330 + t * l, 30, c);
		l++;
		// left								right						top							　　　bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				pagemax = 1;
				crick = 7;//ここはキーのようなもの
				page = 0; //ページ初期化
			}
		}
		if (crick == 7)
		{
			if (page == 0)//上を変えたらここも変える
			{
				ver = 0;
				Font::StrDraw(L"さそり座の恒星で2等星。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"さそり座ではアンタレスに次いで明るい恒星である。青白色の", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"準巨星。ケフェウス座β型変光星であり、わずかに変光するが", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"変光範囲が小さいので眼視観測ではこの変光はわからない。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"この星は3つの星からなる重星である。λ星Bは15等星で", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"λ星Aとλ星Bは42秒離れている。ただしこれらが物理的な", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"どうかは知られていない。もし連星だとするなら、AとBの間", left_end, IO_y + Interval_y * ver, font_size, c);
			}
			else if (page == 1)//上を変えたらここも変える
			{
				ver = 0;
				Font::StrDraw(L"は7,500天文単位、AとCの間は17,000天文単位（0.27光年） ", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"離れていることになる。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"ことになる。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[重星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"地球上から見て一つの星に見える星のこと、ただし連星と", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"は違い見かけ上は一つの星に見えるというだけで実際には", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"重なっている星々は距離が離れている。", left_end, IO_y + Interval_y * ver, font_size, c);
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


		Font::StrDraw(L"ゼミディムラ", 10 + fy * std, 340 + t * l, 30, c);
		l++;
		// left								right						top						bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				pagemax = 1;
				crick = 8;//ここはキーのようなもの
				page = 0; //ページ初期化
			}
		}
		if (crick == 8) {
			if (page == 0)//上を変えたらここも変える
			{
				ver = 0;
				Font::StrDraw(L"さそり座に位置する重星。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"μ1星とμ2星で構成される。この2つの恒星は、連星で", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"あるという主張と単なる見かけの二重星であるという主張の", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"両方が存在しているがガイア計画での年周視差の測定値が", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"正しければ490光年近く離れており連星ではではないと", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"考えられる。μ1星は、2つのB型星から成る連星で", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"約1日半で公転している。Xamidimura は、", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"アフリカ大陸南部に住むコイコイ人の言葉で", left_end, IO_y + Interval_y * ver, font_size, c);
			}
			else if (page == 1)//上を変えたらここも変える
			{
				//7行まで
				ver = 0;
				Font::StrDraw(L"「ライオンの眼」を意味する xami di muraに由来する", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[二重星・重星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"地球上から見る恒星が同じ方向に近接して見える物を指す。", left_end, IO_y + Interval_y * ver, font_size, c);
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

		t -= 4;
		l -= 4;
		std++;//四つ星を表示したらstdを入れる
		Font::StrDraw(L"ピピリマ", 30 + fy * std, 330 + t * l, 30, c);
		l++;

		if (start_flag == true)
		{
			// left								right						top						bottom               
			if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
			{
				if (m_mou_l == true)
				{

					crick = 9;//ここはキーのようなもの
					page = 0; //ページ初期化

				}
			}
		}


		if (crick == 9)//上を変えたらここも変える
		{
			page_max = 1; //最大ページ数
			//ページ数表示
			swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
			Font::StrDraw(strp, pagex, pagey, pagesize, c);

			ver = VER_start; //文字間隔初期化
			Font::StrDraw(L"Pipirima は、タヒチの伝承に登場する双子の男女に由来する", left_end, IO_y + Interval_y * ver, font_size, c);

			//ページ制限
			if (page < 0 || page > 0)
			{
				page = 0;
			}
		}

		Font::StrDraw(L"ジャバハー", 30 + fy * std, 340 + t * l, 30, c);
		l++;
		// left								right						top						bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				pagemax = 1;
				crick = 10;//ここはキーのようなもの
				page = 0; //ページ初期化
			}
		}
		if (crick == 10) {
			if (page == 0)//上を変えたらここも変える
			{
				ver = 0;
				Font::StrDraw(L"地球から見てさそり座の方向に約500光年離れた位置にある", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"4等級の恒星である。さそり座ν星は、7つの恒星から成る", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"七重連星系である。最も明るい恒星Aaは、太陽の約6倍の", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"質量と、2,900倍の光度を持つB型主系列星である。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[連星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"2つの恒星が両者の重心の周りを軌道運動している天体", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"である。双子星（ふたごぼし）とも呼ばれる。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[B型主系列星（Bがたしゅけいれっせい）とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			}
			else if (page == 1)//上を変えたらここも変える
			{
				//7行まで
				ver = 0;
				Font::StrDraw(L"スペクトル型がB、光度階級がVの、水素の核融合で燃える", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"主系列星である。太陽の2倍から16倍の質量を持ち", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"表面温度は10,000Kから30,000Kの間である。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"B型主系列星は希な存在で、主系列星全体に占める割合は", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"0.1%程度に過ぎないと考えられている", left_end, IO_y + Interval_y * ver, font_size, c);
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

		//					　　	 X　		    Y　 大きさ
		Font::StrDraw(L"ファング", 30 + fy * std, 350 + t * l, 30, c);
		l++;

		// left								right						top								　bottom                            
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				pagemax = 1;
				crick = 11;//ここはキーのようなもの
				page = 0; //ページ初期化
			}
		}
		if (crick == 11) {
			if (page == 0)//上を変えたらここも変える
			{
				ver = 0;
				Font::StrDraw(L"さそり座の恒星で3等星。この星は三重星である。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"さそり座π星Aはこと座β型変光星の接触連星である。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"どちらも熱い青白色のB型主系列星である。公転周期は", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"1.57日で、わずかに太陽半径の15倍だけ離れている。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"さらに遠くを+12.2等級の暗い伴星さそり座π星Bが", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"公転している。地球から見て50秒ほど離れ、少なくとも", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"7000天文単位の公転軌道であると考えられている。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[接触連星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			}
			else if (page == 1)//上を変えたらここも変える
			{
				//7行まで
				ver = 0;
				Font::StrDraw(L"恒星間の距離が近すぎて表面が接触しているか、あるいは", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"融合してガスの外層を共有しているような連星である。", left_end, IO_y + Interval_y * ver, font_size, c);
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

		//					　　	 X　 Y　 大きさ
		Font::StrDraw(L"イクリール", 30 + fy * std, 360 + t * l, 30, c);
		l++;
		// left								right						top							　　　bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				pagemax = 1;
				crick = 12;//ここはキーのようなもの
				page = 0; //ページ初期化
			}
		}
		if (crick == 12)
		{
			if (page == 0)//上を変えたらここも変える
			{
				ver = 0;
				Font::StrDraw(L"さそり座の恒星で4等星。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"B型のスペクトルを持つ準巨星である主星Aと約40秒離れた", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"位置に見える伴星Bの二重星である。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"主星Aは、これ自体が分光連星であるが、あまりに2つの星が", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"近くにあるため詳細はわかっていない。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[二重星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"ルが[光が299.792.458分の1秒間に進む距離]と定義されてい", left_end, IO_y + Interval_y * ver, font_size, c);

			}
			else if (page == 1)//上を変えたらここも変える
			{
				ver = 0;
				Font::StrDraw(L"るので、1光秒は正確に 299.792.458 m となる。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[分光連星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"変化によって2つ以上の天体からなることを検出できる", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"連星のこと。", left_end, IO_y + Interval_y * ver, font_size, c);
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
		t -= 4;
		l -= 4;
		std++;//四つ星を表示したらstdを入れる
		Font::StrDraw(L"アル・ニヤト", 10 + fy * std, 330 + t * l, 30, c);
		l++;

		if (start_flag == true)
		{
			// left								right						top						bottom               
			if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
			{
				if (m_mou_l == true)
				{
					crick = 13;//ここはキーのようなもの
					page = 0; //ページ初期化
				}
			}
		}
		if (crick == 13)
		{
			if (page == 0)//上を変えたらここも変える
			{
				ver = 0;
				Font::StrDraw(L"さそり座にある恒星で3等星。地球からの距離は696光年", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"（214パーセク）と推定されている。恒星系の主星は", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"二重線の分光連星であり望遠鏡では解像できない。33.01日の", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"軌道周期で軌道離心率は0.32と推定されている。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"固有名のアル・ニヤトは、アラビア語で「動脈」から来ている。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[光年とは]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"主として天文学で用いられる距離（長さ）の単位であり", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"約9.5兆キロメートルである。", left_end, IO_y + Interval_y * ver, font_size, c);
			}
			else if (page == 1)//上を変えたらここも変える
			{

				//7行まで
				ver = 0;
				Font::StrDraw(L"[パーセクとは]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"距離を表す計量単位であり、約3.26光年である。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"主として天文学で使われる。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[分光連星(ぶんこうれんせい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"望遠鏡を使用して分離できなくとも、周期的なスペクトル線の", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"移動やパルス周期の変動など、スペクトルの特徴の周期的な", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"変化によって2つ以上の天体からなることを検出できる", left_end, IO_y + Interval_y * ver, font_size, c);
			}
			else if (page == 2)//上を変えたらここも変える
			{
				//7行まで
				ver = 0;
				Font::StrDraw(L"連星のこと。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[軌道離心率(きどうりしんりつ)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"天体の軌道の絶対的な形を決める重要なパラメータである。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"軌道離心率は、この形がどれだけ円から離れているかを表す値", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"であると言う事ができる。", left_end, IO_y + Interval_y * ver, font_size, c);
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
		//					　　	 X　		    Y　 大きさ
		Font::StrDraw(L"レサト", 30 + fy * std, 340 + t * l, 30, c);
		l++;

		if (start_flag == true)
		{
			// left								right						top								　bottom                            
			if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
			{
				if (m_mou_l == true)
				{
					crick = 14;//ここはキーのようなもの
					page = 0; //ページ初期化
				}
			}
		}

		if (crick == 14) {
			if (page == 0)//上を変えたらここも変える
			{
				ver = 0;
				Font::StrDraw(L"さそり座の恒星で3等星。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"シャウラと肉眼でも見える二重星となっている。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"ただし2つの星は180光年離れており、連星ではない。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"太陽質量の10倍の質量という超新星爆発を起こすか白色矮星と", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"なるかの境であるが、酸素、ネオン、マグネシウムだけで", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"構成された非常に質量の大きな白色矮星になるものと", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"考えられている。", left_end, IO_y + Interval_y * ver, font_size, c);
			}
			else if (page == 1)//上を変えたらここも変える
			{

				//7行まで
				ver = 0;
				Font::StrDraw(L"[二重星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"地球上から見る恒星が同じ方向に近接して見える物を指す。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[連星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"2つの恒星が両者の重心の周りを軌道運動している天体である。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[超新星爆発とは？]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"大質量の恒星が、その一生を終えるときに起こす大規模な爆発", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"現象である。", left_end, IO_y + Interval_y * ver, font_size, c);
			}
			else if (page == 2)//上を変えたらここも変える
			{
				ver = 0;
				Font::StrDraw(L"[白色矮星とは？]", left_end, Interval_y*ver, font_size, c);
				ver++;
				Font::StrDraw(L"恒星が進化の終末期にとりうる形態の一つ。質量は太陽と同程 ", left_end, Interval_y*ver, font_size, c);
				ver++;
				Font::StrDraw(L"度から数分の1程度と大きいが、直径は地球と同程度かやや大", left_end, Interval_y*ver, font_size, c);
				ver++;
				Font::StrDraw(L"きいくらいに縮小しており、非常に高密度の天体である。", left_end, Interval_y*ver, font_size, c);
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


		//					　　	 X　 Y　 大きさ
		Font::StrDraw(L"フユエ", 30 + fy * std, 360 + t * l, 30, c);
		l++;

		if (start_flag == true)
		{
			// left								right						top							　　　bottom               
			if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
			{
				if (m_mou_l == true)
				{
					crick = 15;//ここはキーのようなもの
					page = 0; //ページ初期化
				}
			}
		}


		if (crick == 15)//上を変えたらここも変える
		{
			ver = VER_start; //文字間隔初期化
			page_max = 2; //最大ページ数

			//ページ数表示
			swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
			Font::StrDraw(strp, pagex, pagey, pagesize, c);

			if (page == 0)
			{
				Font::StrDraw(L"さそり座の恒星で3等星。この星は橙色の巨星である。中国では", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"二十八宿の１つ「尾宿」にある星官の1つ「傅説」とされる。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"2017年6月30日、国際天文学連合の恒星の命名に関する", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"ワーキンググループ (WGSN) は、さそり座G星の固有名", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"として、Fuyue を正式に承認した。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"ぼうえんきょう座ではγ星、さそり座の名称なしの星として", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"扱っていた。最終的にさそり座G星と呼ばれるようになった。", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
			}
			else if (page == 1)
			{
				//8行まで
				Font::StrDraw(L"[巨星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"同じ表面温度を持つ主系列星よりも半径および明るさが非常に", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"大きい恒星のことである。典型的には、巨星の半径は", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"太陽の10倍から100倍、明るさは10倍から1000倍で", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"ある。", left_end, IO_y + Interval_y * ver, font_size, c);
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

		swprintf_s(see, L"現在ページ数%d/終わりページ数%d", page, pagemax);
		Font::StrDraw(see, 530, 5, 18, c);


	}
}