//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

#include"GameHead.h"
#include"ObjFirstStar.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjFirstStar::Init()
{
	m_px = 0;
	m_py = 0;
	m_vx = 0.0f;


}

//�A�N�V����
void CObjFirstStar::Action()
{
	m_move = rand() % 50;

	if (m_move <= 90 && m_move <= 0)
		m_vx += 1.0f;

	m_px += m_vx;

}
//�h���[
void CObjFirstStar::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

			   //�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 190.0f;
	src.m_bottom = 200.0f;


	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px;
	dst.m_right = 64.0f + m_px;
	dst.m_bottom = 64.0f + m_py;

	//�`��
	Draw::Draw(5, &src, &dst, c, 0.0f);
}
