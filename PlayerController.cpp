#include "PlayerController.h"



PlayerController::PlayerController()
{
}


PlayerController::~PlayerController()
{
}

void PlayerController::UpdateKey() {
	GetHitKeyStateAll(*key);
	for (i = 0; i < 256; i++) {
		if (*key[i] != 0) {
			*key[i]++;
		}
		else
		{
			*key[i] = 0;
		}
	}
}

void PlayerController::Update(float Deltatime) {

}