//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjStarmodel.h"
extern int lever;

void CObjStarmodel::Init()
{
	size = 20;
	size_y = 30;
	m_y = 310;
	font = 30;
	ver;

}

void CObjStarmodel::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
}

void CObjStarmodel::Draw()
{
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

	int g = 200.0f;//星枠の横幅
	int k = 75.0f;//星枠の立幅
	
	dst.m_top = 0.0f;
	dst.m_left = 67.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 300.0f;
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.f);
	dst.m_top = 300.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.f);

	//戻るボタンの枠を描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 67.0f;
	dst.m_bottom = 100.0f;
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.f);

	//次のページに行くためのボタンの枠を描画
	dst.m_top = 200.0f;
	dst.m_bottom = 300.0f;

	//次への枠
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.f);

	dst.m_top = 100.0f;
	dst.m_bottom = 200.0f;

	//戻すの枠
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.f);

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

	
	

	//みずがめ座
	if (lever == 13)
	{	
		ver = 0;
		Font::StrDraw(L"みずがめ座", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"この星座には2等星以上の明るい星はない。みずがめ座には流星群が3つある。", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"3つとも、毎時約20個の流星が観測される。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"Water Jarと呼ばれるアステリズムがある。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"[アステリズムまたは星群(せいぐん)とは]", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"複数の恒星が天球上に形作るパターンである。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"星座の星の並び同様、地球からの距離は同じとは限らず、空間的にはまとまっていない。", font, m_y + size_y* ver, size, c);
	}
	//うお座
	else if (lever == 14)
	{
		ver = 0;
		Font::StrDraw(L"うお座", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"うお座は黄道十二星座でありながら、3等星より明るい星がなくあまり目立たない星座である。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"星図では、紐で結ばれた2匹の魚として描かれる。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"ペガススの大四辺形のちょうど南で、この西の魚の胴体を象るアステリズムを", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"英米ではCircletと呼んでいる。", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"[アステリズムまたは星群(せいぐん)とは]", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"複数の恒星が天球上に形作るパターンである。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"星座の星の並び同様、地球からの距離は同じとは限らず、空間的にはまとまっていない。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, m_y + size_y * ver, size, c);
		ver++;
	}
	//ひつじ座
	else if (lever == 15)
	{
		ver = 0;
		Font::StrDraw(L"おひつじ座", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"この星座の比較的明るい東側（向かって西側）のハマル・シェラタン・メサルティムで", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"できる鉤型は、古代バビロニアでは「農夫」あるいは「雇夫」", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"（麦播きの農繁期に雇われる日雇い農夫）だった。隣のうお座の中央が、彼が耕す農地である。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"「男」と「羊」が同音異義語 lu だったことから、羊と同一視されるようになった。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"中国では二十八宿の婁宿であり、日本ではこれを「たたらぼし」と訓じていた。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"[二十八宿（にじゅうはっしゅく）とは]", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"天球を、28のエリア（星宿）に不均等分割したもの。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"二十八舎（にじゅうはっしゃ）ともいう。", font, m_y + size_y* ver, size, c);
		ver++;
	}
	//うし座
	else if (lever == 16)
	{
		ver = 0;
		Font::StrDraw(L"おうし座", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"α星は、全天21の1等星の1つであり、アルデバランと呼ばれる。この星座には", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"プレアデス星団をはじめ有名な天体が多い。日本では、うし座と呼んだことがある。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"またおうし座に関係する方言は、プレアデス星団、ヒアデス星団、主星アルデバランに", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"名づけられたものが見つかっており、特にプレアデス星団は多い。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"日本では、うし座と呼んだことがある。またおうし座に関係する方言は", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"プレアデス星団、ヒアデス星団、主星アルデバランに名づけられたものが", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"見つかっており、特にプレアデス星団は多い。", font, m_y + size_y* ver, size, c);
		ver++;
	}
	//ふたご座
	else if (lever == 17)
	{
		ver = 0;
		Font::StrDraw(L"ふたご座", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"β星は、全天21の1等星の1つであり、ポルックスと呼ばれる。α星カストルは", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"ポルックスに準じる明るさである。ポルックスの近く（北西）に位置する。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"ポルックスとカストルと、それにアルヘナとテジェットで、星座はほぼ長方形を形作る。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"ふたご座と向かい合う極はいて座である。冥王星は、ワサトのそばで1930年に発見された。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"日本では、カストルとポルックスをアステリズムと捉える方言が伝わっている。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"[アステリズムまたは星群(せいぐん)とは]", font, m_y + size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"複数の恒星が天球上に形作るパターンである。", font, m_y + size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"星座の星の並び同様、地球からの距離は同じとは限らず、空間的にはまとまっていない。", font, m_y + size_y * ver, size, c);
	}
	//かに座
	else if (lever == 18)
	{
		ver = 0;
		Font::StrDraw(L"かに座", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"星座のほぼ中央にあるM44（プレセペ星団、プレセペ散開星団）が有名である。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"かに座は最も明るいタルフで3.520等、他は4等星以下と全体に暗い星からなる星座である。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"[プレセペ星団とは]", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"かに座にある散開星団である。", font, m_y + size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"[散開星団とは]", font, m_y + size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"恒星の集団（星団）の一種である。", font, m_y + size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"[かに座HM星とは]", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"かに座の方向に地球から1600光年離れた位置にある白色矮星の連星である。", font, m_y + size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"[白色矮星(はくしょくわいせい)とは]", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"恒星が進化の終末期にとりうる形態の一つ。", font, m_y + size_y* ver, size, c);
		ver++;
	}
	//しし座
	else if (lever == 19)
	{
		ver = 0;
		Font::StrDraw(L"しし座", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"日本では春の代表的な星座である。α星は、全天21の1等星の1つであり", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"レグルスと呼ばれる。β星のデネボラが、うしかい座のα星アークトゥルス", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"おとめ座のα星スピカと形作る三角形は春の大三角と呼ばれる。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"日本ではこれを「樋掛け星（といかけぼし）」と呼ぶ地方がある。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, m_y + size_y* ver, size, c);
		ver++;
	}
	//おとめ座
	else if (lever == 20)
	{
		ver = 0;
		Font::StrDraw(L"おとめ座", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"全天でうみへび座に次いで2番目に広い星座である。現在秋分点がある。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"α星は、全天21の1等星の1つであり、スピカと呼ばれる。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"スピカと、うしかい座のα星アークトゥルス、しし座のβ星デネボラで", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"春の大三角を形成する。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"[アークトゥルスとは]", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"うしかい座で最も明るい恒星で全天21の1等星の1つである赤色巨星。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"太陽を除き実視等級がマイナスとなる4つの恒星の1つ。", font, m_y + size_y* ver, size, c);
		ver++;
	}
	//てんびん座
	else if (lever == 21)
	{
		ver = 0;
		Font::StrDraw(L"てんびん座", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"西はおとめ座と、東はさそり座と接する。2等級より明るい星はなく", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"3つの3等星があり、これらが長方形を形作る。α星とβ星には", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"さそり座由来の名がついている。これはかつて、この星座が", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"さそり座のはさみの部分であったことに起因する。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"α星、β星はてんびん棒の部分で、γ星とσ星はてんびんの皿にあたる。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, m_y + size_y* ver, size, c);
		ver++;
	}
	//さそり座
	else if (lever == 22)
	{
		ver = 0;
		Font::StrDraw(L"さそり座", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"天の川沿いにある大きくて有名な星座である。日本では夏の大三角と共に", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"夏の星座として親しまれ、南の空に確認することができる。天の川に", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"大きなS字型で横たわっており、特徴的な形をしている。明るい星が多く", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"全天でも明るい星座の一つである。α星は、全天21の1等星の1つであり", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"アンタレスと呼ばれる。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, m_y + size_y* ver, size, c);
		ver++;
	}
	//いて座
	else if (lever == 23)
	{
		ver = 0;
		Font::StrDraw(L"いて座", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"冬至点や銀河の中心がこの星座の領域にある。比較的明るい星は", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"射手の上半身に集中しており、下半身は4等星以下の暗い星ばかりである。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"いて座A…電波源。銀河系中心に存在する。天文学者は、いて座Aが", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"大質量のブラックホールを含むかもしれないと考えている。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"いて座Aは我々の銀河系の中心に存在する電波源の複合体である。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, m_y + size_y* ver, size, c);
		ver++;
	}
	//やぎ座
	else if (lever == 24)
	{
		ver = 0;
		Font::StrDraw(L"やぎ座", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"この星座には2等星以上の明るい星は無い。M30は、やぎ座にある球状星団。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"海王星は、1846年9月23日、デネブ・アルゲディの近くでフランスの", font, m_y + size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"天文学者ルヴェリエの予測計算とドイツの天文学者ガレの観測によって発見された。", font, m_y + size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"[球状星団(きゅうじょうせいだん)とは]", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"恒星が互いの重力で球形に集まった天体。銀河の周りを軌道運動している。", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"球状星団は重力的に非常に強く束縛されており、そのために形状は球対称となり", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"中心核に向かって非常に密度が高くなっている。", font, m_y + size_y * ver, size, c);
		ver++;
	}


}