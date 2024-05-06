#include "engine/math/vector3.h"

float& Vector3::operator[](unsigned long long index)
{
	return *(reinterpret_cast<float*>(this) + index);
}
