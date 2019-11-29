#pragma once

#include"Vector3.h"

/// <summary> 概要 : 無限平面　</summary>
class Plane {
public:
	Plane(float x, float y, float z, float distance);
	Plane(const Vector3& normal, float distance);
	Plane(const Vector3& p1, const Vector3& p2, Vector3& p3);
	//法線の正規化
	void Normalize();
private:
	//面の法線
	Vector3 normal;
	//原点との距離
	float distance;
};