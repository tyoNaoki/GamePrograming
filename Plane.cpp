#include "Plane.h"

Plane::Plane(float x, float y, float z, float distance)
	:normal(Vector3(x, y, z))
	, distance(distance)
{
}

Plane::Plane(const Vector3 & normal, float distance)
	: normal(normal)
	, distance(distance)
{
}

Plane::Plane(const Vector3 & p1, const Vector3 & p2, Vector3 & p3)
{
	Vector3 v1 = p2 - p1;
	Vector3 v2 = p3 - p1;

	normal = v1.Cross(v2);
	distance = normal.Dot(p1);
}

void Plane::Normalize()
{
	distance = distance / normal.Length();
	normal.Normalize();
}
