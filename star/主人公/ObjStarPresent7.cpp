//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjStarPresent7.h"
extern int lever;
extern int crick;
extern int cenge;


void CObjStarPresent7::Init()
{

}

void CObjStarPresent7::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();


}

void CObjStarPresent7::Draw()
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
	int g = 200.0f;//���g�̉���
	int k = 75.0f;//���g�̗���
	int t = 70;//���̖��O�̈ʒu
	int l = 0;//t�Ɗ|����p�̕ϐ�
	int s = 0;//���̃N���b�N�̌�
	int std = 0;
	int side_a = 0;
	int side_b = 200;
	int size = 25;
	int  size_y = 30;
	int font = 80;

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
	Font::StrDraw(L"�J�X�g��", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"�|���b�N�X", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"�A���w�i", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"���T�g", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"���u�X�^", 20 + 220, 320 + t * l, 30, c);
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
	Font::StrDraw(L"���N�u�_", 20 + 220, 330 + t * l, 30, c);
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
	Font::StrDraw(L"�v���v�X", 20 + 220, 340 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 7;
		}
	}
	//					�@�@	  X�@        Y�@    �傫��
	Font::StrDraw(L"�e�W�F�b�g", 20 + 220, 350 + t * l, 30, c);
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
	Font::StrDraw(L"�A���Y��", 20 + 420, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 9;
		}
	}
	//					  �@�@	    X�@        Y�@    �傫��
	Font::StrDraw(L"�`�V���G�C", 20 + 420, 330 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 10;
		}
	}

	int ver;

	if (crick == 1)
	{
		ver = 0;
		Font::StrDraw(L"�ӂ������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�ӂ�������2�Ԗڂɖ��邢�P���J�X�g��A�ƃJ�X�g��B", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�J�X�g��C�̎O�d�A���ł����3�̐����ׂĂ�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"2�̐����琬��A���ł���A�ʏ��3�i6�j", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���킹��2�����Ƃ��Ĉ�����", font, size_y* ver, size, c);
	}
	else if (crick == 2)
	{
		ver = 0;
		Font::StrDraw(L"�ӂ������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�ӂ������ōł����邢�P���ŁA�S�V21��1������", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"1�~�̃_�C�������h���`������P����1�ł�����", font, size_y* ver, size, c);
	}
	else if (crick == 3)
	{
		ver = 0;
		Font::StrDraw(L"�ӂ������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�ӂ�������3�Ԗڂɖ��邢�P���O����12.6�N�̎�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���񂵂Ă���", font, size_y* ver, size, c);
	}
	else if (crick == 4)
	{
		ver = 0;
		Font::StrDraw(L"�ӂ������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���悻1,200�N�����Ď��񂵂Ă���", font, size_y* ver, size, c);
	}
	else if (crick == 5)
	{
		ver = 0;
		Font::StrDraw(L"�ӂ������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�������ŁA���ɉ��������ۂɏڍׂȊϑ���������Ă���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�������c���z���͂邩�ɑ傫�����邢�P���̂���", font, size_y* ver, size, c);
	}
	else if (crick == 6)
	{
		ver = 0;
		Font::StrDraw(L"�ӂ������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"10.15���̎�����3.62������4.18���܂ŕό�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�P�t�F�C�h�ό����̒������ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�P�t�F�C�h�ό����c�������ς�邱�Ƃ��̐��̕ό��͈͂�1�`2��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"������2�`50���قǂł���", font, size_y* ver, size, c);
	}
	else if (crick == 7)
	{
		ver = 0;
		Font::StrDraw(L"�ӂ������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���悻232.9���̎�����3.15������3.9���܂ŕό�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���K���^�ό����̋���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���K���^�ό����c�ό��͈͂͐��S���̐��������琔�����ł���", font, size_y* ver, size, c);
	}
	else if (crick == 8)
	{
		ver = 0;
		Font::StrDraw(L"�ӂ������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�P����3����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���z�ɔ��1,540�{�ȏ�̃G�l���M�[����o���Ă���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�n�����猩���ꍇ�A���̍P������5�{�ȏ�̑��x��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�ړ����Ă���悤�Ɍ�����", font, size_y* ver, size, c);
	}
	else if (crick == 9)
	{
		ver = 0;
		Font::StrDraw(L"�ӂ������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"3�����̍P���ŁA�n�������60���N���ꂽ�AF�^��n��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���邢�͏������ŁA���z��1.7�{�̎��ʂ�2.7�{�̔��a������", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�N���15���N�ƎႭ�A�����ʂ͑��z�Ƃقړ����x�Ƃ���Ă���", font, size_y* ver, size, c);
	}
	else if (crick == 10)
	{
		ver = 0;
		Font::StrDraw(L"�ӂ������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�P����5����", font, size_y* ver, size, c);
	}

}