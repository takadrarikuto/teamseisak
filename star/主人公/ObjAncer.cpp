//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjAncer.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjAncer::Init()
{
	//�A���J�[�ʒu������
	//�{��
	m_px = 420.0f;
	m_py = 520.0f;
	//�A���J�[
	m_pax = 428.5f;
	m_pay = 505.0f;
	//���[�v
	m_prx = 446.0f;
	m_pry = 480.0f;

	//�ړ��x�N�g��������
	m_vx = 0.0f;
	m_vy = 0.0f;

	//���N���b�N���쏉����
	m_mous_l = false;
	
	//�����蔻��p��HitBox���쐬

	//�A���J�[
	//Hits::SetHitBox(this, m_px, m_py, 20, 50, ELEMENT_ANCER, OBJ_ANCER, 11);

}

//�A�N�V����
void CObjAncer::Action()
{
	/*
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float ax = hero->GetX();
	float ay = hero->GetY();

	//�ʒu�X�V
	m_px +=  ax + 50.0f;
	m_py +=  ay;
	*/

	m_mous_l = Input::GetMouButtonL();

	//�ړ��x�N�g���j��
	m_vx = 0.0f;
	m_vy = 0.0f;

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

	//�A���J�[����
	if (Input::GetMouButtonL() == true)
	{
		m_vy -= 6.0f;
	}
	else if(Input::GetMouButtonL() == false && m_pay < 505.0f)
	{
		m_vy += 3.0f;
	}


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
	if (m_pax < 29.0f)
	{
		m_pax = 29.0f; 
	}
	else if (m_pax + 46.0f > 800.0f)
	{
		m_pax = 800.0f -46.0f; 
	}
	//���[�v
	if (m_prx < 46.0f)
	{
		m_prx = 46.0f;
	}
	else if (m_prx + 28.0f > 800.0f)
	{
		m_prx = 800.0f - 28.0f;
	}

	//�ʒu�X�V
	m_px += m_vx;
	m_pax += m_vx;
	m_pay += m_vy;
	m_prx += m_vx;
	m_pry += m_vy;
	
	//���g��HitBox�������Ă���
	//CHitBox* hit_a = Hits::GetHitBox(this);

	//HitBox�̈ʒu�̕ύX
	//hit_a->SetPos(m_px, m_py);

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

	//�؂���ʒu�̈ʒu
	srcr.m_top = 0.0f;
	srcr.m_left = 70.0f;
	srcr.m_right = 80.0f;
	srcr.m_bottom = 30.0f;

	//�\���ʒu�̐ݒ�
	dstr.m_top = 0.0f + m_pry;
	dstr.m_left = 0.0f + m_prx;
	dstr.m_right = 20.0f + m_prx;
	dstr.m_bottom = 100.0f + m_pry;

	Draw::Draw(11, &srcr, &dstr, c, 0.0f);

	
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

	Draw::Draw(11, &src, &dst, c, 0.0f);
	

	//�؂���ʒu�̈ʒu
	srca.m_top = 0.0f;
	srca.m_left = 30.0f;
	srca.m_right = 70.0f;
	srca.m_bottom = 100.0f;

	//�\���ʒu�̐ݒ�
	dsta.m_top = 0.0f + m_pay;
	dsta.m_left = 0.0f + m_pax;
	dsta.m_right = 50.0f + m_pax;
	dsta.m_bottom = 100.0f + m_pay;

	Draw::Draw(11, &srca, &dsta, c, 0.0f);

}
