//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjFirstStar.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
void CObjFirstStar::Init()
{
	m_px = 0.0f;
	m_py = 100.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;

	star_co = 0;

	star_flag = false;

	Hits::SetHitBox(this, m_px, m_py, 64, 64, OBJ_FIRSTSTAR, ELEMENT_RED, 12);


}

//�A�N�V����
void CObjFirstStar::Action()
{
	
	m_move = rand() % 50;

	if (m_move <= 90 && m_move <= 0)
		m_vx += 1.0f;

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
		m_py = ay - 45;
	}

	//��ʊO�ɏo���琯���폜
	if (m_px > 800.0f || star_flag == true)
	{
		this->SetStatus(false); //���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this); //HitBox�폜
		star_flag = false;
	}

	if (m_py > 450.0f)
	{
		star_co += 1; //���̐��J�E���g	
		star_flag = true;	
	}

	/*
	//��l���̓����蔻��ɓ�����Ɛ��t���O��true�ɂ��A���̐����J�E���g
	if (hit_s->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		star_co += 1; //���̐��J�E���g
		star_flag = true;
	}
	*/

	if (star_co > 10)
	{
			Scene::SetScene(new CSceneGameKuria());
	}
	
}
//�h���[
void CObjFirstStar::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	swprintf_s(str, L"���̐��~%3d��", star_co); //�I�u�W�F�N�g�������������ŕ`�悪���Z�b�g�����
	Font::StrDraw(str, 10, 570, 30, c);

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 350.0f; //�F0.0f
	src.m_right = 510.0f; //�F190.0f
	src.m_bottom = 200.0f; //�F200.0f


	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px;
	dst.m_right = 64.0f + m_px;
	dst.m_bottom = 64.0f + m_py;

	//�`��
	Draw::Draw(13, &src, &dst, c, 0.0f);
}
