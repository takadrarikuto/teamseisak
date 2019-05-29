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

	Audio_co = 0;
	m_mou_time = 0.0f;

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

	//SE��������
	if (m_mou_l == true)
	{
		Audio_co++;
	}
	else if (m_mou_l == false)
	{
		Audio_co = 0;
	}

	//SE��������
	if (Audio_co == 1)
	{
		Audio::Start(1);
	}
	else if (Audio_co > 1)
	{
		Audio_co = 2;
	}

	//�F���D�փ{�^��
	// left				 right            top            bottom         
	if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>0 && m_mou_y < 100)
	{
		if (m_mou_l == true)
		{
			time_flag = true;
			if (a_time == 10)
			{
				lever = 0;
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
				Scene::SetScene(new CSceneStageselect());
			}
			
		}

	}

	

	if (m_mou_l == true)
	{
		time_flag = true;
	}
	else if (m_mou_l == false)
	{
		a_time = 0;
		time_flag = false;
	}


	if (time_flag == true)
	{
		a_time++;
	}

	if (a_time == 1)
	{
	Audio::Start(1);
	}

	Back_time++;

	//���������Ɩ߂�
	if (Input::GetVKey('B') == true && Back_time > 60.0f)
	{
		lever = 0;
		a_time = 0;
		Back_time = 0.0f;
		time_flag = false;
		Scene::SetScene(new CSceneStageselect());
	}


}

void CObjStarPicbook::Draw()
{
	int g = 200.0f;//���g�̉��� 200.0f
	int k = 75.0f;//���g�̗��� 75.0f
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
	swprintf_s(strmous, L"x=%d,y=%d", (int)m_mou_x, (int)m_mou_y);
	Font::StrDraw(strmous, 600, 20, 30, c);


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

	if (m_mou_l == true)
	{
		time_flag = true;
	}
	else if (m_mou_l == false)
	{
		a_time = 0;
		time_flag = false;
	}


	if (time_flag == true)
	{
		a_time++;
	}

	if (a_time == 1)
	{
		Audio::Start(1);
	}

	//�F���D�ւ̕�����`�悷��
	//					�@�@X�@Y�@�傫��
	Font::StrDraw(L"�F��", 10, 25, 25, c);
	Font::StrDraw(L"�D��", 10, 50, 25, c);

	Font::StrDraw(L"���r��", 30 + fy * std, 330 + t*l, 30, c);
	l++;         
	//���r���͈̔�
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (star_count <200 )
		{
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���200�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (m_mou_l == true && star_count >= 200)
		{	
			//    top            bottom  
			//����
			if (starmodel_flag == true)
			{
				
					lever = 1;
					a_time = 0;
					Back_time = 0.0f;
					time_flag = false;
					starmodel_flag = false;
					//�V�[���č쐬�h�~(��)
					/*this->SetStatus(false);
					CObjStarPresent4* p = new CObjStarPresent4();
					Objs::InsertObj(p, OBJ_STARPRESENT4, 9);*/
					Scene::SetScene(new CSceneStarPicbook());
			
			}
			
			//�摜
			else 
			{
				starmodel_flag = true;
			}

		}

	}

	if (m_mou_x > 130 * 1 * std&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k*(l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (star_count < 200)
		{
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���200�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (m_mou_l == true && star_count >= 200)
		{
			//    top            bottom  
			//����
			if (starmodel_flag == true)
			{

				lever = 13;
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
				starmodel_flag = false;
				Scene::SetScene(new CSceneStarPicbook());

			}

			//�摜
			else
			{
				starmodel_flag = true;
			}

		}
	}
	
	
	Font::StrDraw(L"����", 30 + fy * std, 330 + t*l, 30, c);
	l++;
	//�����͈̔�
    if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (star_count < 250)
		{
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���250�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (m_mou_l == true && star_count >= 250)
		{
			if (starmodel_flag = true)
			{
				
					lever = 2;
					a_time = 0;
					Back_time = 0.0f;
					time_flag = false;
					starmodel_flag = false;
					Scene::SetScene(new CSceneStarPicbook());
				
			}
			
		}
		else
		{
			starmodel_flag = true;
		}
	}

	if (m_mou_x > 130 * 1 * std&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k*(l - 1) && m_mou_y < 300 + 73 * l)
	  {
		if (star_count < 250)
		{
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���250�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (m_mou_l == true && star_count >= 250)
		{
			if (starmodel_flag = true)
			{

				lever = 14;
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
				starmodel_flag = false;
				Scene::SetScene(new CSceneStarPicbook());

			}

		}
		else
		{
			starmodel_flag = true;
		}
	  }

	//���r��
	Font::StrDraw(L"���r��", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (star_count <300 )
		{
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���300�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (m_mou_l == true && star_count >= 300)
		{
			if (starmodel_flag == true)
			{
				
					lever = 3;
					a_time = 0;
					Back_time = 0.0f;
					time_flag = false;
					starmodel_flag = false;
					Scene::SetScene(new CSceneStarPicbook());
				
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}

	if (m_mou_x > 60+130 * 1 * std&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (star_count < 300)
		{
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���300�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (m_mou_l == true && star_count >= 300)
		{
			if (starmodel_flag == true)
			{

				lever = 15;
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
				starmodel_flag = false;
				Scene::SetScene(new CSceneStarPicbook());

			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	
	//������
	Font::StrDraw(L"������", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (star_count < 100)
		{
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���100�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (m_mou_l == true&&star_count>=100)
		{
			if (starmodel_flag = true)
			{
			
					lever = 4;
					a_time = 0;
					Back_time = 0.0f;
					time_flag = false;
					starmodel_flag = false;
					Scene::SetScene(new CSceneStarPicbook());
				
				
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}

	if (m_mou_x > 130 * 1 * std&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (star_count < 100)
		{
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���100�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (m_mou_l == true && star_count >= 100)
		{
			if (starmodel_flag = true)
			{

				lever = 16;
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
				starmodel_flag = false;
				Scene::SetScene(new CSceneStarPicbook());


			}
			else
			{
				starmodel_flag = true;
			}
		}
	}

	t -= 4;
	l -= 4;
	std=1;

	//�o�q��
	Font::StrDraw(L"�o�q��", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70*std+side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (star_count < 350)
		{
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���350�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (m_mou_l == true && star_count >= 350)
		{
			if (starmodel_flag = true)
			{
				
					lever = 5;
					a_time = 0;
					Back_time = 0.0f;
					time_flag = false;
					Scene::SetScene(new CSceneStarPicbook());
				
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}

	if (m_mou_x > 325&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (star_count < 350)
		{
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���350�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (m_mou_l == true && star_count >= 350)
		{
			if (starmodel_flag = true)
			{

				lever = 17;
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
				Scene::SetScene(new CSceneStarPicbook());

			}
			else
			{
				starmodel_flag = true;
			}
		}
	}

	//�I��
	Font::StrDraw(L"�I��", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (star_count < 400)
		{
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���400�W�߂Ă�������", left_end, 260, font_size, c);
		}
		if (m_mou_l == true&&star_count >= 400)
		{
			if (starmodel_flag = true)
			{
				
					lever = 6;
					a_time = 0;
					Back_time = 0.0f;
					time_flag = false;
					Scene::SetScene(new CSceneStarPicbook());
				
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	if (m_mou_x > 325 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (star_count < 400)
		{
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���400�W�߂Ă�������", left_end, 260, font_size, c);
		}
		if (m_mou_l == true && star_count >= 400)
		{
			if (starmodel_flag == true)
			{
				
					lever = 18;
					a_time = 0;
					Back_time = 0.0f;
					time_flag = false;
					Scene::SetScene(new CSceneStarPicbook());
				
			}
		}
		else
		{
			starmodel_flag = true;
		}
	}

	//���q��
	Font::StrDraw(L"���q��", 30 + fy * std, 350 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (star_count < 450)
		{
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���450�W�߂Ă�������", left_end, 260, font_size, c);
		}
		if (m_mou_l == true && star_count >= 450)
		{
			if (starmodel_flag = true)
			{
				
					lever = 7;
					a_time = 0;
					Back_time = 0.0f;
					time_flag = false;					
					Scene::SetScene(new CSceneStarPicbook());
				
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	if (m_mou_x > 325 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (star_count < 450)
		{
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���450�W�߂Ă�������", left_end, 260, font_size, c);
		}
		if (m_mou_l == true && star_count >= 450)
		{
			if (starmodel_flag = true)
			{

				lever = 19;
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
				Scene::SetScene(new CSceneStarPicbook());

			}
			else
			{
				starmodel_flag = true;
			}
		}
	}

	//������
	Font::StrDraw(L"������", 30 + fy * std, 350 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (star_count <500)
		{
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���500�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (m_mou_l == true && star_count >= 500)
		{
			if (starmodel_flag = true)
			{
				
					lever = 8;
					a_time = 0;
					Back_time = 0.0f;
					time_flag = false;
					Scene::SetScene(new CSceneStarPicbook());
				
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	if (m_mou_x > 325 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (star_count < 500)
		{
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���500�W�߂Ă�������", left_end, 260, font_size, c);
		}

		if (m_mou_l == true && star_count >= 500)
		{
			if (starmodel_flag = true)
			{

				lever = 20;
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
				Scene::SetScene(new CSceneStarPicbook());

			}
			else
			{
				starmodel_flag = true;
			}
		}
	}

	t -= 4;
	l -= 4;
	std = 2;
	//�V����
	Font::StrDraw(L"�V����", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (star_count <150 )
		{
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���150�W�߂Ă�������", left_end, 260, font_size, c);
		}
		if (m_mou_l == true)
		{
			if (m_mou_l == true && star_count >= 150)
			{
				
					lever = 9;
					a_time = 0;
					Back_time = 0.0f;
					time_flag = false;
					Scene::SetScene(new CSceneStarPicbook());
				
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	if (m_mou_x > 500 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (star_count < 150)
		{
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���150�W�߂Ă�������", left_end, 260, font_size, c);
		}
		if (m_mou_l == true)
		{
			if (m_mou_l == true && star_count >= 150)
			{

				lever = 21;
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
				Scene::SetScene(new CSceneStarPicbook());

			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	
Font::StrDraw(L"嶍�", 30 + fy * std, 330 + t*l, 30, c);
l++;

	//嶍�				left		     right							 top						 bottom       
if (m_mou_x > side_a + side_b * std && m_mou_x < 70 * std+side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
{// �{���̐���
	if (star_count < 50 && g_other_star < 50)
	{
		Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ōܓ�����50�W�߂Ă�������", left_end, 260, font_size, c);
	}
	
	if (m_mou_l == true&& star_count >= 50&& g_other_star>=50)
	{
		

			if (starmodel_flag == true)
			{

				lever = 10;
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
				starmodel_flag = false;
				Scene::SetScene(new CSceneStarPicbook());


			}
		
	}
	else
	{
		starmodel_flag = true;
	}



}

//   left				  right			  top			 bottom                
if (m_mou_x > 130+200*std&& m_mou_x < 197*(std+1) && m_mou_y>302+k*(l-1) && m_mou_y < 300+73*l)
{
	if (star_count < 50 && g_other_star < 50)
	{
		Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ōܓ�����50�W�߂Ă�������", left_end, 260, font_size, c);
	}

	if (m_mou_l == true && star_count >= 50 && g_other_star >= 50)
	{


		if (starmodel_flag == true)
		{

			lever = 22;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			starmodel_flag = false;
			Scene::SetScene(new CSceneStarPicbook());


		}

	}
	else
	{
		starmodel_flag = true;
	}
}

	//�ˎ��
Font::StrDraw(L"�ˎ��", 30 + fy * std, 350 + t * l, 30, c);
l++;
if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
{
	if (star_count < 550)
	{
		Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���550�W�߂Ă�������", left_end, 260, font_size, c);
	}
	if (m_mou_l == true && star_count >= 550)
	{
		if (starmodel_flag = true)
		{
		
				lever = 11;
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
				Scene::SetScene(new CSceneStarPicbook());
			
			
		}
		else
		{
			starmodel_flag = true;
		}
	}
}
if (m_mou_x > 520 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
{
	if (star_count < 550)
	{
		Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���550�W�߂Ă�������", left_end, 260, font_size, c);
	}
	if (m_mou_l == true && star_count >= 550)
	{
		if (starmodel_flag = true)
		{

			lever = 23;
			a_time = 0;
			Back_time = 0.0f;
			time_flag = false;
			Scene::SetScene(new CSceneStarPicbook());


		}
		else
		{
			starmodel_flag = true;
		}
	}
}
	//�R�r��
	Font::StrDraw(L"�R�r��", 30 + fy * std, 360 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (star_count < 600)
		{
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���100�W�߂Ă�������", left_end, 260, font_size, c);
		}
		if (m_mou_l == true && star_count >= 600)
		{
			if (starmodel_flag = true)
			{
				
					lever = 12;
					a_time = 0;
					Back_time = 0.0f;
					time_flag = false;
					Scene::SetScene(new CSceneStarPicbook());
				
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	if (m_mou_x > 500 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (star_count < 600)
		{
			Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���100�W�߂Ă�������", left_end, 260, font_size, c);
		}
		if (m_mou_l == true && star_count >= 600)
		{
			if (starmodel_flag = true)
			{

				lever = 24;
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
				Scene::SetScene(new CSceneStarPicbook());

			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	
	Font::StrDraw(L"���̖��O�ɃJ�[�\�����킹�č��N���b�N����Ƃ��̐����ɂ���", 80, 25, 25, c);
	Font::StrDraw(L"��Ȑ��̐���������܂��B", 80, 50, 25, c);
	Font::StrDraw(L"�����̊G�ɃJ�[�\�������킹�ăN���b�N����Ɛ������̂��̂�", 80, 100, 25, c);
	Font::StrDraw(L"�����ɓ���܂��B", 80, 125, 25, c);
	Font::StrDraw(L"�y�[�W���߂���ɂ͍��ɂ��鎟�ւ��N���b�N���܂��B", 80, 170,25, c);
	Font::StrDraw(L"��O�̃y�[�W�ɂ������ꍇ�͖߂���N���b�N���܂��B", 80, 195, 25, c);

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