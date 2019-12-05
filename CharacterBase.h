#pragma once

#include "DxLib.h"
#include "ObjectBase.h"
#include "Vector3.h"

class ObjectBase;

class CharacterBase
{
public:
	virtual void Initialize(Render &renderer) = 0;
	
	virtual void Move(float Deltatime) = 0;
	virtual std::string GetName() = 0;
	virtual int GetHP() = 0;
	virtual int GetGard() = 0;
	virtual float GetVelocity() = 0;
	virtual bool IsDeath() = 0;
	virtual bool IsCancel() = 0;
	virtual void Animation(float Deltatime) = 0;
	virtual void LookAtTarget(ObjectBase *target) =0;
	virtual void LookAtDirection(Vector3 &TargetPostion) =0;
	CharacterBase(World &_world, Vector3 &_position);
	virtual ~CharacterBase() {};

protected:
	virtual void Update(float Deltatime)=0;
	virtual void SubUpdate(float Deltatime)=0;
	virtual void Draw(float Deltatime, Render &renderer)=0;
	virtual void SubDraw(float Deltatime, Render &renderer)=0;

public:
	void BaseUpdate(float Deltatime);
	void BaseDraw(float Deltatime,Render &renderer);

protected:
	World *world;
	Vector3 position;
	std::string Name;
	int HP;
	int Diffence;
}; 

