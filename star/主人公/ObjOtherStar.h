#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�^�C�g��
class CObjOtherStar : public CObj
{
public:
	CObjOtherStar() {};
	~CObjOtherStar() {};
	CObjOtherStar(float x, float y); //�R���X�g���N�^
	void Init();      //�C�j�V�����C�Y
	void Action();    //�A�N�V����
	void Draw();      //�h���[

					  //float GetX() { return m_px; }
					  //float GetY() { return m_py; }
private:
	float m_move;//���E�X�N���[���p
	float m_px;
	float m_py;
	float m_vx; //�ړ��x�N�g��
	float m_vy;

	bool hero_flag; //��l���t���O
	bool ancer_flag; //�A���J�[�t���O


};