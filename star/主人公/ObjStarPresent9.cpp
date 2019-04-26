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
		Font::StrDraw(L"ある", font, size_y* ver, size, c);
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
		Font::StrDraw(L"恒星をいう。矮星ともいう恒星表面における動径脈動及び", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"非動径脈動の両方の原因によって光度が変化する変光星である", font, size_y* ver, size, c);
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
		Font::StrDraw(L"ある", font, size_y* ver, size, c);
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
		Font::StrDraw(L"位置する恒星をいう。矮星ともいう。", font, size_y* ver, size, c);
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
		Font::StrDraw(L"ある", font, size_y* ver, size, c);
	}

}