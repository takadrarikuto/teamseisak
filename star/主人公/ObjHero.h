#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�@��l��
class CObjHero :public CObj
{
public:
	CObjHero() {};
	~CObjHero() {};
	void Init();
	void Action();
	void Draw();

private:
	float m_px; //�`��ʒu
	float m_py;
	float m_vx; //�ړ��x�N�g��

	float m_pos; //��l������
};