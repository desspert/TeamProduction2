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


enum class Scenename{
	TITLE,			//�^�C�g��
	GAMEMANAGER,	//�Q�[���}�l�[�W���[
	UNITSELECT,		//���j�b�g�Z���N�g
	GAMEMAIN,		//�Q�[�����C��
	RESULT,			//���U���g
};

enum class Ismove{
	STOP,	//�~�܂��Ă���
	MOVE,	//�����Ă���
};

enum class Direction{
	UP,			//�O
	DOWN,		//���
	RIGHT,		//�E
	LEFT,		//��
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