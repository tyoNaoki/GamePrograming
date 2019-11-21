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
	//操作に対する挙動が成功したか
	virtual bool Input() { return false; };

	virtual void Update(float Deltatime) {};
	virtual void Draw() {};
	virtual void LoadAsset() {};
	virtual bool IsEnd() const = 0;
	virtual Scene Next() = 0;
	virtual ~ISeen() {};
};

