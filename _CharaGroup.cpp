#include "_CharaGroup.h"
#include <cassert>

_CharaGroup::_CharaGroup() {
}

_CharaGroup::~_CharaGroup(){
	for (auto x : Character){
		delete x;
	}
}

void _CharaGroup::Regist(const std::string name, CharacterBase * character){

	Character.push_back(character);
}

bool _CharaGroup::contain(const std::string &name) {
	for (auto x : Character){
		if (x->GetName() == name) {
			return true;
		}
	}
	return false;
}

int _CharaGroup::GetAliveNumber() {
	return Character.size();
}

void _CharaGroup::Initialize(Render &renderer) {
	for (auto x : Character) {
		x->Initialize(renderer);
	}
}

void _CharaGroup::Finalize() {
}

bool _CharaGroup::Remove(const std::string name) {
	if (contain(name) != true) {
		return false;
	}
	return true;
}

void _CharaGroup::Update(const float Deltatime) {
	for (auto&& x : Character) {
		x->BaseUpdate(Deltatime);
	}
}

void _CharaGroup::Draw(const float &Deltatime,Render &renderer) {
	for (auto&& x : Character) {
		x->BaseDraw(Deltatime,renderer);
	}
}

CharacterBase* _CharaGroup::Get(const std::string name) {
	for (auto&& x : Character) {
		if (x->GetName() == name) {
			return x;
		}
	}
	return nullptr;
}
