#pragma once
#include <Dxlib.h>
#include <array>
#include <functional>
#include "Vector3.h"
#include "Math.h"



enum class Command {
	Dicide,
	Cancel,
	Up,
	Down,
	Left,
	Right,
	Exit,
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

	Vector3 velocity;
public:
	static Input& GetInstance();

	void Update();
	Vector3 GetVelocity();

	/*　キーボード関係のキー入力　  */
	bool IsKeyBoardUp(int key);    //キーボード UP
	bool IsKeyBoardDown(int key);  //キーボード DOWN
	bool IsKeyBoardState(int key); //キーボード STATE

	void Input::RegistKey();

	static const int Max_Key_Num = 256;

	using Keys = std::array<char, Max_Key_Num>;

	/* キーボード関係   */
	Keys curKeys;   //キーの現在の押下状況保存
	Keys preKeys;   //キーの1F前の押下状況保存

	bool GetCommand(Command command);

	using CommandFunc = std::array < std::function<bool(void)>, static_cast<int>(Command::Max_Of_Num)>;
	CommandFunc commandFunc;
};

