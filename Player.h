#pragma once
#include "CharacterBase.h"

enum class PlayerAnimation {
	Idle,
	Walk,
	Run,
	Attack01,
	Attack02,
	Attack03,
	GardShild,
	Jump,
	Death
};

class Player :
	public CharacterBase
{
public:
	Player(World &world, Vector3 &pos,std::string &_name);
	~Player();
	void Initialize(Render &renderer)override;
	void Update(float Deltatime)override;
	void SubUpdate(float Delattime)override;
	void Draw(float Deltatime, Render &renderer) override;
	void SubDraw(float Deltatime, Render &renderer)override;
	void Move(float Deltatime) override;
	void Twist() override;
	int GetHP() override;
	int GetGard() override;
	std::string GetName() override;
	float GetVelocity() override;
	bool IsDeath() override;
	bool IsCancel() override;
	void Animation(float Deltatime) override;
	void LookAtTarget(ObjectBase *target) override;
	void LookAtDirection(Vector3 &TargetPostion) override;
private:
	void LookAtDirectionOfMovement(const Vector3& velocity);

	bool IsKnockBack;

	float speed = 0;
	bool IsAttack;
	bool IsGard;
	bool IsJuming;
	bool Avoidance;
	bool isTwist = false;
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

	float twistAngle;
	float maxTwistAngle;

	float keyBoadAngle;

	Matrix4 shoulderMatrix;

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

