#pragma once
#include <DxLib.h>
#include <vector>
#include "ISeen.h"
#include <unordered_map>

enum Scene;
#include "Render.h"


class SeenController
{
public:
	SeenController();
	~SeenController();
	bool AddTask(Scene name,ISeen *scene);
	virtual void MainUpdate(float Deltatime);
	virtual void Initialize();
	virtual void Change(Scene name);
private:
	ISeen *currentSeen;
	Render render;
	std::unordered_map<Scene, ISeen*>scenes;
};