//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

#include"GameHead.h"
#include"Objstaminagaugeframe.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�X�^�~�i���_�f�ύX

//�C�j�V�����C�Y
void CObjstaminagaugeframe::Init()
{
	m_px = 694.0f;
	m_py = 570.0f;
}

//�A�N�V����
void CObjstaminagaugeframe::Action()
{

}
//�h���[
void CObjstaminagaugeframe::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"�_�f�c��", 460, 570, 30, c);

	//�w�i
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 84.0f;
	src.m_bottom = 8.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px;
	dst.m_right = 105.0f + m_px;
	dst.m_bottom = 30.0f + m_py;

	//�`��
	Draw::Draw(21, &src, &dst, c, 0.0f);

}
