#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�@�A���J�[
class CObjAncer : public CObj
{
public:
	CObjAncer() {};
	~CObjAncer() {};

	void Init();
	void Action();
	void Draw();

	float GetX() { return m_pax; }
	float GetY() { return m_pay; }
private:

	//�ʒu
	float m_px; //�{��
	float m_py;
	float m_pax; //�A���J�[
	float m_pay;
	float m_prx; //���[�v
	float m_pry;

	//�ړ��x�N�g��
	float m_vx;
	float m_vy;

	bool m_mous_l;
	float time;

	bool ancer_flag; //�A���J�[�ړ��t���O

};