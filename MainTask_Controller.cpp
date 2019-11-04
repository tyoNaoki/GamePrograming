#include "MainTask_Controller.h"
#include <DxLib.h>
#include "ITask.h"
#include <memory>

MainTask_Controller::MainTask_Controller()
{
}


MainTask_Controller::~MainTask_Controller()
{
}

bool MainTask_Controller::AddTask(std::unique_ptr<ITask>task) {
	int id = task->ID;
	for (auto it = m_TaskList.begin(); it != m_TaskList.end(); it++) {
		if (it->get()->ID == id) {
			task.reset();
			return false;
		}
	}
	m_TaskList.push_back(move(task));
	return true;
}

bool MainTask_Controller::EraseTask(int EraseID) {
	for (auto it = m_TaskList.begin(); it != m_TaskList.end(); it++) {
		if (it->get()->ID == EraseID) {
			m_TaskList.remove(*it);
			return true;
		}
	}
	return false;
}

void MainTask_Controller::MainUpdate(float Deltatime) {
	CurrentTask->Update(Deltatime);
}