#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�^�C�g��
class CObjStarCount : public CObj
{
public:
	CObjStarCount() {};
	~CObjStarCount() {};
	void Init();      //�C�j�V�����C�Y
	void Action();    //�A�N�V����
	void Draw();      //�h���[

private:
	
	bool star_flag; //���t���O

	wchar_t str[256];

	float m_px;
	float m_py;
};