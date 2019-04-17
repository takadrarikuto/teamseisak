//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

#include"GameHead.h"
#include"Objstaminagauge.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

extern bool Ancer_on;
extern bool Aitem_on;

//�C�j�V�����C�Y
void CObjstaminagauge::Init()
{
	Aitem_flag = true;
	Aitem_co_max = 5;

	m_px = 702.0f;
	m_py = 551.0f;

	m_vx = 0.0f;
	m_vax = 0.0f;

	stamina_co = 0;
	time_co = 0;
	stamina_back = 0;

	m_mous_l = false;
	stamina_flag = false;
}

//�A�N�V����
void CObjstaminagauge::Action()
{
	m_mous_l = Input::GetMouButtonL();
	
	time_co++;

	//�A���J�[�̈ʒu�������Ă���
	CObjAncer* Ancer = (CObjAncer*)Objs::GetObj(OBJ_ANCER);
	float ay = Ancer->GetY();


	//�X�^�~�i��
	if (Input::GetVKey('A') == true)
	{
		if (Aitem_co_max > 0)
		{
			if (Aitem_flag == true)
			{
				Aitem_co_max -= 1;
				m_vx -= 30.0f;
				Aitem_flag = false;
			}
		}
		else
		{
			;
		}
	}
	else
	{
		Aitem_flag = true;
	}

	if (time_co > 30)
	{
		//���N���b�N�ŃX�^�~�i5���� 
		if (m_mous_l == true && ay > 535.0f)
		{		
			stamina_flag = true;
			m_vax = 5.0f;
		}
		else
		{
			m_mous_l = false;
		}
	}

	if (stamina_flag == true)
	{
		stamina_back += 1;
		m_vax *= stamina_back;
		stamina_flag = false;
	}

	
	//�̗͌�������
	stamina_co += 1;

	//5�b��1�X�^�~�i����
	if (stamina_co == 300)
	{
		m_vx += 1.0f;
		stamina_co = 0;
	}
	
	//�X�^�~�i���ő�l�A�ŏ��l�𒴂��Ȃ��悤�ɂ��鏈��
	if (m_vx < 0)
	{
		m_vx = 0.0f;
	}
	else if (m_vx > 96.0f || m_vax > 96.0f)
	{
		m_vx = 96.0f;
		m_vax = 96.0f;
	}
	
	//�X�^�~�i�������Ȃ�ƉF���D��
	if (m_vx == 96.0f || m_vax == 96.0f)
	{
		Scene::SetScene(new CSceneStageselect());
	}


}
//�h���[
void CObjstaminagauge::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�w�i
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 70.0;
	src.m_right = 80.0f;
	src.m_bottom = 4.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 6.0f + m_py;
	dst.m_left = 0.0f + m_px + m_vx + m_vax;
	dst.m_right = 96.0f + m_px;
	dst.m_bottom = 22.0f + m_py;

	//�`��
	Draw::Draw(18, &src, &dst, c, 0.0f);

}
