#include "Task_Game.h"
#include "ITask.h"
#include <DxLib.h>


Task_Game::Task_Game(int id)
{
	ITask::ID = id;
}


Task_Game::~Task_Game()
{
}

void Task_Game::Update(float Deltatime) {
}

void Task_Game::Draw(float Deltatime) {
}