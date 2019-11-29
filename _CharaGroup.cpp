#include "_CharaGroup.h"

_CharaGroup::_CharaGroup()
{
}


_CharaGroup::~_CharaGroup()
{
}


void _CharaGroup::RegistObject(const std::string name, ObjectBase* object) {
	Objects[name] = object;
}

void _CharaGroup::RegistChara(const std::string name, CharacterBase * character){
	Characters[name] = character;
}

bool _CharaGroup::contain(const std::string &name) {
	auto itr = Characters.find(name);
	if (itr != Characters.end()) {
		return true;
	}
	return false;
}
 
int _CharaGroup::GetAliveNumber() {
	return Objects.size();
}

void _CharaGroup::Initialize() {

}

void _CharaGroup::Finalize() {

}

void _CharaGroup::RemoveChara(const std::string name) {
	if (contain(name)) {
		Characters.erase(name);
	}
}

void _CharaGroup::UpdateChara(const float Deltatime) {
	for (auto itr = Characters.begin(); itr != Characters.end(); itr++) {
		itr->second->BaseUpdate(Deltatime);
	}
}

void _CharaGroup::UpdateObject(const float Deltatime) {
	for (auto itr = Objects.begin(); itr != Objects.end(); itr++) {
		itr->second->Update(Deltatime);
	}
}

void _CharaGroup::DrawChara(const float &Deltatime,Render &renderer) {
	for (auto itr = Characters.begin(); itr != Characters.end(); itr++) {
		itr->second->BaseDraw(Deltatime,renderer);
	}
}

void _CharaGroup::DrawObject(const float Deltatime, Render &renderer) {
	for (auto itr = Objects.begin(); itr != Objects.end(); itr++) {
		itr->second->Draw(Deltatime, renderer);
	}
}

CharacterBase* _CharaGroup::GetChara(const std::string name) {
	auto itr = Characters.find(name);
	if (itr != Characters.end()) {
		return itr->second;
	}
	return nullptr;
}

ObjectBase* _CharaGroup::GetObject(const std::string name)
{
	auto itr = Objects.find(name);
	if (itr != Objects.end()) {
		return itr->second;
	}
	return nullptr;
}
