#pragma once
#include "vector4.h"

struct Matrix4x4
{
	Vector4 value[4];
	Vector4& operator[](unsigned long long index);
};
