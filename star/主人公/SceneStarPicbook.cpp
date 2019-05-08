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

	Draw::LoadImage(L"�p�X�e���u���[�^�C��.png", 1, TEX_SIZE_512);

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


	//�����}�ӃI�u�W�F�N�g����

	//���}�ӃI�u�W�F�N�g����
	if (lever == 0)
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
		CObjStarPresent* s = new CObjStarPresent();
		Objs::InsertObj(s, OBJ_STARPRESENT, 10);
	}
	else if (lever == 3)
	{
		//�Ђ�
		CObjStarPresent* s = new CObjStarPresent();
		Objs::InsertObj(s, OBJ_STARPRESENT, 10);
	}
	else if (lever == 4)
	{
		//������
		CObjStarPresent* s = new CObjStarPresent();
		Objs::InsertObj(s, OBJ_STARPRESENT, 10);
	}
	else if (lever == 5)
	{
		//�ӂ�����
		CObjStarPresent* s = new CObjStarPresent();
		Objs::InsertObj(s, OBJ_STARPRESENT, 10);
	}
	else if (lever == 6)
	{
		//���ɍ�
		CObjStarPresent* s = new CObjStarPresent();
		Objs::InsertObj(s, OBJ_STARPRESENT, 10);
	}
	else if (lever == 7)
	{
		//���ɍ�
		CObjStarPresent* s = new CObjStarPresent();
		Objs::InsertObj(s, OBJ_STARPRESENT, 10);
	}
	else if (lever == 8)
	{
		//���Ƃߍ�
		CObjStarPresent* s = new CObjStarPresent();
		Objs::InsertObj(s, OBJ_STARPRESENT, 10);
	}
	else if (lever == 9)
	{
		//�V����
		CObjStarPresent* s = new CObjStarPresent();
		Objs::InsertObj(s, OBJ_STARPRESENT, 10);
	}
	else if (lever == 10)
	{
		//嶍�
		CObjStarPresent* s = new CObjStarPresent();
		Objs::InsertObj(s, OBJ_STARPRESENT, 10);
	}
	else if (lever == 11)
	{
		//�ˎ��
		CObjStarPresent* s = new CObjStarPresent();
		Objs::InsertObj(s, OBJ_STARPRESENT, 10);
	}
	else if (lever == 12)
	{
		//�R�r��
		CObjStarPresent* s = new CObjStarPresent();
		Objs::InsertObj(s, OBJ_STARPRESENT, 10);
	}
	else if (lever == 13)
	{
		//�݂����ߍ�
		CObjStarmodel* a = new CObjStarmodel();
		Objs::InsertObj(a, OBJ_STARMODEL, 12);
	}
	else if (lever == 14)
	{
		//������
		CObjStarmodel* a = new CObjStarmodel();
		Objs::InsertObj(a, OBJ_STARMODEL, 12);
	}
	else if (lever == 15)
	{
		//�Ђ���
		CObjStarmodel* a = new CObjStarmodel();
		Objs::InsertObj(a, OBJ_STARMODEL, 12);
	}
	else if (lever == 16)
	{
		//������
		CObjStarmodel* a = new CObjStarmodel();
		Objs::InsertObj(a, OBJ_STARMODEL, 12);
	}
	else if (lever == 17)
	{
		//�ӂ���
		CObjStarmodel* a = new CObjStarmodel();
		Objs::InsertObj(a, OBJ_STARMODEL, 12);
	}
	else if (lever == 18)
	{
		//����
		CObjStarmodel* a = new CObjStarmodel();
		Objs::InsertObj(a, OBJ_STARMODEL, 12);
	}
	else if (lever == 19)
	{
		//����
		CObjStarmodel* a = new CObjStarmodel();
		Objs::InsertObj(a, OBJ_STARMODEL, 12);
	}
	else if (lever == 20)
	{
		//���Ƃ�
		CObjStarmodel* a = new CObjStarmodel();
		Objs::InsertObj(a, OBJ_STARMODEL, 12);
	}
	else if (lever == 21)
	{
		//�Ă�т�
		CObjStarmodel* a = new CObjStarmodel();
		Objs::InsertObj(a, OBJ_STARMODEL, 12);
	}
	else if (lever == 22)
	{
		//������
		CObjStarmodel* a = new CObjStarmodel();
		Objs::InsertObj(a, OBJ_STARMODEL, 12);
	}
	else if (lever == 23)
	{
		//����
		CObjStarmodel* a = new CObjStarmodel();
		Objs::InsertObj(a, OBJ_STARMODEL, 12);
	}
	else if (lever == 24)
	{
		//�€
		CObjStarmodel* a = new CObjStarmodel();
		Objs::InsertObj(a, OBJ_STARMODEL, 12);
	}

}

//�Q�[���^�C�g�����s���\�b�h
void CSceneStarPicbook::Scene()
{

}