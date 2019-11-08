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
	char tmpKey[256]; // 現在のキーの入力状態を格納する
	GetHitKeyStateAll(tmpKey); // 全てのキーの入力状態を得る
	for (int i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) { // i番のキーコードに対応するキーが押されていたら
			Key[i]++;     // 加算
		}
		else {              // 押されていなければ
			Key[i] = 0;   // 0にする
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
