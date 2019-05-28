//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameL\Audio.h"
#include "GameHead.h"
#include "ObjStarPresent9.h"
extern int lever;
extern int crick;
extern int cenge;
extern int star_count; 

void CObjStarPresent9::Init()
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

	a_time = 0;
	time_flag = false;
	m_mou_time = 0.0f;

	Audio::LoadAudio(1, L"���ʉ�.wav", EFFECT);
}

void CObjStarPresent9::Action()
{

	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	//�A���ړ��h�~
	if (m_mou_time == 60.0f)
	{
		;
	}
	else if (m_mou_time < 60.0f)
	{
		m_mou_time++;
		m_mou_l = false;
	}

	//SE��������
	if (m_mou_l == true)
	{
		time_flag = true;
	}
	else if (m_mou_l == false)
	{
		a_time = 0;
		time_flag = false;
	}

	//SE��������
	if (time_flag == true)
	{
		a_time++;
	}
	if (a_time == 1)
	{
		Audio::Start(1);
	}

	//�����I���փ{�^��
	// left				 right            top            bottom         
	if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>0 && m_mou_y < 100)
	{
		if (m_mou_l == true)
		{
			time_flag = true;
			if (a_time == 10)
			{
				lever = 0;
				a_time = 0;
				Scene::SetScene(new CSceneStarPicbook());
				return;
			}
		}
	}
	//���������Ɩ߂�
	else if (Input::GetVKey('B') == true)
	{
		lever = 0;
		a_time = 0;
		Scene::SetScene(new CSceneStarPicbook());
	}

}

void CObjStarPresent9::Draw()
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

	if (star_count >=450)
	{
	//					�@�@	    X�@ Y�@ �傫��
	Font::StrDraw(L"���O���X", 20, 320 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 1;
				page = 0; //�y�[�W������
			}
		}
	}
	

	//					�@�@	    X�@ Y�@ �傫��
	Font::StrDraw(L"�f�l�{��", 20, 320 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 2;
				page = 0; //�y�[�W������
			}
		}
	}
	

	//					�@�@	    X�@        Y�@    �傫��
	Font::StrDraw(L"�A���M�G�o", 20, 330 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 3;
				page = 0; //�y�[�W������
			}
		}
	}
	
	//					�@�@	  X�@        Y�@    �傫��
	Font::StrDraw(L"�]�X�}", 20, 340 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 4;
				page = 0; //�y�[�W������
			}
		}
	}
	

	t -= 4;
	l -= 4;
	std = 1;

	//					�@�@	  X�@        Y�@    �傫��
	Font::StrDraw(L"�A�_�t�F��", 20 + 220, 320 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 5;
				page = 0; //�y�[�W������
			}
		}
	}
	
	//					�@�@	  X�@        Y�@    �傫��
	Font::StrDraw(L"�V�F���^��", 20 + 220, 330 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 6;
				page = 0; //�y�[�W������
			}
		}
	}
	
	//					  �@�@	    X�@        Y�@    �傫��
	Font::StrDraw(L"�A���e���t", 20 + 220, 340 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 7;
				page = 0; //�y�[�W������
			}
		}
	}
	
	//					  �@�@	    X�@        Y�@    �傫��
	Font::StrDraw(L"���T���X", 20 + 220, 340 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 8;
				page = 0; //�y�[�W������
			}
		}
	}
	

	t -= 4;
	l -= 4;
	std = 2;

	//					�@�@	  X�@        Y�@    �傫��
	Font::StrDraw(L"�X�[�o�[", 20 + 400, 320 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 9;
				page = 0; //�y�[�W������
			}
		}
	}
	


	if (crick == 1)
	{
		page_max = 2; //�ő�y�[�W��
		ver = VER_start; //�����Ԋu������

		//�y�[�W���\��
		swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"�������ɑ�����ł����邢�P���őS�V21��1������1�B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"1�����̒��ł͍ł��Â��قډ�����ɂ���A�q�C�ʒu��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�v���̊�ƂȂ�B��p�P���ƂȂ��Ă���4�̐����e2��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�y�A�ɂȂ��Č݂��ɉ���Ă��鑽�d�A���ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[�����Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�V����ɂ����鑾�z�̌�������̒ʂ蓹�i��~�j�������B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�A���Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2�̍P�������҂̏d�S�̎�����O���^�����Ă���V��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ł���B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		//�y�[�W����
		else if (page < 1)
		{
			page = 0;
		}
		else if (page > 1)
		{
			page = 1;
		}
	}
	else if (crick == 2)
	{
		page_max = 3; //�ő�y�[�W��
		ver = VER_start; //�����Ԋu������

		//�y�[�W���\��
		swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"�������ɑ����邵�����̍P����2�����B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����������̃A�[�N�g�D���X�Ƃ��Ƃߍ��̃X�s�J�Ƃ�", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�t�̑�O�p�`���`�����锒�F�̎�n�񐯁B���č��^�ό���", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ł���A�ό��͈͂͂����킸���Ȃ̂Ŋᎋ�ϑ��ł͕ό�", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�͂킩��Ȃ��B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[��n��(���ク�������)�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�P���̗L�����x�Ɩ��邳���������}�ł��鍶�㉄�т�", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���ł���w���c�V���v�����O�E���b�Z���} (HR�}) ���", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���邭��������Â��ቷ�Ɏ�n��Ɉʒu����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�P���������B�␯�Ƃ�����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[���č��^�ό���(���Ă��f���^�����ւ񂱂�����)�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����ό����̈��ŁA�P���\�ʂɂ����铮�a�����y�є񓮌a����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�̗����̌����ɂ���Č��x���ω�����ό����ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 2)
		{
			Font::StrDraw(L"[�����ό���(�݂Ⴍ�ǂ��ւ񂱂�����)�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�c���Ǝ��k���J��Ԃ����Ƃɂ��A�܂��͐��̌`�󂪕ω�����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���Ƃɂ�薾�邳���ω�����ό����̂��ƁB", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�ό���(�ւ񂱂�����)�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�V�̂̈��ŁA���邳�i�����j���ω�������̂̂��Ƃł���B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		//�y�[�W����
		else if (page < 1)
		{
			page = 0;
		}
		else if (page > 2)
		{
			page = 2;
		}
	}
	else if (crick == 3)
	{
		page_max = 2; //�ő�y�[�W��
		ver = VER_start; //�����Ԋu������

		//�y�[�W���\��
		swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"�������ɑ�����P���ɂ���2�����ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"��F�̋����ł���启�Ɖ��F�����̔�������Ȃ�����A��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ł��肻�̔������Ə��K�͂̓V�̖]�����ł���y�Ɋϑ��ł���", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���Ƃ���V���Ƃ����ɂ��l�C�̍����P���ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�܂������������Q�̕��˓_���߂����Ƃł��m����B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[�����Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���a����і��邳�����ɑ傫���P���B�����̔��a��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���z��10�{����100�{�A���邳��10�{����1000�{��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"����B������薾�邢�P���́A��������ɒ������ƌĂ΂��B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�����A��(��d��)�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"��d���̐����邤���̈�B�]�����ŗ����ɕ������Ċϑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���������]�^�����Ă��鎖���m�F����Ă���A���������B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		//�y�[�W����
		else if (page < 1)
		{
			page = 0;
		}
		else if (page > 1)
		{
			page = 1;
		}
	}
	else if (crick == 4)
	{
		page_max = 2; //�ő�y�[�W��
		ver = VER_start; //�����Ԋu������

		//�y�[�W���\��
		swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"�������ɑ�����P����3�����B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���F�̋P�����ŁA���z�����኱�傫���č����ł��邩�Ȃ�ǂ�", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"��������Ă���A�N���傫�����Ă͔�r�I���m�ɑ��肳���", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���鑾�z�����ɑ傫�Ȏ��ʂ����������͒Z����F�̋�����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ԐF�����ɂȂ�Â��ɔ��F�␯�ɂȂ�ƍl�����Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�P�����Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ɂ߂Ė��邢�����ɕ��ނ����B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[�ԐF�����Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"����Ŋώ@����ƐԂ������邱�Ƃ���u�ԐF�v������", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�Ă΂��B�@���F�␯(�͂����傭�킢����)�c�P����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�i���̏I�����ɂƂ肤��`�Ԃ̈��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�����Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���a����і��邳�����ɑ傫���P���B�����̔��a��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���z��10�{����100�{�A���邳��10�{����1000�{��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"����B������薾�邢�P���́A��������ɒ������ƌĂ΂��B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		//�y�[�W����
		else if (page < 1)
		{
			page = 0;
		}
		else if (page > 1)
		{
			page = 1;
		}
	}
	else if (crick == 5)
	{
		page_max = 2; //�ő�y�[�W��
		ver = VER_start; //�����Ԋu������

		//�y�[�W���\��
		swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"�������ɑ�����P����3�����B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"������F�^�̋����ŁA���S�j�ł͐��f�̊j�Z���͊��ɏI���", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�w���E���̊j�����k���Ă���i�K�ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�������ꂽ�ʒu�ɂ��邵����35�Ԑ��Ƃ͌������̓�d����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�֌W�ɂ���A�A���ł͂Ȃ��B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[��d���Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�n���ォ�猩��P�������������ɋߐڂ��Č����镨���w���B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[�A���Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2�̍P�������҂̏d�S�̎�����O���^�����Ă���V��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ł���B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�����Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���a����і��邳�����ɑ傫���P���B�����̔��a��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���z��10�{����100�{�A���邳��10�{����1000�{��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"����B������薾�邢�P���́A��������ɒ������ƌĂ΂��B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		//�y�[�W����
		else if (page < 1)
		{
			page = 0;
		}
		else if (page > 1)
		{
			page = 1;
		}
	}
	else if (crick == 6)
	{
		page_max = 2; //�ő�y�[�W��
		ver = VER_start; //�����Ԋu������

		//�y�[�W���\��
		swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"�������ɑ�����P����3�����B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"A�^�X�y�N�g���̎�n�񐯂��珀�����ɕ��ނ����B���悻", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"4500���N�O�ɒa�������Ƃ��ɂ�B8�^�̎�n�񐯂ł���", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����͎��ʂ̑傫�Ȕ��F�␯�ɂȂ���̂ƍl�����Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�������Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����X�y�N�g���^�̒ʏ�̎�n�񐯂���▾�邭", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����قǂ͖��邭�Ȃ��P���̕��ނ�1�ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[��n�񐯂Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�P���̗L�����x�Ɩ��邳���������}�ł���", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�w���c�V���v�����O�E���b�Z���} (HR�}) ���", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���邭��������Â��ቷ�ɉ��т���ł����n���", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ʒu����P���������B�␯�Ƃ������B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[���F�␯(�͂����傭�킢����)�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�P�����i���̏I�����ɂƂ肤��`�Ԃ̈�B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		//�y�[�W����
		else if (page < 1)
		{
			page = 0;
		}
		else if (page > 1)
		{
			page = 1;
		}
	}
	else if (crick == 7)
	{
		page_max = 2; //�ő�y�[�W��
		ver = VER_start; //�����Ԋu������

		//�y�[�W���\��
		swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"�������ɑ�����P����4�����B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���������̃A���f�o�����Ƃ悭���ʂ��Ă����Γ����ł�", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�킸���ɂ��̐��̂ق������邢���n������̋�����������", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"��������25�{�قǈÂ�������B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�₪�ă~���̂悤�Ȓ������̕ό����ƂȂ�ƍl�����Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[�ό����Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�V�̂̈��ŁA���邳�i�����j���ω�������̂̂��Ƃ���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�~���Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����ł����k��������ɖ��邳���ɑ�ƂȂ鐫�������B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		//�y�[�W����
		else if (page < 1)
		{
			page = 0;
		}
		else if (page > 1)
		{
			page = 1;
		}
	}
	else if (crick == 8)
	{
		page_max = 1; //�ő�y�[�W��
		ver = VER_start; //�����Ԋu������

		//�y�[�W���\��
		swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		Font::StrDraw(L"�������ɑ�����P����4�����B", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"K�^�̋��������A�܂����S�j�ł̓w���E���̊j�Z����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�n�܂��Ă��炸�j�����k���Ă���i�K�ł���ƍl�����Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"5,000���N��ɂ̓w���E���̊j�Z�����n�܂�A���݂��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"10�{����20�{�͌��x���������̂Ɨ\������Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);

		//�y�[�W����
		if (page < 0 || page > 0)
		{
			page = 0;
		}

	}
	else if (crick == 9)
	{
		page_max = 3; //�ő�y�[�W��
		ver = VER_start; //�����Ԋu������

		//�y�[�W���\��
		swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"�������ɑ�����P����4�����B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"F�^�̃X�y�N�g������������A�^��n�񐯂��A���n��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����Ă��邪�A�启�Ɣ����̕��ϋ�������ϋ߂����ߕ����@", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�܂��̓X�y�b�N�����@�ł����ϑ��ł��Ă��Ȃ�2�̐���", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"14.498���̎����ŋ��ʏd�S���݂��ɏ����Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[A�^��n�񐯂Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�X�y�N�g���^��A�A���x�K����V�̐��f��R�₵�ĔR����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"��n�񐯂ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[��n�񐯂Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�P���̗L�����x�Ɩ��邳���������}�ł���", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�w���c�V���v�����O�E���b�Z���} (HR�}) ���", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���邭��������Â��ቷ�ɉ��т���ł����n���", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ʒu����P���������B�␯�Ƃ������B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 2)
		{
			Font::StrDraw(L"[�A���Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2�̍P�������҂̏d�S�̎�����O���^�����Ă���V��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ł���B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		//�y�[�W����
		else if (page < 1)
		{
			page = 0;
		}
		else if (page > 2)
		{
			page = 2;
		}
	}
	}
else
	{
	ver = 0;
	Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���450�W�߂Ă�������", left_end, IO_y + Interval_y * ver, font_size, c);
	}

}