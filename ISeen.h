#pragma once
#include <DxLib.h>
#include "System.h"

class ISeen
{
public:
	//操作に対する挙動が成功したか
	virtual bool Input() { return false; };

	virtual void Update(float Deltatime) {};
	virtual void Draw() {};
	virtual bool IsCharacter() { return true; }
	 ISeen() {};
	 ~ISeen() {};
};

