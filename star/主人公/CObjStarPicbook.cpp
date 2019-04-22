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

	//�J�[�\���\��(�������������)
	swprintf_s(strmous, L"x=%d,y=%d", (int)m_mou_r, (int)m_mou_l);
	Font::StrDraw(strmous, 600, 20, 30, c);


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
	dst.m_right = 67.0f;
	dst.m_bottom = 600.0f;

	//���[�v���ĕ`�悷��
	for (int i = 0; i <= 11; i++)
	{
		//���̖��O�̘g��`��
		Draw::Draw(1, &src, &dst, c, 0.0f);
		dst.m_left = dst.m_right + 0.0f;
		dst.m_right = dst.m_right + 67.0f;
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
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 215.0f;
	src.m_bottom = 240.0f;

	dst.m_top = 500.0f;
	dst.m_left = 0.0f;
	dst.m_right = 67.0f;
	dst.m_bottom = 600.0f;
	
	Draw::Draw(2, &src, &dst, c, 0.0f);
	
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

	int l = 50;
	int vx = 0;

	wchar_t test[2][2]{ L"�",L"��" };
	wchar_t test2[3][2]{ L"�V",L"��",L"��" };
		//���[�v���ďo��
		for (int i = 0; i <= 1; i++)
		{
			swprintf_s(str, L"%s", test[i]);

			//Y�͈��ڂ�i��0�Ȃ̂�0��50���|���Ă���
			//2��ڂ�i��1�Ȃ̂�50��100�ɑ����B
			//				�@�@X�@ Y�@ �傫��
			Font::StrDraw(str, 10 + vx, 350 + l * i, 50, c);

		}
		for (int i = 0; i <= 2; i++)
		{
			swprintf_s(str, L"%s", test2[i]);
			l = 100;
			vx = 265;
			//				�@�@X�@ Y�@ �傫��
			Font::StrDraw(str, 10 + vx, 320 + l * i, 50, c);
		}

		// left				 right            top            bottom       
		if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>300 && m_mou_y < 490)
		{
			if (m_mou_l == true)
			{			
				lever = 1;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}
		//嶍��͈̔�
		if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>500 && m_mou_y < 600)
		{
			if (m_mou_l == true)
			{
				lever = 11;
				Scene::SetScene(new CSceneStarPicbook());
			}
		}

}