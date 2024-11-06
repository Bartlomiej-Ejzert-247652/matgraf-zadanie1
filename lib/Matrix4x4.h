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

    Matrix4x4 operator*(const float c) {
        return Matrix4x4(entries[0] * c,
                         entries[1] * c,
                         entries[2] * c,
                         entries[3] * c,
                         entries[4] * c,
                         entries[5] * c,
                         entries[6] * c,
                         entries[7] * c,
                         entries[8] * c,
                         entries[9] * c,
                         entries[10] * c,
                         entries[11] * c,
                         entries[12] * c,
                         entries[13] * c,
                         entries[14] * c,
                         entries[15] * c
                );
    }
    const Matrix4x4 operator+(const Matrix4x4 &mat) const;

};

#endif //ZADANIE1_MATRIX4X4_H
