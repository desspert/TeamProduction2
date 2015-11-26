#include "Unitplayer.h"

Unitplayer::Unitplayer(){
	pos = Vec2f(500, -HEIGHT / 3);
	size = Vec2f(100, 200);
	direction = Direction::NORTH;
	can_move = false;
	is_attack = false;
	chara_type = Animationtype::NORMAL;



}

void Unitplayer::Setup(Status status){





}

void Unitplayer::Update(){
	if (can_move == false)
	{



	}
}

void Unitplayer::Draw(){

	drawFillBox(pos.x(), pos.y(),
				size.x(), size.y(),
				color);

	int num = unitlist->num;
	font.size(50);
	font.draw("No." + std::to_string(num), Vec2f(pos.x(), pos.y() - 100), Color::white);
	//font.draw("No." + std::to_string(status->hp), Vec2f(pos.x(), pos.y() - 200), Color::white);

}

//****************************************************************
// �Z�b�^�[
//****************************************************************
void Unitplayer::SetCanMove(bool can_move_){
	can_move = can_move_;
}
void Unitplayer::SetIsAttack(bool is_attack_){
	is_attack = is_attack_;
}

void Unitplayer::SetDirection(Direction ui_direction){
	//if (can_move == true)
		Move(ui_direction);
	direction = ui_direction;

}

void Unitplayer::SetSelectPos(Vec2f select_pos){
	pos -= select_pos;
}

void Unitplayer::SetSelectNum(int selectnumber){
	unitlist->num += selectnumber;
}

void Unitplayer::SetUnitlistPos(Vec2i getpos){
	unitlist->pos = getpos;
	SetDrawPos(getpos);
}

void Unitplayer::SetDrawPos(Vec2i getpos){
	pos.x() = getpos.x() * CHIPSIZE_X;
	pos.y() = getpos.y() * CHIPSIZE_Y;
}
//****************************************************************
// �Q�b�^�[
//****************************************************************
Status Unitplayer::GetStatus(){
	return Status{
		status->hp,
		status->power,
		status->magic_power,
		status->defense,
		status->magic_defense,
	};
}

Unitlist Unitplayer::GetUnitlist(){
	return Unitlist{
		unitlist->num,
		unitlist->pos,
	};
}

int Unitplayer::GetNum(){
	return unitlist->num;
}

Vec2f Unitplayer::GetSelectPos(){
	return Vec2f(500, -HEIGHT / 3);
}

Vec2i Unitplayer::GetPos(){
	return unitlist->pos;
}

//Job Unitplayer::GetJob(){
//	return job;
//}

// �����ɂ���Ĉړ����鏈��
void Unitplayer::Move(Direction ui_direction){
	Vec2i speed = Vec2i(CHIPSIZE_X, CHIPSIZE_Y);
	switch (direction)
	{
	case Direction::NORTH:
		switch (ui_direction)
		{
		case Direction::NORTH:
			unitlist->pos.y() += 1;
			move_limit.y() -= speed.y();
			pos.y() += speed.y();
			break;
		case Direction::SOUTH:
			direction = Direction::SOUTH;
			break;
		case Direction::EAST:
			direction = Direction::EAST;
			break;
		case Direction::WEST:
			direction = Direction::WEST;
			break;
		}
		break;
	case Direction::SOUTH:
		switch (ui_direction)
		{
		case Direction::NORTH:
			direction = Direction::NORTH;
			break;
		case Direction::SOUTH:
			unitlist->pos.y() -= 1;
			move_limit.y() -= speed.y();
			pos.y() -= speed.y();
			break;
		case Direction::EAST:
			direction = Direction::EAST;
			break;
		case Direction::WEST:
			direction = Direction::WEST;
			break;
		}
		break;
	case Direction::EAST:
		switch (ui_direction)
		{
		case Direction::NORTH:
			direction = Direction::NORTH;
			break;
		case Direction::SOUTH:
			direction = Direction::SOUTH;
			break;
		case Direction::EAST:
			unitlist->pos.x() += 1;
			move_limit.x() -= speed.x();
			pos.x() += speed.x();
			break;
		case Direction::WEST:
			direction = Direction::WEST;
			break;
		}
		break;
	case Direction::WEST:
		switch (ui_direction)
		{
		case Direction::NORTH:
			direction = Direction::NORTH;
			break;
		case Direction::SOUTH:
			direction = Direction::SOUTH;
			break;
		case Direction::EAST:
			direction = Direction::EAST;
			break;
		case Direction::WEST:
			unitlist->pos.x() -= 1;
			move_limit.x() -= speed.x();
			pos.x() -= speed.x();
			break;
		}
		break;
	}
	if (move_limit.x() < 0 || move_limit.y() < 0){
		can_move = false;
		move_limit = Vec2f(CHIPSIZE_X, CHIPSIZE_Y);
	}
}

void Unitplayer::Animation(){

	switch (chara_type)
	{
	case Animationtype::NORMAL:
		//CharacterAnimation(pos, size, offset_size, chara_normal, 4, 20, 0);
		break;
	case Animationtype::MOVE:
		//CharacterAnimation(pos, size, offset_size, chara_normal, 4, 20, 0);
		break;
	case Animationtype::ATTACK:
		//CharacterAnimation(pos, size, offset_size, chara_normal, 4, 20, 0);
		break;

	}
}


