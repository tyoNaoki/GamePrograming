#include "Player.h"
#include "DxLib.h"

//tset
Player::Player(){

}

Player::~Player(){
}

//Debug
void Player::Test() {

}

int Player::UpdateKey() {
	char tmpKey[256]; // ���݂̃L�[�̓��͏�Ԃ��i�[����
	GetHitKeyStateAll(tmpKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�
	for (int i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) { // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
			Key[i]++;     // ���Z
		}
		else {              // ������Ă��Ȃ����
			Key[i] = 0;   // 0�ɂ���
		}
	}
	return 0;
}

void Player::PlayerMovement() {
	if (Key[KEY_INPUT_W] >= 1) {
		playerLocation.Y--;
	}
	if (Key[KEY_INPUT_S] >= 1) {
		playerLocation.Y++;
	}
	if (Key[KEY_INPUT_A] >= 1) {
		playerLocation.X--;
	}
	if (Key[KEY_INPUT_D] >= 1) {
		playerLocation.X++;
	}
}
