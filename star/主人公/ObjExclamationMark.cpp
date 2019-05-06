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
	m_pemx = 0.0f;
	//�r�b�N���}�[�N�ʒuy������
	m_pemy = 0.0f;


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
	m_pemy = hy - 40.0f;


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
	dst.m_right = 30.0f + m_pemx;
	dst.m_bottom = 30.0f + m_pemy;

	if (EM_flag == true)
	{
		//�`��
		Draw::Draw(23, &src, &dst, c, 0.0f);
	}


}
