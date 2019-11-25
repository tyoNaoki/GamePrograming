#include "_CharaGroup.h"


_CharaGroup::_CharaGroup()
{
}


_CharaGroup::~_CharaGroup()
{
}

void _CharaGroup::RegistChara(const std::string &name,CharacterBase *chara) {
	Chara[name] = chara;
}

bool _CharaGroup::contain(const std::string &name) {
	auto itr = Chara.find(name);
	if (itr != Chara.end()) {
		return true;
	}
	return false;
}
 
int _CharaGroup::GetAliveNumber() {
	return Chara.size();
}

void _CharaGroup::Initialize() {

}

void _CharaGroup::Finalize() {

}

void _CharaGroup::RemoveChara(const std::string &name) {
	if (contain(name)) {
		Chara.erase(name);
	}
}

void _CharaGroup::UpdateChara(const float &Deltatime) {
	for (auto itr = Chara.begin(); itr != Chara.end(); itr++) {
		itr->second->Update(Deltatime);
	}
}

CharacterBase* _CharaGroup::FindChara(const std::string &name) {
	auto itr = Chara.find(name);
	if (itr != Chara.end()) {
		return itr->second;
	}
	return nullptr;
}