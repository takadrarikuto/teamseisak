//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjStarPresent10.h"
extern int lever;
extern int crick;
extern int cenge;


void CObjStarPresent10::Init()
{

}

void CObjStarPresent10::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();


}

void CObjStarPresent10::Draw()
{
	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu
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
	int g = 200.0f;//���g�̉���
	int k = 75.0f;//���g�̗���
	int t = 70;//���̖��O�̈ʒu
	int l = 0;//t�Ɗ|����p�̕ϐ�
	int s = 0;//���̃N���b�N�̌�
	int std = 0;
	int side_a = 0;
	int side_b = 200;
	int size = 25;
	int size_y = 30;
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

	//�������̔w�i������`��
	dst.m_top = 0.0f;
	dst.m_left = 67.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 300.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);

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
	Font::StrDraw(L"�X�s�J", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"�T���B�����@", 20, 330 + t * l, 30, c);
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
	Font::StrDraw(L"�|���}", 20, 330 + t * l, 30, c);
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
	Font::StrDraw(L"�~�l���E�o", 20, 330 + t * l, 30, c);
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
	Font::StrDraw(L"���B���f�~�A�g���b�N�X", 20 + 180, 330 + t * l, 18, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 5;
		}
	}
	//					�@�@	  X�@        Y�@    �傫��
	Font::StrDraw(L"�U�j�A", 20 + 220, 330 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 6;
		}
	}
	//					  �@�@	    X�@        Y�@    �傫��
	Font::StrDraw(L"�V�����}", 20 + 220, 340 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 7;
		}
	}
	Font::StrDraw(L"�J���O", 20 + 220, 340 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
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
	Font::StrDraw(L"�J���{���A", 20 + 400, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 9;
		}
	}
	//					�@�@	  X�@        Y�@    �傫��
	Font::StrDraw(L"�G���K���t�@", 20 + 400, 330 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
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
		Font::StrDraw(L"���Ƃߍ��ɑ�����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���Ƃߍ��ōł����邢�P���őS�V21��1������1�B�t�̖��", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�����P���B����B�^�̃X�y�N�g��������0.98����10.5����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�P������Ȃ�A���n�ł���B0.17���̎�����0.015���ό�", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���Ă���", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�A���c2�̍P�������҂̏d�S�̎�����O���^�����Ă���V�̂�", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"����B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�ό��c���邳�i�����j���ω�������̂̂��Ƃł���", font, size_y * ver, size, c);
	}
	else if (crick == 2)
	{
		ver = 0;
		Font::StrDraw(L"���Ƃߍ��ɑ�����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���Ƃߍ��̕��p�ɂ���P����4�����B���z�����傫��", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�d���A��r�I�����ʂɕx��ł��鉩���ɂ��Ȃ�߂��ʒu��", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���邽�߁A���⎞�ɂ͘f���ɂ�鉆�����ϑ������", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�����c�V����ɂ����鑾�z�̌�������̒ʂ蓹�i��~�j������", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�����c����V�̂��ϑ��҂Ƒ��̓V�̂̊Ԃ�ʉ߂��邽�߂�", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���̓V�̂��B����錻�ۂł���", font, size_y * ver, size, c);
	}
	else if (crick == 3)
	{
		ver = 0;
		Font::StrDraw(L"���Ƃߍ��ɑ�����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���Ƃߍ��ɂ���3�����̘A���ł���BF�^��n�񐯓��m����Ȃ�", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�A���ł���B�����͎启�̎����168.93�N�Ō��]���Ă���", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"F�^��n�񐯁c�X�y�N�g���^��F�A���x�K����V�̐��f��", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�R�₵�ĔR�����n�񐯂ł���", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�A���c2�̍P�������҂̏d�S�̎�����O���^�����Ă���V�̂�", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"����B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��", font, size_y * ver, size, c);
	}
	else if (crick == 4)
	{
		ver = 0;
		Font::StrDraw(L"���Ƃߍ��ɑ�����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���Ƃߍ��̍P����3�����B���̐��͐ԐF�������� (RGB) ��", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�i�K�ɂ���B�n������ϑ�����80�b���ꂽ�ʒu�Ɍ�����11����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�͔����̉\��������Ƃ����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�ԐF�����c�P������n�񐯂��I�������Ƃ̐i���i�K�ł���", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"��C���c�����A���̑傫���͒n���̌��]�O�����a����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�ΐ��̂���ɑ�������", font, size_y * ver, size, c);
	}
	else if (crick == 5)
	{
		ver = 0;
		Font::StrDraw(L"���Ƃߍ��ɑ�����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���Ƃߍ��̍P���ł���B3�����̉��F�����ŁA���Ƃߍ��ł�", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�����̃X�s�J�A�����̃|���}�Ɏ����Ŗ��邢�N��0.2�b�Ƃ���", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�����ňړ����Č�����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�����c�����\�ʉ��x������n�񐯂������a����і��邳��", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���ɑ傫���P���̂��Ƃł��鋐���̔��a�͑��z��10�{����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"100�{�A���邳��10�{����1000�{�ł���", font, size_y * ver, size, c);
	}
	else if (crick == 6)
	{
		ver = 0;
		Font::StrDraw(L"���Ƃߍ��ɑ�����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�P����4�����B�����A���ŁA3�̐����琬��A���n�ł����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�l�����Ă���B������1�́A���ϖ�10au���ꂽ�O����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"13.12�N���|���Ď��񂵂Ă���B����Ɏ启�ɂ͖�0.5au��", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�O����72���̎����ŉ�锺��������ƌ�����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"au�c�V���P�ʂƌ����A�����̒P�ʂŁA���m�� 149597870700 m ", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�ł���B��Ƃ��ēV���w�ŗp�����A��Ƃ��Ēn���Ƒ��z��", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�����̋ߎ��l�͖�1 au�ł���Əq�ׂ邱�Ƃ��ł���", font, size_y * ver, size, c);
	}
	else if (crick == 7)
	{
		ver = 0;
		Font::StrDraw(L"���Ƃߍ��ɑ�����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���Ƃߍ��̕��p�ɂ���P����4�����B", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"2010�N�Ɏ��͂�55�N�Ō��]���锺���𔭌������Ƃ���", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�������ʂ����\���ꂽ�B�����̒��ڌ��o�ɂ͐������Ă��Ȃ���", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���z��0.6�{�̎��ʂ�����n�񐯂����F�␯�ł����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�l�����Ă���", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"��n�񐯁c�P���̗L�����x�Ɩ��邳���������}�ł���w���c�V��", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L" �v�����O�E���b�Z���}(HR�}) ��Ŗ��邭��������Â��ቷ��", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���т���ł����n��Ɉʒu����P���������B�␯�Ƃ�����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���F�␯�c�P�����i���̏I�����ɂƂ肤��`�Ԃ̈��", font, size_y * ver, size, c);
	}
	else if (crick == 8)
	{
		ver = 0;
		Font::StrDraw(L"���Ƃߍ��ɑ�����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���Ƃߍ��̍P����4�����B�����̓�\���h�̂P��", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�u�� (Kang)�v�̋����Ƃ����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"��\���h�i�ɂ��イ�͂����キ�j�c�V�����A28�̃G���A�i���h�j", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�ɕs�ϓ������������́B��\���Ɂi�ɂ��イ�͂�����j�Ƃ�����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���h�i�������キ�j�c�V����̓V�̐ԓ��t�߁i�{���͌���", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�ʂ蓹�ł��锒���j��27�Ȃ���28�̃G���A�ɕ�����������", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"��������u���̏h��v���Ӗ����邪���{�⒆���ł�", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"��ʂɐ��h�ƌĂ�ł���B���h�͐��E�e�n�Ɍ�����", font, size_y * ver, size, c);
	}
	else if (crick == 9)
	{
		ver = 0;
		Font::StrDraw(L"���Ƃߍ��ɑ�����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���Ƃߍ��̍P����5�����B5.00���̎启��5.63���̔����ɂ��", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�����A���ł���", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�����A���i�Ԃ񂱂���񂹂��j�c�]�������g�p���Ă�", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�����ł��Ȃ��Ƃ������I�ȃX�y�N�g�����̈ړ���", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�p���X�����̕ϓ��ȂǃX�y�N�g���̓����̎����I�ȕω���", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�����2�ȏ�̓V�̂���Ȃ邱�Ƃ����o�ł���A���̂���", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�A���c2�̍P�������҂̏d�S�̎�����O���^�����Ă���V�̂�", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"����B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��", font, size_y * ver, size, c);
	}
	else if (crick == 10)
	{
		ver = 0;
		Font::StrDraw(L"���Ƃߍ��ɑ�����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���Ƃߍ��̍P����5�����B4.92���̉��F�����܂��͏�������A����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"10.02���̞�F�␯��B������Ȃ�A���n��A�����g��", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�����A���ł���\������������Ă���", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�����c�����\�ʉ��x������n�񐯂������a����і��邳��", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���ɑ傫���P���̂��Ƃł���", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�������c�����X�y�N�g���^�̒ʏ�̎�n�񐯂���▾�邭", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�����قǂ͖��邭�Ȃ��P���̕��ނ�1�ł���", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�A���c2�̍P�������҂̏d�S�̎�����O���^�����Ă���V�̂�", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"����B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��", font, size_y * ver, size, c);
	}
}
