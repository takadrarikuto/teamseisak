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
	float GetX() { return m_px; }
	float GetY() { return m_py; }
	void Init();
	void Action();
	void Draw();

private:
	float m_px; //��l���`��ʒu
	float m_py;
	float m_ax; //�A���J�[�`��ʒu
	float m_ay;
	float m_vx; //�ړ��x�N�g��
	float m_pos; //��l������

	int m_ani_time;		//�A�j���[�V�����t���[������Ԋu
	int m_ani_frame;	//�`��t���[��

	bool m_return_flag;

	bool m_mous_l;

};