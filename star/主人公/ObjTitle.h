#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�@�^�C�g��
class CObjTitle :public CObj
{
public:
	CObjTitle() {};
	~CObjTitle() {};
	void Init();
	void Action();
	void Draw();

private:
	bool m_mous_l; //���N���b�N�t���O
	bool m_start_flag;
	float m_mous_x; //�}�E�X�̈ʒuX
	float m_mous_y; //�}�E�X�̈ʒuY
	int a_time;
	bool time_flag;
	int font_size;//�����̑傫��

	float m_mou_time; //�A���I��h�~�^�C��
};