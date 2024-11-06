#include <cstring>
#include <cstdio>
#include <cmath>
#include "Matrix4x4.h"

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
    Vector u = axis.normalise();

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
