#pragma once

//�I�u�W�F�N�g�l�[��------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//�I�u�W�F�N�g������(�֎~)
	//�Q�[���Ŏg���I�u�W�F�N�g�̖��O
	//OBJ_�����ƕ\�L
	OBJ_HERO,
	OBJ_ANCER,
	OBJ_TIME,
	OBJ_TITLE,
	OBJ_STAGESELECT,
	OBJ_STAGESELECTPLANET,
	OBJ_ENEMY,
	OBJ_OBJECT,
	OBJ_STARPICBOOK,
	OBJ_MARS,
	OBJ_FIRSTSTAR,
	OBJ_SECONDSTAR,
	OBJ_OTHERSTAR,
	OBJ_OPERATION,
	OBJ_STAGE,
};
//------------------------------------------------

//�����蔻�葮��----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//�������� �S�Ă̑����Ɠ����蔻�肪���s�����
	//�ȉ��@�����������m�ł͓����蔻��͎��s����Ȃ�
	//�����͒ǉ��\�����A�f�o�b�N���̐F�͏����ݒ蕪��������
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_ANCER,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//�Z�[�u�����[�h�ƃV�[���Ԃ̂���肷��f�[�^
struct UserData
{
	int mSeveData;	//�T���v���Z�[�u�f�[�^
	
};
//------------------------------------------------


//�Q�[�����Ŏg�p�����O���[�o���ϐ��E�萔�E��--



//------------------------------------------------
//�Q�[�����Ŏg�p����N���X�w�b�_------------------


//------------------------------------------------

//�Q�[���V�[���I�u�W�F�N�g�w�b�_------------------
#include "ObjHero.h"
#include "ObjTitle.h"
#include "ObjStageselect.h"
#include "ObjSelectPlanet.h"
#include "CObjStarPicbook.h"
#include "ObjMars.h"
#include "ObjAncer.h"
#include "ObjFirstStar.h"
#include "Objstage.h"
#include "CObjOperation.h"
//------------------------------------------------

//�Q�[���V�[���N���X�w�b�_------------------------
#include "SceneMar.h"
#include "SceneTitle.h"
#include "SceneStageselect.h"
#include"SceneStarPicbook.h"
#include "SceneMars.h"
#include"SceneOperation.h"
//------------------------

//�V�[���X�^�[�g�N���X---------------------------
//�Q�[���J�n���̃V�[���N���X�o�^
//#define SET_GAME_START  CSceneMain
#define SET_GAME_START CSceneOperation
#define SET_GAME_START  CSceneStarPicbook
//#define SET_GAME_START CSceneTitle
//-----------------------------------------------