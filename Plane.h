#pragma once

#include"Vector3.h"

/// <summary> �T�v : �������ʁ@</summary>
class Plane {
public:
	Plane(float x, float y, float z, float distance);
	Plane(const Vector3& normal, float distance);
	Plane(const Vector3& p1, const Vector3& p2, Vector3& p3);
	//�@���̐��K��
	void Normalize();
private:
	//�ʂ̖@��
	Vector3 normal;
	//���_�Ƃ̋���
	float distance;
};