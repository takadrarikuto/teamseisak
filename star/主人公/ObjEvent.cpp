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
bool Event_Star = false; //�C�x���g�����̈ړ������ύX
int Event_Conversion = 0; //�C�x���g�G���A�؂�ւ�

//�C�j�V�����C�Y
void CObjEvent::Init()
{
	//�C�x���g�X�^�[�g�t���O������
	E_Start = false;
	//�C�x���g�X�^�[�g�J�E���g������
	E_Start_co = 0;

	//�w�i����p������
	m_x1 = 0.0f;
	m_x2 = 800.0f;
	m_y1 = 0.0f;
	m_y2 = 600.0f;

}

//�A�N�V����
void CObjEvent::Action()
{

	//�w�i�ړ�����
	if (Event_Conversion == 0)
	{
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
	}
	else if (Event_Conversion == 1)
	{
		m_y1 += 10.0f;
		if (m_y1 > 500.0f)
		{
			m_y1 = -500.0f;
		}

		m_y2 += 10.0f;
		if (m_y2 > 500.0f)
		{
			m_y2 = -500.0f;
		}
	}
	else if (Event_Conversion == 2)
	{
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
	}
	else if (Event_Conversion == 3)
	{
		m_x1 += 10.0f;
		if (m_x1 > 800.0f)
		{
			m_x1 = -790.0f;
		}

		m_x2 += 10.0f;
		if (m_x2 > 800.0f)
		{
			m_x2 = -790.0f;
		}
	}
	
	E_Start_co++;

	//�X�e�[�W�ʂŊJ�n���ԂƏI�����Ԃ�ύX
	if (Event_Conversion == 0)
	{
		//�C�x���g�J�n����
		if (E_Start_co == 3600)
		{
			E_Start = true;
			Event_on = true;
			Event_Star = true;
			E_Start_co++;
		}
		//�C�x���g�I������
		else if (E_Start_co == 4200)
		{
			E_Start = false;
			Event_on = false;
			Event_Star = false;
			E_Start_co = 0;
		}
	}
	else if (Event_Conversion == 1)
	{
		//�C�x���g�J�n����
		if (E_Start_co == 3000)
		{
			E_Start = true;
			Event_on = true;
			Event_Star = true;
			E_Start_co++;
		}
		//�C�x���g�I������
		else if (E_Start_co == 3600)
		{
			E_Start = false;
			Event_on = false;
			Event_Star = false;
			E_Start_co = 0;
		}
	}
	else if (Event_Conversion == 2)
	{
		//�C�x���g�J�n����
		if (E_Start_co == 2400)
		{
			E_Start = true;
			Event_on = true;
			Event_Star = true;
			E_Start_co++;
		}
		//�C�x���g�I������
		else if (E_Start_co == 3600)
		{
			E_Start = false;
			Event_on = false;
			Event_Star = false;
			E_Start_co = 0;
		}
	}
	else if (Event_Conversion == 3)
	{
		//�C�x���g�J�n����
		if (E_Start_co == 900)
		{
			E_Start = true;
			Event_on = true;
			Event_Star = true;
			E_Start_co++;
		}
		//�C�x���g�I������
		else if (E_Start_co == 1800)
		{
			E_Start = false;
			Event_on = false;
			Event_Star = false;
			E_Start_co = 0;
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

	//�ΐ�
	if (Event_Conversion == 0)
	{
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
	//����
	else if (Event_Conversion == 1)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 640.0f;
		src.m_bottom = 480.0f;

		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_y1;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 500.0f + m_y1;

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
		dst.m_top = 0.0f + m_y2;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 500.0f + m_y2;

		if (E_Start == true)
		{
			//�`��
			Draw::Draw(9, &src, &dst, c, 0.0f);
		}

	}
	//�ؐ�
	else if (Event_Conversion == 2)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 1000.0f;
		src.m_bottom = 1000.0f;

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
		src.m_right = 1000.0f;
		src.m_bottom = 1000.0f;

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
	//�y��
	else if (Event_Conversion == 3)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 90.0f;
		src.m_left = 0.0f;
		src.m_right = 400.0f;
		src.m_bottom = 310.0f;

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
		src.m_top = 90.0f;
		src.m_left = 0.0f;
		src.m_right = 400.0f;
		src.m_bottom = 310.0f;

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
}
