#pragma once
#include "ISeen.h"
#include "Vector2.h"
#include "Render.h"

class Seen_Tytle :
	public ISeen
{
public:
	void Update(float Deltatime)override;
	//操作に対する挙動が成功したか
	bool Input()override;

	void LoadAsset() override;
protected:
	void Draw()override;
public:
	Seen_Tytle(Render *renderer);
	~Seen_Tytle();
	bool IsEnd()const override;

	Scene Next()override;

	

	void Barsize() {};

private:
	bool isEnd;
	float Nextpos;
	Vector2 framePosition;
	Render* renderer = new Render;
	Scene NextScene = Scene::Battle;
};

