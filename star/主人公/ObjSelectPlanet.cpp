//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjSelectPlanet.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjSelectPlanet::Init()
{
	m_mous_l = false;
	m_mous_x = 0.0f;
	m_mous_y = 0.0f;
}

//�A�N�V����
void CObjSelectPlanet::Action()
{
	m_mous_l = Input::GetMouButtonL();

	//�}�E�X�̈ʒu�̎擾
	m_mous_x = (float)Input::GetPosX();
	m_mous_y = (float)Input::GetPosY();

	if (m_mous_x > 50 && m_mous_x < 190 && m_mous_y>115 && m_mous_y < 335)
	{
		if (m_mous_l == true)
		{
			if (m_start_flag == true)
			{
				Scene::SetScene(new CSceneMar());
			}
		}
		else
		{
			m_start_flag = true;
		}
	}

}

//�h���[
void CObjSelectPlanet::Draw()
{

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//���}�E�X�ʒu
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mous_x, m_mous_y);
	Font::StrDraw(str, 20, 20, 30, c);

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̈ʒu
	src.m_top = 30.0;
	src.m_left = 70.0f;
	src.m_right = 1000.0f;
	src.m_bottom = 250.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 100.0f;
	dst.m_left = 60.0f;
	dst.m_right = 760.0f;
	dst.m_bottom = 400.0f;

	Draw::Draw(12, &src, &dst, c, 0.0f);
}