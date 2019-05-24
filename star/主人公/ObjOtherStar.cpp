//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjSecondStar.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

extern bool Event_Star;//�C�x���g�����̈ړ������ύX
extern int Event_Conversion; //�C�x���g�G���A�؂�ւ�
extern int g_other_star[15];
extern int star_count;
extern int OtStar_Reco;


CObjOtherStar::CObjOtherStar(float x)
{
	m_px = x;
}

//�C�j�V�����C�Y
void CObjOtherStar::Init()
{
	m_py = rand() % 340 + 1;
	m_vx = 0.0f;
	m_vy = 0.0f;

	hero_flag = false;
	ancer_flag = false;
	
	star_num = rand() % 5;



	Hits::SetHitBox(this, m_px, m_py, 32, 32, OBJ_OTHERSTAR, ELEMENT_RED, 12);


}

//�A�N�V����
void CObjOtherStar::Action()
{

	//�ړ������ύX
	if (Event_Conversion == 0)
	{
		if (Event_Star == false)
		{
			m_vx = 2.0f;
		}
		else if (Event_Star == true)
		{
			m_vx = -2.0f;
		}
	}
	else if (Event_Conversion == 1)
	{
		if (Event_Star == false)
		{
			m_vx = 2.0f;
			m_vy = 0.0f;
		}
		else if (Event_Star == true)
		{
			m_vx = 2.0f;
			m_vy = 0.5f;
		}
	}
	else if (Event_Conversion == 2)
	{
		if (Event_Star == false)
		{
			m_vx = 2.0f;
			m_vy = 0.0f;
		}
		else if (Event_Star == true)
		{
			m_vx = -3.0f;
			m_vy = -0.5f;
		}
	}
	else if (Event_Conversion == 3)
	{
		if (Event_Star == false)
		{
			m_vx = 2.0f;
		}
		else if (Event_Star == true)
		{
			m_vx = 4.0f;
		}
	}

	
	m_px += m_vx;
	m_py += m_vy;


	//���g��HitBox�������Ă���
	CHitBox* hit_s = Hits::GetHitBox(this);

	//HitBox�̈ʒu�̕ύX
	hit_s->SetPos(m_px, m_py);

	//�A���J�[�̈ʒu�̎擾
	CObjAncer* Ancer = (CObjAncer*)Objs::GetObj(OBJ_ANCER);
	float ax = Ancer->GetX();
	float ay = Ancer->GetY();

	//�A���J�[�Ɠ������Ă��邩
	if (hit_s->CheckObjNameHit(OBJ_ANCER) != nullptr)
	{
		m_px = ax - 13;
		m_py = ay - 50;
		ancer_flag = true;
		//��l���̓����蔻��ɓ�����Ǝ�l���t���O��true�ɂ��A���̐����J�E���g
		if (hit_s->CheckObjNameHit(OBJ_HERO) != nullptr)
		{
			hero_flag = true;

		}

	}

	//��ʊO�ɏo���琯���폜
	if (m_px > 800.0f || m_px < 0.0f || m_py > 500.0f  || m_px < 0.0f)
	{
		this->SetStatus(false); //���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this); //HitBox�폜

	}
	//�A���J�[�ɓ������Ă��Ȃ����y����350�̈ʒu�Ő����폜
	if (ancer_flag == false)
	{
		if (m_py > 350.0f || m_py < 0.0f || m_py > 500.0f)
		{
			this->SetStatus(false); //���g�ɍ폜���߂��o��
			Hits::DeleteHitBox(this); //HitBox�폜
		}
	}
	//�A���J�[�ɓ������Ă����ԂŎ�l���ɓ�����ƍ폜
	else if (ancer_flag == true && hero_flag == true)
	{
		this->SetStatus(false); //���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this); //HitBox�폜
		ancer_flag = false;
		hero_flag = false;

		OtStar_Reco += 1; //3�����_�f�񕜗p�J�E���g

		if (g_other_star[star_num] != 0)
		{
			g_other_star[32]++;
			star_count++;
		}
		else if (g_other_star[star_num] == 0)
		{
			star_count++;
			g_other_star[star_num]++;

		}
	}
	

}
//�h���[
void CObjOtherStar::Draw()
{
	//���g��HitBox�������Ă���
	CHitBox* hit_s = Hits::GetHitBox(this);
	hit_s->SetPos(m_px, m_py);

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

			   //�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 100.0f;
	src.m_bottom = 100.0f;

	if (hit_s->CheckObjNameHit(OBJ_ANCER) != nullptr)
	{
		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_py;
		dst.m_left = 0.0f + m_px;
		dst.m_right = 32.0f + m_px;
		dst.m_bottom = 32.0f + m_py;
	}
	else
	{
		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_py;
		dst.m_left = 0.0f + m_px;
		dst.m_right = 32.0f + m_px;
		dst.m_bottom = 32.0f + m_py;
	}

	//�`��
	Draw::Draw(20, &src, &dst, c, 0.0f);
}
