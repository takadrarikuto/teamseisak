#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�C�x���g
class CObjStarPresent3 : public CObjStarPresent
{
public:
	CObjStarPresent3() {};	//�R���X�g���N�^
	~CObjStarPresent3() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	int a_time;
	bool time_flag;


};
