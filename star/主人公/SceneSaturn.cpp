//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneSaturn.h"
#include "GameHead.h"


//���������]�b�g
void CSceneSaturn::InitScene()
{
	//�O���t�B�b�N�ǂݍ���
	//�w�i
	Draw::LoadImage(L"�t�B�[���h�w�i�ΐ�(���ߍς�).png", 8, TEX_SIZE_512);
	Draw::LoadImage(L"�C�x���g�w�i(�ΐ�).png", 9, TEX_SIZE_512);
	Draw::LoadImage(L"�ΐ�.png", 10, TEX_SIZE_512);

	//��l��
	Draw::LoadImage(L"��l��.png", 11, TEX_SIZE_512);
	//�A���J�[
	Draw::LoadImage(L"�A���J�[�i���@���ߍς݁j.png", 12, TEX_SIZE_512);

	//�O���O���t�B�b�N��ǂݍ���5�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"��(���ߍς�).png", 13, TEX_SIZE_512);

	//�w�i�I�u�W�F�N�g����
	CObjMars* obj_m = new CObjMars();
	Objs::InsertObj(obj_m, OBJ_MARS, 8);
	CObjIbent* obj_i = new CObjIbent();
	Objs::InsertObj(obj_i, OBJ_IBENT, 9); //�C�x���g�w�i	
	CObjstage* obj_h = new CObjstage();
	Objs::InsertObj(obj_h, OBJ_STAGE, 10);


	//����l���I�u�W�F�N�g����
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 11);

	//�A���J�[�I�u�W�F�N�g�쐬
	CObjAncer* obj_a = new CObjAncer();
	Objs::InsertObj(obj_a, OBJ_ANCER, 12);

	//�X�^�[�I�u�W�F�N�g�쐬
	CObjFirstStar* star = new CObjFirstStar();
	Objs::InsertObj(star, OBJ_MARS, 13);    //�X�^�[�I�u�W�F�N�g�o�^

	//�A�C�e���I�u�W�F�N�g����
	CObjAitem* obj_ai = new CObjAitem();
	Objs::InsertObj(obj_ai, OBJ_AITEM, 14);

	//�X�^�[�J�E���g�I�u�W�F�N�g�쐬
	CObjStarCount* obj_sc = new CObjStarCount();
	Objs::InsertObj(obj_sc, OBJ_STARCOUNT, 15);

	//���������ԏ�����
	time_star = 0;

	//�������t���O������
	star_flag = false;

}

//���s�����]�b�g
void CSceneSaturn::Scene()
{

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
		CObjFirstStar* star = new CObjFirstStar();
		Objs::InsertObj(star, OBJ_MARS, 13);    //�X�^�[�I�u�W�F�N�g�o�^

		time_star = 0;
		star_flag = false;
	}

	

}