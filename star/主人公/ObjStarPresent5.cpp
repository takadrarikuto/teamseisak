//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjStarPresent5.h"
extern int lever;
extern int crick;
extern int cenge;


void CObjStarPresent5::Init()
{
	page = 0;//���̃y�[�W�֍s�����߂̕ϐ�
	page_flag = false;
	ver = 0;
	g = 200;//���g�̉���
	k = 75;//���g�̗���	
	s = 0;//���̃N���b�N�̌�	
	side_a = 0;
	side_b = 200;
	size = 25;
	size_y = 30;
	font = 80;
	fy = 200.0f;//���̖��O�̉���
	font_size = 25;//�����̑傫��
	IO_y = 25; //y���W�J�n�n�_
	Interval_y = 35;//�����̗����Ԋu
	left_end = 80;//�������̍��̌��E�����߂�
	pagex = 680; //�y�[�W���Wx
	pagey = 10; //�y�[�W���Wy
	pagesize = 20; //�y�[�W�T�C�Y

}

void CObjStarPresent5::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();


}

void CObjStarPresent5::Draw()
{
	//����͂����Ɏc��
	t = 70;//���̖��O�̈ʒu 
	l = 0;//t�Ɗ|����p�̕ϐ� 
	std = 0;


	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };
	float p[4] = { 1.0f,1.0f,1.0f,0.6f, };
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
	dst.m_right = 200.0f;
	dst.m_bottom = 350.0f;

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
	dst.m_right = 800.0f;
	dst.m_bottom = 300.0f;
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.f);

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

	//�����I���ւ̕�����`�悷��
	//					�@�@X�@Y�@�傫��
	Font::StrDraw(L"����", 10, 25, 25, c);
	Font::StrDraw(L"�I��", 10, 50, 25, c);
	Font::StrDraw(L"��", 10, 75, 25, c);

	//�����I���փ{�^��
	// left				 right            top            bottom         
	if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>0 && m_mou_y < 100)
	{
		if (m_mou_l == true)
		{
			lever = 0;
			Scene::SetScene(new CSceneStarPicbook());

		}
	}
	//���������Ɩ߂�
	else if (Input::GetVKey('B') == true)
	{
		lever = 0;
		Scene::SetScene(new CSceneStarPicbook());
	}

	//���ւ̕��������[�v���ďo��
	wchar_t next[2][2]{ L"��",L"��" };
	for (int i = 0; i <= 1; i++)
	{
		int l = 25;
		swprintf_s(str, L"%s", next[i]);
		//				�@�@X�@ Y�@ �傫��
		Font::StrDraw(str, 20, 130 + l * i, 25, c);
	}

	//�߂��̕��������[�v���ďo��
	wchar_t before[2][2]{ L"��",L"��" };
	for (int i = 0; i <= 1; i++)
	{
		int l = 25;
		swprintf_s(str, L"%s", before[i]);

		//				�@�@X�@ Y�@ �傫��
		Font::StrDraw(str, 20, 230 + l * i, 25, c);
	}

	//�߂����������StarPresent�ɐ؂�ւ���
	// left				 right            top            bottom       
	if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>190 && m_mou_y < 300)
	{
		if (m_mou_l == true)
		{
			if (page_flag == true)
			{
				page--;
				page_flag = false;
			}
		}
		else
		{
			page_flag = true;
		}
	}

	//���ւ���������StarPresent2�ɐ؂�ւ���
	// left				 right            top            bottom       
	if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>100 && m_mou_y < 200)
	{
		if (m_mou_l == true)
		{
			if (page_flag == true)
			{
				page++;
				page_flag = false;
			}
		}
		else
		{
			page_flag = true;
		}
	}


	//					�@�@	    X�@ Y�@ �傫��
	Font::StrDraw(L"�A�����V��", 15, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 1;
		}
	}

	//					�@�@			    X�@    Y�@   �傫��
	Font::StrDraw(L"�t���E�A���E�T�}�J�[", 10, 335 + t * l, 18, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 2;
		}
	}

	//					�@�@	    X�@        Y�@    �傫��
	Font::StrDraw(L"���[���@�e�B ", 15, 330 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 3;
		}
	}
	//					�@�@	  X�@        Y�@    �傫��
	Font::StrDraw(L"�g���N���A", 15, 330 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 4;
		}
	}


	if (crick == 1)
	{
		ver = 0;
		Font::StrDraw(L"�������ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"4.1���̎启A��5.1���̔���B����Ȃ�A���n", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���悻720�N�̎����Ō݂��Ɏ��񂵂Ă���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�A���c2�̍P�������҂̏d�S�̎�����O���^�����Ă���V�̂�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"����B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 2)
	{
		ver = 0;
		Font::StrDraw(L"�������ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�����������̃X�y�N�g���^��B6 Ve���ʂ͑��z��5�{", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���a�͑��z��3.6�{�Ɛ��肳���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�X�y�N�g���^�c�P���̕��ޖ@�̈�ł���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�P��������˂��ꂽ�d���g�𑨂��X�y�N�g�����ώ@���ĕ��ނ���", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 3)
	{
		ver = 0;
		Font::StrDraw(L"�������ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"5�̍P�������d�����\�����Ă���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���d���c�n�����猩��Ƌߐڂ����ʒu�Ɍ�����3�ȏ�̍P����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"����", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 4)
	{
		ver = 0;
		Font::StrDraw(L"�������ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"4�����B4.26����A����8.30����B���̓�d���ł���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"��d���c�n���ォ�猩��P�������������ɋߐڂ��Č����镨��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�w��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"����ł�1�̐��Ɍ����邪�A�]�����ȂǂŊϑ����鎖�ɂ����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"2�ɕ�������", left_end, IO_y + Interval_y * ver, font_size, c);
	}


}