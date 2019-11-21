#pragma once
#include "ISeen.h"
#include "Vector2.h"
#include "Render.h"

class Seen_Tytle :
	public ISeen
{
public:
	void Update(float Deltatime)override;
	//����ɑ΂��鋓��������������
	bool Input()override;

	void LoadAsset() override;
protected:
	void Draw()override;
public:
	Seen_Tytle(Render *renderer);
	~Seen_Tytle();
	bool IsEnd()const override;

	void Barsize();

private:
	bool isEnd;
	float Next;
	float barsize;
	Vector2 framePosition;
	Render* renderer = new Render;
};

