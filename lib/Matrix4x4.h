#ifndef ZADANIE1_MATRIX4X4_H
#define ZADANIE1_MATRIX4X4_H

class Matrix4x4 {

public:
    float entries[16];

    Matrix4x4() {}

    Matrix4x4(float e0, float e1, float e2, float e3,
              float e4, float e5, float e6, float e7,
              float e8, float e9, float e10, float e11,
              float e12, float e13, float e14, float e15);

    Matrix4x4(const float* f);

    Matrix4x4(const Matrix4x4 &mat);

    ~Matrix4x4() {}

    const Matrix4x4 operator+(const Matrix4x4 &mat) const;

};

#endif //ZADANIE1_MATRIX4X4_H
