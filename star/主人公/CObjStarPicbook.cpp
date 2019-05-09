//GameL�Ŏg�p����w�b�_�[
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
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
}

void CObjStarPicbook::Draw()
{
	int g = 200.0f;//���g�̉��� 200.0f
	int k = 75.0f;//���g�̗��� 75.0f
	int t = 70;//���̖��O�̈ʒu 70
	int l = 0;//t�Ɗ|����p�̕ϐ� 0
	int s = 0;//���̃N���b�N�̌� 0
	int std = 0;//���������Ɉڂ��ϐ� 0
	int side_a = 0;//���̘g�͈� 0
	int side_b = 200;//�E�̘g�͈� 200
	int side_c = 129;//129
	int fy = 200;//���̖��O�̉��� 200
	int font_size = 25;//�����̑傫�� 25
	int  Interval_y = 35;//�����̗����Ԋu 35
	int  left_end = 80;//�������̍��̌��E�����߂� 80

	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float p[4] = { 1.0f,1.0f,1.0f,0.6f, };

	//�J�[�\���\��(�������������)
	swprintf_s(strmous, L"x=%d,y=%d", (int)m_mou_x, (int)m_mou_y);
	Font::StrDraw(strmous, 600, 20, 30, c);


	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�T�C�o�[�w�i�̐؂���
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 513.0f;
	src.m_bottom = 289.0f;

	//�w�i��`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(15, &src, &dst, c, 0.0f);

	//�p�X�e���u���[�^�C���̐؂���
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 130.0f;
	src.m_bottom = 67.0f;

	//�����̘g��`��
	dst.m_top = 300.0f;
	dst.m_left = 0.0f;
	dst.m_right = 67.0f;
	dst.m_bottom = 600.0f;

	//���[�v���ĕ`�悷��
	for (int i = 0; i <= 3; i++)
	{
		//���̖��O�̘g��`��
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

	//�������̔w�i������`��
	dst.m_top = 0.0f;
	dst.m_left = 67.0f;
	dst.m_right =800.0f;
	dst.m_bottom = 300.0f;
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.0f);

	//�߂�{�^���̘g��`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 67.0f;
	dst.m_bottom = 100.0f;
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.0f);

	//���̃y�[�W�ɍs�����߂̃{�^���̘g��`��
	dst.m_top = 200.0f;
	dst.m_bottom = 300.0f;

	//���ւ̘g
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.0f);

	dst.m_top = 100.0f;
	dst.m_bottom = 200.0f;

	//�߂��̘g
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.0f);

	int Dc = 0; //�`��D��x�����p

	//嶍��̉摜�ʒu
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 764.0f;
	src.m_bottom = 578.0f;

	dst.m_top = 380.0f;
	dst.m_left = 330.0f;
	dst.m_right =400.0f;
	dst.m_bottom = 450.0f;
	
	//��������摜
	Draw::Draw(2, &src, &dst, c, 0.0f);

	/*Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 215.0f;
	src.m_bottom = 240.0f;

	dst.m_top = 500.0f;
	dst.m_left = 67.0f;
	dst.m_right = 132.0f;
	dst.m_bottom = 600.0f;

	//�Ă�т���摜
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 215.0f;
	src.m_bottom = 240.0f;

	dst.m_top = 500.0f;
	dst.m_left = 132.0f;
	dst.m_right = 202.0f;
	dst.m_bottom = 600.0f;

	//�ӂ������摜
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 215.0f;
	src.m_bottom = 240.0f;

	dst.m_top = 500.0f;
	dst.m_left = 202.0f;
	dst.m_right = 269.0f;
	dst.m_bottom = 600.0f;

	//�݂����ߍ��摜
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 215.0f;
	src.m_bottom = 240.0f;

	dst.m_top = 500.0f;
	dst.m_left = 269.0f;
	dst.m_right = 338.0f;
	dst.m_bottom = 600.0f;

	//���č��摜
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 215.0f;
	src.m_bottom = 240.0f;

	dst.m_top = 500.0f;
	dst.m_left = 338.0f;
	dst.m_right = 405.0f;
	dst.m_bottom = 600.0f;

	//���������摜
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 215.0f;
	src.m_bottom = 240.0f;

	dst.m_top = 500.0f;
	dst.m_left = 405.0f;
	dst.m_right = 468.0f;
	dst.m_bottom = 600.0f;

	//�€���摜
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 2;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 215.0f;
	src.m_bottom = 240.0f;

	dst.m_top = 500.0f;
	dst.m_left = 468.0f;
	dst.m_right = 536.0f;
	dst.m_bottom = 600.0f;

	//�������摜
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 215.0f;
	src.m_bottom = 240.0f;

	dst.m_top = 500.0f;
	dst.m_left = 536.0f;
	dst.m_right = 603.0f;
	dst.m_bottom = 600.0f;

	//���ɍ��摜
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 215.0f;
	src.m_bottom = 240.0f;

	dst.m_top = 500.0f;
	dst.m_left = 603.0f;
	dst.m_right = 670.0f;
	dst.m_bottom = 600.0f;

	//���Ƃߍ��摜
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 145.0f;
	src.m_bottom = 240.0f;

	dst.m_top = 500.0f;
	dst.m_left = 670.0f;
	dst.m_right = 738.0f;
	dst.m_bottom = 600.0f;

	//���Ђ����摜
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 215.0f;
	src.m_bottom = 240.0f;

	dst.m_top = 500.0f;
	dst.m_left = 738.0f;
	dst.m_right = 800.0f ;
	dst.m_bottom = 600.0f;

	//���������摜
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	*/

	//�F���D�ւ̕�����`�悷��
	//					�@�@X�@Y�@�傫��
	Font::StrDraw(L"�F��", 10, 25, 25, c);
	Font::StrDraw(L"�D��", 10, 50, 25, c);

	//�F���D�փ{�^��
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
	//���������Ɩ߂�
	else if (Input::GetVKey('B') == true)
	{
		lever = 0;
		Scene::SetScene(new CSceneStageselect());
	}

	/*int l = 50;
	

	wchar_t test[2][2]{ L"�",L"��" }; //������
	wchar_t test2[3][2]{ L"�V",L"��",L"��" }; //�Ă�т�
	wchar_t test3[3][2]{ L"�o",L"�q",L"��" }; //�ӂ���
	wchar_t test4[3][2]{ L"��",L"�r",L"��" }; //�݂�����
	wchar_t test5[3][2]{ L"��",L"��",L"��" }; //����
	wchar_t test6[3][2]{ L"��",L"�q",L"��" }; //����
	wchar_t test7[3][2]{ L"�R",L"�r",L"��" }; //�€
	wchar_t test8[2][2]{ L"��",L"��" }; //����
	wchar_t test9[2][2]{ L"�I",L"��" }; //����
	wchar_t test10[3][2]{ L"��",L"��",L"��" }; //���Ƃ�
	wchar_t test11[3][2]{ L"��",L"�r",L"��" }; //�Ђ�
	wchar_t test12[3][2]{ L"��",L"��",L"��" }; //����


		//���[�v���ďo��
		for (int i = 0; i <= 1; i++)
		{
			swprintf_s(str, L"%s", test8[i]);
			swprintf_s(str2, L"%s", test9[i]);
			swprintf_s(str3, L"%s", test[i]);


			//Y�͈��ڂ�i��0�Ȃ̂�0��50���|���Ă���
			//2��ڂ�i��1�Ȃ̂�50��100�ɑ����B
			//				�@�@X�@ Y�@ �傫��
			Font::StrDraw(str, 75, 320 + l * i, 50, c); //test8
			Font::StrDraw(str2, 342, 320 + l * i, 50, c); //test9
			Font::StrDraw(str3, 610, 320 + l * i, 50, c); //test
			


		}
		
		for (int i = 0; i <= 2; i++)
		{
			swprintf_s(str, L"%s", test4[i]);
			swprintf_s(str2, L"%s", test11[i]);
			swprintf_s(str3, L"%s", test12[i]);
			swprintf_s(str4, L"%s", test3[i]);
			swprintf_s(str5, L"%s", test6[i]);
			swprintf_s(str6, L"%s", test10[i]);
			swprintf_s(str7, L"%s", test2[i]);
			swprintf_s(str8, L"%s", test5[i]);
			swprintf_s(str9, L"%s", test7[i]);

			//				�@�@X�@ Y�@ �傫��
			Font::StrDraw(str, 10, 320 + l * i, 50, c); 
			Font::StrDraw(str2, 140, 320 + l * i, 50, c); 
			Font::StrDraw(str3, 208, 320 + l * i, 50, c); 
			Font::StrDraw(str4, 275, 320 + l * i, 50, c); 
			Font::StrDraw(str5, 410, 320 + l * i, 50, c); 
			Font::StrDraw(str6, 480, 320 + l * i, 50, c); 
			Font::StrDraw(str7, 545, 320 + l * i, 50, c); 
			//�񕶎��̐�����2����̂�2�Ԃ�󂯂�
			Font::StrDraw(str8, 680, 320 + l * i, 50, c); 
			Font::StrDraw(str9, 745, 320 + l * i, 50, c); 
		}*/

	Font::StrDraw(L"���r��", 30 + fy * std, 330 + t*l, 30, c);
	l++;
	// left				 right             
	//���r���͈̔�
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{	
			//    top            bottom  
			//����
			if (starmodel_flag == true)
			{
				lever = 1;
				starmodel_flag = false;
				Scene::SetScene(new CSceneStarPicbook());
			}
			//�摜
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

	Font::StrDraw(L"����", 30 + fy * std, 330 + t*l, 30, c);
	l++;
	//�����͈̔�
    if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			if (m_mou_y > 300 && m_mou_y < 490)
			{
				lever = 2;
				Scene::SetScene(new CSceneStarPicbook());
			}
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

	//���r��
	Font::StrDraw(L"���r��", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			if (m_mou_y > 300 && m_mou_y < 490)
			{
				lever = 3;
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
	
	//������
	Font::StrDraw(L"������", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			if (m_mou_y > 300 && m_mou_y < 490)
			{
				lever = 4;
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

	
	//�o�q��
	Font::StrDraw(L"�o�q��", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70*std+side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			if (m_mou_y > 300 && m_mou_y < 490)
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

	/*if (m_mou_x > 130 + 1 * std&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
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
	}*/
	/*
	//���q��
	else if (m_mou_x > 396 && m_mou_x < 463)
	{
		if (m_mou_l == true)
		{
			if (m_mou_y > 300 && m_mou_y < 490)
			{
				lever = 7;
				Scene::SetScene(new CSceneStarPicbook());
			}
			else if (m_mou_y > 500 && m_mou_y < 600)
			{
				lever = 19;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}
	}
	//������
	else if (m_mou_x > 463 && m_mou_x < 530)
	{
		if (m_mou_l == true)
		{
			if (m_mou_y > 300 && m_mou_y < 490)
			{
				lever = 8;
				Scene::SetScene(new CSceneStarPicbook());
			}
			else if (m_mou_y > 500 && m_mou_y < 600)
			{
				lever = 20;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}
	}
	//�V����
	else if (m_mou_x > 530 && m_mou_x < 594)
	{
		if (m_mou_l == true)
		{
			if (m_mou_y > 300 && m_mou_y < 490)
			{
				lever = 9;
				Scene::SetScene(new CSceneStarPicbook());
			}
			else if (m_mou_y > 500 && m_mou_y < 600)
			{
				lever = 21;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}
	}
	*/



	//					�@�@	 X�@		    Y�@ �傫��
Font::StrDraw(L"嶍�", 30 + fy * std, 330 + t*l, 30, c);
l++;

	//嶍�				left		     right							 top						 bottom       
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
/*
	//�ˎ��
	else if (m_mou_x > 662 && m_mou_x < 727)
	{
		if (m_mou_l == true)
		{
			if (m_mou_y > 300 && m_mou_y < 490)
			{
				lever = 11;
				Scene::SetScene(new CSceneStarPicbook());
			}
			else if (m_mou_y > 500 && m_mou_y < 600)
			{
				lever = 23;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}
	}
	//�R�r��
	else
	{
		if (m_mou_l == true)
		{
			if (m_mou_y > 300 && m_mou_y < 490)
			{
				lever = 12;
				Scene::SetScene(new CSceneStarPicbook());
			}
			else if (m_mou_y > 500 && m_mou_y < 600)
			{
				lever = 24;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}
	}*/
}