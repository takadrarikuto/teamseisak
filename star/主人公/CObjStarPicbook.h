#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�C�x���g
class CObjStarPicbook : public CObj
{
public:
	CObjStarPicbook() {};	//�R���X�g���N�^
	~CObjStarPicbook() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	float m_mou_x;//�}�E�X�̈ʒuX
	float m_mou_y;//�}�E�X�̈ʒuX
	bool m_mou_r;//�}�E�X�̉E�{�^��
	bool m_mou_l;//�}�E�X�̍��{�^��
	bool starmodel_flag;
	int a_time;
	int a_time_max;
	bool time_flag;

	wchar_t str[256];
	wchar_t str2[256];
	wchar_t str3[256];
	wchar_t str4[256];
	wchar_t str5[256];
	wchar_t str6[256];
	wchar_t str7[256];
	wchar_t str8[256];
	wchar_t str9[256];

	wchar_t strmous[256]; //�}�E�X�J�[�\���p

	bool Spaceship_back;
	bool StarPicbook;
	bool StarPicbook2;
	bool StarPicbook3;
	bool StarPicbook4;
	bool StarPicbook5;
	bool StarPicbook6;
	bool StarPicbook7;
	bool StarPicbook8;
	bool StarPicbook9;
	bool StarPicbook10;
	bool StarPicbook11;
	bool StarPicbook12;
	bool Starmodel;
	bool Starmodel2;
	bool Starmodel3;
	bool Starmodel4;
	bool Starmodel5;
	bool Starmodel6;
	bool Starmodel7;
	bool Starmodel8;
	bool Starmodel9;
	bool Starmodel10;
	bool Starmodel11;
	bool Starmodel12;

	float m_mou_time; //�A���I��h�~�^�C��

	float Back_time; //�A���ړ��h�~�^�C��
};
