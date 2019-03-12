//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"

#include "GameHead.h"
#include "ObjHero.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjHero::Init()
{
	//�ʒu������
	m_px = 400.0f;
	m_py = 520.0f;

	//�ړ��x�N�g��������
	m_vx = 0.0f;

	//��l������������
	m_pos = 3.0f;

	m_ani_time = 0;
	m_ani_frame = 1;	//�Î~�t���[���������ɂ���

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

	if (m_ani_time > 4)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	m_px += m_vx;

	//��ʊO�ɏo�Ȃ�����
	if (m_px < 0.0f)
	{
		m_px = 0.0f;
	}
	if (m_px + 50.0f > 800.0f)
	{
		m_px = 800.0f - 50.0f;
	}


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