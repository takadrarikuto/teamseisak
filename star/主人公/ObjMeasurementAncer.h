#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

#define Ancer_InitialTime (0.0f) //�A���J�[�E���[�v���ʏ����l


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�@�A���J�[
class CObjMeasurementAncer : public CObj
{
public:
	CObjMeasurementAncer() {};
	~CObjMeasurementAncer() {};

	void Init();
	void Action();
	void Draw();

private:

	//�ʒu
	float m_pafx; //�򋗗�����p�A���J�[
	float m_pafy;
	//�A���J�[�T�C�Y�ύX�p
	float m_sizex;
	float m_sizey;
	float size;
	float hitbox_size; //�q�b�g�{�b�N�X�T�C�Y�����p

	//�ړ��x�N�g��
	float m_vfx; //�򋗗�����p�A���J�[
	float m_vfy;

	bool m_mous_l;
	int time_co; //��ʈړ����N���h�~�p
	float ancer_time; //�A���J�[�򋗗�����

	bool ancer_flag; //�A���J�[�ړ��t���O
	bool ancer_Prevent_doublepress; //�A�����˖h�~�t���O

	bool Ancer_flag; //�򋗗�����p�A���J�[�쐬

};