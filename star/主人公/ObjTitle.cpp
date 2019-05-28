//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"


#include "GameHead.h"
#include "ObjTitle.h"
#include "SceneStageselect.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTitle::Init()
{
	m_mous_l = false;
	m_start_flag = false;
	m_mous_x = 0.0f;
	m_mous_y = 0.0f;
	a_time = 0;
	time_flag = false;

	
	Audio::LoadAudio(1, L"���ʉ�.wav", EFFECT);
}

//�A�N�V����
void CObjTitle::Action()
{
	m_mous_l = Input::GetMouButtonL();

	//�}�E�X�̈ʒu�̎擾
	m_mous_x = (float)Input::GetPosX();
	m_mous_y = (float)Input::GetPosY();

	if (m_mous_x > 307 && m_mous_x < 480 && m_mous_y>440 && m_mous_y < 480)
	{
		if (m_mous_l == true)
		{

			time_flag = true;
			
		}
	}

	if (time_flag == true)
	{
		a_time++;
	}

	//10�b��ɉ�ʈړ�
	if (a_time == 10)
	{
		a_time = 0;
		Scene::SetScene(new CSceneOperation()); //��������I����ʂɈړ�
		
	}
	else if (a_time ==1)
	{
		
		
		Audio::Start(1);
	}

}

//�h���[
void CObjTitle::Draw()
{

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,100.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̈ʒu
	src.m_top = 0.0;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(11, &src, &dst, c, 0.0f);

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 130.0f;
	src.m_bottom = 67.0f;

	//���}�ӂ̘g��`��
	dst.m_top = 440.0f;
	dst.m_left = 307.0f;
	dst.m_right = 480.0f;
	dst.m_bottom =480.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);

}