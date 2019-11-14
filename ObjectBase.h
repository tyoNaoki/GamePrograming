#pragma once
#include "Dxlib.h"

typedef enum _EObjectType {
	Object,
	Chara
};

typedef struct _SObjecAngle {
	float X;
	float Y;
	float Z;
};

typedef struct _SObjectBaseData {
	VECTOR location = { 0,0,0 };
	//Collisionがありかどうか
	bool Collision = false;
	//モデルデータ
	int ModelHandle;
	//オブジェクトのタイプ
	_EObjectType *EObjectType;
	//名前
	char Name;
	//角度
	_SObjecAngle *SObjectAngle;
};


class ObjectBase
{
public:
	ObjectBase();
	~ObjectBase();
};

