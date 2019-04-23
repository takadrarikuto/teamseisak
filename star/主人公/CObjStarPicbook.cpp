//GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"


#include "CObjStarPicbook.h"
#include "GameHead.h"
extern int lever;

void CObjStarPicbook::Init()
{
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
	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�J�[�\���\��(�������������)
	swprintf_s(strmous, L"x=%d,y=%d", (int)m_mou_x, (int)m_mou_y);
	Font::StrDraw(strmous, 600, 20, 30, c);


	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu
	//�u���b�N�^�C���̐؂���
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1039.0f;
	src.m_bottom = 469.0f;

	//�����̘g��`��
	dst.m_top = 300.0f;
	dst.m_left = 0.0f;
	dst.m_right = 67.0f;
	dst.m_bottom = 600.0f;

	//���[�v���ĕ`�悷��
	for (int i = 0; i <= 11; i++)
	{
		//���̖��O�̘g��`��
		Draw::Draw(1, &src, &dst, c, 0.0f);
		dst.m_left = dst.m_right + 0.0f;
		dst.m_right = dst.m_right + 67.0f;
	}

	//�߂�{�^���̘g��`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 67.0f;
	dst.m_bottom = 100.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);

	//���̃y�[�W�ɍs�����߂̃{�^���̘g��`��
	dst.m_top = 200.0f;
	dst.m_bottom = 300.0f;

	//���ւ̘g
	Draw::Draw(1, &src, &dst, c, 0.0f);
	dst.m_top = 100.0f;
	dst.m_bottom = 200.0f;

	//�߂��̘g
	Draw::Draw(1, &src, &dst, c, 0.0f);

	int Dc = 0; //�`��D��x�����p

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 215.0f;
	src.m_bottom = 240.0f;

	dst.m_top = 500.0f;
	dst.m_left = 0.0f;
	dst.m_right = 67.0f;
	dst.m_bottom = 600.0f;
	
	//��������摜
	Draw::Draw(2, &src, &dst, c, 0.0f);
	Dc += 1;

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
			lever = 0;
			Scene::SetScene(new CSceneStageselect());
		}
	}
	//���������Ɩ߂�
	else if (Input::GetVKey('B') == true)
	{
		lever = 0;
		Scene::SetScene(new CSceneStageselect());
	}

	int l = 50;
	

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
		}

	// left				 right             
	//���r���͈̔�
	if (m_mou_x > 0 && m_mou_x < 67)
	{
		if (m_mou_l == true)
		{	
			//    top            bottom  
			//����
			if (m_mou_y > 300 && m_mou_y < 490)
			{
				
			}
			//�摜
			else if (m_mou_y > 500 && m_mou_y < 600)
			{
				
			}
		}
	}
	//�����͈̔�
	else if (m_mou_x > 67 && m_mou_x < 130)
	{
		if (m_mou_l == true)
		{
			if (m_mou_y > 300 && m_mou_y < 490)
			{

			}
			else if (m_mou_y > 500 && m_mou_y < 600)
			{

			}
		}
	}
	//���r��
	else if (m_mou_x > 130 && m_mou_x < 200)
	{
		if (m_mou_l == true)
		{
			if (m_mou_y > 300 && m_mou_y < 490)
			{

			}
			else if (m_mou_y > 500 && m_mou_y < 600)
			{

			}
		}
	}
	//������
	else if (m_mou_x > 200 && m_mou_x < 265)
	{
		if (m_mou_l == true)
		{
			if (m_mou_y > 300 && m_mou_y < 490)
			{

			}
			else if (m_mou_y > 500 && m_mou_y < 600)
			{

			}
		}
	}
	//�o�q��
	else if (m_mou_x > 265 && m_mou_x < 330)
	{
		if (m_mou_l == true)
		{
			if (m_mou_y > 300 && m_mou_y < 490)
			{

			}
			else if (m_mou_y > 500 && m_mou_y < 600)
			{

			}
		}
	}
	//�I��
	else if (m_mou_x > 330 && m_mou_x < 396)
	{
		if (m_mou_l == true)
		{
			if (m_mou_y > 300 && m_mou_y < 490)
			{

			}
			else if (m_mou_y > 500 && m_mou_y < 600)
			{

			}
		}
	}
	//���q��
	else if (m_mou_x > 396 && m_mou_x < 463)
	{
		if (m_mou_l == true)
		{
			if (m_mou_y > 300 && m_mou_y < 490)
			{

			}
			else if (m_mou_y > 500 && m_mou_y < 600)
			{

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

			}
			else if (m_mou_y > 500 && m_mou_y < 600)
			{

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

			}
			else if (m_mou_y > 500 && m_mou_y < 600)
			{

			}
		}
	}
	//嶍�
	else if (m_mou_x > 594 && m_mou_x < 662)
	{
		if (m_mou_l == true)
		{
			if (m_mou_y > 300 && m_mou_y < 490)
			{
				lever = 1;
				Scene::SetScene(new CSceneStarPicbook());
			}
			else if (m_mou_y > 500 && m_mou_y < 600)
			{
				lever = 11;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}
	}
	//�ˎ��
	else if (m_mou_x > 662 && m_mou_x < 727)
	{
		if (m_mou_l == true)
		{
			if (m_mou_y > 300 && m_mou_y < 490)
			{

			}
			else if (m_mou_y > 500 && m_mou_y < 600)
			{

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

			}
			else if (m_mou_y > 500 && m_mou_y < 600)
			{

			}
		}
	}
}