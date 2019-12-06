#include "Input.h"



Input::Input()
{
	RegistKey();
}

Input &Input::GetInstance() {
	static Input instance;
	return instance;
}

bool Input::GetCommand(Command command) {
	return commandFunc[static_cast<int>(command)]();
}

void Input::RegistKey() {

	commandFunc[0] = [&](void)->bool {return IsKeyBoardDown(KEY_INPUT_SPACE); };//Dicide
	commandFunc[1] = [&](void)->bool {return IsKeyBoardDown(KEY_INPUT_BACK); };//Cancel
	commandFunc[2] = [&](void)->bool {return IsKeyBoardDown(KEY_INPUT_UP); };//UP
	commandFunc[3] = [&](void)->bool {return IsKeyBoardDown(KEY_INPUT_DOWN); };//Down
	commandFunc[4] = [&](void)->bool {return IsKeyBoardDown(KEY_INPUT_LEFT); };//Left
	commandFunc[5] = [&](void)->bool {return IsKeyBoardDown(KEY_INPUT_RIGHT); };//Right
	commandFunc[6] = [&](void)->bool {return IsKeyBoardDown(KEY_INPUT_ESCAPE); };//Exit
	/*
	commandFunc[7] = [&](void)->bool {return IsKeyBoardDown(KEY_INPUT_SPACE); };
	commandFunc[8] = [&](void)->bool {return IsKeyBoardDown(KEY_INPUT_SPACE); };
	commandFunc[9] = [&](void)->bool {return IsKeyBoardDown(KEY_INPUT_SPACE); };
	commandFunc[10] = [&](void)->bool {return IsKeyBoardDown(KEY_INPUT_SPACE); };*/
}

void Input::InitializeKey() {
	/*　キーボード配列の初期化　　*/
	for (int index = 0; index < Max_Key_Num; ++index) {
		curKeys[index] = 0;
		preKeys[index] = 0;
	}
}

void Input::Update() {
	//軽くなるかも？
	ClearInputCharBuf();

	//キーボード入力更新
	preKeys.swap(curKeys);
	GetHitKeyStateAll(curKeys.data());

}

/*　キーボード関係　*/
bool Input::IsKeyBoardUp(int key) {
	bool keyState = false;
	if (!curKeys[key] && preKeys[key])
		keyState = true;

	return keyState;
}

bool Input::IsKeyBoardDown(int key) {
	bool keyState = false;
	if (curKeys[key] && !preKeys[key])
		keyState = true;

	return keyState;
}

bool Input::IsKeyBoardState(int key) {
	bool keyState = false;
	if (curKeys[key])
		keyState = true;

	return keyState;
}

Vector3 Input::GetWASDVelocity() {
	//プレイヤーの移動量
	Vector3 velocity = Vector3::Vector3(0.0f, 0.0f, 0.0f);

	if (IsKeyBoardState(KEY_INPUT_W))
		velocity.z = 1.0f;
	if (IsKeyBoardState(KEY_INPUT_A))
		velocity.x = -1.0f;
	if (IsKeyBoardState(KEY_INPUT_S))
		velocity.z = -1.0f;
	if (IsKeyBoardState(KEY_INPUT_D))
		velocity.x = 1.0f;

	//斜めの正規化
	if (velocity.Length() != 0.0f)
		velocity.Normalize();

	return velocity;
}

Vector3 Input::GetULDRVelocity() {
	//プレイヤーの移動量
	Vector3 velocity = Vector3::Vector3(0.0f, 0.0f, 0.0f);

	if (IsKeyBoardState(KEY_INPUT_UP))
		velocity.z = 1.0f;
	if (IsKeyBoardState(KEY_INPUT_LEFT))
		velocity.x = -1.0f;
	if (IsKeyBoardState(KEY_INPUT_DOWN))
		velocity.z = -1.0f;
	if (IsKeyBoardState(KEY_INPUT_RIGHT))
		velocity.x = 1.0f;

	//斜めの正規化
	if (velocity.Length() != 0.0f)
		velocity.Normalize();

	return velocity;
}

Vector3 Input::GetVelocity() {
	return velocity;
}

Input::~Input()
{
}
