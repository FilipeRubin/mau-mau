#pragma once

struct Vector3
{
	float x = 0.0f, y = 0.0f, z = 0.0f;
	float& operator[](unsigned long long index);
	float operator[](unsigned long long index) const;
};
