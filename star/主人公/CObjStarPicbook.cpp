//GameL‚ÅŽg—p‚·‚éƒwƒbƒ_[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"


#include "CObjStarPicbook.h"
#include "GameHead.h"
extern int lever;


void CObjStarPicbook::Init()
{
	starmodel_flag = false;
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
}

void CObjStarPicbook::Action()
{
	//ƒ}ƒEƒX‚ÌˆÊ’u‚ðŽæ“¾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//ƒ}ƒEƒX‚Ìƒ{ƒ^ƒ“‚Ìó‘Ô
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	//‰F’ˆ‘D‚Öƒ{ƒ^ƒ“
	// left				 right            top            bottom         
	if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>0 && m_mou_y < 100)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				lever = 0;
				Scene::SetScene(new CSceneStageselect());
				starmodel_flag = false;
			}
		}
		else
		{
			starmodel_flag = true;
		}


	}
	//‚‚‚ð‰Ÿ‚·‚Æ–ß‚é
	else if (Input::GetVKey('B') == true)
	{
		lever = 0;
		Scene::SetScene(new CSceneStageselect());
	}


	
}

void CObjStarPicbook::Draw()
{
	int g = 200.0f;//¯˜g‚Ì‰¡• 200.0f
	int k = 75.0f;//¯˜g‚Ì—§• 75.0f
	int t = 70;//¯‚Ì–¼‘O‚ÌˆÊ’u 70
	int l = 0;//t‚ÆŠ|‚¯‚é—p‚Ì•Ï” 0
	int s = 0;//¯‚ÌƒNƒŠƒbƒN‚ÌŒ® 0
	int std = 0;//•¶Žš‚ð‰¡‚ÉˆÚ‚·•Ï” 0
	int side_a = 0;//¶‚Ì˜g”ÍˆÍ 0
	int side_b = 200;//‰E‚Ì˜g”ÍˆÍ 200
	int side_c = 129;//129
	int fy = 200;//¯‚Ì–¼‘O‚Ì‰¡• 200
	int font_size = 25;//•¶Žš‚Ì‘å‚«‚³ 25
	int  Interval_y = 35;//•¶Žš‚Ì—§•ŠÔŠu 35
	int  left_end = 80;//à–¾•¶‚Ì¶‚ÌŒÀŠE‚ðŒˆ‚ß‚é 80

	//•`‰æƒJƒ‰[î•ñ@R=Red@G=Green@B=Blue@A=alpha(“§‰ßî•ñ)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float p[4] = { 1.0f,1.0f,1.0f,0.6f, };

	//ƒJ[ƒ\ƒ‹•\Ž¦(Š®¬‚µ‚½‚çÁ‚·)
	swprintf_s(strmous, L"x=%d,y=%d", (int)m_mou_x, (int)m_mou_y);
	Font::StrDraw(strmous, 600, 20, 30, c);


	RECT_F src;//•`‰æŒ³Ø‚èŽæ‚èˆÊ’u
	RECT_F dst;//•`‰ææ•\Ž¦ˆÊ’u

	//ƒTƒCƒo[”wŒi‚ÌØ‚èŽæ‚è
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 513.0f;
	src.m_bottom = 289.0f;

	//”wŒi‚ð•`‰æ
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(15, &src, &dst, c, 0.0f);

	//ƒpƒXƒeƒ‹ƒuƒ‹[ƒ^ƒCƒ‹‚ÌØ‚èŽæ‚è
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 130.0f;
	src.m_bottom = 67.0f;

	//¯}ŠÓ‚Ì˜g‚ð•`‰æ
	dst.m_top = 300.0f;
	dst.m_left = 0.0f;
	dst.m_right = 67.0f;
	dst.m_bottom = 600.0f;

	//ƒ‹[ƒv‚µ‚Ä•`‰æ‚·‚é
	for (int i = 0; i <= 3; i++)
	{
		//¯‚Ì–¼‘O‚Ì˜g‚ð•`‰æ
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

	//à–¾•¶‚Ì”wŒi•”•ª‚ð•`‰æ
	dst.m_top = 0.0f;
	dst.m_left = 67.0f;
	dst.m_right =800.0f;
	dst.m_bottom = 300.0f;
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.0f);

	//–ß‚éƒ{ƒ^ƒ“‚Ì˜g‚ð•`‰æ
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 67.0f;
	dst.m_bottom = 100.0f;
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.0f);

	//ŽŸ‚Ìƒy[ƒW‚És‚­‚½‚ß‚Ìƒ{ƒ^ƒ“‚Ì˜g‚ð•`‰æ
	dst.m_top = 200.0f;
	dst.m_bottom = 300.0f;

	//ŽŸ‚Ö‚Ì˜g
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.0f);

	dst.m_top = 100.0f;
	dst.m_bottom = 200.0f;

	//–ß‚·‚Ì˜g
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.0f);

	int Dc = 0; //•`‰æ—Dæ“x‘‰Á—p

	//å¶À‚Ì‰æ‘œˆÊ’u
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 764.0f;
	src.m_bottom = 578.0f;

	dst.m_top = 376.0f;
	dst.m_left = 530.0f;
	dst.m_right =600.0f;
	dst.m_bottom = 450.0f;
	
	//‚³‚»‚èÀ‰æ‘œ
	Draw::Draw(2, &src, &dst, c, 0.0f);
	
	Dc += 1;
	
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1104.0f;
	src.m_bottom = 844.0f;

	dst.m_top = 300.0f;
	dst.m_bottom = 374.0f;

	//‚Ä‚ñ‚Ñ‚ñÀ‰æ‘œ
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 400.0f;
	src.m_bottom = 400.0f;

	dst.m_top = 300.0f;
	dst.m_bottom = 374.0f;
	dst.m_left = 330.0f;
	dst.m_right = 400.0f;


	//‚Ó‚½‚²À‰æ‘œ
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 654.0f;
	src.m_bottom = 578.0f;

	dst.m_left = 130.0f;
	dst.m_right = 200.0f;
	
	//‚Ý‚¸‚ª‚ßÀ‰æ‘œ
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;
	
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 764.0f;
	src.m_bottom = 578.0f;

	dst.m_top = 450.0f;
	dst.m_left = 530.0f;
	dst.m_right =600.0f;
	dst.m_bottom = 524.0f;

	//‚¢‚ÄÀ‰æ‘œ
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1192.0f;
	src.m_bottom = 872.0f;

	dst.m_top = 450.0f;
	dst.m_bottom = 524.0f;
	dst.m_left = 330.0f;
	dst.m_right = 400.0f;

	//‚µ‚µÀ‰æ‘œ
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 764.0f;
	src.m_bottom = 578.0f;

	dst.m_top = 523.0f;
	dst.m_left = 530.0f;
	dst.m_right = 600.0f;
	dst.m_bottom = 600.0f;

	//‚â‚¬À‰æ‘œ
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 2;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1360.0f;
	src.m_bottom = 880.0f;

	dst.m_top = 376.0f;
	dst.m_bottom = 450.0f;
	dst.m_left = 130.0f;
	dst.m_right = 200.0f;

	//‚¤‚¨À‰æ‘œ
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 884.0f;
	src.m_bottom = 624.0f;

	dst.m_top = 376.0f;
	dst.m_bottom = 450.0f;
	dst.m_left = 330.0f;
	dst.m_right = 400.0f;

	//‚©‚ÉÀ‰æ‘œ
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1308.0f;
	src.m_bottom = 776.0f;

	dst.m_top = 523.0f;
	dst.m_bottom = 600.0f;
	dst.m_left = 330.0f;
	dst.m_right = 400.0f;

	//‚¨‚Æ‚ßÀ‰æ‘œ
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 424.0f;
	src.m_bottom = 320.0f;

	dst.m_top = 450.0f;
	dst.m_bottom = 524.0f;
	dst.m_left = 130.0f;
	dst.m_right = 200.0f;

	//‚¨‚Ð‚Â‚¶À‰æ‘œ
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 424.0f;
	src.m_bottom = 320.0f;

	dst.m_left = 130.0f;
	dst.m_right = 200.0f;
	dst.m_top = 526.0f;
	dst.m_bottom = 600.0f;

	//‚¨‚¤‚µÀ‰æ‘œ
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);

	//‰F’ˆ‘D‚Ö‚Ì•¶Žš‚ð•`‰æ‚·‚é
	//					@@X@Y@‘å‚«‚³
	Font::StrDraw(L"‰F’ˆ", 10, 25, 25, c);
	Font::StrDraw(L"‘D‚Ö", 10, 50, 25, c);

	//‰F’ˆ‘D‚Öƒ{ƒ^ƒ“
	// left				 right            top            bottom         
	if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>0 && m_mou_y < 100)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				lever = 0;
				Scene::SetScene(new CSceneStageselect());
				starmodel_flag = false;
			}
		}
		else
		{
			starmodel_flag = true;
		}
		
		
	}
	//‚‚‚ð‰Ÿ‚·‚Æ–ß‚é
	else if (Input::GetVKey('B') == true)
	{
		lever = 0;
		Scene::SetScene(new CSceneStageselect());
	}



	Font::StrDraw(L"…•rÀ", 30 + fy * std, 330 + t*l, 30, c);
	l++;         
	//…•rÀ‚Ì”ÍˆÍ
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{	
			//    top            bottom  
			//•¶Žš
			if (starmodel_flag == true)
			{
				lever = 1;
				starmodel_flag = false;
				Scene::SetScene(new CSceneStarPicbook());
			}
			//‰æ‘œ
			else 
			{
			starmodel_flag = true;
			}
		}
	}
	if (m_mou_x > 130 + 1 * std&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k*(l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				lever = 13;
				starmodel_flag = false;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}
		else
		{
			starmodel_flag = true;
		}
	}

	Font::StrDraw(L"‹›À", 30 + fy * std, 330 + t*l, 30, c);
	l++;
	//‹›À‚Ì”ÍˆÍ
    if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag = true)
			{
				lever = 2;
				starmodel_flag = false;
				Scene::SetScene(new CSceneStarPicbook());
			}
			
		}
		else
		{
			starmodel_flag = true;
		}
	}

	if (m_mou_x > 130 + 1 * std&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k*(l - 1) && m_mou_y < 300 + 73 * l)
	  {
		  if (m_mou_l == true)
		  {
			  if (starmodel_flag == true)
			  {
				  lever = 14;
				  starmodel_flag = false;
				  Scene::SetScene(new CSceneStarPicbook());
			  }
		  }
		  else
		  {
			  starmodel_flag = true;
		  }
	  }

	//‰²—rÀ
	Font::StrDraw(L"‰²—rÀ", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				lever = 3;
				starmodel_flag = false;
				Scene::SetScene(new CSceneStarPicbook());
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}

	if (m_mou_x > 130 + 1 * std&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				lever = 15;
				starmodel_flag = false;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}
		else
		{
			starmodel_flag = true;
		}
	}
	
	//‰²‹À
	Font::StrDraw(L"‰²‹À", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag = true)
			{
				lever = 4;
				starmodel_flag = false;
				Scene::SetScene(new CSceneStarPicbook());
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}

	if (m_mou_x > 130 + 1 * std&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				lever = 16;
				starmodel_flag = false;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}
		else
		{
			starmodel_flag = true;
		}
	}

	t -= 4;
	l -= 4;
	std=1;

	//‘oŽqÀ
	Font::StrDraw(L"‘oŽqÀ", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70*std+side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag = true)
			{
				lever = 5;
				Scene::SetScene(new CSceneStarPicbook());
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}

	if (m_mou_x > 300&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				lever = 17;
				starmodel_flag = false;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}
		else
		{
			starmodel_flag = true;
		}
	}

	//ŠIÀ
	Font::StrDraw(L"ŠIÀ", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag = true)
			{
				lever = 6;
				Scene::SetScene(new CSceneStarPicbook());
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	if (m_mou_x > 300 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				lever = 18;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}
		else
		{
			starmodel_flag = true;
		}
	}

	//Ž‚ŽqÀ
	Font::StrDraw(L"Ž‚ŽqÀ", 30 + fy * std, 350 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag = true)
			{
				lever = 7;
				Scene::SetScene(new CSceneStarPicbook());
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	if (m_mou_x > 300 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				lever = 19;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}
		else
		{
			starmodel_flag = true;
		}
	}

	//‰³—À
	Font::StrDraw(L"‰³—À", 30 + fy * std, 350 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag = true)
			{
				lever = 8;
				Scene::SetScene(new CSceneStarPicbook());
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	if (m_mou_x > 300 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				lever = 20;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}
		else
		{
			starmodel_flag = true;
		}
	}

	t -= 4;
	l -= 4;
	std = 2;
	//“V”‰À
	Font::StrDraw(L"“V”‰À", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag = true)
			{
				lever = 9;
				Scene::SetScene(new CSceneStarPicbook());
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	if (m_mou_x > 500 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				lever = 21;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}
		else
		{
			starmodel_flag = true;
		}
	}
	
Font::StrDraw(L"å¶À", 30 + fy * std, 330 + t*l, 30, c);
l++;

	//å¶À				left		     right							 top						 bottom       
if (m_mou_x > side_a + side_b * std && m_mou_x < 70 * std+side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
{
	if (m_mou_l == true)
	{
		if (starmodel_flag == true)
		{
			lever = 10;
			starmodel_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else
	{
		starmodel_flag = true;
	}
}

//   left				  right			  top			 bottom                
if (m_mou_x > 130+200*std&& m_mou_x < 197*(std+1) && m_mou_y>302+k*(l-1) && m_mou_y < 300+73*l)
{
	if (m_mou_l == true)
	{
		if (starmodel_flag == true)
		{
			lever = 22;
			starmodel_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else
	{
		starmodel_flag = true;
	}
}

	//ŽËŽèÀ
Font::StrDraw(L"ŽËŽèÀ", 30 + fy * std, 350 + t * l, 30, c);
l++;
if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
{
	if (m_mou_l == true)
	{
		if (starmodel_flag = true)
		{
			lever = 11;
			Scene::SetScene(new CSceneStarPicbook());
		}
		else
		{
			starmodel_flag = true;
		}
	}
}
if (m_mou_x > 520 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
{
	if (m_mou_l == true)
	{
		if (starmodel_flag == true)
		{
			lever = 23;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else
	{
		starmodel_flag = true;
	}
}
	//ŽR—rÀ
	Font::StrDraw(L"ŽR—rÀ", 30 + fy * std, 360 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag = true)
			{
				lever = 12;
				Scene::SetScene(new CSceneStarPicbook());
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	if (m_mou_x > 500 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				lever = 24;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}
		else
		{
			starmodel_flag = true;
		}
	}

}