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
	IO_y = 25; //y���W�J�n�n�_25
	Interval_y = 35;//�����̗����Ԋu35
	left_end = 80;//�������̍��̌��E�����߂�
	pagex = 680; //�y�[�W���Wx
	pagey = 10; //�y�[�W���Wy
	pagesize = 20; //�y�[�W�T�C�Y

	 g = 200.0f;//���g�̉���
	 k = 75.0f;//���g�̗���
	 t = 70;//���̖��O�̈ʒu
	 l = 0;//t�Ɗ|����p�̕ϐ�
	 s = 0;//���̃N���b�N�̌�
	 std = 0;//���������Ɉڂ��ϐ�
	 side_a = 0;//���̘g�͈�
	 side_b = 200;//�E�̘g�͈�
	 fy = 200;//���̖��O�̉���
	 font_size = 25;//�����̑傫��
	  Interval_y = 35;//�����̗����Ԋu
	  left_end = 80;//�������̍��̌��E�����߂�
	 page = 0;//���݂̃y�[�W��
	 pagemax=0;//�ő�y�[�W��
}

void CObjStarPresent::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();


	//�����I���փ{�^��
	// left				 right            top            bottom         
	if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>0 && m_mou_y < 100)
	{
		if (m_mou_l == true)
		{
			lever = 0;
			start_time = 0; //�}�E�X����J�n����
			Scene::SetScene(new CSceneStarPicbook());
			return;
		}
	}
	//���������Ɩ߂�
	else if (Input::GetVKey('B') == true)
	{
		lever = 0;
		start_time = 0; //�}�E�X����J�n����
		Scene::SetScene(new CSceneStarPicbook());
	}


	//30f��ɕ\��
	start_time++;

	if (start_time >30.0f)
	{
		start_flag = true;
	}
	else
	{
		start_flag = false;
	}
}

void CObjStarPresent::Draw()
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

	//�߂����������
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

	
	//					�@�@	 X�@		    Y�@ �傫��
	Font::StrDraw(L"�A���^���X", 30 + fy * std, 330 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left								right						top								�@bottom                            
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 1;//�����̓L�[�̂悤�Ȃ���
				page = 0; //�y�[�W������
			}
		}
	}

	if (crick == 1)//���ς����炱�����ς���
	{
		page_max = 1; //�ő�y�[�W��
		//�y�[�W���\��
		swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);
		
		ver = VER_start; //�����Ԋu������
		Font::StrDraw(L"��������ōł����邢�P���őS�V21��1������1�B�Ă̓�̋�", left_end, IO_y + Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�ɐԂ��P���悭�m����P����1�ł���B", left_end, IO_y + Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�A���^���X�͂��Ē��a�����z��230�{�Ƃ���A�u���ȔN�\�v��", left_end, IO_y + Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"���炭���̒l���̗p���Ă������A���ۂ͂����Ƒ傫�Ȑ��ŁA��", left_end, IO_y + Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�a�͑��z��600�{�Ȃ���800�{�ł���B", left_end, IO_y + Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"���邳�͑��z��8000�{�Ȃ���1���{�ƍl�����Ă���B�Ȃ��A��", left_end, IO_y + Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�O�����܂߂Čv�Z����Ɩ��邳�͑��z��6.5���{�ł���B", left_end, IO_y + Interval_y*ver, font_size, c);
	
		//�y�[�W����
		if (page < 0 || page > 0)
		{
			page = 0;
		}
	}
	
	//					�@�@	 X�@ Y�@ �傫��
	Font::StrDraw(L"�A�N���u", 30 + fy * std, 330+t*l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left								right						top							�@�@�@bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 2;//�����̓L�[�̂悤�Ȃ���
				page = 0; //�y�[�W������
			}
		}
	}


	if (crick == 2)//���ς����炱�����ς���
	{
		page_max = 1; //�ő�y�[�W��
		//�y�[�W���\��
		swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
		Font::StrDraw(strp, pagex, pagey, pagesize, c);

		ver = VER_start; //�����Ԋu������
		Font::StrDraw(L"��������̍P����3�������Z�d�A���B", left_end, IO_y + Interval_y*ver, font_size,c);
		ver++;
		Font::StrDraw(L"[�A���Ƃ�?]���݂��̏d�͂Ɉ����ꂠ�����藣�ꂽ����J��Ԃ�", left_end, IO_y + Interval_y*ver, font_size,  c);
		ver++;
		Font::StrDraw(L"�����Ă���B����Ō����ꍇ�͈�Ɍ����邪�A�]����", left_end, IO_y + Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�Ȃǉ������Ō����ꍇ��ɕ��􂷂�B", left_end, IO_y + Interval_y*ver, font_size, c);
	
		//�y�[�W����
		if (page < 0 || page > 0)
		{
			page = 0;
		}
	}
	

	Font::StrDraw(L"�W���o", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	// left								right						top						bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			pagemax = 1;
			crick = 3;//�����̓L�[�̂悤�Ȃ���
		
		}
	}

	if (crick == 3)
	{
		if (page == 0)//���ς����炱�����ς���
		{
			ver = 0;
			Font::StrDraw(L"��������̍P����2�����B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"Be���̒��ł������^�ό����̃J�V�I�y�������^�ό����ł����", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�l�����Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�����^�ό����Ƃ́H]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����^�ό����͕ό����̈��B�P���̊O�w���C�̔����ɂ��", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ĕό����鐯�B", left_end, IO_y + Interval_y * ver, font_size, c);
			//7�s�ڂŁA���s

		}
		else if (page == 1)
		{
			ver = 0;
			Font::StrDraw(L"[�J�V�I�y�������^�ό����Ƃ́H]", left_end, IO_y + Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"�K�X�k���̂��Ƃł���A�����̗��o�̂��߁A���x�͕s�K����", left_end, IO_y + Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ω�����B", left_end, IO_y + Interval_y*ver, font_size, c);
			ver++;
			Font::StrDraw(L"�K�X�k���͍����Ŏ��]���A���̋@�\�Ɉ��̐�����^���Ă���", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���A�����䂪�c���Ă���B�ό����̏ꍇ�A�J�V�I�y�������^�� ", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����ɕ��ނ����B", left_end, IO_y + Interval_y * ver, font_size, c);
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


	Font::StrDraw(L"�������O", 30 + fy * std, 330 + t * l, 30, c);
	l++;

	if (start_flag == true)
	{
		// left								right						top						bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 4;//�����̓L�[�̂悤�Ȃ���
				page = 0; //�y�[�W������
			}
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

	if (start_flag == true)
	{
		// left								right						top						bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				crick = 5;//�����̓L�[�̂悤�Ȃ���
				page = 0; //�y�[�W������
			}
		}



		if (crick == 5)//���ς����炱�����ς���
		{
			page_max = 1; //�ő�y�[�W��
			//�y�[�W���\��
			swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
			Font::StrDraw(strp, pagex, pagey, pagesize, c);

			ver = VER_start; //�����Ԋu������
			Font::StrDraw(L"�����F�̋P�����B2������A����6������B���̓�d���ł���B ", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"[�P�����Ƃ́H]", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�P�����́A�񓙐��قǂ̖��邳�����P���ł���B������ ", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�������璴�����ɂ܂�����傫���ł��邪�A�ʏ�͒�������", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�ǖ��邭�d���킯�ł͂Ȃ��A�ɂ߂Ė��邢�����ɕ��ނ����B", left_end, IO_y + Interval_y * ver, font_size, c);

			//�y�[�W����
			if (page < 0 || page > 0)
			{
				page = 0;
			}
		}


		//					�@�@	 X�@		    Y�@ �傫��
		Font::StrDraw(L"�M���^�u", 30 + fy * std, 330 + t * l, 30, c);
		l++;

		if (start_flag == true)
		{
			// left								right						top								�@bottom                            
			if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
			{
				if (m_mou_l == true)
				{
					crick = 6;//�����̓L�[�̂悤�Ȃ���
					page = 0; //�y�[�W������
				}
			}
		}

		if (crick == 6)//���ς����炱�����ς���
		{
			page_max = 1; //�ő�y�[�W��
			//�y�[�W���\��
			swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
			Font::StrDraw(strp, pagex, pagey, pagesize, c);

			ver = VER_start; //�����Ԋu������
			Font::StrDraw(L"���̍P���͕����A���ŁA�启�̓P�t�F�E�X�����^�ό����ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"�����ϑ��ɂ��A���]������195���Ƒ��肳�ꂽ�B", left_end, IO_y + Interval_y * ver, font_size, c);
			ver++;
			Font::StrDraw(L"���邳�̕ω��́A4.80���ԁA4.93���Ԃł���B", left_end, IO_y + Interval_y * ver, font_size, c);

		}


		//					�@�@	 X�@ Y�@ �傫��
		Font::StrDraw(L"�V���E��", 30 + fy * std, 330 + t * l, 30, c);
		l++;
		// left								right						top							�@�@�@bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				pagemax = 1;
				crick = 7;//�����̓L�[�̂悤�Ȃ���
				page = 0; //�y�[�W������
			}
		}
		if (crick == 7)
		{
			if (page == 0)//���ς����炱�����ς���
			{
				ver = 0;
				Font::StrDraw(L"��������̍P����2�����B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"��������ł̓A���^���X�Ɏ����Ŗ��邢�P���ł���B���F��", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�������B�P�t�F�E�X�����^�ό����ł���A�킸���ɕό����邪", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�ό��͈͂��������̂Ŋᎋ�ϑ��ł͂��̕ό��͂킩��Ȃ��B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"���̐���3�̐�����Ȃ�d���ł���B�ɐ�B��15������", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�ɐ�A�ƃɐ�B��42�b����Ă���B����������炪�����I��", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�ǂ����͒m���Ă��Ȃ��B�����A�����Ƃ���Ȃ�AA��B�̊�", left_end, IO_y + Interval_y * ver, font_size, c);
			}
			else if (page == 1)//���ς����炱�����ς���
			{
				ver = 0;
				Font::StrDraw(L"��7,500�V���P�ʁAA��C�̊Ԃ�17,000�V���P�ʁi0.27���N�j ", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"����Ă��邱�ƂɂȂ�B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"���ƂɂȂ�B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[�d���Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�n���ォ�猩�Ĉ�̐��Ɍ����鐯�̂��ƁA�������A����", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�͈Ⴂ��������͈�̐��Ɍ�����Ƃ��������Ŏ��ۂɂ�", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�d�Ȃ��Ă��鐯�X�͋���������Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);
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


		Font::StrDraw(L"�[�~�f�B����", 10 + fy * std, 340 + t * l, 30, c);
		l++;
		// left								right						top						bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				pagemax = 1;
				crick = 8;//�����̓L�[�̂悤�Ȃ���
				page = 0; //�y�[�W������
			}
		}
		if (crick == 8) {
			if (page == 0)//���ς����炱�����ς���
			{
				ver = 0;
				Font::StrDraw(L"��������Ɉʒu����d���B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"��1���ƃ�2���ō\�������B����2�̍P���́A�A����", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"����Ƃ����咣�ƒP�Ȃ錩�����̓�d���ł���Ƃ����咣��", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"���������݂��Ă��邪�K�C�A�v��ł̔N�������̑���l��", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"���������490���N�߂�����Ă���A���ł͂ł͂Ȃ���", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�l������B��1���́A2��B�^�����琬��A����", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"��1�����Ō��]���Ă���BXamidimura �́A", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�A�t���J�嗤�암�ɏZ�ރR�C�R�C�l�̌��t��", left_end, IO_y + Interval_y * ver, font_size, c);
			}
			else if (page == 1)//���ς����炱�����ς���
			{
				//7�s�܂�
				ver = 0;
				Font::StrDraw(L"�u���C�I���̊�v���Ӗ����� xami di mura�ɗR������", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[��d���E�d���Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�n���ォ�猩��P�������������ɋߐڂ��Č����镨���w���B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[�A���Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"2�̍P�������҂̏d�S�̎�����O���^�����Ă���V��", left_end, IO_y + Interval_y * ver, font_size, c);
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

		t -= 4;
		l -= 4;
		std++;//�l����\��������std������
		Font::StrDraw(L"�s�s���}", 30 + fy * std, 330 + t * l, 30, c);
		l++;

		if (start_flag == true)
		{
			// left								right						top						bottom               
			if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
			{
				if (m_mou_l == true)
				{

					crick = 9;//�����̓L�[�̂悤�Ȃ���
					page = 0; //�y�[�W������

				}
			}
		}


		if (crick == 9)//���ς����炱�����ς���
		{
			page_max = 1; //�ő�y�[�W��
			//�y�[�W���\��
			swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
			Font::StrDraw(strp, pagex, pagey, pagesize, c);

			ver = VER_start; //�����Ԋu������
			Font::StrDraw(L"Pipirima �́A�^�q�`�̓`���ɓo�ꂷ��o�q�̒j���ɗR������", left_end, IO_y + Interval_y * ver, font_size, c);

			//�y�[�W����
			if (page < 0 || page > 0)
			{
				page = 0;
			}
		}

		Font::StrDraw(L"�W���o�n�[", 30 + fy * std, 340 + t * l, 30, c);
		l++;
		// left								right						top						bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				pagemax = 1;
				crick = 10;//�����̓L�[�̂悤�Ȃ���
				page = 0; //�y�[�W������
			}
		}
		if (crick == 10) {
			if (page == 0)//���ς����炱�����ς���
			{
				ver = 0;
				Font::StrDraw(L"�n�����猩�Ă�������̕����ɖ�500���N���ꂽ�ʒu�ɂ���", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"4�����̍P���ł���B��������ː��́A7�̍P�����琬��", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"���d�A���n�ł���B�ł����邢�P��Aa�́A���z�̖�6�{��", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"���ʂƁA2,900�{�̌��x������B�^��n�񐯂ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[�A���Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"2�̍P�������҂̏d�S�̎�����O���^�����Ă���V��", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�ł���B�o�q���i�ӂ����ڂ��j�Ƃ��Ă΂��B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[B�^��n�񐯁iB�������ク����������j�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			}
			else if (page == 1)//���ς����炱�����ς���
			{
				//7�s�܂�
				ver = 0;
				Font::StrDraw(L"�X�y�N�g���^��B�A���x�K����V�́A���f�̊j�Z���ŔR����", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"��n�񐯂ł���B���z��2�{����16�{�̎��ʂ�����", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�\�ʉ��x��10,000K����30,000K�̊Ԃł���B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"B�^��n�񐯂͊�ȑ��݂ŁA��n�񐯑S�̂ɐ�߂銄����", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"0.1%���x�ɉ߂��Ȃ��ƍl�����Ă���", left_end, IO_y + Interval_y * ver, font_size, c);
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

		//					�@�@	 X�@		    Y�@ �傫��
		Font::StrDraw(L"�t�@���O", 30 + fy * std, 350 + t * l, 30, c);
		l++;

		// left								right						top								�@bottom                            
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				pagemax = 1;
				crick = 11;//�����̓L�[�̂悤�Ȃ���
				page = 0; //�y�[�W������
			}
		}
		if (crick == 11) {
			if (page == 0)//���ς����炱�����ς���
			{
				ver = 0;
				Font::StrDraw(L"��������̍P����3�����B���̐��͎O�d���ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"��������ΐ�A�͂��ƍ����^�ό����̐ڐG�A���ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�ǂ�����M�����F��B�^��n�񐯂ł���B���]������", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"1.57���ŁA�킸���ɑ��z���a��15�{��������Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"����ɉ�����+12.2�����̈Â�������������ΐ�B��", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"���]���Ă���B�n�����猩��50�b�قǗ���A���Ȃ��Ƃ�", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"7000�V���P�ʂ̌��]�O���ł���ƍl�����Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[�ڐG�A���Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
			}
			else if (page == 1)//���ς����炱�����ς���
			{
				//7�s�܂�
				ver = 0;
				Font::StrDraw(L"�P���Ԃ̋������߂����ĕ\�ʂ��ڐG���Ă��邩�A���邢��", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�Z�����ăK�X�̊O�w�����L���Ă���悤�ȘA���ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[�A���Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"2�̍P�������҂̏d�S�̎�����O���^�����Ă���V��", left_end, IO_y + Interval_y * ver, font_size, c);
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

		//					�@�@	 X�@ Y�@ �傫��
		Font::StrDraw(L"�C�N���[��", 30 + fy * std, 360 + t * l, 30, c);
		l++;
		// left								right						top							�@�@�@bottom               
		if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
		{
			if (m_mou_l == true)
			{
				pagemax = 1;
				crick = 12;//�����̓L�[�̂悤�Ȃ���
				page = 0; //�y�[�W������
			}
		}
		if (crick == 12)
		{
			if (page == 0)//���ς����炱�����ς���
			{
				ver = 0;
				Font::StrDraw(L"��������̍P����4�����B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"B�^�̃X�y�N�g�������������ł���启A�Ɩ�40�b���ꂽ", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�ʒu�Ɍ����锺��B�̓�d���ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�启A�́A���ꎩ�̂������A���ł��邪�A���܂��2�̐���", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�߂��ɂ��邽�ߏڍׂ͂킩���Ă��Ȃ��B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[��d���Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"����[����299.792.458����1�b�Ԃɐi�ދ���]�ƒ�`����Ă�", left_end, IO_y + Interval_y * ver, font_size, c);

			}
			else if (page == 1)//���ς����炱�����ς���
			{
				ver = 0;
				Font::StrDraw(L"��̂ŁA1���b�͐��m�� 299.792.458 m �ƂȂ�B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[�����A���Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�ω��ɂ����2�ȏ�̓V�̂���Ȃ邱�Ƃ����o�ł���", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�A���̂��ƁB", left_end, IO_y + Interval_y * ver, font_size, c);
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
		t -= 4;
		l -= 4;
		std++;//�l����\��������std������
		Font::StrDraw(L"�A���E�j���g", 10 + fy * std, 330 + t * l, 30, c);
		l++;

		if (start_flag == true)
		{
			// left								right						top						bottom               
			if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
			{
				if (m_mou_l == true)
				{
					crick = 13;//�����̓L�[�̂悤�Ȃ���
					page = 0; //�y�[�W������
				}
			}
		}
		if (crick == 13)
		{
			if (page == 0)//���ς����炱�����ς���
			{
				ver = 0;
				Font::StrDraw(L"��������ɂ���P����3�����B�n������̋�����696���N", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�i214�p�[�Z�N�j�Ɛ��肳��Ă���B�P���n�̎启��", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"��d���̕����A���ł���]�����ł͉𑜂ł��Ȃ��B33.01����", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�O�������ŋO�����S����0.32�Ɛ��肳��Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�ŗL���̃A���E�j���g�́A�A���r�A��Łu�����v���痈�Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[���N�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"��Ƃ��ēV���w�ŗp�����鋗���i�����j�̒P�ʂł���", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"��9.5���L�����[�g���ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
			}
			else if (page == 1)//���ς����炱�����ς���
			{

				//7�s�܂�
				ver = 0;
				Font::StrDraw(L"[�p�[�Z�N�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"������\���v�ʒP�ʂł���A��3.26���N�ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"��Ƃ��ēV���w�Ŏg����B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[�����A��(�Ԃ񂱂���񂹂�)�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�]�������g�p���ĕ����ł��Ȃ��Ƃ��A�����I�ȃX�y�N�g������", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�ړ���p���X�����̕ϓ��ȂǁA�X�y�N�g���̓����̎����I��", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�ω��ɂ����2�ȏ�̓V�̂���Ȃ邱�Ƃ����o�ł���", left_end, IO_y + Interval_y * ver, font_size, c);
			}
			else if (page == 2)//���ς����炱�����ς���
			{
				//7�s�܂�
				ver = 0;
				Font::StrDraw(L"�A���̂��ƁB", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[�O�����S��(���ǂ��肵����)�Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�V�̂̋O���̐�ΓI�Ȍ`�����߂�d�v�ȃp�����[�^�ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�O�����S���́A���̌`���ǂꂾ���~���痣��Ă��邩��\���l", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�ł���ƌ��������ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
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
		//					�@�@	 X�@		    Y�@ �傫��
		Font::StrDraw(L"���T�g", 30 + fy * std, 340 + t * l, 30, c);
		l++;

		if (start_flag == true)
		{
			// left								right						top								�@bottom                            
			if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
			{
				if (m_mou_l == true)
				{
					crick = 14;//�����̓L�[�̂悤�Ȃ���
					page = 0; //�y�[�W������
				}
			}
		}

		if (crick == 14) {
			if (page == 0)//���ς����炱�����ς���
			{
				ver = 0;
				Font::StrDraw(L"��������̍P����3�����B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�V���E���Ɠ���ł��������d���ƂȂ��Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"������2�̐���180���N����Ă���A�A���ł͂Ȃ��B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"���z���ʂ�10�{�̎��ʂƂ������V���������N���������F�␯��", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�Ȃ邩�̋��ł��邪�A�_�f�A�l�I���A�}�O�l�V�E��������", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�\�����ꂽ���Ɏ��ʂ̑傫�Ȕ��F�␯�ɂȂ���̂�", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�l�����Ă���B", left_end, IO_y + Interval_y * ver, font_size, c);
			}
			else if (page == 1)//���ς����炱�����ς���
			{

				//7�s�܂�
				ver = 0;
				Font::StrDraw(L"[��d���Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�n���ォ�猩��P�������������ɋߐڂ��Č����镨���w���B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[�A���Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"2�̍P�������҂̏d�S�̎�����O���^�����Ă���V�̂ł���B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"[���V�������Ƃ́H]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�县�ʂ̍P�����A���̈ꐶ���I����Ƃ��ɋN������K�͂Ȕ���", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"���ۂł���B", left_end, IO_y + Interval_y * ver, font_size, c);
			}
			else if (page == 2)//���ς����炱�����ς���
			{
				ver = 0;
				Font::StrDraw(L"[���F�␯�Ƃ́H]", left_end, Interval_y*ver, font_size, c);
				ver++;
				Font::StrDraw(L"�P�����i���̏I�����ɂƂ肤��`�Ԃ̈�B���ʂ͑��z�Ɠ��� ", left_end, Interval_y*ver, font_size, c);
				ver++;
				Font::StrDraw(L"�x���琔����1���x�Ƒ傫�����A���a�͒n���Ɠ����x������", left_end, Interval_y*ver, font_size, c);
				ver++;
				Font::StrDraw(L"�������炢�ɏk�����Ă���A���ɍ����x�̓V�̂ł���B", left_end, Interval_y*ver, font_size, c);
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


		//					�@�@	 X�@ Y�@ �傫��
		Font::StrDraw(L"�t���G", 30 + fy * std, 360 + t * l, 30, c);
		l++;

		if (start_flag == true)
		{
			// left								right						top							�@�@�@bottom               
			if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
			{
				if (m_mou_l == true)
				{
					crick = 15;//�����̓L�[�̂悤�Ȃ���
					page = 0; //�y�[�W������
				}
			}
		}


		if (crick == 15)//���ς����炱�����ς���
		{
			ver = VER_start; //�����Ԋu������
			page_max = 2; //�ő�y�[�W��

			//�y�[�W���\��
			swprintf_s(strp, L"�y�[�W��%d/%d", page + 1, page_max);
			Font::StrDraw(strp, pagex, pagey, pagesize, c);

			if (page == 0)
			{
				Font::StrDraw(L"��������̍P����3�����B���̐��͞�F�̋����ł���B�����ł�", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"��\���h�̂P�u���h�v�ɂ��鐯����1�u�����v�Ƃ����B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"2017�N6��30���A���ۓV���w�A���̍P���̖����Ɋւ���", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"���[�L���O�O���[�v (WGSN) �́A�������G���̌ŗL��", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�Ƃ��āAFuyue �𐳎��ɏ��F�����B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�ڂ����񂫂傤���ł̓����A��������̖��̂Ȃ��̐��Ƃ���", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�����Ă����B�ŏI�I�ɂ������G���ƌĂ΂��悤�ɂȂ����B", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
			}
			else if (page == 1)
			{
				//8�s�܂�
				Font::StrDraw(L"[�����Ƃ�]", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�����\�ʉ��x������n�񐯂������a����і��邳������", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"�傫���P���̂��Ƃł���B�T�^�I�ɂ́A�����̔��a��", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"���z��10�{����100�{�A���邳��10�{����1000�{��", left_end, IO_y + Interval_y * ver, font_size, c);
				ver++;
				Font::StrDraw(L"����B", left_end, IO_y + Interval_y * ver, font_size, c);
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

		swprintf_s(see, L"���݃y�[�W��%d/�I���y�[�W��%d", page, pagemax);
		Font::StrDraw(see, 530, 5, 18, c);


	}
}