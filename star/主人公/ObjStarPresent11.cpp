//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjStarPresent11.h"
extern int lever;
extern int crick;
extern int cenge;


void CObjStarPresent11::Init()
{

}

void CObjStarPresent11::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();


}

void CObjStarPresent11::Draw()
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
	int g = 200.0f;//星枠の横幅
	int k = 75.0f;//星枠の立幅
	int t = 70;//星の名前の位置
	int l = 0;//tと掛ける用の変数
	int s = 0;//星のクリックの鍵
	int std = 0;
	int side_a = 0;
	int side_b = 200;
	int size = 25;
	int size_y = 30;
	int font = 80;


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