#pragma once
#include "IScene.h"
#include "Vector2.h"
#include "Render.h"
#include "Color.h"

class Scene_Tytle :
	public IScene
{
public:
	void Update(float Deltatime)override;
	void Initialize() override;
	void LoadAsset() override;
	void Finalize() override;
protected:
	void Draw(float Deltatime)override;
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
	_Color color = _Color(1.0f, 1.0f, 1.0f, 1.0f);
};

