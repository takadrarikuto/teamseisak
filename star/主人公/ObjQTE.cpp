//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

#include"GameHead.h"
#include"ObjQTE.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjQTE::Init()
{
	i = rand() % 36;

	time = 0;

}

//�A�N�V����
void CObjQTE::Action()
{
	time++;

	if(time == 10)
	this->SetStatus(false); //���g�ɍ폜���߂��o��
}
//�h���[
void CObjQTE::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	float c2[4] = { 1.0f,1.0f,1.0f,1.0f };

	switch (i)
	{
	case 1:
		Font::StrDraw(L"A", 150, 150, 30, c2);
		break;
	case 2:
		Font::StrDraw(L"B", 150, 150, 30, c2);
		break;
	}
	//�w�i
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 15.0f;
	src.m_left = 12.0f;
	src.m_right = 437.0f;
	src.m_bottom = 270.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 100.0f;
	dst.m_left = 100.0f;
	dst.m_right = 200.0f;
	dst.m_bottom = 200.0f;

	//�`��
	Draw::Draw(20, &src, &dst, c, 0.0f);

}
