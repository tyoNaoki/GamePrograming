#pragma once

//“–‚½‚è”»’è‚ÌŒ`ó
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

