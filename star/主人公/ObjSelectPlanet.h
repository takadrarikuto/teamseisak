#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[�����C��
class CObjSelectPlanet :public CObj
{
public:
	CObjSelectPlanet() {};
	~CObjSelectPlanet() {};
	void Init();
	void Action();
	void Draw();

private:
	bool m_mous_l;
	bool m_start_flag;
	float m_mous_x; //�}�E�X�̈ʒuX
	float m_mous_y; //�}�E�X�̈ʒuY
};