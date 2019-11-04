#pragma once
#include "ITask.h"
#include <DxLib.h>

class Task_Game :
	public ITask
{
private:
	void Update(float Deltatime)override;
	void Draw(float Deltatime)override;
public:
	Task_Game(int id);
	~Task_Game();
};

