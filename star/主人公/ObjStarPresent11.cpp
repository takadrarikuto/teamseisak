//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjStarPresent11.h"
extern int lever;
extern int crick;
extern int cenge;


void CObjStarPresent11::Init()
{

}

void CObjStarPresent11::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();


}

void CObjStarPresent11::Draw()
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
	Font::StrDraw(L"���N�o�g", 20, 320 + t * l, 30, c);
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
	Font::StrDraw(L"�A���J�u�E�v���I��", 17, 330 + t * l, 18, c);
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
	Font::StrDraw(L"�A���J�u�E�|�X�e���I��", 3, 340 + t * l, 18, c);
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
	Font::StrDraw(L"�A���i�X��", 20, 335 + t * l, 30, c);
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
	Font::StrDraw(L"�J�E�X�E���f�B�A", 10 + 220, 330 + t * l, 18, c);
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
	Font::StrDraw(L"�J�E�X�E�A�E�X�g�����X", 20 + 180, 335 + t * l, 18, c);
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
	Font::StrDraw(L"�A�X�P��", 20 + 220, 340 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 7;
		}
	}
	Font::StrDraw(L"�J�E�X�E�{���A���X", 20 + 200, 355 + t * l, 18, c);
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
	Font::StrDraw(L"�|���X", 20 + 400, 320 + t * l, 30, c);
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
	Font::StrDraw(L"�A�C���E�A���E���[�~�[", 1 + 400, 340 + t * l, 18, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 10;
		}
	}
	//					  �@�@	    X�@        Y�@    �傫��
	Font::StrDraw(L"�A���o���_", 20 + 400, 350 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 11;
		}
	}
	Font::StrDraw(L"�k���L", 20 + 400, 360 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
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
	Font::StrDraw(L"�e���r����", 20 + 600, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 13;
		}
	}


	int ver;
	if (crick == 1)
	{
		ver = 0;
		Font::StrDraw(L"���č��ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���č���4�����B���č��̐��̒��ł�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"16�Ԗڂ̖��邳�ł��葼�̐����Ō�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�K��������͑傫���O��Ă���悤�Ɍ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
	}
	else if (crick == 2)
	{
		ver = 0;
		Font::StrDraw(L"���č��ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���č��̍P����4�����B�A���J�u�E�|�X�e���I���Ƃ͌�������", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"��d���̊֌W�������̍P�����̂�B�^��n�񐯂�4�����̎启A��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"F�^��n�񐯂�7�����̔���B����Ȃ�A���ł���B��d���c", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�n���ォ�猩��P�������������ɋߐڂ��Č����镨���w��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"B�^��n�񐯁c�X�y�N�g���^��B�A���x�K����V�̐��f�̊j�Z����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�R�����n�񐯂ł���BF�^��n�񐯁c�X�y�N�g���^��F", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���x�K����V�̐��f��R�₵�ĔR�����n�񐯂ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�A���c2�̍P�������҂̏d�S�̎�����O���^�����Ă���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�V�̂ł���B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��", font, size_y* ver, size, c);
	}
	else if (crick == 3)
	{
		ver = 0;
		Font::StrDraw(L"���č��ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���č��̍P����4�����B�A���J�u�E�v���I���Ƃ͌�������", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"��d���̊֌W�ŁA�A���ł͂Ȃ��BF�^��n�񐯂Ő��f�̊j�Z����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�I���ď������ɂȂ낤���Ƃ����i�K�ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"��d���c�n���ォ�猩��P�������������ɋߐڂ���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����镨���w��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�A���c2�̍P�������҂̏d�S�̎�����O���^�����Ă���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�V�̂ł���B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�������c�����X�y�N�g���^�̒ʏ�̎�n�񐯂���▾�邭", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����قǂ͖��邭�Ȃ��P���̕��ނ�1�ł���", font, size_y* ver, size, c);
	}
	else if (crick == 4)
	{
		ver = 0;
		Font::StrDraw(L"���č��ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���č��̍P����3�����BK�^�̋����Ŋ��ɒ��S�j�ł�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���f�̊j�Z�����I���ăw���E���̊j�Z�����i��ł���i�K�ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����@�ɂ��ϑ����ʂ��町���̑��݂���������Ă��邪", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�ڂ������Ƃ͉����킩���Ă��Ȃ�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����c�����\�ʉ��x������n�񐯂���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���a����і��邳�����ɑ傫���P���̂��Ƃł���", font, size_y* ver, size, c);
	}
	else if (crick == 5)
	{
		ver = 0;
		Font::StrDraw(L"���č��ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���č��̍P����3�����B���ԕ������ǂ̒��x���邩", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�킩���Ă��Ȃ����ߕs�m���ł͂��邪�ϑ�����Ă������", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���x��30%���a��15%�قǑ傫�����̂ƍl�����Ă���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���ԕ����c�P���Ԃ̉F����Ԃɕ��z����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�󔖕����̑��̂ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
	}
	else if (crick == 6)
	{
		ver = 0;
		Font::StrDraw(L"���č��ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���č��ōł����邢�P����2�����BB�^�̃X�y�N�g������������", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���ނ���Ă��邪A�^�̋P�����Ƃ���邱�Ƃ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���݂ł͑��z��70�{�ȏ�Ƃ������]���x�ɂ��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�K�X�k���ł���ƍl�����Ă���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�P�����c�ɂ߂Ė��邢�����ɕ��ނ����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����c�����\�ʉ��x������n�񐯂������a����і��邳��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���ɑ傫���P���̂��Ƃł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�K�X�k���c�ԓ����͂ɃK�X�̉~�Ղ������Ƃ��������P��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�ł���", font, size_y* ver, size, c);
	}
	else if (crick == 7)
	{
		ver = 0;
		Font::StrDraw(L"���č��ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���č���3�Ԗڂɖ��邢�P����3�����B+3.26������A2�^������", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"+3.47������A4�^����������\�������A���n��2�̐���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���ϋ���13.4au�̋O����21.075�N�̎����Ō݂������񂵂Ă���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"100�N�]��̌ŗL�^���̊ϑ����ʂ��猩�����̓�d���ł����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�l�����Ă���B�����c�����\�ʉ��x������n�񐯂���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���a����і��邳�����ɑ傫���P���̂��Ƃł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�������c�����X�y�N�g���^�̒ʏ�̎�n�񐯂���▾�邭", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����قǂ͖��邭�Ȃ��P���̕��ނ�1�ł���B��d���c", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�n���ォ�猩��P�������������ɋߐڂ��Č����镨���w��", font, size_y* ver, size, c);
	}
	else if (crick == 8)
	{
		ver = 0;
		Font::StrDraw(L"���č��ɑ�����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���č��̍P����3�����B�����郌�b�h�N�����v�ɕ��ނ����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�������Œ��S�j�ł̓w���E������_�f��Y�f�̊j�Z����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�i��ł���B", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���b�h�N�����v�c�����ʂ������P���̐i���̒i�K�Ɍ����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�\�ʉ��x��������n�񐯂Ɣ�ׂČ��x���傫��", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�������c�����X�y�N�g���^�̒ʏ�̎�n�񐯂���▾�邭", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����قǂ͖��邭�Ȃ��P���̕��ނ�1�ł���", font, size_y* ver, size, c);
	}
	else if (crick == 9)
	{
		ver = 0;
		Font::StrDraw(L"���č��ɑ�����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���č���4�����B��l�Z���̕��̒[�Ɉʒu����B�܏d����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���̂���4�̍P���͎��ۂɘA���n�𐬂��Ă���", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���z�n����̋����͂��悻3,600���N�ƂȂ�", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�l�d���n�͏d�͓I�ɕs����Ȃ���", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�������1��2���e���o�������̂ƍl�����Ă���", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�A���c2�̍P�������҂̏d�S�̎�����O���^�����Ă���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�V�̂ł���B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��", font, size_y* ver, size, c);
	}
	else if (crick == 10)
	{
		ver = 0;
		Font::StrDraw(L"���č��ɑ�����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���č���5�����B�u�e�B�[�X�v�[���v�ƌĂ΂��A�X�e���Y����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�ꕔ�𐬂��B", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�A�X�e���Y�����邢�͐��Q�c�����̍P�����V�����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�`���p�^�[���ł���B�����̐��̕��ѓ��l", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�n������̋����͓����Ƃ͌��炸�A��ԓI�ɂ�", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�܂Ƃ܂��Ă��Ȃ�", font, size_y * ver, size, c);
	}
	else if (crick == 11)
	{
		ver = 0;
		Font::StrDraw(L"���č��ɑ�����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���č��̍P���n�ł���B3�̍P������Ȃ�A���n��", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�����ʂɋ߂����߁A���č��ΐ��͌��A�����܂��", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�f���ɂ�鉆�����ϑ������", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�����c�V����ɂ����鑾�z�̌�������̒ʂ蓹�i��~�j������", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�V���c�n���𒆐S�Ƃ��Ď�芪�����̂̂���", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�����c����V�̂��ϑ��҂Ƒ��̓V�̂̊Ԃ�ʉ߂��邽�߂�", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���̓V�̂��B����錻�ۂł���", font, size_y* ver, size, c);
	}
	else if (crick == 12)
	{
		ver = 0;
		Font::StrDraw(L"���č��ɑ�����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���č���2�Ԗڂɖ��邢�P����2�����B��l�Z������鐯��1��", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���z��7�{���̎��ʂ������߁A���S�j�ł̊j�Z���������i��", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�a�����炨�悻5000���N�قǂŎ������}���邾�낤�Ɛ��������", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���̂Ƃ��ɂ́A���z�Ɠ������x�̎��ʂ������F�␯��", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�Ȃ邾�낤�ƍl�����Ă���", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���F�␯�c�P�����i���̏I�����ɂƂ肤��`�Ԃ̈��", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"", font, size_y* ver, size, c);
	}
	else if (crick == 13)
	{
		ver = 0;
		Font::StrDraw(L"���č��ɑ�����", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���č��̍P����5�����B�������č��ɂ���I���K���_�Ƃ�", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���O�����Ă��邾���ňقȂ�V�̂ł���", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�I���K���_�c���č��Ɉʒu����U�����_�ł���", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���_�̒��Ƀ��[�v��̍\���������邱�Ƃ���", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"��������낢��ȕ��Ɍ����Ăāu�I���K���_�v�u�������_�v�Ȃ�", font, size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���낢��ȌĂі������U�����_�ł���", font, size_y * ver, size, c);
	}

}