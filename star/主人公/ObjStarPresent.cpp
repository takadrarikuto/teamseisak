//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjStarPresent.h"
extern int lever;

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
	
	wchar_t test[2][2]{L"�",L"��"};

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu
	//					�@�@	 X�@ Y�@ �傫��
	Font::StrDraw(L"�A���^���X", 10, 305,15, c);

	// left				 right            top            bottom               
	if (m_mou_x > 0 && m_mou_x < 100 && m_mou_y>300 && m_mou_y <315)
	{
		Font::StrDraw(L"��������ɑ�����", 110, 0, 30, c);
		Font::StrDraw(L"��Ԗ��邢��", 110, 50, 30, c);
		//���[�v���ďo��
		for (int i = 0; i <= 1; i++)
		{
			int l = 50;
			swprintf_s(str, L"%s", test[i]);
			//Y�͈��ڂ�i��0�Ȃ̂�0��50���|���Ă���
			//2��ڂ�i��1�Ȃ̂�50��100�ɑ����B
			//				�@�@X�@ Y�@ �傫��
			Font::StrDraw(str, 20, 100+l*i, 50, c);
		}
	}

}