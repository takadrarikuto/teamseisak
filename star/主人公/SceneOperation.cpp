// STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneOperation.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneOperation::CSceneOperation()
{

}

//�f�X�g���N�^
CSceneOperation::~CSceneOperation()
{

}

//�Q�[�����C�����������\�b�h
void CSceneOperation::InitScene()
{
	//���y���ǂݍ���
	Audio::LoadAudio(0, L"������BGM .wav", BACK_MUSIC);


	//�o�b�N�~���[�W�b�N�X�^�[�g
	Audio::Start(0);

	
	//�O���O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"�Q�[������.png", 17, TEX_SIZE_512);
	
	CObjOperation* obj_o = new CObjOperation();
	Objs::InsertObj(obj_o, OBJ_OPERATION, 17);

}

//�Q�[�����C�����s�����\�b�h
void CSceneOperation::Scene()
{

}