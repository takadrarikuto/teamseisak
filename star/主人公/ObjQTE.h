#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�@��l��
class CObjQTE :public CObj
{
public:
	CObjQTE() {};
	~CObjQTE() {};
	void Init();
	void Action();
	void Draw();

private:
	int i;
	int time;

};