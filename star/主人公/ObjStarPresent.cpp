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
	
	int g = 200.0f;//���g�̉���
	int k = 75.0f;//���g�̗���
	int t = 70;//���̖��O�̈ʒu
	int l = 0;//t�Ɗ|����p�̕ϐ�
	int s = 0;//���̃N���b�N�̌�
	int std = 0;
	int side_a = 0;//���̘g�͈�
	int side_b = 200;//�E�̘g�͈�
	int fy = 200;//���̖��O�̉���
	int key = 0;

	//���[�v���ĕ`�悷��
	for (int i = 0; i <= 3; i++)
	{
	//���̖��O�̘g��`��
	dst.m_top = 300.0f;
	dst.m_left = 0.0f +g*i;
	dst.m_right = 200.0f + g*i;
	dst.m_bottom = 300.0f+k;
	Draw::Draw(1, &src, &dst, c, 0.0f);

	for (int l = 0; l <=2; l++)
	{
		
		dst.m_top = 375.0f+k*l;
		dst.m_bottom =450.0f+k*l;
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

	//�F���D�փ{�^��
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
	
	//					�@�@	 X�@		    Y�@ �傫��
	Font::StrDraw(L"�A���^���X", 30 + fy * std, 330+t*l, 30, c);
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
		Font::StrDraw(L"��������ɑ�����", 110, 0, 30, c);
		Font::StrDraw(L"��Ԗ��邢��", 110, 50, 30, c);
		
		
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
		Font::StrDraw(L"��������ɑ�����", 110, 0, 30, c);
		Font::StrDraw(L"�Z�d�A���ŁA���^�]������3�����̃�1����5�����̃�2����2���Ɍ�����B", 110, 50, 30, c);
		Font::StrDraw(L"��2���̓���C�ƃ���E����`������A����Ƀ���E�̓���Ea�ƃ���Eb����`�������", 110, 100, 30, c);
		
	}
	
	Font::StrDraw(L"�W���o", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	// left								right						top						bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{

			crick = 3;//�����̓L�[�̂悤�Ȃ���
		
		}
	}

	if (crick == 3)//���ς����炱�����ς���
	{
		Font::StrDraw(L"��������ɑ�����", 110, 0, 30, c);
		Font::StrDraw(L"�ʏ��B�^�̍P���ƍl�����Ă������A2000�N6�����ɑ������A", 110,50, 30, c);
		Font::StrDraw(L"���̃X�y�N�g����Be���̂��̂ւƕϖe�������Ƃ��ϑ����ꂽ�B", 110, 100, 30, c);
		
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
		Font::StrDraw(L"��������ɑ�����", 110, 0, 30, c);
		Font::StrDraw(L"���邢���ł���Ȃ��璷�炭�m��ꂽ�ŗL�����Ȃ��������Ƃ���A�p�g���b�N�E���[�A�ɂ���āA�Ɛ��A�ɐ��A�Ґ�����������ߕӂ�", 110, 50, 30, c);
		Font::StrDraw(L"���ō\������钆���̓�\���h����h�̖��O�ɂ��Ȃ�ŁA������Łu���v�Ƃ����Ӗ���Wei�Ɩ��Â���ꂽ���Ƃ�����B ", 110,100, 30, c);
		
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
		Font::StrDraw(L"��������ɑ�����", 110, 0, 30, c);
		Font::StrDraw(L"�ʖ��̃M���^�u (Girtab) �́A�V�����[���Ŏg��ꂽ�T�\����͂������� GIR.TAB �ɗR������B����͂�������Ȑ��Ȃǂɂ��g���Ă���B", 110, 50, 30, c);
		Font::StrDraw(L" ", 110, 100, 30, c);
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
		Font::StrDraw(L"���̍P���͕����A���ŁA�启�̓P�t�F�E�X�����^�ό����ł���B", 110, 0, 30, c);
		Font::StrDraw(L"�����ϑ��ɂ��A���]������195���Ƒ��肳�ꂽ�B", 110, 50, 30, c);
		Font::StrDraw(L"���邳�̕ω��́A4.80���ԁA4.93���Ԃł���B", 110, 100, 30, c);

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

	if (crick == 7)//���ς����炱�����ς���
	{
		int test=0;
		Font::StrDraw(L"���F�̏������B ", 110, 0*test, 30, c);
		test++;
		Font::StrDraw(L"�P�t�F�E�X�����^�ό����ł���A�킸���ɕό����邪�A�ό��͈͂��������̂Ŋᎋ�ϑ��ł͂��̕ό��͂킩��Ȃ��B", 110, 50*test, 30, c);

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