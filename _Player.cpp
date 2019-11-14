#include "_Player.h"
#include "Dxlib.h"

_Player::_Player(_SPlayerData *playerdata)
{
	SPlayerData = playerdata;
}


_Player::~_Player()
{
}
void _Player::Movement(char *key) {
	char Key[256];
	if (Key[KEY_INPUT_W] >= 1) {
		SPlayerData->location.y--;
	}
	if (key[KEY_INPUT_S] >= 1) {
		SPlayerData->location.y++;
	}
	if (key[KEY_INPUT_A] >= 1) {
		SPlayerData->location.x--;
	}
	if (key[KEY_INPUT_D] >= 1) {
		SPlayerData->location.x++;
	}
}

void _Player::Update(float Deltatime) {
	PController->UpdateKey();
	Movement(*PController->key);
}

