//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameL\Audio.h"
#include "GameHead.h"
#include "ObjStarPresent9.h"
extern int lever;
extern int crick;
extern int cenge;
extern int star_count; 

void CObjStarPresent9::Init()
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

	Audio::LoadAudio(1, L"効果音.wav", EFFECT);
}

void CObjStarPresent9::Action()
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
				Scene::SetScene(new CSceneStarPicbook());
				return;
			}
		}
	}
	//ｂを押すと戻る
	else if (Input::GetVKey('B') == true)
	{
		lever = 0;
		a_time = 0;
		Scene::SetScene(new CSceneStarPicbook());
	}

}

void CObjStarPresent9::Draw()
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

	if (star_count >=450)
	{
	//					　　	    X　 Y　 大きさ
	Font::StrDraw(L"レグルス", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"デネボラ", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"アルギエバ", 20, 330 + t * l, 30, c);
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
	Font::StrDraw(L"ゾスマ", 20, 340 + t * l, 30, c);
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
	Font::StrDraw(L"アダフェラ", 20 + 220, 320 + t * l, 30, c);
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
	Font::StrDraw(L"シェルタン", 20 + 220, 330 + t * l, 30, c);
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
	Font::StrDraw(L"アルテルフ", 20 + 220, 340 + t * l, 30, c);
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
	
	//					  　　	    X　        Y　    大きさ
	Font::StrDraw(L"ラサラス", 20 + 220, 340 + t * l, 30, c);
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
	Font::StrDraw(L"スーバー", 20 + 400, 320 + t * l, 30, c);
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
			Font::StrDraw(L"しし座に属する最も明るい恒星で全天21の1等星の1つ。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"1等星の中では最も暗いほぼ黄道上にあり、航海位置の", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"計測の基準となる。常用恒星となっている4個の星が各2個の", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ペアになって互いに回っている多重連星である。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[黄道とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"天球上における太陽の見かけ上の通り道（大円）をいう。", left_end, IO_y + Interval_y * ver, font_size, c);
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
	else if (crick == 2)
	{
		page_max = 3; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"しし座に属するしし座の恒星で2等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"うしかい座のアークトゥルスとおとめ座のスピカとで", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"春の大三角形を形成する白色の主系列星。たて座δ型変光星", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"であり、変光範囲はごくわずかなので眼視観測では変光", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"はわからない。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[主系列星(しゅけいれつせい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"恒星の有効温度と明るさを示した図である左上延びる", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"線であるヘルツシュプルング・ラッセル図 (HR図) 上で", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"明るく高温から暗く低温に主系列に位置する", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"恒星をいう。矮星ともいう", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[たて座δ型変光星(たてざデルタがたへんこうせい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"脈動変光星の一種で、恒星表面における動径脈動及び非動径脈動", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"の両方の原因によって光度が変化する変光星である。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 2)
		{
			Font::StrDraw(L"[脈動変光星(みゃくどうへんこうせい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"膨張と収縮を繰り返すことにより、または星の形状が変化する", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ことにより明るさが変化する変光星のこと。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[変光星(へんこうせい)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"天体の一種で、明るさ（等級）が変化するもののことである。", left_end, IO_y + Interval_y * ver, font_size, c);
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
		page_max = 2; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"しし座に属する恒星にある2等星である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"橙色の巨星である主星と黄色巨星の伴星からなる実視連星", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"でありその美しさと小規模の天体望遠鏡でも手軽に観測できる", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ことから天文家たちにも人気の高い恒星である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"またしし座流星群の放射点が近いことでも知られる。", left_end, IO_y + Interval_y * ver, font_size, c);
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
			Font::StrDraw(L"[実視連星(二重星)とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"二重星の数あるうちの一つ。望遠鏡で両星に分離して観測され", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"両星が公転運動している事が確認されている連星を言う。", left_end, IO_y + Interval_y * ver, font_size, c);
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
			Font::StrDraw(L"しし座に属する恒星で3等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"白色の輝巨星で、太陽よりも若干大きくて高温であるかなり良く", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"研究されており、年齢や大きさついては比較的正確に測定されて", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"いる太陽よりもに大きな質量を持ち寿命は短く橙色の巨星か", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"赤色巨星になり静かに白色矮星になると考えられている。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[輝巨星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"極めて明るい巨星に分類される。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[赤色巨星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"肉眼で観察すると赤く見えることから「赤色」巨星と", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"呼ばれる。　白色矮星(はくしょくわいせい)…恒星が", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"進化の終末期にとりうる形態の一つ", left_end, IO_y + Interval_y * ver, font_size, c);
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
			Font::StrDraw(L"しし座に属する恒星で3等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"珍しいF型の巨星で、中心核では水素の核融合は既に終わり", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"ヘリウムの核が収縮している段階である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"少し離れた位置にあるしし座35番星とは見かけの二重星の", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"関係にあり、連星ではない。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[二重星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"地球上から見る恒星が同じ方向に近接して見える物を指す。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[連星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2つの恒星が両者の重心の周りを軌道運動している天体", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"である。双子星（ふたごぼし）とも呼ばれる。", left_end, IO_y + Interval_y * ver, font_size, c);
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
	else if (crick == 6)
	{
		page_max = 2; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"しし座に属する恒星で3等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"A型スペクトルの主系列星から準巨星に分類される。およそ", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"4500万年前に誕生したときにはB8型の主系列星であり", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"将来は質量の大きな白色矮星になるものと考えられている。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[準巨星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"同じスペクトル型の通常の主系列星よりやや明るく", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"巨星ほどは明るくない恒星の分類の1つである。", left_end, IO_y + Interval_y * ver, font_size, c);
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
	else if (crick == 7)
	{
		page_max = 2; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"しし座に属する恒星で4等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"おうし座のアルデバランとよく似通っており絶対等級では", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"わずかにこの星のほうが明るいが地球からの距離がずっと", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"遠いため25倍ほど暗く見える。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"やがてミラのような長周期の変光星となると考えられている。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[変光星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"天体の一種で、明るさ（等級）が変化するもののことある。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[ミラとは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"星が最も収縮した直後に明るさが極大となる性質を持つ。", left_end, IO_y + Interval_y * ver, font_size, c);
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
		page_max = 1; //最大ページ数
		ver = VER_start; //文字間隔初期化

		//ページ数表示
		swprintf_s(strp, L"ページ数%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		Font::StrDraw(L"しし座に属する恒星で4等星。", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"K型の巨星だが、まだ中心核ではヘリウムの核融合が", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"始まっておらず核が収縮している段階であると考えられている。", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"5,000万年後にはヘリウムの核融合が始まり、現在より", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"10倍から20倍は光度が増すものと予測されている。", left_end, IO_y + Interval_y * ver, font_size, c);

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
			Font::StrDraw(L"しし座に属する恒星で4等星。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"F型のスペクトルを持つ巨星とA型主系列星が連星系を", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"成しているが、主星と伴星の平均距離が大変近いため分光法", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"またはスペックル干渉法でしか観測できていない2つの星は", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"14.498日の周期で共通重心を互いに巡っている。", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[A型主系列星とは]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"スペクトル型がA、光度階級がVの水素を燃やして燃える", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"主系列星である。", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
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
	}
else
	{
	ver = 0;
	Font::StrDraw(L"この星々を閲覧するには合計で星を450個集めてください", left_end, IO_y + Interval_y * ver, font_size, c);
	}

}