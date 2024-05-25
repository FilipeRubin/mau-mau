#include "engine/math/matrix4x4.h"
#include <cmath>

Matrix4x4 Matrix4x4::Perspective(float hFOV, float aspectRatio, float zNear, float zFar)
{
    const float v11 = aspectRatio * (1.0f / tanf(hFOV / 2.0f));
    const float v22 = (1.0f / tanf(hFOV / 2.0f));
    const float v33 = zFar / (zFar - zNear);
    const float v34 = (-zFar * zNear) / (zFar - zNear);
    const float v43 = 1.0f;

    return Matrix4x4
    {
        Vector4(v11, 0.f, 0.f, 0.f),
        Vector4(0.f, v22, 0.f, 0.f),
        Vector4(0.f, 0.f, v33, v34),
        Vector4(0.f, 0.f, v43, 0.f)
    };
}

Vector4& Matrix4x4::operator[](unsigned long long index)
{
    return value[index];
}
