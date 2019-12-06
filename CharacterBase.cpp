#include "CharacterBase.h"

CharacterBase::CharacterBase(World &_world, Vector3 &_position)
	: world(&_world), position(_position){};

void CharacterBase::BaseUpdate(float Deltatime) {
	Update(Deltatime);
	SubUpdate(Deltatime);
}

void CharacterBase::BaseDraw(float Deltatime,Render &renderer) {
	Draw(Deltatime,renderer);
	SubDraw(Deltatime,renderer);
}

Vector3 CharacterBase::GetPosition()const {
	return position;
}

Matrix4 CharacterBase::GetMatrix()const {
	return Matrix4(matrix).SetPosition(position);
}