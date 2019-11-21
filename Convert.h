#pragma once

class Vector3;
class Vector2;
class Matrix4;
#include<DxLib.h>

/// <summary> �T�v : �ϊ��N���X�@</summary>
class Convert {
public:
	/// <summary> �T�v : DirectX��VECTOR�ɕϊ��@</summary>
	static VECTOR ToVECTOR(const Vector2& vector);
	/// <summary> �T�v : DirectX��VECTOR�ɕϊ��@</summary>
	static VECTOR ToVECTOR(const Vector3& vector);
	/// <summary> �T�v : DirectX��MATRIX�ɕϊ��@</summary>
	static MATRIX ToMATRIX(const Matrix4& matrix);
	/// <summary> �T�v : Vector2�ɕϊ��@</summary>
	static Vector2 ToVector2(const VECTOR& vector);
	/// <summary> �T�v : Vector3�ɕϊ��@</summary>
	static Vector3 ToVector3(const VECTOR& vector);
	/// <summary> �T�v : Matrix4�ɕϊ��@</summary>
	static Matrix4 ToMatrix4(const MATRIX& matrix);
};