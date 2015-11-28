#pragma once
#include "../Share/Share.h"
#include "../Unit/Player/Player.h"

class Unitplayer : public Chara{
private:

	
	void Animation();

	Font font = Font("res/meiryo.ttc");


	//�ԍ�������W������o���֐�
	void SetDrawPos(Vec2i getpos);

public:


	Unitplayer();

	void Setup(Status status);
	void Update();
	void Draw();
	//�Z���N�g�Ɏg���֐�
	void SetSelectPos(Vec2f select_pos);
	void SetSelectNum(int selectnumber);
	//�Z���N�g�Ɏg���֐�
	Vec2f GetSelectPos();

	void Move(Direction ui_direction);
	//�}�b�v����canmove�����炤�Z�b�^�[
	void SetCanMove(bool can_move_);
	//�}�b�v����isattack�����炤�Z�b�^�[
	void SetIsAttack(bool is_attack_);
	//UI����direction��������Ă��̕����ɓ����֐�
	void SetDirection(Direction ui_direction);
	//�}�b�v�`�b�v�ԍ������炤�Z�b�^�[
	void SetUnitlistPos(Vec2i getpos);

	//�}�b�v��Unitllist�ɓn���֐� 
	Unitlist GetUnitlist();
	//�`�b�v�ԍ���Ԃ��֐�
	Vec2i GetPos();
	//UI�ɃX�e�[�^�X��Ԃ��֐�
	Status GetStatus();
	//�i���o�[��Ԃ��֐�
	int GetNum();
	//�W���u��Ԃ��֐��i�g���ĂȂ��j
	Job GetJob();
	Direction GetDirection();

};

