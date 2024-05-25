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

const Vector4& Matrix4x4::operator[](unsigned long long index) const
{
    return value[index];
}

Vector4 Matrix4x4::operator+(const Vector4& other) const
{
    const Vector4& o = other;
    const Vector4(&v)[4] = value;

    return Vector4
    (
        (o[0] * v[0][0]) + (o[1] * v[0][1]) + (o[2] * v[0][2]) + (o[3] * v[0][3]),
        (o[0] * v[1][0]) + (o[1] * v[1][1]) + (o[2] * v[1][2]) + (o[3] * v[1][3]),
        (o[0] * v[2][0]) + (o[1] * v[2][1]) + (o[2] * v[2][2]) + (o[3] * v[2][3]),
        (o[0] * v[3][0]) + (o[1] * v[3][1]) + (o[2] * v[3][2]) + (o[3] * v[3][3])
    );
}
