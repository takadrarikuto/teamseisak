//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameL\Audio.h"
#include "GameHead.h"
#include "ObjStarPresent12.h"
extern int lever;
extern int crick;
extern int cenge;


void CObjStarPresent12::Init()
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
	pagex = 530; //�y�[�W���Wx
	pagey = 5; //�y�[�W���Wy
	pagesize = 18; //�y�[�W�T�C�Y

	a_time = 0;
	time_flag = false;
	m_mou_time = 0.0f;

	Back_time = 0.0f;
	Spaceship_back = false;

	Audio::LoadAudio(1, L"���ʉ�.wav", EFFECT);
}

void CObjStarPresent12::Action()
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
		time_flag = false;
		if (a_time > 1)
		{
			a_time++;
		}
		else
		{
			a_time = 0;
		}
	}

	//SE��������
	if (time_flag == true)
	{
		a_time++;
	}
	else if (time_flag == false)
	{
		a_time = 0;
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
		Spaceship_back = true;
		if (m_mou_l == true)
		{
			time_flag = true;
		}
	}
	else
	{
		Spaceship_back = false;
	}
	//���������Ɩ߂�
	if (Input::GetVKey('B') == true && Back_time > 60.0f)
	{
		lever = 0;
		a_time = 0;
		Back_time = 0.0f;
		time_flag = false;
		Scene::SetScene(new CSceneStarPicbook());
	}

	if (Spaceship_back == true)
	{
		if (a_time >= 8)
		{
			lever = 0;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}

}

void CObjStarPresent12::Draw()
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
	Font::StrDraw(L"�A���Q�f�B", 20, 320 + t * l, 30, c);
	l++;

	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 1;
			page = 0; //�y�[�W������
		}
	}
	

	//					�@�@	    X�@ Y�@ �傫��
	Font::StrDraw(L"�_�r�[", 20, 325 + t * l, 30, c);
	l++;

	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 2;
			page = 0; //�y�[�W������
		}
	}
	

	//					�@�@	    X�@        Y�@    �傫��
	Font::StrDraw(L"�i�V��", 20, 330 + t * l, 30, c);
	l++;

	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 3;
			page = 0; //�y�[�W������
		}
	}
	
	//					�@�@	  X�@        Y�@    �傫��
	Font::StrDraw(L"�f�l�u�E�A���Q�f�B", 18, 340 + t * l, 20, c);
	l++;

	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 4;
			page = 0; //�y�[�W������
		}
	}
	

	t -= 4;
	l -= 4;
	std = 1;

	//					�@�@	  X�@        Y�@    �傫��
	Font::StrDraw(L"�A���V���g", 20 + 200, 320 + t * l, 30, c);
	l++;

	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 5;
			page = 0; //�y�[�W������
		}
	}
	

	if (crick == 1)
	{
		page_max = 2; //�ő�y�[�W��
		ver = VER_start; //�����Ԋu������

		//�y�[�W���\��
		swprintf_s(strp, L"���݃y�[�W��%d/�ő�y�[�W��%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"�€���ɑ�����3�Ԗڂɖ��邢�P����4�����B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"����ł��A���Q�f�B1���ƃA���Q�f�B2���ɕ����ł����d���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"6.6�����ꂽ�A���Q�f�B1���ƃA���Q�f�B2���͘A���ł͂Ȃ�", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�������̓�d���̊֌W�ɂ���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�p�x�̒P�ʂƂ��Ă̕��Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"1�x��60����1�̊p�x�ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[�A���Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2�ȏ�̍P�������҂̏d�S�̎�����O���^�����Ă���V��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ł���B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[��d���Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
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
		page_max = 2; //�ő�y�[�W��
		ver = VER_start; //�����Ԋu������

		//�y�[�W���\��
		swprintf_s(strp, L"���݃y�[�W��%d/�ő�y�[�W��%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"�€���ɑ�����3�����̃_�r�[1����6�����̃_�r�[2��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"����Ȃ�A���n�ł���B�_�r�[1����6�����̃_�r�[2����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�n������͏�������Ă���A�o�ዾ���g���Ηe�Ղɕ�������", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���邱�Ƃ��ł���B�܂��A�_�r�[1���A�_�r�[2���̂��ꂼ�ꂪ", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�܂��A���n�𐬂��Ă���S�̂Ƃ��ď��Ȃ��Ƃ�5�ȏ�̍P��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"����\������Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
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
	else if (crick == 3)
	{
		page_max = 3; //�ő�y�[�W��
		ver = VER_start; //�����Ԋu������

		//�y�[�W���\��
		swprintf_s(strp, L"���݃y�[�W��%d/�ő�y�[�W��%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"�€���ɑ�����P����4�����B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"F0�̃X�y�N�g��������n�񐯂ƍl�����Ă������A�ߔN��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ϑ����ʂ���̓X�y�N�g���^A7�̏����̋����ł͂Ȃ�����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�l�����Ă���B���]���x���x�����߁A�Η��Əd�͂�", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�e���ɂ���ėl�X�ȋ������f����C���Ɍ�����Am����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"����Ƃ��l�����Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[Am��(���[���ނ���)�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�X�y�N�g���^A�̉��w���ِ��ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
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
			Font::StrDraw(L"[�X�y�N�g�����ނƂ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�P���̕��ޖ@�̈�B�X�y�N�g�����ނɂ���čו����ꂽ����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�^�C�v���X�y�N�g���^�ƌĂԁB�P��������˂��ꂽ�d���g��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����A�X�y�N�g�����ώ@���邱�Ƃɂ���ĕ��ނ���B", left_end, IO_y + Interval_y * ver, font_size, c);
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
		swprintf_s(strp, L"���݃y�[�W��%d/�ő�y�[�W��%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"�€���ɑ�����ł����邢�P����3�����B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����t�߂ɂ��邽�ߌ���f���ɂ�鉆�����N����B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�€�����́A4�̍P������Ȃ�P���n�ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"2017�N2��1���ɍ��ۓV���w�A���̍P���̖����Ɋւ���", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���[�L���O�O���[�v(WGSN)�́A�f�l�u�E�A���Q�f�B��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�€����Aa�̌ŗL���Ƃ��Đ����ɏ��F�����B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[����(�����ǂ�)�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�V����ɂ����鑾�z�̌�������̒ʂ蓹�i��~�j�������B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[����(����؂�)�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"����V�̂��ϑ��҂Ƒ��̓V�̂̊Ԃ�ʉ߂��邽�߂ɂ��̓V�̂�", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�B����錻�ۂł���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�P���n(������������)]�Ƃ�", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���̍P�����d�͂Ō��т��Ă��݂��̎�������]���Ă���", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���n�ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
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
		swprintf_s(strp, L"���݃y�[�W��%d/�ő�y�[�W��%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		if (page == 0)
		{
			Font::StrDraw(L"�€���ɑ�����P����5�����B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�n�������4.74����A����11.80����B���̓�d����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"������B�d�͓I�Ɋ֌W�̂Ȃ��������̓�d���Ǝv���邪", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����A���n�𐬂��Ă����ꍇ��4,000�V���P�ʈȏ㗣�ꂽ", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�O����14���N�|���Ď��񂵂Ă���ƍl������B", left_end, IO_y + Interval_y * ver, font_size, c);
		}
		else if (page == 1)
		{
			Font::StrDraw(L"[��d���Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�n���ォ�猩��P�������������ɋߐڂ��Č����镨���w���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�V���P��(�Ă���񂽂�)�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����̒P�ʂŁA���m�� 149597870700 m�ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
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