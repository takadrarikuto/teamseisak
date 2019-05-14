//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjStarPresent9.h"
extern int lever;
extern int crick;
extern int cenge;


void CObjStarPresent9::Init()
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

void CObjStarPresent9::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();


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
	Font::StrDraw(L"���O���X", 20, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 1;
		}
	}

	//					�@�@	    X�@ Y�@ �傫��
	Font::StrDraw(L"�f�l�{��", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"�A���M�G�o", 20, 330 + t * l, 30, c);
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
	Font::StrDraw(L"�]�X�}", 20, 340 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 4;
		}
	}

	t -= 4;
	l -= 4;
	std = 1;

	//					�@�@	  X�@        Y�@    �傫��
	Font::StrDraw(L"�A�_�t�F��", 20 + 220, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 5;
		}
	}
	//					�@�@	  X�@        Y�@    �傫��
	Font::StrDraw(L"�V�F���^��", 20 + 220, 330 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 6;
		}
	}
	//					  �@�@	    X�@        Y�@    �傫��
	Font::StrDraw(L"�A���e���t", 20 + 220, 340 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 7;
		}
	}
	//					  �@�@	    X�@        Y�@    �傫��
	Font::StrDraw(L"���T���X", 20 + 220, 340 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 8;
		}
	}

	t -= 4;
	l -= 4;
	std = 2;

	//					�@�@	  X�@        Y�@    �傫��
	Font::StrDraw(L"�X�[�o�[", 20 + 400, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 9;
		}
	}


	if (crick == 1)
	{
		ver = 0;
		Font::StrDraw(L"�������ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�������ōł����邢�P���őS�V21��1������1�B1�����̒��ł�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�ł��Â��قډ�����ɂ���A�q�C�ʒu�̌v���̊�ƂȂ�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"��p�P���ƂȂ��Ă���4�̐����e2�̃y�A�ɂȂ��Č݂���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"����Ă��鑽�d�A���ł���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�����c�V����ɂ����鑾�z�̌�������̒ʂ蓹�i��~�j������", left_end, IO_y + Interval_y * ver, font_size, c);
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
		Font::StrDraw(L"�������̍P����2�����B�����������̃A�[�N�g�D���X��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���Ƃߍ��̃X�s�J�ƂŁA�t�̑�O�p�`���`�����锒�F��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"��n�񐯁B���č��^�ό����ł���A�ό��͈͂�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�����킸���Ȃ̂Ŋᎋ�ϑ��ł͕ό��͂킩��Ȃ�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"��n�񐯁c�P���̗L�����x�Ɩ��邳���������}�ł��鍶�㉄�т�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���ł���w���c�V���v�����O�E���b�Z���} (HR�}) ���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���邭��������Â��ቷ�Ɏ�n��Ɉʒu����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�P���������B�␯�Ƃ�����", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 3)
	{
		ver = 0;
		Font::StrDraw(L"�������ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�������̍P���ɂ���2�����ł���B��F�̋����ł���启��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���F�����̔�������Ȃ�����A���ł��肻�̔������Ə��K�͂�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�V�̖]�����ł���y�Ɋϑ��ł��邱�Ƃ���V���Ƃ����ɂ�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�l�C�̍����P���ł���B�܂������������Q�̕��˓_��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�߂����Ƃł��m����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�����A���c��d���̐����邤���̈�B�]�����ŗ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�������Ċϑ����ꗼ�������]�^�����Ă��鎖��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�m�F����Ă���A��������", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 4)
	{
		ver = 0;
		Font::StrDraw(L"�������ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�������̍P����3�����B���F�̋P�����ŁA���z�����኱", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�傫���č����ł��邩�Ȃ�ǂ���������Ă���A�N���傫����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���Ă͔�r�I���m�ɑ��肳��Ă��鑾�z����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�傫�Ȏ��ʂ����������͒Z����F�̋������ԐF�����ɂȂ�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�Â��ɔ��F�␯�ɂȂ�ƍl�����Ă���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�P�����c�ɂ߂Ė��邢�����ɕ��ނ����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�ԐF�����c����Ŋώ@����ƐԂ������邱�Ƃ���u�ԐF�v������", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�Ă΂��B�@���F�␯(�͂����傭�킢����)�c�P����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�i���̏I�����ɂƂ肤��`�Ԃ̈��", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 5)
	{
		ver = 0;
		Font::StrDraw(L"�������ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�������̍P����3�����B������F�^�̋����ŁA���S�j�ł�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���f�̊j�Z���͊��ɏI���w���E���̊j�����k���Ă���i�K��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"����B�������ꂽ�ʒu�ɂ��邵����35�Ԑ��Ƃ͌������̓�d����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�֌W�ɂ���A�A���ł͂Ȃ�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"��d���c�n���ォ�猩��P�������������ɋߐڂ��Č����镨��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�w��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�A���c2�̍P�������҂̏d�S�̎�����O���^�����Ă���V�̂�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"����B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 6)
	{
		ver = 0;
		Font::StrDraw(L"�������ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�������̍P����3�����BA�^�X�y�N�g���̎�n�񐯂��珀������", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���ނ����B���悻4500���N�O�ɒa�������Ƃ��ɂ�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"B8�^�̎�n�񐯂ł��菫���͎��ʂ̑傫�Ȕ��F�␯��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�Ȃ���̂ƍl�����Ă���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"��n�񐯁c�P���̗L�����x�Ɩ��邳���������}�ł���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�w���c�V���v�����O�E���b�Z���} (HR�}) ��ŁA", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���邭��������Â��ቷ�ɉ��т���ł����n���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�ʒu����P���������B�␯�Ƃ�����", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 7)
	{
		ver = 0;
		Font::StrDraw(L"�������ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�������̍P����4�����B���������̃A���f�o������", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�悭���ʂ��Ă����Γ����ł͂킸���ɂ��̐��̂ق���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���邢���n������̋����������Ɖ�������25�{�قǈÂ�������", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�₪�ă~���̂悤�Ȓ������̕ό����ƂȂ�ƍl�����Ă���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�~���c�����ł����k��������ɖ��邳���ɑ�ƂȂ鐫��������", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�ό����c�V�̂̈��ŁA���邳�i�����j���ω�������̂̂���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"����", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 8)
	{
		ver = 0;
		Font::StrDraw(L"�������ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�������̍P����4�����BK�^�̋��������A�܂����S�j�ł�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�w���E���̊j�Z�����n�܂��Ă��炸�j�����k���Ă���i�K�ł���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�ƍl�����Ă���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"5,000���N��ɂ̓w���E���̊j�Z�����n�܂�A���݂��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"10�{����20�{�͌��x���������̂Ɨ\������Ă���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"��358�������Č��]���Ă���", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 9)
	{
		ver = 0;
		Font::StrDraw(L"�������ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�������̍P����4�����BF�^�̃X�y�N�g������������", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"A�^��n�񐯂��A���n�𐬂��Ă��邪�A�启�Ɣ����̕��ϋ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"��ϋ߂����ߕ����@�܂��̓X�y�b�N�����@�ł���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�ϑ��ł��Ă��Ȃ�2�̐��́A14.498���̎����ŋ��ʏd�S��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�݂��ɏ����Ă���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"A�^��n�񐯁c�X�y�N�g���^��A�A���x�K����V��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���f��R�₵�ĔR�����n�񐯂ł���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�A���c2�̍P�������҂̏d�S�̎�����O���^�����Ă���V�̂�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"����B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��", left_end, IO_y + Interval_y * ver, font_size, c);
	}


}