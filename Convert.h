#pragma once

class Vector3;
class Vector2;
class Matrix4;
#include<DxLib.h>

/// <summary> 概要 : 変換クラス　</summary>
class Convert {
public:
	/// <summary> 概要 : DirectXのVECTORに変換　</summary>
	static VECTOR ToVECTOR(const Vector2& vector);
	/// <summary> 概要 : DirectXのVECTORに変換　</summary>
	static VECTOR ToVECTOR(const Vector3& vector);
	/// <summary> 概要 : DirectXのMATRIXに変換　</summary>
	static MATRIX ToMATRIX(const Matrix4& matrix);
	/// <summary> 概要 : Vector2に変換　</summary>
	static Vector2 ToVector2(const VECTOR& vector);
	/// <summary> 概要 : Vector3に変換　</summary>
	static Vector3 ToVector3(const VECTOR& vector);
	/// <summary> 概要 : Matrix4に変換　</summary>
	static Matrix4 ToMatrix4(const MATRIX& matrix);
};