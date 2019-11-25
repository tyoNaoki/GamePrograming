#include "_Player.h"
#include "Dxlib.h"

_Player::_Player(_SPlayerData &playerdata){
	SPlayerData = playerdata;
	bool Debug = SObjectBaseData.ModelHandle = MV1LoadModel("Data\\Character\\Player\\PC.mv1");
	SObjectBaseData.location.y = 100;
}

_Player::_Player() {

}

_Player::~_Player()
{
}
void _Player::Movement(char *key) {
	char Key[256];
	if (Key[KEY_INPUT_W] >= 1) {
		SObjectBaseData.location.y--;
	}
	if (key[KEY_INPUT_S] >= 1) {
		SObjectBaseData.location.y++;
	}
	if (key[KEY_INPUT_A] >= 1) {
		SObjectBaseData.location.x--;
	}
	if (key[KEY_INPUT_D] >= 1) {
		SObjectBaseData.location.x++;
	}
}

void _Player::Update(float Deltatime) {
}

