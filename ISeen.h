#pragma once
#include <DxLib.h>
#include "System.h"

class ISeen
{
public:
	//����ɑ΂��鋓��������������
	virtual bool Input() { return false; };

	virtual void Update(float Deltatime) {};
	virtual void Draw(float Deltatime) {};
	virtual bool NotERRORMyID() { return ID != -1; }
	virtual bool NotERRORNextID() { return NextID != -1; }
//�V�[���Έڂ̂��߂̃V�[������ID
	//����ID
	int NextID = -1;
	//���g�̎���ID
	int ID = -1;
	//�ΈڑO��ID
	int BackID = -1;
	 ISeen() {};
	 ~ISeen() {};
};

