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
	 page = 0;
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

	// left								right						top								　bottom                            
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
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
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
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
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{

			crick = 5;//ここはキーのようなもの
		}
	}

	if (crick == 5)//上を変えたらここも変える
	{
		ver = 0;
		Font::StrDraw(L"薄黄色の輝巨星。2等星のA星と6等星のB星の二重星である。 ", left_end, Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"[輝巨星とは？]", left_end, Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"輝巨星は、二等星ほどの明るさを持つ恒星である。これらは ", left_end, Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"巨星から超巨星にまたがる大きさであるが、通常は超巨星ほ", left_end, Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"ど明るく重いわけではなく、極めて明るい巨星に分類される。", left_end, Interval_y * ver, font_size, c);


	}

	//					　　	 X　		    Y　 大きさ
	Font::StrDraw(L"ギルタブ", 30 + fy * std, 330 + t * l, 30, c);
	l++;

	// left								right						top								　bottom                            
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 6;//ここはキーのようなもの
		}
	}

	if (crick == 6)//上を変えたらここも変える
	{
		ver = 0;
		Font::StrDraw(L"この恒星は分光連星で、主星はケフェウス座β型変光星である。", left_end, Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"分光観測により、公転周期は195日と測定された。", left_end, Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"明るさの変化は、4.80時間、4.93時間である。", left_end, Interval_y * ver, font_size, c);

	}

	//					　　	 X　 Y　 大きさ
	Font::StrDraw(L"シャウラ", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	// left								right						top							　　　bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			page = 0;
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
		ver=0;
		Font::StrDraw(L"ゼミディムラ は、アフリカ大陸南部に住むコイコイ人の言葉で", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"「ライオンの眼」を意味する ゼム デ ムラに由来する", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"ピピリマとは二重星の関係らしい", left_end, Interval_y*ver, font_size, c);

	}

	t -= 4;
	l -= 4;
	std++;//四つ星を表示したらstdを入れる
	Font::StrDraw(L"ピピリマ", 30 + fy * std, 330 + t * l, 30, c);
	l++;

	// left								right						top						bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 9;//ここはキーのようなもの
		}
	}

	if (crick == 9)//上を変えたらここも変える
	{
		ver = 0;
		Font::StrDraw(L"ピピリマ は、タヒチの伝承に登場する双子の男女に由来する", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"ゼミディムラとは二重星の関係らしい", left_end, Interval_y*ver, font_size, c);
	}

	Font::StrDraw(L"ジャバハー", 30 + fy * std, 340 + t * l, 30, c);
	l++;
	// left								right						top						bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{

			crick = 10;//ここはキーのようなもの
		}
	}

	if (crick == 10)//上を変えたらここも変える
	{
		ver = 0;
		Font::StrDraw(L"ジャバハーは、地球から見てさそり座の方向に約500光年離", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"れた位置にある、4等級の恒星である。", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"7つの恒星から成る七重連星系である。現時点で発見されて", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"いる七重連星系は、他にはカシオペヤ座AR星しかない。", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"", left_end, Interval_y*ver, font_size, c);

	}

	//					　　	 X　		    Y　 大きさ
	Font::StrDraw(L"ファング", 30 + fy * std, 350 + t * l, 30, c);
	l++;

	// left								right						top								　bottom                            
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 11;//ここはキーのようなもの
		}
	}

	if (crick == 11)//上を変えたらここも変える
	{
		ver = 0;
		Font::StrDraw(L"この星は三重星である。さそり座π星Aはこと座β型変光星", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"の接触連星である。どちらも熱い青白色のB型主系列星であ", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"る。", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"[接触連星とは？]", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"接触連星は、恒星間の距離が近すぎて表面が接触しているか、", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"あるいは融合してガスの外層を共有しているような連星であ", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"る。外層を共有する連星のことは、特に過剰接触連星という。", left_end, Interval_y*ver, font_size, c);
	}

	//					　　	 X　 Y　 大きさ
	Font::StrDraw(L"イクリール", 30 + fy * std, 360 + t * l, 30, c);
	l++;
	// left								right						top							　　　bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 12;//ここはキーのようなもの
		}
	}

	if (crick == 12&&page==0)//上を変えたらここも変える
	{
		ver = 0;
		Font::StrDraw(L"Aと約40秒離れた位置に見える伴星Bの二重星である。 ", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"B型のスペクトルを持つ準巨星である主星Aは、これ", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"自体が分光連星であるが、あまりに2つの星が近く", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"にあるため詳細はわかっていない。", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"[光秒とは？]", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"1光秒は光（電磁波）が1秒間に進む距離と定義される。メート ", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"ルが[光が299.792.458分の1秒間に進む距離]と定義されてい", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"るので、1光秒は正確に 299.792.458 m となる。", left_end, Interval_y*ver, font_size, c);
		


	}
	else if (crick == 12 && page == 1)
	{
		ver=0;
		Font::StrDraw(L"[分光連星とは]", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"望遠鏡を使用して分離できなくとも、様々な変化の観測によっ", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"て2つ以上の天体からなることを検出できる連星のこと。", left_end, Interval_y*ver, font_size, c);
	}



	t -= 4;
	l -= 4;
	std++;//四つ星を表示したらstdを入れる
	Font::StrDraw(L"アル・ニヤト", 10 + fy * std, 330 + t * l, 30, c);
	l++;
	// left								right						top						bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 13;//ここはキーのようなもの
		}
	}

	if (crick == 13)//上を変えたらここも変える
	{
		ver = 0;
		Font::StrDraw(L"ヒッパルコスによる視差の測定より、地球からの距離は696光", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"年と推定されている。恒星系の主星は、二重線の分光連星で", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"あり、望遠鏡では解像できない。", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"[ヒッパルコスとは？]", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"この衛星は、恒星の位置を大気の影響の無い宇宙空間で精密", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"に測定することが主なミッションであった。", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"", left_end, Interval_y*ver, font_size, c);

	}

	//					　　	 X　		    Y　 大きさ
	Font::StrDraw(L"レサト", 30 + fy * std, 340 + t * l, 30, c);
	l++;

	// left								right						top								　bottom                            
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 14;//ここはキーのようなもの
		}
	}

	if (crick == 14)//上を変えたらここも変える
	{
		ver = 0;
		Font::StrDraw(L"シャウラと肉眼でも見える二重星となっている。", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"ただし2つの星は180光年離れており、連星ではない。", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"太陽の質量の10倍の質量という超新星爆発を起こすか白色矮星 ", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"となるかの境であるが、酸素、ネオン、マグネシウムだけで構", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"成された非常に質量の大きな白色矮星になるものと考えられて", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"いる。", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"[]", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"", left_end, Interval_y*ver, font_size, c);

	}

	//					　　	 X　 Y　 大きさ
	Font::StrDraw(L"フユエ", 30 + fy * std, 360 + t * l, 30, c);
	l++;
	// left								right						top							　　　bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
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
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
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

	swprintf_s(see, L"%d", page);
	Font::StrDraw(see, 600, 20, 30, c);
}