#include "SeenController.h"
#include <DxLib.h>
#include "ISeen.h"
#include "Seen_Game.h"
#include <memory>


SeenController::SeenController()
{
}

SeenController::~SeenController()
{
	for (auto it = m_SeenList.begin(); it != m_SeenList.end(); it++) {
		delete *it;
	}
}

bool SeenController::AddTask(Category_Task Ctask) {

	ISeen *pTask = NULL;
	switch (Ctask)
	{
	case CTask_Game:
		pTask = new Seen_Game;
		break;
	}
	if (pTask != NULL)
	{
		m_SeenList.push_back(pTask);
	}
	return true;
}

//bool MainTask_Controller::EraseTask(Category_Task)  {
//	for (auto it = m_TaskList.begin(); it != m_TaskList.end(); it++) {
//		if (it->get()->ID == EraseID) {
//			m_TaskList.remove(*it);
//			return true;
//		}
//	}
//	return false;
//}

void SeenController::MainUpdate(float Deltatime) {
	m_SeenList[CurrentSeenNumber]->Update(Deltatime);
}