//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

extern bool EM_flag;
extern bool Event_Star;//�C�x���g�����̈ړ������ύX
extern int Event_Conversion; //�C�x���g�G���A�؂�ւ�

//�g�p�w�b�_�[
#include "SceneSaturn.h"
#include "GameHead.h"
#include <random>
#include <stdlib.h> // rand()�֐��p
#include <time.h>   // time()�֐��p

std::random_device srd{};
/**
 * �d�ݕt���Œ��I���s��
 * @param pArray ���I����Ώۂ̔z��
 * @param Length �z��̃T�C�Y
 */
int CSceneSaturn::WeightedPick(int* pArray, int Length) {
	int totalWeight = 0;
	int pick = 0;

	// �g�[�^���̏d�݂��v�Z����
	for (int i = 0; i < Length; i++) {
		totalWeight += pArray[i];
	}


	// ���I����
	int rnd = srd() % totalWeight;

	for (int i = 0; i < Length; i++) {
		if (rnd < pArray[i]) {
			// ���I�Ώی���
			pick = i;
			break;
		}

		// ���̑Ώۂ𒲂ׂ�
		rnd -= pArray[i];
	}

	return pick;
}

//���������]�b�g
void CSceneSaturn::InitScene()
{
	//���y���ǂݍ���
	Audio::LoadAudio(0, L"���C��BGMTitle.wav", BACK_MUSIC);
	Audio::LoadAudio(1, L"���ʉ�.wav", EFFECT);


	occur = 0;
	m_Pf = false;
	m_key_f = false;//�s������

	//�O���t�B�b�N�ǂݍ���
	//�w�i
	Draw::LoadImage(L"�ʏ펞�w�i.png", 8, TEX_SIZE_512);
	Draw::LoadImage(L"���q.png", 9, TEX_SIZE_512);
	Draw::LoadImage(L"�ΐ��n�\.png", 10, TEX_SIZE_512);

	//��l��
	Draw::LoadImage(L"��l��.png", 11, TEX_SIZE_512);
	//�A���J�[
	Draw::LoadImage(L"�򋗗�����p�A���J�[.png", 12, TEX_SIZE_512);
	Draw::LoadImage(L"�A���J�[�i���@���ߍς݁j.png", 13, TEX_SIZE_512);

	//�O���O���t�B�b�N��ǂݍ���5�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"yellow_star.png", 16, TEX_SIZE_512);
	Draw::LoadImage(L"red_star.png", 17, TEX_SIZE_512);
	Draw::LoadImage(L"pink_star.png", 18, TEX_SIZE_512);
	Draw::LoadImage(L"green_star.png", 19, TEX_SIZE_512);
	Draw::LoadImage(L"brown_star.png", 20, TEX_SIZE_512);


	//�Q�[�W�֌W
	//�̗�
	Draw::LoadImage(L"�Q�[�W�g.png", 21, TEX_SIZE_512);
	Draw::LoadImage(L"�Q�[�W.png", 22, TEX_SIZE_512);

	//�r�b�N���}�[�N
	Draw::LoadImage(L"�r�b�N���}�[�N.png", 23, TEX_SIZE_512);

	//�w�i�I�u�W�F�N�g����
	CObjBackground* obj_h = new CObjBackground();
	Objs::InsertObj(obj_h, OBJ_BACKGROUND, 8);
	CObjEvent* obj_i = new CObjEvent();
	Objs::InsertObj(obj_i, OBJ_EVENT, 9); //�C�x���g�w�i	
	CObjMars* obj_m = new CObjMars();
	Objs::InsertObj(obj_m, OBJ_MARS, 10);

	//��l���I�u�W�F�N�g����
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 11);

	//�A���J�[�I�u�W�F�N�g�쐬
	CObjMeasurementAncer* obj_ma = new CObjMeasurementAncer();
	Objs::InsertObj(obj_ma, OBJ_MANCER, 12);
	CObjAncer* obj_a = new CObjAncer();
	Objs::InsertObj(obj_a, OBJ_ANCER, 13);

	//�A�C�e���I�u�W�F�N�g����
	CObjAitem* obj_ai = new CObjAitem();
	Objs::InsertObj(obj_ai, OBJ_AITEM, 14);

	//�X�^�[�J�E���g�I�u�W�F�N�g�쐬
	CObjStarCount* obj_sc = new CObjStarCount();
	Objs::InsertObj(obj_sc, OBJ_STARCOUNT, 15);

	//�Q�[�W�֌W
	//�X�^�~�i�I�u�W�F�N�g�쐬
	CObjstaminagaugeframe* obj_stf = new CObjstaminagaugeframe();
	Objs::InsertObj(obj_stf, OBJ_STRENGTHGAUGEFRAME1, 21);
	CObjstaminagauge* obj_st = new CObjstaminagauge();
	Objs::InsertObj(obj_st, OBJ_STRENGTHGAUGE, 22);

	//�r�b�N���}�[�N�I�u�W�F�N�g�쐬
	CObjExclamationMark* obj_em = new CObjExclamationMark();
	Objs::InsertObj(obj_em, OBJ_EM, 23);

	//���������ԏ�����
	time_star = 0;

	//1�����쐬�x���p�J�E���g������
	Star_time = 0.0f;
	//1�����쐬�x���p�t���O������
	Star_flag = false;

	Event_Star = false;
	Event_Conversion = 3;
}

//���s�����]�b�g
void CSceneSaturn::Scene()
{
	CObjPose* pob = (CObjPose*)Objs::GetObj(OBJ_POSE);

	//�|�[�Y
	if (pob == nullptr)
		m_Pf = false;

	while (1)
	{
		if (Input::GetVKey('P') == true)//P�L�[���͎�
		{

			if (m_Pf == true) {//m_f��true�̏ꍇ
							   //�R�}���h�pSE��炷


				while (1)
				{
					if (Input::GetVKey('Z') == true)
					{
						Scene::SetScene(new CSceneTitle());
						break;
					}

					if (Input::GetVKey('X') == true)//X�L�[���͎�
					{
						if (m_Pf == true)
						{
							//�|�[�Y�I�u�W�F�N�g���폜
							if (pob != nullptr)
								pob->SetAf(true);
							break;
						}
					}
				}

			}

			if (m_Pf == false) {
				//�|�[�Y�I�u�W�F�N�g�쐬
				CObjPose* po = new CObjPose();       //�|�[�Y�I�u�W�F�N�g�쐬
				Objs::InsertObj(po, OBJ_POSE, 11);    //�|�[�Y�I�u�W�F�N�g�o�^
				m_Pf = true;

			}
			else {}
		}
		break;
	}
	occur++;
	//�@3/4�b���Ƃɐ����o��������
	if (occur == 45)
	{
		//�d�ݕt���ŏo�������鐯�����߂�
		int Items[] = { 1, 5, 20,40,60 };
		int result = WeightedPick(Items, 5);


		//1�����쐬0.7%
		if (result == 0)
		{
			Star_flag = true; //1�����쐬�x���p�t���O �I��
		}

		//2�����쐬 3.9%
		if (result == 1)
		{
			//�X�^�[�I�u�W�F�N�g�쐬
			CObjSecondStar* star2 = new CObjSecondStar(0.0f);
			Objs::InsertObj(star2, OBJ_SECONDSTAR, 11);    //�X�^�[�I�u�W�F�N�g�o�^
		}
		//3�����쐬 15.8%
		if (result == 2)
		{
			//�X�^�[�I�u�W�F�N�g�쐬
			CObjThirdStar* star3 = new CObjThirdStar(0.0f);
			Objs::InsertObj(star3, OBJ_THIRDSTAR, 12);    //�X�^�[�I�u�W�F�N�g�o�^
		}
		//4�����쐬 31.7%
		if (result == 3)
		{
			//�X�^�[�I�u�W�F�N�g�쐬
			CObjFourthStar* star4 = new CObjFourthStar(0.0f);
			Objs::InsertObj(star4, OBJ_FOURTHSTAR, 13);    //�X�^�[�I�u�W�F�N�g�o�^
		}
		//5�����ȉ��쐬 47.6%
		if (result == 4)
		{
			//�X�^�[�I�u�W�F�N�g�쐬
			CObjOtherStar* star5 = new CObjOtherStar(0.0f);
			Objs::InsertObj(star5, OBJ_OTHERSTAR, 14);    //�X�^�[�I�u�W�F�N�g�o�^
		}
		occur = 0;
	}

	//1�����쐬���x������
	if (Star_flag == true)
	{
		Star_time++;
		EM_flag = true; //�r�b�N���}�[�N�o���t���O �I��
	}

	//5�b��1�����쐬
	if (Star_time == 300.0f)
	{
		//�X�^�[�I�u�W�F�N�g�쐬
		CObjFirstStar* star = new CObjFirstStar(0.0f);
		Objs::InsertObj(star, OBJ_FIRSTSTAR, 10);    //�X�^�[�I�u�W�F�N�g�o�^


		Star_time = 0.0f; //1�����쐬�x���p�J�E���g������	
		Star_flag = false; //1�����쐬�x���p�t���O������
		EM_flag = false; //�r�b�N���}�[�N�o���t���O������
	}

	//QTE
	//CObjQTE* obj_qte = new CObjQTE();
	//Objs::InsertObj(obj_qte, OBJ_QTE, 20);

}