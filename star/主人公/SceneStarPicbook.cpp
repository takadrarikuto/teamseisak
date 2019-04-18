//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;
extern int lever;

//�g�p�w�b�_�[
#include "SceneStarPicbook.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneStarPicbook::CSceneStarPicbook()
{

}

//�f�X�g���N�^
CSceneStarPicbook::~CSceneStarPicbook()
{

}

//�Q�[���^�C�g�����������\�b�h
void CSceneStarPicbook::InitScene()
{	
	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"�e�L�X�g�{�b�N�X.png", 9, TEX_SIZE_512);

	Draw::LoadImage(L"�u���b�N�^�C��.png", 1, TEX_SIZE_512);

	//���}�ӃI�u�W�F�N�g����
	if(lever==0)
	{
		CObjStarPicbook* p = new CObjStarPicbook();
		Objs::InsertObj(p, OBJ_STARPICBOOK, 9);
	}
	if (lever == 1)
	{
		//���}�ӃI�u�W�F�N�g����
		CObjStarPresent* s = new CObjStarPresent();
		Objs::InsertObj(s, OBJ_STARPRESENT, 10);
	}

	if (lever==2)
	{
		CObjStarPresent2* a = new CObjStarPresent2();
		Objs::InsertObj(a, OBJ_STARPRESENT2, 11);
	}

}

//�Q�[���^�C�g�����s���\�b�h
void CSceneStarPicbook::Scene()
{

}