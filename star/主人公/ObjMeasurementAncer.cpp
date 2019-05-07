//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

#include "GameHead.h"
#include "ObjMeasurementAncer.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

extern bool Event_on;
bool MAncer = false;

//�C�j�V�����C�Y
void CObjMeasurementAncer::Init()
{
	//�A���J�[�ʒu������
	//�򋗗�����p�A���J�[������
	m_pafx = 430.0f;
	m_pafy = 535.0f;
	//�A���J�[�T�C�Y�ύX
	m_sizex = 0;
	m_sizey = 0;
	size = 38;
	//�q�b�g�{�b�N�X�T�C�Y����
	hitbox_size = 0.0f;

	//�򋗗�����p�A���J�[�ړ��x�N�g��������
	m_vfx = 0.0f;
	m_vfy = 0.0f;


	//���N���b�N���쏉����
	m_mous_l = false;

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_pafx, m_pafy, size, size, ELEMENT_ANCER, OBJ_MANCER, 12);

	//�A���J�[�ړ��t���O������
	ancer_flag = false;

	//��ʈړ����N���h�~�p������
	time_co = 0;

	//�A�����˖h�~�t���O������
	ancer_Prevent_doublepress = false;

	//�򋗗�����p�A���J�[�쐬������
	Ancer_flag = false;
}

//�A�N�V����
void CObjMeasurementAncer::Action()
{
	m_mous_l = Input::GetMouButtonL();

	time_co++;

	//�ړ��x�N�g���j��
	m_vfx = 0.0f;
	m_vfy = 0.0f;

	//�ړ�
	//��
	if (Input::GetVKey('A') == true)
	{
		m_vfx -= 4.0f;
	}
	//�E
	else if (Input::GetVKey('D') == true)
	{
		m_vfx += 4.0f;
	}


	//���g��HitBox�������Ă���
	CHitBox* hit_a = Hits::GetHitBox(this);

	//��ʈړ����N���h�~�p
	if (time_co > 30)
	{
		if (m_mous_l == true && MAncer == false)
		{
			Ancer_flag = true;
		}
		else if (m_mous_l == false)
		{
			Ancer_flag = false;
		}
	}
	else
	{
		m_mous_l = false;
	}

	if (Ancer_flag == true)
	{
		m_vfy -= 10.0f;
	}
	else if (Ancer_flag == false)
	{
		m_pafy = 535.0f;
	}

	//��ʊO�ɏo�Ȃ�����
	//�򋗗�����p�A���J�[
	if (m_pafy < 0.0f)
	{
		m_pafy = 0.0f;
		Ancer_flag = false;
	}
	else if (m_pafy > 535.0f)
	{
		m_pafy = 535.0f;
	}


	//�ʒu�X�V
	m_pafx += m_vfx;
	m_pafy += m_vfy;


	//HitBox�̈ʒu�̕ύX
	hit_a->SetPos(m_pafx + hitbox_size, m_pafy, size, size);


}

//�h���[
void CObjMeasurementAncer::Draw()
{

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�򋗗�����p�A���J�[
	//�؂���ʒu�̈ʒu
	src.m_top = 50.0f;
	src.m_left = 40.0f;
	src.m_right = 180.0f;
	src.m_bottom = 170.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_pafy;
	dst.m_left = 0.0f + m_pafx;
	dst.m_right = 40.0f + m_pafx;
	dst.m_bottom = 40.0f + m_pafy;

	if (Ancer_flag == true)
	{
		Draw::Draw(12, &src, &dst, c, 0.0f);
	}

}
