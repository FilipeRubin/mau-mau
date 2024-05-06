#include "engine/math/matrix4x4.h"

Vector4& Matrix4x4::operator[](unsigned long long index)
{
    return value[index];
}
