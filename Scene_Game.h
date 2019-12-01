#pragma once
#include "IScene.h"
#include "Render.h"
#include <DxLib.h>
#include "World.h"
#include "StageBase.h"

class World;
class StageBase;
class Render;

class Scene_Game :
	public IScene
{
private:
	void Update(float Deltatime)override;
	void Initialize() override;
	void LoadAsset() override;
	void Finalize() override;
protected:
	void Draw(float Deltatime)override;
public:
	Scene_Game(Render *renderer);
	~Scene_Game();
	bool IsEnd()const override;

	Scene Next()override;

private:
	bool isEnd;
	Render *render;
	World *worlds;
};

