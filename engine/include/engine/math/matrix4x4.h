#pragma once
#include "vector3.h"
#include "vector4.h"

struct Matrix4x4
{
	static Matrix4x4 Identity();
	static Matrix4x4 Perspective(float hFOV, float aspectRatio, float zNear, float zFar);
	static Matrix4x4 Rotation(const Vector3& rotationAngles);
	static Matrix4x4 RotationX(float angle);
	static Matrix4x4 RotationY(float angle);
	static Matrix4x4 RotationZ(float angle);
	static Matrix4x4 Scale(const Vector3& scale);
	static Matrix4x4 Translation(const Vector3& translation);
	Vector4 value[4];
	Matrix4x4();
	Matrix4x4(const Vector4& row1, const Vector4& row2, const Vector4& row3, const Vector4& row4);
	Vector4& operator[](unsigned long long index);
	const Vector4& operator[](unsigned long long index) const;
	Vector4 operator*(const Vector4& other) const;
	Matrix4x4 operator*(const Matrix4x4& other) const;
};
