#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�^�C�g��
class CObjFourthStar : public CObjFirstStar
{
public:
	CObjFourthStar() {};
	~CObjFourthStar() {};
	CObjFourthStar(float x); //�R���X�g���N�^
	void Init();      //�C�j�V�����C�Y
	void Action();    //�A�N�V����
	void Draw();      //�h���[

private:

};