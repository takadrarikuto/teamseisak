//GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "CObjStarPicbook.h"
#include "GameHead.h"

void CObjStarPicbook::Init()
{
	
}

void CObjStarPicbook::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	
}

void CObjStarPicbook::Draw()
{
	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 300.0f;
	src.m_bottom = 461.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 300.0f;
	dst.m_left = 0.0f;
	dst.m_right = 100.0f;
	dst.m_bottom = 600.0f;

	//���̖��O��`��
	for (int i = 0; i = 6; i++)
	{
		dst.m_left = dst.m_right +0.0f;
		dst.m_right = dst.m_right +100.0f;
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}

	//�}�E�X�̈ʒu�ƃN���b�N����ꏊ�œ����蔻��
	if (m_mou_x > 230 && m_mou_x < 450 && m_mou_y>400 && m_mou_y < 430)
	{
	Font::StrDraw(L"��test", 230, 400, 30, c);
	}

	//�؂���ʒu�̐ݒ�
	src.m_top = 1.9f;
	src.m_left = 0.0f;
	src.m_right = 300.0f;
	src.m_bottom = 28.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 300.0f;

	//��������`��
	Draw::Draw(9, &src, &dst, c, 0.0f);

	//���}�E�X�ʒu�\��
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 20, 20, 12, c);


}