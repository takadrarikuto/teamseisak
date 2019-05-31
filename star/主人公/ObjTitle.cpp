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
	m_mous_x = 0.0f;
	m_mous_y = 0.0f;

	font_size = 30;//�����̑傫�� 30

	a_time = 0;
	time_flag = false;

	m_mou_time = 0.0f;
	
	Audio::LoadAudio(1, L"���ʉ�.wav", EFFECT);
}

//�A�N�V����
void CObjTitle::Action()
{
	//�}�E�X�̈ʒu�̎擾
	m_mous_x = (float)Input::GetPosX();
	m_mous_y = (float)Input::GetPosY();

	m_mous_l = Input::GetMouButtonL();

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
	else if (m_mous_l == false && a_time > 1)
	{
		time_flag = false;
		a_time++;
	}

	if (time_flag == true)
	{
		a_time++;
	}
	
	//10�b��ɉ�ʈړ�
	if (a_time == 5)
	{
		a_time = 0;
		m_mou_time = 0.0f;
		time_flag = false;
		Scene::SetScene(new CSceneOperation()); //��������I����ʂɈړ�	
	}
	else if (a_time == 1)
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
	src.m_right = 400.0f;
	src.m_bottom = 300.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(11, &src, &dst, c, 0.0f);

	float cs[4] = { 0.1f,0.1f,0.1f,1.0f };
	Font::StrDraw(L"PLEASE CLICK", 280, 500, font_size, cs);
}