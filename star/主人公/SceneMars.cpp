//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMars.h"
#include "GameHead.h"



//���������]�b�g
void CSceneMars::InitScene()
{
	occur = 0;
	m_Pf = false;
	m_key_f = false;//�s������

	//�O���t�B�b�N�ǂݍ���
	//�w�i
	Draw::LoadImage(L"�ʏ펞�w�i.png", 8, TEX_SIZE_512);
	Draw::LoadImage(L"�C�x���g�w�i(�ΐ�).png", 9, TEX_SIZE_512);
	Draw::LoadImage(L"�ΐ��n�\.png", 10, TEX_SIZE_512);

	//��l��
	Draw::LoadImage(L"��l��.png", 11, TEX_SIZE_512);
	//�A���J�[
	Draw::LoadImage(L"�A���J�[�i���@���ߍς݁j.png", 12, TEX_SIZE_512);

	//�O���O���t�B�b�N��ǂݍ���5�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"��(���ߍς�).png", 13, TEX_SIZE_512);
	Draw::LoadImage(L"�h�����N���2.png", 14, TEX_SIZE_512);
	Draw::LoadImage(L"brown_star.png", 16, TEX_SIZE_512);
	Draw::LoadImage(L"green_star.png", 19, TEX_SIZE_512);

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
void CSceneMars::Scene()
{
	CObjPose* pob = (CObjPose*)Objs::GetObj(OBJ_POSE);

	//�|�[�Y
	if (pob == nullptr)
		m_Pf = false;

	while (1)
	{
		if (Input::GetVKey('P') == true)//M�L�[���͎�
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
							Sleep(1);
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
	arise = rand() % 10;

	if (occur == 60)
	{
		if (arise < 2 && arise > 0)
		{
			//�X�^�[�I�u�W�F�N�g�쐬
			CObjFirstStar* star = new CObjFirstStar();
			Objs::InsertObj(star, OBJ_FIRSTSTAR, 13);    //�X�^�[�I�u�W�F�N�g�o�^
		}


		if (arise < 3 && arise > 1)
		{
			//�X�^�[�I�u�W�F�N�g�쐬
			CObjSecondStar* star2 = new CObjSecondStar();
			Objs::InsertObj(star2, OBJ_SECONDSTAR, 16);    //�X�^�[�I�u�W�F�N�g�o�^
		}
		if (arise < 4 && arise > 2)
		{
			//�X�^�[�I�u�W�F�N�g�쐬
			CObjOtherStar* star3 = new CObjOtherStar();
			Objs::InsertObj(star3, OBJ_OTHERSTAR, 19);    //�X�^�[�I�u�W�F�N�g�o�^
		}
		occur = 0;
	}

}