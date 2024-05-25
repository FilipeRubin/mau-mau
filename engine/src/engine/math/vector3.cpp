#include "engine/math/vector3.h"

float& Vector3::operator[](unsigned long long index)
{
	return *(reinterpret_cast<float*>(this) + index);
}

float Vector3::operator[](unsigned long long index) const
{
	return *(reinterpret_cast<const float*>(this) + index);
}
