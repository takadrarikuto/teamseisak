//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

#include"GameHead.h"
#include"Objstaminagaugeframe.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjstaminagaugeframe::Init()
{
	Aitem_flag = true;
	Aitem_co_max = 5;
	Aitem_co = 1;
	m_px = 700.0f;
	m_py = 550.0f;
}

//�A�N�V����
void CObjstaminagaugeframe::Action()
{
	/*
	//�A�C�e���g�p
	if (Input::GetVKey('A') == true)
	{
		//�摜���3��
		if (Aitem_co_max > 0)
		{
			if (Aitem_flag == true)
			{
				Aitem_co_max -= Aitem_co;
				Aitem_flag = false;
			}
		}
		else
		{
			;
		}
	}
	else
	{
		Aitem_flag = true;
	}
	*/

}
//�h���[
void CObjstaminagaugeframe::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

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
	dst.m_right = 100.0f + m_px;
	dst.m_bottom = 30.0f + m_py;

	//�`��
	Draw::Draw(17, &src, &dst, c, 0.0f);

}
