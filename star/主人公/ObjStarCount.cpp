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


//�C�j�V�����C�Y
void CObjStarCount::Init()
{
	star_flag = false;

	//��l���ƍ��킹��
	m_px = 400.0f;
	m_py = 520.0f;

	Hits::SetHitBox(this, m_px, m_py, 50, 50, OBJ_STARCOUNT, ELEMENT_RED, 21);
	
	((UserData*)Save::GetData())->star_co = 0;
}

//�A�N�V����
void CObjStarCount::Action()
{
	CObjHero* Hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float scx = Hero->GetX();
	float scy = Hero->GetY();

	m_px += scx;
	m_py += scy;


	//���g��HitBox�������Ă���
	CHitBox* hit_sc = Hits::GetHitBox(this);	

	if (hit_sc->CheckObjNameHit(OBJ_FIRSTSTAR) != nullptr || hit_sc->CheckObjNameHit(OBJ_SECONDSTAR) != nullptr
		|| hit_sc->CheckObjNameHit(OBJ_THIRDSTAR) != nullptr || hit_sc->CheckObjNameHit(OBJ_FOURTHSTAR) != nullptr
		|| hit_sc->CheckObjNameHit(OBJ_OTHERSTAR) != nullptr)
	{
		star_flag = true;
	}

	if (star_flag == true)
	{
		((UserData*)Save::GetData())->star_co += 1;
		star_flag = false;
	}

	if (((UserData*)Save::GetData())->star_co > 10)
	{
		//Scene::SetScene(new CSceneGameKuria());
	}

	//HitBox�̈ʒu�̕ύX
	hit_sc->SetPos(m_px, m_py);

}

//�h���[
void CObjStarCount::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	swprintf_s(str, L"���̐��~%3d��", ((UserData*)Save::GetData())->star_co);
	Font::StrDraw(str, 10, 570, 30, c);

}
