#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

#define Event_Time (130) //�C�x���g���ԃJ�E���g�p
#define Ancer_Rope_InitialTime (0.0f) //�A���J�[�E���[�v���ʏ����l


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
	float GetAncerFlag() { return ancer_flag; }

private:

	//�ʒu
	float m_px; //�{��
	float m_py;
	float m_pax; //�A���J�[
	float m_pay;
	//�A���J�[�T�C�Y�ύX�p
	float m_sizex;
	float m_sizey;
	float size;
	float hitbox_size; //�q�b�g�{�b�N�X�T�C�Y�����p
	float m_prx; //���[�v
	float m_pry;

	//�ړ��x�N�g��
	float m_vx; //�{�́E�A���J�[
	float m_vy;
	float m_vfx; //�򋗗�����p�A���J�[
	float m_vfy;

	bool m_mous_l;
	float rope; //���[�v�`��p
	int time_co; //��ʈړ����N���h�~�p
	float ancer_time; //�A���J�[�򋗗�����
	float rope_time; //���[�v�򋗗�����

	bool ancer_flag; //�A���J�[�ړ��t���O

	int A_event; //�C�x���g�^�C������
	int Ev_ancer; //�C�x���g���A���J�[����

	bool Ancer_dabletapp; //��x�����΍��p�t���O

};