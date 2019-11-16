#pragma once
#include "Dxlib.h"

typedef enum _EObjectType {
	Object,
	Player,
	Enemy
};

typedef struct _SObjectAngle {
	float X;
	float Y;
	float Z;
};

typedef struct _SObjectBaseData {
public:
	VECTOR location = { 0,0,0 };
	//Collisionがありかどうか
	bool Collision = false;
	//モデルデータ
	int ModelHandle;
	//名前
	char Name;
	//角度
	_SObjectAngle *SObjectAngle;
};


class ObjectBase
{
public:
	ObjectBase();
	~ObjectBase();
};

