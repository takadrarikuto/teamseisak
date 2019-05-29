//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameL\Audio.h"
#include "GameHead.h"
#include "ObjStarPresent5.h"
extern int lever;
extern int crick;
extern int cenge;
extern int star_count;

void CObjStarPresent5::Init()
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

void CObjStarPresent5::Action()
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
			if (a_time == 10)
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

void CObjStarPresent5::Draw()
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
	if (star_count >=250)
	{
	//					　　	    X　 Y　 大きさ
	Font::StrDraw(L"アルレシャ", 15, 320 + t * l, 30, c);
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

	//					　　			    X　    Y　   大きさ
	Font::StrDraw(L"フム・アル・サマカー", 10, 335 + t * l, 18, c);
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
	Font::StrDraw(L"レーヴァティ ", 15, 330 + t * l, 30, c);
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
	Font::StrDraw(L"トルクレア", 15, 330 + t * l, 30, c);
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

	


	if (crick == 1)
	{
		ver = VER_start; //文字間隔初期化
		page_max = 2; //最大ページ数

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"うお座に属する4等星で変光星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"4.1等の主星Aと5.1等の伴星Bからなる連星系で、", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"軌道長半径約130au、近点距離約50au、遠点距離", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"約190auの軌道を、およそ720年の周期で互いに", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"周回している。また、ABどちらもさらに伴星を従えている", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"可能性が示唆されている。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[変光星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"天体の一種で、明るさ（等級）が変化するもののことである。", left_end, IO_y + Interval_y * ver, font_size, c);
			//8行目まで、改行
		}
		else if (page == 1)
		{
			//8行まで
			Font::StrDraw(L"[連星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2つの恒星が両者の重心の周りを軌道運動している天体", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"である。双子星（ふたごぼし）とも呼ばれる。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[天文単位(au)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"長さの単位で、正確に 149597870700 m である。", left_end, IO_y + Interval_y * ver, font_size, c);	
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
			Font::StrDraw(L"うお座に属する青白い色の恒星である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"視等級は4.52で、肉眼でもみることができる。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ガイア計画で測定された年周視差の最新データに基づいて", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"計算された地球からの距離は約420光年である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"うお座β星の質量は太陽の5倍半径は太陽の3.6倍と", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"推定される。光度は太陽の810倍で有効温度は", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"15,500Kと推定される。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"自転速度は高く、下限速度は100km/sとみられる。", left_end, IO_y + Interval_y * ver, font_size, c);
			//8行目まで、改行
		}
		else if (page == 1)
		{			
			//8行まで
			Font::StrDraw(L"[天文学においての等級（とうきゅう）とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"天体の明るさを表す尺度である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[年周視差とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"地球の公転運動による視差のために天体の天球上の位置が", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"公転周期と同じ周期で変化して見える現象のことである。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[スペクトル型とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"恒星の分類法の一つである。恒星から放射された電磁波を", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"捉えスペクトルを観察して分類する。", left_end, IO_y + Interval_y * ver, font_size, c);
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
		page_max = 3; //最大ページ数

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"うお座の恒星で5等星。5つの恒星が多重星を構成している。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"星Aは、共にA7のスペクトルを持つ2つの準巨星の", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"AaとAbからなり、両星は地球からはわずか0.15秒角だけ", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"離れて見える。BaとBbの主系列星が9.075日の周期で", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"互いに周回しており、B星のペアはA星のペアから", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"22.90秒角離れた位置にある。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"さらにB星から1秒角の位置に12.2等のC星がある。", left_end, IO_y + Interval_y * ver, font_size, c);
			//8行目まで、改行
		}
		else if (page == 1)
		{
			//8行まで
			Font::StrDraw(L"[多重星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"地球から見ると近接した位置に見える3つ以上の恒星である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[スペクトル分類とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"恒星の分類法の一つである。スペクトル分類によって", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"細分された星のタイプをスペクトル型と呼ぶ。恒星から", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"放射された電磁波を捉え、スペクトルを観察することに", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"よって分類する。恒星のスペクトルはその表面温度や", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"化学組成により変わってくる。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 2)
		{
			//8行まで
			Font::StrDraw(L"[角度の単位としての秒とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"分の1/60の角度である。1秒は1度の1/3600である。", left_end, IO_y + Interval_y * ver, font_size, c);
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
		ver = VER_start; //文字間隔初期化
		page_max = 3; //最大ページ数

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"うお座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"4等星。4.26等のA星と8.30等のB星の二重星である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"星と伴星の間の見かけの距離（離角）は、12ミリ秒以上で", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"スペックル・イメージングで検出されていないことから", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"30ミリ秒以下であるとみられる。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"主星と伴星は、明るさが4等級ほど異なり、それゆえ伴星は", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"主系列星ではないかと予想される。", left_end, IO_y + Interval_y * ver, font_size, c);
			//8行目まで、改行
		}
		else if (page == 1)
		{
			//8行まで
			Font::StrDraw(L"[離角（りかく）とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"位置天文学において、ある点から見た2つの天体のなす角度で", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ある。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[スペックル・イメージングとは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"高分解能の天体撮像技術を指す用語である。この技術は", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"地上設置天体望遠鏡の分解能を劇的に改善する。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 2)
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
			Font::StrDraw(L"[主系列星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"主系列に位置する恒星をいう。矮星ともいう。一般に", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"重い恒星ほど主系列に留まる時間は短くなる。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"つまり主系列星としての寿命が短くなる。", left_end, IO_y + Interval_y * ver, font_size, c);
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
	}
else
	{
	ver = 0;
	Font::StrDraw(L"この星々を閲覧するには合計で星を250個集めてください", left_end, IO_y + Interval_y * ver, font_size, c);
	}

}