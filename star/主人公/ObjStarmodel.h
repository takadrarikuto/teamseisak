#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�C�x���g
class CObjStarmodel : public CObj
{
public:
	CObjStarmodel() {};	//�R���X�g���N�^
	~CObjStarmodel() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	float m_mou_x;//�}�E�X�̈ʒuX
	float m_mou_y;//�}�E�X�̈ʒuX
	bool m_mou_r;//�}�E�X�̉E�{�^��
	bool m_mou_l;//�}�E�X�̍��{�^��

	wchar_t str[256];

	int size;
	int size_y;
	int m_y;
	int font;
	int ver;
	int VER_start; //�o�[������
	bool starmodel_flag;

};
