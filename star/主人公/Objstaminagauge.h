#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�@�^�C�g��
class CObjstaminagauge :public CObj
{
public:
	CObjstaminagauge() {};
	~CObjstaminagauge() {};
	void Init();
	void Action();
	void Draw();

private:
	//�A�C�e���I�u�W�F�N�g������p
	bool Aitem_flag; //�A�C�e���t���O
	int Aitem_co_max; //��

	float m_px;
	float m_py;

	int m_stamina_max; //�X�^�~�i�ő�l
	int m_stamina; //�\���p�X�^�~�i

	float m_vx; //�S�Ă̏���p
	float m_vstamina;//���R����p
	float m_vancer; //�A���J�[�g�p���p

	int stamina_back; //�X�^�~�i����p
	int stamina_co; //�b���J�E���g
	int time_co; //��ʈړ����N���h�~�p

	int Ev_time; //�C�x���g�J�E���g

	wchar_t str[256];

};