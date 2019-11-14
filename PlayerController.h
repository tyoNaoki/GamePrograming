#pragma once
#include "BaseCharaController.h"

#define AllKeyNumber 256

class PlayerController :
	public BaseCharaController
{
private:
	int i;
public:
	char *key[AllKeyNumber];
	void Update(float Deltatime)override;
	void UpdateKey();
	PlayerController();
	~PlayerController();
};
