//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

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
	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"�^�C�g��.png", 11, TEX_SIZE_512);

	//�^�C�g���I�u�W�F�N�g����
	CObjTitle* obj_t = new CObjTitle();
	Objs::InsertObj(obj_t, OBJ_TITLE, 11);

}

//���s�����]�b�g
void CSceneTitle::Scene()
{

}