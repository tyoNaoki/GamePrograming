#pragma once

//当たり判定の形状
enum class ShapeType {
	BoundingSphere,
	Capsule,
	Line,

	Max_Num
};

class ShapeBase
{
public:
	ShapeBase();
	~ShapeBase();
};

