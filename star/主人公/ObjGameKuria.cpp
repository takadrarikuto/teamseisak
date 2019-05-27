//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include "GameL\UserData.h"

#include"GameHead.h"
#include"ObjGamekuria.h"
#include"ObjFirstStar.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;
extern int star_count;
extern int FiStar_Reco; //1���������̐�������
extern int FoStar_Reco; //2���������̐�������
extern int OtStar_Reco; //3���������̐�������


//�C�j�V�����C�Y
void CObjGameKuria::Init()
{
	m_mous_l = false;
	m_start_flag = false;

}

//�A�N�V����
void CObjGameKuria::Action()
{
	m_mous_l = Input::GetMouButtonL();

	//���J�E���g�n������
	star_count = 0;
	FiStar_Reco = 0;
	FoStar_Reco = 0;
	OtStar_Reco = 0;

	if (m_mous_l == true)
	{
		if (m_start_flag == true)
		{
			Scene::SetScene(new CSceneTitle()); 
		}
	}
	else
	{
		m_start_flag = true;
	}

}
//�h���[
void CObjGameKuria::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"�Q�[���N���A", 240, 200, 50, c);
	Font::StrDraw(L"���N���b�N�Ń^�C�g����", 130, 400, 50, c);

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 190.0f;
	src.m_bottom = 200.0f;


	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 64.0f;
	dst.m_bottom = 64.0f;

	//�`��
	Draw::Draw(11, &src, &dst, c, 0.0f);
}
