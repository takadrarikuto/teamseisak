//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneStageselect.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneStageselect::CSceneStageselect()
{

}

//�f�X�g���N�^
CSceneStageselect::~CSceneStageselect()
{

}

//���������]�b�g
void CSceneStageselect::InitScene()
{
	//�O���t�B�b�N�ǂݍ���
	//Draw::LoadImage(L"�F���D�w�i.png", 11, TEX_SIZE_512);
	Draw::LoadImage(L"�f��(���ߍς�).png", 12, TEX_SIZE_512);

	//�X�e�[�W�I����ʃI�u�W�F�N�g����
	CObjStageselect* obj_ss = new CObjStageselect();
	Objs::InsertObj(obj_ss, OBJ_STAGESELECT, 11);

	CObjSelectPlanet* obj_sp = new CObjSelectPlanet();
	Objs::InsertObj(obj_sp, OBJ_STAGESELECTPLANET, 12);

}

//���s�����]�b�g
void CSceneStageselect::Scene()
{

}