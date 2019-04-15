//GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"


#include "CObjStarPicbook.h"
#include "GameHead.h"
extern int lever;

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
	
	//���[�v���ĕ`�悷��
	for (int i = 0; i <= 7; i++)
	{
		//���̖��O�̘g��`��
			Draw::Draw(9, &src, &dst, c, 0.0f);
			dst.m_left = dst.m_right + 0.0f;
			dst.m_right = dst.m_right + 100.0f;
	}

	//�؂���ʒu�̐ݒ�
	src.m_top = 1.9f;
	src.m_left = 0.0f;
	src.m_right = 300.0f;
	src.m_bottom = 28.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 700.0f;
	dst.m_bottom = 300.0f;

	//��������`��
	Draw::Draw(9, &src, &dst, c, 0.0f);

	//�}�E�X�̈ʒu�ƃN���b�N����ꏊ�œ����蔻��
	
	//�؂���ʒu�̐ݒ�
	src.m_top = 1.5f;
	src.m_left = 0.0f;
	src.m_right = 300.0f;
	src.m_bottom = 28.0f;

	//�߂�{�^���̘g��`��
	dst.m_top = 0.0f;
	dst.m_left = 5.0f;
	dst.m_right = 110.0f;
	dst.m_bottom = 50.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);

	//�����ɑ����邩�̘g��`��
	dst.m_top = 50.0f;
	dst.m_left = 5.0f;
	dst.m_right = 110.0f;
	dst.m_bottom = 300.0f;
    Draw::Draw(9, &src, &dst, c, 0.0f);
	
	//�؂���ʒu�̐ݒ�
	src.m_top =0.0f;
	src.m_left = 5.0f;
	src.m_right = 202.0f;
	src.m_bottom = 470.0f;

	//���̃y�[�W�ɍs�����߂̃{�^���̘g��`��
	dst.m_top = 0.0f;
	dst.m_left = 700.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 150.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);
	dst.m_top = 140.0f;
	dst.m_bottom = 300.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);
	//					�@�@X�@Y�@�傫��
	Font::StrDraw(L"�߂�", 10, 0, 50, c);
	
	//�߂�{�^��
	// left				 right            top            bottom         
	if (m_mou_x > 5 && m_mou_x < 110 && m_mou_y>0 && m_mou_y <50)
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
		int l = 50;
		swprintf_s(str, L"%s", next[i]);
		//				�@�@X�@ Y�@ �傫��
		Font::StrDraw(str, 720, 25 + l*i, 50, c);
	}

	//���ւ���������StarPresent2�ɐ؂�ւ���
	// left				 right            top            bottom       
	if (m_mou_x > 700 && m_mou_x < 800 && m_mou_y>0 && m_mou_y <140)
	{
		if (m_mou_l == true)
		{
			lever = 1;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}

	//�߂��̕��������[�v���ďo��
	wchar_t before[2][2]{ L"��",L"��" };
	for (int i = 0; i <= 1; i++)
	{
		int l = 50;
		swprintf_s(str, L"%s", before[i]);

		//				�@�@X�@ Y�@ �傫��
		Font::StrDraw(str, 720, 160 + l*i, 50, c);
	}
	//���ւ���������StarPresent�ɐ؂�ւ���
	// left				 right            top            bottom       
	if (m_mou_x > 700 && m_mou_x < 800 && m_mou_y>150 && m_mou_y <300)
	{
		if (m_mou_l == true)
		{
			lever = 0;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}

}