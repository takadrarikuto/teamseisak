//GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include"GameL\SceneObjManager.h"
#include "GameL\Audio.h"
#include "CObjOperation.h"
#include "GameHead.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

void CObjOperation::Init()
{
	m_mous_l = false;
	m_start_flag = false;
	m_mous_x = 0.0f;
	m_mous_y = 0.0f;

	a_time = 0;
	time_flag = false;

	Back_time = 0.0f;

	m_mou_time = 0.0f;

	Audio::LoadAudio(1, L"���ʉ�.wav", EFFECT);
}


void CObjOperation::Action()
{
	
	m_mous_l = Input::GetMouButtonL();

	//�}�E�X�̈ʒu�̎擾
	m_mous_x = (float)Input::GetPosX();
	m_mous_y = (float)Input::GetPosY();

	//�A���ړ��h�~
	if (m_mou_time == 60.0f)
	{
		;
	}
	else if (m_mou_time < 60.0f)
	{
		m_mou_time++;
		m_mous_l = false;
	}

	if (m_mous_l == true)
	{
		time_flag = true;
	}

		
	if (time_flag == true)
	{
		a_time++;
	}


	//10�b��ɉ�ʈړ�
	if (a_time == 10)
	{
		a_time = 0;
		Back_time = 0.0f;
		m_mou_time = 0.0f;
		time_flag = false;
		Scene::SetScene(new CSceneStageselect()); //��������I����ʂɈړ�

	}
	else if (a_time == 1)
	{
		Audio::Start(1);
	}

	Back_time++;

	//�^�C�g���֖߂�
	if (Input::GetVKey('B') == true && Back_time > 60.0f)
	{
		a_time = 0;
		Back_time = 0.0f;
		m_mou_time = 0.0f;
		time_flag = false;
		Scene::SetScene(new CSceneTitle()); //��������I����ʂɈړ�
	}
}

void CObjOperation::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̈ʒu
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(17, &src, &dst, c, 0.0f);

}
