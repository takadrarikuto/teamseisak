//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjStarPresent8.h"
extern int lever;
extern int crick;
extern int cenge;


void CObjStarPresent8::Init()
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

void CObjStarPresent8::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();


}

void CObjStarPresent8::Draw()
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


	if (crick == 1)
	{
		ver = 0;
		Font::StrDraw(L"���ɍ��ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���ɍ��̒��ł�4�Ԗڂɖ��邭�A4.20�����ŗǂ������̉��ł�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"����ł̊ϑ����\�ł�����x�͑��z��23�{�ȏ�ł���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�����ʂ̋߂��ɂ��邽�ߌ���A�H�ɘf���ɂ�鉆����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�N���邱�Ƃ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�����c�V����ɂ����鑾�z�̌�������̒ʂ蓹�i��~�j������", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 2)
	{
		ver = 0;
		Font::StrDraw(L"���ɍ��ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���ɍ��ōł����邢4�����̍P���ł���B�����A���ł���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�启�̂��ɍ�����A�͞�F��K�^�����Ńo���E�����Ƃ��Ă�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�m���Ă���B��������3.50���A��Γ�����-1.25��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�������ɍ�����B�͐ԐF�␯�A�启����29�b���ꂽ�O����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"76,000�N�Ō��]���Ă���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�o���E�����c�X�y�N�g���^��G�^�܂���K�^�̋����ł���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�X�y�N�g������AS�ߒ����ߏ�ɐi��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"455.4nm�̈ꉿ�̃o���E�������݂��邱�Ƃ���������Ă���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�ԐF�␯�c��n�񐯂̒��œ��ɏ������P���̃O���[�v", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 3)
	{
		ver = 0;
		Font::StrDraw(L"���ɍ��ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�P����5�����B�������Ƃ���Ă��邪�A���_����͎�n�񐯂�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"��������Ă���B10������12�����̍P���ƎO�d���Ɍ����邪", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"��������A���ł͂Ȃ�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�A���c2�̍P�������҂̏d�S�̎�����O���^�����Ă���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�V�̂ł���B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 4)
	{
		ver = 0;
		Font::StrDraw(L"���ɍ��ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���ɍ��Ɉʒu����P����5�����B�������Ƃ���Ă��邪�A", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���_����͎�n�񐯂Ɛ�������Ă���B10������12�����̍P����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�O�d���Ɍ����邪�A��������A���ł͂Ȃ�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�������c�����X�y�N�g���^�̒ʏ�̎�n�񐯂���▾�邭", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�����قǂ͖��邭�Ȃ��P���̕��ނ�1�ł���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"��n�񐯁c�P���̗L�����x�Ɩ��邳���������}�ł���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�w���c�V���v�����O�E���b�Z���} (HR�}) ���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���邭��������Â��ቷ�ɉ��т���ł����n���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�ʒu����P���������B�␯�Ƃ�����", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 5)
	{
		ver = 0;
		Font::StrDraw(L"���ɍ��ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���ɍ��̍P����6�����B���F��A�^��n�񐯂ŁA�v���Z�y���c��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���邢����1�ł���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"A�^��n�񐯁c�X�y�N�g���^��A�A���x�K����V�̐��f��R�₵��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�R�����n�񐯂ł���X�y�N�g�����̋������f�̋z�����ɂ����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"��ʂ����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�v���Z�y���c�c���ɍ��ɂ���U�J���c�ł���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�U�J���c�c�P���̏W�c�i���c�j�̈��ł���B���q�_���瓯����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���܂ꂽ�����m�����܂��Ɍ݂��ɋ߂��ʒu�ɂ����Ԃ̓V�̂�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�w����͂̃f�B�X�N�����ɑ��݂��邽�ߋ�͐��c�Ƃ��Ă΂��", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 6)
	{
		ver = 0;
		Font::StrDraw(L"���ɍ��ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���Ȃ��Ƃ�4�̍P������\������邩�ɍ��̍P���n�ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�����ʂ̕t�߂ɂ��邽�߁A����H�ɘf���ɂ�鉆����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�ϑ�����邱�Ƃ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�����c����V�̂��ϑ��҂Ƒ��̓V�̂̊Ԃ�ʉ߂��邽�߂�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���̓V�̂��B����錻�ۂł���", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 7)
	{
		ver = 0;
		Font::StrDraw(L"���ɍ��ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���ɍ��̍P����6�����B���̐��͐���B�^��n�񐯂ł���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"B�^��n�񐯁c�X�y�N�g���^��B�A���x�K����V��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���f�̊j�Z���ŔR�����n�񐯂ł���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���z��2�{����16�{�̎��ʂ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�\�ʉ��x��10,000K����30,000K�̊Ԃł���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"B�^��n�񐯂͊�ȑ��݂ŁA��n�񐯑S�̂ɐ�߂銄����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"0.1%���x�ɉ߂��Ȃ��ƍl�����Ă���", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 8)
	{
		ver = 0;
		Font::StrDraw(L"���ɍ��ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���ɍ��̍P����5�����B", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�ŗL���̃n�i�́A�y���V�A��Łu�@�v�Ƃ���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�Ӗ��̌��t�ɗR������", left_end, IO_y + Interval_y * ver, font_size, c);
	}
	else if (crick == 9)
	{
		ver = 0;
		Font::StrDraw(L"���ɍ��ɑ�����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���z�n����41���N�̋����ɂ��邩�ɍ��̘A���n�ł���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���z�Ɏ���G�^��n�񐯁i���ɍ�55�Ԑ�A�j��", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�ԐF�␯�i���ɍ�55�Ԑ�B�j����\������A2�̓V�̂�", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"1000�V���P�ʈȏ㗣��Ă���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"2008�N�܂łɁA���ɍ�55�Ԑ�A�̎���ɂ�5�̑��z�n�O�f����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"��������Ă���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"G�^��n�񐯁c�X�y�N�g���^��G�^�A���x�K����", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"V�̍P���i��n�񐯁j�̂��Ɖ��F�␯�i�������傭�킢�����j", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"G V�Ƃ��Ă΂��B���z��G�^��n�񐯂̈�ł���", left_end, IO_y + Interval_y * ver, font_size, c);
		ver++;
	}


}