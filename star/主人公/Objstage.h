#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�@�A���J�[
class CObjstage : public CObj
{
public:
	CObjstage() {};
	~CObjstage() {};

	void Init();
	void Action();
	void Draw();

private:
	int stageselect;

};