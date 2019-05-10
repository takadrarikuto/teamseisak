//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjStarPresent2.h"
extern int lever;
extern int crick;
extern int cenge;

void CObjStarPresent2::Init()
{

}

void CObjStarPresent2::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
}

void CObjStarPresent2::Draw()
{
	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };
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
		Draw::Draw(1, &src, &dst, c, 0.0f);

		for (int l = 0; l <= 2; l++)
		{

			dst.m_top = 375.0f + k * l;
			dst.m_bottom = 450.0f + k * l;
			Draw::Draw(1, &src, &dst, c, 0.0f);
		}

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

	//�F���D�ւ̕�����`�悷��
	//					�@�@X�@Y�@�傫��
	Font::StrDraw(L"�F��", 10, 25, 25, c);
	Font::StrDraw(L"�D��", 10, 50, 25, c);

	//�߂�{�^��
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

	//���ւ̕��������[�v���ďo��
	wchar_t next[2][2]{ L"��",L"��" };
	for (int i = 0; i <= 1; i++)
	{
		int l = 25;
		swprintf_s(str, L"%s", next[i]);
		//				�@�@X�@ Y�@ �傫��
		Font::StrDraw(str, 20, 130 + l * i, 25, c);
	}
	//�߂����������StarPresent�ɐ؂�ւ���
	// left				 right            top            bottom       
	if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>190 && m_mou_y < 300)
	{
		if (m_mou_l == true)
		{
			lever = 0;
			Scene::SetScene(new CSceneStarPicbook());
		}
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
	//���ւ���������StarPresent2�ɐ؂�ւ���
	// left				 right            top            bottom       
	/*if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>100 && m_mou_y <200)
	{
		if (m_mou_l == true)
		{
			lever =1;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}*/

	page = 0;//���̃y�[�W�֍s�����߂̕ϐ�
	page_flag = false;
	ver = 0;
	g = 200.0f;//���g�̉���
	k = 75.0f;//���g�̗���
	t = 70;//���̖��O�̈ʒu
	l = 0;//t�Ɗ|����p�̕ϐ�
	s = 0;//���̃N���b�N�̌�
	std = 0;
	side_a = 0;
	side_b = 200;
	size = 25;
	size_y = 30;
	font = 80;
	fy = 200;//���̖��O�̉���
	font_size = 25;//�����̑傫��
	Interval_y = 35;//�����̗����Ԋu
	left_end = 80;//�������̍��̌��E�����߂�


	//					�@�@	    X�@ Y�@ �傫��
	Font::StrDraw(L"�A���f�o����", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"�G���i�g", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"�v���}�q�A�f�X", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"�Z�J���h�q�A�f�X", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"�A�C��", 20 + 220, 320 + t * l, 30, c);
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
	Font::StrDraw(L"�e���J��", 20 + 220, 330 + t * l, 30, c);
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
	Font::StrDraw(L"�A���L�I�l", 20 + 220, 340 + t * l, 30, c);
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
	Font::StrDraw(L"�`�����N�C", 20 + 220, 340 + t * l, 30, c);
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
	Font::StrDraw(L"�P���G�m", 20 + 220, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 9;
		}
	}
	//					�@�@	  X�@        Y�@    �傫��
	Font::StrDraw(L"�G���N�g��", 20 + 220, 330 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 10;
		}
	}
	//					  �@�@	    X�@        Y�@    �傫��
	Font::StrDraw(L"�^�C�Q�^", 20 + 220, 340 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 11;
		}
	}
	//					  �@�@	    X�@        Y�@    �傫��
	Font::StrDraw(L"�}�C�A", 20 + 220, 340 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 12;
		}
	}

	t -= 4;
	l -= 4;
	std = 3;

	//					�@�@	  X�@        Y�@    �傫��
	Font::StrDraw(L"�A�X�e���[�y", 20 + 220, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 13;
		}
	}
	//					�@�@	  X�@        Y�@    �傫��
	Font::StrDraw(L"�����[�y", 20 + 220, 330 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 14;
		}
	}
	//					  �@�@	    X�@        Y�@    �傫��
	Font::StrDraw(L"�A�g���X", 20 + 220, 340 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 15;
		}
	}
	//					  �@�@	    X�@        Y�@    �傫��
	Font::StrDraw(L"�v���C�I�l", 20 + 220, 340 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 16;
		}
	}

	if (crick == 1)
	{
		ver = 0;
		Font::StrDraw(L"���������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���������ōł����邢�P���őS�V21��1������1��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�~�̃_�C�������h���`������P����1�ł�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�ؐ��̐��{�̎��ʂ̘f��������", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�~�̃_�C�������h�c6��1���������Ɍ��ԂƑ傫�ȃ_�C�������h��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�`�ƂȂ�B������A�~�̃_�C�������h�܂��͓~�̑�Z�p�`�ƌ���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 2)
	{
		ver = 0;
		Font::StrDraw(L"���������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�A����������2�Ԗڂɖ��邢�P����2�����B���Ă͂��債����ɂ�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����ɑ����Ă����B���ِ��A���ł�����E�}���K������", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���ނ���Ă���A���z�ɂ���ׂă}���K���̊ܗL����20�{������", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�܂��J���V�E���ƃ}�O�l�V�E����8����1�ƒႢ", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���ِ��c���Ȃ��Ƃ����̕\�ʂɂ����āA�����ʂ̑g����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���̍P���Ƃ��Ȃ�قȂ��Ă��鐯�ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 3)
	{
		ver = 0;
		Font::StrDraw(L"���������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���������̍P����4�����B��d���Ƃ���Ă��邪", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����ɂ��ē��ɂ킩���Ă��邱�Ƃ͂Ȃ��B�启A��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"G9.5�`K0�̃X�y�N�g�����������ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"��d���c�n���ォ�猩��P�������������ɋߐڂ��Č����镨��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�w��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 4)
	{
		ver = 0;
		Font::StrDraw(L"���������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���������̍P����4�����B�q�A�f�X���c�̈����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�Z�J���h�q�A�f�X��1A���ƃ�1B�����������̓�d����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����Ă���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�q�A�f�X���c�c���������Ɉʒu����U�J���c�ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�U�J���c�c�P���̏W�c�i���c�j�̈��ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 5)
	{
		ver = 0;
		Font::StrDraw(L"���������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���������̕��p�Ɉʒu�����F�����ł���B", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�N���6��2500���N�Ɛ��x�ǂ��\������Ă���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"189�b���ꂽ�Ƃ���Ɍ�����11�����̍P���ƘA���ł��邩", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�������̓�d���ł��邩�͒肩�ł͂Ȃ�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�A���c2�̍P�������҂̏d�S�̎�����O���^�����Ă���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�V�̂ł���B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"��d���c�n���ォ�猩��P�������������ɋߐڂ��Č����镨��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�w��", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 6)
	{
		ver = 0;
		Font::StrDraw(L"���������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���������̍P����3�����B���z�Ɣ�ׂ�Ǝ启��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���ʂ�11�{�ȏ�A���a��5�|6�{�Ƃ�������ȍP���ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"125 km/s�ƍ����Ŏ��]���Ă���B�O��������", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�ق�113���ł���Ɛ��肳���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 7)
	{
		ver = 0;
		Font::StrDraw(L"���������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���������̍P����3�����B�v���A�f�X���c�� �ł����邢�P����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"����B���̑�����Be���Ɠ��l��215km/s�Ƒ������]���x��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����P���̉��ɃK�X�̉~�Ղ�����Ă���B���邳��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"1.13���Ԃ��Ƃ�+8.25����+8.30�܂ŕω�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�v���A�f�X���c�c���������Ɉʒu����U�J���c�ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�U�J���c�c�P���̏W�c�i���c�j�̈��ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 8)
	{
		ver = 0;
		Font::StrDraw(L"���������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���������̓�d���ł���A�q�A�f�X���c�̃����o�[�ł���B", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"5.62�����ꂽ2�̐�����\�������B�����̑��肩��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"����������1���͒n�������152���N�A����������2����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"��157���N�̋����Ɉʒu����Ɛ��肳��Ă���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"��d���c�n���ォ�猩��P�������������ɋߐڂ��Č����镨��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�w��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 9)
	{
		ver = 0;
		Font::StrDraw(L"���������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���������̍P���Ńv���A�f�X���c�ɑ�����5�����B", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�v���A�f�X���c�̒��ł͋P���̈�����A5�����ƈÂ�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"����Ō�����͓̂��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���ԕ����ɂ�錸����0.3�����قǂ���ƍl�����Ă���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���ԕ����c�P���Ԃ̉F����Ԃɕ��z����󔖕����̑��̂ł���B", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"��ʂ̐��ԕ������Ïk���āA�����\������ޗ��ɂ��Ȃ�B", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����c�ϑ��҂ɓ��B����d���g�̃G�l���M�[���ʂ����錻��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�y�т��̌����ʂ�\���w�W�̂��Ƃł���", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 10)
	{
		ver = 0;
		Font::StrDraw(L"���������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���������̍P���Ńv���A�f�X���c�ɑ�����A�F�����ł���B", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�v���A�f�X���c�̋P���̒��ł����邢���̂̈�B���̐��͌���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�������I�ɉ�������A�܂����z�n�̑��̘f���ɂ���Ă�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"����邱�Ƃ�����B���]���x��181km/s�ƍ����Ŏ��]���Ă���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����̎��]�̂��߁A�ɕt�߂͕������Ȃ�A�ԓ��͖c�����Ă���B", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�F�����c�����̂��߂ɐ�������P��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 11)
	{
		ver = 0;
		Font::StrDraw(L"���������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���������̍P���Ńv���A�f�X���c�ɑ�����4�����B", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���ɉ�������邱�Ƃ�����A���̂Ƃ��̊ϑ����ʂ���启�Ɣ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�ڍׂ��킩���Ă���B�v���A�f�X���c�̒��ł͖��邢���̂̈��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�启�Ɣ����͒n�������0.012�b����Č����A1313����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���]���Ă���B", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����c����V�̂��ϑ��҂Ƒ��̓V�̂̊Ԃ�ʉ߂��邽�߂�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���̓V�̂��B����錻�ۂł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 12)
	{
		ver = 0;
		Font::StrDraw(L"���������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���������̍P���Ńv���A�f�X���c�ɑ�����4�����B�v���A�f�X", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���c�̒��ł����邢���̂̈�B���]���x���x�����Ƃɂ��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"��C���ɐ����}���K���̋P�������������鐅��E�}���K������", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���ނ����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�v���A�f�X���c�c���������Ɉʒu����U�J���c�ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�U�J���c�c�P���̏W�c�i���c�j�̈��ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 13)
	{
		ver = 0;
		Font::StrDraw(L"���������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���������̍P���Ńv���A�f�X���c�ɑ����Ă���B", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�ŗL���A�X�e���[�y�́A�M���V���_�b�ɓo�ꂷ��v���C�A�f�X��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"��l�̖��O�Ɉ���ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�v���A�f�X���c�c���������Ɉʒu����U�J���c�ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�U�J���c�c�P���̏W�c�i���c�j�̈��ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 14)
	{
		ver = 0;
		Font::StrDraw(L"���������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���������Ɉʒu����P���Ńv���A�f�X���c�ɑ����Ă���B", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�v���A�f�X���c�̋P���̒��ł����邢���̂̈�B", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"23�Ԑ��̕��˂̉e���Ō�������Ă���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�ŗL�������[�y �́A�M���V���_�b�ɓo�ꂷ��v���C�A�f�X��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"��l�̖��O�Ɉ���ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 15)
	{
		ver = 0;
		Font::StrDraw(L"���������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���������̍P���Ńv���A�f�X���c�ɑ����Ă���B�v���A�f�X���c��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�P���̒��ł����邢���̂̈�ŎO�d���B���Ȃ��Ƃ�52au", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���ꂽ�O����150�N�ȏォ���Ď��񂵂Ă���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"au(�V���P��)�c�����̒P�ʂ�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���m�� 149597870700 m�ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�O�d��(���d��)�c�n�����猩��Ƌߐڂ����ʒu�Ɍ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"3�ȏ�̍P���ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 16)
	{
		ver = 0;
		Font::StrDraw(L"���������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���������̍P���Ńv���A�f�X���c�ɑ����B�v���A�f�X���c��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���ł͋P���̈�����A��������5.09�ƈÂ��A�܂��߂���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"��4�{���邢��������27�Ԑ��������邽�߂ɗ���Ō�����̂�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�v���A�f�X���c�c���������Ɉʒu����U�J���c�ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�U�J���c�c�P���̏W�c�i���c�j�̈��ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
		ver++;
	}


}