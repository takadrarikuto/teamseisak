#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


//�I�u�W�F�N�g�F�C�x���g
class CObjStarPresent : public CObj
{
public:
	CObjStarPresent() {};	//�R���X�g���N�^
	~CObjStarPresent() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[

	float m_mou_x;//�}�E�X�̈ʒuX
	float m_mou_y;//�}�E�X�̈ʒuX
	bool m_mou_r;//�}�E�X�̉E�{�^��
	bool m_mou_l;//�}�E�X�̍��{�^��
	bool starpresent_flag;
	bool page_flag;
	bool page_flag_b;
	int page;//���̃y�[�W�֍s�����߂̕ϐ�
	int page_max; //�ő�y�[�W��
	int page_b;
	int time;
	wchar_t str[256];
	wchar_t see[256];
	wchar_t strp[256]; //�y�[�W�\���p
	int g;//���g�̉���
	int k;//���g�̗���
	int t;//���̖��O�̈ʒu
	int l;//t�Ɗ|����p�̕ϐ�
	int s;//���̃N���b�N�̌�
	int std;
	int side_a;
	int side_b;
	int size;
	int size_y;
	int font;
	int ver;
	int VER_start; //�o�[������
	int fy;//���̖��O�̉���
	int font_size;//�����̑傫��
	int Interval_y;//�����̗����Ԋu35
	int IO_y; //y���W�J�n�n�_25
	int pagex; //�y�[�W���Wx
	int pagey; //�y�[�W���Wy
	int pagesize; //�y�[�W�T�C�Y
	int  left_end;//�������̍��̌��E�����߂�
	int pagemax;//�y�[�W���̌��E

	float start_time; //�}�E�X����J�n����
	bool start_flag; //�}�E�X����J�n�t���O

	int a_time;
	bool time_flag;

	float m_mou_time; //�A���I��h�~�^�C��
private:
	

};


