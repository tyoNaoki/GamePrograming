#include "FirstStage.h"
#include "GameTurn.h"
#include "CharacterBase.h"
#include "ObjectManager.h"
#include "ObjectBase.h"
#include "Player.h"
#include "World.h"

#define PLAYER_FILL "Data\\Character\\Player\\"


FirstStage::FirstStage(World*world,Render *renderer,ObjectManager *Manager)
	:world(world),render(renderer),objectManager(Manager), DefenceTime(DefaultDefenceTime),BreakTime(DefaultBreakTime),IsEndTurn(false)
{
}


FirstStage::~FirstStage()
{
}

void FirstStage::StageInitialize(){
	ChangeTurn(GameTurn::DefenceTurn);
}

void FirstStage::Finalize()
{

}

Vector3 FirstStage::GetStartPotion()
{
	return StartPos;
}

Vector3 FirstStage::GetEnemySpawnPos()
{
	return StartPos;
}

void FirstStage::LoadAsset(){
	render->Load3DModel("Player", PLAYER_FILL"PC.mv1");
	render->LoadAnimation("Player", PLAYER_FILL"Anim_Neutral.mv1");
}

void FirstStage::TurnFinalize(GameTurn CurrentTurn) {
	switch (CurrentTurn)
	{
	case GameTurn::None:
		break;
	case GameTurn::Initialize:
		break;
	case GameTurn::DefenceTurn:
		break;
	case GameTurn::BreakTurn:
		break;
	case GameTurn::Clear:
		break;
	case GameTurn::GameOver:
		break;
	default:
		break;
	}
}

void FirstStage::TurnInitialize(GameTurn NextTurn) {
	switch (NextTurn)
	{
	case GameTurn::None:
		break;
	case GameTurn::Initialize:
		break;
	case GameTurn::DefenceTurn:
		break;
	case GameTurn::BreakTurn:
		
		break;
	case GameTurn::Clear:
		break;
	case GameTurn::GameOver:
		break;
	default:
		break;
	}
}

void FirstStage::ChangeTurn(GameTurn NextTurn) {
	TurnFinalize(Turn);
	TurnInitialize(NextTurn);
	Turn = NextTurn;
}

void FirstStage::Fade(float Deltatime) {
	if (alpha <= 1.0){
		alpha += Deltatime;
	}else
	{
	}
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
		//if (!GetTime() <= 0) {
			objectManager->Update(Deltatime);
		//}
		//else{
		//}
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

void FirstStage::CreateStage() {

}
