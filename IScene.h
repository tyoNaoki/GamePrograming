#pragma once
#include <DxLib.h>
#include "System.h"

enum  Scene {
	None,
	Title,
	Menu,
	Battle
};

class IScene
{
public:
	virtual void Update(float Deltatime) =0;
	virtual void Draw(float Deltatime) =0;
	virtual void LoadAsset() =0;
	virtual bool IsEnd() const = 0;
	virtual void Initialize()=0;
	virtual void Finalize() =0;
	virtual Scene Next() = 0;
	virtual ~IScene() {};
};

