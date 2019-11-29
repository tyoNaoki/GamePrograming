#include"BoundingSphere.h"

#include"HitInfo.h"
#include"Collision.h"
#include"Matrix4.h"
#include<DxLib.h>
#include<cassert>
#include"Capsule.h"
#include"Line.h"
#include"Convert.h"

BoundingSphere::BoundingSphere(const Vector3& center, float radius)
	:ShapeBase()
	, center(center)
	, radius(radius) {
}

BoundingSphere::BoundingSphere(float radius) :
	BoundingSphere(Vector3(0.0f, 0.0f, 0.0f), radius) {
}

ShapeBase* BoundingSphere::Translate(const Vector3& position) const {
	return new BoundingSphere(center + position, radius);
}

ShapeBase* BoundingSphere::Transform(const Matrix4& matrix) const {
	return new BoundingSphere(matrix.Transform(center), radius * matrix.GetScale().y);
}

ShapeType BoundingSphere::GetShapeType() const
{
	return ShapeType::BoundingSphere;
}

bool BoundingSphere::Collide_BoundingSphere(const ShapeBase & shape, HitInfo & hitInfo)
{
	const BoundingSphere* sphere = dynamic_cast<const BoundingSphere*>(&shape);
	if (sphere == nullptr) {
		assert(!"Conversion failed.");
		return false;
	}
	return Collision::BoundingShpere_BoundingSphere(*this, *sphere, hitInfo);;
}

bool BoundingSphere::Collide_Capsule(const ShapeBase & shape, HitInfo & hitInfo)
{
	const Capsule* capsule = dynamic_cast<const Capsule*>(&shape);
	if (capsule == nullptr) {
		assert(!"Conversion failed.");
		return false;
	}
	return Collision::BoundingSphere_Capsule(*this, *capsule, hitInfo);;
}

bool BoundingSphere::Collide_Line(const ShapeBase & shape, HitInfo & hitInfo)
{
	const Line* line = dynamic_cast<const Line*>(&shape);
	if (line == nullptr) {
		assert(!"Conversion failed.");
		return false;
	}
	return Collision::BoundingSphere_Line(*this, *line, hitInfo);;
}

void BoundingSphere::Draw() const
{
	DrawSphere3D(Convert::ToVECTOR(center), radius, 32, GetColor(255, 255, 255), GetColor(255, 255, 255), FALSE);
}