#include "engine/math/vector4.h"

float& Vector4::operator[](unsigned long long index)
{
    return *(reinterpret_cast<float*>(this) + index);
}

float Vector4::operator[](unsigned long long index) const
{
    return *(reinterpret_cast<const float*>(this) + index);
}
