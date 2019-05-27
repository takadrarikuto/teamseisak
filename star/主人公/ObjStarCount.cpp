//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameL\UserData.h"

#include"GameHead.h"
#include"ObjStarCount.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

bool star_flag = false; //���t���O
extern bool Star_Recovery;
extern bool FiStar_Recovery;
extern bool FoStar_Recovery;
extern bool OtStar_Recovery;
extern int g_mars_star[33];
extern int star_count;
int FiStar_Reco = 0; //1���������̐�������
int FoStar_Reco = 0; //2���������̐�������
int OtStar_Reco = 0; //3���������̐�������


//�C�j�V�����C�Y
void CObjStarCount::Init()
{	
	
	FiStar_Reco_max = 5; //1�����l�����m�F�p�ő吔�ݒ�
	FoStar_Reco_max = 25; //2�����l�����m�F�p�ő吔�ݒ�
	OtStar_Reco_max = 50; //3�����l�����m�F�p�ő吔�ݒ�

}

//�A�N�V����
void CObjStarCount::Action()
{
	
	//�_�f�񕜏���
	if (FiStar_Reco >= FiStar_Reco_max)
	{
		FiStar_Recovery = true;
		FiStar_Reco = 0;
	}
	else if (FoStar_Reco >= FoStar_Reco_max)
	{
		FoStar_Recovery = true;
		FoStar_Reco = 0;
	}
	else if (OtStar_Reco >= OtStar_Reco_max)
	{
		OtStar_Recovery = true;
		OtStar_Reco = 0;
	}


	//�N���A��ʈړ�
	if (star_count >= 100)
	{
		Scene::SetScene(new CSceneGameKuria());
	}

}

//�h���[
void CObjStarCount::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	swprintf_s(str, L"���̐��~%3d��", star_count);
	Font::StrDraw(str, 10, 570, 30, c);


	//�_�f�m�F�p�J�E���g�\��
	swprintf_s(strFis, L"1�����̐��~%2d/%d��", FiStar_Reco, FiStar_Reco_max);
	Font::StrDraw(strFis, 10, 10, 20, c);

	swprintf_s(strFos, L"2�����̐��~%2d/%d��", FoStar_Reco, FoStar_Reco_max);
	Font::StrDraw(strFos, 200, 10, 20, c);

	swprintf_s(strOts, L"3�����̐��~%2d/%d��", OtStar_Reco, OtStar_Reco_max);
	Font::StrDraw(strOts, 400, 10, 20, c);



}
