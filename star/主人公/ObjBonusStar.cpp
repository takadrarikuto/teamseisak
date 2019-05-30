//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjBonusStar.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

extern bool Event_Star;//�C�x���g�����̈ړ������ύX
extern int Event_Conversion; //�C�x���g�G���A�؂�ւ�
extern int g_third_star;//3�����J�E���g
extern int g_fouth_star;//4�����J�E���g
extern int g_other_star;//5�E6�����J�E���g
extern int star_count;


CObjBonusStar::CObjBonusStar(float x)
{
	m_px = x;
}

//�C�j�V�����C�Y
void CObjBonusStar::Init()
{
	m_py = rand() % 340 + 1;
	m_vx = 5.0f;
	m_vy = 0.0f;

	hero_flag = false;
	ancer_flag = false;

	star_num = rand() % 10 + 1;

	Hits::SetHitBox(this, m_px, m_py, 64,64, OBJ_BONUSSTAR, ELEMENT_RED, 12);


}

//�A�N�V����
void CObjBonusStar::Action()
{


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
	if (m_px > 800.0f || m_px < 0.0f || m_py > 500.0f || m_px < 0.0f)
	{
		this->SetStatus(false); //���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this); //HitBox�폜

	}
	//�A���J�[�ɓ������Ă��Ȃ����y����350�̈ʒu�Ő����폜
	if (ancer_flag == false)
	{
		if (m_py > 350.0f || m_py < 0.0f)
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

		if (star_num <= 1)
		{
			g_third_star += 10;
			star_count += 10;
		}
		else if (star_num <= 5)
		{
			g_fouth_star += 10;
			star_count += 10;
		}
		else if (star_num <= 10)
		{
			g_other_star += 10;
			star_count += 10;
		}
	}




}
//�h���[
void CObjBonusStar::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	 //�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 100.0f;
	src.m_bottom = 100.0f;


	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px;
	dst.m_right = 64.0f + m_px;
	dst.m_bottom = 64.0f + m_py;

	//�`��
	Draw::Draw(24, &src, &dst, c, 0.0f);
}
