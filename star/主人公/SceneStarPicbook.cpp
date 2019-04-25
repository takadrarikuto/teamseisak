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

	Draw::LoadImage(L"嶍�.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"�V����.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"�o�q��.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"���r��.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"�ˎ��.png", 6, TEX_SIZE_512);
	Draw::LoadImage(L"���q��.png", 7, TEX_SIZE_512);
	Draw::LoadImage(L"�R�r��.png", 8, TEX_SIZE_512);
	Draw::LoadImage(L"����.png", 10, TEX_SIZE_512);
	Draw::LoadImage(L"�I��.png", 11, TEX_SIZE_512);
	Draw::LoadImage(L"������.png", 12, TEX_SIZE_512);
	Draw::LoadImage(L"���r��.png", 13, TEX_SIZE_512);
	Draw::LoadImage(L"������.png", 14, TEX_SIZE_512);

	//���}�ӃI�u�W�F�N�g����
	if(lever==0)
	{
		//���}�ӃI�u�W�F�N�g����
		CObjStarPicbook* p = new CObjStarPicbook();
		Objs::InsertObj(p, OBJ_STARPICBOOK, 9);
	}
	else if (lever == 1)
	{
		//�݂�����
		CObjStarPresent4* a = new CObjStarPresent4();
		Objs::InsertObj(a, OBJ_STARPRESENT4, 11);
	}
	else if (lever == 2)
	{
		//����
		CObjStarPresent5* a = new CObjStarPresent5();
		Objs::InsertObj(a, OBJ_STARPRESENT5, 11);
	}
	else if (lever == 3)
	{
		//�Ђ�
		CObjStarPresent6* a = new CObjStarPresent6();
		Objs::InsertObj(a, OBJ_STARPRESENT6, 11);
	}
	else if (lever== 4)
	{
		//������
		CObjStarPresent2* a = new CObjStarPresent2();
		Objs::InsertObj(a, OBJ_STARPRESENT2, 11);
	}
	else if (lever == 5)
	{
		//�ӂ�����
		CObjStarPresent7* a = new CObjStarPresent7();
		Objs::InsertObj(a, OBJ_STARPRESENT7, 11);
	}
	else if (lever == 6)
	{
		//���ɍ�
		CObjStarPresent8* a = new CObjStarPresent8();
		Objs::InsertObj(a, OBJ_STARPRESENT8, 11);
	}
	else if (lever == 7)
	{
		//���ɍ�
		CObjStarPresent9* a = new CObjStarPresent9();
		Objs::InsertObj(a, OBJ_STARPRESENT9, 11);
	}
	else if (lever == 8)
	{
		//���Ƃߍ�
		CObjStarPresent10* a = new CObjStarPresent10();
		Objs::InsertObj(a, OBJ_STARPRESENT10, 11);
	}
	else if (lever == 9)
	{
		//�V����
		CObjStarPresent3* a = new CObjStarPresent3();
		Objs::InsertObj(a, OBJ_STARPRESENT3, 11);
	}
	else if (lever == 10)
	{
		//���}�ӃI�u�W�F�N�g����
		CObjStarPresent* s = new CObjStarPresent();
		Objs::InsertObj(s, OBJ_STARPRESENT, 10);
	}
	else if (lever == 11)
	{
		CObjStarmodel* a = new CObjStarmodel();
		Objs::InsertObj(a, OBJ_STARMODEL, 12);
	}
	else if (lever == 13)
	{
		//�݂����ߍ�
	}
	else if (lever == 14)
	{
		//������
	}
	else if (lever == 15)
	{
		//�Ђ���
	}
	else if (lever == 16)
	{
		//������
	}
	else if (lever == 17)
	{
		//�ӂ���
	}
	else if (lever == 18)
	{
		//����
	}
	else if (lever == 19)
	{
		//����
	}
	else if (lever == 20)
	{
		//���Ƃ�
	}
}

//�Q�[���^�C�g�����s���\�b�h
void CSceneStarPicbook::Scene()
{

}