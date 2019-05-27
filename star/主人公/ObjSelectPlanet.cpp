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
	m_start_flag = false;
	time_back = 0;
}

//�A�N�V����
void CObjSelectPlanet::Action()
{
	m_mous_l = Input::GetMouButtonL();

	//�}�E�X�̈ʒu�̎擾
	m_mous_x = (float)Input::GetPosX();
	m_mous_y = (float)Input::GetPosY();

	time_back++;

	if (m_mous_x > 60 && m_mous_x < 190 && m_mous_y>130 && m_mous_y < 325)
	{
		if (m_mous_l == true)
		{
			if (m_start_flag == true)
			{
				Scene::SetScene(new CSceneMars()); //�ΐ�
			}
		}
	}
	if (m_mous_x > 230 && m_mous_x < 379 && m_mous_y>180 && m_mous_y < 330)
	{
		if (m_mous_l == true)
		{
			if (m_start_flag == true)
			{
				Scene::SetScene(new CSceneVenus()); //����
			}
		}
	}
	if (m_mous_x > 422 && m_mous_x < 542 && m_mous_y>135 && m_mous_y < 325)
	{
		if (m_mous_l == true)
		{
			if (m_start_flag == true)
			{
				Scene::SetScene(new CSceneJupiter()); //�ؐ�
			}
		}
	}
	if (m_mous_x > 585 && m_mous_x < 722 && m_mous_y>135 && m_mous_y < 325)
	{
		if (m_mous_l == true)
		{
			if (m_start_flag == true)
			{
				Scene::SetScene(new CSceneSaturn()); //�y��
			}
		}
	}
	else
	{
		m_start_flag = true;
	}

	if (m_mous_x > 600 && m_mous_y > 550)
	{
		if (m_mous_l == true)
		{
			if (m_start_flag == true)
			{
				Scene::SetScene(new CSceneStarPicbook()); //���}��
			}
		}
	}
	else
	{
		m_start_flag = true;
	}


	if (time_back > 30)
	{
		//b�������ƃ^�C�g����ʂɈړ�
		if (Input::GetVKey('B') == true)
		{
			if (m_start_flag == true)
			{
				Scene::SetScene(new CSceneTitle());
			}
			else
			{
				m_start_flag = true;
			}
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
	swprintf_s(str, L"x=%d,y=%d", (int)m_mous_x,(int) m_mous_y);
	Font::StrDraw(str, 10, 20, 30, c);
	Font::StrDraw(L"���}�ӂ�", 600, 550, 50, c);
	Font::StrDraw(L"�ǂ̐��֍s���܂����H", 150, 120, 50, c);
	Font::StrDraw(L"�ΐ�", 100, 370, 30, c);
	Font::StrDraw(L"����", 280, 370, 30, c);
	Font::StrDraw(L"�ؐ�", 460, 370, 30, c);
	Font::StrDraw(L"�y��", 640, 370, 30, c);

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̈ʒu
	src.m_top = 30.0;
	src.m_left = 70.0f;
	src.m_right = 1000.0f;
	src.m_bottom = 250.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 170.0f;
	dst.m_left = 70.0f;
	dst.m_right = 760.0f;
	dst.m_bottom = 370.0f;

	Draw::Draw(12, &src, &dst, c, 0.0f);
}