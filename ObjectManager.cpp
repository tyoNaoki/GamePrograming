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

ObjectBase* ObjectManager::FindObject(GroupCategory name, std::string ObjectName)
{
	return FindGroup(name)->GetObject(ObjectName);
}

CharacterBase* ObjectManager::FindChara(GroupCategory name, std::string CharaName)
{
	return FindGroup(name)->GetChara(CharaName);
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
	_CharaGroup *tempGroup = new _CharaGroup();
	Group[name] = tempGroup;
}

void ObjectManager::AddChildren(GroupCategory name, std::string TargetName, CharacterBase* target) {
	auto itr = FindGroup(name);
	if (itr != nullptr) {
		if (name != GroupCategory::None) {
			itr->Regist(TargetName, target);
		}
	}
}

void ObjectManager::AddChildren(GroupCategory GroupType, CharaCategory CharaType, std::string Targetname) {
	auto itr = FindGroup(GroupType);
	if (itr != nullptr) {
		if (GroupType != GroupCategory::None) {
			itr->Regist(Targetname)
		}
	}
}

void ObjectManager::RemoveGroup(GroupCategory name) {
	auto itr = Group.find(name);
	if (itr != Group.end()) {
		delete itr->second;
		Group.erase(itr);
	}
}


