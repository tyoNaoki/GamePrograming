#pragma once
#include <Dxlib.h>
#include <array>
#include <functional>
#include "Math.h"



enum class Command {
	Dicide,
	Cancel,
	Up,
	Down,
	Left,
	Right,
	ShutDown,
	Pause,
	Dash,
	Jump,
	Max_Of_Num
};

class Input
{
private:
	Input();
	~Input();

public:
	static Input& GetInstance();

	void Update();

	/*�@�L�[�{�[�h�֌W�̃L�[���́@  */
	bool IsKeyBoardUp(int key);    //�L�[�{�[�h UP
	bool IsKeyBoardDown(int key);  //�L�[�{�[�h DOWN
	bool IsKeyBoardState(int key); //�L�[�{�[�h STATE

	static const int Max_Key_Num = 256;

	using Keys = std::array<char, Max_Key_Num>;

	/* �L�[�{�[�h�֌W   */
	Keys curKeys;   //�L�[�̌��݂̉����󋵕ۑ�
	Keys preKeys;   //�L�[��1F�O�̉����󋵕ۑ�

	bool GetCommand(Command command);

	using CommandFunc = std::array < std::function<bool(void)>, static_cast<int>(Command::Max_Of_Num)>;
	CommandFunc commandFunc;
};

