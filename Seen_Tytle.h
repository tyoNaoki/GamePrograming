#pragma once
#include "ISeen.h"
#include "Vector2.h"
#include "Render.h"

class Seen_Tytle :
	public ISeen
{
public:
	void Update(float Deltatime)override;
	//‘€ì‚É‘Î‚·‚é‹““®‚ª¬Œ÷‚µ‚½‚©
	bool Input()override;

	void Draw()override;
	Seen_Tytle();
	~Seen_Tytle();

private:
	bool isEnd;
	float Next;
	float Barsize;
	Vector2 framePosition;
	Render renderer;
};

