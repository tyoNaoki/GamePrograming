#pragma once
#include "Vector3.h"
#include "GameTurn.h"

enum class GameTurn;

class StageBase
{
public:
	virtual ~StageBase() {};
	virtual void StageInitialize() = 0;
	virtual void Finalize() = 0;

	virtual Vector3 GetStartPotion()=0;
	virtual Vector3 GetEnemySpawnPos() = 0;

	virtual void LoadAsset() = 0;
	virtual void Update(float Deltatime) = 0;
	virtual void Draw(float Deltatime) = 0;
	virtual void Upgrade() = 0;
	virtual void DownGrade() = 0;
	virtual void GameOver() = 0;
	virtual int GetTime() = 0;
	virtual int GetRound() = 0;
	virtual GameTurn GetTurn() { return GameTurn::None; }

	virtual int RemainRound() = 0;
	virtual void TurnInitialize(GameTurn NextTurn) = 0;
	virtual void TurnFinalize(GameTurn CurrentTurn) = 0;

	virtual void ChangeTurn(GameTurn NextTurn) = 0;
};

