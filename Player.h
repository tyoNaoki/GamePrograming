#pragma once


typedef struct {
public:
	int X = 0;
	int Y = 0;
}PlayerLocation;

class Player
{
public:
	Player();
	virtual ~Player();

//Player����/////

	int UpdateKey();

	virtual void PlayerMovement();


//Debug�֐�
	void Test();
private:

public:
	PlayerLocation playerLocation;
	int Key[256];
};

