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
	 starpresent_flag = false;
	 ver = 0;
}

void CObjStarPresent::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
}

void CObjStarPresent::Draw()
{
	//描画カラー情報　R=Red　G=Green　B=Blue　A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };
	float p[4] = { 1.0f,1.0f,1.0f,0.6f, };
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置
	
	int g = 200.0f;//星枠の横幅
	int k = 75.0f;//星枠の立幅
	int t = 70;//星の名前の位置
	int l = 0;//tと掛ける用の変数
	int s = 0;//星のクリックの鍵
	int std = 0;//文字を横に移す変数
	int side_a = 0;//左の枠範囲
	int side_b = 200;//右の枠範囲
	int fy = 200;//星の名前の横幅
	int font_size = 25;//文字の大きさ
	int  Interval_y= 35;//文字の立幅間隔
	int  left_end= 80;//説明文の左の限界を決める
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

	int size = 25;
	int size_y = 30;
	int font = 80;
	int ver;


	if (lever == 0)
	{
		;
	}
	//水瓶座
	else if (lever == 1)
	{
		//					　　	    X　 Y　 大きさ
		Font::StrDraw(L"サダルメリク", 20, 320 + t * l, 30, c);
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
		Font::StrDraw(L"サダルスウド", 20, 320 + t * l, 30, c);
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
		Font::StrDraw(L"サダクビア", 20, 320 + t * l, 30, c);
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
		Font::StrDraw(L"スカトム", 20, 320 + t * l, 30, c);
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
		Font::StrDraw(L"アルバリ", 20 + 220, 320 + t * l, 30, c);
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
		Font::StrDraw(L"アンカ", 20 + 220, 330 + t * l, 30, c);
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
		Font::StrDraw(L"シュチュラ", 20 + 220, 340 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 7;
			}
		}

		int ver;
		if (crick == 1)
		{
			ver = 0;
			Font::StrDraw(L"みずがめ座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"みずがめ座で2番目に明るい恒星", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"ほぼ天の赤道上にある", font, size_y* ver, size, c);
		}
		else if (crick == 2)
		{
			ver = 0;
			Font::StrDraw(L"みずがめ座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"みずがめ座で最も明るい恒星", font, size_y* ver, size, c);
		}
		else if (crick == 3)
		{
			ver = 0;
			Font::StrDraw(L"みずがめ座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"恒星で4等星、A型主系列星の主星の周りを58日の周期で", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"周っている", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"A型主系列星…水素を燃やして燃える主系列星である", font, size_y* ver, size, c);
		}
		else if (crick == 4)
		{
			ver = 0;
			Font::StrDraw(L"みずがめ座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"みずがめ座で3番目に明るい恒星", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"おおぐま座運動星団の星の一つと考えられている", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"おおぐま座運動星団…地球の最も近くにある運動星団である", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"星団…お互いの重力によって生まれた恒星の集団", font, size_y* ver, size, c);
		}
		else if (crick == 5)
		{
			ver = 0;
			Font::StrDraw(L"みずがめ座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"恒星で4等星変光、化学組成、惑星は発見されていないなど", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"不確かな点が多い", font, size_y* ver, size, c);
		}
		else if (crick == 6)
		{
			ver = 0;
			Font::StrDraw(L"みずがめ座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"恒星で4等星、将来は白色矮星になると予測されている", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"白色矮星(はくしょくわいせい)…恒星が進化の終末期にとりうる形態の一つ", font, size_y* ver, size, c);
		}
		else if (crick == 7)
		{
			ver = 0;
			Font::StrDraw(L"みずがめ座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"恒星で5等星、スペクトル分類K型の巨星", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"スペクトル分類…恒星の分類法の一つ", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"巨星…半径および明るさが非常に大きい恒星", font, size_y* ver, size, c);
		}
	}
	//魚座
	else if (lever == 2)
	{
		//					　　	    X　 Y　 大きさ
		Font::StrDraw(L"アルレシャ", 15, 320 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 1;
			}
		}

		//					　　			    X　    Y　   大きさ
		Font::StrDraw(L"フム・アル・サマカー", 10, 335 + t * l, 18, c);
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
		Font::StrDraw(L"レーヴァティ ", 15, 330 + t * l, 30, c);
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
		Font::StrDraw(L"トルクレア", 15, 330 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 4;
			}
		}


		int ver;
		if (crick == 1)
		{
			ver = 0;
			Font::StrDraw(L"うお座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"4.1等の主星Aと5.1等の伴星Bからなる連星系", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"およそ720年の周期で互いに周回している", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"連星…2つの恒星が両者の重心の周りを軌道運動している天体で", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"ある。双子星（ふたごぼし）とも呼ばれる", font, size_y* ver, size, c);
		}
		else if (crick == 2)
		{
			ver = 0;
			Font::StrDraw(L"うお座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"うお座β星のスペクトル型はB6 Ve質量は太陽の5倍", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"半径は太陽の3.6倍と推定される", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"スペクトル型…恒星の分類法の一つである", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"恒星から放射された電磁波を捉えスペクトルを観察して分類する", font, size_y* ver, size, c);
		}
		else if (crick == 3)
		{
			ver = 0;
			Font::StrDraw(L"うお座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"5つの恒星が多重星を構成している", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"多重星…地球から見ると近接した位置に見える3つ以上の恒星で", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"ある", font, size_y* ver, size, c);
		}
		else if (crick == 4)
		{
			ver = 0;
			Font::StrDraw(L"うお座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"4等星。4.26等のA星と8.30等のB星の二重星である", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"二重星…地球上から見る恒星が同じ方向に近接して見える物を", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"指す", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"肉眼では1つの星に見えるが、望遠鏡などで観測する事によって", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"2つに分解する", font, size_y* ver, size, c);
		}
	}
	//牡羊座
	else if (lever == 3)
	{
		//					　　	    X　 Y　 大きさ
		Font::StrDraw(L"ハマル", 20, 320 + t * l, 30, c);
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
		Font::StrDraw(L"シェラタン", 20, 320 + t * l, 30, c);
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
		Font::StrDraw(L"メサルティム", 15, 320 + t * l, 30, c);
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
		Font::StrDraw(L"ボテイン", 20, 320 + t * l, 30, c);
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
		Font::StrDraw(L"リリィブロア", 20 + 200, 320 + t * l, 30, c);
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
		Font::StrDraw(L"バラニー", 20 + 200, 330 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 6;
			}
		}

		int ver;

		if (crick == 1)
		{
			ver = 0;
			Font::StrDraw(L"おひつじ座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"おひつじ座で最も明るい恒星で、唯一の2等星", font, size_y* ver, size, c);
		}
		else if (crick == 2)
		{
			ver = 0;
			Font::StrDraw(L"おひつじ座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"おひつじ座で2番目に明るい恒星で、3等星", font, size_y* ver, size, c);
		}
		else if (crick == 3)
		{
			ver = 0;
			Font::StrDraw(L"おひつじ座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"ほぼ同じ明るさの2つの恒星からなる", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"美しい二重星として知られ互いに5,000年以上掛けて", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"周回している", font, size_y* ver, size, c);
		}
		else if (crick == 4)
		{
			ver = 0;
			Font::StrDraw(L"おひつじ座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"K型の巨星で、わずかな変光が観測されているが真に変光星で", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"あるかは定かではない", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"巨星…同じ表面温度を持つ主系列星よりも半径および明るさが", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"非常に大きい恒星のことである", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"変光星…天体の一種で、明るさ（等級）が変化するもののことで", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"ある", font, size_y* ver, size, c);
		}
		else if (crick == 5)
		{
			ver = 0;
			Font::StrDraw(L"おひつじ座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"約170光年離れた位置にある5等級の恒星である", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"寿命を迎えつつある橙色巨星の段階にある", font, size_y* ver, size, c);
		}
		else if (crick == 6)
		{
			ver = 0;
			Font::StrDraw(L"おひつじ座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"太陽の3.2倍の質量を持つB型主系列星を主星とする分光連星で、", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"伴星は主星から軌道を約30年掛けて周回していると", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"考えられている", font, size_y* ver, size, c);
		}
	}
	//牡牛座
	else if (lever == 4)
	{
		//					　　	 X　 Y　 大きさ
		Font::StrDraw(L"アルデバラン", 10, 305, 15, c);

		// left				 right            top            bottom               
		if (m_mou_x > 0 && m_mou_x < 100 && m_mou_y>300 && m_mou_y < 325)
		{
			Font::StrDraw(L"おうし座にに属する", 110, 0, 30, c);
			Font::StrDraw(L"一番明るい星", 110, 50, 30, c);
		}
	}
	//,双子座
	else if (lever == 5)
	{
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
		std = 2;
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

		int ver;

		if (crick == 1)
		{
			ver = 0;
			Font::StrDraw(L"ふたご座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"ふたご座で2番目に明るい恒星カストルAとカストルB", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"カストルCの三重連星でこれら3つの星すべてが", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"2つの星から成る連星である、通常は3つ（6つ）", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"合わせて2等星として扱われる", font, size_y* ver, size, c);
		}
		else if (crick == 2)
		{
			ver = 0;
			Font::StrDraw(L"ふたご座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"ふたご座で最も明るい恒星で、全天21の1等星の", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"1つ冬のダイヤモンドを形成する恒星の1つでもある", font, size_y* ver, size, c);
		}
		else if (crick == 3)
		{
			ver = 0;
			Font::StrDraw(L"ふたご座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"ふたご座で3番目に明るい恒星軌道を12.6年の周期で", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"周回している", font, size_y* ver, size, c);
		}
		else if (crick == 4)
		{
			ver = 0;
			Font::StrDraw(L"ふたご座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"およそ1,200年かけて周回している", font, size_y* ver, size, c);
		}
		else if (crick == 5)
		{
			ver = 0;
			Font::StrDraw(L"ふたご座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"超巨星で、月に掩蔽される際に詳細な観測が成されている", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"超巨星…太陽よりはるかに大きく明るい恒星のこと", font, size_y* ver, size, c);
		}
		else if (crick == 6)
		{
			ver = 0;
			Font::StrDraw(L"ふたご座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"10.15日の周期で3.62等から4.18等まで変光する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"ケフェイド変光星の超巨星である", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"ケフェイド変光星…等級が変わることこの星の変光範囲は1～2等", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"周期は2～50日ほどである", font, size_y* ver, size, c);
		}
		else if (crick == 7)
		{
			ver = 0;
			Font::StrDraw(L"ふたご座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"およそ232.9日の周期で3.15等から3.9等まで変光する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"半規則型変光星の巨星", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"半規則型変光星…変光範囲は数百分の数等級から数等級である", font, size_y* ver, size, c);
		}
		else if (crick == 8)
		{
			ver = 0;
			Font::StrDraw(L"ふたご座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"恒星で3等星", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"太陽に比べ1,540倍以上のエネルギーを放出している", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"地球から見た場合、他の恒星よりも5倍以上の速度で", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"移動しているように見える", font, size_y* ver, size, c);
		}
		else if (crick == 9)
		{
			ver = 0;
			Font::StrDraw(L"ふたご座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"3等星の恒星で、地球から約60光年離れた、F型主系列星", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"あるいは準巨星で、太陽の1.7倍の質量と2.7倍の半径を持つ", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"年齢は15億年と若く、金属量は太陽とほぼ同程度とされている", font, size_y* ver, size, c);
		}
		else if (crick == 10)
		{
			ver = 0;
			Font::StrDraw(L"ふたご座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"恒星で5等星", font, size_y* ver, size, c);
		}
	}
	//蟹座
	else if (lever == 6)
	{
		//					　　	            X　 Y　 大きさ
		Font::StrDraw(L"アクベンス ", 20, 330 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 1;
			}
		}

		//					　　			    X　 Y　 大きさ
		Font::StrDraw(L"アルタルフ", 20, 330 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 2;
			}
		}

		//					　　		       X　 Y　 大きさ
		Font::StrDraw(L"アセルス・ボレアリス ", 10, 335 + t * l, 18, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 3;
			}
		}
		//					　　        X　        Y　    大きさ
		Font::StrDraw(L"アセルス・アウストラリス", 10, 340 + t * l, 18, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 4;
			}
		}

		t -= 4;
		l -= 4;
		std = 1;

		Font::StrDraw(L"ストール ", 20 + 220, 320 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 5;
			}
		}

		//					　　			    X　 Y　 大きさ
		Font::StrDraw(L"テグミン ", 20 + 220, 330 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 6;
			}
		}

		//					　　		       X　 Y　 大きさ
		Font::StrDraw(L"ピアトス ", 20 + 220, 340 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 7;
			}
		}
		//					　　        X　        Y　    大きさ
		Font::StrDraw(L"ナハ", 20 + 220, 350 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 8;
			}
		}


		t -= 4;
		l -= 4;
		std = 2;

		Font::StrDraw(L"コペルニクス ", 20 + 400, 320 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 9;
			}
		}


		int ver;

		if (crick == 1)
		{
			ver = 0;
			Font::StrDraw(L"かに座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"かに座の中では4番目に明るく、4.20等級で良い条件の下では", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"肉眼での観測が可能である光度は太陽の23倍以上である", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"黄道面の近くにあるため月や、稀に惑星による掩蔽が", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"起こることがある", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"黄道…天球上における太陽の見かけ上の通り道（大円）をいう", font, size_y* ver, size, c);
		}
		else if (crick == 2)
		{
			ver = 0;
			Font::StrDraw(L"かに座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"かに座で最も明るい4等星の恒星である。実視連星であり", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"主星のかに座β星Aは橙色のK型巨星でバリウム星としても", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"知られている。視等級は3.50等、絶対等級は-1.25等", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"伴星かに座β星Bは赤色矮星、主星から29秒離れた軌道を", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"76,000年で公転している", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"バリウム星…スペクトル型がG型またはK型の巨星である", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"スペクトルから、S過程が過剰に進み", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"455.4nmの一価のバリウムが存在することが示唆されている", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"赤色矮星…主系列星の中で特に小さい恒星のグループ", font, size_y* ver, size, c);
		}
		else if (crick == 3)
		{
			ver = 0;
			Font::StrDraw(L"かに座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"恒星で5等星。準巨星とされているが、理論からは主系列星と", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"推測されている。10等星と12等星の恒星と三重星に見えるが", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"いずれも連星ではない", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"連星…2つの恒星が両者の重心の周りを軌道運動している", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"天体である。双子星（ふたごぼし）とも呼ばれる", font, size_y* ver, size, c);
		}
		else if (crick == 4)
		{
			ver = 0;
			Font::StrDraw(L"かに座に属する", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"かに座に位置する恒星で5等星。準巨星とされているが、", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"理論からは主系列星と推測されている。10等星と12等星の恒星と", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"三重星に見えるが、いずれも連星ではない", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"準巨星…同じスペクトル型の通常の主系列星よりやや明るく", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"巨星ほどは明るくない恒星の分類の1つである", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"主系列星…恒星の有効温度と明るさを示した図である", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"ヘルツシュプルング・ラッセル図 (HR図) 上で", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"明るく高温から暗く低温に延びる線である主系列に", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"位置する恒星をいう。矮星ともいう", font, size_y * ver, size, c);
		}
		else if (crick == 5)
		{
			ver = 0;
			Font::StrDraw(L"かに座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"かに座の恒星で6等星。白色のA型主系列星で、プレセペ星団で", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"明るい星の1つである", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"A型主系列星…スペクトル型がA、光度階級がVの水素を燃やして", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"燃える主系列星であるスペクトル中の強い水素の吸収線によって", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"区別される", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"プレセペ星団…かに座にある散開星団である", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"散開星団…恒星の集団（星団）の一種である。分子雲から同時に", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"生まれた星同士がいまだに互いに近い位置にある状態の天体を", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"指す銀河のディスク部分に存在するため銀河星団とも呼ばれる", font, size_y* ver, size, c);
		}
		else if (crick == 6)
		{
			ver = 0;
			Font::StrDraw(L"かに座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"少なくとも4つの恒星から構成されるかに座の恒星系である。", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"黄道面の付近にあるため、月や稀に惑星による掩蔽が", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"観測されることがある", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"掩蔽…ある天体が観測者と他の天体の間を通過するために", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"その天体が隠される現象である", font, size_y* ver, size, c);
		}
		else if (crick == 7)
		{
			ver = 0;
			Font::StrDraw(L"かに座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"かに座の恒星で6等星。この星は青白いB型主系列星である", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"B型主系列星…スペクトル型がB、光度階級がVの", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"水素の核融合で燃える主系列星である", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"太陽の2倍から16倍の質量を持ち", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"表面温度は10,000Kから30,000Kの間である", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"B型主系列星は希な存在で、主系列星全体に占める割合は", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"0.1%程度に過ぎないと考えられている", font, size_y* ver, size, c);
		}
		else if (crick == 8)
		{
			ver = 0;
			Font::StrDraw(L"かに座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"かに座の恒星で5等星。", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"固有名のハナは、ペルシア語で「鼻」という", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"意味の言葉に由来する", font, size_y* ver, size, c);
		}
		else if (crick == 9)
		{
			ver = 0;
			Font::StrDraw(L"かに座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"太陽系から41光年の距離にあるかに座の連星系である", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"太陽に似たG型主系列星（かに座55番星A）と", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"赤色矮星（かに座55番星B）から構成され、2つの天体は", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"1000天文単位以上離れている", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"2008年までに、かに座55番星Aの周りには5つの太陽系外惑星が", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"発見されている", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"G型主系列星…スペクトル型がG型、光度階級が", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"Vの恒星（主系列星）のこと黄色矮星（おうしょくわいせい）", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"G Vとも呼ばれる。太陽はG型主系列星の一つである", font, size_y* ver, size, c);
			ver++;
		}
	}
	//蟹座
	else if (lever == 7)
	{
		//					　　	    X　 Y　 大きさ
		Font::StrDraw(L"レグルス", 20, 320 + t * l, 30, c);
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
		Font::StrDraw(L"デネボラ", 20, 320 + t * l, 30, c);
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
		Font::StrDraw(L"アルギエバ", 20, 330 + t * l, 30, c);
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
		Font::StrDraw(L"ゾスマ", 20, 340 + t * l, 30, c);
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
		Font::StrDraw(L"アダフェラ", 20 + 220, 320 + t * l, 30, c);
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
		Font::StrDraw(L"シェルタン", 20 + 220, 330 + t * l, 30, c);
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
		Font::StrDraw(L"アルテルフ", 20 + 220, 340 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 7;
			}
		}
		//					  　　	    X　        Y　    大きさ
		Font::StrDraw(L"ラサラス", 20 + 220, 340 + t * l, 30, c);
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
		std = 2;

		//					　　	  X　        Y　    大きさ
		Font::StrDraw(L"スーバー", 20 + 400, 320 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 9;
			}
		}


		int ver;
		if (crick == 1)
		{
			ver = 0;
			Font::StrDraw(L"しし座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"しし座で最も明るい恒星で全天21の1等星の1つ。1等星の中では", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"最も暗いほぼ黄道上にあり、航海位置の計測の基準となる", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"常用恒星となっている4個の星が各2個のペアになって互いに", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"回っている多重連星である", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"黄道…天球上における太陽の見かけ上の通り道（大円）をいう", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"連星…2つの恒星が両者の重心の周りを軌道運動している天体で", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"ある。双子星（ふたごぼし）とも呼ばれる", font, size_y* ver, size, c);
		}
		else if (crick == 2)
		{
			ver = 0;
			Font::StrDraw(L"しし座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"しし座の恒星で2等星。うしかい座のアークトゥルスと", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"おとめ座のスピカとで、春の大三角形を形成する白色の", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"主系列星。たて座δ型変光星であり、変光範囲は", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"ごくわずかなので眼視観測では変光はわからない", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"主系列星…恒星の有効温度と明るさを示した図である左上延びる", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"線であるヘルツシュプルング・ラッセル図 (HR図) 上で", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"明るく高温から暗く低温に主系列に位置する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"恒星をいう。矮星ともいう", font, size_y* ver, size, c);
		}
		else if (crick == 3)
		{
			ver = 0;
			Font::StrDraw(L"しし座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"しし座の恒星にある2等星である。橙色の巨星である主星と", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"黄色巨星の伴星からなる実視連星でありその美しさと小規模の", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"天体望遠鏡でも手軽に観測できることから天文家たちにも", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"人気の高い恒星である。またしし座流星群の放射点が", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"近いことでも知られる", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"実視連星…二重星の数あるうちの一つ。望遠鏡で両星に", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"分離して観測され両星が公転運動している事が", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"確認されている連星を言う", font, size_y* ver, size, c);
		}
		else if (crick == 4)
		{
			ver = 0;
			Font::StrDraw(L"しし座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"しし座の恒星で3等星。白色の輝巨星で、太陽よりも若干", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"大きくて高温であるかなり良く研究されており、年齢や大きさに", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"ついては比較的正確に測定されている太陽よりも", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"大きな質量を持ち寿命は短く橙色の巨星か赤色巨星になり", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"静かに白色矮星になると考えられている", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"輝巨星…極めて明るい巨星に分類される", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"赤色巨星…肉眼で観察すると赤く見えることから「赤色」巨星と", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"呼ばれる。　白色矮星(はくしょくわいせい)…恒星が", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"進化の終末期にとりうる形態の一つ", font, size_y* ver, size, c);
		}
		else if (crick == 5)
		{
			ver = 0;
			Font::StrDraw(L"しし座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"しし座の恒星で3等星。珍しいF型の巨星で、中心核では", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"水素の核融合は既に終わりヘリウムの核が収縮している段階で", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"ある。少し離れた位置にあるしし座35番星とは見かけの二重星の", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"関係にあり、連星ではない", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"二重星…地球上から見る恒星が同じ方向に近接して見える物を", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"指す", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"連星…2つの恒星が両者の重心の周りを軌道運動している天体で", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"ある。双子星（ふたごぼし）とも呼ばれる", font, size_y* ver, size, c);
		}
		else if (crick == 6)
		{
			ver = 0;
			Font::StrDraw(L"しし座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"しし座の恒星で3等星。A型スペクトルの主系列星から準巨星に", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"分類される。およそ4500万年前に誕生したときには", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"B8型の主系列星であり将来は質量の大きな白色矮星に", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"なるものと考えられている", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"主系列星…恒星の有効温度と明るさを示した図である", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"ヘルツシュプルング・ラッセル図 (HR図) 上で、", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"明るく高温から暗く低温に延びる線である主系列に", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"位置する恒星をいう。矮星ともいう", font, size_y* ver, size, c);
		}
		else if (crick == 7)
		{
			ver = 0;
			Font::StrDraw(L"しし座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"しし座の恒星で4等星。おうし座のアルデバランと", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"よく似通っており絶対等級ではわずかにこの星のほうが", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"明るいが地球からの距離がずっと遠いため25倍ほど暗く見える", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"やがてミラのような長周期の変光星となると考えられている", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"ミラ…星が最も収縮した直後に明るさが極大となる性質を持つ", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"変光星…天体の一種で、明るさ（等級）が変化するもののこと", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"ある", font, size_y* ver, size, c);
		}
		else if (crick == 8)
		{
			ver = 0;
			Font::StrDraw(L"しし座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"しし座の恒星で4等星。K型の巨星だが、まだ中心核では", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"ヘリウムの核融合が始まっておらず核が収縮している段階である", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"と考えられている", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"5,000万年後にはヘリウムの核融合が始まり、現在より", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"10倍から20倍は光度が増すものと予測されている", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"約358日かけて公転している", font, size_y* ver, size, c);
		}
		else if (crick == 9)
		{
			ver = 0;
			Font::StrDraw(L"しし座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"しし座の恒星で4等星。F型のスペクトルを持つ巨星と", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"A型主系列星が連星系を成しているが、主星と伴星の平均距離が", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"大変近いため分光法またはスペックル干渉法でしか", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"観測できていない2つの星は、14.498日の周期で共通重心を", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"互いに巡っている", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"A型主系列星…スペクトル型がA、光度階級がVの", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"水素を燃やして燃える主系列星である", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"連星…2つの恒星が両者の重心の周りを軌道運動している天体で", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"ある。双子星（ふたごぼし）とも呼ばれる", font, size_y* ver, size, c);
		}
	}
	//乙女座
	else if (lever == 8)
	{
		//					　　	    X　 Y　 大きさ
		Font::StrDraw(L"スピカ", 20, 320 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 1;
			}
		}

		//					　　	    X　 Y　 大きさ
		Font::StrDraw(L"サヴィヤヴァ", 20, 330 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 2;
			}
		}

		//					　　	    X　        Y　    大きさ
		Font::StrDraw(L"ポリマ", 20, 330 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 3;
			}
		}
		//					　　	  X　        Y　    大きさ
		Font::StrDraw(L"ミネラウバ", 20, 330 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
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
		Font::StrDraw(L"ヴィンデミアトリックス", 20 + 180, 330 + t * l, 18, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 5;
			}
		}
		//					　　	  X　        Y　    大きさ
		Font::StrDraw(L"ザニア", 20 + 220, 330 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 6;
			}
		}
		//					  　　	    X　        Y　    大きさ
		Font::StrDraw(L"シュルマ", 20 + 220, 340 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 7;
			}
		}
		Font::StrDraw(L"カング", 20 + 220, 340 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 8;
			}
		}

		t -= 4;
		l -= 4;
		std = 2;

		//					　　	  X　        Y　    大きさ
		Font::StrDraw(L"カンボリア", 20 + 400, 320 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 9;
			}
		}
		//					　　	  X　        Y　    大きさ
		Font::StrDraw(L"エレガラファ", 20 + 400, 330 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 10;
			}
		}

		int ver;
		if (crick == 1)
		{
			ver = 0;
			Font::StrDraw(L"おとめ座に属する", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"おとめ座で最も明るい恒星で全天21の1等星の1つ。春の夜に", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"青白く輝く。共にB型のスペクトルを持つ0.98等と10.5等の", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"恒星からなる連星系である。0.17日の周期で0.015等変光", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"している", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"連星…2つの恒星が両者の重心の周りを軌道運動している天体で", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"ある。双子星（ふたごぼし）とも呼ばれる", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"変光…明るさ（等級）が変化するもののことである", font, size_y * ver, size, c);
		}
		else if (crick == 2)
		{
			ver = 0;
			Font::StrDraw(L"おとめ座に属する", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"おとめ座の方角にある恒星で4等星。太陽よりも大きく", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"重く、比較的金属量に富んでいる黄道にかなり近い位置に", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"あるため、月や時には惑星による掩蔽が観測される", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"黄道…天球上における太陽の見かけ上の通り道（大円）をいう", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"掩蔽…ある天体が観測者と他の天体の間を通過するために", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"その天体が隠される現象である", font, size_y * ver, size, c);
		}
		else if (crick == 3)
		{
			ver = 0;
			Font::StrDraw(L"おとめ座に属する", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"おとめ座にある3等級の連星である。F型主系列星同士からなる", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"連星である。伴星は主星の周りを168.93年で公転している", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"F型主系列星…スペクトル型がF、光度階級がVの水素を", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"燃やして燃える主系列星である", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"連星…2つの恒星が両者の重心の周りを軌道運動している天体で", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"ある。双子星（ふたごぼし）とも呼ばれる", font, size_y * ver, size, c);
		}
		else if (crick == 4)
		{
			ver = 0;
			Font::StrDraw(L"おとめ座に属する", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"おとめ座の恒星で3等星。この星は赤色巨星分岐 (RGB) の", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"段階にある。地球から観測して80秒離れた位置に見える11等星", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"は伴星の可能性があるとされる", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"赤色巨星…恒星が主系列星を終えたあとの進化段階である", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"大気が膨張し、その大きさは地球の公転軌道半径から", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"火星のそれに相当する", font, size_y * ver, size, c);
		}
		else if (crick == 5)
		{
			ver = 0;
			Font::StrDraw(L"おとめ座に属する", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"おとめ座の恒星である。3等星の黄色巨星で、おとめ座では", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"α星のスピカ、γ星のポリマに次いで明るい年に0.2秒という", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"高速で移動して見える", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"巨星…同じ表面温度を持つ主系列星よりも半径および明るさが", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"非常に大きい恒星のことである巨星の半径は太陽の10倍から", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"100倍、明るさは10倍から1000倍である", font, size_y * ver, size, c);
		}
		else if (crick == 6)
		{
			ver = 0;
			Font::StrDraw(L"おとめ座に属する", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"恒星で4等星。分光連星で、3つの星から成る連星系であると", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"考えられている。伴星の1つは、平均約10au離れた軌道を", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"13.12年を掛けて周回している。さらに主星には約0.5auの", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"軌道を72日の周期で回る伴星があると見られる", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"au…天文単位と言い、長さの単位で、正確に 149597870700 m ", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"である。主として天文学で用いられ、例として地球と太陽の", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"距離の近似値は約1 auであると述べることができる", font, size_y * ver, size, c);
		}
		else if (crick == 7)
		{
			ver = 0;
			Font::StrDraw(L"おとめ座に属する", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"おとめ座の方角にある恒星で4等星。", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"2010年に周囲を55年で公転する伴星を発見したとする", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"研究結果が発表された。伴星の直接検出には成功していないが", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"太陽の0.6倍の質量を持つ主系列星か白色矮星であると", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"考えられている", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"主系列星…恒星の有効温度と明るさを示した図であるヘルツシュ", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L" プルング・ラッセル図(HR図) 上で明るく高温から暗く低温に", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"延びる線である主系列に位置する恒星をいう。矮星ともいう", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"白色矮星…恒星が進化の終末期にとりうる形態の一つ", font, size_y * ver, size, c);
		}
		else if (crick == 8)
		{
			ver = 0;
			Font::StrDraw(L"おとめ座に属する", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"おとめ座の恒星で4等星。中国の二十八宿の１つ", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"「亢 (Kang)」の距星とされる", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"二十八宿（にじゅうはっしゅく）…天球を、28のエリア（星宿）", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"に不均等分割したもの。二十八舎（にじゅうはっしゃ）ともいう", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"月宿（げっしゅく）…天球上の天の赤道付近（本来は月の", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"通り道である白道）を27ないし28のエリアに分割したもの", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"いずれも「月の宿り」を意味するが日本や中国では", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"一般に星宿と呼んでいる。月宿は世界各地に見られる", font, size_y * ver, size, c);
		}
		else if (crick == 9)
		{
			ver = 0;
			Font::StrDraw(L"おとめ座に属する", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"おとめ座の恒星で5等星。5.00等の主星と5.63等の伴星による", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"分光連星である", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"分光連星（ぶんこうれんせい）…望遠鏡を使用しても", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"分離できなくとも周期的なスペクトル線の移動や", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"パルス周期の変動などスペクトルの特徴の周期的な変化に", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"よって2つ以上の天体からなることを検出できる連星のこと", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"連星…2つの恒星が両者の重心の周りを軌道運動している天体で", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"ある。双子星（ふたごぼし）とも呼ばれる", font, size_y * ver, size, c);
		}
		else if (crick == 10)
		{
			ver = 0;
			Font::StrDraw(L"おとめ座に属する", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"おとめ座の恒星で5等星。4.92等の黄色巨星または準巨星のA星と", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"10.02等の橙色矮星のB星からなる連星系でA星自身も", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"分光連星である可能性を示唆されている", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"巨星…同じ表面温度を持つ主系列星よりも半径および明るさが", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"非常に大きい恒星のことである", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"準巨星…同じスペクトル型の通常の主系列星よりやや明るく", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"巨星ほどは明るくない恒星の分類の1つである", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"連星…2つの恒星が両者の重心の周りを軌道運動している天体で", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"ある。双子星（ふたごぼし）とも呼ばれる", font, size_y * ver, size, c);
		}
	}
	else if (lever == 9)
	{
		//					　　	            X　 Y　 大きさ
		Font::StrDraw(L"ズベン・エル・ゲヌビ", 2, 330 + t * l, 20, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 1;
			}
		}

		//					　　			    X　 Y　 大きさ
		Font::StrDraw(L"ズベン・エス・カマリ", 2, 330 + t * l, 20, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 2;
			}
		}

		//					　　		       X　 Y　 大きさ
		Font::StrDraw(L"ズベンエルハクラビ", 10, 330 + t * l, 20, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 3;
			}
		}
		//					　　        X　        Y　    大きさ
		Font::StrDraw(L"ブラキウム", 25, 330 + t * l, 20, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 4;
			}
		}

		int ver;

		if (crick == 1)
		{
			ver = 0;
			Font::StrDraw(L"てんびん座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"この星は光学二重星で、空気が澄んでいれば肉眼で見わけられる", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"重星…地球上から見る恒星が同じ方向に近接して見える物。", font, size_y* ver, size, c);
		}
		else if (crick == 2)
		{
			ver = 0;
			Font::StrDraw(L"てんびん座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"てんびん座で最も明るい恒星", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"地球からの距離は185光年と推測される", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"高速で回転しており、太陽の100倍以上の自転速度である", font, size_y* ver, size, c);
		}
		else if (crick == 3)
		{
			ver = 0;
			Font::StrDraw(L"てんびん座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"軌道を55,000年以上かけて回っている", font, size_y* ver, size, c);
		}
		else if (crick == 4)
		{
			ver = 0;
			Font::StrDraw(L"てんびん座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"さそり座の他の恒星と離れた位置にあることから", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"「さそり座γ星」をてんびん座の一部", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"その後新たに「てんびん座σ星」という符号を振り直した", font, size_y* ver, size, c);
		}
	}
	//蠍座
	else if (lever == 10)
	{
		//					　　	 X　		    Y　 大きさ
		Font::StrDraw(L"アンタレス", 30 + fy * std, 330 + t * l, 30, c);
		l++;

		// left								right						top								　bottom                            
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 1;//ここはキーのようなもの
			}
		}

	if (crick == 1)//上を変えたらここも変える
	{
		ver = 0;
		Font::StrDraw(L"さそり座で最も明るい恒星で全天21の1等星の1つ。夏の南の空", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"に赤く輝くよく知られる恒星の1つである。", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"アンタレスはかつて直径が太陽の230倍とされ、「理科年表」も", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"長らくこの値を採用していたが、実際はもっと大きな星で、直", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"径は太陽の600倍ないし800倍である。", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"明るさは太陽の8000倍ないし1万倍と考えられている。なお、赤", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"外線を含めて計算すると明るさは太陽の6.5万倍である。", left_end, Interval_y*ver, font_size, c);
	}
	
	//					　　	 X　 Y　 大きさ
	Font::StrDraw(L"アクラブ", 30 + fy * std, 330+t*l, 30, c);
	l++;
	// left								right						top							　　　bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 2;//ここはキーのようなもの
		}
	}

	if (crick == 2)//上を変えたらここも変える
	{
		ver = 0;
		Font::StrDraw(L"さそり座の恒星で3等星かつ六重連星。", left_end, Interval_y*ver, font_size,c);
		ver++;
		Font::StrDraw(L"[連星とは?]お互いの重力に引かれあったり離れたりを繰り返し", left_end, Interval_y*ver, font_size,  c);
		ver++;
		Font::StrDraw(L"をしている。肉眼で見た場合は一つに見えるが、望遠鏡", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"など遠距離で見た場合二つに分裂する。", left_end, Interval_y*ver, font_size, c);
	}
	
	Font::StrDraw(L"ジュバ", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	// left								right						top						bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			page = 0;
			crick = 3;//ここはキーのようなもの
		
		}
	}

	if (crick == 3 &&page==0)//上を変えたらここも変える
	{
		ver = 0;
		Font::StrDraw(L"さそり座の恒星で2等星。", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"Be星の中でも爆発型変光星のカシオペヤ座γ型変光星であると", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"考えられている。", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"[爆発型変光星とは？]", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"爆発型変光星は変光星の一種。恒星の外層や大気の爆発によっ", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"て変光する星。", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"[カシオペヤ座γ型変光星とは？]", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"ガス殻星のことであり、物質の流出のため、光度は不規則に", left_end, Interval_y*ver, font_size, c);
		//8行目まで、改行
		
	}
	if (crick == 3 && page == 1)
	{
		ver = 0;
		Font::StrDraw(L"変化する。", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"ガス殻星は高速で自転し、その機構に一定の説明を与えている", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"が、未だ謎が残っている。変光星の場合、カシオペヤ座γ型変 ", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"光星に分類される。", left_end, Interval_y*ver, font_size, c);

		}

		Font::StrDraw(L"ララワグ", 30 + fy * std, 330 + t * l, 30, c);
		l++;
		// left								right						top						bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 4;//ここはキーのようなもの
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
		// left								right						top						bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{

				crick = 5;//ここはキーのようなもの
			}
		}

		if (crick == 5)//上を変えたらここも変える
		{
			ver = 0;
			Font::StrDraw(L"薄黄色の輝巨星。2等星のA星と6等星のB星の二重星である。 ", left_end, Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"[輝巨星とは？]", left_end, Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"輝巨星は、二等星ほどの明るさを持つ恒星である。これらは ", left_end, Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"巨星から超巨星にまたがる大きさであるが、通常は超巨星ほ", left_end, Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"ど明るく重いわけではなく、極めて明るい巨星に分類される。", left_end, Interval_y*ver, font_size, c);


		}

		//					　　	 X　		    Y　 大きさ
		Font::StrDraw(L"ギルタブ", 30 + fy * std, 330 + t * l, 30, c);
		l++;

		// left								right						top								　bottom                            
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 6;//ここはキーのようなもの
			}
		}

		if (crick == 6)//上を変えたらここも変える
		{
			ver = 0;
			Font::StrDraw(L"この恒星は分光連星で、主星はケフェウス座β型変光星である。", left_end, Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"分光観測により、公転周期は195日と測定された。", left_end, Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"明るさの変化は、4.80時間、4.93時間である。", left_end, Interval_y*ver, font_size, c);

		}

		//					　　	 X　 Y　 大きさ
		Font::StrDraw(L"シャウラ", 30 + fy * std, 330 + t * l, 30, c);
		l++;
		// left								right						top							　　　bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 7;//ここはキーのようなもの
			}
		}

	if (crick == 7 && page == 0)//上を変えたらここも変える
	{
		ver = 0;
		Font::StrDraw(L"青白色の準巨星。", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"ケフェウス座β型変光星であり、わずかに変光するが、変光範 ", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"囲が小さいので眼視観測ではこの変光はわからない。", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"この星は3つの星からなる重星である。", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"λ星Bは15等星で、λ星Aとλ星Bは42秒離れている。", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"ただし、これらが物理的な影響を及ぼしあう連星であるのか", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"どうかは知られていない。もし連星だとするなら、AとBの間", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"は7,500天文単位、AとCの間は17,000天文単位（0.27光年） ", left_end, Interval_y*ver, font_size, c);
	}
	if (crick == 7 && page == 1)//上を変えたらここも変える
	{
		ver = 0;
		Font::StrDraw(L"離れていることになる。", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"[重星とは]", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"地球上から見て一つの星に見える星のこと、ただし連星と", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"は違い見かけ上は一つの星に見えるというだけで実際には", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"重なっている星々は距離が離れている。", left_end, Interval_y*ver, font_size, c);
		
	}
	Font::StrDraw(L"ゼミディムラ", 10 + fy * std, 340 + t * l, 30, c);
	l++;
	// left								right						top						bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{

				crick = 8;//ここはキーのようなもの

			}
		}

		if (crick == 8)//上を変えたらここも変える
		{

			Font::StrDraw(L"Xamidimura は、アフリカ大陸南部に住むコイコイ人の言葉で", 110, 0, 30, c);
			Font::StrDraw(L"「ライオンの眼」を意味する xami di muraに由来する", 110, 50, 30, c);

		}

		t -= 4;
		l -= 4;
		std++;//四つ星を表示したらstdを入れる
		Font::StrDraw(L"ピピリマ", 30 + fy * std, 330 + t * l, 30, c);
		l++;

		// left								right						top						bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{

				crick = 9;//ここはキーのようなもの

			}
		}

		if (crick == 9)//上を変えたらここも変える
		{
			Font::StrDraw(L"Pipirima は、タヒチの伝承に登場する双子の男女に由来する", 110, 0, 30, c);
		}

		Font::StrDraw(L"ジャバハー", 30 + fy * std, 340 + t * l, 30, c);
		l++;
		// left								right						top						bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{

				crick = 10;//ここはキーのようなもの
			}
		}

		if (crick == 10)//上を変えたらここも変える
		{
			Font::StrDraw(L"ジャバハー", 110, 0, 30, c);
		}

		//					　　	 X　		    Y　 大きさ
		Font::StrDraw(L"ファング", 30 + fy * std, 350 + t * l, 30, c);
		l++;

		// left								right						top								　bottom                            
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 11;//ここはキーのようなもの
			}
		}

		if (crick == 11)//上を変えたらここも変える
		{
			Font::StrDraw(L"ファング", 110, 0, 30, c);
		}

		//					　　	 X　 Y　 大きさ
		Font::StrDraw(L"イクリール", 30 + fy * std, 360 + t * l, 30, c);
		l++;
		// left								right						top							　　　bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 12;//ここはキーのようなもの
			}
		}

		if (crick == 12)//上を変えたらここも変える
		{
			Font::StrDraw(L"イクリール", 110, 0, 30, c);

		}

		t -= 4;
		l -= 4;
		std++;//四つ星を表示したらstdを入れる
		Font::StrDraw(L"アル・ニヤト", 10 + fy * std, 330 + t * l, 30, c);
		l++;
		// left								right						top						bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 13;//ここはキーのようなもの
			}
		}

		if (crick == 13)//上を変えたらここも変える
		{
			Font::StrDraw(L"アル・ニヤト", 110, 0, 30, c);
		}

		//					　　	 X　		    Y　 大きさ
		Font::StrDraw(L"レサト", 30 + fy * std, 340 + t * l, 30, c);
		l++;

		// left								right						top								　bottom                            
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 14;//ここはキーのようなもの
			}
		}

		if (crick == 14)//上を変えたらここも変える
		{

			Font::StrDraw(L"レサト", 110, 0, 30, c);

		}

		//					　　	 X　 Y　 大きさ
		Font::StrDraw(L"フユエ", 30 + fy * std, 360 + t * l, 30, c);
		l++;
		// left								right						top							　　　bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 15;//ここはキーのようなもの
			}
		}

		if (crick == 15)//上を変えたらここも変える
		{
			Font::StrDraw(L"フユエ", 110, 0, 30, c);
		}

		Font::StrDraw(L"", 30 + fy * std, 370 + t * l, 30, c);
		l++;
		// left								right						top						bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{

				crick = 16;//ここはキーのようなもの

			}
		}

		if (crick == 16)//上を変えたらここも変える
		{

			Font::StrDraw(L"", 110, 0, 30, c);
		}
	}
	//射手座
	else if (lever == 11)
	{
		//					　　	    X　 Y　 大きさ
		Font::StrDraw(L"ルクバト", 20, 320 + t * l, 30, c);
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
		Font::StrDraw(L"アルカブ・プリオル", 17, 330 + t * l, 18, c);
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
		Font::StrDraw(L"アルカブ・ポステリオル", 3, 340 + t * l, 18, c);
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
		Font::StrDraw(L"アルナスル", 20, 335 + t * l, 30, c);
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
		Font::StrDraw(L"カウス・メディア", 10 + 220, 330 + t * l, 18, c);
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
		Font::StrDraw(L"カウス・アウストラリス", 20 + 180, 335 + t * l, 18, c);
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
		Font::StrDraw(L"アスケラ", 20 + 220, 340 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 7;
			}
		}
		Font::StrDraw(L"カウス・ボレアリス", 20 + 200, 355 + t * l, 18, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 8;
			}
		}

		t -= 4;
		l -= 4;
		std = 2;

		//					　　	  X　        Y　    大きさ
		Font::StrDraw(L"ポリス", 20 + 400, 320 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 9;
			}
		}
		//					　　	  X　        Y　    大きさ
		Font::StrDraw(L"アイン・アル・ラーミー", 1 + 400, 340 + t * l, 18, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 10;
			}
		}
		//					  　　	    X　        Y　    大きさ
		Font::StrDraw(L"アルバルダ", 20 + 400, 350 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 11;
			}
		}
		Font::StrDraw(L"ヌンキ", 20 + 400, 360 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 12;
			}
		}

		t -= 4;
		l -= 4;
		std = 3;

		//					　　	  X　        Y　    大きさ
		Font::StrDraw(L"テレビルム", 20 + 600, 320 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 13;
			}
		}


		int ver;
		if (crick == 1)
		{
			ver = 0;
			Font::StrDraw(L"いて座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"いて座の4等星。いて座の星の中では", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"16番目の明るさであり他の星座で見られる", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"規則性からは大きく外れているように見える", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"", font, size_y* ver, size, c);
		}
		else if (crick == 2)
		{
			ver = 0;
			Font::StrDraw(L"いて座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"いて座の恒星で4等星。アルカブ・ポステリオルとは見かけの", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"二重星の関係だがこの恒星自体はB型主系列星で4等星の主星Aと", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"F型主系列星で7等星の伴星Bからなる連星である。二重星…", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"地球上から見る恒星が同じ方向に近接して見える物を指す", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"B型主系列星…スペクトル型がB、光度階級がVの水素の核融合で", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"燃える主系列星である。F型主系列星…スペクトル型がF", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"光度階級がVの水素を燃やして燃える主系列星である", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"連星…2つの恒星が両者の重心の周りを軌道運動している", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"天体である。双子星（ふたごぼし）とも呼ばれる", font, size_y* ver, size, c);
		}
		else if (crick == 3)
		{
			ver = 0;
			Font::StrDraw(L"いて座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"いて座の恒星で4等星。アルカブ・プリオルとは見かけの", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"二重星の関係で、連星ではない。F型主系列星で水素の核融合を", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"終えて準巨星になろうかという段階である", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"二重星…地球上から見る恒星が同じ方向に近接して", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"見える物を指す", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"連星…2つの恒星が両者の重心の周りを軌道運動している", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"天体である。双子星（ふたごぼし）とも呼ばれる", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"準巨星…同じスペクトル型の通常の主系列星よりやや明るく", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"巨星ほどは明るくない恒星の分類の1つである", font, size_y* ver, size, c);
		}
		else if (crick == 4)
		{
			ver = 0;
			Font::StrDraw(L"いて座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"いて座の恒星で3等星。K型の巨星で既に中心核では", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"水素の核融合を終えてヘリウムの核融合が進んでいる段階である", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"分光法による観測結果から伴星の存在が示唆されているが", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"詳しいことは何もわかっていない", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"巨星…同じ表面温度を持つ主系列星よりも", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"半径および明るさが非常に大きい恒星のことである", font, size_y* ver, size, c);
		}
		else if (crick == 5)
		{
			ver = 0;
			Font::StrDraw(L"いて座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"いて座の恒星で3等星。星間物質がどの程度あるか", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"わかっていないため不確かではあるが観測されているよりも", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"光度は30%半径は15%ほど大きいものと考えられている", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"星間物質…恒星間の宇宙空間に分布する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"希薄物質の総称である", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"", font, size_y* ver, size, c);
		}
		else if (crick == 6)
		{
			ver = 0;
			Font::StrDraw(L"いて座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"いて座で最も明るい恒星で2等星。B型のスペクトルを持つ巨星に", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"分類されているがA型の輝巨星とされることもある", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"現在では太陽の70倍以上という自転速度による", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"ガス殻星であると考えられている", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"輝巨星…極めて明るい巨星に分類される", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"巨星…同じ表面温度を持つ主系列星よりも半径および明るさが", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"非常に大きい恒星のことである", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"ガス殻星…赤道周囲にガスの円盤を持つことが示される恒星", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"である", font, size_y* ver, size, c);
		}
		else if (crick == 7)
		{
			ver = 0;
			Font::StrDraw(L"いて座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"いて座で3番目に明るい恒星で3等星。+3.26等級のA2型巨星と", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"+3.47等級のA4型準巨星から構成される連星系で2つの星は", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"平均距離13.4auの軌道を21.075年の周期で互いを周回している", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"100年余りの固有運動の観測結果から見かけの二重星であると", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"考えられている。巨星…同じ表面温度を持つ主系列星よりも", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"半径および明るさが非常に大きい恒星のことである", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"準巨星…同じスペクトル型の通常の主系列星よりやや明るく", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"巨星ほどは明るくない恒星の分類の1つである。二重星…", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"地球上から見る恒星が同じ方向に近接して見える物を指す", font, size_y* ver, size, c);
		}
		else if (crick == 8)
		{
			ver = 0;
			Font::StrDraw(L"いて座に属する", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"いて座の恒星で3等星。いわゆるレッドクランプに分類される", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"準巨星で中心核ではヘリウムから酸素や炭素の核融合が", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"進んでいる。", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"レッドクランプ…金属量が多い恒星の進化の段階に見られ", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"表面温度が同じ主系列星と比べて光度が大きい", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"準巨星…同じスペクトル型の通常の主系列星よりやや明るく", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"巨星ほどは明るくない恒星の分類の1つである", font, size_y* ver, size, c);
		}
		else if (crick == 9)
		{
			ver = 0;
			Font::StrDraw(L"いて座に属する", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"いて座の4等星。南斗六星の柄の端に位置する。五重星で", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"そのうち4つの恒星は実際に連星系を成している", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"太陽系からの距離はおよそ3,600光年となる", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"四重星系は重力的に不安定なため", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"いずれは1個か2個か弾き出されるものと考えられている", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"連星…2つの恒星が両者の重心の周りを軌道運動している", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"天体である。双子星（ふたごぼし）とも呼ばれる", font, size_y* ver, size, c);
		}
		else if (crick == 10)
		{
			ver = 0;
			Font::StrDraw(L"いて座に属する", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"いて座の5等星。「ティースプーン」と呼ばれるアステリズムの", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"一部を成す。", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"アステリズムあるいは星群…複数の恒星が天球上に", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"形作るパターンである。星座の星の並び同様", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"地球からの距離は同じとは限らず、空間的には", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"まとまっていない", font, size_y * ver, size, c);
		}
		else if (crick == 11)
		{
			ver = 0;
			Font::StrDraw(L"いて座に属する", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"いて座の恒星系である。3つの恒星からなる連星系で", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"黄道面に近いため、いて座π星は月、ごくまれに", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"惑星による掩蔽が観測される", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"黄道…天球上における太陽の見かけ上の通り道（大円）をいう", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"天球…地球を中心として取り巻く球体のこと", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"掩蔽…ある天体が観測者と他の天体の間を通過するために", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"その天体が隠される現象である", font, size_y* ver, size, c);
		}
		else if (crick == 12)
		{
			ver = 0;
			Font::StrDraw(L"いて座に属する", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"いて座で2番目に明るい恒星で2等星。南斗六星を作る星の1つ", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"太陽の7倍もの質量を持つため、中心核での核融合が早く進み", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"誕生からおよそ5000万年ほどで寿命を迎えるだろうと推測される", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"そのときには、太陽と同じ程度の質量を持つ白色矮星に", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"なるだろうと考えられている", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"白色矮星…恒星が進化の終末期にとりうる形態の一つ", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"", font, size_y* ver, size, c);
		}
		else if (crick == 13)
		{
			ver = 0;
			Font::StrDraw(L"いて座に属する", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"いて座の恒星で5等星。同じいて座にあるオメガ星雲とは", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"名前が似ているだけで異なる天体である", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"オメガ星雲…いて座に位置する散光星雲である", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"星雲の中にループ状の構造が見えることから", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"これをいろいろな物に見立てて「オメガ星雲」「白鳥星雲」など", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"いろいろな呼び名を持つ散光星雲である", font, size_y * ver, size, c);
		}
	}
	//山羊座
	else if (lever == 12)
	{
		//					　　	    X　 Y　 大きさ
		Font::StrDraw(L"アルゲディ", 20, 320 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 1;
			}
		}

		//					　　	    X　 Y　 大きさ
		Font::StrDraw(L"ダビー", 20, 325 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 2;
			}
		}

		//					　　	    X　        Y　    大きさ
		Font::StrDraw(L"ナシラ", 20, 330 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 3;
			}
		}
		//					　　	  X　        Y　    大きさ
		Font::StrDraw(L"デネブ・アルゲディ", 18, 340 + t * l, 20, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
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
		Font::StrDraw(L"アルシャト", 20 + 200, 320 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 5;
			}
		}

		int ver;
		if (crick == 1)
		{
			ver = 0;
			Font::StrDraw(L"やぎ座に属する", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"肉眼でもアルゲディ1星とアルゲディ2星に分離できる二重星", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"6.6分離れたアルゲディ1星とアルゲディ2星は連星ではなく", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"見かけの二重星の関係にある", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"分…角度の単位としての分。1度の60分の1の角度である", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"連星…2つの恒星が両者の重心の周りを軌道運動している天体", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"である。双子星（ふたごぼし）とも呼ばれる。", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"二重星…地球上から見る恒星が同じ方向に近接して", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"見える物を指す", font, size_y* ver, size, c);
			ver++;
		}
		else if (crick == 2)
		{
			ver = 0;
			Font::StrDraw(L"やぎ座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"やぎ座にある3等星のダビー1星と6等星のダビー2星からなる", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"連星系である。ダビー1星と6等星のダビー2星は地球からは", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"少し離れており、双眼鏡を使えば容易に分離して見ることが", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"できる。また、ダビー1星、ダビー2星のそれぞれが", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"また連星系を成しており全体として少なくとも", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"5つ以上の恒星から構成されている", font, size_y* ver, size, c);
			ver++;
		}
		else if (crick == 3)
		{
			ver = 0;
			Font::StrDraw(L"やぎ座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"やぎ座の恒星で4等星。近年の観測結果からは", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"スペクトル型A7の初期の巨星ではないかと考えられている", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"自転速度が遅いため、対流と重力の影響によって様々な", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"金属元素が大気中に見られるAm星であるとも考えられている", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"巨星…同じ表面温度を持つ主系列星よりも半径および明るさが", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"非常に大きい恒星のことである", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"Am星…化学特異星である", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"特異星…少なくともその表面において、金属量の組成が", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"他の恒星とかなり異なっている星である", font, size_y* ver, size, c);
			ver++;
		}
		else if (crick == 4)
		{
			ver = 0;
			Font::StrDraw(L"やぎ座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"やぎ座で最も明るい恒星で3等星。黄道付近にあるため", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"月や惑星による掩蔽が起きる", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"黄道…天球上における太陽の見かけ上の通り道（大円）をいう", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"掩蔽…ある天体が観測者と他の天体の間を通過するために", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"その天体が隠される現象である", font, size_y* ver, size, c);
			ver++;
		}
		else if (crick == 5)
		{
			ver = 0;
			Font::StrDraw(L"やぎ座に属する", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"やぎ座の恒星で5等星。地球からは4.74等のA星と", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"11.80等のB星の二重星に見える", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"重力的に関係のない見かけの二重星と思われるが、もし連星系を", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"成していた場合は4,000天文単位以上離れた軌道を14万年掛けて", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"周回していると考えられる", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"二重星…地球上から見る恒星が同じ方向に近接して見える物を", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"指す", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"天文単位…長さの単位で、正確に 149597870700 m", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"である", font, size_y* ver, size, c);
			ver++;
		}
	}
}