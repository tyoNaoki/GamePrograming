#pragma once
#include <DxLib.h>
#include <vector>
#include "ISeen.h"
#include "Seen_Tytle.h"
#include <unordered_map>

enum Scene;
#include "Render.h"


class SeenController
{
public:
	SeenController();
	~SeenController();
	virtual void AddScene(Scene name,ISeen *scene);
	virtual void MainUpdate(float Deltatime);
	virtual void Initialize();
	virtual void Change(Scene name);
	virtual void MainRender(float Deltatime);
	virtual void Finalize();
private:
	ISeen *currentSeen;
	Render *render;
	std::unordered_map<Scene, ISeen*>scenes;
	float alpha;
	Seen_Tytle *Tytle;
};