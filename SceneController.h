#pragma once
#include <DxLib.h>
#include <vector>
#include "IScene.h"
#include "Scene_Tytle.h"
#include "Scene_Game.h"
#include <unordered_map>

enum Scene;
#include "Render.h"


class SceneController
{
public:
	SceneController();
	~SceneController();
	virtual void AddScene(Scene name,IScene *scene);
	virtual void MainUpdate(float Deltatime);
	virtual void Initialize();
	virtual void Change(Scene name);
	virtual void MainRender(float Deltatime);
	virtual void Finalize();
private:
	IScene *currentSeen;
	Render *render;
	std::unordered_map<Scene, IScene*>scenes;
	float alpha;
	Scene_Tytle *Tytle;
	Scene_Game *Game;
	bool IsFinishedInitialize ;
};