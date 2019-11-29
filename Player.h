#pragma once
#include "CharacterBase.h"


class Player :
	public CharacterBase
{
public:
	Player(World &world, Vector3 &position);
	~Player();
	void Initialize(Render &renderer)override;
	void Update(float Deltatime)override;
	void SubUpdate(float Delattime)override;
	void Draw(float Deltatime, Render &renderer) override;
	void SubDraw(float Deltatime, Render &renderer)override;
	void Move(float Deltatime) override;
	int GetHP() override;
	int GetGard() override;
	float GetVelocity() override;
	bool IsDeath() override;
	bool IsCancel() override;
	void Animation(float Deltatime) override;
	void LookAtTarget(ObjectBase *target) override;
	void LookAtDirection(Vector3 &TargetPostion) override;
private:
	int HP;
	int Gard;

	bool IsKnockBack;

	bool IsAttack;
	bool IsGard;
	bool IsJuming;
	bool Avoidance;
	float JumpingTime;

	float timer;
	float AvoidanceTimer;
	float actionAnimTImer;
	float animTime;
	float Velocity;
	int AnimIndex;

	float rate;

	ObjectBase *target;
	Vector3 targetVector;
	Vector3 inertiaVector;


	enum class Anim {
		Idle,
		Walk,
		Run,
		Damaged,
		Jump,
		RightTwist,
		LeftTwist,
		ForwardKnockDown,
		BackKnockDown,
		RightKnockDown,
		LeftKnockDown,
		Sword,
		Shild,
		Death,
	};

	static const float WalkSpeed;
	static const float RunSpeed;
	static const int DefaultHP;
	static const float AvoidanceSpeed;
	static const float GardSpeed;
};

