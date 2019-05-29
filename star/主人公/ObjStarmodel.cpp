//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

#include "GameHead.h"
#include "ObjStarmodel.h"
extern int lever;
extern int star_count;

void CObjStarmodel::Init()
{
	size = 20;
	size_y = 25;
	m_y = 310;
	font = 20;
	ver = 0;
	VER_start = 0;

	a_time = 0;
	time_flag = false;
	m_mou_time = 0.0f;

	Back_time = 0.0f;

	Audio::LoadAudio(1, L"���ʉ�.wav", EFFECT);
}

void CObjStarmodel::Action()
{
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
	else if (m_mou_time < 60.0f)
	{
		m_mou_time++;
		m_mou_l = false;
	}

	//SE��������
	if (m_mou_l == true)
	{
		time_flag = true;
	}
	else if (m_mou_l == false)
	{
		a_time = 0;
		time_flag = false;
	}

	//SE��������
	if (time_flag == true)
	{
		a_time++;
	}

	if (a_time == 1)
	{
		Audio::Start(1);
	}

	Back_time++;

	//�����I���փ{�^��
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
				Scene::SetScene(new CSceneStarPicbook());
				return;
			}
		}
	}
	//���������Ɩ߂�
	else if (Input::GetVKey('B') == true && Back_time > 60.0f)
	{
		lever = 0;
		a_time = 0;
		Back_time = 0.0f;
		time_flag = false;
		Scene::SetScene(new CSceneStarPicbook());

	}

	//���ւ��������玟�̐����ɐ؂�ւ���
	// left				 right            top            bottom       
	if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>100 && m_mou_y < 200)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true && lever < 24)
			{
				lever += 1;
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
				ver = VER_start; //�����Ԋu������
				starmodel_flag = false;
			}
		}
		else
		{
			starmodel_flag = true;
		}
	}
	//�߂����������O�̐����ɐ؂�ւ���
	// left				 right            top            bottom       
	if (m_mou_x > 0 && m_mou_x < 67 && m_mou_y>190 && m_mou_y < 300)
	{
		if (m_mou_l == true)
		{
			if (starmodel_flag == true && lever > 13)
			{
				lever -= 1;
				a_time = 0;
				Back_time = 0.0f;
				time_flag = false;
				ver = VER_start; //�����Ԋu������
				starmodel_flag = false;
			}
		}
		else
		{
			starmodel_flag = true;
		}
	}

}

void CObjStarmodel::Draw()
{
	//�`��J���[���@R=Red�@G=Green�@B=Blue�@A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f, };
	float p[4] = { 1.0f,1.0f,1.0f,0.6f, };
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

	//�����̘g��`��
	dst.m_top = 300.0f;
	dst.m_left = 0.0f;
	dst.m_right = 200.0f;
	dst.m_bottom = 350.0f;

	int g = 200.0f;//���g�̉���
	int k = 75.0f;//���g�̗���
	
	dst.m_top = 0.0f;
	dst.m_left = 67.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 300.0f;
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.f);
	dst.m_top = 300.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.f);

	//�߂�{�^���̘g��`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 67.0f;
	dst.m_bottom = 100.0f;
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.f);

	//���̃y�[�W�ɍs�����߂̃{�^���̘g��`��
	dst.m_top = 200.0f;
	dst.m_bottom = 300.0f;

	//���ւ̘g
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.f);

	dst.m_top = 100.0f;
	dst.m_bottom = 200.0f;

	//�߂��̘g
	Draw::Draw(1, &src, &dst, p, 0.0f);
	Draw::Draw(9, &src, &dst, c, 0.f);

	//�����I���ւ̕�����`�悷��
	//					�@�@X�@Y�@�傫��
	Font::StrDraw(L"����", 10, 25, 25, c);
	Font::StrDraw(L"�I��", 10, 50, 25, c);
	Font::StrDraw(L"��", 10, 75, 25, c);


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

	//�݂����ߍ�
	if (lever == 13 && star_count >= 200)
	{	
		ver = VER_start; //�����Ԋu������

		Font::StrDraw(L"�݂����ߍ�", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���̐����ɂ�2�����ȏ�̖��邢���͂Ȃ��B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�݂����ߍ��ɂ͗����Q��3����B3�Ƃ��A������20�̗������ϑ������B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"Water Jar�ƌĂ΂��A�X�e���Y��������B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"[�����Q(��イ��������)�Ƃ�]", font, m_y + size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"���̋O�Ղ��V����̂����_�i���˓_�܂����t�˓_�Ƃ����j�𒆐S�ɕ��ˏ��", font, m_y + size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�L����悤�ɏo�������Q�̗����̂��Ƃ������B�����Q�ɑ����闬�����Q�����Ƃ����B", font, m_y + size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"[�A�X�e���Y���܂��͐��Q(��������)�Ƃ�]", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����̍P�����V����Ɍ`���p�^�[���ł���B�����̐��̕��ѓ��l�A�n������̋���", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�͓����Ƃ͌��炸�A��ԓI�ɂ͂܂Ƃ܂��Ă��Ȃ��B", font, m_y + size_y* ver, size, c);
	}
	else if (lever == 13 && star_count <= 200)
	{
		ver = 0;
		Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���200�W�߂Ă�������", 80, 0, 25, c);
	}
	//������
	if (lever == 14 && star_count >= 250)
	{
		ver = VER_start; //�����Ԋu������

		Font::StrDraw(L"������", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�������͉����\�񐯍��ł���Ȃ���A3������薾�邢�����Ȃ����܂�ڗ����Ȃ������ł���B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���}�ł́A�R�Ō��΂ꂽ2�C�̋��Ƃ��ĕ`�����B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�y�K�X�X�̑�l�ӌ`�̂��傤�Ǔ�ŁA���̐��̋��̓��̂��ۂ�A�X�e���Y����", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�p�Ăł�Circlet�ƌĂ�ł���B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"[�A�X�e���Y���܂��͐��Q(��������)�Ƃ�]", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����̍P�����V����Ɍ`���p�^�[���ł���B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����̐��̕��ѓ��l�A�n������̋����͓����Ƃ͌��炸�A��ԓI�ɂ͂܂Ƃ܂��Ă��Ȃ��B", font, m_y + size_y* ver, size, c);
	}
	else if (lever == 14 && star_count <= 250)
	{
		ver = 0;
		Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���250�W�߂Ă�������", 80, 0, 25, c);
	}

	//�Ђ���
	if (lever == 15 && star_count >= 300)
	{
		ver = VER_start; //�����Ԋu������

		Font::StrDraw(L"���Ђ���", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���̐����̔�r�I���邢�����i�������Đ����j�̃n�}���E�V�F���^���E���T���e�B����", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�ł�����^�́A�Ñ�o�r���j�A�ł́u�_�v�v���邢�́u�ٕv�v", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�i���d���̔_�Ɋ��Ɍق�����ق��_�v�j�������B�ׂ̂������̒������A�ނ��k���_�n�ł���B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�u�j�v�Ɓu�r�v�������ً`�� lu ���������Ƃ���A�r�Ɠ��ꎋ�����悤�ɂȂ����B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����ł͓�\���h�̘K�h�ł���A���{�ł͂�����u������ڂ��v�ƌP���Ă����B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"[��\���h�i�ɂ��イ�͂����キ�j�Ƃ�]", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�V�����A28�̃G���A�i���h�j�ɕs�ϓ������������́B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"��\���Ɂi�ɂ��イ�͂�����j�Ƃ������B", font, m_y + size_y* ver, size, c);
	}
	else if (lever == 15 && star_count <= 300)
	{
		ver = 0;
		Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���300�W�߂Ă�������", 80, 0, 25, c);
	}

	//������
	if (lever == 16 && star_count >= 100)
	{
		ver = VER_start; //�����Ԋu������

		Font::StrDraw(L"��������", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����́A�S�V21��1������1�ł���A�A���f�o�����ƌĂ΂��B���̐����ɂ�", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�v���A�f�X���c���͂��ߗL���ȓV�̂������B���{�ł́A�������ƌĂ񂾂��Ƃ�����B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�܂����������Ɋ֌W��������́A�v���A�f�X���c�A�q�A�f�X���c�A�启�A���f�o������", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���Â���ꂽ���̂��������Ă���A���Ƀv���A�f�X���c�͑����B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���{�ł́A�������ƌĂ񂾂��Ƃ�����B�܂����������Ɋ֌W���������", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�v���A�f�X���c�A�q�A�f�X���c�A�启�A���f�o�����ɖ��Â���ꂽ���̂�", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�������Ă���A���Ƀv���A�f�X���c�͑����B", font, m_y + size_y* ver, size, c);
	}
	else if (lever == 16 && star_count <= 100)
	{
		ver = 0;
		Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���100�W�߂Ă�������", 80, 0, 25, c);
	}

	//�ӂ�����
	if (lever == 17 && star_count >= 350)
	{
		ver = VER_start; //�����Ԋu������

		Font::StrDraw(L"�ӂ�����", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����́A�S�V21��1������1�ł���A�|���b�N�X�ƌĂ΂��B�����J�X�g����", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�|���b�N�X�ɏ����閾�邳�ł���B�|���b�N�X�̋߂��i�k���j�Ɉʒu����B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�|���b�N�X�ƃJ�X�g���ƁA����ɃA���w�i�ƃe�W�F�b�g�ŁA�����͂قڒ����`���`���B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�ӂ������ƌ����������ɂ͂��č��ł���B�������́A���T�g�̂��΂�1930�N�ɔ������ꂽ�B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���{�ł́A�J�X�g���ƃ|���b�N�X���A�X�e���Y���Ƒ�����������`����Ă���B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"[�A�X�e���Y���܂��͐��Q(��������)�Ƃ�]", font, m_y + size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�����̍P�����V����Ɍ`���p�^�[���ł���B", font, m_y + size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�����̐��̕��ѓ��l�A�n������̋����͓����Ƃ͌��炸�A��ԓI�ɂ͂܂Ƃ܂��Ă��Ȃ��B", font, m_y + size_y * ver, size, c);
	}
	else if (lever == 17 && star_count <= 350)
	{
		ver = 0;
		Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���350�W�߂Ă�������", 80, 0, 25, c);
	}

	//���ɍ�
	if (lever == 18 && star_count >= 400)
	{
		ver = VER_start; //�����Ԋu������

		Font::StrDraw(L"���ɍ�", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����̂قڒ����ɂ���M44�i�v���Z�y���c�A�v���Z�y�U�J���c�j���L���ł���B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���ɍ��͍ł����邢�^���t��3.520���A����4�����ȉ��ƑS�̂ɈÂ�������Ȃ鐯���ł���B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"[�v���Z�y���c�Ƃ�]", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���ɍ��ɂ���U�J���c�ł���B", font, m_y + size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"[�U�J���c�Ƃ�]", font, m_y + size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�P���̏W�c�i���c�j�̈��ł���B", font, m_y + size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"[���ɍ�HM���Ƃ�]", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���ɍ��̕����ɒn������1600���N���ꂽ�ʒu�ɂ��锒�F�␯�̘A���ł���B", font, m_y + size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"[���F�␯(�͂����傭�킢����)�Ƃ�]", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�P�����i���̏I�����ɂƂ肤��`�Ԃ̈�B", font, m_y + size_y* ver, size, c);
	}
	else if (lever == 18 && star_count <= 400)
	{
		ver = 0;
		Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���400�W�߂Ă�������", 80, 0, 25, c);
	}

	//������
	if (lever == 19 && star_count >= 450)
	{
		ver = VER_start; //�����Ԋu������

		Font::StrDraw(L"������", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���{�ł͏t�̑�\�I�Ȑ����ł���B�����́A�S�V21��1������1�ł���", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���O���X�ƌĂ΂��B�����̃f�l�{�����A�����������̃����A�[�N�g�D���X", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���Ƃߍ��̃����X�s�J�ƌ`���O�p�`�͏t�̑�O�p�ƌĂ΂��B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���{�ł͂�����u��|�����i�Ƃ������ڂ��j�v�ƌĂԒn��������B", font, m_y + size_y* ver, size, c);
	}
	else if (lever == 19 && star_count <= 450)
	{
		ver = 0;
		Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���450�W�߂Ă�������", 80, 0, 25, c);
	}

	//���Ƃߍ�
	if (lever == 20 && star_count >= 500)
	{
		ver = VER_start; //�����Ԋu������

		Font::StrDraw(L"���Ƃߍ�", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�S�V�ł��݂ւэ��Ɏ�����2�ԖڂɍL�������ł���B���ݏH���_������B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����́A�S�V21��1������1�ł���A�X�s�J�ƌĂ΂��B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�X�s�J�ƁA�����������̃����A�[�N�g�D���X�A�������̃����f�l�{����", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�t�̑�O�p���`������B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"[�A�[�N�g�D���X�Ƃ�]", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����������ōł����邢�P���őS�V21��1������1�ł���ԐF�����B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���z�����������������}�C�i�X�ƂȂ�4�̍P����1�B", font, m_y + size_y* ver, size, c);
	}
	else if (lever == 20 && star_count <= 500)
	{
		ver = 0;
		Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���500�W�߂Ă�������", 80, 0, 25, c);
	}

	//�Ă�т��
	if (lever == 21 && star_count >= 150)
	{
		ver = VER_start; //�����Ԋu������

		Font::StrDraw(L"�Ă�т��", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���͂��Ƃߍ��ƁA���͂�������Ɛڂ���B2������薾�邢���͂Ȃ�", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"3��3����������A����炪�����`���`���B�����ƃ����ɂ�", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"��������R���̖������Ă���B����͂��āA���̐�����", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"��������̂͂��݂̕����ł��������ƂɋN������B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�����A�����͂Ă�т�_�̕����ŁA�����ƃА��͂Ă�т�̎M�ɂ�����B", font, m_y + size_y* ver, size, c);
	}
	else if (lever == 21 && star_count <= 150)
	{
		ver = 0;
		Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���150�W�߂Ă�������", 80, 0, 25, c);
	}

	//�������
	if (lever == 22 && star_count >= 50)
	{
		ver = VER_start; //�����Ԋu������

		Font::StrDraw(L"�������", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�V�̐쉈���ɂ���傫���ėL���Ȑ����ł���B���{�ł͉Ă̑�O�p�Ƌ���", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�Ă̐����Ƃ��Đe���܂�A��̋�Ɋm�F���邱�Ƃ��ł���B�V�̐��", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�傫��S���^�ŉ�������Ă���A�����I�Ȍ`�����Ă���B���邢��������", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�S�V�ł����邢�����̈�ł���B�����́A�S�V21��1������1�ł���", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�A���^���X�ƌĂ΂��B", font, m_y + size_y* ver, size, c);
	}
	else if (lever == 22 && star_count <= 50)
	{
		ver = 0;
		Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���50�W�߂Ă�������", 80, 0, 25, c);
	}

	//���č�
	if (lever == 23 && star_count >= 550)
	{
		ver = VER_start; //�����Ԋu������

		Font::StrDraw(L"���č�", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�~���_���͂̒��S�����̐����̗̈�ɂ���B��r�I���邢����", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�ˎ�̏㔼�g�ɏW�����Ă���A�����g��4�����ȉ��̈Â����΂���ł���B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���č�A�c�d�g���B��͌n���S�ɑ��݂���B�V���w�҂́A���č�A��", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�县�ʂ̃u���b�N�z�[�����܂ނ�������Ȃ��ƍl���Ă���B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���č�A�͉�X�̋�͌n�̒��S�ɑ��݂���d�g���̕����̂ł���B", font, m_y + size_y* ver, size, c);
	}
	else if (lever == 23 && star_count <= 550)
	{
		ver = 0;
		Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���550�W�߂Ă�������", 80, 0, 25, c);
	}

	//�€��
	if (lever == 24&& star_count >= 600)
	{
		ver = VER_start; //�����Ԋu������

		Font::StrDraw(L"�€��", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���̐����ɂ�2�����ȏ�̖��邢���͖����BM30�́A�€���ɂ��鋅�󐯒c�B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�C�����́A1846�N9��23���A�f�l�u�E�A���Q�f�B�̋߂��Ńt�����X��", font, m_y + size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"�V���w�҃����F���G�̗\���v�Z�ƃh�C�c�̓V���w�҃K���̊ϑ��ɂ���Ĕ������ꂽ�B", font, m_y + size_y * ver, size, c);
		ver++;
		Font::StrDraw(L"[���󐯒c(���イ���傤��������)�Ƃ�]", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"�P�����݂��̏d�͂ŋ��`�ɏW�܂����V�́B��͂̎�����O���^�����Ă���B", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���󐯒c�͏d�͓I�ɔ��ɋ�����������Ă���A���̂��߂Ɍ`��͋��Ώ̂ƂȂ�", font, m_y + size_y* ver, size, c);
		ver++;
		Font::StrDraw(L"���S�j�Ɍ������Ĕ��ɖ��x�������Ȃ��Ă���B", font, m_y + size_y * ver, size, c);
	}
	else if(lever == 24 && star_count <= 600)
	{
		ver = 0;
		Font::StrDraw(L"���̐��X���{������ɂ͍��v�Ő���600�W�߂Ă�������", 80, 0,25, c);
	}

}