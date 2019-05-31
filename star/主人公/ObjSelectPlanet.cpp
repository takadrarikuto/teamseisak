//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameL\Audio.h"
#include "GameHead.h"
#include "ObjSelectPlanet.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;
extern int g_first_star;//1�����J�E���g
extern int star_count;//�������J�E���g�p


//�C�j�V�����C�Y
void CObjSelectPlanet::Init()
{
	m_mous_l = false;
	m_mous_x = 0.0f;
	m_mous_y = 0.0f;
	m_start_flag = false;

	Mars_up = false;
	Venus_up = false;
	Jupiter_up = false;
	Saturn_up = false;
	StarPic = false;

	Sart_flag = false;
	FiStar_flag = false;

	time_flag = false;
	a_time = 0;

	Back_time = 0.0f;
	m_mou_time = 0.0f;

	Audio::LoadAudio(1, L"���ʉ�.wav", EFFECT);
}

//�A�N�V����
void CObjSelectPlanet::Action()
{
	m_mous_l = Input::GetMouButtonL();

	//�}�E�X�̈ʒu�̎擾
	m_mous_x = (float)Input::GetPosX();
	m_mous_y = (float)Input::GetPosY();

	Mars_up = false;
	Venus_up = false;
	Jupiter_up = false;
	Saturn_up = false;

	//�A���ړ��h�~
	if (m_mou_time == 60.0f)
	{
		;
	}
	else if (m_mou_time < 60.0f)
	{
		m_mou_time++;
		m_mous_l = false;
	}


	if (m_mous_x > 60 && m_mous_x < 190 && m_mous_y>130 && m_mous_y < 325)
	{
		Mars_up = true;
		if (m_mous_l == true)
		{
			time_flag = true;
		}
	}
	if (m_mous_x > 230 && m_mous_x < 379 && m_mous_y>180 && m_mous_y < 330)
	{
		Venus_up = true;
		if (m_mous_l == true)
		{
			time_flag = true;
		}
	}
	if (m_mous_x > 422 && m_mous_x < 542 && m_mous_y>135 && m_mous_y < 325)
	{
		Jupiter_up = true;
		if (m_mous_l == true)
		{
			time_flag = true;
		}
	}
	if (m_mous_x > 585 && m_mous_x < 722 && m_mous_y>135 && m_mous_y < 325)
	{
		Saturn_up = true;
		if (m_mous_l == true)
		{
			time_flag = true;
		}
	}
	if (m_mous_x > 600 && m_mous_y > 550)
	{
		StarPic = true;
		if (m_mous_l == true)
		{
			time_flag = true;
		}
	}

	//�X�e�[�W��ʈړ�
	if (Mars_up == true)
	{
		//10�b��ɉ�ʈړ�
		if (a_time >= 10)
		{
			a_time = 0;
			Back_time = 0.0f;
			m_mou_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneMars()); //�ΐ�
		}
	}
	else if (Venus_up == true)
	{
		//10�b��ɉ�ʈړ�
		if (a_time >= 10)
		{
			a_time = 0;
			Back_time = 0.0f;
			m_mou_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneVenus()); //����
		}
	}
	else if (Saturn_up == true)
	{
		//10�b��ɉ�ʈړ�
		if (a_time >= 10)
		{
			a_time = 0;
			Back_time = 0.0f;
			m_mou_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneSaturn()); //�y��
		}
	}
	else if (Jupiter_up == true)
	{
		//10�b��ɉ�ʈړ�
		if (a_time >= 10)
		{
			a_time = 0;
			Back_time = 0.0f;
			m_mou_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneJupiter()); //�ؐ�
		}
	}
	else if (StarPic == true)
	{
		//10�b��ɉ�ʈړ�
		if (a_time >= 10)
		{
			a_time = 0;
			Back_time = 0.0f;
			m_mou_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook()); //���}��

		}
	}


	if (time_flag == true)
	{
		a_time++;
	}	
	if (m_mous_l == false && a_time > 1)
	{
		time_flag = false;
		a_time++;
	}


	if (a_time == 1)
	{
		Audio::Start(1);
	}


	Back_time++;

	//��������I����ʂɈړ�
	if (Input::GetVKey('B') == true && Back_time > 60.0f)
	{
		a_time = 0;
		Back_time = 0.0f;
		m_mou_time = 0.0f;
		time_flag = false;
		Scene::SetScene(new CSceneOperation()); 
	}

	if (star_count < 1000)
	{
		Sart_flag = false;
	}
	else if (star_count >= 1000)
	{
		Sart_flag = true;
	}
	else if (g_first_star < 5)
	{
		FiStar_flag = false;
	}
	else if (g_first_star >= 5)
	{
		FiStar_flag = true;
	}
	
}

//�h���[
void CObjSelectPlanet::Draw()
{

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"���}�ӂ�", 600, 550, 50, c);
	Font::StrDraw(L"�ǂ̐��֍s���܂����H", 150, 120, 50, c);
	Font::StrDraw(L"�ΐ�", 100, 370, 30, c);
	Font::StrDraw(L"����", 280, 370, 30, c);
	Font::StrDraw(L"�ؐ�", 460, 370, 30, c);
	Font::StrDraw(L"�y��", 640, 370, 30, c);

	if (Sart_flag == false)
	{
		swprintf_s(str, L"�N���A�܂ł̐��̍��v������%4d��", 1000 - star_count);
		Font::StrDraw(str, 10, 560, 20, c);
	}
	else if (Sart_flag == true)
	{
		swprintf_s(str, L"�N���A�@���݂̐��̍��v%4d��", star_count);
		Font::StrDraw(str, 10, 560, 20, c);
	}
	if (g_first_star == false)
	{
		swprintf_s(strFi, L"�N���A�܂ł�1�����̐����Ɓ~%d��", 5 - g_first_star);
		Font::StrDraw(strFi, 24, 580, 20, c);
	}
	else if (g_first_star == true)
	{
		swprintf_s(strFi, L"�N���A�@���݂�1�����̐��~%d��", g_first_star);
		Font::StrDraw(strFi, 24, 580, 20, c);
	}
	

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu
	RECT_F srcm; //�`�挳�؂���ʒu
	RECT_F dstm; //�`���\���ʒu
	RECT_F srcv; //�`�挳�؂���ʒu
	RECT_F dstv; //�`���\���ʒu
	RECT_F srcj; //�`�挳�؂���ʒu
	RECT_F dstj; //�`���\���ʒu
	RECT_F srcs; //�`�挳�؂���ʒu
	RECT_F dsts; //�`���\���ʒu
	RECT_F srcFi; //�`�挳�؂���ʒu
	RECT_F dstFi; //�`���\���ʒu



	//�؂���ʒu�̈ʒu
	src.m_top = 30.0;
	src.m_left = 70.0f;
	src.m_right = 1000.0f;
	src.m_bottom = 250.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 170.0f;
	dst.m_left = 70.0f;
	dst.m_right = 760.0f;
	dst.m_bottom = 370.0f;

	Draw::Draw(12, &src, &dst, c, 0.0f);

	if (Mars_up == true)
	{
		//�؂���ʒu�̈ʒu
		srcm.m_top = 40.0f;
		srcm.m_left = 60.0f;
		srcm.m_right = 240.0f;
		srcm.m_bottom = 210.0f;

		//�\���ʒu�̐ݒ�
		dstm.m_top = 160.0f;
		dstm.m_left = 50.0f;
		dstm.m_right = 210.0f;
		dstm.m_bottom = 370.0f;

		Draw::Draw(12, &srcm, &dstm, c, 0.0f);

	}
	else if (Venus_up == true)
	{
		//�؂���ʒu�̈ʒu
		srcv.m_top = 40.0f;
		srcv.m_left = 290.0f;
		srcv.m_right = 490.0f;
		srcv.m_bottom = 210.0f;

		//�\���ʒu�̐ݒ�
		dstv.m_top = 160.0f;
		dstv.m_left = 220.0f;
		dstv.m_right = 400.0f;
		dstv.m_bottom = 370.0f;

		Draw::Draw(12, &srcv, &dstv, c, 0.0f);

	}
	else if (Jupiter_up == true)
	{
		//�؂���ʒu�̈ʒu
		srcj.m_top = 50.0f;
		srcj.m_left = 540.0f;
		srcj.m_right = 720.0f;
		srcj.m_bottom = 220.0f;

		//�\���ʒu�̐ݒ�
		dstj.m_top = 160.0f;
		dstj.m_left = 410.0f;
		dstj.m_right = 560.0f;
		dstj.m_bottom = 370.0f;

		Draw::Draw(12, &srcj, &dstj, c, 0.0f);

	}
	else if (Saturn_up == true)
	{
		//�؂���ʒu�̈ʒu
		srcs.m_top = 50.0f;
		srcs.m_left = 760.0f;
		srcs.m_right = 980.0f;
		srcs.m_bottom = 210.0f;

		//�\���ʒu�̐ݒ�
		dsts.m_top = 160.0f;
		dsts.m_left = 570.0f;
		dsts.m_right = 750.0f;
		dsts.m_bottom = 370.0f;

		Draw::Draw(12, &srcs, &dsts, c, 0.0f);

	}

	//1����

	//�؂���ʒu�̐ݒ�
	srcFi.m_top = 0.0f;
	srcFi.m_left = 0.0f;
	srcFi.m_right = 100.0f;
	srcFi.m_bottom = 100.0f;


	//�\���ʒu�̐ݒ�
	dstFi.m_top = 578.0f;
	dstFi.m_left = 0.0f;
	dstFi.m_right = 22.0f;
	dstFi.m_bottom = 600.0f;

	//�`��
	Draw::Draw(13, &srcFi, &dstFi, c, 0.0f);

}