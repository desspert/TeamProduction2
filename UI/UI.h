#pragma once
#include "../Share/Share.h"
struct UI{
	Vec2f pos;
	Vec2f size;
};
class Ui{
private:
	UI command_board;
	UI command;
	UI status_board;
	float angle;
	float animation;
	int instruction;
	bool action;
	//�v���C���[������炤���
	
	Vec2f plyer_pos;

	//Get���
	Direction direction;
	int number;
	bool attack;
public:
	Ui();
	void Update();
	void Draw();
	void BoardDraw();
	void OperatePlayer();
	void Move();
	void Animation();
	void OperateCursor();
	void Select();

	Direction GetDir();
	int GetUnitNum();
};