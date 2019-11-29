#pragma once

#include"Vector3.h"
#include"ObjectBase.h"

/// <summary> 概要 : 衝突情報　</summary>
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
	//接触点
	Vector3 intersect;
	//衝突した相手のポインタ
	ObjectBase* collideObject;
	//オクツリー以外では使わない。
	Vector3 normal;
};


