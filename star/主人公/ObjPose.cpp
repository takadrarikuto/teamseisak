//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\Audio.h"
#include"GameHead.h"
#include"ObjPose.h"
#include "GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjPose::Init()
{
	m_Af = false;
	
}

//�A�N�V����
void  CObjPose::Action()
{
	if (Input::GetVKey('N') == true)
	{
		this->SetStatus(false);	//���g�ɍ폜���߂��o��			

	}

			
	
}

//�h���[
void  CObjPose::Draw()
{
	float bc[4] = { 1.0f,1.0f,1.0f,0.6f };
	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̈ʒu
	src.m_top = 0.0;
	src.m_left = 0.0f;
	src.m_right = 100.0f;
	src.m_bottom = 100.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(25, &src, &dst, bc, 0.0f);

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"�F���D�ɖ߂�܂���?�L�[����͂��Ă�������", 120, 120, 30, c);

	Font::StrDraw(L"�߂�Ȃ�(N)", 450, 300, 30, c);
	Font::StrDraw(L"�߂�(B)", 250, 300, 30, c);



}
