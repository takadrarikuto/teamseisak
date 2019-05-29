//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include "GameL\UserData.h"
#include "GameL\Audio.h"

#include"GameHead.h"
#include"ObjGamekuria.h"
#include"ObjFirstStar.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;
extern int star_count;
extern int FiStar_Reco; //1���������̐�������
extern int SeStar_Reco; //2���������̐�������
extern int ThStar_Reco; //3���������̐�������


//�C�j�V�����C�Y
void CObjGameKuria::Init()
{
	m_mous_l = false;
	m_start_flag = false;

	a_time = 0;
	time_flag = false;

	m_mou_time = 0.0f;

	Audio::LoadAudio(1, L"���ʉ�.wav", EFFECT);
}

//�A�N�V����
void CObjGameKuria::Action()
{
	m_mous_l = Input::GetMouButtonL();

	//���J�E���g�n������
	star_count = 0;
	FiStar_Reco = 0;
	SeStar_Reco = 0;
	ThStar_Reco = 0;

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
	if (a_time == 10)
	{
		a_time = 0;
		m_mou_time = 0.0f;
		time_flag = false;
		Scene::SetScene(new CSceneTitle());
	}
	else if (a_time == 1)
	{
		Audio::Start(1);
	}

}
//�h���[
void CObjGameKuria::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 750.0f;
	src.m_bottom = 600.0f;


	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	//�`��
	Draw::Draw(11, &src, &dst, c, 0.0f);
}
