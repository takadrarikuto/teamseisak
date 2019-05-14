//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjStarPresent9.h"
extern int lever;
extern int crick;
extern int cenge;


void CObjStarPresent9::Init()
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

void CObjStarPresent9::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();


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


	if (crick == 1)
	{
		ver = 0;
		Font::StrDraw(L"しし座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"しし座で最も明るい恒星で全天21の1等星の1つ。1等星の中では", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"最も暗いほぼ黄道上にあり、航海位置の計測の基準となる", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"常用恒星となっている4個の星が各2個のペアになって互いに", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"回っている多重連星である", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"黄道…天球上における太陽の見かけ上の通り道（大円）をいう", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"連星…2つの恒星が両者の重心の周りを軌道運動している天体で", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"ある。双子星（ふたごぼし）とも呼ばれる", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 2)
	{
		ver = 0;
		Font::StrDraw(L"しし座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"しし座の恒星で2等星。うしかい座のアークトゥルスと", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"おとめ座のスピカとで、春の大三角形を形成する白色の", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"主系列星。たて座δ型変光星であり、変光範囲は", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"ごくわずかなので眼視観測では変光はわからない", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"主系列星…恒星の有効温度と明るさを示した図である左上延びる", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"線であるヘルツシュプルング・ラッセル図 (HR図) 上で", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"明るく高温から暗く低温に主系列に位置する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"恒星をいう。矮星ともいう", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 3)
	{
		ver = 0;
		Font::StrDraw(L"しし座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"しし座の恒星にある2等星である。橙色の巨星である主星と", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"黄色巨星の伴星からなる実視連星でありその美しさと小規模の", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"天体望遠鏡でも手軽に観測できることから天文家たちにも", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"人気の高い恒星である。またしし座流星群の放射点が", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"近いことでも知られる", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"実視連星…二重星の数あるうちの一つ。望遠鏡で両星に", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"分離して観測され両星が公転運動している事が", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"確認されている連星を言う", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 4)
	{
		ver = 0;
		Font::StrDraw(L"しし座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"しし座の恒星で3等星。白色の輝巨星で、太陽よりも若干", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"大きくて高温であるかなり良く研究されており、年齢や大きさに", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"ついては比較的正確に測定されている太陽よりも", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"大きな質量を持ち寿命は短く橙色の巨星か赤色巨星になり", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"静かに白色矮星になると考えられている", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"輝巨星…極めて明るい巨星に分類される", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"赤色巨星…肉眼で観察すると赤く見えることから「赤色」巨星と", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"呼ばれる。　白色矮星(はくしょくわいせい)…恒星が", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"進化の終末期にとりうる形態の一つ", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 5)
	{
		ver = 0;
		Font::StrDraw(L"しし座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"しし座の恒星で3等星。珍しいF型の巨星で、中心核では", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"水素の核融合は既に終わりヘリウムの核が収縮している段階で", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"ある。少し離れた位置にあるしし座35番星とは見かけの二重星の", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"関係にあり、連星ではない", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"二重星…地球上から見る恒星が同じ方向に近接して見える物を", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"指す", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"連星…2つの恒星が両者の重心の周りを軌道運動している天体で", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"ある。双子星（ふたごぼし）とも呼ばれる", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 6)
	{
		ver = 0;
		Font::StrDraw(L"しし座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"しし座の恒星で3等星。A型スペクトルの主系列星から準巨星に", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"分類される。およそ4500万年前に誕生したときには", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"B8型の主系列星であり将来は質量の大きな白色矮星に", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"なるものと考えられている", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"主系列星…恒星の有効温度と明るさを示した図である", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"ヘルツシュプルング・ラッセル図 (HR図) 上で、", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"明るく高温から暗く低温に延びる線である主系列に", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"位置する恒星をいう。矮星ともいう", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 7)
	{
		ver = 0;
		Font::StrDraw(L"しし座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"しし座の恒星で4等星。おうし座のアルデバランと", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"よく似通っており絶対等級ではわずかにこの星のほうが", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"明るいが地球からの距離がずっと遠いため25倍ほど暗く見える", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"やがてミラのような長周期の変光星となると考えられている", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"ミラ…星が最も収縮した直後に明るさが極大となる性質を持つ", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"変光星…天体の一種で、明るさ（等級）が変化するもののこと", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"ある", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 8)
	{
		ver = 0;
		Font::StrDraw(L"しし座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"しし座の恒星で4等星。K型の巨星だが、まだ中心核では", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"ヘリウムの核融合が始まっておらず核が収縮している段階である", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"と考えられている", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"5,000万年後にはヘリウムの核融合が始まり、現在より", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"10倍から20倍は光度が増すものと予測されている", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"約358日かけて公転している", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 9)
	{
		ver = 0;
		Font::StrDraw(L"しし座に属する", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"しし座の恒星で4等星。F型のスペクトルを持つ巨星と", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"A型主系列星が連星系を成しているが、主星と伴星の平均距離が", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"大変近いため分光法またはスペックル干渉法でしか", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"観測できていない2つの星は、14.498日の周期で共通重心を", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"互いに巡っている", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"A型主系列星…スペクトル型がA、光度階級がVの", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"水素を燃やして燃える主系列星である", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"連星…2つの恒星が両者の重心の周りを軌道運動している天体で", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"ある。双子星（ふたごぼし）とも呼ばれる", left_end, IO_y + Interval_y * ver, font_size, c);
	}


}