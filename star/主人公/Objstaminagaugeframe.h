#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�@�^�C�g��
class CObjstaminagaugeframe :public CObj
{
public:
	CObjstaminagaugeframe() {};
	~CObjstaminagaugeframe() {};
	void Init();
	void Action();
	void Draw();

private:
	bool Aitem_flag; //�A�C�e���t���O
	int Aitem_co_max; //��
	int Aitem_co; //�������炷�悤

	float m_px;
	float m_py;
};