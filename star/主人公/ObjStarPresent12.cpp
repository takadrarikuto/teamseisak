//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjStarPresent.h"
extern int lever;
extern int crick;
extern int cenge;


void CObjStarPresent::Init()
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

void CObjStarPresent::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();


}

void CObjStarPresent::Draw()
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
	Font::StrDraw(L"�A���Q�f�B", 20, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 1;
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
		}
	}

	if (crick == 1)
	{
		ver = 0;
		Font::StrDraw(L"�€���ɑ�����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"����ł��A���Q�f�B1���ƃA���Q�f�B2���ɕ����ł����d��", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"6.6�����ꂽ�A���Q�f�B1���ƃA���Q�f�B2���͘A���ł͂Ȃ�", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�������̓�d���̊֌W�ɂ���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���c�p�x�̒P�ʂƂ��Ă̕��B1�x��60����1�̊p�x�ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�A���c2�̍P�������҂̏d�S�̎�����O���^�����Ă���V��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�ł���B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��B", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"��d���c�n���ォ�猩��P�������������ɋߐڂ���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����镨���w��", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 2)
	{
		ver = 0;
		Font::StrDraw(L"�€���ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�€���ɂ���3�����̃_�r�[1����6�����̃_�r�[2������Ȃ�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�A���n�ł���B�_�r�[1����6�����̃_�r�[2���͒n�������", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"��������Ă���A�o�ዾ���g���Ηe�Ղɕ������Č��邱�Ƃ�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�ł���B�܂��A�_�r�[1���A�_�r�[2���̂��ꂼ�ꂪ", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�܂��A���n�𐬂��Ă���S�̂Ƃ��ď��Ȃ��Ƃ�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"5�ȏ�̍P������\������Ă���", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 3)
	{
		ver = 0;
		Font::StrDraw(L"�€���ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�€���̍P����4�����B�ߔN�̊ϑ����ʂ����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�X�y�N�g���^A7�̏����̋����ł͂Ȃ����ƍl�����Ă���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���]���x���x�����߁A�Η��Əd�͂̉e���ɂ���ėl�X��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�������f����C���Ɍ�����Am���ł���Ƃ��l�����Ă���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����c�����\�ʉ��x������n�񐯂������a����і��邳��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���ɑ傫���P���̂��Ƃł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"Am���c���w���ِ��ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���ِ��c���Ȃ��Ƃ����̕\�ʂɂ����āA�����ʂ̑g����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���̍P���Ƃ��Ȃ�قȂ��Ă��鐯�ł���", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 4)
	{
		ver = 0;
		Font::StrDraw(L"�€���ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�€���ōł����邢�P����3�����B�����t�߂ɂ��邽��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"����f���ɂ�鉆�����N����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����c�V����ɂ����鑾�z�̌�������̒ʂ蓹�i��~�j������", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����c����V�̂��ϑ��҂Ƒ��̓V�̂̊Ԃ�ʉ߂��邽�߂�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���̓V�̂��B����錻�ۂł���", font, size_y* ver, size, c);
		ver++;
	}
	else if (crick == 5)
	{
		ver = 0;
		Font::StrDraw(L"�€���ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�€���̍P����5�����B�n�������4.74����A����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"11.80����B���̓�d���Ɍ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�d�͓I�Ɋ֌W�̂Ȃ��������̓�d���Ǝv���邪�A�����A���n��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����Ă����ꍇ��4,000�V���P�ʈȏ㗣�ꂽ�O����14���N�|����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���񂵂Ă���ƍl������", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"��d���c�n���ォ�猩��P�������������ɋߐڂ��Č����镨��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�w��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�V���P�ʁc�����̒P�ʂŁA���m�� 149597870700 m", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�ł���", font, size_y* ver, size, c);
		ver++;
	}

}