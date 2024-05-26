#include "engine/math/matrix4x4.h"
#include <cmath>

Matrix4x4 Matrix4x4::Identity()
{
    return Matrix4x4
    (
        Vector4(1.0f, 0.0f, 0.0f, 0.0f),
        Vector4(0.0f, 1.0f, 0.0f, 0.0f),
        Vector4(0.0f, 0.0f, 1.0f, 0.0f),
        Vector4(0.0f, 0.0f, 0.0f, 1.0f)
    );
}

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
    const Vector4(&a)[4] = value;
    const Vector4& b = other;

    return Vector4
    (
        (a[0][0] * b[0]) + (a[0][1] * b[1]) + (a[0][2] * b[2]) + (a[0][3] * b[3]),
        (a[1][0] * b[0]) + (a[1][1] * b[1]) + (a[1][2] * b[2]) + (a[1][3] * b[3]),
        (a[2][0] * b[0]) + (a[2][1] * b[1]) + (a[2][2] * b[2]) + (a[2][3] * b[3]),
        (a[3][0] * b[0]) + (a[3][1] * b[1]) + (a[3][2] * b[2]) + (a[3][3] * b[3])
    );
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& other) const
{
    const Matrix4x4(&a) = *this;
    const Matrix4x4& b = other;

    const float c11 = a[0][0] * b[0][0] + a[0][1] * b[1][0] + a[0][2] * b[2][0] + a[0][3] * b[3][0];
    const float c12 = a[0][0] * b[0][1] + a[0][1] * b[1][1] + a[0][2] * b[2][1] + a[0][3] * b[3][1];
    const float c13 = a[0][0] * b[0][2] + a[0][1] * b[1][2] + a[0][2] * b[2][2] + a[0][3] * b[3][2];
    const float c14 = a[0][0] * b[0][3] + a[0][1] * b[1][3] + a[0][2] * b[2][3] + a[0][3] * b[3][3];
    const float c21 = a[1][0] * b[0][0] + a[1][1] * b[1][0] + a[1][2] * b[2][0] + a[1][3] * b[3][0];
    const float c22 = a[1][0] * b[0][1] + a[1][1] * b[1][1] + a[1][2] * b[2][1] + a[1][3] * b[3][1];
    const float c23 = a[1][0] * b[0][2] + a[1][1] * b[1][2] + a[1][2] * b[2][2] + a[1][3] * b[3][2];
    const float c24 = a[1][0] * b[0][3] + a[1][1] * b[1][3] + a[1][2] * b[2][3] + a[1][3] * b[3][3];
    const float c31 = a[2][0] * b[0][0] + a[2][1] * b[1][0] + a[2][2] * b[2][0] + a[2][3] * b[3][0];
    const float c32 = a[2][0] * b[0][1] + a[2][1] * b[1][1] + a[2][2] * b[2][1] + a[2][3] * b[3][1];
    const float c33 = a[2][0] * b[0][2] + a[2][1] * b[1][2] + a[2][2] * b[2][2] + a[2][3] * b[3][2];
    const float c34 = a[2][0] * b[0][3] + a[2][1] * b[1][3] + a[2][2] * b[2][3] + a[2][3] * b[3][3];
    const float c41 = a[3][0] * b[0][0] + a[3][1] * b[1][0] + a[3][2] * b[2][0] + a[3][3] * b[3][0];
    const float c42 = a[3][0] * b[0][1] + a[3][1] * b[1][1] + a[3][2] * b[2][1] + a[3][3] * b[3][1];
    const float c43 = a[3][0] * b[0][2] + a[3][1] * b[1][2] + a[3][2] * b[2][2] + a[3][3] * b[3][2];
    const float c44 = a[3][0] * b[0][3] + a[3][1] * b[1][3] + a[3][2] * b[2][3] + a[3][3] * b[3][3];

    return Matrix4x4
    (
        Vector4(c11, c12, c13, c14),
        Vector4(c21, c22, c23, c24),
        Vector4(c31, c32, c33, c34),
        Vector4(c41, c42, c43, c44)
    );
}
