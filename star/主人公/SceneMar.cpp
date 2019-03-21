//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMar.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneMar::CSceneMar()
{

}

//�f�X�g���N�^
CSceneMar::~CSceneMar()
{

}

//���������]�b�g
void CSceneMar::InitScene()
{
	//�O���t�B�b�N�ǂݍ���
	//�w�i
	Draw::LoadImage(L"�ΐ�.png", 8, TEX_SIZE_512);
	Draw::LoadImage(L"�t�B�[���h�w�i�ΐ�(���ߍς�).png", 9, TEX_SIZE_512);
	//��l��
	Draw::LoadImage(L"��l���i���j.png", 10, TEX_SIZE_512);
	//�A���J�[
	Draw::LoadImage(L"�A���J�[�i���@���ߍς݁j.png", 11, TEX_SIZE_512);

	//����l���I�u�W�F�N�g����
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//�A���J�[�I�u�W�F�N�g�쐬
	CObjAncer* obj_a = new CObjAncer();
	Objs::InsertObj(obj_a, OBJ_ANCER, 11);

	//�w�i�I�u�W�F�N�g����
	CObjMars* obj_m = new CObjMars();
	Objs::InsertObj(obj_m, OBJ_MARS, 8);
	CObjstage* obj_h = new CObjstage();
	Objs::InsertObj(obj_h, OBJ_STAGE, 9);
}

//���s�����]�b�g
void CSceneMar::Scene()
{

}