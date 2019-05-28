//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameL\Audio.h"
#include "GameHead.h"
#include "ObjStarPresent7.h"
extern int lever;
extern int crick;
extern int cenge;


void CObjStarPresent7::Init()
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
	Audio::LoadAudio(1, L"���ʉ�.wav", EFFECT);
}

void CObjStarPresent7::Action()
{
	


	if (m_mou_l == true)
	{
		time_flag = true;
	}
	else if (m_mou_l == false)
	{
		a_time = 0;
		time_flag = false;
	}


	if (time_flag == true)
	{
		a_time++;
	}

	if (a_time == 1)
	{
		Audio::Start(1);
	}
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

void CObjStarPresent7::Draw()
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
	Font::StrDraw(L"�J�X�g��", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"�|���b�N�X", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"�A���w�i", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"���T�g", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"���u�X�^", 20 + 220, 320 + t * l, 30, c);
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
	Font::StrDraw(L"���N�u�_", 20 + 220, 330 + t * l, 30, c);
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
	Font::StrDraw(L"�v���v�X", 20 + 220, 340 + t * l, 30, c);
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
	
	//					�@�@	  X�@        Y�@    �傫��
	Font::StrDraw(L"�e�W�F�b�g", 20 + 220, 350 + t * l, 30, c);
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
	std=2;
	//					�@�@	  X�@        Y�@    �傫��
	Font::StrDraw(L"�A���Y��", 20 + 420, 320 + t * l, 30, c);
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

	//					  �@�@	    X�@        Y�@    �傫��
	Font::StrDraw(L"�`�V���G�C", 20 + 420, 330 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 10;
				page = 0; //�y�[�W������
			}
		}
	}



	if (crick == 1)
	{
		page_max = 3; //�ő�y�[�W��
		ver = VER_start; //�����Ԋu������

		//�y�[�W���\��
		swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"�ӂ������ɑ�����2�Ԗڂɖ��邢�P���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�o�C�G�������ł̓����Ƃ���Ă͂��邪", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ӂ����������i1�����A�|���b�N�X�j�������Â��B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�J�X�g���̓|���b�N�X�Ƃ��킹�āA�V����Ō������ア����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ӂ������̂悤�Ɍ����A�����̂ЂƂł���ӂ�������", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�`������B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�O�嗬���Q�̈�ɐ�������ӂ����������Q��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�J�X�g���t�߂���˓_�Ƃ��Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);
			//8�s�ڂ܂ŁA���s
		}
		else if (page == 1)
		{
			//8�s�܂�
			Font::StrDraw(L"[�ӂ����������Q(�ӂ�������イ��������)�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ӂ���������(�J�X�g��)�t�߂���˓_�Ƃ��ďo������", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����Q�ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ӂ������������Q�i�ӂ������A���t�@��イ��������j�Ƃ�", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�Ă΂��B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�����Q�i��イ��������j�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���̋O�Ղ��V����̂����_�i���˓_�܂����t�˓_�Ƃ����j��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���S�ɕ��ˏ�ɍL����悤�ɏo�������Q�̗����̂��Ƃ������B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 2)
		{
			Font::StrDraw(L"[���˓_�i�ق�����Ă�j�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����Q�ɑ����闬���i�Q�����j�����ˏ�ɔ�яo���Ă���悤��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"������A�V�����1�_�̂��Ƃł���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�t�˓_�i�ӂ�����Ă�j�Ƃ������B", left_end, IO_y + Interval_y * ver, font_size, c);
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
	else if (crick == 2)
	{
		page_max = 1; //�ő�y�[�W��
		ver = VER_start; //�����Ԋu������

		//�y�[�W���\��
		swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		Font::StrDraw(L"�ӂ������ɑ�����ł����邢�P���B", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�S�V21��1������1�~�̃_�C�������h���`������", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�P����1�ł�����B", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���݂̞�F�������P���B�����̃J�X�g���ƂƂ��ɁA�ӂ�������", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�Z��̓��Ɍ����Ă��Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);	

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
			Font::StrDraw(L"�ӂ������ɑ�����3�Ԗڂɖ��邢�P���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����A���ŁA�启��A�^�̏������B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����͑��z�Ƃقړ������ʂ������A�启�𕽋�8.5au���ꂽ", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���S���̕���8.5au���ꂽ���S���̍����O����12.6�N��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����Ŏ��񂵂Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[�����A���i�Ԃ񂱂���񂹂��j�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�]�������g�p���ĕ����ł��Ȃ��Ƃ��A�X�y�N�g���̓�����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����I�ȕω��ɂ����2�ȏ�̓V�̂���Ȃ邱�Ƃ�", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���o�ł���A���̂��ƁB", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"����ɑ΂��A�]�����ŕ����ł�����̂������A���Ƃ����B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�������Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����X�y�N�g���^�̒ʏ�̎�n�񐯂���▾�邭", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����قǂ͖��邭�Ȃ��P���̕��ނ�1�ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 2)
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
			Font::StrDraw(L"[au(�V���P��)�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����̒P�ʂŐ��m�� 149597870700 m�ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
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
		page_max = 3; //�ő�y�[�W��
		ver = VER_start; //�����Ԋu������

		//�y�[�W���\��
		swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"�ӂ������ɑ�����P����4�����B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"F�^�̏�������4������A����K�^��n�񐯂�8������", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"B���ɂ��A���n�ŁAB����A������100au�̋��������悻", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"1,200�N�����Ď��񂵂Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"A���͂���ɕ����A���Ƃ���邪�ڍׂ͂킩���Ă��Ȃ��B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[������(����񂫂傹��)�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����X�y�N�g���^�̒ʏ�̎�n�񐯂���▾�邭�A�����قǂ�", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���邭�Ȃ��P���̕��ނ�1�ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[K�^��n��(K�������ク�������)�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���S���ł̐��f�̊j�Z���ŋP���Ă���B���ʂ͑��z��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"0.46�{����0.8�{�A�\�ʉ��x��3,900K����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"5,200K�ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
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
			Font::StrDraw(L"[�����A���i�Ԃ񂱂���񂹂��j�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�]�������g�p���ĕ����ł��Ȃ��Ƃ��A�����I�ȃX�y�N�g������", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ړ���p���X�����̕ϓ��ȂǁA�X�y�N�g���̓����̎����I��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ω��ɂ����2�ȏ�̓V�̂���Ȃ邱�Ƃ�", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���o�ł���A���̂��ƁB", left_end, IO_y + Interval_y * ver, font_size, c);
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
	else if (crick == 5)
	{
		page_max = 2; //�ő�y�[�W��
		ver = VER_start; //�����Ԋu������

		//�y�[�W���\��
		swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"�ӂ������ɑ�����P����3�����B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�������ŁA���ɉ��������ۂɏڍׂȊϑ���������Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"110�b���ꂽ�ʒu�Ɍ�����K2�^��10�����Ƃ͌�������", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"��d���̊֌W�ɂ���A�A���ł͂Ȃ��B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�������Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���z���͂邩�ɑ傫�����邢�P���̂��ƁB���邳�͐F��������", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ꍇ�͑��z��1���{�i�S�G�l���M�[���˂ő��z��10���{�j�ȏ�", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ԐF�������̏ꍇ�͑��z�̐���{�i��3���{�j�ȏ゠��B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[�p�x�̒P�ʂƂ��Ă̕b�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"����1/60�̊p�x�ł���B1�b��1�x��1/3600�ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[��d���Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�n���ォ�猩��P�������������ɋߐڂ��Č����镨��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�w���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�A���Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2�ȏ�̍P�������҂̏d�S�̎�����O���^�����Ă���V��", left_end, IO_y + Interval_y * ver, font_size, c);
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
	else if (crick == 6)
	{
		page_max = 2; //�ő�y�[�W��
		ver = VER_start; //�����Ԋu������

		//�y�[�W���\��
		swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"�ӂ������ɑ�����P����4�����B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"10.15���̎�����3.62������4.18���܂ŕό�����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�P�t�F�C�h�ό����̒������ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�B�܂������A���ł����邪�A�����̏ڍׂ͂킩���Ă��Ȃ��B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[�P�t�F�C�h�ό����Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�������ς�邱�Ƃ��̐��̕ό��͈͂�1�`2��������2�`50��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�قǂł���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�����A���i�Ԃ񂱂���񂹂��j�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�]�������g�p���ĕ����ł��Ȃ��Ƃ��A�����I�ȃX�y�N�g������", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ړ���p���X�����̕ϓ��ȂǁA�X�y�N�g���̓����̎����I��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ω��ɂ����2�ȏ�̓V�̂���Ȃ邱�Ƃ�", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���o�ł���A���̂��ƁB", left_end, IO_y + Interval_y * ver, font_size, c);
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
		page_max = 4; //�ő�y�[�W��
		ver = VER_start; //�����Ԋu������

		//�y�[�W���\��
		swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"�ӂ������ɑ�����P����3�����B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���悻232.9���̎�����3.15������3.9���܂�", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ό����锼�K���^�ό����̋����ł���A�܂������ɂ��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����ŕό�����A���S���^�ό����ł�����B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"1781�N�ɃE�B���A���E�n�[�V�F�����V�����𔭌������̂�", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���̍P���̋߂��ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[���K���^�ό���(�͂񂫂��������ւ񂱂�����)�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���Ȃ�����I�ɕό����邱�Ƃ����������X�s�K���Ȍ��x�ω���", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���邱�Ƃ�����A��������ӊ��̃X�y�N�g���^������", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����܂��͒������ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�X�y�N�g�����ނƂ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�P���̕��ޖ@�̈�B�X�y�N�g�����ނɂ���čו����ꂽ����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�^�C�v���X�y�N�g���^�ƌĂԁB�P��������˂��ꂽ�d���g��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����A�X�y�N�g�����ώ@���邱�Ƃɂ���ĕ��ނ���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
		}
		else if (page == 2)
		{
			Font::StrDraw(L"[�����Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���a����і��邳�����ɑ傫���P���B�����̔��a��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���z��10�{����100�{�A���邳��10�{����1000�{��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"����B������薾�邢�P���́A��������ɒ������ƌĂ΂��B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�������Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���z���͂邩�ɑ傫�����邢�P���̂��ƁB���邳�͐F��������", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ꍇ�͑��z��1���{�i�S�G�l���M�[���˂ő��z��10���{�j�ȏ�", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ԐF�������̏ꍇ�͑��z�̐���{�i��3���{�j�ȏ゠��B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
		}
		else if (page == 3)
		{
			Font::StrDraw(L"[�A���S���^�ό���(�A���S�������ւ񂱂�����)�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�H�ό����̕��ނ�1�ŁA�O�����ʂ��n������̕��p��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"��v���Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�E�B���A���E�n�[�V�F���Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�h�C�c�̃n�m�[�t�@�[�o�g�̃C�M���X�̓V���w�ҁE���y��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�E�]��������ҁB", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
		}
		//�y�[�W����
		else if (page < 1)
		{
			page = 0;
		}
		else if (page > 3)
		{
			page = 3;
		}
	}
	else if (crick == 8)
	{
		page_max = 2; //�ő�y�[�W��
		ver = VER_start; //�����Ԋu������

		//�y�[�W���\��
		swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"�ӂ������ɑ�����P����3�����B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���z�ɔ��1,540�{�ȏ�̃G�l���M�[����o���Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����a��0.0135�b�B�n�����猩���ꍇ�A���̍P������", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"5�{�ȏ�̑��x�ňړ����Ă���悤�Ɍ�����B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�n�����猩��2������Ĉʒu����9�����̐��́A�߂���", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����Ă��邾���ł���A���ۂɂ̓ʐ��Ƃ͊֘A���͖�����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"��������Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[�p�x�̒P�ʂƂ��Ă̕b�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"����1/60�̊p�x�ł���B1�b��1�x��1/3600�ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
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
	else if (crick == 9)
	{
		page_max = 2; //�ő�y�[�W��
		ver = VER_start; //�����Ԋu������

		//�y�[�W���\��
		swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"�ӂ������ɑ�����3�����̍P���ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�n�������60���N���ꂽ�AF�^��n�񐯂��邢�͏�������", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���z��1.7�{�̎��ʂ�2.7�{�̔��a�����B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�N���15���N�ƎႭ�A�����ʂ͑��z�Ƃقړ����x��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"����Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[F�^��n��(F�������ク���������)�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���f��R�₵�ĔR�����n�񐯂ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���z���ʂ�1.0�{����1.4�{�̎��ʂ������A�\�ʉ��x��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"6000K����7600K�̊Ԃł���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�������Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����X�y�N�g���^�̒ʏ�̎�n�񐯂���▾�邭", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����قǂ͖��邭�Ȃ��P���̕��ނ�1�ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
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
	else if (crick == 10)
	{
		page_max = 2; //�ő�y�[�W��
		ver = VER_start; //�����Ԋu������

		//�y�[�W���\��
		swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"�ӂ������ɑ�����P����5�����B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ŗL���̐ϐ��́A�Ñ㒆���̓V���w�ɂ����ē�\���h��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"1�̈�h�Ƃ������h�Ɋ܂܂�鐯���ŁA���𒙂��邱��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�]���ėp���r��C�Ȃǂ��Ӗ�����B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2017�N6��30���A���ۓV���w�A���̍P���̌ŗL���Ɋւ���", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���[�L���O�O���[�v�́A�ϐ����ӂ������͐��̌ŗL��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�Ƃ��Đ����ɏ��F�����B", left_end, IO_y + Interval_y * ver, font_size, c);

		}
		else if (page == 1)
		{
			Font::StrDraw(L"[��\���h(�ɂ��イ�͂����キ)�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�V�����A28�̃G���A(���h)�ɕs�ϓ������������́B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"��\���Ɂi�ɂ��イ�͂�����j�Ƃ������B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�V���Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�f����P�������̏�ɒ���t���^������ƍl����ꂽ", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�n���𒆐S�Ƃ��Ď�芪�����̂̂��ƁB", left_end, IO_y + Interval_y * ver, font_size, c);
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