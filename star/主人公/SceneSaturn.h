#pragma once
//�g�p����w�b�_�[�t�@�C��
#include"GameL\SceneManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C�g��
class CSceneSaturn : public CScene
{
public:
	CSceneSaturn() {};
	~CSceneSaturn() {};
	void InitScene(); //�Q�[���^�C�g���̏��������\�b�h
	void Scene();     //�Q�[���^�C�g���̎��s�����\�b�h
private:
	int time_star; //����������
	bool star_flag;


};