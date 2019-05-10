//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjStarPresent2.h"
extern int lever;
extern int crick;
extern int cenge;

void CObjStarPresent2::Init()
{

}

void CObjStarPresent2::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
}

void CObjStarPresent2::Draw()
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


	//					　　	    X　 Y　 大きさ
	Font::StrDraw(L"アルデバラン", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"エルナト", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"プリマヒアデス", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"セカンドヒアデス", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"アイン", 20 + 220, 320 + t * l, 30, c);
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
	Font::StrDraw(L"テンカン", 20 + 220, 330 + t * l, 30, c);
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
	Font::StrDraw(L"アルキオネ", 20 + 220, 340 + t * l, 30, c);
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
	Font::StrDraw(L"チャムクイ", 20 + 220, 340 + t * l, 30, c);
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
	Font::StrDraw(L"ケラエノ", 20 + 220, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 9;
		}
	}
	//					　　	  X　        Y　    大きさ
	Font::StrDraw(L"エレクトラ", 20 + 220, 330 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 10;
		}
	}
	//					  　　	    X　        Y　    大きさ
	Font::StrDraw(L"タイゲタ", 20 + 220, 340 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 11;
		}
	}
	//					  　　	    X　        Y　    大きさ
	Font::StrDraw(L"マイア", 20 + 220, 340 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
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
	Font::StrDraw(L"アステローペ", 20 + 220, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 13;
		}
	}
	//					　　	  X　        Y　    大きさ
	Font::StrDraw(L"メローペ", 20 + 220, 330 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 14;
		}
	}
	//					  　　	    X　        Y　    大きさ
	Font::StrDraw(L"アトラス", 20 + 220, 340 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 15;
		}
	}
	//					  　　	    X　        Y　    大きさ
	Font::StrDraw(L"プレイオネ", 20 + 220, 340 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 16;
		}
	}

	if (crick == 1)
	{
		ver = 0;
		Font::StrDraw(L"おうし座に属する", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"おうし座で最も明るい恒星で全天21の1等星の1つ", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"冬のダイヤモンドを形成する恒星の1つでもある", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"木星の数倍の質量の惑星を持つ", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"冬のダイヤモンド…6つの1等星を順に結ぶと大きなダイヤモンドの", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"形となる。これを、冬のダイヤモンドまたは冬の大六角形と言う", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 2)
	{
		ver = 0;
		Font::StrDraw(L"おうし座に属する", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"、おうし座で2番目に明るい恒星で2等星。かつてはぎょしゃ座にも", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"同時に属していた。特異星、中でも水銀・マンガン星に", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"分類されており、太陽にくらべてマンガンの含有率が20倍も高く", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"またカルシウムとマグネシウムは8分の1と低い", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"特異星…少なくともその表面において、金属量の組成が", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"他の恒星とかなり異なっている星である", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 3)
	{
		ver = 0;
		Font::StrDraw(L"おうし座に属する", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"おうし座の恒星で4等星。二重星とされているが", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"伴星について特にわかっていることはない。主星Aは", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"G9.5～K0のスペクトルを持つ巨星である", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"二重星…地球上から見る恒星が同じ方向に近接して見える物を", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"指す", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 4)
	{
		ver = 0;
		Font::StrDraw(L"おうし座に属する", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"おうし座の恒星で4等星。ヒアデス星団の一員で", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"セカンドヒアデスの1A星とδ1B星が見かけの二重星を", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"成している", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"ヒアデス星団…おうし座に位置する散開星団である", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"散開星団…恒星の集団（星団）の一種である", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 5)
	{
		ver = 0;
		Font::StrDraw(L"おうし座に属する", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"おうし座の方角に位置する橙色巨星である。", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"年齢は6億2500万年と精度良く予測されている", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"189秒離れたところに見える11等級の恒星と連星であるか", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"見かけの二重星であるかは定かではない", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"連星…2つの恒星が両者の重心の周りを軌道運動している", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"天体である。双子星（ふたごぼし）とも呼ばれる", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"二重星…地球上から見る恒星が同じ方向に近接して見える物を", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"指す", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 6)
	{
		ver = 0;
		Font::StrDraw(L"おうし座に属する", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"おうし座の恒星で3等星。太陽と比べると主星は", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"質量で11倍以上、半径で5－6倍という巨大な恒星である", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"125 km/sと高速で自転している。軌道周期は", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"ほぼ113日であると推定される", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 7)
	{
		ver = 0;
		Font::StrDraw(L"おうし座に属する", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"おうし座の恒星で3等星。プレアデス星団で 最も明るい恒星で", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"ある。他の多くのBe星と同様に215km/sと速い自転速度を", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"持ち恒星の回りにガスの円盤を作っている。明るさは", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"1.13時間ごとに+8.25から+8.30まで変化する", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"プレアデス星団…おうし座に位置する散開星団である", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"散開星団…恒星の集団（星団）の一種である", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 8)
	{
		ver = 0;
		Font::StrDraw(L"おうし座に属する", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"おうし座の二重星であり、ヒアデス星団のメンバーである。", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"5.62′離れた2つの星から構成される。視差の測定から", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"おうし座θ1星は地球から約152光年、おうし座θ2星は", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"約157光年の距離に位置すると推定されている", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"二重星…地球上から見る恒星が同じ方向に近接して見える物を", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"指す", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 9)
	{
		ver = 0;
		Font::StrDraw(L"おうし座に属する", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"おうし座の恒星でプレアデス星団に属する5等星。", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"プレアデス星団の中では輝星の一つだが、5等星と暗く", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"肉眼で見つけるのは難しい", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"星間物質による減光が0.3等級ほどあると考えられている", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"星間物質…恒星間の宇宙空間に分布する希薄物質の総称である。", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"大量の星間物質が凝縮して、星を構成する材料にもなる。", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"減光…観測者に到達する電磁波のエネルギー総量が減る現象", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"及びその減衰量を表す指標のことである", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 10)
	{
		ver = 0;
		Font::StrDraw(L"おうし座に属する", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"おうし座の恒星でプレアデス星団に属する、青色巨星である。", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"プレアデス星団の輝星の中でも明るいものの一つ。この星は月に", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"より周期的に掩蔽され、また太陽系の他の惑星によっても掩蔽", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"されることがある。自転速度は181km/sと高速で自転している", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"高速の自転のため、極付近は平たくなり、赤道は膨張している。", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"青色巨星…高温のために青く見える恒星", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 11)
	{
		ver = 0;
		Font::StrDraw(L"おうし座に属する", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"おうし座の恒星でプレアデス星団に属する4等星。", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"月に掩蔽されることがあり、そのときの観測結果から主星と伴星の", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"詳細がわかっている。プレアデス星団の中では明るいものの一つ", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"主星と伴星は地球からは0.012秒離れて見え、1313日で", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"公転している。", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"掩蔽…ある天体が観測者と他の天体の間を通過するために", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"その天体が隠される現象である", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 12)
	{
		ver = 0;
		Font::StrDraw(L"おうし座に属する", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"おうし座の恒星でプレアデス星団に属する4等星。プレアデス", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"星団の中でも明るいものの一つ。自転速度が遅いことにより", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"大気中に水銀やマンガンの輝線が強く見られる水銀・マンガン星に", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"分類される", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"プレアデス星団…おうし座に位置する散開星団である", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"散開星団…恒星の集団（星団）の一種である", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 13)
	{
		ver = 0;
		Font::StrDraw(L"おうし座に属する", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"おうし座の恒星でプレアデス星団に属している。", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"固有名アステローペは、ギリシャ神話に登場するプレイアデスの", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"一人の名前に因んでいる", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"プレアデス星団…おうし座に位置する散開星団である", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"散開星団…恒星の集団（星団）の一種である", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 14)
	{
		ver = 0;
		Font::StrDraw(L"おうし座に属する", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"おうし座に位置する恒星でプレアデス星団に属している。", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"プレアデス星団の輝星の中でも明るいものの一つ。", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"23番星の放射の影響で光を放っている", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"固有名メローペ は、ギリシャ神話に登場するプレイアデスの", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"一人の名前に因んでいる", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 15)
	{
		ver = 0;
		Font::StrDraw(L"おうし座に属する", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"おうし座の恒星でプレアデス星団に属している。プレアデス星団の", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"輝星の中でも明るいものの一つで三重星。少なくとも52au", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"離れた軌道を150年以上かけて周回している", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"au(天文単位)…長さの単位で", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"正確に 149597870700 mである", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"三重星(多重星)…地球から見ると近接した位置に見える", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"3つ以上の恒星である", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 16)
	{
		ver = 0;
		Font::StrDraw(L"おうし座に属する", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"おうし座の恒星でプレアデス星団に属す。プレアデス星団の", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"中では輝星の一つだが、視等級は5.09と暗く、また近くに", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"約4倍明るいおうし座27番星が見えるために裸眼で見つけるのは", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"難しい", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"プレアデス星団…おうし座に位置する散開星団である", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"散開星団…恒星の集団（星団）の一種である", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}


}