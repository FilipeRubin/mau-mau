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
    const float v33 = (zFar + zNear) / (zNear - zFar);
    const float v34 = (2.0f * zFar * zNear) / (zNear - zFar);
    const float v43 = -1.0f;

    return Matrix4x4
    {
        Vector4(v11, 0.f, 0.f, 0.f),
        Vector4(0.f, v22, 0.f, 0.f),
        Vector4(0.f, 0.f, v33, v34),
        Vector4(0.f, 0.f, v43, 0.f)
    };
}

Matrix4x4 Matrix4x4::Rotation(const Vector3& rotationAngles)
{
    return RotationX(rotationAngles.x) * RotationY(rotationAngles.y) * RotationZ(rotationAngles.z);
}

Matrix4x4 Matrix4x4::RotationX(float angle)
{
    return Matrix4x4
    (
        Vector4(1.0f,        0.0f,         0.0f, 0.0f),
        Vector4(0.0f, cosf(angle), -sinf(angle), 0.0f),
        Vector4(0.0f, sinf(angle),  cosf(angle), 0.0f),
        Vector4(0.0f,        0.0f,         0.0f, 1.0f)
    );
}

Matrix4x4 Matrix4x4::RotationY(float angle)
{
    return Matrix4x4
    (
        Vector4( cosf(angle), 0.0f, sinf(angle), 0.0f),
        Vector4(        0.0f, 1.0f,        0.0f, 0.0f),
        Vector4(-sinf(angle), 0.0f, cosf(angle), 0.0f),
        Vector4(        0.0f, 0.0f,        0.0f, 1.0f)
    );
}

Matrix4x4 Matrix4x4::RotationZ(float angle)
{
    return Matrix4x4
    (
        Vector4(cosf(angle), -sinf(angle), 0.0f, 0.0f),
        Vector4(sinf(angle),  cosf(angle), 0.0f, 0.0f),
        Vector4(       0.0f,         0.0f, 1.0f, 0.0f),
        Vector4(       0.0f,         0.0f, 0.0f, 1.0f)
    );
}

Matrix4x4 Matrix4x4::Scale(const Vector3& scale)
{
    return Matrix4x4
    (
        Vector4(scale.x, 0.0f   , 0.0f   , 0.0f),
        Vector4(0.0f   , scale.y, 0.0f   , 0.0f),
        Vector4(0.0f   , 0.0f   , scale.z, 0.0f),
        Vector4(0.0f   , 0.0f   , 0.0f   , 1.0f)
    );
}

Matrix4x4 Matrix4x4::Translation(const Vector3& translation)
{
    return Matrix4x4
    (
        Vector4(1.0f, 0.0f, 0.0f, translation.x),
        Vector4(0.0f, 1.0f, 0.0f, translation.y),
        Vector4(0.0f, 0.0f, 1.0f, translation.z),
        Vector4(0.0f, 0.0f, 0.0f,          1.0f)
    );
}

Matrix4x4::Matrix4x4()
{
}

Matrix4x4::Matrix4x4(const Vector4& row1, const Vector4& row2, const Vector4& row3, const Vector4& row4) :
    value{ row1, row2, row3, row4 }
{
}

Vector4& Matrix4x4::operator[](unsigned long long index)
{
    return value[index];
}

const Vector4& Matrix4x4::operator[](unsigned long long index) const
{
    return value[index];
}

Vector4 Matrix4x4::operator*(const Vector4& other) const
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
