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
}

//�A�N�V����
void CObjTitle::Action()
{
	m_mous_l = Input::GetMouButtonL();

	//�}�E�X�̈ʒu�̎擾
	m_mous_x = (float)Input::GetPosX();
	m_mous_y = (float)Input::GetPosY();

	if (m_mous_x > 270 && m_mous_x < 430 && m_mous_y>500 && m_mous_y < 550)
	{
		if (m_mous_l == true)
		{
			time_flag = true;
				//Audio::Start(1);
				//a_time++;
				//300�b��ɉ�ʈړ�
				
				//if(a_time<=300){
			Scene::SetScene(new CSceneStageselect()); //��������I����ʂɈړ�
					
				//}
			
		}
	}

	if (time_flag == true)
	{
		a_time++;
	}

	if (a_time == 100)
	{
		Scene::SetScene(new CSceneStageselect()); //��������I����ʂɈړ�
	}
	else if (a_time == 1)
	{
		//Audio::Start(1);
	}
	else
	{
		//Audio::Stop(1);
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
	src.m_right = 1280.0f;
	src.m_bottom = 907.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 800.0f;

	Draw::Draw(11, &src, &dst, c, 0.0f);

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 130.0f;
	src.m_bottom = 67.0f;

	//���}�ӂ̘g��`��
	dst.m_top = 500.0f;
	dst.m_left = 270.0f;
	dst.m_right = 430.0f;
	dst.m_bottom =550.0f;
	Draw::Draw(9, &src, &dst, c, 0.0f);

}