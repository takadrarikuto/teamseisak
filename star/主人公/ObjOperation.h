#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�^�C�g��
class CObjOperation : public CObj
{
public:
	CObjOperation() {};
	~CObjOperation() {};
	void Init();      //�C�j�V�����C�Y
	void Action();    //�A�N�V����
	void Draw();      //�h���[

private:
	bool m_mous_l; //���N���b�N�t���O
	bool m_start_flag;
	float m_mous_x; //�}�E�X�̈ʒuX
	float m_mous_y; //�}�E�X�̈ʒuY

};