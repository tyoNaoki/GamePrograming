#pragma once
#include <DxLib.h>
#include "System.h"

class ISeen
{
public:
	//����ɑ΂��鋓��������������
	virtual bool Input() { return false; };

	virtual void Update(float Deltatime) {};
	virtual void Draw() {};
	virtual bool IsCharacter() { return true; }
	 ISeen() {};
	 ~ISeen() {};
};

