//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjStarPresent.h"
extern int lever;
int crick = 0;
int cenge = 0;


void CObjStarPresent::Init()
{
	 page = 0;//���̃y�[�W�֍s�����߂̕ϐ�
	 page_flag = false;
	 starpresent_flag = false;
	 ver = 0;
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
	float p[4] = { 1.0f,1.0f,1.0f,0.6f, };
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu
	
	int g = 200.0f;//���g�̉���
	int k = 75.0f;//���g�̗���
	int t = 70;//���̖��O�̈ʒu
	int l = 0;//t�Ɗ|����p�̕ϐ�
	int s = 0;//���̃N���b�N�̌�
	int std = 0;//���������Ɉڂ��ϐ�
	int side_a = 0;//���̘g�͈�
	int side_b = 200;//�E�̘g�͈�
	int fy = 200;//���̖��O�̉���
	int font_size = 25;//�����̑傫��
	int  Interval_y= 35;//�����̗����Ԋu
	int  left_end= 80;//�������̍��̌��E�����߂�
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

	int size = 25;
	int size_y = 30;
	int font = 80;
	int ver;


	if (lever == 0)
	{
		;
	}
	//���r��
	else if (lever == 1)
	{
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

		int ver;
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
	//����
	else if (lever == 2)
	{
		//					�@�@	    X�@ Y�@ �傫��
		Font::StrDraw(L"�A�����V��", 15, 320 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 1;
			}
		}

		//					�@�@			    X�@    Y�@   �傫��
		Font::StrDraw(L"�t���E�A���E�T�}�J�[", 10, 335 + t * l, 18, c);
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
		Font::StrDraw(L"���[���@�e�B ", 15, 330 + t * l, 30, c);
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
		Font::StrDraw(L"�g���N���A", 15, 330 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 4;
			}
		}


		int ver;
		if (crick == 1)
		{
			ver = 0;
			Font::StrDraw(L"�������ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"4.1���̎启A��5.1���̔���B����Ȃ�A���n", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���悻720�N�̎����Ō݂��Ɏ��񂵂Ă���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�A���c2�̍P�������҂̏d�S�̎�����O���^�����Ă���V�̂�", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"����B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��", font, size_y* ver, size, c);
		}
		else if (crick == 2)
		{
			ver = 0;
			Font::StrDraw(L"�������ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�����������̃X�y�N�g���^��B6 Ve���ʂ͑��z��5�{", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���a�͑��z��3.6�{�Ɛ��肳���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�X�y�N�g���^�c�P���̕��ޖ@�̈�ł���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�P��������˂��ꂽ�d���g�𑨂��X�y�N�g�����ώ@���ĕ��ނ���", font, size_y* ver, size, c);
		}
		else if (crick == 3)
		{
			ver = 0;
			Font::StrDraw(L"�������ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"5�̍P�������d�����\�����Ă���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���d���c�n�����猩��Ƌߐڂ����ʒu�Ɍ�����3�ȏ�̍P����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"����", font, size_y* ver, size, c);
		}
		else if (crick == 4)
		{
			ver = 0;
			Font::StrDraw(L"�������ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"4�����B4.26����A����8.30����B���̓�d���ł���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"��d���c�n���ォ�猩��P�������������ɋߐڂ��Č����镨��", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�w��", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"����ł�1�̐��Ɍ����邪�A�]�����ȂǂŊϑ����鎖�ɂ����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"2�ɕ�������", font, size_y* ver, size, c);
		}
	}
	//���r��
	else if (lever == 3)
	{
		//					�@�@	    X�@ Y�@ �傫��
		Font::StrDraw(L"�n�}��", 20, 320 + t * l, 30, c);
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
		Font::StrDraw(L"�V�F���^��", 20, 320 + t * l, 30, c);
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
		Font::StrDraw(L"���T���e�B��", 15, 320 + t * l, 30, c);
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
		Font::StrDraw(L"�{�e�C��", 20, 320 + t * l, 30, c);
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
		Font::StrDraw(L"�����B�u���A", 20 + 200, 320 + t * l, 30, c);
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
		Font::StrDraw(L"�o���j�[", 20 + 200, 330 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 6;
			}
		}

		int ver;

		if (crick == 1)
		{
			ver = 0;
			Font::StrDraw(L"���Ђ����ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���Ђ����ōł����邢�P���ŁA�B���2����", font, size_y* ver, size, c);
		}
		else if (crick == 2)
		{
			ver = 0;
			Font::StrDraw(L"���Ђ����ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���Ђ�����2�Ԗڂɖ��邢�P���ŁA3����", font, size_y* ver, size, c);
		}
		else if (crick == 3)
		{
			ver = 0;
			Font::StrDraw(L"���Ђ����ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�قړ������邳��2�̍P������Ȃ�", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"��������d���Ƃ��Ēm���݂���5,000�N�ȏ�|����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���񂵂Ă���", font, size_y* ver, size, c);
		}
		else if (crick == 4)
		{
			ver = 0;
			Font::StrDraw(L"���Ђ����ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"K�^�̋����ŁA�킸���ȕό����ϑ�����Ă��邪�^�ɕό�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���邩�͒肩�ł͂Ȃ�", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�����c�����\�ʉ��x������n�񐯂������a����і��邳��", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���ɑ傫���P���̂��Ƃł���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�ό����c�V�̂̈��ŁA���邳�i�����j���ω�������̂̂��Ƃ�", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"����", font, size_y* ver, size, c);
		}
		else if (crick == 5)
		{
			ver = 0;
			Font::StrDraw(L"���Ђ����ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"��170���N���ꂽ�ʒu�ɂ���5�����̍P���ł���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�������}�������F�����̒i�K�ɂ���", font, size_y* ver, size, c);
		}
		else if (crick == 6)
		{
			ver = 0;
			Font::StrDraw(L"���Ђ����ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���z��3.2�{�̎��ʂ�����B�^��n�񐯂��启�Ƃ��镪���A���ŁA", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�����͎启����O�����30�N�|���Ď��񂵂Ă����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�l�����Ă���", font, size_y* ver, size, c);
		}
	}
	//������
	else if (lever == 4)
	{
		//					�@�@	 X�@ Y�@ �傫��
		Font::StrDraw(L"�A���f�o����", 10, 305, 15, c);

		// left				 right            top            bottom               
		if (m_mou_x > 0 && m_mou_x < 100 && m_mou_y>300 && m_mou_y < 325)
		{
			Font::StrDraw(L"���������ɂɑ�����", 110, 0, 30, c);
			Font::StrDraw(L"��Ԗ��邢��", 110, 50, 30, c);
		}
	}
	//,�o�q��
	else if (lever == 5)
	{
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
	//�I��
	else if (lever == 6)
	{
		//					�@�@	            X�@ Y�@ �傫��
		Font::StrDraw(L"�A�N�x���X ", 20, 330 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 1;
			}
		}

		//					�@�@			    X�@ Y�@ �傫��
		Font::StrDraw(L"�A���^���t", 20, 330 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 2;
			}
		}

		//					�@�@		       X�@ Y�@ �傫��
		Font::StrDraw(L"�A�Z���X�E�{���A���X ", 10, 335 + t * l, 18, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 3;
			}
		}
		//					�@�@        X�@        Y�@    �傫��
		Font::StrDraw(L"�A�Z���X�E�A�E�X�g�����X", 10, 340 + t * l, 18, c);
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

		Font::StrDraw(L"�X�g�[�� ", 20 + 220, 320 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 5;
			}
		}

		//					�@�@			    X�@ Y�@ �傫��
		Font::StrDraw(L"�e�O�~�� ", 20 + 220, 330 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 6;
			}
		}

		//					�@�@		       X�@ Y�@ �傫��
		Font::StrDraw(L"�s�A�g�X ", 20 + 220, 340 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 7;
			}
		}
		//					�@�@        X�@        Y�@    �傫��
		Font::StrDraw(L"�i�n", 20 + 220, 350 + t * l, 30, c);
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

		Font::StrDraw(L"�R�y���j�N�X ", 20 + 400, 320 + t * l, 30, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 9;
			}
		}


		int ver;

		if (crick == 1)
		{
			ver = 0;
			Font::StrDraw(L"���ɍ��ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���ɍ��̒��ł�4�Ԗڂɖ��邭�A4.20�����ŗǂ������̉��ł�", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"����ł̊ϑ����\�ł�����x�͑��z��23�{�ȏ�ł���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�����ʂ̋߂��ɂ��邽�ߌ���A�H�ɘf���ɂ�鉆����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�N���邱�Ƃ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�����c�V����ɂ����鑾�z�̌�������̒ʂ蓹�i��~�j������", font, size_y* ver, size, c);
		}
		else if (crick == 2)
		{
			ver = 0;
			Font::StrDraw(L"���ɍ��ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���ɍ��ōł����邢4�����̍P���ł���B�����A���ł���", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"�启�̂��ɍ�����A�͞�F��K�^�����Ńo���E�����Ƃ��Ă�", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�m���Ă���B��������3.50���A��Γ�����-1.25��", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"�������ɍ�����B�͐ԐF�␯�A�启����29�b���ꂽ�O����", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"76,000�N�Ō��]���Ă���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�o���E�����c�X�y�N�g���^��G�^�܂���K�^�̋����ł���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�X�y�N�g������AS�ߒ����ߏ�ɐi��", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"455.4nm�̈ꉿ�̃o���E�������݂��邱�Ƃ���������Ă���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�ԐF�␯�c��n�񐯂̒��œ��ɏ������P���̃O���[�v", font, size_y* ver, size, c);
		}
		else if (crick == 3)
		{
			ver = 0;
			Font::StrDraw(L"���ɍ��ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�P����5�����B�������Ƃ���Ă��邪�A���_����͎�n�񐯂�", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"��������Ă���B10������12�����̍P���ƎO�d���Ɍ����邪", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"��������A���ł͂Ȃ�", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�A���c2�̍P�������҂̏d�S�̎�����O���^�����Ă���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�V�̂ł���B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��", font, size_y* ver, size, c);
		}
		else if (crick == 4)
		{
			ver = 0;
			Font::StrDraw(L"���ɍ��ɑ�����", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"���ɍ��Ɉʒu����P����5�����B�������Ƃ���Ă��邪�A", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"���_����͎�n�񐯂Ɛ�������Ă���B10������12�����̍P����", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"�O�d���Ɍ����邪�A��������A���ł͂Ȃ�", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"�������c�����X�y�N�g���^�̒ʏ�̎�n�񐯂���▾�邭", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"�����قǂ͖��邭�Ȃ��P���̕��ނ�1�ł���", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"��n�񐯁c�P���̗L�����x�Ɩ��邳���������}�ł���", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"�w���c�V���v�����O�E���b�Z���} (HR�}) ���", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"���邭��������Â��ቷ�ɉ��т���ł����n���", font, size_y * ver, size, c);
			ver++;
			Font::StrDraw(L"�ʒu����P���������B�␯�Ƃ�����", font, size_y * ver, size, c);
		}
		else if (crick == 5)
		{
			ver = 0;
			Font::StrDraw(L"���ɍ��ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���ɍ��̍P����6�����B���F��A�^��n�񐯂ŁA�v���Z�y���c��", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���邢����1�ł���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"A�^��n�񐯁c�X�y�N�g���^��A�A���x�K����V�̐��f��R�₵��", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�R�����n�񐯂ł���X�y�N�g�����̋������f�̋z�����ɂ����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"��ʂ����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�v���Z�y���c�c���ɍ��ɂ���U�J���c�ł���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�U�J���c�c�P���̏W�c�i���c�j�̈��ł���B���q�_���瓯����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���܂ꂽ�����m�����܂��Ɍ݂��ɋ߂��ʒu�ɂ����Ԃ̓V�̂�", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�w����͂̃f�B�X�N�����ɑ��݂��邽�ߋ�͐��c�Ƃ��Ă΂��", font, size_y* ver, size, c);
		}
		else if (crick == 6)
		{
			ver = 0;
			Font::StrDraw(L"���ɍ��ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���Ȃ��Ƃ�4�̍P������\������邩�ɍ��̍P���n�ł���B", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�����ʂ̕t�߂ɂ��邽�߁A����H�ɘf���ɂ�鉆����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�ϑ�����邱�Ƃ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�����c����V�̂��ϑ��҂Ƒ��̓V�̂̊Ԃ�ʉ߂��邽�߂�", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���̓V�̂��B����錻�ۂł���", font, size_y* ver, size, c);
		}
		else if (crick == 7)
		{
			ver = 0;
			Font::StrDraw(L"���ɍ��ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���ɍ��̍P����6�����B���̐��͐���B�^��n�񐯂ł���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"B�^��n�񐯁c�X�y�N�g���^��B�A���x�K����V��", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���f�̊j�Z���ŔR�����n�񐯂ł���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���z��2�{����16�{�̎��ʂ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�\�ʉ��x��10,000K����30,000K�̊Ԃł���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"B�^��n�񐯂͊�ȑ��݂ŁA��n�񐯑S�̂ɐ�߂銄����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"0.1%���x�ɉ߂��Ȃ��ƍl�����Ă���", font, size_y* ver, size, c);
		}
		else if (crick == 8)
		{
			ver = 0;
			Font::StrDraw(L"���ɍ��ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���ɍ��̍P����5�����B", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�ŗL���̃n�i�́A�y���V�A��Łu�@�v�Ƃ���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�Ӗ��̌��t�ɗR������", font, size_y* ver, size, c);
		}
		else if (crick == 9)
		{
			ver = 0;
			Font::StrDraw(L"���ɍ��ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���z�n����41���N�̋����ɂ��邩�ɍ��̘A���n�ł���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���z�Ɏ���G�^��n�񐯁i���ɍ�55�Ԑ�A�j��", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�ԐF�␯�i���ɍ�55�Ԑ�B�j����\������A2�̓V�̂�", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"1000�V���P�ʈȏ㗣��Ă���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"2008�N�܂łɁA���ɍ�55�Ԑ�A�̎���ɂ�5�̑��z�n�O�f����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"��������Ă���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"G�^��n�񐯁c�X�y�N�g���^��G�^�A���x�K����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"V�̍P���i��n�񐯁j�̂��Ɖ��F�␯�i�������傭�킢�����j", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"G V�Ƃ��Ă΂��B���z��G�^��n�񐯂̈�ł���", font, size_y* ver, size, c);
			ver++;
		}
	}
	//�I��
	else if (lever == 7)
	{
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


		int ver;
		if (crick == 1)
		{
			ver = 0;
			Font::StrDraw(L"�������ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�������ōł����邢�P���őS�V21��1������1�B1�����̒��ł�", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�ł��Â��قډ�����ɂ���A�q�C�ʒu�̌v���̊�ƂȂ�", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"��p�P���ƂȂ��Ă���4�̐����e2�̃y�A�ɂȂ��Č݂���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"����Ă��鑽�d�A���ł���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�����c�V����ɂ����鑾�z�̌�������̒ʂ蓹�i��~�j������", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�A���c2�̍P�������҂̏d�S�̎�����O���^�����Ă���V�̂�", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"����B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��", font, size_y* ver, size, c);
		}
		else if (crick == 2)
		{
			ver = 0;
			Font::StrDraw(L"�������ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�������̍P����2�����B�����������̃A�[�N�g�D���X��", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���Ƃߍ��̃X�s�J�ƂŁA�t�̑�O�p�`���`�����锒�F��", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"��n�񐯁B���č��^�ό����ł���A�ό��͈͂�", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�����킸���Ȃ̂Ŋᎋ�ϑ��ł͕ό��͂킩��Ȃ�", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"��n�񐯁c�P���̗L�����x�Ɩ��邳���������}�ł��鍶�㉄�т�", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���ł���w���c�V���v�����O�E���b�Z���} (HR�}) ���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���邭��������Â��ቷ�Ɏ�n��Ɉʒu����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�P���������B�␯�Ƃ�����", font, size_y* ver, size, c);
		}
		else if (crick == 3)
		{
			ver = 0;
			Font::StrDraw(L"�������ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�������̍P���ɂ���2�����ł���B��F�̋����ł���启��", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���F�����̔�������Ȃ�����A���ł��肻�̔������Ə��K�͂�", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�V�̖]�����ł���y�Ɋϑ��ł��邱�Ƃ���V���Ƃ����ɂ�", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�l�C�̍����P���ł���B�܂������������Q�̕��˓_��", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�߂����Ƃł��m����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�����A���c��d���̐����邤���̈�B�]�����ŗ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�������Ċϑ����ꗼ�������]�^�����Ă��鎖��", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�m�F����Ă���A��������", font, size_y* ver, size, c);
		}
		else if (crick == 4)
		{
			ver = 0;
			Font::StrDraw(L"�������ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�������̍P����3�����B���F�̋P�����ŁA���z�����኱", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�傫���č����ł��邩�Ȃ�ǂ���������Ă���A�N���傫����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���Ă͔�r�I���m�ɑ��肳��Ă��鑾�z����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�傫�Ȏ��ʂ����������͒Z����F�̋������ԐF�����ɂȂ�", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�Â��ɔ��F�␯�ɂȂ�ƍl�����Ă���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�P�����c�ɂ߂Ė��邢�����ɕ��ނ����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�ԐF�����c����Ŋώ@����ƐԂ������邱�Ƃ���u�ԐF�v������", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�Ă΂��B�@���F�␯(�͂����傭�킢����)�c�P����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�i���̏I�����ɂƂ肤��`�Ԃ̈��", font, size_y* ver, size, c);
		}
		else if (crick == 5)
		{
			ver = 0;
			Font::StrDraw(L"�������ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�������̍P����3�����B������F�^�̋����ŁA���S�j�ł�", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���f�̊j�Z���͊��ɏI���w���E���̊j�����k���Ă���i�K��", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"����B�������ꂽ�ʒu�ɂ��邵����35�Ԑ��Ƃ͌������̓�d����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�֌W�ɂ���A�A���ł͂Ȃ�", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"��d���c�n���ォ�猩��P�������������ɋߐڂ��Č����镨��", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�w��", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�A���c2�̍P�������҂̏d�S�̎�����O���^�����Ă���V�̂�", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"����B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��", font, size_y* ver, size, c);
		}
		else if (crick == 6)
		{
			ver = 0;
			Font::StrDraw(L"�������ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�������̍P����3�����BA�^�X�y�N�g���̎�n�񐯂��珀������", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���ނ����B���悻4500���N�O�ɒa�������Ƃ��ɂ�", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"B8�^�̎�n�񐯂ł��菫���͎��ʂ̑傫�Ȕ��F�␯��", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�Ȃ���̂ƍl�����Ă���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"��n�񐯁c�P���̗L�����x�Ɩ��邳���������}�ł���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�w���c�V���v�����O�E���b�Z���} (HR�}) ��ŁA", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���邭��������Â��ቷ�ɉ��т���ł����n���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�ʒu����P���������B�␯�Ƃ�����", font, size_y* ver, size, c);
		}
		else if (crick == 7)
		{
			ver = 0;
			Font::StrDraw(L"�������ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�������̍P����4�����B���������̃A���f�o������", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�悭���ʂ��Ă����Γ����ł͂킸���ɂ��̐��̂ق���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���邢���n������̋����������Ɖ�������25�{�قǈÂ�������", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�₪�ă~���̂悤�Ȓ������̕ό����ƂȂ�ƍl�����Ă���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�~���c�����ł����k��������ɖ��邳���ɑ�ƂȂ鐫��������", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�ό����c�V�̂̈��ŁA���邳�i�����j���ω�������̂̂���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"����", font, size_y* ver, size, c);
		}
		else if (crick == 8)
		{
			ver = 0;
			Font::StrDraw(L"�������ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�������̍P����4�����BK�^�̋��������A�܂����S�j�ł�", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�w���E���̊j�Z�����n�܂��Ă��炸�j�����k���Ă���i�K�ł���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�ƍl�����Ă���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"5,000���N��ɂ̓w���E���̊j�Z�����n�܂�A���݂��", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"10�{����20�{�͌��x���������̂Ɨ\������Ă���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"��358�������Č��]���Ă���", font, size_y* ver, size, c);
		}
		else if (crick == 9)
		{
			ver = 0;
			Font::StrDraw(L"�������ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�������̍P����4�����BF�^�̃X�y�N�g������������", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"A�^��n�񐯂��A���n�𐬂��Ă��邪�A�启�Ɣ����̕��ϋ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"��ϋ߂����ߕ����@�܂��̓X�y�b�N�����@�ł���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�ϑ��ł��Ă��Ȃ�2�̐��́A14.498���̎����ŋ��ʏd�S��", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�݂��ɏ����Ă���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"A�^��n�񐯁c�X�y�N�g���^��A�A���x�K����V��", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���f��R�₵�ĔR�����n�񐯂ł���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�A���c2�̍P�������҂̏d�S�̎�����O���^�����Ă���V�̂�", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"����B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��", font, size_y* ver, size, c);
		}
	}
	//������
	else if (lever == 8)
	{
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
	else if (lever == 9)
	{
		//					�@�@	            X�@ Y�@ �傫��
		Font::StrDraw(L"�Y�x���E�G���E�Q�k�r", 2, 330 + t * l, 20, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 1;
			}
		}

		//					�@�@			    X�@ Y�@ �傫��
		Font::StrDraw(L"�Y�x���E�G�X�E�J�}��", 2, 330 + t * l, 20, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 2;
			}
		}

		//					�@�@		       X�@ Y�@ �傫��
		Font::StrDraw(L"�Y�x���G���n�N���r", 10, 330 + t * l, 20, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 3;
			}
		}
		//					�@�@        X�@        Y�@    �傫��
		Font::StrDraw(L"�u���L�E��", 25, 330 + t * l, 20, c);
		l++;
		// left				 right            top            bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 4;
			}
		}

		int ver;

		if (crick == 1)
		{
			ver = 0;
			Font::StrDraw(L"�Ă�т���ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���̐��͌��w��d���ŁA��C������ł���Γ���Ō��킯����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�d���c�n���ォ�猩��P�������������ɋߐڂ��Č����镨�B", font, size_y* ver, size, c);
		}
		else if (crick == 2)
		{
			ver = 0;
			Font::StrDraw(L"�Ă�т���ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�Ă�т���ōł����邢�P��", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�n������̋�����185���N�Ɛ��������", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�����ŉ�]���Ă���A���z��100�{�ȏ�̎��]���x�ł���", font, size_y* ver, size, c);
		}
		else if (crick == 3)
		{
			ver = 0;
			Font::StrDraw(L"�Ă�т���ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�O����55,000�N�ȏォ���ĉ���Ă���", font, size_y* ver, size, c);
		}
		else if (crick == 4)
		{
			ver = 0;
			Font::StrDraw(L"�Ă�т���ɑ�����", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"��������̑��̍P���Ɨ��ꂽ�ʒu�ɂ��邱�Ƃ���", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"�u������������v���Ă�т���̈ꕔ", font, size_y* ver, size, c);
			ver++;
			Font::StrDraw(L"���̌�V���Ɂu�Ă�т���А��v�Ƃ���������U�蒼����", font, size_y* ver, size, c);
		}
	}
	//嶍�
	else if (lever == 10)
	{
		//					�@�@	 X�@		    Y�@ �傫��
		Font::StrDraw(L"�A���^���X", 30 + fy * std, 330 + t * l, 30, c);
		l++;

		// left								right						top								�@bottom                            
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 1;//�����̓L�[�̂悤�Ȃ���
			}
		}

	if (crick == 1)//���ς����炱�����ς���
	{
		ver = 0;
		Font::StrDraw(L"��������ōł����邢�P���őS�V21��1������1�B�Ă̓�̋�", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�ɐԂ��P���悭�m����P����1�ł���B", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�A���^���X�͂��Ē��a�����z��230�{�Ƃ���A�u���ȔN�\�v��", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"���炭���̒l���̗p���Ă������A���ۂ͂����Ƒ傫�Ȑ��ŁA��", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�a�͑��z��600�{�Ȃ���800�{�ł���B", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"���邳�͑��z��8000�{�Ȃ���1���{�ƍl�����Ă���B�Ȃ��A��", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�O�����܂߂Čv�Z����Ɩ��邳�͑��z��6.5���{�ł���B", left_end, Interval_y*ver, font_size, c);
	}
	
	//					�@�@	 X�@ Y�@ �傫��
	Font::StrDraw(L"�A�N���u", 30 + fy * std, 330+t*l, 30, c);
	l++;
	// left								right						top							�@�@�@bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 2;//�����̓L�[�̂悤�Ȃ���
		}
	}

	if (crick == 2)//���ς����炱�����ς���
	{
		ver = 0;
		Font::StrDraw(L"��������̍P����3�������Z�d�A���B", left_end, Interval_y*ver, font_size,c);
		ver++;
		Font::StrDraw(L"[�A���Ƃ�?]���݂��̏d�͂Ɉ����ꂠ�����藣�ꂽ����J��Ԃ�", left_end, Interval_y*ver, font_size,  c);
		ver++;
		Font::StrDraw(L"�����Ă���B����Ō����ꍇ�͈�Ɍ����邪�A�]����", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�Ȃǉ������Ō����ꍇ��ɕ��􂷂�B", left_end, Interval_y*ver, font_size, c);
	}
	
	Font::StrDraw(L"�W���o", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	// left								right						top						bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			page = 0;
			crick = 3;//�����̓L�[�̂悤�Ȃ���
		
		}
	}

	if (crick == 3 &&page==0)//���ς����炱�����ς���
	{
		ver = 0;
		Font::StrDraw(L"��������̍P����2�����B", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"Be���̒��ł������^�ό����̃J�V�I�y�������^�ό����ł����", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�l�����Ă���B", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"[�����^�ό����Ƃ́H]", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�����^�ό����͕ό����̈��B�P���̊O�w���C�̔����ɂ��", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�ĕό����鐯�B", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"[�J�V�I�y�������^�ό����Ƃ́H]", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�K�X�k���̂��Ƃł���A�����̗��o�̂��߁A���x�͕s�K����", left_end, Interval_y*ver, font_size, c);
		//8�s�ڂ܂ŁA���s
		
	}
	if (crick == 3 && page == 1)
	{
		ver = 0;
		Font::StrDraw(L"�ω�����B", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�K�X�k���͍����Ŏ��]���A���̋@�\�Ɉ��̐�����^���Ă���", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"���A�����䂪�c���Ă���B�ό����̏ꍇ�A�J�V�I�y�������^�� ", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�����ɕ��ނ����B", left_end, Interval_y*ver, font_size, c);

		}

		Font::StrDraw(L"�������O", 30 + fy * std, 330 + t * l, 30, c);
		l++;
		// left								right						top						bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 4;//�����̓L�[�̂悤�Ȃ���
			}
		}

		if (crick == 4)//���ς����炱�����ς���
		{
			ver = 0;
			Font::StrDraw(L"��������̍P����2�����B ", left_end, Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"2017�N11��17���A���ۓV���w�A���̍P���̖����Ɋւ��郏�[�L", left_end, Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"���O�O���[�v �́A��������Ð��̌ŗL���Ƃ��āA�������O��", left_end, Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����ɒ�߂��B", left_end, Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"����́A�I�[�X�g�����A�̃m�[�U���E�e���g���[�ɏZ�ރI�[�X", left_end, Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"�g�����A��Z���̃����_�}�������g���Ă����ď̂��̗p������ ", left_end, Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"�̂ł���B", left_end, Interval_y*ver, font_size, c);

		}

		t -= 4;
		l -= 4;
		std++;//�l����\��������std������
		Font::StrDraw(L"�T���K�X", 30 + fy * std, 330 + t * l, 30, c);
		l++;
		// left								right						top						bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{

				crick = 5;//�����̓L�[�̂悤�Ȃ���
			}
		}

		if (crick == 5)//���ς����炱�����ς���
		{
			ver = 0;
			Font::StrDraw(L"�����F�̋P�����B2������A����6������B���̓�d���ł���B ", left_end, Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�P�����Ƃ́H]", left_end, Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"�P�����́A�񓙐��قǂ̖��邳�����P���ł���B������ ", left_end, Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"�������璴�����ɂ܂�����傫���ł��邪�A�ʏ�͒�������", left_end, Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ǖ��邭�d���킯�ł͂Ȃ��A�ɂ߂Ė��邢�����ɕ��ނ����B", left_end, Interval_y*ver, font_size, c);


		}

		//					�@�@	 X�@		    Y�@ �傫��
		Font::StrDraw(L"�M���^�u", 30 + fy * std, 330 + t * l, 30, c);
		l++;

		// left								right						top								�@bottom                            
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 6;//�����̓L�[�̂悤�Ȃ���
			}
		}

		if (crick == 6)//���ς����炱�����ς���
		{
			ver = 0;
			Font::StrDraw(L"���̍P���͕����A���ŁA�启�̓P�t�F�E�X�����^�ό����ł���B", left_end, Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����ϑ��ɂ��A���]������195���Ƒ��肳�ꂽ�B", left_end, Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"���邳�̕ω��́A4.80���ԁA4.93���Ԃł���B", left_end, Interval_y*ver, font_size, c);

		}

		//					�@�@	 X�@ Y�@ �傫��
		Font::StrDraw(L"�V���E��", 30 + fy * std, 330 + t * l, 30, c);
		l++;
		// left								right						top							�@�@�@bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 7;//�����̓L�[�̂悤�Ȃ���
			}
		}

	if (crick == 7 && page == 0)//���ς����炱�����ς���
	{
		ver = 0;
		Font::StrDraw(L"���F�̏������B", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�P�t�F�E�X�����^�ό����ł���A�킸���ɕό����邪�A�ό��� ", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�͂��������̂Ŋᎋ�ϑ��ł͂��̕ό��͂킩��Ȃ��B", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"���̐���3�̐�����Ȃ�d���ł���B", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�ɐ�B��15�����ŁA�ɐ�A�ƃɐ�B��42�b����Ă���B", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�������A����炪�����I�ȉe�����y�ڂ������A���ł���̂�", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�ǂ����͒m���Ă��Ȃ��B�����A�����Ƃ���Ȃ�AA��B�̊�", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"��7,500�V���P�ʁAA��C�̊Ԃ�17,000�V���P�ʁi0.27���N�j ", left_end, Interval_y*ver, font_size, c);
	}
	if (crick == 7 && page == 1)//���ς����炱�����ς���
	{
		ver = 0;
		Font::StrDraw(L"����Ă��邱�ƂɂȂ�B", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"[�d���Ƃ�]", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�n���ォ�猩�Ĉ�̐��Ɍ����鐯�̂��ƁA�������A����", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�͈Ⴂ��������͈�̐��Ɍ�����Ƃ��������Ŏ��ۂɂ�", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�d�Ȃ��Ă��鐯�X�͋���������Ă���B", left_end, Interval_y*ver, font_size, c);
		
	}
	Font::StrDraw(L"�[�~�f�B����", 10 + fy * std, 340 + t * l, 30, c);
	l++;
	// left								right						top						bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{

				crick = 8;//�����̓L�[�̂悤�Ȃ���

			}
		}

		if (crick == 8)//���ς����炱�����ς���
		{

			Font::StrDraw(L"Xamidimura �́A�A�t���J�嗤�암�ɏZ�ރR�C�R�C�l�̌��t��", 110, 0, 30, c);
			Font::StrDraw(L"�u���C�I���̊�v���Ӗ����� xami di mura�ɗR������", 110, 50, 30, c);

		}

		t -= 4;
		l -= 4;
		std++;//�l����\��������std������
		Font::StrDraw(L"�s�s���}", 30 + fy * std, 330 + t * l, 30, c);
		l++;

		// left								right						top						bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{

				crick = 9;//�����̓L�[�̂悤�Ȃ���

			}
		}

		if (crick == 9)//���ς����炱�����ς���
		{
			Font::StrDraw(L"Pipirima �́A�^�q�`�̓`���ɓo�ꂷ��o�q�̒j���ɗR������", 110, 0, 30, c);
		}

		Font::StrDraw(L"�W���o�n�[", 30 + fy * std, 340 + t * l, 30, c);
		l++;
		// left								right						top						bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{

				crick = 10;//�����̓L�[�̂悤�Ȃ���
			}
		}

		if (crick == 10)//���ς����炱�����ς���
		{
			Font::StrDraw(L"�W���o�n�[", 110, 0, 30, c);
		}

		//					�@�@	 X�@		    Y�@ �傫��
		Font::StrDraw(L"�t�@���O", 30 + fy * std, 350 + t * l, 30, c);
		l++;

		// left								right						top								�@bottom                            
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 11;//�����̓L�[�̂悤�Ȃ���
			}
		}

		if (crick == 11)//���ς����炱�����ς���
		{
			Font::StrDraw(L"�t�@���O", 110, 0, 30, c);
		}

		//					�@�@	 X�@ Y�@ �傫��
		Font::StrDraw(L"�C�N���[��", 30 + fy * std, 360 + t * l, 30, c);
		l++;
		// left								right						top							�@�@�@bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 12;//�����̓L�[�̂悤�Ȃ���
			}
		}

		if (crick == 12)//���ς����炱�����ς���
		{
			Font::StrDraw(L"�C�N���[��", 110, 0, 30, c);

		}

		t -= 4;
		l -= 4;
		std++;//�l����\��������std������
		Font::StrDraw(L"�A���E�j���g", 10 + fy * std, 330 + t * l, 30, c);
		l++;
		// left								right						top						bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 13;//�����̓L�[�̂悤�Ȃ���
			}
		}

		if (crick == 13)//���ς����炱�����ς���
		{
			Font::StrDraw(L"�A���E�j���g", 110, 0, 30, c);
		}

		//					�@�@	 X�@		    Y�@ �傫��
		Font::StrDraw(L"���T�g", 30 + fy * std, 340 + t * l, 30, c);
		l++;

		// left								right						top								�@bottom                            
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 14;//�����̓L�[�̂悤�Ȃ���
			}
		}

		if (crick == 14)//���ς����炱�����ς���
		{

			Font::StrDraw(L"���T�g", 110, 0, 30, c);

		}

		//					�@�@	 X�@ Y�@ �傫��
		Font::StrDraw(L"�t���G", 30 + fy * std, 360 + t * l, 30, c);
		l++;
		// left								right						top							�@�@�@bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 15;//�����̓L�[�̂悤�Ȃ���
			}
		}

		if (crick == 15)//���ς����炱�����ς���
		{
			Font::StrDraw(L"�t���G", 110, 0, 30, c);
		}

		Font::StrDraw(L"", 30 + fy * std, 370 + t * l, 30, c);
		l++;
		// left								right						top						bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{

				crick = 16;//�����̓L�[�̂悤�Ȃ���

			}
		}

		if (crick == 16)//���ς����炱�����ς���
		{

			Font::StrDraw(L"", 110, 0, 30, c);
		}
	}
	//�ˎ��
	else if (lever == 11)
	{
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
	//�R�r��
	else if (lever == 12)
	{
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

		int ver;
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
}