#include "engine/math/vector2.h"

float& Vector2::operator[](unsigned long long index)
{
    return *(reinterpret_cast<float*>(this) + index);
}

float Vector2::operator[](unsigned long long index) const
{
    return *(reinterpret_cast<const float*>(this) + index);
}
