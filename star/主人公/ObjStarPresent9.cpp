//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjStarPresent9.h"
extern int lever;
extern int crick;
extern int cenge;


void CObjStarPresent9::Init()
{

}

void CObjStarPresent9::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();


}

void CObjStarPresent9::Draw()
{
	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu
	//�u���b�N�^�C���̐؂���
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1039.0f;
	src.m_bottom = 469.0f;

	//�����̘g��`��
	dst.m_top = 300.0f;
	dst.m_left = 0.0f;
	dst.m_right = 200.0f;
	dst.m_bottom = 350.0f;
	int g = 200.0f;//���g�̉���
	int k = 75.0f;//���g�̗���
	int t = 70;//���̖��O�̈ʒu
	int l = 0;//t�Ɗ|����p�̕ϐ�
	int s = 0;//���̃N���b�N�̌�
	int std = 0;
	int side_a = 0;
	int side_b = 200;
	int size = 25;
	int size_y = 30;
	int font = 80;


	//���[�v���ĕ`�悷��
	for (int i = 0; i <= 3; i++)
	{
		//���̖��O�̘g��`��
		dst.m_top = 300.0f;
		dst.m_left = 0.0f + g * i;
		dst.m_right = 200.0f + g * i;
		dst.m_bottom = 300.0f + k;
		Draw::Draw(1, &src, &dst, c, 0.0f);

		for (int l = 0; l <= 2; l++)
		{

			dst.m_top = 375.0f + k * l;
			dst.m_bottom = 450.0f + k * l;
			Draw::Draw(1, &src, &dst, c, 0.0f);
		}

	}

	//�߂�{�^���̘g��`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 67.0f;
	dst.m_bottom = 100.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);

	//���̃y�[�W�ɍs�����߂̃{�^���̘g��`��
	dst.m_top = 200.0f;
	dst.m_bottom = 300.0f;

	//���ւ̘g
	Draw::Draw(1, &src, &dst, c, 0.0f);
	dst.m_top = 100.0f;
	dst.m_bottom = 200.0f;

	//�߂��̘g
	Draw::Draw(1, &src, &dst, c, 0.0f);

	//�F���D�ւ̕�����`�悷��
	//					�@�@X�@Y�@�傫��
	Font::StrDraw(L"�F��", 10, 25, 25, c);
	Font::StrDraw(L"�D��", 10, 50, 25, c);

	//�߂�{�^��
	// left				 right            top            bottom         
	if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>0 && m_mou_y < 100)
	{
		if (m_mou_l == true)
		{
			lever = 0;
			Scene::SetScene(new CSceneStageselect());
		}
	}
	//���������Ɩ߂�
	else if (Input::GetVKey('B') == true)
	{
		lever = 0;
		Scene::SetScene(new CSceneStageselect());
	}

	//���ւ̕��������[�v���ďo��
	wchar_t next[2][2]{ L"��",L"��" };
	for (int i = 0; i <= 1; i++)
	{
		int l = 25;
		swprintf_s(str, L"%s", next[i]);
		//				�@�@X�@ Y�@ �傫��
		Font::StrDraw(str, 20, 130 + l * i, 25, c);
	}
	//�߂����������StarPresent�ɐ؂�ւ���
	// left				 right            top            bottom       
	if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>190 && m_mou_y < 300)
	{
		if (m_mou_l == true)
		{
			lever = 0;
			Scene::SetScene(new CSceneStarPicbook());
		}
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
	//���ւ���������StarPresent2�ɐ؂�ւ���
	// left				 right            top            bottom       
	/*if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>100 && m_mou_y <200)
	{
		if (m_mou_l == true)
		{
			lever =1;
			Scene::SetScene(new CSceneStarPicbook());
		}
	}*/

	//					�@�@	    X�@ Y�@ �傫��
	Font::StrDraw(L"���O���X", 20, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 1;
		}
	}

	//					�@�@	    X�@ Y�@ �傫��
	Font::StrDraw(L"�f�l�{��", 20, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 2;
		}
	}

	//					�@�@	    X�@        Y�@    �傫��
	Font::StrDraw(L"�A���M�G�o", 20, 330 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 3;
		}
	}
	//					�@�@	  X�@        Y�@    �傫��
	Font::StrDraw(L"�]�X�}", 20, 340 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 4;
		}
	}

	t -= 4;
	l -= 4;
	std = 1;

	//					�@�@	  X�@        Y�@    �傫��
	Font::StrDraw(L"�A�_�t�F��", 20 + 220, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 5;
		}
	}
	//					�@�@	  X�@        Y�@    �傫��
	Font::StrDraw(L"�V�F���^��", 20 + 220, 330 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 6;
		}
	}
	//					  �@�@	    X�@        Y�@    �傫��
	Font::StrDraw(L"�A���e���t", 20 + 220, 340 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 7;
		}
	}
	//					  �@�@	    X�@        Y�@    �傫��
	Font::StrDraw(L"���T���X", 20 + 220, 340 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 8;
		}
	}

	t -= 4;
	l -= 4;
	std = 2;

	//					�@�@	  X�@        Y�@    �傫��
	Font::StrDraw(L"�X�[�o�[", 20 + 400, 320 + t * l, 30, c);
	l++;
	// left				 right            top            bottom               
	if (m_mou_x > side_a + side_b * std && m_mou_x < side_b*(std + 1) && m_mou_y>300 + k * (l - 1) && m_mou_y < 300 + k * l)
	{
		if (m_mou_l == true)
		{
			crick = 9;
		}
	}


	int ver;
	if (crick == 1)
	{
		ver = 0;
		Font::StrDraw(L"�������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�������ōł����邢�P���őS�V21��1������1�B1�����̒��ł�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�ł��Â��قډ�����ɂ���A�q�C�ʒu�̌v���̊�ƂȂ�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"��p�P���ƂȂ��Ă���4�̐����e2�̃y�A�ɂȂ��Č݂���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"����Ă��鑽�d�A���ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����c�V����ɂ����鑾�z�̌�������̒ʂ蓹�i��~�j������", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�A���c2�̍P�������҂̏d�S�̎�����O���^�����Ă���V�̂�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"����", font, size_y* ver, size, c);
	}
	else if (crick == 2)
	{
		ver = 0;
		Font::StrDraw(L"�������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�������̍P����2�����B�����������̃A�[�N�g�D���X��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���Ƃߍ��̃X�s�J�ƂŁA�t�̑�O�p�`���`�����锒�F��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"��n�񐯁B���č��^�ό����ł���A�ό��͈͂�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����킸���Ȃ̂Ŋᎋ�ϑ��ł͕ό��͂킩��Ȃ�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"��n�񐯁c�P���̗L�����x�Ɩ��邳���������}�ł��鍶�㉄�т�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���ł���w���c�V���v�����O�E���b�Z���} (HR�}) ���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���邭��������Â��ቷ�Ɏ�n��Ɉʒu����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�P���������B�␯�Ƃ������P���\�ʂɂ����铮�a�����y��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�񓮌a�����̗����̌����ɂ���Č��x���ω�����ό����ł���", font, size_y* ver, size, c);
	}
	else if (crick == 3)
	{
		ver = 0;
		Font::StrDraw(L"�������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�������̍P���ɂ���2�����ł���B��F�̋����ł���启��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���F�����̔�������Ȃ�����A���ł��肻�̔������Ə��K�͂�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�V�̖]�����ł���y�Ɋϑ��ł��邱�Ƃ���V���Ƃ����ɂ�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�l�C�̍����P���ł���B�܂������������Q�̕��˓_��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�߂����Ƃł��m����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����A���c��d���̐����邤���̈�B�]�����ŗ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�������Ċϑ����ꗼ�������]�^�����Ă��鎖��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�m�F����Ă���A��������", font, size_y* ver, size, c);
	}
	else if (crick == 4)
	{
		ver = 0;
		Font::StrDraw(L"�������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�������̍P����3�����B���F�̋P�����ŁA���z�����኱", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�傫���č����ł��邩�Ȃ�ǂ���������Ă���A�N���傫����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���Ă͔�r�I���m�ɑ��肳��Ă��鑾�z����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�傫�Ȏ��ʂ����������͒Z����F�̋������ԐF�����ɂȂ�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�Â��ɔ��F�␯�ɂȂ�ƍl�����Ă���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�P�����c�ɂ߂Ė��邢�����ɕ��ނ����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�ԐF�����c����Ŋώ@����ƐԂ������邱�Ƃ���u�ԐF�v������", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�Ă΂��B�@���F�␯(�͂����傭�킢����)�c�P����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�i���̏I�����ɂƂ肤��`�Ԃ̈��", font, size_y* ver, size, c);
	}
	else if (crick == 5)
	{
		ver = 0;
		Font::StrDraw(L"�������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�������̍P����3�����B������F�^�̋����ŁA���S�j�ł�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���f�̊j�Z���͊��ɏI���w���E���̊j�����k���Ă���i�K��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"����B�������ꂽ�ʒu�ɂ��邵����35�Ԑ��Ƃ͌������̓�d����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�֌W�ɂ���A�A���ł͂Ȃ�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"��d���c�n���ォ�猩��P�������������ɋߐڂ��Č����镨��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�w��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�A���c2�̍P�������҂̏d�S�̎�����O���^�����Ă���V�̂�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"����", font, size_y* ver, size, c);
	}
	else if (crick == 6)
	{
		ver = 0;
		Font::StrDraw(L"�������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�������̍P����3�����BA�^�X�y�N�g���̎�n�񐯂��珀������", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���ނ����B���悻4500���N�O�ɒa�������Ƃ��ɂ�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"B8�^�̎�n�񐯂ł��菫���͎��ʂ̑傫�Ȕ��F�␯��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�Ȃ���̂ƍl�����Ă���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"��n�񐯁c�P���̗L�����x�Ɩ��邳���������}�ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�w���c�V���v�����O�E���b�Z���} (HR�}) ��ŁA", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���邭��������Â��ቷ�ɉ��т���ł����n���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�ʒu����P���������B�␯�Ƃ������B", font, size_y* ver, size, c);
	}
	else if (crick == 7)
	{
		ver = 0;
		Font::StrDraw(L"�������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�������̍P����4�����B���������̃A���f�o������", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�悭���ʂ��Ă����Γ����ł͂킸���ɂ��̐��̂ق���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���邢���n������̋����������Ɖ�������25�{�قǈÂ�������", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�₪�ă~���̂悤�Ȓ������̕ό����ƂȂ�ƍl�����Ă���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�~���c�����ł����k��������ɖ��邳���ɑ�ƂȂ鐫��������", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�ό����c�V�̂̈��ŁA���邳�i�����j���ω�������̂̂���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"����", font, size_y* ver, size, c);
	}
	else if (crick == 8)
	{
		ver = 0;
		Font::StrDraw(L"�������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�������̍P����4�����BK�^�̋��������A�܂����S�j�ł�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�w���E���̊j�Z�����n�܂��Ă��炸�j�����k���Ă���i�K�ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�ƍl�����Ă���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"5,000���N��ɂ̓w���E���̊j�Z�����n�܂�A���݂��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"10�{����20�{�͌��x���������̂Ɨ\������Ă���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"��358�������Č��]���Ă���", font, size_y* ver, size, c);
	}
	else if (crick == 9)
	{
		ver = 0;
		Font::StrDraw(L"�������ɑ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�������̍P����4�����BF�^�̃X�y�N�g������������", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"A�^��n�񐯂��A���n�𐬂��Ă��邪�A�启�Ɣ����̕��ϋ�����", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"��ϋ߂����ߕ����@�܂��̓X�y�b�N�����@�ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�ϑ��ł��Ă��Ȃ�2�̐��́A14.498���̎����ŋ��ʏd�S��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�݂��ɏ����Ă���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"A�^��n�񐯁c�X�y�N�g���^��A�A���x�K����V��", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���f��R�₵�ĔR�����n�񐯂ł���", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�A���c2�̍P�������҂̏d�S�̎�����O���^�����Ă���V�̂�", font, size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"����", font, size_y* ver, size, c);
	}

}