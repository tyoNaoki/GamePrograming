#include "ObjectManager.h"
#include "CharacterBase.h"
#include "_CharaGroup.h"
#include "Vector3.h"
#include "Player.h"
#include <cassert>



ObjectManager::ObjectManager(World*world,Render *renderer):world(world),render(renderer){
	Initialize();
}

ObjectManager::~ObjectManager(){
	for (auto itr = Characters.begin();itr!= Characters.end(); itr++) {
		delete itr->second;
	}
	for (auto itr = Objects.begin(); itr != Objects.end();itr++) {
		delete itr->second;
	}
}

void ObjectManager::Initialize() {
}

_CharaGroup* ObjectManager::FindGroup(CharaCategory CharaType) {
	auto itr = Characters.at(CharaType);
	return itr;
}

//ObjectBase* ObjectManager::FindChildren(ObjectCategory ObjectType, std::string ObjectName){
//	return nullptr;
//}

CharacterBase* ObjectManager::FindChildren(CharaCategory CharaType, std::string CharaName){
	return nullptr;
}


void ObjectManager::Update(float Deltatime) {
	for (auto itr = Characters.begin(); itr != Characters.end(); itr++) {
		itr->second->Update(Deltatime);
	}
	for (auto itr = Objects.begin(); itr != Objects.end(); itr++) {
	}
}

void ObjectManager::Draw(float Deltatime, Render &renderer) {
	for (auto itr = Characters.begin(); itr != Characters.end(); itr++){
		itr->second->Draw(Deltatime, renderer);
	}
	for (auto itr = Objects.begin(); itr != Objects.end(); itr++){
	}
}

void ObjectManager::AddGroup(CharaCategory CharaType) {
	Characters[CharaType] = new _CharaGroup();
}

//void ObjectManager::AddChildren(GroupCategory GroupType,) {
//	auto itr = FindGroup(name);
//	if (itr != nullptr) {
//		itr->Regist(TargetName, target);
//	}
//	else {
//		Characters[name] = new
//	}
//}

void ObjectManager::AddChildren(CharaCategory CharaType, std::string Targetname) {
	auto TargetGroup = FindGroup(CharaType);
	switch (CharaType)
	{
	case CharaCategory::Player:

		TargetGroup->Regist(Targetname, new Player(*world, world->GetStartPosition(), Targetname));
		break;
	case CharaCategory::NormalEnemy:
		break;
	case CharaCategory::TargetEnemy:
		break;
	case CharaCategory::Boss:
		break;
	case CharaCategory::None:
		break;
	default:
		break;
	}
}

void ObjectManager::AddChildren(CharaCategory CharaType, std::string TargetName, EnemyCategory EnemyType) {
	auto TargetGroup = FindGroup(CharaType);
	switch (EnemyType)
	{
	case EnemyCategory::Goblin:
		break;
	case EnemyCategory::BossGoblin:
		break;
	default:
		break;
	}
}

//void ObjectManager::AddChildren(GroupCategory GroupType, ObjectCategory ObjectType, std::string TargetType) {
//
//}

void ObjectManager::RemoveGroup(CharaCategory CharaType) {
	auto itr = Characters.find(CharaType);
	delete &itr;
	Characters.erase(CharaType);
}


