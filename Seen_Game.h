#pragma once
#include "ISeen.h"
#include <DxLib.h>

class Seen_Game :
	public ISeen
{
private:
	void Update(float Deltatime)override;
	void Draw()override;
public:
	Seen_Game();
	~Seen_Game();
};

