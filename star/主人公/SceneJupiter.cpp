//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneJupiter.h"
#include "GameHead.h"



//���������]�b�g
void CSceneJupiter::InitScene()
{
	//�O���t�B�b�N�ǂݍ���
	//�w�i
	Draw::LoadImage(L"�ʏ펞�w�i.png", 8, TEX_SIZE_512);
	Draw::LoadImage(L"�C�x���g�w�i(�ΐ�).png", 9, TEX_SIZE_512);
	Draw::LoadImage(L"�ؐ�.png", 10, TEX_SIZE_512);

	//��l��
	Draw::LoadImage(L"��l��.png", 11, TEX_SIZE_512);
	//�A���J�[
	Draw::LoadImage(L"�A���J�[�i���@���ߍς݁j.png", 12, TEX_SIZE_512);

	//�O���O���t�B�b�N��ǂݍ���5�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"��(���ߍς�).png", 13, TEX_SIZE_512);
	Draw::LoadImage(L"�h�����N���2.png", 14, TEX_SIZE_512);
	Draw::LoadImage(L"brown_star.png", 16, TEX_SIZE_512);

	//�Q�[�W�֌W
	//�̗�
	Draw::LoadImage(L"�Q�[�W�g.png", 17, TEX_SIZE_512);
	Draw::LoadImage(L"�Q�[�W.png", 18, TEX_SIZE_512);

	
	//�w�i�I�u�W�F�N�g����
	CObjBackground* obj_h = new CObjBackground();
	Objs::InsertObj(obj_h, OBJ_BACKGROUND, 8);
	CObjEvent* obj_i = new CObjEvent();
	Objs::InsertObj(obj_i, OBJ_EVENT, 9); //�C�x���g�w�i	
	CObjMars* obj_m = new CObjMars();
	Objs::InsertObj(obj_m, OBJ_MARS, 10);


	//����l���I�u�W�F�N�g����
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 11);

	//�A���J�[�I�u�W�F�N�g�쐬
	CObjAncer* obj_a = new CObjAncer();
	Objs::InsertObj(obj_a, OBJ_ANCER, 12);


	//�A�C�e���I�u�W�F�N�g����
	CObjAitem* obj_ai = new CObjAitem();
	Objs::InsertObj(obj_ai, OBJ_AITEM, 14);

	//�X�^�[�J�E���g�I�u�W�F�N�g�쐬
	CObjStarCount* obj_sc = new CObjStarCount();
	Objs::InsertObj(obj_sc, OBJ_STARCOUNT, 15);

	//�Q�[�W�֌W
	//�X�^�~�i�I�u�W�F�N�g�쐬
	CObjstaminagaugeframe* obj_stf = new CObjstaminagaugeframe();
	Objs::InsertObj(obj_stf, OBJ_STRENGTHGAUGEFRAME1, 17);
	CObjstaminagauge* obj_st = new CObjstaminagauge();
	Objs::InsertObj(obj_st, OBJ_STRENGTHGAUGE, 18);


	//���������ԏ�����
	time_star = 0;
}

//���s�����]�b�g
void CSceneJupiter::Scene()
{
	arise = rand() % 200;

	if (arise <= 1 && arise >= 0)
	{
		//�X�^�[�I�u�W�F�N�g�쐬
		CObjFirstStar* star = new CObjFirstStar();
		Objs::InsertObj(star, OBJ_FIRSTSTAR, 13);    //�X�^�[�I�u�W�F�N�g�o�^
	}
	if (arise <= 3 && arise >= 2)
	{
		//�X�^�[�I�u�W�F�N�g�쐬
		CObjSecondStar* star2 = new CObjSecondStar();
		Objs::InsertObj(star2, OBJ_SECONDSTAR, 16);    //�X�^�[�I�u�W�F�N�g�o�^
	}

}