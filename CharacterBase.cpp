#include "CharacterBase.h"



void CharacterBase::BaseUpdate(float Deltatime) {
	Update(Deltatime);
	SubUpdate(Deltatime);
}

void CharacterBase::BaseDraw(float Deltatime,Render &renderer) {
	Draw(Deltatime,renderer);
	SubDraw(Deltatime,renderer);
}