#include "Input.h"



Input::Input()
{
}

Input &Input::GetInstance() {
	static Input instance;
	return instance;
}

bool Input::GetCommand(Command command) {
	return commandFunc[static_cast<int>(command)]();
}

void Input::Update() {
	//�y���Ȃ邩���H
	ClearInputCharBuf();

	//�L�[�{�[�h���͍X�V
	preKeys.swap(curKeys);
	GetHitKeyStateAll(curKeys.data());

}

/*�@�L�[�{�[�h�֌W�@*/
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
