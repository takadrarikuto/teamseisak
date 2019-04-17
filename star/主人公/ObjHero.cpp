//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjHero.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjHero::Init()
{
	//��l���ʒu������
	m_px = 400.0f;
	m_py = 520.0f;
	//�A���J�[�ʒu������
	m_ax = 450.0f;
	m_ay = 520.0f;

	//�ړ��x�N�g��������
	m_vx = 0.0f;

	//��l������������
	m_pos = 3.0f;

	m_ani_time = 0;
	m_ani_frame = 1;	//�Î~�t���[���������ɂ���

	m_return_flag = false;

	//�����蔻��p��HitBox���쐬

	//��l��
	Hits::SetHitBox(this, m_px, m_py, 50, 50, ELEMENT_PLAYER, OBJ_HERO, 10);

	m_mous_l = false;
}

//�A�N�V����
void CObjHero::Action()
{
	//�ړ��x�N�g���j��
	m_vx = 0.0f;

	//��l�������Œ�
	m_pos = 3.0f;

	m_mous_l = Input::GetMouButtonL();

	//�A���J�[�̈ʒu�̎擾
	CObjAncer* Ancer = (CObjAncer*)Objs::GetObj(OBJ_ANCER);
	float ax = Ancer->GetX();
	float ay = Ancer->GetY();

	//���N���b�N���Ă��鎞�܂��̓A���J�[��y�ʒu��535�ȉ��̎��ړ��֎~
	if (m_mous_l == false && ay > 535.0f)
	{
		//�ړ�����
		//��
		if (Input::GetVKey('A') == true)
		{
			m_vx -= 4.0f;
			m_pos = 1.0f;
			m_ani_time += 1;
		}
		//�E
		else if (Input::GetVKey('D') == true)
		{
			m_vx += 4.0f;
			m_pos = 2.0f;
			m_ani_time += 1;
		}
		else
		{
			m_ani_time = 0; //�A�j���[�V������~
			m_ani_frame = 1; //�L�[���͂������ꍇ�͐Î~�t���[���ɂ���
		}
	}
	else
	{
		m_ani_time = 0; //�A�j���[�V������~
		m_ani_frame = 1; //�L�[���͂������ꍇ�͐Î~�t���[���ɂ���
	}

	//�X�e�[�W�I����ʂɖ߂�
	if (Input::GetVKey('B') == true)
	{
		if (m_return_flag = true)
		{
			Scene::SetScene(new CSceneStageselect());
		}
	}
	//���ݏ������Ă��鐯�̐��m�F��ʂɈړ�
	else if (Input::GetVKey('S') == true)
	{
		if (m_return_flag = true)
		{
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else
	{
		m_return_flag = true;
	}

	if (m_ani_time > 4)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//�ʒu�X�V
	m_px += m_vx;

	//��ʊO�ɏo�Ȃ�����
	if (m_px < 0.0f)
	{
		m_px = 0.0f;
	}
	if (m_px + 50.0f > 777.0f)
	{
		m_px = 777.0f - 50.0f;
	}

	//���g��HitBox�������Ă���
	CHitBox* hit = Hits::GetHitBox(this);

	//HitBox�̈ʒu�̕ύX
	hit->SetPos(m_px, m_py);


}

//�h���[
void CObjHero::Draw()
{
	//���[�V����
	int AniData[4]=
	{
		1,0,2,0,
	};

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	if (m_pos == 1)
	{
		//�؂���ʒu�̈ʒu
		src.m_top = 220.0f;
		src.m_left = 35.0f + AniData[m_ani_frame] * 150;
		src.m_right = 175.0f + AniData[m_ani_frame] * 150;
		src.m_bottom = 425.0f;
	}
	else if (m_pos == 2)
	{
		//�؂���ʒu�̈ʒu
		src.m_top = 0.0f;
		src.m_left = 35.0f + AniData[m_ani_frame] * 150;
		src.m_right = 160.0f + AniData[m_ani_frame] * 150;
		src.m_bottom = 200.0f;
	}
	else if (m_pos == 3)
	{
		//�؂���ʒu�̈ʒu
		src.m_top = 20.0f;
		src.m_left =490.0f;
		src.m_right = 610.0f;
		src.m_bottom = 220.0f;
	}
	

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f  + m_px;
	dst.m_right = 50.0f + m_px;
	dst.m_bottom = 50.0f + m_py;

	Draw::Draw(11, &src, &dst, c, 0.0f);
}