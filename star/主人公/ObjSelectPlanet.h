#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[�����C��
class CObjSelectPlanet :public CObj
{
public:
	CObjSelectPlanet() {};
	~CObjSelectPlanet() {};
	void Init();
	void Action();
	void Draw();

private:
	bool m_mous_l;
	bool m_start_flag;
	float m_mous_x; //�}�E�X�̈ʒuX
	float m_mous_y; //�}�E�X�̈ʒuY
	int a_time;
	bool time_flag;

	bool Mars_up;
	bool Venus_up;
	bool Jupiter_up;
	bool Saturn_up;
	bool StarPic;

	bool Sart_flag;
	bool FiStar_flag;

	float Back_time; //�A���ړ��h�~�^�C��
	float m_mou_time; //�A���I��h�~�^�C��

	wchar_t str[256];
	wchar_t strFi_co[256];

	wchar_t strFi[256];
	wchar_t strSe[256];
	wchar_t strTh[256];
	wchar_t strFo[256];
	wchar_t strOt[256];


};