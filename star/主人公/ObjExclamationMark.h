#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�@�^�C�g��
class CObjExclamationMark :public CObj
{
public:
	CObjExclamationMark() {};
	~CObjExclamationMark() {};
	void Init();
	void Action();
	void Draw();

private:

	float m_pemx; //�r�b�N���}�[�N�ʒux
	float m_pemy; //�r�b�N���}�[�N�ʒuy

};