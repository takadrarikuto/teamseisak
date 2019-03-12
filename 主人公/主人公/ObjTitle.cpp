//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjTitle.h"
#include "SceneStageselect.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTitle::Init()
{
	m_mous_l = false;
	m_start_flag = false;
}

//�A�N�V����
void CObjTitle::Action()
{
	m_mous_l = Input::GetMouButtonL();

	if (m_mous_l == true)
	{
		if (m_start_flag == true)
		{
			Scene::SetScene(new CSceneStageselect());
		}
	}
	else
	{
		m_start_flag = true;
	}
}

//�h���[
void CObjTitle::Draw()
{

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̈ʒu
	src.m_top = 0.0;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(11, &src, &dst, c, 0.0f);
}