#pragma once
/************************************************************
* File Name	: Vector2.h
* Description	: 二次元ベクトルクラス
*																Date		:	2015-10-22.
*															  Author	:	阿曽
*************************************************************/
#pragma once

class Vector2 {
public:
	Vector2();
	Vector2(float x, float y);
	Vector2(const Vector2& vector);
	~Vector2();

	/// <summary> 概要 : ベクトルの長さを取得　</summary>
	/// <returns>ベクトルの長さ</returns>
	float Length() const;

	/// <summary> 概要 : ベクトルの2乗の長さを取得　</summary>
	/// <returns>ベクトルの2乗の長さ</returns>
	float SquareLength() const;

	/// <summary> 概要 : ベクトルを正規化(長さ１に)する　</summary>
	void Normalize();

	/// <summary> 概要 : 正規化(長さ１に)したベクトルを取得　</summary>
	/// <returns>正規化されたベクトル</returns>
	Vector2 GetNormal() const;

	/// <summary> 概要 : XとYの要素をコンソール画面に表示　</summary>
	void Print() const;

public:
	/// <summary> 概要 : 内積　</summary>
	float Dot(const Vector2& vector);

	/// <summary> 概要 : 外積　</summary>
	float Cross(const Vector2& vector);

	/// <summary> 概要 : ２点間の距離を求める　</summary>
	float Distance(const Vector2& vector);

	/// <summary> 概要 : ベクトルを範囲内に収める　</summary>
	void Clamp(const Vector2& min, const Vector2& max);

	/// <summary> 概要 : 2つのベクトルの角度を求める　</summary>
	float Angle(const Vector2& vector);

	/// <summary> 概要 : 2つのベクトルの線形補間　</summary>
	Vector2 Lerp(const Vector2& vector, float lerpTime);

	/// <summary> 概要 : 原点を中心に回転するベクトルを求める　</summary>
	Vector2 Rotate(float angle);

public:
	//X要素
	float x;
	//Y要素
	float y;

	/// <summary> 概要 : オーバーライド定義 </summary>
public:
	Vector2 operator + ();
	Vector2 operator - ();
	Vector2 operator + (const Vector2& vector) const;
	Vector2 operator - (const Vector2& vector) const;
	Vector2 operator * (float scalar) const;
	Vector2 operator / (float scalar) const;
	Vector2& operator += (const Vector2& vector);
	Vector2& operator -= (const Vector2& vector);
	Vector2& operator *= (float scalar);
	Vector2& operator /= (float scalar);

public:
	static const Vector2 Up;			// Vector2( 0,  1)
	static const Vector2 Down;			// Vector2( 0, -1)
	static const Vector2 Left;			// Vector2(-1,  0)
	static const Vector2 Right;			// Vector2( 1,  0)
	static const Vector2 UnitX;			// Vector2( 1,  0)
	static const Vector2 UnitY;			// Vector2( 0,  1)
	static const Vector2 One;			// Vector2( 1,  1)
	static const Vector2 Zero;			// Vector2( 0,  0)
};


