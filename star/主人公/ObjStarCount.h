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

	wchar_t str[256];

	wchar_t strFis[256]; //1�����l�����m�F�p
	wchar_t strFos[256]; //2�����l�����m�F�p
	wchar_t strOts[256]; //3�����l�����m�F�p

	int FiStar_Reco_max; //1�����l�����m�F�p�ő吔
	int SeStar_Reco_max; //2�����l�����m�F�p�ő吔
	int ThStar_Reco_max; //3�����l�����m�F�p�ő吔

	float m_px;
	float m_py;
};