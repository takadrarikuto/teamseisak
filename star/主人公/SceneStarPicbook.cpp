//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

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
	CObjStarPicbook* p = new CObjStarPicbook();
	Objs::InsertObj(p, OBJ_STARPICBOOK,1);
}

//�Q�[���^�C�g�����s���\�b�h
void CSceneStarPicbook::Scene()
{

}