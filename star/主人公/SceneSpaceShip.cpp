//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneSpaceShip.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneSpaceShip::CSceneSpaceShip()
{

}

//�f�X�g���N�^
CSceneSpaceShip::~CSceneSpaceShip()
{

}

//���������]�b�g
void CSceneSpaceShip::InitScene()
{



}

//���s�����]�b�g
void CSceneSpaceShip::Scene()
{
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMars());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}