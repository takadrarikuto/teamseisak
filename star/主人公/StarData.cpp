#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include"GameL\DrawFont.h"
#include"GameL\Audio.h"
#include"GameL\UserData.h"
#include"GameHead.h"

int g_Aries[5] = {};//���r���F6��
int g_Taurus[17] = {};//�������F16��
int g_Gemini[29] = {};//�o�q���F10��
int g_Cancer[5] = {};//�I���F9��
int g_Leo[17] = {};//���q���F9��
int g_Virgo[29] = {};//�������F10��
int g_Libra[5] = {};//�V�����F4��
int g_Scorpio[17] = {};//嶍��F15��
int g_Sagittarius[29] = {};//�ˎ���F13��
int g_Capricorn[5] = {};//�R�r���F5��
int g_Aquarius[17] = {};//���r���F7��
int g_Pisces[29] = {};//�����F4��

int g_debris;//�͂���g

int star_count;//�������J�E���g�p

unique_ptr<wchar_t>p;//�X�e�[�W���|�C���^�[
int size;			//�X�e�[�W���̑傫��
p = Save::ExternalDataOpen(L"Book1.csv", &size);//�O���f�[�^�ǂݍ���

int map[56][56];
int count = 1;
for (int i = 0; i < 56; i++)
{
	for (int j = 0; j < 56; j++)
	{
		int w = 0;
		swscanf_s(&p.get()[count], L"%d", &w);

		map[i][j] = w;

		if (w >= 10)
		{
			count += 1;
		}

		count += 2;
	}
}