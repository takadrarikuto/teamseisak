//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

#include"GameHead.h"
#include"Objstaminagauge.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

extern bool Event_on;
extern bool Aitem_on;
bool FiStar_Recovery = false;  //1�����m�ێ��_�f��
bool SeStar_Recovery = false;  //2�����m�ێ��_�f��
bool ThStar_Recovery = false;  //3�����m�ێ��_�f��
extern bool Aitem_co; //�A�C�e�����Y
extern int Event_Conversion; //�C�x���g�G���A�؂�ւ�

//�X�^�~�i���_�f�ύX

//�C�j�V�����C�Y
void CObjstaminagauge::Init()
{
	Aitem_flag = true; //�A�C�e���I�u�W�F�N�g������p������
	Aitem_co_max = 5;

	m_px = 697.0f;
	m_py = 571.0f;

	//�\���p�_�f������
	m_stamina = 100;

	//�_�f�ő�l������
	m_stamina_max = 100;

	//�S�Ă̏���p������
	m_vx = 0.0f;

	//���R�������
	m_vstamina = 0.0f;

	//�A���J�[�g�p���p������
	m_vancer = 0.0f;

	//�b���J�E���g������
	stamina_co = 0;
	//��ʈړ����N���h�~�p������
	time_co = 0;
	//�_�f����p������
	stamina_back = 0;

	//�C�x���g�J�E���g������
	Ev_time = 0;
}

//�A�N�V����
void CObjstaminagauge::Action()
{	
	time_co++;

	//�_�f��
	if (Aitem_on == true)
	{
		m_vx -= 100.0f; //�_�f��30���₷
		m_stamina += 100;
		Aitem_on = false;
	}
	
	//�̗͌�������
	stamina_co += 1;

	//5�b��1�_�f����
	if (stamina_co == 300)
	{
		m_vstamina += 1.0f;
		m_stamina -= 1;
		stamina_co = 0;
	}
	else
	{
		m_vstamina = 0.0f;
	}

	//1�����`3�������m�ۂ������_�f��
	if (FiStar_Recovery == true)
	{
		Aitem_co = true; //�\���_�f�{���x��
		FiStar_Recovery = false;
	}
	else if (SeStar_Recovery == true)
	{
		m_vx -= 50.0f;
		m_stamina += 50.0f;
		SeStar_Recovery = false;
	}
	else if (ThStar_Recovery == true)
	{
		m_vx -= 30.0f;
		m_stamina += 30.0f;
		ThStar_Recovery = false;
	}
	//�C�x���g��
	Ev_time = rand() % 5;

	//����̏����Ŏ_�f��10%~40%������
	if (Event_Conversion == 0)
	{
		if (Event_on == true && Ev_time == 4 && stamina_co == 150)
		{
			m_vstamina += m_px / m_stamina_max;
			m_stamina -= m_px / m_stamina_max;
		}
	}
	else if (Event_Conversion == 1)
	{
		if (Event_on == true && Ev_time == 4 && stamina_co == 150)
		{
			m_vstamina += m_px / 90;
			m_stamina -= m_px / 90;
		}
	}
	else if (Event_Conversion == 2)
	{
		if (Event_on == true && Ev_time == 4 && stamina_co == 150)
		{
			m_vstamina += m_px / 80;
			m_stamina -= m_px / 80;
		}
	}
	else if (Event_Conversion == 3)
	{
		if (Event_on == true && Ev_time == 4 && stamina_co == 150)
		{
			m_vstamina += m_px / 70;
			m_stamina -= m_px / 70;
		}
	}
	
	//����_�f���ő�l�A�ŏ��l�𒴂��Ȃ��悤�ɂ��鏈��
	if (m_vx < 0.0f)
	{
		m_vx = 0.0f;
	}
	else if (m_vx > m_stamina_max)
	{
		m_vx = m_stamina_max;
	}

	//�\���_�f���ő�l�A�ŏ��l�𒴂��Ȃ��悤�ɂ��鏈��
	if (m_stamina < 0)
	{
		m_stamina = 0;
	}
	else if (m_stamina > m_stamina_max)
	{
		m_stamina = m_stamina_max;
	}
	
	//�_�f�������Ȃ�ƉF���D��
	if (m_vx == m_stamina_max)
	{
		Scene::SetScene(new CSceneTitle());
	}

	//�_�f�����
	m_vx += m_vstamina + m_vancer;

}
//�h���[
void CObjstaminagauge::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	swprintf_s(str, L"%d/%d", m_stamina, m_stamina_max);
	Font::StrDraw(str, 580, 570, 30, c);

	//�w�i
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 70.0;
	src.m_right = 80.0f;
	src.m_bottom = 4.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 6.0f + m_py;
	dst.m_left = 0.0f + m_px + m_vx;
	dst.m_right = 100.0f + m_px;
	dst.m_bottom = 22.0f + m_py;

	//�`��
	Draw::Draw(22, &src, &dst, c, 0.0f);

}
