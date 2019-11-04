#pragma once
#include <DxLib.h>
#include <list>
#include "ITask.h"
#include <memory>
class MainTask_Controller
{
	std::list<std::unique_ptr<ITask>>m_TaskList;
public:
	MainTask_Controller();
	~MainTask_Controller();
	bool AddTask(std::unique_ptr<ITask>task);
	bool EraseTask(int EraseID);
	void MainUpdate(float Deltatime);
	ITask GetCurrentTask_ptr() { return *CurrentTask; }

private:
	ITask *CurrentTask;
	ITask *BackTask;
	ITask *NextTask;
};

