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
	CObjFirstStar(float x); //�R���X�g���N�^
	void Init();      //�C�j�V�����C�Y
	void Action();    //�A�N�V����
	void Draw();      //�h���[

	float m_move;//���E�X�N���[���p
	float m_px;
	float m_py;
	float m_vx; //�ړ��x�N�g��
	float m_vy;

	bool hero_flag; //��l���t���O
	bool ancer_flag; //�A���J�[�t���O
	bool stop_flag;//�X�g�b�v�t���O
	bool m_Sf;


	wchar_t str[256];
	int star_num;//���ԍ�

private:


};