//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjStarPresent2.h"
extern int lever;


void CObjStarPresent2::Init()
{

}

void CObjStarPresent2::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();
}

void CObjStarPresent2::Draw()
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