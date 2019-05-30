//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjTimeStop.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

extern bool Event_Star;//�C�x���g�����̈ړ������ύX
extern int Event_Conversion; //�C�x���g�G���A�؂�ւ�
extern int star_count;


//�C�j�V�����C�Y
void CObjTimeStop::Init()
{
	m_px = rand() % 650 + 50;
	m_py = 1;
	m_vx = 0.0f;
	m_vy = 2.0f;

	hero_flag = false;
	ancer_flag = false;


	Hits::SetHitBox(this, m_px, m_py, 32, 32, OBJ_TIMESTOP, ELEMENT_RED, 12);


}

//�A�N�V����
void CObjTimeStop::Action()
{


	m_px += m_vx;
	m_py += m_vy;


	//���g��HitBox�������Ă���
	CHitBox* hit_s = Hits::GetHitBox(this);

	//HitBox�̈ʒu�̕ύX
	hit_s->SetPos(m_px, m_py);


		//��l���̓����蔻��ɓ�����Ǝ�l���t���O��true�ɂ��A���̐����J�E���g
		if (hit_s->CheckObjNameHit(OBJ_HERO) != nullptr || hit_s->CheckObjNameHit(OBJ_ANCER) != nullptr)
		{
			this->SetStatus(false); //���g�ɍ폜���߂��o��
			Hits::DeleteHitBox(this); //HitBox�폜

			stop_flag = true;
			hero_flag = false;
		}

	//�A���J�[�ɓ������Ă��Ȃ����y����350�̈ʒu�Œ�~

		if (m_py > 520.0f)
		{
			m_vy = 0;
		}



}
//�h���[
void CObjTimeStop::Draw()
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
	dst.m_right = 32.0f + m_px;
	dst.m_bottom = 32.0f + m_py;

	//�`��
	Draw::Draw(25, &src, &dst, c, 0.0f);
}
