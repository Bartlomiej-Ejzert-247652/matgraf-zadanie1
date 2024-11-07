#include <cstring>
#include <cstdio>
#include <cmath>
#include "Matrix4x4.h"
#include <algorithm>
#include <cmath>

Matrix4x4::Matrix4x4(float e0, float e1, float e2, float e3,
                     float e4, float e5, float e6, float e7,
                     float e8, float e9, float e10, float e11,
                     float e12, float e13, float e14, float e15) {

    entries[0] = e0;
    entries[1] = e1;
    entries[2] = e2;
    entries[3] = e3;
    entries[4] = e4;
    entries[5] = e5;
    entries[6] = e6;
    entries[7] = e7;
    entries[8] = e8;
    entries[9] = e9;
    entries[10] = e10;
    entries[11] = e11;
    entries[12] = e12;
    entries[13] = e13;
    entries[14] = e14;
    entries[15] = e15;

}

Matrix4x4::Matrix4x4(const float *f) {
    memcpy(entries, f, 16*sizeof(float));
}

Matrix4x4::Matrix4x4(const Matrix4x4 &mat) {
    memcpy(entries, mat.entries, 16*sizeof(float));
}

const Matrix4x4 Matrix4x4::operator+(const Matrix4x4 &mat) const {
    return Matrix4x4(entries[0] + mat.entries[0],
                     entries[1] + mat.entries[1],
                     entries[2] + mat.entries[2],
                     entries[3] + mat.entries[3],
                     entries[4] + mat.entries[4],
                     entries[5] + mat.entries[5],
                     entries[6] + mat.entries[6],
                     entries[7] + mat.entries[7],
                     entries[8] + mat.entries[8],
                     entries[9] + mat.entries[9],
                     entries[10] + mat.entries[10],
                     entries[11] + mat.entries[11],
                     entries[12] + mat.entries[12],
                     entries[13] + mat.entries[13],
                     entries[14] + mat.entries[14],
                     entries[15] + mat.entries[15]);
}

const Matrix4x4 Matrix4x4::operator*(const float c) const {
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

void Matrix4x4::LoadIdentity() {
    memset(entries, 0, 16 * sizeof(float));
    entries[0] = 1.0;
    entries[5] = 1.0;
    entries[10] = 1.0;
    entries[15] = 1.0;
}


Matrix4x4 Matrix4x4::operator*(const Matrix4x4 &mat) const {
    if (entries[3] == 0.0f && entries[7] == 0.0f && entries[11] == 0.0f && entries[15] == 1.0f &&
        mat.entries[3] == 0.0f && mat.entries[7] == 0.0f && mat.entries[11] == 0.0f && mat.entries[15] == 1.0f) {

        return Matrix4x4(entries[0] * mat.entries[0] + entries[4] * mat.entries[1] + entries[8] * mat.entries[2],
                         entries[1] * mat.entries[0] + entries[5] * mat.entries[1] + entries[9] * mat.entries[2],
                         entries[2] * mat.entries[0] + entries[6] * mat.entries[1] + entries[10] * mat.entries[2],
                         0.0f,
                         entries[0] * mat.entries[4] + entries[4] * mat.entries[5] + entries[8] * mat.entries[6],
                         entries[1] * mat.entries[4] + entries[5] * mat.entries[5] + entries[9] * mat.entries[6],
                         entries[2] * mat.entries[4] + entries[6] * mat.entries[5] + entries[10] * mat.entries[6],
                         0.0f,
                         entries[0] * mat.entries[8] + entries[4] * mat.entries[9] + entries[8] * mat.entries[10],
                         entries[1] * mat.entries[8] + entries[5] * mat.entries[9] + entries[9] * mat.entries[10],
                         entries[2] * mat.entries[8] + entries[6] * mat.entries[9] + entries[10] * mat.entries[10],
                         0.0f,
                         entries[0] * mat.entries[12] + entries[4] * mat.entries[13] +
                         entries[8] * mat.entries[14] + entries[12],
                         entries[1] * mat.entries[12] + entries[5] * mat.entries[13] +
                         entries[9] * mat.entries[14] + entries[13],
                         entries[2] * mat.entries[12] + entries[6] * mat.entries[13] +
                         entries[10] * mat.entries[14] + entries[14],
                         1.0f);

    }
    return Matrix4x4(
            entries[0] * mat.entries[0] + entries[4] * mat.entries[1] + entries[8] * mat.entries[2] + entries[12] * mat.entries[3],
            entries[1] * mat.entries[0] + entries[5] * mat.entries[1] + entries[9] * mat.entries[2] + entries[13] * mat.entries[3],
            entries[2] * mat.entries[0] + entries[6] * mat.entries[1] + entries[10] * mat.entries[2] + entries[14] * mat.entries[3],
            entries[3] * mat.entries[0] + entries[7] * mat.entries[1] + entries[11] * mat.entries[2] + entries[15] * mat.entries[3],

            entries[0] * mat.entries[4] + entries[4] * mat.entries[5] + entries[8] * mat.entries[6] + entries[12] * mat.entries[7],
            entries[1] * mat.entries[4] + entries[5] * mat.entries[5] + entries[9] * mat.entries[6] + entries[13] * mat.entries[7],
            entries[2] * mat.entries[4] + entries[6] * mat.entries[5] + entries[10] * mat.entries[6] + entries[14] * mat.entries[7],
            entries[3] * mat.entries[4] + entries[7] * mat.entries[5] + entries[11] * mat.entries[6] + entries[15] * mat.entries[7],

            entries[0] * mat.entries[8] + entries[4] * mat.entries[9] + entries[8] * mat.entries[10] + entries[12] * mat.entries[11],
            entries[1] * mat.entries[8] + entries[5] * mat.entries[9] + entries[9] * mat.entries[10] + entries[13] * mat.entries[11],
            entries[2] * mat.entries[8] + entries[6] * mat.entries[9] + entries[10] * mat.entries[10] + entries[14] * mat.entries[11],
            entries[3] * mat.entries[8] + entries[7] * mat.entries[9] + entries[11] * mat.entries[10] + entries[15] * mat.entries[11],

            entries[0] * mat.entries[12] + entries[4] * mat.entries[13] + entries[8] * mat.entries[14] + entries[12] * mat.entries[15],
            entries[1] * mat.entries[12] + entries[5] * mat.entries[13] + entries[9] * mat.entries[14] + entries[13] * mat.entries[15],
            entries[2] * mat.entries[12] + entries[6] * mat.entries[13] + entries[10] * mat.entries[14] + entries[14] * mat.entries[15],
            entries[3] * mat.entries[12] + entries[7] * mat.entries[13] + entries[11] * mat.entries[14] + entries[15] * mat.entries[15]
    );
}

void Matrix4x4::SetMatrixAsInvertedOfGivenMatrix(const Matrix4x4 &mat) {
    Matrix4x4 augmented = mat;
    LoadIdentity();

    // Algorytm Gaussa-Jordana
    for (int i = 0; i < 4; ++i) {
        // Znajdź maksymalny element w kolumnie do stabilizacji numerycznej
        int maxRow = i;
        for (int k = i + 1; k < 4; ++k) {
            if (std::fabs(augmented.entries[k * 4 + i]) > std::fabs(augmented.entries[maxRow * 4 + i])) {
                maxRow = k;
            }
        }

        // Zamień wiersze, jeśli to konieczne
        if (i != maxRow) {
            for (int j = 0; j < 4; ++j) {
                std::swap(augmented.entries[i * 4 + j], augmented.entries[maxRow * 4 + j]);
                std::swap(entries[i * 4 + j], entries[maxRow * 4 + j]);
            }
        }

        // Sprawdzenie, czy element główny jest różny od zera
        float pivot = augmented.entries[i * 4 + i];
        if (std::fabs(pivot) < 1e-9) {
            return;
        }

        // Normalizacja wiersza
        for (int j = 0; j < 4; ++j) {
            augmented.entries[i * 4 + j] /= pivot;
            entries[i * 4 + j] /= pivot;
        }

        // Wyzerowanie elementów w innych wierszach
        for (int k = 0; k < 4; ++k) {
            if (k != i) {
                float factor = augmented.entries[k * 4 + i];
                for (int j = 0; j < 4; ++j) {
                    augmented.entries[k * 4 + j] -= factor * augmented.entries[i * 4 + j];
                    entries[k * 4 + j] -= factor * entries[i * 4 + j];
                }
            }
        }
    }
}

float determinant3x3(float a11, float a12, float a13,
                     float a21, float a22, float a23,
                     float a31, float a32, float a33) {
    return a11 * (a22 * a33 - a23 * a32)
           - a12 * (a21 * a33 - a23 * a31)
           + a13 * (a21 * a32 - a22 * a31);
}

Matrix4x4 Matrix4x4::cofactor() const {
    Matrix4x4 cof;
    cof.entries[0]  =  determinant3x3(entries[5],  entries[6],  entries[7],
                                      entries[9],  entries[10], entries[11],
                                      entries[13], entries[14], entries[15]);
    cof.entries[1]  = -determinant3x3(entries[4],  entries[6],  entries[7],
                                      entries[8],  entries[10], entries[11],
                                      entries[12], entries[14], entries[15]);
    cof.entries[2]  =  determinant3x3(entries[4],  entries[5],  entries[7],
                                      entries[8],  entries[9],  entries[11],
                                      entries[12], entries[13], entries[15]);
    cof.entries[3]  = -determinant3x3(entries[4],  entries[5],  entries[6],
                                      entries[8],  entries[9],  entries[10],
                                      entries[12], entries[13], entries[14]);

    cof.entries[4]  = -determinant3x3(entries[1],  entries[2],  entries[3],
                                      entries[9],  entries[10], entries[11],
                                      entries[13], entries[14], entries[15]);
    cof.entries[5]  =  determinant3x3(entries[0],  entries[2],  entries[3],
                                      entries[8],  entries[10], entries[11],
                                      entries[12], entries[14], entries[15]);
    cof.entries[6]  = -determinant3x3(entries[0],  entries[1],  entries[3],
                                      entries[8],  entries[9],  entries[11],
                                      entries[12], entries[13], entries[15]);
    cof.entries[7]  =  determinant3x3(entries[0],  entries[1],  entries[2],
                                      entries[8],  entries[9],  entries[10],
                                      entries[12], entries[13], entries[14]);

    cof.entries[8]  =  determinant3x3(entries[1],  entries[2],  entries[3],
                                      entries[5],  entries[6],  entries[7],
                                      entries[13], entries[14], entries[15]);
    cof.entries[9]  = -determinant3x3(entries[0],  entries[2],  entries[3],
                                      entries[4],  entries[6],  entries[7],
                                      entries[12], entries[14], entries[15]);
    cof.entries[10] =  determinant3x3(entries[0],  entries[1],  entries[3],
                                      entries[4],  entries[5],  entries[7],
                                      entries[12], entries[13], entries[15]);
    cof.entries[11] = -determinant3x3(entries[0],  entries[1],  entries[2],
                                      entries[4],  entries[5],  entries[6],
                                      entries[12], entries[13], entries[14]);

    cof.entries[12] = -determinant3x3(entries[1],  entries[2],  entries[3],
                                      entries[5],  entries[6],  entries[7],
                                      entries[9],  entries[10], entries[11]);
    cof.entries[13] =  determinant3x3(entries[0],  entries[2],  entries[3],
                                      entries[4],  entries[6],  entries[7],
                                      entries[8],  entries[10], entries[11]);
    cof.entries[14] = -determinant3x3(entries[0],  entries[1],  entries[3],
                                      entries[4],  entries[5],  entries[7],
                                      entries[8],  entries[9],  entries[11]);
    cof.entries[15] =  determinant3x3(entries[0],  entries[1],  entries[2],
                                      entries[4],  entries[5],  entries[6],
                                      entries[8],  entries[9],  entries[10]);

    return cof;
}

float Matrix4x4::determinant() const {

    float c0 =  determinant3x3(entries[5], entries[6], entries[7], entries[9], entries[10], entries[11], entries[13], entries[14], entries[15]);
    float c1 = -determinant3x3(entries[4], entries[6], entries[7], entries[8], entries[10], entries[11], entries[12], entries[14], entries[15]);
    float c2 =  determinant3x3(entries[4], entries[5], entries[7], entries[8], entries[9], entries[11], entries[12], entries[13], entries[15]);
    float c3 = -determinant3x3(entries[4], entries[5], entries[6], entries[8], entries[9], entries[10], entries[12], entries[13], entries[14]);

    return entries[0] * c0 + entries[1] * c1 + entries[2] * c2 + entries[3] * c3;
}

void Matrix4x4::SetMatrixAsInvertedOfGivenMatrix4x4() {

    float det = determinant();
    if (det == 0) return;

    Matrix4x4 dope = cofactor().Transpose();


    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            entries[j + i * 4] = dope.entries[j + i * 4] / det;


}

void Matrix4x4::InvertMatrix() {
    SetMatrixAsInvertedOfGivenMatrix4x4();
}

std::string Matrix4x4::print() const {
    std::string s = "[ [";
    s += std::to_string(entries[0]) + ", ";
    s += std::to_string(entries[1]) + ", ";
    s += std::to_string(entries[2]) + ", ";
    s += std::to_string(entries[3]) + "] \n";
    s += " [";
    s += std::to_string(entries[4]) + ", ";
    s += std::to_string(entries[5]) + ", ";
    s += std::to_string(entries[6]) + ", ";
    s += std::to_string(entries[7]) + "] \n";
    s += " [";
    s += std::to_string(entries[8]) + ", ";
    s += std::to_string(entries[9]) + ", ";
    s += std::to_string(entries[10]) + ", ";
    s += std::to_string(entries[11]) + "] \n";
    s += " [";
    s += std::to_string(entries[12]) + ", ";
    s += std::to_string(entries[13]) + ", ";
    s += std::to_string(entries[14]) + ", ";
    s += std::to_string(entries[15]) + "] ]";
    return s;
	
}
	
void Matrix4x4::SetTranslationPart(const Vector &translation) {
    entries[12] = translation.getX();
    entries[13] = translation.getY();
    entries[14] = translation.getZ();
}

void Matrix4x4::SetScale(const Vector &scaleFactor) {
    LoadIdentity();

    entries[0]=scaleFactor.getX();
    entries[5] = scaleFactor.getY();
    entries[10] = scaleFactor.getZ();
}

void Matrix4x4::SetUniformScale(const float scaleFactor) {
    LoadIdentity();

    entries[0] = entries[5] = entries[10] = scaleFactor;
}

void Matrix4x4::SetRotationAxis(const double angle, Vector axis) {
    axis.normalise();

    Vector u = axis;

    float sinAngle=(float)sin(M_PI*angle/180);
    float cosAngle = (float) cos(M_PI*angle/180);
    float oneMinusCosAngle = 1.0f-cosAngle;

    LoadIdentity();

    entries[0]=(u.getX()) * (u.getX()) + cosAngle*(1-(u.getX())*(u.getX()));
    entries[4]=(u.getX()) * (u.getY()) * (oneMinusCosAngle) - sinAngle*u.getZ();
    entries[8] = (u.getX()) * (u.getZ()) * (oneMinusCosAngle) + sinAngle * u.getY();

    entries[1] = (u.getX()) * (u.getY()) * (oneMinusCosAngle) + sinAngle*u.getZ();
    entries[5] = (u.getY()) * (u.getY()) + cosAngle*(1-(u.getY())*(u.getY()));
    entries[9] = (u.getY()) * (u.getZ()) * (oneMinusCosAngle) - sinAngle*u.getX();

    entries[2] = (u.getX()) * (u.getZ()) * (oneMinusCosAngle) - sinAngle*u.getY();
    entries[6] = (u.getY()) * (u.getZ()) * (oneMinusCosAngle) + sinAngle*u.getX();
    entries[10] = (u.getZ()) * (u.getZ()) + cosAngle*(1-(u.getZ())*(u.getZ()));
}

void Matrix4x4::SetRotationX(const double angle) {
    LoadIdentity();

    entries[5] = (float)cos(M_PI*angle/180);
    entries[6] = (float)sin(M_PI*angle/180);

    entries[9] = -entries[6];
    entries[10] = entries[5];
}

void Matrix4x4::SetRotationY(const double angle) {
    LoadIdentity();

    entries[0] = (float)cos(M_PI*angle/180);
    entries[2] = -(float)sin(M_PI*angle/180);

    entries[8] = -entries[2];
    entries[10] = entries[0];
}

void Matrix4x4::SetRotationZ(const double angle) {
    LoadIdentity();

    entries[0] = (float)cos(M_PI*angle/180);
    entries[1] = (float)sin(M_PI*angle/180);

    entries[4] = -entries[1];
    entries[5] = entries[0];
}

Matrix4x4 Matrix4x4::Transpose() const {
    Matrix4x4 result;
//    = Matrix4x4(0, 0, 0, 0,
//                                 0, 0, 0, 0,
//                                 0, 0, 0, 0,
//                                 0, 0, 0, 0);
    result.SetTransposeOfGivenMatrix(*this);
    return result;
}

void Matrix4x4::SetTransposeOfGivenMatrix(const Matrix4x4& mat) {
    entries[0] = mat.entries[0];
    entries[1] = mat.entries[4];
    entries[2] = mat.entries[8];
    entries[3] = mat.entries[12];
    entries[4] = mat.entries[1];
    entries[5] = mat.entries[5];
    entries[6] = mat.entries[9];
    entries[7] = mat.entries[13];
    entries[8] = mat.entries[2];
    entries[9] = mat.entries[6];
    entries[10] = mat.entries[10];
    entries[11] = mat.entries[14];
    entries[12] = mat.entries[3];
    entries[13] = mat.entries[7];
    entries[14] = mat.entries[11];
    entries[15] = mat.entries[15];
}


Vector Matrix4x4::operator*(const Vector &v) const {
    float x = entries[0] * v.getX() + entries[4] * v.getY() + entries[8] * v.getZ() + entries[12] * v.getW();
    float y = entries[1] * v.getX() + entries[5] * v.getY() + entries[9] * v.getZ() + entries[13] * v.getW();
    float z = entries[2] * v.getX() + entries[6] * v.getY() + entries[10] * v.getZ() + entries[14] * v.getW();
    float w = entries[3] * v.getX() + entries[7] * v.getY() + entries[11] * v.getZ() + entries[15] * v.getW();

    return Vector(x, y, z, w);
}