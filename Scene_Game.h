#pragma once
#include "IScene.h"
#include "Render.h"
#include <DxLib.h>

class Scene_Game :
	public IScene
{
private:
	void Update(float Deltatime)override;
	void Initialize() override;
	void LoadAsset() override;
	void Finalize() override;
protected:
	void Draw()override;
public:
	Scene_Game(Render *renderer);
	~Scene_Game();
	bool IsEnd()const override;

	Scene Next()override;

private:
	bool isEnd;
	Render *render;

	Matrix4 PlayerPos = Matrix4();
};

