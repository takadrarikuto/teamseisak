//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjStarPresent4.h"
extern int lever;
extern int crick;
extern int cenge;


void CObjStarPresent4::Init()
{
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

}

void CObjStarPresent4::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();


}

void CObjStarPresent4::Draw()
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

	//					�@�@	    X�@ Y�@ �傫��
	Font::StrDraw(L"�T�_�������N", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"�T�_���X�E�h", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"�T�_�N�r�A", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"�X�J�g��", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"�A���o��", 20 + 220, 320 + t * l, 30, c);
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
	Font::StrDraw(L"�A���J", 20 + 220, 330 + t * l, 30, c);
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
	Font::StrDraw(L"�V���`����", 20 + 220, 340 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 7;
		}
	}

	if (crick == 1)
	{
		ver = 0;
		Font::StrDraw(L"�݂����ߍ��ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�݂����ߍ���2�Ԗڂɖ��邢�P��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�قړV�̐ԓ���ɂ���", font, size_y* ver, size, c);
	}
	else if (crick == 2)
	{
		ver = 0;
		Font::StrDraw(L"�݂����ߍ��ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�݂����ߍ��ōł����邢�P��", font, size_y* ver, size, c);
	}
	else if (crick == 3)
	{
		ver = 0;
		Font::StrDraw(L"�݂����ߍ��ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�P����4�����AA�^��n�񐯂̎启�̎����58���̎�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����Ă���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"A�^��n�񐯁c���f��R�₵�ĔR�����n�񐯂ł���", font, size_y* ver, size, c);
	}
	else if (crick == 4)
	{
		ver = 0;
		Font::StrDraw(L"�݂����ߍ��ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�݂����ߍ���3�Ԗڂɖ��邢�P��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�������܍��^�����c�̐��̈�ƍl�����Ă���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�������܍��^�����c�c�n���̍ł��߂��ɂ���^�����c�ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���c�c���݂��̏d�͂ɂ���Đ��܂ꂽ�P���̏W�c", font, size_y* ver, size, c);
	}
	else if (crick == 5)
	{
		ver = 0;
		Font::StrDraw(L"�݂����ߍ��ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�P����4�����ό��A���w�g���A�f���͔�������Ă��Ȃ��Ȃ�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�s�m���ȓ_������", font, size_y* ver, size, c);
	}
	else if (crick == 6)
	{
		ver = 0;
		Font::StrDraw(L"�݂����ߍ��ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�P����4�����A�����͔��F�␯�ɂȂ�Ɨ\������Ă���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���F�␯(�͂����傭�킢����)�c�P�����i���̏I�����ɂƂ肤��`�Ԃ̈��", font, size_y* ver, size, c);
	}
	else if (crick == 7)
	{
		ver = 0;
		Font::StrDraw(L"�݂����ߍ��ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�P����5�����A�X�y�N�g������K�^�̋���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�X�y�N�g�����ށc�P���̕��ޖ@�̈��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����c���a����і��邳�����ɑ傫���P��", font, size_y* ver, size, c);
	}

}