#pragma once
#include <DxLib.h>
#include <vector>
#include "ISeen.h"
#include <memory>

enum Category_Task {
	CTask_Game = 0,
};

class SeenController
{
	std::vector<ISeen*>m_SeenList;
public:
	SeenController();
	~SeenController();
	bool AddTask(Category_Task Ctask);
	bool EraseTask(int EraseID);
	void MainUpdate(float Deltatime);
	ISeen GetCurrentTask_ptr() { return *m_SeenList[CurrentSeenNumber]; }
private:
	int CurrentSeenNumber = 0;
};

