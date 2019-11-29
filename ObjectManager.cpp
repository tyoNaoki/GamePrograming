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
	auto itr = Charas.find(name);
	if (itr != Charas.end()) {
		return itr->second;
	}
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
	for (auto itr=Charas.begin();itr!=Charas.end();itr++){
		itr->second->UpdateChara(Deltatime);
	}
}

void ObjectManager::Draw(float Deltatime, Render &renderer) {
	for (auto itr = Charas.begin(); itr != Charas.end(); itr++) {
		itr->second->DrawChara(Deltatime, renderer);
	}
}

void ObjectManager::AddGroup(GroupCategory name,_CharaGroup *Group) {
	Charas[name] = Group;
}

template<typename T>
void ObjectManager::Add(GroupCategory name,std::string TargetName,T* Target) {
	auto itr = FindGroup(name);
	if (name == GroupCategory::EnemyGroup || name == GroupCategory::PlayerGroup) {
		itr->second->RegistObject(TargetName, T* Target);
	}else if(name != GroupCategory::None){
		itr->second->RegistChara(TargetName, T* Target);
	}
}

void ObjectManager::RegisterGroup(GroupCategory Gname) {
	AddGroup(Gname, new _CharaGroup());
}

void ObjectManager::RemoveGroup(GroupCategory name) {
	auto itr = Charas.find(name);
	if (itr != Charas.end()) {
		delete itr->second;
		Charas.erase(itr);
	}
}


