//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameL\Audio.h"
#include "GameHead.h"
#include "ObjStarPresent3.h"
extern int lever;
extern int crick;
extern int cenge ;
extern int star_count;

void CObjStarPresent3::Init()
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

void CObjStarPresent3::Action()
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
			if (a_time == 5)
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

void CObjStarPresent3::Draw()
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

	if (star_count >=0)
	{
		//					�@�@	            X�@ Y�@ �傫��
		Font::StrDraw(L"�Y�x���E�G���E�Q�k�r", 2, 330 + t * l, 20, c);
		l++;

		if (start_flag == true)
		{
			// left				 right            top            bottom               
			if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
			{
				if (m_mou_l == true)
				{
					crick = 1;
					page = 0;
				}
			}
		}


		//					�@�@			    X�@ Y�@ �傫��
		Font::StrDraw(L"�Y�x���E�G�X�E�J�}��", 2, 330 + t * l, 20, c);
		l++;

		if (start_flag == true)
		{
			// left				 right            top            bottom               
			if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
			{
				if (m_mou_l == true)
				{
					crick = 2;
					page = 0;
				}
			}
		}


		//					�@�@		       X�@ Y�@ �傫��
		Font::StrDraw(L"�Y�x���G���n�N���r", 10, 330 + t * l, 20, c);
		l++;

		if (start_flag == true)
		{
			// left				 right            top            bottom               
			if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
			{
				if (m_mou_l == true)
				{
					crick = 3;
					page = 0;
				}
			}
		}

		//					�@�@        X�@        Y�@    �傫��
		Font::StrDraw(L"�u���L�E��", 25, 330 + t * l, 20, c);
		l++;

		if (start_flag == true)
		{
			// left				 right            top            bottom               
			if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
			{
				if (m_mou_l == true)
				{
					crick = 4;
					page = 0;
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
				Font::StrDraw(L"�Ă�т���ɑ������d���ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"��1���ƃ�2����2�̍P���́A�n������231�b�����", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"������B���������̍P���ɂƂĂ��߂��Ƃ����ʂ��Ă��邽��", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"���i�����܂�ɘf���j�ɂ�鉆���i���H�j���N����₷���B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"���̐��͓�d���ŁA��C������ł���Γ���Ō��킯����B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�A���r�A��Łu��̒܁v���Ӗ�����B", left_end, IO_y + Interval_y * ver, font_size, c);
				//8�s�ڂ܂ŁA���s
			}
			else if (page == 1)
			{
				//8�s�܂�
				Font::StrDraw(L"[����(�����ǂ�)�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�V����ɂ����鑾�z�̌�������̒ʂ蓹�i��~�j�������B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[����(����؂�)�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"����V�̂��ϑ��҂Ƒ��̓V�̂̊Ԃ�ʉ߂��邽�߂ɁA���̓V�̂��B����錻�ۂł���B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[��d���i�ɂ��イ�����j�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�n���ォ�猩��P�������������ɋߐڂ��Č����镨���w���B", left_end, IO_y + Interval_y * ver, font_size, c);
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
			page_max = 1; //�ő�y�[�W��
			ver = VER_start; //�����Ԋu������

			//�y�[�W���\��
			swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
			Font::StrDraw(strp, pagex, pagey, pagesize, c);

			Font::StrDraw(L"�Ă�т���ɑ�����ł����邢�P����3�����B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"��������A�n������̋�����185���N�Ɛ��������B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���̐��̍����̓V���v���ȃX�y�N�g���̌��𐶐����A�n����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���̐��Ƃ̊Ԃ̐��ԃK�X�Ɛo�𒲍�����̂ɗ��z�I�ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"����̑����̐��̂悤�ɁA�����ŉ�]���Ă���A���z��100�{", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ȏ�̎��]���x�ł���B���̎�̐��͒ʏ�͐��������邪", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���̐��͗ΐF�ƕ\������鎖���悭����A����͓���Ō�����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�B��̗ΐF�̍P���ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
			//8�s�ڂ܂ŁA���s
			//�y�[�W����
			if (page < 0 || page > 0)
			{
				page = 0;
			}
		}
		else if (crick == 3)
		{
			page_max = 3; //�ő�y�[�W��
			ver = VER_start; //�����Ԋu������

			//�y�[�W���\��
			swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
			Font::StrDraw(strp, pagex, pagey, pagesize, c);

			if (page == 0)
			{
				Font::StrDraw(L"�Ă�т���ɑ�����P����4�����B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"��d���ł����炭�A���ł���ƍl�����Ă���B���̏ꍇ", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�n������͎启A��42.5�b����Č����锺��B��", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�启A���班�Ȃ��Ƃ�2,100au���ꂽ�O����", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"55,000�N�ȏォ���ĉ���Ă���", left_end, IO_y + Interval_y * ver, font_size, c);
				//8�s�ڂ܂ŁA���s
			}
			else if (page == 1)
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
				Font::StrDraw(L"[�A���Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"2�̍P�������҂̏d�S�̎�����O���^�����Ă���V�̂�", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"����B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
			}
			else if (page == 2)
			{
				Font::StrDraw(L"[�p�x�̒P�ʂƂ��Ă̕b�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"����1/60�̊p�x�ł���B1�b��1�x��1/3600�ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[�V���P��(au)�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�����̒P�ʂŁA���m�� 149597870700 m �ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
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
		else if (crick == 4)
		{
			page_max = 2; //�ő�y�[�W��
			ver = VER_start; //�����Ԋu������

			//�y�[�W���\��
			swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
			Font::StrDraw(strp, pagex, pagey, pagesize, c);

			if (page == 0)
			{
				Font::StrDraw(L"�Ă�т���ɑ�����P����3�����B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"��������̑��̍P���Ɨ��ꂽ�ʒu�ɂ��邱�Ƃ���", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�u�������y���v���Ă�т���̈ꕔ�Ƃ��A�V����", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�u�Ă�т���А��v�Ƃ���������U�蒼�����B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"���̍P���͐ԐF�����ŁA�K�����̒ႢSRB�^�̔��K���^��", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�����ό����ɕ��ނ���Ă���A20���O��̎�����", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"0.26�����͈̔͂ŕό����Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);
				//8�s�ڂ܂ŁA���s
				ver++;
			}
			else if (page == 1)
			{
				//8�s�܂�
				Font::StrDraw(L"[�ԐF����(�������傭���傹��)�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�P������n�񐯂��I�������Ƃ̐i���i�K�ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[���K���^�ό���(�͂񂫂��������ւ񂱂�����)�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"������X�s�K���Ȍ��x�ω������邱�Ƃ�����X�y�N�g���^��", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�������܂��͒������ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[�����ό���(�݂Ⴍ�ǂ��ւ񂱂�����)�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�c���Ǝ��k���J��Ԃ����Ƃɂ��A�܂��͐��̌`��", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�ω����邱�Ƃɂ�薾�邳���ω�����ό����̂��ƁB", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
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

	}
	else
	{
	ver = 0;
	Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���150�W�߂Ă�������", left_end, IO_y + Interval_y * ver, font_size, c);
	}
}