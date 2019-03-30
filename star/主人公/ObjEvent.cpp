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

//�C�j�V�����C�Y
void CObjEvent::Init()
{
	I_Start = false;
	I_co = 0;
	I_Start_co = 0;

	m_px = 0.0f;
	m_py = 0.0f;

	m_x1 = 0.0f;
	m_x2 = 800.0f;

	Hits::SetHitBox(this, m_px, m_py, 800, 400, OBJ_EVENT, ELEMENT_FIELD, 9);

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

	I_Start_co++;

	//�C�x���g�J�n����
	if (I_Start_co == 360)
	{
		I_Start = true;
		I_co++;

		//�C�x���g�I������
		if (I_co == 30)
		{
			I_Start = false;
			I_Start_co = 0;
			I_co = 0;

			this->SetStatus(false); //���g�ɍ폜���߂��o��
			Hits::DeleteHitBox(this); //HitBox�폜
		}
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

	if (I_Start == true)
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

	if (I_Start == true)
	{
		//�`��
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}
}
