//�g�p����w�b�_�[�t�@�C��
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
	page = 0;//���̃y�[�W�֍s�����߂̕ϐ�
	page_flag = false;
	ver = 0;
	VER_start = 0; //�o�[������
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

	start_time = 0.0f; //�}�E�X����J�n����
	start_flag = false; //�}�E�X����J�n�t���O
}

void CObjStarPresent10::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	//�����I���փ{�^��
	// left				 right            top            bottom         
	if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>0 && m_mou_y < 100)
	{
		if (m_mou_l == true)
		{
			lever = 0;
			start_time = 0; //�}�E�X����J�n����
			Scene::SetScene(new CSceneStarPicbook());

		}
	}
	//���������Ɩ߂�
	else if (Input::GetVKey('B') == true)
	{
		lever = 0;
		start_time = 0; //�}�E�X����J�n����
		Scene::SetScene(new CSceneStarPicbook());
	}

	//30f��ɕ\��
	start_time++;

	if (start_time > 30.0f)
	{
		start_flag = true;
	}
	else
	{
		m_mou_l = false;
		start_flag = false;
	}
}

void CObjStarPresent10::Draw()
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
	Font::StrDraw(L"�X�s�J", 20, 320 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 1;
			}
		}
	}
	

	//					�@�@	    X�@ Y�@ �傫��
	Font::StrDraw(L"�T���B�����@", 20, 330 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 2;
			}
		}
	}
	

	//					�@�@	    X�@        Y�@    �傫��
	Font::StrDraw(L"�|���}", 20, 330 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 3;
			}
		}
	}
	
	//					�@�@	  X�@        Y�@    �傫��
	Font::StrDraw(L"�~�l���E�o", 20, 330 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 4;
			}
		}
	}
	

	t -= 4;
	l -= 4;
	std = 1;

	//					�@�@	  X�@        Y�@    �傫��
	Font::StrDraw(L"���B���f�~�A�g���b�N�X", 20 + 180, 330 + t * l, 18, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 5;
			}
		}
	}
	
	//					�@�@	  X�@        Y�@    �傫��
	Font::StrDraw(L"�U�j�A", 20 + 220, 330 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 6;
			}
		}
	}
	
	//					  �@�@	    X�@        Y�@    �傫��
	Font::StrDraw(L"�V�����}", 20 + 220, 340 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 7;
			}
		}
	}
	
	Font::StrDraw(L"�J���O", 20 + 220, 340 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 8;
			}
		}
	}
	

	t -= 4;
	l -= 4;
	std = 2;

	//					�@�@	  X�@        Y�@    �傫��
	Font::StrDraw(L"�J���{���A", 20 + 400, 320 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 9;
			}
		}
	}
	
	//					�@�@	  X�@        Y�@    �傫��
	Font::StrDraw(L"�G���K���t�@", 20 + 400, 330 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 10;
			}
		}
	}
	

	if (crick == 1)
	{
		ver = VER_start; //�����Ԋu������
		Font::StrDraw(L"���Ƃߍ��ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���Ƃߍ��ōł����邢�P���őS�V21��1������1�B�t�̖��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�����P���B����B�^�̃X�y�N�g��������0.98����10.5����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�P������Ȃ�A���n�ł���B0.17���̎�����0.015���ό�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���Ă���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�A���c2�̍P�������҂̏d�S�̎�����O���^�����Ă���V�̂�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"����B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�ό��c���邳�i�����j���ω�������̂̂��Ƃł���", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 2)
	{
		ver = VER_start; //�����Ԋu������
		Font::StrDraw(L"���Ƃߍ��ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���Ƃߍ��̕��p�ɂ���P����4�����B���z�����傫��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�d���A��r�I�����ʂɕx��ł��鉩���ɂ��Ȃ�߂��ʒu��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���邽�߁A���⎞�ɂ͘f���ɂ�鉆�����ϑ������", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�����c�V����ɂ����鑾�z�̌�������̒ʂ蓹�i��~�j������", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�����c����V�̂��ϑ��҂Ƒ��̓V�̂̊Ԃ�ʉ߂��邽�߂�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���̓V�̂��B����錻�ۂł���", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 3)
	{
		ver = VER_start; //�����Ԋu������
		Font::StrDraw(L"���Ƃߍ��ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���Ƃߍ��ɂ���3�����̘A���ł���BF�^��n�񐯓��m����Ȃ�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�A���ł���B�����͎启�̎����168.93�N�Ō��]���Ă���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"F�^��n�񐯁c�X�y�N�g���^��F�A���x�K����V�̐��f��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�R�₵�ĔR�����n�񐯂ł���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�A���c2�̍P�������҂̏d�S�̎�����O���^�����Ă���V�̂�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"����B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 4)
	{
		ver = VER_start; //�����Ԋu������
		Font::StrDraw(L"���Ƃߍ��ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���Ƃߍ��̍P����3�����B���̐��͐ԐF�������� (RGB) ��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�i�K�ɂ���B�n������ϑ�����80�b���ꂽ�ʒu�Ɍ�����11����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�͔����̉\��������Ƃ����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�ԐF�����c�P������n�񐯂��I�������Ƃ̐i���i�K�ł���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"��C���c�����A���̑傫���͒n���̌��]�O�����a����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�ΐ��̂���ɑ�������", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 5)
	{
		ver = VER_start; //�����Ԋu������
		Font::StrDraw(L"���Ƃߍ��ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���Ƃߍ��̍P���ł���B3�����̉��F�����ŁA���Ƃߍ��ł�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�����̃X�s�J�A�����̃|���}�Ɏ����Ŗ��邢�N��0.2�b�Ƃ���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�����ňړ����Č�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�����c�����\�ʉ��x������n�񐯂������a����і��邳��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���ɑ傫���P���̂��Ƃł��鋐���̔��a�͑��z��10�{����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"100�{�A���邳��10�{����1000�{�ł���", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 6)
	{
		ver = VER_start; //�����Ԋu������
		Font::StrDraw(L"���Ƃߍ��ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�P����4�����B�����A���ŁA3�̐����琬��A���n�ł����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�l�����Ă���B������1�́A���ϖ�10au���ꂽ�O����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"13.12�N���|���Ď��񂵂Ă���B����Ɏ启�ɂ͖�0.5au��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�O����72���̎����ŉ�锺��������ƌ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"au�c�V���P�ʂƌ����A�����̒P�ʂŁA���m�� 149597870700 m ", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�ł���B��Ƃ��ēV���w�ŗp�����A��Ƃ��Ēn���Ƒ��z��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�����̋ߎ��l�͖�1 au�ł���Əq�ׂ邱�Ƃ��ł���", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 7)
	{
		ver = VER_start; //�����Ԋu������
		Font::StrDraw(L"���Ƃߍ��ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���Ƃߍ��̕��p�ɂ���P����4�����B", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"2010�N�Ɏ��͂�55�N�Ō��]���锺���𔭌������Ƃ���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�������ʂ����\���ꂽ�B�����̒��ڌ��o�ɂ͐������Ă��Ȃ���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���z��0.6�{�̎��ʂ�����n�񐯂����F�␯�ł����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�l�����Ă���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"��n�񐯁c�P���̗L�����x�Ɩ��邳���������}�ł���w���c�V��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L" �v�����O�E���b�Z���}(HR�}) ��Ŗ��邭��������Â��ቷ��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���т���ł����n��Ɉʒu����P���������B�␯�Ƃ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���F�␯�c�P�����i���̏I�����ɂƂ肤��`�Ԃ̈��", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 8)
	{
		ver = VER_start; //�����Ԋu������
		Font::StrDraw(L"���Ƃߍ��ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���Ƃߍ��̍P����4�����B�����̓�\���h�̂P��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�u�� (Kang)�v�̋����Ƃ����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"��\���h�i�ɂ��イ�͂����キ�j�c�V�����A28�̃G���A�i���h�j", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�ɕs�ϓ������������́B��\���Ɂi�ɂ��イ�͂�����j�Ƃ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���h�i�������キ�j�c�V����̓V�̐ԓ��t�߁i�{���͌���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�ʂ蓹�ł��锒���j��27�Ȃ���28�̃G���A�ɕ�����������", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"��������u���̏h��v���Ӗ����邪���{�⒆���ł�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"��ʂɐ��h�ƌĂ�ł���B���h�͐��E�e�n�Ɍ�����", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 9)
	{
		ver = VER_start; //�����Ԋu������
		Font::StrDraw(L"���Ƃߍ��ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���Ƃߍ��̍P����5�����B5.00���̎启��5.63���̔����ɂ��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�����A���ł���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�����A���i�Ԃ񂱂���񂹂��j�c�]�������g�p���Ă�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�����ł��Ȃ��Ƃ������I�ȃX�y�N�g�����̈ړ���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�p���X�����̕ϓ��ȂǃX�y�N�g���̓����̎����I�ȕω���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�����2�ȏ�̓V�̂���Ȃ邱�Ƃ����o�ł���A���̂���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�A���c2�̍P�������҂̏d�S�̎�����O���^�����Ă���V�̂�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"����B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 10)
	{
		ver = VER_start; //�����Ԋu������
		Font::StrDraw(L"���Ƃߍ��ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���Ƃߍ��̍P����5�����B4.92���̉��F�����܂��͏�������A����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"10.02���̞�F�␯��B������Ȃ�A���n��A�����g��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�����A���ł���\������������Ă���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�����c�����\�ʉ��x������n�񐯂������a����і��邳��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���ɑ傫���P���̂��Ƃł���", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�������c�����X�y�N�g���^�̒ʏ�̎�n�񐯂���▾�邭", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�����قǂ͖��邭�Ȃ��P���̕��ނ�1�ł���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�A���c2�̍P�������҂̏d�S�̎�����O���^�����Ă���V�̂�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"����B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��", left_end, IO_y + Interval_y * ver, font_size, c);
	}

}
