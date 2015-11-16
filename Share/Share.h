#pragma once
#include "../lib/framework.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <list>

#define env App::Get()
#define pose Gamecount::GameCount()
#define CHIPSIZE_X (128)
#define CHIPSIZE_Y (64)

enum Maptype
{
	LOAD,
	NONE
};

enum Windowsize{
	WIDTH = 1920,
	HEIGHT = 1080,
};

class App{
public:
	static AppEnv& Get(){
		static AppEnv singleton_env(WIDTH, HEIGHT, false, true);
		return singleton_env;
	}
};


enum class Scenename
{
	TITLE,			//�^�C�g��
	GAMEMANAGER,	//�Q�[���}�l�[�W���[
	UNITSELECT,		//���j�b�g�Z���N�g
	GAMEMAIN,		//�Q�[�����C��
	RESULT,			//���U���g
};

enum class Ismove
{
	STOP,	//�~�܂��Ă���
	MOVE,	//�����Ă���
};

enum class Direction
{
	NORTH,		//�k
	SOUTH,		//��
	EAST,		//��
	WEST,		//��
};


enum class Job
{
	WARRIOR,	//��m
	LANCER,		//�����T�[�@

	JOB_MAX,
};


class Gamecount{
public:

	//�G�X�P�[�v��������J�E���g���~�߂�֐��i�S�̂̏������~�߂�̂Ɏg���j
	static int GameCount(bool is_count = true){
		static int count = 0;
		static bool is_stop = false;
		if (is_count == true)
		{
			return count;
		}
		else
		{
			if (is_stop == false)
			{
				count++;
			}
			if (count == 0)
			{
				if (env.isPushKey(GLFW_KEY_ESCAPE))
				{
					is_stop = false;
				}
			}
			if (count > 0)
			{
				if (env.isPushKey(GLFW_KEY_ESCAPE))
				{
					is_stop = true;
					count = 0;
				}
			}


			return 0;
		}
	}
};

struct Unitlist
{
	int num;
	Vec2i pos;
};

struct Status{
	int hp;
	float power;
	float magic_power;
	float defense;
	float magic_defense;

	int num;

	Status(int hp,
		   float power,
		   float magic_power,
		   float defense,
		   float magic_defense):
		   hp(hp),
		   power(power),
		   magic_power(magic_power),
		   defense(defense),
		   magic_defense(magic_defense)
	{}
};


//�l�p�Ǝl�p�̓����蔻��
static bool boxCollision(Vec2f box_pos, Vec2f box_size, Vec2f box1_pos, Vec2f box1_size) {
	return (
		box_pos.x() < box1_pos.x() + box1_size.x() &&
		box_pos.x() + box_size.x() > box1_pos.x() &&
		box_pos.y() < box1_pos.y() + box1_size.y() &&
		box_pos.y() + box_size.y() > box1_pos.y());
}
