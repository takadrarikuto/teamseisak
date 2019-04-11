//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjEvent.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

bool Event_on = false; //�C�x���g�J�n

//�C�j�V�����C�Y
void CObjEvent::Init()
{
	//�C�x���g�X�^�[�g�t���O
	E_Start = false;
	//�C�x���g�J�E���g
	E_co = 0;
	//�C�x���g�J�E���g
	E_Start_co = 0;

	m_px = 0.0f;
	m_py = 0.0f;

	//�w�i����p
	m_x1 = 0.0f;
	m_x2 = 800.0f;

}

//�A�N�V����
void CObjEvent::Action()
{

	//�w�i�ړ�����
	m_x1 -= 10.0f;
	if (m_x1 < -800.0f)
	{
		m_x1 = 790.0f;
	}

	m_x2 -= 10.0f;
	if (m_x2 < -800.0f)
	{
		m_x2 = 790.0f;
	}
	

	//�C�x���g�J�n����
	if (E_Start_co == 360)
	{
		E_Start = true;
		E_Start_co++;
		Event_on = true;
	}
	else
	{
		E_Start_co++;
	}

	//�C�x���g�I������
	if (E_Start_co == 6000)
	{
		E_Start = false;
		E_Start_co = 0;
		Event_on = false;
	}


}
//�h���[
void CObjEvent::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�w�i
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 640.0f;
	src.m_bottom = 480.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x1;
	dst.m_right = 800.0f + m_x1;
	dst.m_bottom = 500.0f;

	if (E_Start == true)
	{
		//�`��
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}
	
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 640.0f;
	src.m_bottom = 480.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x2;
	dst.m_right = 800.0f + m_x2;
	dst.m_bottom = 500.0f;

	if (E_Start == true)
	{
		//�`��
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}
}
