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
};
