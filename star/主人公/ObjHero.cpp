//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
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
	//�A���J�[�{��
	//Hits::SetHitBox(this, m_px + 50.0f, m_py, 20, 50, ELEMENT_ANCER, OBJ_ANCER, 10);

}

//�A�N�V����
void CObjHero::Action()
{
	//�ړ��x�N�g���j��
	m_vx = 0.0f;

	//��l�������Œ�
	m_pos = 3.0f;


	//�ړ�����
	//��
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= 4.0f;
		m_pos = 1.0f;
		m_ani_time += 1;
	}
	//�E
	else if (Input::GetVKey(VK_RIGHT) == true)
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

	//�X�e�[�W�I����ʂɖ߂�
	if (Input::GetVKey('B') == true)
	{
		if (m_return_flag = true)
		{
			Scene::SetScene(new CSceneStageselect());
		}
	}
	else
	{
		m_return_flag = true;
	}

	//�A�C�e���g�p
	if (Input::GetVKey('A') == true)
	{

	}

	//���ݏ������Ă��鐯�̐��m�F��ʂɈړ�
	if (Input::GetVKey('S') == true)
	{

	}

	//�|�[�Y�ֈړ�
	if (Input::GetVKey(VK_SPACE) == true)
	{

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

	//�؂���ʒu�̈ʒu
	src.m_top = (65.0f* m_pos);
	src.m_left = 0.0f + AniData[m_ani_frame] * 64;
	src.m_right = 60.0f + AniData[m_ani_frame] * 64;
	src.m_bottom = (65 + 65.0f *m_pos);

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f  + m_px;
	dst.m_right = 50.0f + m_px;
	dst.m_bottom = 50.0f + m_py;

	Draw::Draw(10, &src, &dst, c, 0.0f);
}