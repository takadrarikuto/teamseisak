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
#include "SceneGameKuria.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneGameKuria::CSceneGameKuria()
{

}

//�f�X�g���N�^
CSceneGameKuria::~CSceneGameKuria()
{

}

//���������]�b�g
void CSceneGameKuria::InitScene()
{
	//���y���ǂݍ���
	Audio::LoadAudio(0, L"�Q�[���N���A���BGM.wav", BACK_MUSIC);


	//�o�b�N�~���[�W�b�N�X�^�[�g
	Audio::Start(0);


	//�O���O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"�Q�[���N���A.png", 11, TEX_SIZE_512);


	//�^�C�g���I�u�W�F�N�g����
	CObjGameKuria* obj_t = new CObjGameKuria();
	Objs::InsertObj(obj_t, OBJ_GAMEKURIA, 11);
}

//���s�����]�b�g
void CSceneGameKuria::Scene()
{

}