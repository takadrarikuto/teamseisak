//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneMars.h"
#include"GameHead.h"

//�Q�[�����C�����������\�b�h
void CSceneMars::InitScene()
{
	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"��l���i���j.png", 10, TEX_SIZE_512);

	//����l���I�u�W�F�N�g����
	CObjHero* hero = new CObjHero();
	Objs::InsertObj(hero, OBJ_HERO, 10);

	//�O���O���t�B�b�N��ǂݍ���4�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"�ΐ�.png", 4, TEX_SIZE_512);

	//�ΐ��I�u�W�F�N�g�쐬
	CObjMars* mars = new CObjMars();       //�^�C�g���I�u�W�F�N�g�쐬
	Objs::InsertObj(mars, OBJ_MARS, 4);    //�^�C�g���I�u�W�F�N�g�o�^
}

//�Q�[�����C�����s�����\�b�h
void CSceneMars::Scene()
{

}