#pragma once

#include"Vector3.h"
#include"ObjectBase.h"

/// <summary> �T�v : �Փˏ��@</summary>
class HitInfo {
public:
	HitInfo()
		: intersect(0, 0, 0)
		, collideObject(nullptr)
		, normal(0, 0, 0)
	{
	}
	~HitInfo() {
	}
public:
	//�ڐG�_
	Vector3 intersect;
	//�Փ˂�������̃|�C���^
	ObjectBase* collideObject;
	//�I�N�c���[�ȊO�ł͎g��Ȃ��B
	Vector3 normal;
};


