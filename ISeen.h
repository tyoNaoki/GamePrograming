#pragma once
#include <DxLib.h>
#include "System.h"

enum  Scene {
	None,
	Title,
	Menu,
	Battle,
};

class ISeen
{
public:
	//‘€ì‚É‘Î‚·‚é‹““®‚ª¬Œ÷‚µ‚½‚©
	virtual bool Input() { return false; };

	virtual void Update(float Deltatime) {};
	virtual void Draw() {};
	virtual void LoadAsset() {};
	virtual bool IsEnd() const = 0;
	virtual Scene Next() = 0;
	virtual ~ISeen() {};
};

