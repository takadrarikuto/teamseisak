//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

#include"GameHead.h"
#include "ObjExclamationMark.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

bool EM_flag = false; //�r�b�N���}�[�N�o���t���O

//�C�j�V�����C�Y
void CObjExclamationMark::Init()
{
	//�r�b�N���}�[�N�ʒux������
	m_pemx = 400.0f;
	//�r�b�N���}�[�N�ʒuy������
	m_pemy = 480.0f;

	//���ړ��x�N�g��������
	m_vx = 0.0f;
}

//�A�N�V����
void CObjExclamationMark::Action()
{
	//�A���J�[�̈ʒu�̎擾
	CObjHero* Hero = (CObjHero*)Objs::GetObj(OBJ_EM);
	float hx = Hero->GetX();
	float hy = Hero->GetY();

	//��l���̏�ɋN��������

	m_pemx = hx;
	m_pemy = hy;

	m_vx = 0.0f;

	//��
	if (Input::GetVKey('A') == true)
	{
		m_vx -= 4.0f;
	}
	//�E
	else if (Input::GetVKey('D') == true)
	{
		m_vx += 4.0f;
	}

	//��ʊO�ɏo�Ȃ��悤�ɂ��鏈��
	if (m_pemx < 4.0f)
	{
		m_pemx = 4.0f;
	}
	else if (m_pemx + 40.0f > 766.0f)
	{
		m_pemx = 766.0f - 40.0f;
	}

	//�ʒu�X�V
	m_pemx += m_vx;
}
//�h���[
void CObjExclamationMark::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�w�i
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 270.0f;
	src.m_left = 200.0f;
	src.m_right = 1240.0f;
	src.m_bottom = 1200.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_pemy;
	dst.m_left = 0.0f + m_pemx;
	dst.m_right = 40.0f + m_pemx;
	dst.m_bottom = 40.0f + m_pemy;

	if (EM_flag == true)
	{
		//�`��
		Draw::Draw(23, &src, &dst, c, 0.0f);
	}


}
