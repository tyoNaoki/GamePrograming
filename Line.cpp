#include"Line.h"
#include"Color.h"
#include"BoundingSphere.h"
#include"HitInfo.h"
#include"Convert.h"

Line::Line(const Vector3& p1, const Vector3& p2)
	:p1(p1)
	, p2(p2)
	, vector(p2 - p1)
{
}

Line::~Line() {
}

Line Line::Translate(const Vector3 & position)
{
	return Line(p1 + position, p2 + position);
}

Line Line::Transform(const Matrix4 & matrix)
{
	return Line(matrix.Transform(p1), matrix.Transform(p2));
}

bool Line::Intersects(const BoundingSphere & other, HitInfo & hitInfo)
{
	return false;
}

void Line::Draw(const _Color& color)
{
	DrawLine3D(Convert::ToVECTOR(p1), Convert::ToVECTOR(p2), color.ToCOLOR());
}