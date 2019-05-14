//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

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

void CObjStarPresent7::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();


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
	Font::StrDraw(L"カストル", 20, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 1;
		}
	}

	//					　　	    X　 Y　 大きさ
	Font::StrDraw(L"ポルックス", 20, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 2;
		}
	}

	//					　　	    X　        Y　    大きさ
	Font::StrDraw(L"アルヘナ", 20, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 3;
		}
	}
	//					　　	  X　        Y　    大きさ
	Font::StrDraw(L"ワサト", 20, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
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
	Font::StrDraw(L"メブスタ", 20 + 220, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 5;
		}
	}
	//					　　	  X　        Y　    大きさ
	Font::StrDraw(L"メクブダ", 20 + 220, 330 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 6;
		}
	}
	//					  　　	    X　        Y　    大きさ
	Font::StrDraw(L"プロプス", 20 + 220, 340 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 7;
		}
	}
	//					　　	  X　        Y　    大きさ
	Font::StrDraw(L"テジェット", 20 + 220, 350 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 8;
		}
	}

	t -= 4;
	l -= 4;
	std=2;
	//					　　	  X　        Y　    大きさ
	Font::StrDraw(L"アルズラ", 20 + 420, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 9;
		}
	}
	//					  　　	    X　        Y　    大きさ
	Font::StrDraw(L"チシュエイ", 20 + 420, 330 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 10;
		}
	}


	if (crick == 1)
	{
		ver = 0;
		Font::StrDraw(L"ふたご座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"ふたご座で2番目に明るい恒星カストルAとカストルB", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"カストルCの三重連星でこれら3つの星すべてが", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"2つの星から成る連星である、通常は3つ（6つ）", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"合わせて2等星として扱われる", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 2)
	{
		ver = 0;
		Font::StrDraw(L"ふたご座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"ふたご座で最も明るい恒星で、全天21の1等星の", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"1つ冬のダイヤモンドを形成する恒星の1つでもある", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 3)
	{
		ver = 0;
		Font::StrDraw(L"ふたご座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"ふたご座で3番目に明るい恒星軌道を12.6年の周期で", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"周回している", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 4)
	{
		ver = 0;
		Font::StrDraw(L"ふたご座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"およそ1,200年かけて周回している", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 5)
	{
		ver = 0;
		Font::StrDraw(L"ふたご座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"超巨星で、月に掩蔽される際に詳細な観測が成されている", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"超巨星…太陽よりはるかに大きく明るい恒星のこと", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 6)
	{
		ver = 0;
		Font::StrDraw(L"ふたご座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"10.15日の周期で3.62等から4.18等まで変光する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"ケフェイド変光星の超巨星である", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"ケフェイド変光星…等級が変わることこの星の変光範囲は1～2等", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"周期は2～50日ほどである", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 7)
	{
		ver = 0;
		Font::StrDraw(L"ふたご座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"およそ232.9日の周期で3.15等から3.9等まで変光する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"半規則型変光星の巨星", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"半規則型変光星…変光範囲は数百分の数等級から数等級である", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 8)
	{
		ver = 0;
		Font::StrDraw(L"ふたご座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"恒星で3等星", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"太陽に比べ1,540倍以上のエネルギーを放出している", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"地球から見た場合、他の恒星よりも5倍以上の速度で", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"移動しているように見える", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 9)
	{
		ver = 0;
		Font::StrDraw(L"ふたご座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"3等星の恒星で、地球から約60光年離れた、F型主系列星", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"あるいは準巨星で、太陽の1.7倍の質量と2.7倍の半径を持つ", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"年齢は15億年と若く、金属量は太陽とほぼ同程度とされている", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 10)
	{
		ver = 0;
		Font::StrDraw(L"ふたご座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"恒星で5等星", left_end, IO_y + Interval_y * ver, font_size, c);
	}

}