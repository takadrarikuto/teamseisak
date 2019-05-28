//GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

#include "CObjStarPicbook.h"
#include "GameHead.h"
extern int lever;


void CObjStarPicbook::Init()
{
	starmodel_flag = false;
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	a_time = 0;
	time_flag = false;
	Audio::LoadAudio(1, L"���ʉ�.wav", EFFECT);
}

void CObjStarPicbook::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

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



	//���������Ɩ߂�
	if (Input::GetVKey('B') == true)
	{
		lever = 0;
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

	//�F���D�ւ̕�����`�悷��
	//					�@�@X�@Y�@�傫��
	Font::StrDraw(L"�F��", 10, 25, 25, c);
	Font::StrDraw(L"�D��", 10, 50, 25, c);

	Font::StrDraw(L"���r��", 30 + fy * std, 330 + t*l, 30, c);
	l++;         
	//���r���͈̔�
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{	
			//    top            bottom  
			//����
			if (starmodel_flag == true)
			{
				if (a_time == 10)
				{
					lever = 1;
					starmodel_flag = false;
					Scene::SetScene(new CSceneStarPicbook());
				}
				
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
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				if (a_time == 10)
				{
					lever = 13;
					starmodel_flag = false;
					Scene::SetScene(new CSceneStarPicbook());
				}
				
			}
			

		}
	
		else
		{
			starmodel_flag = true;
		}
	}
	
	
	Font::StrDraw(L"����", 30 + fy * std, 330 + t*l, 30, c);
	l++;
	//�����͈̔�
    if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag = true)
			{
				if (a_time == 10)
				{
					lever = 2;
					starmodel_flag = false;
					Scene::SetScene(new CSceneStarPicbook());
				}
				
			}
			
		}
		else
		{
			starmodel_flag = true;
		}
	}

	if (m_mou_x > 130 * 1 * std&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k*(l - 1) && m_mou_y < 300 + 73 * l)
	  {
		  if (m_mou_l == true)
		  {
			  if (starmodel_flag == true)
			  {
				  if (a_time == 10)
				  {
					  lever = 14;
					  starmodel_flag = false;
					  Scene::SetScene(new CSceneStarPicbook());
				  }
				  
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
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				if (a_time == 10)
				{
					lever = 3;
					starmodel_flag = false;
					Scene::SetScene(new CSceneStarPicbook());
				}

				
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}

	if (m_mou_x > 60+130 * 1 * std&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				if (a_time == 10)
				{
					lever = 15;
					starmodel_flag = false;
					Scene::SetScene(new CSceneStarPicbook());
				}
				
			}
		}
		else
		{
			starmodel_flag = true;
		}
	}
	
	//������
	Font::StrDraw(L"������", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag = true)
			{
				if (a_time == 10)
				{
					lever = 4;
					starmodel_flag = false;
					Scene::SetScene(new CSceneStarPicbook());
				}
				
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}

	if (m_mou_x > 130 * 1 * std&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				if (a_time == 10)
				{
					lever = 16;
					starmodel_flag = false;
					Scene::SetScene(new CSceneStarPicbook());
				}
				
			}
		}
		else
		{
			starmodel_flag = true;
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
		if (m_mou_l == true)
		{
			if (starmodel_flag = true)
			{
				if (a_time == 10)
				{
					lever = 5;
					Scene::SetScene(new CSceneStarPicbook());
				}
				
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}

	if (m_mou_x > 325&& m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				if (a_time == 10)
				{
					lever = 17;
					starmodel_flag = false;
					Scene::SetScene(new CSceneStarPicbook());
				}
				
			}
		}
		else
		{
			starmodel_flag = true;
		}
	}

	//�I��
	Font::StrDraw(L"�I��", 30 + fy * std, 330 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag = true)
			{
				if (a_time == 10)
				{
					lever = 6;
					Scene::SetScene(new CSceneStarPicbook());
				}
				
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	if (m_mou_x > 325 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				if (a_time == 10)
				{
					lever = 18;
					Scene::SetScene(new CSceneStarPicbook());
				}
				
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
		if (m_mou_l == true)
		{
			if (starmodel_flag = true)
			{
				if (a_time == 10)
				{
					lever = 7;
					Scene::SetScene(new CSceneStarPicbook());
				}
				
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	if (m_mou_x > 325 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				if (a_time == 10)
				{
					lever = 19;
					Scene::SetScene(new CSceneStarPicbook());
				}
				
			}
		}
		else
		{
			starmodel_flag = true;
		}
	}

	//������
	Font::StrDraw(L"������", 30 + fy * std, 350 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag = true)
			{
				if (a_time == 10)
				{
					lever = 8;
					Scene::SetScene(new CSceneStarPicbook());
				}
				
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	if (m_mou_x > 325 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				if (a_time == 10)
				{
					lever = 20;
					Scene::SetScene(new CSceneStarPicbook());
				}
				
			}
		}
		else
		{
			starmodel_flag = true;
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
		if (m_mou_l == true)
		{
			if (starmodel_flag = true)
			{
				if (a_time == 10)
				{
					lever = 9;
					Scene::SetScene(new CSceneStarPicbook());
				}
				
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	if (m_mou_x > 500 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				if (a_time == 10)
				{
					lever = 21;
					Scene::SetScene(new CSceneStarPicbook());
				}
				
			}
		}
		else
		{
			starmodel_flag = true;
		}
	}
	
Font::StrDraw(L"嶍�", 30 + fy * std, 330 + t*l, 30, c);
l++;

	//嶍�				left		     right							 top						 bottom       
if (m_mou_x > side_a + side_b * std && m_mou_x < 70 * std+side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
{
	if (m_mou_l == true)
	{
		if (starmodel_flag == true)
		{
			if (a_time == 10)
			{
				lever = 10;
				starmodel_flag = false;
				Scene::SetScene(new CSceneStarPicbook());
			}
			
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
	if (m_mou_l == true)
	{
		if (starmodel_flag == true)
		{
			if (a_time == 10)
			{
				lever = 22;
				starmodel_flag = false;
				Scene::SetScene(new CSceneStarPicbook());
			}
			
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
	if (m_mou_l == true)
	{
		if (starmodel_flag = true)
		{
			if (a_time == 10)
			{
				lever = 11;
				Scene::SetScene(new CSceneStarPicbook());
			}
			
		}
		else
		{
			starmodel_flag = true;
		}
	}
}
if (m_mou_x > 520 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
{
	if (m_mou_l == true)
	{
		if (starmodel_flag == true)
		{
			if (a_time == 10)
			{
				lever = 23;
				Scene::SetScene(new CSceneStarPicbook());
			}
			
		}
	}
	else
	{
		starmodel_flag = true;
	}
}
	//�R�r��
	Font::StrDraw(L"�R�r��", 30 + fy * std, 360 + t * l, 30, c);
	l++;
	if (m_mou_x > side_a + side_b * std && m_mou_x <70 * std + side_c*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag = true)
			{
				if (a_time == 10)
				{
					lever = 12;
					Scene::SetScene(new CSceneStarPicbook());
				}
				
			}
			else
			{
				starmodel_flag = true;
			}
		}
	}
	if (m_mou_x > 500 && m_mou_x < 197 * (std + 1) && m_mou_y>302 + k * (l - 1) && m_mou_y < 300 + 73 * l)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true)
			{
				if (a_time == 10)
				{
					lever = 24;
					Scene::SetScene(new CSceneStarPicbook());
				}
				
			}
		}
		else
		{
			starmodel_flag = true;
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