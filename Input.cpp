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

Input::~Input()
{
}
