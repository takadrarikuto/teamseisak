//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjStarPresent.h"
extern int lever;


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

	wchar_t test[3][2]{ L"��",L"��",L"��"};

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//					�@�@	 X�@ Y�@ �傫��
	Font::StrDraw(L"�A���f�o����", 10, 305, 15, c);

	// left				 right            top            bottom               
	if (m_mou_x > 0 && m_mou_x < 100 && m_mou_y>300 && m_mou_y <325)
	{
		Font::StrDraw(L"���������ɂɑ�����", 110, 0, 30, c);
		Font::StrDraw(L"��Ԗ��邢��", 110, 50, 30, c);
		//���[�v���ďo��
		for (int i = 0; i <=2; i++)
		{
			int l = 50;
			swprintf_s(str, L"%s", test[i]);
			//				�@�@X�@ Y�@ �傫��
			Font::StrDraw(str, 20, 100 + l*i, 50, c);
		}
	}

}