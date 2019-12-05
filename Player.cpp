#include "Player.h"
#include "Dxlib.h"
#include "Input.h"

const float Player::WalkSpeed = 10.0f;
const float RunSpeed = 1.0f;
const int DefaultHP = 1;
const float AvoidanceSpeed = 1.0f;
const float GardSpeed = 1.0f;

Player::Player(World &world, Vector3 &pos,std::string &_name) 
	: CharacterBase(world,position)
{
	HP = 100;
	Diffence = 0;
	Name = _name;
	position = pos;
}

Player::~Player(){
}

void Player::Initialize(Render &renderer) {
	
}

void Player::Update(float Deltatime) {
	if (Input::GetInstance().GetCommand(Command::Up)) {
		position.x += WalkSpeed * Deltatime;
	}
	if(Input::GetInstance().GetCommand(Command::Down)){
		position.x -= WalkSpeed * Deltatime;
	}
	if (Input::GetInstance().GetCommand(Command::Left)) {
		position.y += WalkSpeed * Deltatime;
	}
	if (Input::GetInstance().GetCommand(Command::Right)) {
		position.y -= WalkSpeed * Deltatime;
	}
}

void Player::SubUpdate(float Delattime){
}

void Player::Draw(float Deltatime, Render &renderer){
	renderer.Draw3DModel(Name, Matrix4::Translate(position));
}

void Player::SubDraw(float Deltatime, Render &renderer){

}

void Player::Move(float Deltatime){

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
