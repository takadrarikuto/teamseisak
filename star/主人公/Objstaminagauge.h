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
	bool Aitem_flag; //�A�C�e���t���O
	int Aitem_co_max; //��

	float m_px;
	float m_py;

	float m_vx; //�S�Ă̏����
	float m_vancer; //�A���J�[�g�p���p
	float m_vstamina; //���R����

	bool m_mous_l;
	bool stamina_flag;

	int stamina_back; //�X�^�~�i����p
	int stamina_co; //�b���J�E���g
	int time_co; //��ʈړ����N���h�~�p

	int Ev_time; //�C�x���g�J�E���g
	
	int m_stamina_max; //�X�^�~�i�ő�l
	int m_stamina; //�\���p�X�^�~�i

	wchar_t str[256];

};