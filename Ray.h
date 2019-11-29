#pragma once

#include"Vector3.h"

/// <summary> 概要 : レイ（無限線分）　</summary>
class Ray {
public:
	Ray(const Vector3& position, const Vector3& direction);
	~Ray();

public:
	//レイを飛ばす位置
	Vector3 position;
	//レイを飛ばす方向
	Vector3 direction;
};

