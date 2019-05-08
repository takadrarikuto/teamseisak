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

	//説明文の背景部分を描画
	dst.m_top = 0.0f;
	dst.m_left = 67.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 300.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);

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
