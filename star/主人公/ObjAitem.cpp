//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

#include"GameHead.h"
#include"ObjAitem.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

bool Aitem_on = false;

//�C�j�V�����C�Y
void CObjAitem::Init()
{
	//�A�C�e���t���O������
	Aitem_flag = true;
	//�ő��������
	Aitem_co_max = 5;
	//�������炷�p������
	Aitem_co = 1; 

	//�摜�p���W������
	m_px = 780;
	m_py = 530;

}

//�A�N�V����
void CObjAitem::Action()
{
	//�A�C�e���g�p
	if (Input::GetVKey('I') == true)
	{
		//�g�p�񐔏���
		if (Aitem_co_max > 0)
		{
			if (Aitem_flag == true)
			{
				Aitem_co_max -= Aitem_co; //�g�p�񐔂����炷
				Aitem_on = true; //�X�^�~�i�𑝂₷
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

}
//�h���[
void CObjAitem::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	swprintf_s(str, L"�h�����N�̐��~%d��", Aitem_co_max);
	Font::StrDraw(str, 530, 540, 30, c);

	//�w�i
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 90.0f;
	src.m_right = 160.0f;
	src.m_bottom = 194.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px;
	dst.m_right = 20.0f + m_px;
	dst.m_bottom = 40.0f + m_py;

	//�`��
	Draw::Draw(14, &src, &dst, c, 0.0f);

}
