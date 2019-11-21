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
	//Collision�����肩�ǂ���
	bool Collision = false;
	//���f���f�[�^
	int ModelHandle;
	//���O
	char Name;
	//�p�x
	_SObjectAngle *SObjectAngle;
};


class ObjectBase
{
public:
	ObjectBase();
	~ObjectBase();
};

