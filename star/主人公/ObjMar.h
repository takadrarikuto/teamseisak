#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[�����C��
class CObjMar :public CObj
{
public:
	CObjMar() {};
	~CObjMar() {};
	void Init();
	void Action();
	void Draw();

private:
	bool m_return_flag;

};