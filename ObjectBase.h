#pragma once
#include "Dxlib.h"
#include "Render.h"
#include "World.h"
#include "Vector3.h"

typedef struct ObjectAngle {
	float X;
	float Y;
	float Z;
};

class World;

typedef struct ObjectBaseData {
public:
	VECTOR location = { 0,0,0 };
	//Collisionがありかどうか
	bool Collision = false;
	//モデルデータ
	int ModelHandle;
	//名前
	char Name;
	//角度
	ObjectAngle *SObjectAngle;
};

class ObjectBase
{
public:
	ObjectBase(World &world,Vector3 &position): pos(position),world(&world){};
	virtual ~ObjectBase() {};
	virtual void Initialize(Render &renderer) = 0;

	virtual void Move(float Deltatime) = 0;
	virtual int GetHP() = 0;
	virtual int GetGard() = 0;
	virtual float GetVelocity() = 0;
	virtual bool IsDeath() = 0;
	virtual bool IsCancel() = 0;
	virtual void Animation(float Deltatime) = 0;
	virtual void LookAtTarget(ObjectBase *target) = 0;
	virtual void LookAtDirection(Vector3 &TargetPostion) = 0;
	virtual void Update(float Deltatime) = 0;
	virtual void Draw(float Deltatime, Render &renderer) = 0;
	Vector3 pos;
	bool Collision;
	World *world;

};

