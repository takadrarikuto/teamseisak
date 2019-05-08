//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjStarPresent.h"
extern int lever;
extern int crick;
extern int cenge;


void CObjStarPresent::Init()
{
	page = 0;//次のページへ行くための変数
	page_flag = false;
	ver = 0;
	g = 200.0f;//星枠の横幅
	k = 75.0f;//星枠の立幅
	t = 70;//星の名前の位置
	l = 0;//tと掛ける用の変数
	s = 0;//星のクリックの鍵
	std = 0;
	side_a = 0;
	side_b = 200;
	size = 25;
	size_y = 30;
	font = 80;
	fy = 200;//星の名前の横幅
	font_size = 25;//文字の大きさ
	Interval_y = 35;//文字の立幅間隔
	left_end = 80;//説明文の左の限界を決める

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
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置
	//ブラックタイルの切り取り
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1039.0f;
	src.m_bottom = 469.0f;

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
		Draw::Draw(1, &src, &dst, c, 0.0f);

		for (int l = 0; l <= 2; l++)
		{

			dst.m_top = 375.0f + k * l;
			dst.m_bottom = 450.0f + k * l;
			Draw::Draw(1, &src, &dst, c, 0.0f);
		}

	}

	//戻るボタンの枠を描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 67.0f;
	dst.m_bottom = 100.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);

	//次のページに行くためのボタンの枠を描画
	dst.m_top = 200.0f;
	dst.m_bottom = 300.0f;

	//次への枠
	Draw::Draw(1, &src, &dst, c, 0.0f);
	dst.m_top = 100.0f;
	dst.m_bottom = 200.0f;

	//戻すの枠
	Draw::Draw(1, &src, &dst, c, 0.0f);

	//宇宙船への文字を描画する
	//					　　X　Y　大きさ
	Font::StrDraw(L"宇宙", 10, 25, 25, c);
	Font::StrDraw(L"船へ", 10, 50, 25, c);

	//戻るボタン
	// left				 right            top            bottom         
	if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>0 && m_mou_y < 100)
	{
		if (m_mou_l == true)
		{
			lever = 0;
			Scene::SetScene(new CSceneStageselect());
		}
	}
	//ｂを押すと戻る
	else if (Input::GetVKey('B') == true)
	{
		lever = 0;
		Scene::SetScene(new CSceneStageselect());
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
	//戻るを押したらStarPresentに切り替える
	// left				 right            top            bottom       
	if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>190 && m_mou_y < 300)
	{
		if (m_mou_l == true)
		{
			lever = 0;
			Scene::SetScene(new CSceneStarPicbook());
		}
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
	//次へを押したらStarPresent2に切り替える
	// left				 right            top            bottom       
	/*if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>100 && m_mou_y <200)
	{
		if (m_mou_l == true)
		{
			lever =1;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}*/

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