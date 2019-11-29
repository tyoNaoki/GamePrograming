#include "FirstStage.h"
#include "GameTurn.h"
#include "CharacterBase.h"
#include "ObjectManager.h"
#include "ObjectBase.h"
#include "World.h"


FirstStage::FirstStage()//:DefenceTime(DefaultDefenceTime),BreakTime(DefaultBreakTime)
{
}


FirstStage::~FirstStage()
{
}

void FirstStage::StageInitialize(){
	LoadAsset();
}

void FirstStage::Finalize()
{

}

Vector3 FirstStage::GetStartPotion()
{
	return Vector3();
}

Vector3 FirstStage::GetEnemySpawnPos()
{
	return Vector3();
}

void FirstStage::LoadAsset(){
	
}

void FirstStage::TurnFinalize(GameTurn CurrentTurn) {

}

void FirstStage::TurnInitialize(GameTurn NextTurn) {

}

void FirstStage::ChangeTurn(GameTurn NextTurn) {
	TurnFinalize(Turn);
	TurnInitialize(NextTurn);
	Turn = NextTurn;
}

void FirstStage::Update(float Deltatime)
{
	switch (Turn)
	{
	case GameTurn::None:

		break;

	case GameTurn::BreakTurn:
		
		break;

	case  GameTurn::DefenceTurn:
		objectManager->Update(Deltatime);
		break;

	case GameTurn::GameOver:
		break;

	case GameTurn::Clear:
		break;
	}
}

void FirstStage::Draw(float Deltatime)
{
	switch (Turn)
	{
	case GameTurn::None:

		break;

	case GameTurn::BreakTurn:

		break;

	case  GameTurn::DefenceTurn:
		break;

	case GameTurn::GameOver:
		break;

	case  GameTurn::Clear:
		break;
	}
}

void FirstStage::Upgrade(){
}

void FirstStage::DownGrade(){

}

void FirstStage::GameOver()
{

}

GameTurn FirstStage::GetTurn() {
	return Turn;
}

int FirstStage::GetTime()
{
	return ((Turn == GameTurn::DefenceTurn) ? DefenceTime : BreakTime);
}

int FirstStage::GetRound()
{
	return NowRound;
}

int FirstStage::RemainRound() {
	return MaxRound - NowRound;
}
