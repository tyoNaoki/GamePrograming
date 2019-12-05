#include "ObjectGroup.h"

ObjectGroup::ObjectGroup()
{
}


ObjectGroup::~ObjectGroup(){
}


bool ObjectGroup::contain(const std::string &name) {
	return false;
}

int ObjectGroup::GetAliveNumber() {
	return Object.size();
}

void ObjectGroup::Initialize() {

}

void ObjectGroup::Finalize() {

}

void ObjectGroup::Remove(const std::string name) {
	//auto itr = Object.find(name);
}

void ObjectGroup::UpdateObject(const float Deltatime) {
	for (auto x : Object) {
		x->Update(Deltatime);
	}
}


void ObjectGroup::DrawObject(const float Deltatime, Render &renderer) {
	for (auto x : Object) {
		x->Draw(Deltatime,renderer);
	}
}

ObjectBase* ObjectGroup::Get(const std::string name)
{
	return nullptr;
}
