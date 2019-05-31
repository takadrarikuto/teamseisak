//GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

#include "CObjStarPicbook.h"
#include "GameHead.h"
extern int lever;
extern int star_count;//�������J�E���g�p

extern int g_first_star;
extern int g_second_star;
extern int g_third_star;
extern int g_fouth_star;
extern int g_other_star;

void CObjStarPicbook::Init()
{
	starmodel_flag = false;
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;

	Spaceship_back = false;
	StarPicbook = false;
	StarPicbook2 = false;
	StarPicbook3 = false;
	StarPicbook4 = false;
	StarPicbook5 = false;
	StarPicbook6 = false;
	StarPicbook7 = false;
	StarPicbook8 = false;
	StarPicbook9 = false;
	StarPicbook10 = false;
	StarPicbook11 = false;
	StarPicbook12 = false;
	Starmodel = false;
	Starmodel2 = false;
	Starmodel3 = false;
	Starmodel4 = false;
	Starmodel5 = false;
	Starmodel6 = false;
	Starmodel7 = false;
	Starmodel8 = false;
	Starmodel9 = false;
	Starmodel10 = false;
	Starmodel11 = false;
	Starmodel12 = false;

	m_mou_time = 0.0f;

	a_time = 0;
	a_time_max = 8;
	Back_time = 0.0f;

	Audio::LoadAudio(1, L"���ʉ�.wav", EFFECT);
}

void CObjStarPicbook::Action()
{
	int	ver = 0;
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	Spaceship_back = false;

	

	//�A���ړ��h�~
	if (m_mou_time == 60.0f)
	{
		;
	}
	else if(m_mou_time < 60.0f)
	{
		m_mou_time++;
		m_mou_l = false;
	}


	//�F���D�փ{�^��
	// left				 right            top            bottom         
	if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>0 && m_mou_y < 100)
	{
		Spaceship_back = true;
		if (m_mou_l == true)
		{
			time_flag = true;			
		}
	}
	else
	{
		Spaceship_back = false;
	}

	//���������Ɩ߂�
	if (Input::GetVKey('B') == true && Back_time > 60.0f)
	{
		lever = 0;
		a_time = 0;
		Back_time = 0.0f;
		time_flag = false;
		Scene::SetScene(new CSceneStageselect());
	}

	if (Spaceship_back == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 0;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStageselect());
		}
	}
	else if (StarPicbook == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 1;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			starmodel_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (StarPicbook2 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 2;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			starmodel_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (StarPicbook3 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 3;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			starmodel_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (StarPicbook4 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 4;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			starmodel_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (StarPicbook5 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 5;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (StarPicbook6 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 6;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (StarPicbook7 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 7;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (StarPicbook8 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 8;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (StarPicbook9 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 9;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}		
	}
	else if (StarPicbook10 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 10;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			starmodel_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}	
	}
	else if (StarPicbook11 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 11;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}		
	}
	else if (StarPicbook12 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 12;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (Starmodel == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 13;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			starmodel_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}

	}
	else if (Starmodel2 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 14;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			starmodel_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (Starmodel3 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 15;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			starmodel_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (Starmodel4 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 16;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			starmodel_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (Starmodel5 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 17;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (Starmodel6 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 18;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (Starmodel7 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 19;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (Starmodel8 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 20;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (Starmodel9 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 21;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}

	}
	else if (Starmodel10 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 22;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			starmodel_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (Starmodel11 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 23;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}
	else if (Starmodel12 == true)
	{
		if (a_time >= a_time_max)
		{
			lever = 24;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}

	//SE��������
	if (m_mou_l == true)
	{
		time_flag = true;
	}
	else if (m_mou_l == false)
	{
		time_flag = false;
		if (a_time > 1)
		{
			a_time++;
		}
		else
		{
			a_time = 0;
		}
	}



	if (time_flag == true)
	{
		a_time++;
	}
	else if (time_flag == false)
	{
		a_time = 0;
	}

	//SE��������
	if (a_time == 1)
	{
		Audio::Start(1);
	}


	Back_time++;



}

void CObjStarPicbook::Draw()
{
	int g = 200.0f;//���g�̉��� 200.0f
	int k = 75;//���g�̗��� 75.0f
	int t = 70;//���̖��O�̈ʒu 70
	int l = 0;//t�Ɗ|����p�̕ϐ� 0
	int s = 0;//���̃N���b�N�̌� 0
	int std = 0;//���������Ɉڂ��ϐ� 0
	int side_a = 0;//���̘g�͈� 0
	int side_b = 200;//�E�̘g�͈� 200
	int side_c = 129;//129
	int fy = 200;//���̖��O�̉��� 200
	int font_size = 25;//�����̑傫�� 25
	int  Interval_y = 35;//�����̗����Ԋu 35
	int  left_end = 80;//�������̍��̌��E�����߂� 80

	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float p[4] = { 1.0f,1.0f,1.0f,0.6f, };

	//�J�[�\���\��(�������������)
	


	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�T�C�o�[�w�i�̐؂���
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 513.0f;
	src.m_bottom = 289.0f;

	//�w�i��`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(15, &src, &dst, c, 0.0f);

	//�p�X�e���u���[�^�C���̐؂���
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 130.0f;
	src.m_bottom = 67.0f;

	//���}�ӂ̘g��`��
	dst.m_top = 300.0f;
	dst.m_left = 0.0f;
	dst.m_right = 67.0f;
	dst.m_bottom = 600.0f;
	
	//���[�v���ĕ`�悷��
	for (int i = 0; i <= 3; i++)
	{
		//���̖��O�̘g��`��
		dst.m_top = 300.0f;
		dst.m_left = 0.0f + g * i;
		dst.m_right = 200.0f + g * i;
		dst.m_bottom = 300.0f + k;
		Draw::Draw(1, &src, &dst, p, 0.0f);
		Draw::Draw(9, &src, &dst, c, 0.0f);
		for (int l = 0; l <= 2; l++)
		{

			dst.m_top = 375.0f + k * l;
			dst.m_bottom = 450.0f + k * l;
			Draw::Draw(1, &src, &dst, p, 0.0f);
			Draw::Draw(9, &src, &dst, c, 0.0f);
		}

	}
	
	

	//�������̔w�i������`��
	dst.m_top = 0.0f;
	dst.m_left = 67.0f;
	dst.m_right =800.0f;
	dst.m_bottom = 300.0f;
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.0f);

	//�߂�{�^���̘g��`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 67.0f;
	dst.m_bottom = 100.0f;
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.0f);

	//���̃y�[�W�ɍs�����߂̃{�^���̘g��`��
	dst.m_top = 200.0f;
	dst.m_bottom = 300.0f;

	//���ւ̘g
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.0f);

	dst.m_top = 100.0f;
	dst.m_bottom = 200.0f;

	//�߂��̘g
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.0f);

	int Dc = 0; //�`��D��x�����p

	//嶍��̉摜�ʒu
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 764.0f;
	src.m_bottom = 578.0f;

	dst.m_top = 376.0f;
	dst.m_left = 530.0f;
	dst.m_right =600.0f;
	dst.m_bottom = 450.0f;
	
	//��������摜
	Draw::Draw(2, &src, &dst, c, 0.0f);
	
	Dc += 1;
	
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1104.0f;
	src.m_bottom = 844.0f;

	dst.m_top = 300.0f;
	dst.m_bottom = 374.0f;

	//�Ă�т���摜
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 400.0f;
	src.m_bottom = 400.0f;

	dst.m_top = 300.0f;
	dst.m_bottom = 374.0f;
	dst.m_left = 330.0f;
	dst.m_right = 400.0f;


	//�ӂ������摜
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 654.0f;
	src.m_bottom = 578.0f;

	dst.m_left = 130.0f;
	dst.m_right = 200.0f;
	
	//�݂����ߍ��摜
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;
	
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 764.0f;
	src.m_bottom = 578.0f;

	dst.m_top = 450.0f;
	dst.m_left = 530.0f;
	dst.m_right =600.0f;
	dst.m_bottom = 524.0f;

	//���č��摜
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1192.0f;
	src.m_bottom = 872.0f;

	dst.m_top = 450.0f;
	dst.m_bottom = 524.0f;
	dst.m_left = 330.0f;
	dst.m_right = 400.0f;

	//�������摜
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 764.0f;
	src.m_bottom = 578.0f;

	dst.m_top = 523.0f;
	dst.m_left = 530.0f;
	dst.m_right = 600.0f;
	dst.m_bottom = 600.0f;

	//�€���摜
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 2;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1360.0f;
	src.m_bottom = 880.0f;

	dst.m_top = 376.0f;
	dst.m_bottom = 450.0f;
	dst.m_left = 130.0f;
	dst.m_right = 200.0f;

	//�������摜
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 884.0f;
	src.m_bottom = 624.0f;

	dst.m_top = 376.0f;
	dst.m_bottom = 450.0f;
	dst.m_left = 330.0f;
	dst.m_right = 400.0f;

	//���ɍ��摜
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1308.0f;
	src.m_bottom = 776.0f;

	dst.m_top = 523.0f;
	dst.m_bottom = 600.0f;
	dst.m_left = 330.0f;
	dst.m_right = 400.0f;

	//���Ƃߍ��摜
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 424.0f;
	src.m_bottom = 320.0f;

	dst.m_top = 450.0f;
	dst.m_bottom = 524.0f;
	dst.m_left = 130.0f;
	dst.m_right = 200.0f;

	//���Ђ����摜
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);
	Dc += 1;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 424.0f;
	src.m_bottom = 320.0f;

	dst.m_left = 130.0f;
	dst.m_right = 200.0f;
	dst.m_top = 526.0f;
	dst.m_bottom = 600.0f;

	//���������摜
	Draw::Draw(2 + Dc, &src, &dst, c, 0.0f);


	//�F���D�ւ̕�����`�悷��
	//					�@�@X�@Y�@�傫��
	Font::StrDraw(L"�F��", 10, 25, 25, c);
	Font::StrDraw(L"�D��", 10, 50, 25, c);

	Font::StrDraw(L"���r��", 30 + fy * std, 330 + t*l, 30, c);
	l++;         
	//���r���͈̔�
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>290 + k * (l - 1) && m_mou_y < 295 + k * l)
	{
		if (star_count < 200)
		{
			time_flag = false;
			StarPicbook = false;
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���200�W�߂Ă�������", left_end, 260, font_size, c);
		}
		else if (star_count >= 200)
		{
			StarPicbook = true;
		}
		

		if (m_mou_l == true && star_count >= 200)
		{	
			time_flag = true;
		}
	}
	else
	{
		StarPicbook = false;
	}


	if (m_mou_x > 150 && m_mou_x < 197 * (std + 1) && m_mou_y>290 + k * (l - 1) && m_mou_y < 290 + k * l)
	{
		if (star_count < 200)
		{
			time_flag = false;
			Starmodel = false;
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���200�W�߂Ă�������", left_end, 260, font_size, c);
		}
		else if (star_count >= 200)
		{
			Starmodel = true;
		}

		if (m_mou_l == true && star_count >= 200)
		{
			time_flag = true;
		}
	}
	else
	{
		Starmodel = false;
	}

	
	Font::StrDraw(L"����", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	//�����͈̔�
    if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>290 + k * (l - 1) && m_mou_y < 290 + k * l)
	{
		if (star_count < 800 && g_first_star < 3)
		{
			time_flag = false;
			StarPicbook2 = false;
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���800�A1������3��", left_end, 240, font_size, c);
			Font::StrDraw(L"�W�߂Ă�������", left_end, 270, font_size, c);
		}

		if (star_count >= 800 && g_first_star >= 3)
		{
			StarPicbook2 = true;
		}

		if (m_mou_l == true && star_count >= 800 && g_first_star >= 3)
		{
			time_flag = true;				
		}
	}
	else
	{
		StarPicbook2 = false;
	}

	if (m_mou_x >150&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k*(l - 1) && m_mou_y < 300 + 73 * l)
	  {
		if (star_count <800 && g_first_star < 3)
		{
			time_flag = false;
			Starmodel2 = false;
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���800�A1������3�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (star_count >= 800 && g_first_star >= 3)
		{
			Starmodel2 = true;
		}

		if (m_mou_l == true && star_count >= 800 && g_first_star >= 3)
		{
			time_flag = true;
		}
	}
	else
	{
		Starmodel2 = false;
	}

	//���r��
	Font::StrDraw(L"���r��", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>290 + k * (l - 1) && m_mou_y < 290 + k * l)
	{
		if (star_count <140 )
		{
			time_flag = false;
			StarPicbook3 = false;
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���140�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (star_count >= 140)
		{
			StarPicbook3 = true;
		}

		if (m_mou_l == true && star_count >= 140)
		{
			time_flag = true;				
		}
	}
	else
	{
		StarPicbook3 = false;
	}

	if (m_mou_x > 150&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (star_count < 140)
		{
			time_flag = false;
			Starmodel3 = false;
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���140�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (star_count >= 140)
		{
			Starmodel3 = true;
		}


		if (m_mou_l == true && star_count >= 140)
		{
			time_flag = true;
		}
	}
	else
	{
		Starmodel3 = false;
	}

	//������
	Font::StrDraw(L"������", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>290 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (star_count <200)
		{
			time_flag = false;
			StarPicbook4 = false;
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���200�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (star_count >= 200)
		{
			StarPicbook4 = true;
		}

		if (m_mou_l == true&&star_count>=200)
		{
			time_flag = true;
		}
	}
	else
	{
		StarPicbook4 = false;
	}

	if (m_mou_x > 150&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (star_count < 200)
		{
			time_flag = false;
			Starmodel4 = false;
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���200�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (star_count >= 200)
		{
			Starmodel4 = true;
		}

		if (m_mou_l == true && star_count >= 200)
		{
			time_flag = true;
		}
	}
	else
	{
		Starmodel4 = false;
	}

	t -= 4;
	l -= 4;
	std=1;

	//�o�q��
	Font::StrDraw(L"�o�q��", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70*std+side_c*(std + 1) && m_mou_y>290 + k * (l - 1) && m_mou_y < 290 + k * l)
	{
		if (star_count < 260)
		{
			time_flag = false;
			StarPicbook5 = false;
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���260�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (star_count >= 260)
		{
			StarPicbook5 = true;
		}

		if (m_mou_l == true && star_count >= 260)
		{
			time_flag = true;
		}
	}
	else
	{
		StarPicbook5 = false;
	}

	if (m_mou_x > 325&& m_mou_x < 197 * (std + 1) && m_mou_y>290 + k * (l - 1) && m_mou_y < 290 + k * l)
	{
		if (star_count < 260)
		{
			time_flag = false;
			Starmodel5 = false;
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���260�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (star_count >= 260)
		{
			Starmodel5 = true;
		}

		if (m_mou_l == true && star_count >= 260)
		{
			time_flag = true;
		}
	}
	else
	{
		Starmodel5 = false;
	}

	//�I��
	Font::StrDraw(L"�I��", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>295 + k * (l - 1) && m_mou_y < 295 + k * l)
	{
		if (star_count < 400)
		{
			time_flag = false;
			StarPicbook6 = false;
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���400�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (star_count >= 400)
		{
			StarPicbook6 = true;
		}

		if (m_mou_l == true&&star_count >= 400)
		{
			time_flag = true;
		}
	}
	else
	{
		StarPicbook6 = false;
	}
	if (m_mou_x > 325 && m_mou_x < 197 * (std + 1) && m_mou_y>295 + k * (l - 1) && m_mou_y < 290 + k * l)
	{
		if (star_count < 400)
		{
			time_flag = false;
			Starmodel6 = false;
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���400�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (star_count >= 400)
		{
			Starmodel6 = true;
		}

		if (m_mou_l == true && star_count >= 400)
		{
			time_flag = true;
		}
	}
	else
	{
		Starmodel6 = false;
	}

	//���q��
	Font::StrDraw(L"���q��", 30 + fy * std, 350 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>290 + k * (l - 1) && m_mou_y < 290 + k * l)
	{
		if (star_count < 450)
		{
			time_flag = false;
			StarPicbook7 = false;
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���450�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (star_count >= 450)
		{
			StarPicbook7 = true;
		}

		if (m_mou_l == true && star_count >= 450)
		{
			time_flag = true;
		}
	}
	else
	{
		StarPicbook7 = false;
	}

	if (m_mou_x > 325 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (star_count < 450)
		{
			time_flag = false;
			Starmodel7 = false;
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���450�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (star_count >= 450)
		{
			Starmodel7 = true;
		}

		if (m_mou_l == true && star_count >= 450)
		{
			time_flag = true;
		}
	}
	else
	{
		Starmodel7 = false;
	}

	//������
	Font::StrDraw(L"������", 30 + fy * std, 350 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>290 + k * (l - 1) && m_mou_y < 290 + k * l)
	{
		if (star_count <500)
		{
			time_flag = false;
			StarPicbook8 = false;
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���500�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (star_count >= 500)
		{
			StarPicbook8 = true;
		}

		if (m_mou_l == true && star_count >= 500)
		{
			time_flag = true;
		}
	}
	else
	{
		StarPicbook8 = false;
	}

	if (m_mou_x > 325 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (star_count < 500)
		{
			time_flag = false;
			Starmodel8 = false;
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���500�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (star_count >= 500)
		{
			Starmodel8 = true;
		}

		if (m_mou_l == true && star_count >= 500)
		{
			time_flag = true;
		}
	}
	else
	{
		Starmodel8 = false;
	}

	t -= 4;
	l -= 4;
	std = 2;
	//�V����
	Font::StrDraw(L"�V����", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>290 + k * (l - 1) && m_mou_y < 295 + k * l)
	{
		if (star_count <150 )
		{
			time_flag = false;
			StarPicbook9 = false;
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���150�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (star_count >= 150)
		{
			StarPicbook9 = true;
		}

		if (m_mou_l == true && star_count >= 150)
		{
			time_flag = true;			
		}
	}
	else
	{
		StarPicbook9 = false;
	}
	if (m_mou_x > 500 && m_mou_x < 197 * (std + 1) && m_mou_y>290 + k * (l - 1) && m_mou_y < 290 + k * l)
	{
		if (star_count < 150)
		{
			time_flag = false;
			Starmodel9 = false;
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���150�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (star_count >= 150)
		{
			Starmodel9 = true;
		}

		if (m_mou_l == true)
		{
			time_flag = true;
		}
	}
	else
	{
		Starmodel9 = false;
	}

	Font::StrDraw(L"嶍�", 30 + fy * std, 330 + t*l, 30, c);
	l++;

	//嶍�				left		     right							 top						 bottom       
	if (m_mou_x > side_a + side_b * std && m_mou_x < 70 * std+side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 295 + k * l)
	{
		// �{���̐���
		if (star_count < 50 || g_other_star < 50)
		{
			time_flag = false;
			StarPicbook10 = false;
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ōܓ�����50�W�߂Ă�������", left_end, 260, font_size, c);
		}
	
		if (star_count >= 50)
		{
			StarPicbook10 = true;
		}

		if (m_mou_l == true&& star_count >= 50&& g_other_star>=50)
		{
			time_flag = true;
		}

	}
	else
	{
		StarPicbook10 = false;
	}

	//   left				  right			  top			 bottom                
	if (m_mou_x > 130+200*std&& m_mou_x < 197*(std+1) && m_mou_y>302+k*(l-1) && m_mou_y < 300+73*l)
	{
		if (g_other_star < 50)
		{
			time_flag = false;
			Starmodel10 = false;
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ōܓ�����50�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (star_count >= 50)
		{
			Starmodel10 = true;
		}

		if (m_mou_l == true && star_count >= 50 && g_other_star >= 50)
		{
			time_flag = true;
		}
	}
	else
	{
		Starmodel10 = false;
	}

	//�ˎ��
	Font::StrDraw(L"�ˎ��", 30 + fy * std, 350 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>290 + k * (l - 1) && m_mou_y < 290 + k * l)
	{
		if (star_count < 550)
		{
			time_flag = false;
			StarPicbook11 = false;
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���550�W�߂Ă�������", left_end, 260, font_size, c);
		}
		if (star_count >= 550)
		{
			StarPicbook11 = true;
		}

		if (m_mou_l == true && star_count >= 550)
		{
			time_flag = true;
		}
	}
	else
	{
		StarPicbook11 = false;
	}

	if (m_mou_x > 520 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (star_count < 550)
		{
			time_flag = false;
			Starmodel11 = false;
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���550�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (star_count >= 550)
		{
			Starmodel11 = true;
		}

		if (m_mou_l == true && star_count >= 550)
		{
			time_flag = true;
		}
	}
	else
	{
		Starmodel11 = false;
	}

	//�R�r��
	Font::StrDraw(L"�R�r��", 30 + fy * std, 360 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>290 + k * (l - 1) && m_mou_y < 290 + k * l)
	{
		if (star_count < 680)
		{
			time_flag = false;
			StarPicbook12 = false;
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���100�W�߂Ă�������", left_end, 260, font_size, c);
		}
		if (star_count >= 680)
		{
			StarPicbook12 = true;
		}

		if (m_mou_l == true && star_count >= 680)
		{
			time_flag = true;
		}
	}
	else
	{
		StarPicbook12 = false;
	}
	if (m_mou_x > 500 && m_mou_x < 197 * (std + 1) && m_mou_y>290 + k * (l - 1) && m_mou_y < 290 + k * l)
	{
		if (star_count < 740)
		{
			time_flag = false;
			Starmodel12 = false;
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���100�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (star_count >= 740)
		{
			Starmodel12 = true;
		}

		if (m_mou_l == true && star_count >= 740)
		{
			time_flag = true;
		}
	}
	else
	{
		Starmodel12 = false;
	}
	std = 0;

	Font::StrDraw(L"���̖��O�ɃJ�[�\�����킹�č��N���b�N����Ƃ��̐����ɂ���", 80, 25, 25, c);
	Font::StrDraw(L"��Ȑ��̐���������܂��B", 80, 50, 25, c);
	Font::StrDraw(L"�����̊G�ɃJ�[�\�������킹�ăN���b�N����Ɛ������̂��̂�", 80, 100, 25, c);
	Font::StrDraw(L"�����ɓ���܂��B", 80, 125, 25, c);
	Font::StrDraw(L"�y�[�W���߂���ɂ͍��ɂ��鎟�ւ��N���b�N���܂��B", 80, 170,25, c);
	Font::StrDraw(L"��O�̃y�[�W�ɂ������ꍇ�͖߂���N���b�N���܂��B", 80, 195, 25, c);
	
	/*swprintf_s(strmous, L"x=%d,y=%d", (int)m_mou_x, (int)m_mou_y);
	Font::StrDraw(strmous, 600, 290, 30, c);*/

	//���ւ̕��������[�v���ďo��
	wchar_t next[2][2]{ L"��",L"��" };
	for (int i = 0; i <= 1; i++)
	{
		int l = 25;
		swprintf_s(str, L"%s", next[i]);
		//				�@�@X�@ Y�@ �傫��
		Font::StrDraw(str, 20, 130 + l * i, 25, c);
	}

	//�߂��̕��������[�v���ďo��
	wchar_t before[2][2]{ L"��",L"��" };
	for (int i = 0; i <= 1; i++)
	{
		int l = 25;
		swprintf_s(str, L"%s", before[i]);

		//				�@�@X�@ Y�@ �傫��
		Font::StrDraw(str, 20, 230 + l * i, 25, c);
	}
}