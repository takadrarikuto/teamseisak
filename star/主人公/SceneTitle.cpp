//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneTitle.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneTitle::CSceneTitle()
{

}

//�f�X�g���N�^
CSceneTitle::~CSceneTitle()
{

}

//���������]�b�g
void CSceneTitle::InitScene()
{
	//���y���ǂݍ���
	//Audio::LoadAudio(0, L"�Q�[���v���CBGMTitle.wav", BACK_MUSIC);
	//Audio::LoadAudio(1, L"���艹.wav", EFFECT);


	//�o�b�N�~���[�W�b�N�X�^�[�g
/*	float Volume = Audio::VolumeMaster(-0.8f);
	Audio::Start(0);*/

	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"���ނ�^�C�g���C��.png", 11, TEX_SIZE_512);
	Draw::LoadImage(L"�p�X�e���u���[�^�C���t���[��.png", 9, TEX_SIZE_512);

	//�^�C�g���I�u�W�F�N�g����
	CObjTitle* obj_t = new CObjTitle();
	Objs::InsertObj(obj_t, OBJ_TITLE, 11);

}

//���s�����]�b�g
void CSceneTitle::Scene()
{

}