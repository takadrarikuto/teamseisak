#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�@�^�C�g��
class CObjEvent :public CObj
{
public:
	CObjEvent() {};
	~CObjEvent() {};
	void Init();
	void Action();
	void Draw();

private:
	bool E_Start; //�C�x���g�X�^�[�g�t���O
	int E_co; //�C�x���g�J�E���g
	int E_Start_co; //�C�x���g�J�E���g

	float m_px;
	float m_py;

	float m_x1; //�w�i����p
	float m_x2;
};