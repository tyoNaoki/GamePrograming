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
	//Collision�����肩�ǂ���
	bool Collision = false;
	//���f���f�[�^
	int ModelHandle;
	//�I�u�W�F�N�g�̃^�C�v
	_EObjectType *EObjectType;
	//���O
	char Name;
	//�p�x
	_SObjecAngle *SObjectAngle;
};


class ObjectBase
{
public:
	ObjectBase();
	~ObjectBase();
};

