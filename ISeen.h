#pragma once
#include <DxLib.h>
#include "System.h"

class ISeen
{
public:
	//操作に対する挙動が成功したか
	virtual bool Input() { return false; };

	virtual void Update(float Deltatime) {};
	virtual void Draw(float Deltatime) {};
	virtual bool NotERRORMyID() { return ID != -1; }
	virtual bool NotERRORNextID() { return NextID != -1; }
//シーン偏移のためのシーン識別ID
	//次のID
	int NextID = -1;
	//自身の識別ID
	int ID = -1;
	//偏移前のID
	int BackID = -1;
	 ISeen() {};
	 ~ISeen() {};
};

