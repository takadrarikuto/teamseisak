#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�C�x���g
class CObjStarPresent : public CObj
{
public:
	CObjStarPresent() {};	//�R���X�g���N�^
	~CObjStarPresent() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	float m_mou_x;//�}�E�X�̈ʒuX
	float m_mou_y;//�}�E�X�̈ʒuX
	bool m_mou_r;//�}�E�X�̉E�{�^��
	bool m_mou_l;//�}�E�X�̍��{�^��
	bool starpresent_flag;
	bool page_flag;
	int page ;//���̃y�[�W�֍s�����߂̕ϐ�
	int page_b;
	int time;
	wchar_t str[256];
	wchar_t see[256];
	int ver;
};
