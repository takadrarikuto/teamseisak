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
	 page = 0;
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

	// left								right						top								�@bottom                            
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
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
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
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
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{

			crick = 5;//�����̓L�[�̂悤�Ȃ���
		}
	}

	if (crick == 5)//���ς����炱�����ς���
	{
		ver = 0;
		Font::StrDraw(L"�����F�̋P�����B2������A����6������B���̓�d���ł���B ", left_end, Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"[�P�����Ƃ́H]", left_end, Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�P�����́A�񓙐��قǂ̖��邳�����P���ł���B������ ", left_end, Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�������璴�����ɂ܂�����傫���ł��邪�A�ʏ�͒�������", left_end, Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�ǖ��邭�d���킯�ł͂Ȃ��A�ɂ߂Ė��邢�����ɕ��ނ����B", left_end, Interval_y * ver, font_size, c);


	}

	//					�@�@	 X�@		    Y�@ �傫��
	Font::StrDraw(L"�M���^�u", 30 + fy * std, 330 + t * l, 30, c);
	l++;

	// left								right						top								�@bottom                            
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 6;//�����̓L�[�̂悤�Ȃ���
		}
	}

	if (crick == 6)//���ς����炱�����ς���
	{
		ver = 0;
		Font::StrDraw(L"���̍P���͕����A���ŁA�启�̓P�t�F�E�X�����^�ό����ł���B", left_end, Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"�����ϑ��ɂ��A���]������195���Ƒ��肳�ꂽ�B", left_end, Interval_y * ver, font_size, c);
		ver++;
		Font::StrDraw(L"���邳�̕ω��́A4.80���ԁA4.93���Ԃł���B", left_end, Interval_y * ver, font_size, c);

	}

	//					�@�@	 X�@ Y�@ �傫��
	Font::StrDraw(L"�V���E��", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	// left								right						top							�@�@�@bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			page = 0;
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
		ver=0;
		Font::StrDraw(L"�[�~�f�B���� �́A�A�t���J�嗤�암�ɏZ�ރR�C�R�C�l�̌��t��", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�u���C�I���̊�v���Ӗ����� �[�� �f �����ɗR������", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�s�s���}�Ƃ͓�d���̊֌W�炵��", left_end, Interval_y*ver, font_size, c);

	}

	t -= 4;
	l -= 4;
	std++;//�l����\��������std������
	Font::StrDraw(L"�s�s���}", 30 + fy * std, 330 + t * l, 30, c);
	l++;

	// left								right						top						bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 9;//�����̓L�[�̂悤�Ȃ���
		}
	}

	if (crick == 9)//���ς����炱�����ς���
	{
		ver = 0;
		Font::StrDraw(L"�s�s���} �́A�^�q�`�̓`���ɓo�ꂷ��o�q�̒j���ɗR������", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�[�~�f�B�����Ƃ͓�d���̊֌W�炵��", left_end, Interval_y*ver, font_size, c);
	}

	Font::StrDraw(L"�W���o�n�[", 30 + fy * std, 340 + t * l, 30, c);
	l++;
	// left								right						top						bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{

			crick = 10;//�����̓L�[�̂悤�Ȃ���
		}
	}

	if (crick == 10)//���ς����炱�����ς���
	{
		ver = 0;
		Font::StrDraw(L"�W���o�n�[�́A�n�����猩�Ă�������̕����ɖ�500���N��", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�ꂽ�ʒu�ɂ���A4�����̍P���ł���B", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"7�̍P�����琬�鎵�d�A���n�ł���B�����_�Ŕ��������", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"���鎵�d�A���n�́A���ɂ̓J�V�I�y����AR�������Ȃ��B", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"", left_end, Interval_y*ver, font_size, c);

	}

	//					�@�@	 X�@		    Y�@ �傫��
	Font::StrDraw(L"�t�@���O", 30 + fy * std, 350 + t * l, 30, c);
	l++;

	// left								right						top								�@bottom                            
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 11;//�����̓L�[�̂悤�Ȃ���
		}
	}

	if (crick == 11)//���ς����炱�����ς���
	{
		ver = 0;
		Font::StrDraw(L"���̐��͎O�d���ł���B��������ΐ�A�͂��ƍ����^�ό���", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�̐ڐG�A���ł���B�ǂ�����M�����F��B�^��n�񐯂ł�", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"��B", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"[�ڐG�A���Ƃ́H]", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�ڐG�A���́A�P���Ԃ̋������߂����ĕ\�ʂ��ڐG���Ă��邩�A", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"���邢�͗Z�����ăK�X�̊O�w�����L���Ă���悤�ȘA���ł�", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"��B�O�w�����L����A���̂��Ƃ́A���ɉߏ�ڐG�A���Ƃ����B", left_end, Interval_y*ver, font_size, c);
	}

	//					�@�@	 X�@ Y�@ �傫��
	Font::StrDraw(L"�C�N���[��", 30 + fy * std, 360 + t * l, 30, c);
	l++;
	// left								right						top							�@�@�@bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 12;//�����̓L�[�̂悤�Ȃ���
		}
	}

	if (crick == 12&&page==0)//���ς����炱�����ς���
	{
		ver = 0;
		Font::StrDraw(L"A�Ɩ�40�b���ꂽ�ʒu�Ɍ����锺��B�̓�d���ł���B ", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"B�^�̃X�y�N�g�������������ł���启A�́A����", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"���̂������A���ł��邪�A���܂��2�̐����߂�", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�ɂ��邽�ߏڍׂ͂킩���Ă��Ȃ��B", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"[���b�Ƃ́H]", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"1���b�͌��i�d���g�j��1�b�Ԃɐi�ދ����ƒ�`�����B���[�g ", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"����[����299.792.458����1�b�Ԃɐi�ދ���]�ƒ�`����Ă�", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"��̂ŁA1���b�͐��m�� 299.792.458 m �ƂȂ�B", left_end, Interval_y*ver, font_size, c);
		


	}
	else if (crick == 12 && page == 1)
	{
		ver=0;
		Font::StrDraw(L"[�����A���Ƃ�]", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�]�������g�p���ĕ����ł��Ȃ��Ƃ��A�l�X�ȕω��̊ϑ��ɂ��", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"��2�ȏ�̓V�̂���Ȃ邱�Ƃ����o�ł���A���̂��ƁB", left_end, Interval_y*ver, font_size, c);
	}



	t -= 4;
	l -= 4;
	std++;//�l����\��������std������
	Font::StrDraw(L"�A���E�j���g", 10 + fy * std, 330 + t * l, 30, c);
	l++;
	// left								right						top						bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 13;//�����̓L�[�̂悤�Ȃ���
		}
	}

	if (crick == 13)//���ς����炱�����ς���
	{
		ver = 0;
		Font::StrDraw(L"�q�b�p���R�X�ɂ�鎋���̑�����A�n������̋�����696��", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�N�Ɛ��肳��Ă���B�P���n�̎启�́A��d���̕����A����", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"����A�]�����ł͉𑜂ł��Ȃ��B", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"[�q�b�p���R�X�Ƃ́H]", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"���̉q���́A�P���̈ʒu���C�̉e���̖����F����ԂŐ���", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�ɑ��肷�邱�Ƃ���ȃ~�b�V�����ł������B", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"", left_end, Interval_y*ver, font_size, c);

	}

	//					�@�@	 X�@		    Y�@ �傫��
	Font::StrDraw(L"���T�g", 30 + fy * std, 340 + t * l, 30, c);
	l++;

	// left								right						top								�@bottom                            
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 14;//�����̓L�[�̂悤�Ȃ���
		}
	}

	if (crick == 14)//���ς����炱�����ς���
	{
		ver = 0;
		Font::StrDraw(L"�V���E���Ɠ���ł��������d���ƂȂ��Ă���B", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"������2�̐���180���N����Ă���A�A���ł͂Ȃ��B", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"���z�̎��ʂ�10�{�̎��ʂƂ������V���������N���������F�␯ ", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�ƂȂ邩�̋��ł��邪�A�_�f�A�l�I���A�}�O�l�V�E�������ō\", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"�����ꂽ���Ɏ��ʂ̑傫�Ȕ��F�␯�ɂȂ���̂ƍl������", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"����B", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"[]", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"", left_end, Interval_y*ver, font_size, c);
		ver++;
		Font::StrDraw(L"", left_end, Interval_y*ver, font_size, c);

	}

	//					�@�@	 X�@ Y�@ �傫��
	Font::StrDraw(L"�t���G", 30 + fy * std, 360 + t * l, 30, c);
	l++;
	// left								right						top							�@�@�@bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
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
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b * (std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
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

	swprintf_s(see, L"%d", page);
	Font::StrDraw(see, 600, 20, 30, c);
}