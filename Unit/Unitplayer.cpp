#include "Unitplayer.h"

Unitplayer::Unitplayer(){


}

void Unitplayer::Setup(){
	



}

void Unitplayer::Update(){
	if (is_move == false)
	{
	


	}
}

void Unitplayer::Draw(){


}

// �����ɂ���Ĉړ����鏈��
void Unitplayer::move(){
	switch (direction)
	{
	case Direction::NORTH:

		break;
	case Direction::SOUTH:

		break;
	case Direction::EAST:

		break;
	case Direction::WEST:

		break;
	}

	if (env.isPushKey(GLFW_KEY_UP))
	{
		direction = Direction::NORTH;
	}
	if (env.isPushKey(GLFW_KEY_DOWN))
	{
		direction = Direction::SOUTH;
	}
	if (env.isPushKey(GLFW_KEY_RIGHT))
	{
		direction = Direction::EAST;
	}
	if (env.isPushKey(GLFW_KEY_LEFT))
	{
		direction = Direction::WEST;
	}

}

//****************************************************************
// �Z�b�^�[
//****************************************************************
void Unitplayer::SetIsMove(bool is_move_){
	is_move = is_move_;
}