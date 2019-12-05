#include "ObjectManager.h"
#include "CharacterBase.h"
#include "_CharaGroup.h"
#include "Vector3.h"
#include "Player.h"



ObjectManager::ObjectManager()
{
	Initialize();
}

ObjectManager::~ObjectManager()
{
}

void ObjectManager::Initialize() {
}

_CharaGroup* ObjectManager::FindGroup(GroupCategory name) {
	auto itr = Group.find(name);
	if (itr != Group.end()) {
		return itr->second;
	}
	return nullptr;
}

ObjectBase* ObjectManager::FindChildren(ObjectCategory ObjectType, std::string ObjectName){
	return nullptr;
}

CharacterBase* ObjectManager::FindChildren(CharaCategory CharaType, std::string CharaName){
	return nullptr;
}


void ObjectManager::Update(float Deltatime) {
	for (auto itr=Group.begin();itr!=Group.end();itr++){
		itr->second->UpdateChara(Deltatime);
	}
}

void ObjectManager::Draw(float Deltatime, Render &renderer) {
	for (auto itr = Group.begin(); itr != Group.end(); itr++) {
		itr->second->DrawChara(Deltatime, renderer);
	}
}

void ObjectManager::AddGroup(GroupCategory name) {
}

void ObjectManager::AddChildren(GroupCategory GroupType,) {
	auto itr = FindGroup(name);
	if (itr != nullptr) {
		itr->Regist(TargetName, target);
	}
	else {
		Characters[name] = new
	}
}

void ObjectManager::AddChildren(GroupCategory GroupType, CharaCategory CharaType, std::string Targetname) {
	Characters[CharaType] = 
}

void ObjectManager::AddChildren(GroupCategory GroupType, ObjectCategory ObjectType, std::string TargetType) {

}

void ObjectManager::RemoveGroup(GroupCategory name) {
	auto itr = Group.find(name);
	if (itr != Group.end()) {
		delete itr->second;
		Group.erase(itr);
	}
}


