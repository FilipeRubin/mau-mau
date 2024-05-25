#pragma once
#include "vector4.h"

struct Matrix4x4
{
	static Matrix4x4 Identity();
	static Matrix4x4 Perspective(float hFOV, float aspectRatio, float zNear, float zFar);
	Vector4 value[4];
	Vector4& operator[](unsigned long long index);
	const Vector4& operator[](unsigned long long index) const;
	Vector4 operator+(const Vector4& other) const;
	Matrix4x4 operator*(const Matrix4x4& other) const;
};
