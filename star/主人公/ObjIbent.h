#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�@�^�C�g��
class CObjIbent :public CObj
{
public:
	CObjIbent() {};
	~CObjIbent() {};
	void Init();
	void Action();
	void Draw();

private:
	bool I_Start; //�C�x���g�X�^�[�g�t���O
	int I_co; //�C�x���g�J�E���g
	int I_Start_co; //�C�x���g�J�E���g

	
	float m_px; //�����蔻��p
	float m_py;

	float m_vx1; //�X�N���[���p
	float m_vx2; 

};