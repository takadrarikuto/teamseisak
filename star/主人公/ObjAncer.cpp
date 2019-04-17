//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjAncer.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

extern bool Event_on;
bool Ancer_on = false; //�A���J�[�g�p

//�C�j�V�����C�Y
void CObjAncer::Init()
{
	//�A���J�[�ʒu������
	//�{��
	m_px = 420.0f;
	m_py = 520.0f;
	//�A���J�[
	m_pax = 433.5f;
	m_pay = 535.0f;
	//���[�v
	//m_pry = 490.0f;
	m_prx = 448.0f;
	m_pry = 500.0f;

	//�ړ��x�N�g��������
	m_vx = 0.0f;
	m_vy = 0.0f;

	m_vancer = 0.0f;
	m_vrope = 0.0f;

	//���N���b�N���쏉����
	m_mous_l = false;
	
	//�����蔻��p��HitBox���쐬

	//�A���J�[
	Hits::SetHitBox(this, m_pax, m_pay, 40, 40, ELEMENT_ANCER, OBJ_ANCER, 11);

	//���[�v�`��p������
	rope = 0.0f;

	//�A���J�[�ړ��t���O������
	ancer_flag = false;

	//�򋗗�����������
	ancer_time = 0.0f;
	rope_time = 0.0f;

	//��ʈړ����N���h�~�p������
	time_co = 0;

	//�C�x���g�^�C������������
	A_event = 0;

	//�C�x���g���A���J�[����������
	Ev_ancer = 0;
}

//�A�N�V����
void CObjAncer::Action()
{
	m_mous_l = Input::GetMouButtonL();

	time_co++;

	//�ړ��x�N�g���j��
	m_vx = 0.0f;
	m_vy = 0.0f;

	//���N���b�N���Ă��鎞�܂��̓A���J�[��y�ʒu��535�ȉ��̎��ړ��֎~
	if (m_mous_l == false && m_pay > 535.0f)
	{
		//�ړ�
		//��
		if (Input::GetVKey(VK_LEFT) == true)
		{
			m_vx -= 4.0f;
		}
		//�E
		else if (Input::GetVKey(VK_RIGHT) == true)
		{
			m_vx += 4.0f;
		}
	}


	//���g��HitBox�������Ă���
	CHitBox* hit_a = Hits::GetHitBox(this);

	//��ʈړ����N���h�~�p
	if (time_co > 30)
	{
		if (m_mous_l == true)
		{
			ancer_flag = true;		
			if (ancer_time <= 100)
			{
				ancer_time += 1.0f;
				rope_time -= 1.0f;
			}		
		}
		else if (m_mous_l == false)
		{
			ancer_flag = false;
			if (ancer_time > 0)
			{
				ancer_time -= 1.0f;
				rope_time += 1.0f;
			}
		}
		
		if (ancer_flag == true)
		{
			//m_vancer -= ancer_time; //�A���J�[�ړ�
			//m_vrope += ancer_time; //���[�v��������
		}
		else if(ancer_flag == false)
		{
			//m_vancer += ancer_time; //�A���J�[�ړ�
			//m_vrope -= ancer_time; //���[�v��������				
			m_vy += ancer_time; //�A���J�[�ړ�
			rope += rope_time; //���[�v��������
		}

		if (m_pay < 50.0f)
		{
			//m_pay = 50.0f;
			//ancer_time = 0;
		}
		else if (m_pay > 535.0f)
		{
			m_pay = 535.0f;
			//ancer_time = 0;
		}
		else if (m_pay > 50.0f && m_pay < 535.0f)
		{
			//m_vy += m_vancer; //�A���J�[�ړ�
			//rope += m_vrope; //���[�v��������
		}


		/*
		//���ɓ�����Ɩ߂�
		if (hit_a->CheckObjNameHit(OBJ_FIRSTSTAR) != nullptr || hit_a->CheckObjNameHit(OBJ_SECONDSTAR) != nullptr)
		{
			ancer_flag = false;
			Ancer_on = false;
		}
		//��ʒu�ɃA���J�[�����鎞�ɍ��N���b�N�ŃA���J�[���ˁE�X�^�~�i����
		else if (Input::GetMouButtonL() == true && m_pay > 535.0f && time == 0)
		{
			ancer_time += 1;
			ancer_flag = true; //�A���J�[����
			Ancer_on = true; //�X�^�~�i����
		}
		else if (Input::GetMouButtonL() == false && ancer_time > 1)
		{
			
		}

		if (ancer_flag == true)
		{	
			m_vy -= 9.0f; //�A���J�[�ړ�
			time += 13.0f; //���[�v��������
		}
		else
		{
			m_vy += 6.0f; //�A���J�[�ړ�
			if (m_pry < 500.0f)
			{
				time -= 9.0f; //���[�v��������
			}
			else
			{
				time = 0.0f; //���[�v��������
				ancer_time = 1;
			}				
		}
		*/
	}
	else
	{
		m_mous_l = false;
	}

	/*
	//�C�x���g����
	Ev_ancer = rand() % 5;

	//����̏����ŃA���J�[��߂�
	if (m_pry < 400.0f && Event_on == true)
	{
		A_event++;
	}
	else if(Event_on == false || A_event > Event_Time)
	{
		A_event = 0;
	}

	if (m_pry < 400.0f && A_event > Event_Time && Ev_ancer == 4)
	{
		ancer_flag = false;
	}
	*/



	//��ʊO�ɏo�Ȃ�����
	//�{��
	if (m_px < 20.0f)
	{
		m_px = 20.0f; 
	}
	else if (m_px + 54.0f  > 800.0f)
	{
		m_px = 800.0f - 54.0f; 
	}
	//�A���J�[
	if (m_pax < 33.0f)
	{
		m_pax = 33.0f; 
	}
	else if (m_pax + 40.0f > 800.0f)
	{
		m_pax = 800.0f -40.0f; 
	}
	if (m_pay < 50.0f)
	{
		m_pay = 50.0f;
		//ancer_flag = false;
	}
	else if (m_pay > 535.0f)
	{
		m_pay = 535.0f;
	}
	//���[�v
	if (m_prx < 49.0f)
	{
		m_prx = 49.0f;
	}
	else if (m_prx + 26.0f > 800.0f)
	{
		m_prx = 800.0f - 26.0f;
	}
	if (m_pry > 500.0f)
	{
		m_pry = 500.0f;
	}
	else if (m_pry < 60.0f)
	{
		m_pry = 60.0f;
	}

	//�ʒu�X�V
	m_px += m_vx; //�{��
	m_pax += m_vx; //�A���J�[
	m_pay += m_vy;
	m_prx += m_vx; //���[�v
	m_pry += m_vy;
	

	//HitBox�̈ʒu�̕ύX
	hit_a->SetPos(m_pax, m_pay - 45);


}

//�h���[
void CObjAncer::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�{��
	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu
	//�A���J�[
	RECT_F srca; //�`�挳�؂���ʒu
	RECT_F dsta; //�`���\���ʒu
	//���[�v
	RECT_F srcr; //�`�挳�؂���ʒu
	RECT_F dstr; //�`���\���ʒu


	//���[�v
	//�؂���ʒu�̈ʒu
	srcr.m_top = 0.0f;
	srcr.m_left = 70.0f;
	srcr.m_right = 80.0f;
	srcr.m_bottom = 30.0f;

	//�\���ʒu�̐ݒ�
	dstr.m_top = 520.0f - rope;
	dstr.m_left = 0.0f + m_prx;
	dstr.m_right = 20.0f + m_prx;
	dstr.m_bottom = 540.0f;

	Draw::Draw(12, &srcr, &dstr, c, 0.0f);

	//�{��
	//�؂���ʒu�̈ʒu
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 30.0f;
	src.m_bottom = 100.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px;
	dst.m_right = 50.0f + m_px;
	dst.m_bottom = 100.0f + m_py;

	Draw::Draw(12, &src, &dst, c, 0.0f);
	
	//�A���J�[
	//�؂���ʒu�̈ʒu
	srca.m_top = 0.0f;
	srca.m_left = 90.0f;
	srca.m_right = 225.0f;
	srca.m_bottom = 200.0f;

	//�\���ʒu�̐ݒ�
	dsta.m_top = 0.0f + m_pay;
	dsta.m_left = 0.0f + m_pax;
	dsta.m_right = 50.0f + m_pax;
	dsta.m_bottom = -60.0f + m_pay;

	Draw::Draw(12, &srca, &dsta, c, 0.0f);

}
