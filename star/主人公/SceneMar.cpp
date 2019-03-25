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
	Draw::LoadImage(L"��l��.png", 10, TEX_SIZE_512);
	//�A���J�[
	Draw::LoadImage(L"�A���J�[�i���@���ߍς݁j.png", 11, TEX_SIZE_512);

	//�O���O���t�B�b�N��ǂݍ���5�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"��(���ߍς�).png", 12, TEX_SIZE_512);


	//��l���I�u�W�F�N�g����
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

	//���������ԏ�����
	time_star = 0;

	//�������t���O������
	star_flag = false;
}

//���s�����]�b�g
void CSceneMar::Scene()
{
	/*
	//���̈ʒu�̎擾
	CObjFirstStar* star = (CObjFirstStar*)Objs::GetObj(OBJ_FIRSTSTAR);
	float sx = star->GetX();
	float sy = star->GetY();
	*/

	if (time_star == 30)
	{
		star_flag = true;
	}

	if (star_flag == false)
	{
		time_star++;
	}
	else if (star_flag == true)
	{
		//�X�^�[�I�u�W�F�N�g�쐬
		CObjFirstStar* star = new CObjFirstStar(0.0f, 100.0f);
		Objs::InsertObj(star, OBJ_MARS, 12);    //�X�^�[�I�u�W�F�N�g�o�^

		time_star = 0;
		star_flag = false;
	}
	
	/*
	if (time_star == 1)
	{
		//�X�^�[�I�u�W�F�N�g�쐬
		CObjFirstStar* star = new CObjFirstStar(0.0f, 0.0f);
		Objs::InsertObj(star, OBJ_MARS, 12);    //�X�^�[�I�u�W�F�N�g�o�^
	}
	else if (time_star == 10)
	{
		//�X�^�[�I�u�W�F�N�g�쐬
		CObjFirstStar* star = new CObjFirstStar(0.0f, 100.0f);
		Objs::InsertObj(star, OBJ_MARS, 12);    //�X�^�[�I�u�W�F�N�g�o�^
	}
	else if (time_star = 60)
	{
		time_star = 0;
	}
	*/

}