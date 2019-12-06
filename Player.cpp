#include "Player.h"
#include "Dxlib.h"
#include "Input.h"

const float Player::WalkSpeed = 10.0f;
const float RunSpeed = 1.0f;
const int DefaultHP = 1;
const float AvoidanceSpeed = 1.0f;
const float GardSpeed = 1.0f;
static const float MaxTwistAngle = 90.0f;

Player::Player(World &world, Vector3 &pos,std::string &_name) 
	: CharacterBase(world,position)
{
	HP = 100;
	Diffence = 0;
	Name = _name;
	position = pos;
	matrix *= Matrix4::CreateFromAxisAngle(Vector3::Up, 180);
}

Player::~Player(){
}

void Player::Initialize(Render &renderer) {
	
}

void Player::Update(float Deltatime) {
	Move(Deltatime);
	Twist();
}

void Player::LookAtDirectionOfMovement(const Vector3& velocity) {
	//�i�s�������y(�O����)�ɐݒ肷��B
	Vector3 z = velocity;
	//�������������(Y��)�ƑO�����ŊO�ς��Ƃ��ċ��߂�B
	Vector3 x = Vector3(0, 1, 0).Cross(z);
	//�V���ɏ������O�����ƍ������ŊO�ς��Ƃ��ċ��߂�B
	Vector3 y = z.Cross(x);

	matrix.SetLeft(-x);
	matrix.SetUp(y);
	matrix.SetFront(-z);

	twistAngle = Vector3(velocity).Yaw();
	maxTwistAngle = twistAngle + 45.0f;
}

void Player::SubUpdate(float Delattime){
}

void Player::Draw(float Deltatime, Render &renderer){
	renderer.Draw3DModel("Player",GetMatrix());
}

void Player::SubDraw(float Deltatime, Render &renderer){

}

void Player::Move(float Deltatime) {
	Vector3 velocity = Input::GetInstance().GetWASDVelocity();

	if (velocity.SquareLength() > 0.0f) inertiaVector = velocity;
	Vector3 plusVelocity;
	
	if (velocity.SquareLength() <= 0.0f) {
		speed = Math::Lerp(speed, 0.0f, 0.05f); //�������c��
		if (speed <= 0.1f || inertiaVector.SquareLength() <= 0.0f) {
			//animeIndex = (int)Player::Anime::Idle;
			//world->TimerUpdate(frameTime);
			return;
		}
		else {
			//animeIndex = (int)Player::Anime::Walk;
		}
		plusVelocity = inertiaVector * speed * Deltatime;
	}
	else {
		LookAtDirectionOfMovement(velocity);
		plusVelocity = velocity * speed * Deltatime;
	}
	position += plusVelocity;
}

void Player::Twist() {
	float angle = 0.0f;

	//�L�[�{�[�h�m�F�p
	if (Input::GetInstance().IsKeyBoardState(KEY_INPUT_I)
		&& Input::GetInstance().IsKeyBoardState(KEY_INPUT_U)) {//�����ɉ������ƂŊp�x���Œ肷��
		keyBoadAngle = Math::Clamp(keyBoadAngle, -MaxTwistAngle, MaxTwistAngle);
		isTwist = true;
		matrix.SetRotateY(keyBoadAngle + 180);
		return;
	}
	else if (Input::GetInstance().IsKeyBoardState(KEY_INPUT_I)) {
		angle = 1.0f;
		keyBoadAngle += angle;
	}
	else if (Input::GetInstance().IsKeyBoardState(KEY_INPUT_U)) {
		angle = -1.0f;
		keyBoadAngle += angle;
	}

	if (angle == 0.0f) {
		isTwist = false;
		keyBoadAngle = 0.0f;
		return;
	}

	twistAngle +=  keyBoadAngle;

	twistAngle = Math::Clamp<float>(twistAngle, maxTwistAngle - 45.0f * 2.0f, maxTwistAngle);

	isTwist = true;
	shoulderMatrix.SetRotateY(twistAngle);
}

int Player::GetHP(){
	return HP;
}

int Player::GetGard(){
	return Diffence;
}

std::string Player::GetName() {
	return Name;
}

float Player::GetVelocity(){
	return Velocity;
}

bool Player::IsDeath(){
	return HP <= 0;
}

bool Player::IsCancel() {
	return false;
}

void Player::Animation(float Deltatime){
}

void Player::LookAtTarget(ObjectBase *target){

}

void Player::LookAtDirection(Vector3 &TargetPostion){

}
