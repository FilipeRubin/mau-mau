#pragma once

struct Vector2
{
	float x = 0.0f, y = 0.0f;
	float& operator[](unsigned long long index);
};
