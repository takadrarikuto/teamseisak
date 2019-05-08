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
	OBJ_SATURN,
	OBJ_VENUS,
	OBJ_JUPITER,
	OBJ_FIRSTSTAR,
	OBJ_SECONDSTAR,
	OBJ_THIRDSTAR,
	OBJ_FOURTHSTAR,
	OBJ_OTHERSTAR,
	OBJ_OPERATION,
	OBJ_BACKGROUND,
	OBJ_GAMEKURIA,
	OBJ_STARPRESENT,
	OBJ_STARPRESENT2,
	OBJ_STARPRESENT3,
	OBJ_STARPRESENT4,
	OBJ_STARPRESENT5,
	OBJ_STARPRESENT6,
	OBJ_STARPRESENT7,
	OBJ_STARPRESENT8,
	OBJ_STARPRESENT9,
	OBJ_STARPRESENT10,
	OBJ_AITEM,
	OBJ_EVENT,
	OBJ_IBENT,
	OBJ_STARCOUNT,
	OBJ_STRENGTHGAUGE,
	OBJ_STRENGTHGAUGEFRAME1,
	OBJ_STRENGTHGAUGEFRAME2,
	OBJ_POSE,
	OBJ_QTE,
	OBJ_STARMODEL,
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
	int star_co;//���̐��J�E���g
	int Aitem_co_max = 5; //�A�C�e����

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
#include "ObjMars.h"
#include "ObjJupiter.h"
#include "ObjVenus.h"
#include "ObjSaturn.h"
#include "ObjAncer.h"
#include "ObjFirstStar.h"
#include "ObjSecondStar.h"
#include "ObjThirdStar.h"
#include "ObjFourthStar.h"
#include "ObjOtherStar.h"
#include "ObjBackground.h"
#include "ObjOperation.h"
#include "ObjGamekuria.h"
#include "CObjStarPicbook.h"
#include "ObjStarPresent.h"
#include "ObjStarPresent2.h"
#include "ObjStarPresent3.h"
#include "ObjStarPresent4.h"
#include "ObjStarPresent5.h"
#include "ObjStarPresent6.h"
#include "ObjStarPresent7.h"
#include "ObjStarPresent8.h"
#include "ObjStarPresent9.h"
#include "ObjStarPresent10.h"
#include "ObjAitem.h"
#include "ObjEvent.h"
#include "ObjStarCount.h"
#include "Objstaminagauge.h"
#include "Objstaminagaugeframe.h"
#include "ObjPose.h"
#include "ObjStarmodel.h"

//------------------------------------------------

//�Q�[���V�[���N���X�w�b�_------------------------
#include "SceneTitle.h"
#include "SceneStageselect.h"
#include "SceneStarPicbook.h"
#include "SceneMars.h"
#include "SceneJupiter.h"
#include "SceneVenus.h"
#include "SceneSaturn.h"
#include "SceneOperation.h"
#include "SceneGamekuria.h"
//------------------------

//�V�[���X�^�[�g�N���X---------------------------
//�Q�[���J�n���̃V�[���N���X�o�^
#define SET_GAME_START CSceneTitle

//-----------------------------------------------