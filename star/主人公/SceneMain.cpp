//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneMain::CSceneMain()
{

}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{

}

//���������]�b�g
void CSceneMain::InitScene()
{
	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"��l���i���j.png", 10, TEX_SIZE_512);

	//����l���I�u�W�F�N�g����
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//�O���O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"�������.png", 10, TEX_SIZE_512);

	CObjOperation* obj_o = new CObjOperation();
	Objs::InsertObj(obj_o, OBJ_OPERATION, 8);


}

//���s�����]�b�g
void CSceneMain::Scene()
{

}