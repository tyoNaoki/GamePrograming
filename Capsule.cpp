#include"Capsule.h"
#include"Color.h"
#include<DxLib.h>
#include"Collision.h"
#include"Line.h"
#include"BoundingSphere.h"
#include<cassert>
#include"Convert.h"

Capsule::Capsule(const Vector3& p1, const Vector3& p2, float radius)
	: p1(p1)
	, p2(p2)
	, vector(p2 - p1)
	, radius(radius)
{
}

Capsule::~Capsule() {
}

ShapeBase* Capsule::Translate(const Vector3 & position) const
{
	return new Capsule(p1 + position, p2 + position, radius);
}

ShapeBase* Capsule::Transform(const Matrix4 & matrix) const
{
	return new Capsule(matrix.Transform(p1), matrix.Transform(p2), radius);
}

ShapeType Capsule::GetShapeType() const
{
	return ShapeType::Capsule;
}

bool Capsule::Collide_BoundingSphere(const ShapeBase & shape, HitInfo & hitInfo)
{
	const BoundingSphere* sphere = dynamic_cast<const BoundingSphere*>(&shape);
	if (sphere == nullptr) {
		assert(!"Conversion failed.");
		return false;
	}
	return Collision::BoundingSphere_Capsule(*sphere, *this, hitInfo);
}

bool Capsule::Collide_Capsule(const ShapeBase & shape, HitInfo & hitInfo)
{
	const Capsule* capsule = dynamic_cast<const Capsule*>(&shape);
	if (capsule == nullptr) {
		assert(!"Conversion failed.");
		return false;
	}
	return Collision::Capsule_Capsule(*this, *capsule, hitInfo);
}

bool Capsule::Collide_Line(const ShapeBase & shape, HitInfo & hitInfo)
{
	const Line* line = dynamic_cast<const Line*>(&shape);
	if (line == nullptr) {
		assert(!"Conversion failed.");
		return false;
	}
	return Collision::Capsule_Line(*this, *line, hitInfo);
}

void Capsule::Draw() const
{
	DrawCapsule3D(Convert::ToVECTOR(p1), Convert::ToVECTOR(p2), radius, 8, _Color::White.ToCOLOR(), _Color::White.ToCOLOR(), FALSE);
}