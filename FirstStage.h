#pragma once
#include "Vector3.h"
#include <vector>
#include <unordered_map>
#include "ObjectManager.h"

#include "StageBase.h"

#define MAX_BARRICADE 5
#define  MAX_ENEMY_SPAWNPOSITION 5

class FirstStage :
	public StageBase
{
public:
	FirstStage();
	~FirstStage();
	virtual void StageInitialize()override;
	virtual void Finalize()override;

	virtual Vector3 GetStartPotion()override;
	virtual Vector3 GetEnemySpawnPos()override;

	virtual void LoadAsset()override;
	virtual void Update(float Deltatime)override;
	virtual void Draw(float Deltatime)override;
	virtual void Upgrade()override;
	virtual void DownGrade()override;
	virtual void GameOver()override;
	virtual int GetTime()override;
	virtual int GetRound()override;
	virtual int RemainRound()override;

	GameTurn GetTurn()override;

	virtual void TurnInitialize(GameTurn NextTurn)override;
	virtual void TurnFinalize(GameTurn CurrentTurn)override;
	virtual void ChangeTurn(GameTurn NextTurn)override;

private:
	Vector3 StartPos;
	std::vector<Vector3>EnemySpawnPositions[MAX_ENEMY_SPAWNPOSITION];
	std::vector<Vector3>BarricadePositions[MAX_BARRICADE];

	std::unordered_map<int, ObjectBase*>Objects;

	ObjectManager *objectManager;

	GameTurn Turn;
	int NowRound = 0;
	int MaxRound = 3;
	int DefenceTime;
	int BreakTime;

	static const int DefaultDefenceTime = 30;
	static const int DefaultBreakTime = 30;
};

