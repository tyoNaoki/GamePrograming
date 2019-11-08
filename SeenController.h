#pragma once
#include <DxLib.h>
#include <list>
#include "ISeen.h"
#include <memory>

enum Category_Task {
	CTask_Game = 0,
};

class SeenController
{
	std::list<ISeen*>m_TaskList;
public:
	SeenController();
	~SeenController();
	bool AddTask(Category_Task Ctask);
	bool EraseTask(int EraseID);
	void MainUpdate(float Deltatime);
	ISeen GetCurrentTask_ptr() { return *CurrentTask; }

	Category_Task Category_task;

private:
	ISeen *CurrentTask;
	ISeen *BackTask;
	ISeen *NextTask;
};

