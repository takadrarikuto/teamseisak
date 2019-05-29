//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameL\Audio.h"
#include "GameHead.h"
#include "ObjStarPresent5.h"
extern int lever;
extern int crick;
extern int cenge;
extern int star_count;

void CObjStarPresent5::Init()
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

	Back_time = 0.0f;

	Audio::LoadAudio(1, L"���ʉ�.wav", EFFECT);
}

void CObjStarPresent5::Action()
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

	Back_time++;

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
				Back_time = 0.0f;
				time_flag = false;
				Scene::SetScene(new CSceneStarPicbook());
				return;
			}
		}
	}
	//���������Ɩ߂�
	else if (Input::GetVKey('B') == true && Back_time > 60.0f)
	{
		lever = 0;
		a_time = 0;
		Back_time = 0.0f;
		time_flag = false;
		Scene::SetScene(new CSceneStarPicbook());
	}



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
	if (star_count >=250)
	{
	//					�@�@	    X�@ Y�@ �傫��
	Font::StrDraw(L"�A�����V��", 15, 320 + t * l, 30, c);
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

	//					�@�@			    X�@    Y�@   �傫��
	Font::StrDraw(L"�t���E�A���E�T�}�J�[", 10, 335 + t * l, 18, c);
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
	Font::StrDraw(L"���[���@�e�B ", 15, 330 + t * l, 30, c);
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
	Font::StrDraw(L"�g���N���A", 15, 330 + t * l, 30, c);
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

	


	if (crick == 1)
	{
		ver = VER_start; //�����Ԋu������
		page_max = 2; //�ő�y�[�W��

		//�y�[�W���\��
		swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"�������ɑ�����4�����ŕό����B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"4.1���̎启A��5.1���̔���B����Ȃ�A���n�ŁA", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�O�������a��130au�A�ߓ_������50au�A���_����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"��190au�̋O�����A���悻720�N�̎����Ō݂���", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���񂵂Ă���B�܂��AAB�ǂ��������ɔ������]���Ă���", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�\������������Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�ό����Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�V�̂̈��ŁA���邳�i�����j���ω�������̂̂��Ƃł���B", left_end, IO_y + Interval_y * ver, font_size, c);
			//8�s�ڂ܂ŁA���s
		}
		else if (page == 1)
		{
			//8�s�܂�
			Font::StrDraw(L"[�A���Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2�̍P�������҂̏d�S�̎�����O���^�����Ă���V��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ł���B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�V���P��(au)�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����̒P�ʂŁA���m�� 149597870700 m �ł���B", left_end, IO_y + Interval_y * ver, font_size, c);	
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
		ver = VER_start; //�����Ԋu������
		page_max = 2; //�ő�y�[�W��

		//�y�[�W���\��
		swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"�������ɑ���������F�̍P���ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"��������4.52�ŁA����ł��݂邱�Ƃ��ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�K�C�A�v��ő��肳�ꂽ�N�������̍ŐV�f�[�^�Ɋ�Â���", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�v�Z���ꂽ�n������̋����͖�420���N�ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����������̎��ʂ͑��z��5�{���a�͑��z��3.6�{��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���肳���B���x�͑��z��810�{�ŗL�����x��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"15,500K�Ɛ��肳���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���]���x�͍����A�������x��100km/s�Ƃ݂���B", left_end, IO_y + Interval_y * ver, font_size, c);
			//8�s�ڂ܂ŁA���s
		}
		else if (page == 1)
		{			
			//8�s�܂�
			Font::StrDraw(L"[�V���w�ɂ����Ă̓����i�Ƃ����イ�j�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�V�̖̂��邳��\���ړx�ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�N�������Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�n���̌��]�^���ɂ�鎋���̂��߂ɓV�̂̓V����̈ʒu��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���]�����Ɠ��������ŕω����Č����錻�ۂ̂��Ƃł���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�X�y�N�g���^�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�P���̕��ޖ@�̈�ł���B�P��������˂��ꂽ�d���g��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����X�y�N�g�����ώ@���ĕ��ނ���B", left_end, IO_y + Interval_y * ver, font_size, c);
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
	else if (crick == 3)
	{
		ver = VER_start; //�����Ԋu������
		page_max = 3; //�ő�y�[�W��

		//�y�[�W���\��
		swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"�������̍P����5�����B5�̍P�������d�����\�����Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"��A�́A����A7�̃X�y�N�g��������2�̏�������", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"Aa��Ab����Ȃ�A�����͒n������͂킸��0.15�b�p����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"����Č�����BBa��Bb�̎�n�񐯂�9.075���̎�����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�݂��Ɏ��񂵂Ă���AB���̃y�A��A���̃y�A����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"22.90�b�p���ꂽ�ʒu�ɂ���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����B������1�b�p�̈ʒu��12.2����C��������B", left_end, IO_y + Interval_y * ver, font_size, c);
			//8�s�ڂ܂ŁA���s
		}
		else if (page == 1)
		{
			//8�s�܂�
			Font::StrDraw(L"[���d���Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�n�����猩��Ƌߐڂ����ʒu�Ɍ�����3�ȏ�̍P���ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�X�y�N�g�����ނƂ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�P���̕��ޖ@�̈�ł���B�X�y�N�g�����ނɂ����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ו����ꂽ���̃^�C�v���X�y�N�g���^�ƌĂԁB�P������", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���˂��ꂽ�d���g�𑨂��A�X�y�N�g�����ώ@���邱�Ƃ�", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"����ĕ��ނ���B�P���̃X�y�N�g���͂��̕\�ʉ��x��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���w�g���ɂ��ς���Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 2)
		{
			//8�s�܂�
			Font::StrDraw(L"[�p�x�̒P�ʂƂ��Ă̕b�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"����1/60�̊p�x�ł���B1�b��1�x��1/3600�ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
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
	else if (crick == 4)
	{
		ver = VER_start; //�����Ԋu������
		page_max = 3; //�ő�y�[�W��

		//�y�[�W���\��
		swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"�������ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"4�����B4.26����A����8.30����B���̓�d���ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���Ɣ����̊Ԃ̌������̋����i���p�j�́A12�~���b�ȏ��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�X�y�b�N���E�C���[�W���O�Ō��o����Ă��Ȃ����Ƃ���", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"30�~���b�ȉ��ł���Ƃ݂���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�启�Ɣ����́A���邳��4�����قǈقȂ�A����䂦������", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"��n�񐯂ł͂Ȃ����Ɨ\�z�����B", left_end, IO_y + Interval_y * ver, font_size, c);
			//8�s�ڂ܂ŁA���s
		}
		else if (page == 1)
		{
			//8�s�܂�
			Font::StrDraw(L"[���p�i�肩���j�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ʒu�V���w�ɂ����āA����_���猩��2�̓V�̂̂Ȃ��p�x��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"����B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�X�y�b�N���E�C���[�W���O�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"������\�̓V�̎B���Z�p���w���p��ł���B���̋Z�p��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�n��ݒu�V�̖]�����̕���\�����I�ɉ��P����B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 2)
		{
			//8�s�܂�
			Font::StrDraw(L"[��d���Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�n���ォ�猩��P�������������ɋߐڂ��Č����镨���w���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"����ł�1�̐��Ɍ����邪�A�]�����ȂǂŊϑ����鎖�ɂ����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2�ɕ�������B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[��n�񐯂Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"��n��Ɉʒu����P���������B�␯�Ƃ������B��ʂ�", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�d���P���قǎ�n��ɗ��܂鎞�Ԃ͒Z���Ȃ�B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�܂��n�񐯂Ƃ��Ă̎������Z���Ȃ�B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
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
	Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���250�W�߂Ă�������", left_end, IO_y + Interval_y * ver, font_size, c);
	}

}