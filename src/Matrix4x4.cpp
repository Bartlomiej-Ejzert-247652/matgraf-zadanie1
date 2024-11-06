#include <cstring>
#include <cstdio>
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


const Matrix4x4 Matrix4x4::operator*(const Matrix4x4 &mat) const {
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

}

void Matrix4x4::SetMatrixAsInvertedOfGivenMatrix(const Matrix4x4 &mat) {
    Matrix4x4 augmented = mat;
    LoadIdentity();  // Ustawiamy bieżącą macierz jako jednostkową (będzie służyła jako prawa strona)

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
            //std::cerr << "Macierz jest osobliwa i nie ma odwrotności." << std::endl;
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

void Matrix4x4::InvertMatrix() {
    SetMatrixAsInvertedOfGivenMatrix(*this);
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
