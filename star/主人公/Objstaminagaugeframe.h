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

	float m_px;
	float m_py;
};