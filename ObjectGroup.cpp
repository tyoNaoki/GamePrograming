#include "ObjectGroup.h"

ObjectGroup::ObjectGroup()
{
}


ObjectGroup::~ObjectGroup()
{
}


void ObjectGroup::Regist(const std::string name, ObjectBase* object) {
	Objects[name] = object;
}


bool ObjectGroup::contain(const std::string &name) {
	auto itr = Characters.find(name);
	if (itr != Characters.end()) {
		return true;
	}
	return false;
}

int ObjectGroup::GetAliveNumber() {
	return Objects.size();
}

void ObjectGroup::Initialize() {

}

void ObjectGroup::Finalize() {

}

void ObjectGroup::Remove(const std::string name) {
	auto itr = Group.find(name);
}

void ObjectGroup::UpdateObject(const float Deltatime) {
	for (auto itr = Objects.begin(); itr != Objects.end(); itr++) {
		itr->second->Update(Deltatime);
	}
}


void ObjectGroup::DrawObject(const float Deltatime, Render &renderer) {
	for (auto itr = Objects.begin(); itr != Objects.end(); itr++) {
		itr->second->Draw(Deltatime, renderer);
	}
}

ObjectBase* ObjectGroup::Get(const std::string name)
{
	auto itr = Objects.find(name);
	if (itr != Objects.end()) {
		return itr->second;
	}
	return nullptr;
}
