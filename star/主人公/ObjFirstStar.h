#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�^�C�g��
class CObjFirstStar : public CObj
{
public:
	CObjFirstStar() {};
	~CObjFirstStar() {};
	void Init();      //�C�j�V�����C�Y
	void Action();    //�A�N�V����
	void Draw();      //�h���[

private:
	float m_move;//���E�X�N���[���p
	float m_px;
	float m_py;
	float m_vx; //�ړ��x�N�g��
	float m_vy;
	
	int star_co; //���̐��J�E���g
	bool star_flag; //���t���O

	wchar_t str[256];


};