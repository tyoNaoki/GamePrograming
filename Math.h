#pragma once
#include<cmath>

class Math {
public:
	/// <summary> 概要 : 二乗根（ルート）を求める　</summary>
	/// <param name="value">値</param>
	static float SquareRoot(float value);

	/// <summary> 概要 : 小さい値を求める　</summary>
	/// <param name="value1">値</param>
	/// <param name="value2">値</param>
	/// <returns>最小の値</returns>
	template<typename T>
	static T Min(T value1, T value2) {
		return (T)std::fminf(value1, value2);
	}

	/// <summary> 概要 : 大きい値を求める　</summary>
	/// <param name="value1">値</param>
	/// <param name="value2">値</param>
	/// <returns>最大の値</returns>
	template<typename T>
	static T Max(T value1, T value2) {
		return (T)std::fmaxf(value1, value2);
	}

	/// <summary> 概要 : 値を範囲内に収める　</summary>
	/// <param name="value">値</param>
	/// <param name="min">最小値</param>
	/// <param name="max">最大値</param>
	/// <returns>範囲内の値</returns>
	template<typename T>
	static T Clamp(T value, T min, T max) {
		return (T)std::fmaxf(min, std::fminf(value, max));
	}

	/// <summary> 概要 : サイン　</summary>
	/// <param name="angle">角度(度)</param>
	/// <returns>サイン値(-1.0f～1.0f)</returns>
	static float Sin(float angle);

	/// <summary> 概要 : コサイン　</summary>
	/// <param name="angle">角度(度)</param>
	/// <returns>コサイン値(-1.0f～1.0f)</returns>
	static float Cos(float angle);

	/// <summary> 概要 : タンジェント　</summary>
	/// <param name="angle">角度(度)</param>
	/// <returns>タンジェント値(-1.0f～1.0f)</returns>
	static float Tan(float angle);

	/// <summary> 概要 : アークサイン　</summary>
	/// <param name="sin">サイン値(-1.0f～1.0f)</param>
	/// <returns>角度(度)</returns>
	static float ArcSin(float sin);

	/// <summary> 概要 : アークコサイン　</summary>
	/// <param name="cos">コサイン値(-1.0f～1.0f)</param>
	/// <returns>角度(度)</returns>
	static float ArcCos(float cos);

	/// <summary> 概要 : アークタンジェント　</summary>
	/// <param name="tan">タンジェント値(-1.0f～1.0f)</param>
	/// <returns>角度(度)</returns>
	static float ArcTan(float y, float x);

	template<typename T = float>
	static T Abs(T value) {
		return (T)abs(value);
	}

	template<typename T = float>
	static T Lerp(T value1, T value2, float amount) {
		return (value1 * (1.0f - amount)) + (value2 * amount);
	}

	template<typename T = float>
	static int Sign(T value) {
		return static_cast<int>((value / Math::Abs<float>(value)));
	}

public:
	/// <summary> 概要 : 円周率(π)　</summary>
	static constexpr float PI = 3.141592f;
	/// <summary> 概要 : 度数法に変換　</summary>
	static constexpr float toDegree = 180.0f / PI;
	/// <summary> 概要 : ラジアン角に変換　</summary>
	static constexpr float toRadian = PI / 180.0f;
};


