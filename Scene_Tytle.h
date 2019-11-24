#pragma once
#include "IScene.h"
#include "Vector2.h"
#include "Render.h"

class Scene_Tytle :
	public IScene
{
public:
	void Update(float Deltatime)override;
	void Initialize() override;
	void LoadAsset() override;
	void Finalize() override;
protected:
	void Draw()override;
public:
	Scene_Tytle(Render *renderer);
	~Scene_Tytle();
	bool IsEnd()const override;

	Scene Next()override;

	void BarSlide();

private:
	bool isEnd;
	float Nextpos;
	Vector2 framePosition;
	Render* renderer = new Render;
	Scene NextScene = Scene::Battle;
	float barSize;
};

