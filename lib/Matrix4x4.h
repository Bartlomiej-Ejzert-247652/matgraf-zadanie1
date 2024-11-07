#ifndef ZADANIE1_MATRIX4X4_H
#define ZADANIE1_MATRIX4X4_H

#include <string>
#include "Vector.h"

class Matrix4x4 {

public:
    float entries[16] = {0};

    Matrix4x4() {}

    Matrix4x4(float e0, float e1, float e2, float e3,
              float e4, float e5, float e6, float e7,
              float e8, float e9, float e10, float e11,
              float e12, float e13, float e14, float e15);

    Matrix4x4(const float* f);

    Matrix4x4(const Matrix4x4 &mat);

    ~Matrix4x4() {}

    const Matrix4x4 operator*(const float c) const;
    const Matrix4x4 operator+(const Matrix4x4 &mat) const;
    Vector operator*(const Vector &v) const;
    void LoadIdentity();
    void SetMatrixAsInvertedOfGivenMatrix(const Matrix4x4 &mat);
    void SetMatrixAsInvertedOfGivenMatrix4x4();
    void InvertMatrix();
    Matrix4x4 Transpose() const;
    void SetTransposeOfGivenMatrix(const Matrix4x4 &mat);
    Matrix4x4 operator*(const Matrix4x4 &mat) const;
    std::string print() const;

    void SetTranslationPart(const Vector& translation);

    void SetScale(const Vector& scaleFactor);

    void SetUniformScale(const float scaleFactor);

    void SetRotationAxis(const double angle, Vector axis);

    void SetRotationX(const double angle);
    void SetRotationY(const double angle);
    void SetRotationZ(const double angle);
    Matrix4x4 cofactor() const;
    float determinant() const;
};

#endif //ZADANIE1_MATRIX4X4_H
