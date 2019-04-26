//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjStarPresent10.h"
extern int lever;
extern int crick;
extern int cenge;


void CObjStarPresent10::Init()
{

}

void CObjStarPresent10::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();


}

void CObjStarPresent10::Draw()
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
	Font::StrDraw(L"サヴィヤヴァ", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"ポリマ", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"ミネラウバ", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"ヴィンデミアトリックス", 20 + 220, 320 + t * l, 15, c);
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
	Font::StrDraw(L"カング", 20 + 220, 320 + t * l, 30, c);
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
		Font::StrDraw(L"おとめ座で最も明るい恒星で全天21の1等星の1つ。春の夜に青白く輝く。", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"共にB型のスペクトルを持つ0.98等と10.5等の恒星からなる連星系である", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"0.17日の周期で0.015等変光している", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"連星…2つの恒星が両者の重心の周りを軌道運動している天体である", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"変光…明るさ（等級）が変化するもののことである", font, size_y * ver, size, c);
		ver++;
	}
	else if (crick == 2)
	{
		ver = 0;
		Font::StrDraw(L"おとめ座に属する", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"おとめ座の方角にある恒星で4等星。太陽よりも大きく", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"重く、比較的金属量に富んでいる黄道にかなり近い位置にあるため、", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"月や時には惑星による掩蔽が観測される", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"黄道…天球上における太陽の見かけ上の通り道（大円）をいう", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"掩蔽…ある天体が観測者と他の天体の間を通過するために", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"その天体が隠される現象である", font, size_y * ver, size, c);
		ver++;
	}
	else if (crick == 3)
	{
		ver = 0;
		Font::StrDraw(L"おとめ座に属する", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"おとめ座にある3等級の連星である。F型主系列星同士からなる連星である", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"伴星は主星の周りを168.93年で公転している", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"F型主系列星…スペクトル型がF、光度階級がVの水素を", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"燃やして燃える主系列星である", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"連星…2つの恒星が両者の重心の周りを軌道運動している天体である", font, size_y * ver, size, c);
		ver++;
	}
	else if (crick == 4)
	{
		ver = 0;
		Font::StrDraw(L"おとめ座に属する", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"おとめ座の恒星で3等星。この星は赤色巨星分岐 (RGB) の", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"段階にある。地球から観測して80秒離れた位置に", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"見える11等星は、伴星の可能性があるとされる", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"赤色巨星…恒星が主系列星を終えたあとの進化段階である", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"大気が膨張し、その大きさは地球の公転軌道半径から", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"火星のそれに相当する", font, size_y * ver, size, c);
		ver++;
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
		Font::StrDraw(L"非常に大きい恒星のことである巨星の半径は太陽の10倍から100倍", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"明るさは10倍から1000倍である", font, size_y * ver, size, c);
		ver++;
	}
	else if (crick == 6)
	{
		ver = 0;
		Font::StrDraw(L"おとめ座に属する", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"恒星で4等星。", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"2010年に周囲を55年で公転する伴星を発見したとする", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"研究結果が発表された。伴星の直接検出には成功していないが", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"太陽の0.6倍の質量を持つ主系列星か白色矮星であると", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"考えられている", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
	}
	else if (crick == 7)
	{
		ver = 0;
		Font::StrDraw(L"おとめ座に属する", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
	}
	else if (crick == 8)
	{
		ver = 0;
		Font::StrDraw(L"おとめ座に属する", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
	}
	else if (crick == 9)
	{
		ver = 0;
		Font::StrDraw(L"おとめ座に属する", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
	}
	else if (crick == 10)
	{
		ver = 0;
		Font::StrDraw(L"おとめ座に属する", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y * ver, size, c);
		ver++;
	}
}
