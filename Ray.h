#pragma once

#include"Vector3.h"

/// <summary> �T�v : ���C�i���������j�@</summary>
class Ray {
public:
	Ray(const Vector3& position, const Vector3& direction);
	~Ray();

public:
	//���C���΂��ʒu
	Vector3 position;
	//���C���΂�����
	Vector3 direction;
};

