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
	virtual bool Input() = 0;

	virtual void Update(float Deltatime) =0;
	virtual void Draw() =0;
	virtual void LoadAsset() =0;
	virtual bool IsEnd() const = 0;
	virtual void Initialize()=0;
	virtual void Finalize() =0;
	virtual Scene Next() = 0;
	virtual ~ISeen() {};
};

