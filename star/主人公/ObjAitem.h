#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�@�^�C�g��
class CObjAitem :public CObj
{
public:
	CObjAitem() {};
	~CObjAitem() {};
	void Init();
	void Action();
	void Draw();

private:
	bool Aitem_flag; //�A�C�e���t���O
	int Aitem_co_max; //�ő��
	int Aitem_co; //�������炷�p

	float m_px; //�摜�p���W
	float m_py;

	wchar_t str[256];

};