#pragma once
//�g�p����w�b�_�[�t�@�C��
#include"GameL\SceneManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C�g��
class CSceneVenus : public CScene
{
public:
	CSceneVenus() {};
	~CSceneVenus() {};
	void InitScene(); //�Q�[���^�C�g���̏��������\�b�h
	void Scene();     //�Q�[���^�C�g���̎��s�����\�b�h
	int WeightedPick(int* pArray, int Length);
private:
	int time_star; //����������
	int occur;	//�������p
	int arise;	//�����m���p
	bool m_Pf;
	bool m_key_f;//�s������
	double probability;//�m��

	float Star_time; //1�����쐬�x���p�J�E���g
	bool Star_flag; //1�����쐬�x���p�t���O


};