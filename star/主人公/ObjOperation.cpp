//GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include"GameL\SceneObjManager.h"

#include "CObjOperation.h"
#include "GameHead.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

void CObjOperation::Init()
{
	m_Operation_flag = false;
}

void CObjOperation::Action()
{
	if (m_Operation_flag == true)
	{
		if (Input::GetVKey(VK_SPACE) == true)
		{
			Scene::SetScene(new CSceneOperation());
		}

	}
	else
	{
		m_Operation_flag = true;
	}


	if (Input::GetVKey(VK_SPACE) == true)
	{
		if (m_Operation_flag == true)
		{
			Scene::SetScene(new CSceneOperation());
		}
	}
	//�X�e�[�W�I����ʂɖ߂�
	else if (Input::GetVKey('B') == true)
	{
		if (m_Operation_flag == true)
		{
			Scene::SetScene(new CSceneStageselect());
		}
	}
	else
	{
		m_Operation_flag = true;
	}


}

void CObjOperation::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̈ʒu
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1052.0f;
	src.m_bottom = 432.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(21, &src, &dst, c, 0.0f);

}
