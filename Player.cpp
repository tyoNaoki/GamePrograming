#include "Player.h"
#include "Dxlib.h"
#include "Input.h"

Player::Player(World &world, Vector3 &position) 
	: CharacterBase(world,position),HP(100),Gard(0){

}


Player::~Player(){
}

void Player::Initialize(Render &renderer) {
	
}

void Player::Update(float Deltatime) {
	if (Input::GetInstance().GetCommand(Command::Up)) {
		
	}
}

void Player::SubUpdate(float Delattime){
}

void Player::Draw(float Deltatime, Render &renderer){
}

void Player::SubDraw(float Deltatime, Render &renderer){

}

void Player::Move(float Deltatime){

}

int Player::GetHP(){
	return HP;
}

int Player::GetGard(){
	return Gard;
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
