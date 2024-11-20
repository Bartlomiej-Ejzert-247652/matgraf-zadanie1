#include "Quaternion.h"
#include <cmath>
#include <iostream>

Quaternion::Quaternion(float _a, float _x, float _y, float _z) {

    this -> a = _a;
    this -> v = Vector(_x, _y, _z);

}

Quaternion::Quaternion(float _a, Vector _v) {

    this -> a = _a;
    this -> v = _v;

}

void Quaternion::operator+=(const Quaternion &q) {
    this->a += q.getA();
    this->v += q.getV();
}

float Quaternion::getA() const {
    return a;
}

void Quaternion::setA(float a) {
    Quaternion::a = a;
}

const Vector &Quaternion::getV() const {
    return v;
}

void Quaternion::setV(const Vector &v) {
    Quaternion::v = v;
}

void Quaternion::operator-=(const Quaternion &q) {
    this->a -= q.getA();
    this->v -= q.getV();
}

//(a+bi+cj+dk)⋅(e+fi+gj+hk)=ae−bf−cg−dh+(af+be+ch−dg)⋅i+(ag−bh+ce+df)⋅j+(ah+bg−cf+de)⋅k

//[a, b, c, d]
//[e, f, g, h]

Quaternion Quaternion::operator*(const Quaternion &q) {
    Quaternion t(0, 0, 0, 0);
    t.a = a * q.a - v.x * q.v.x - v.y * q.v.y - v.z * q.v.z;
    t.v.x = a * q.v.x + v.x * q.a + v.y * q.v.z - v.z * q.v.y;
    t.v.y = a * q.v.y - v.x * q.v.z + v.y * q.a + v.z * q.v.x;
    t.v.z = a * q.v.z + v.x * q.v.y - v.y * q.v.x + v.z * q.a;

    return t;
}


void Quaternion::operator*=(const Quaternion &q) {
//    this->a = this->a * q.getA() - this->v.dotProduct(q.getV());
//
//    this->v = q.getV() * this->a + getV() * q.getA() + v.crossProduct(q.getV());
    *this = *this * q;
}

void Quaternion::operator/=(const Quaternion &q) {
    if ((q.getA() * q.getA() + q.getV().dotProduct(v)) != 0) {
        this->a = a * q.getA() + v.dotProduct(q.getV()) / (q.getA() * q.getA() + q.getV().dotProduct(v));
        this->v = (q.getV() * (-a) + (v * q.getA() + (v.crossProduct(q.getV()) * (-1)))) * (1 / (q.getA() * q.getA() + q.getV().dotProduct(v)));
    } else {
        return;
    }
}

Vector Quaternion::rotate(Vector& v) {

    Quaternion q =  ((*this)* (Quaternion(0, v)) * inverse());
    return {q.getV()};
}

void Quaternion::prepareRotation(Vector& axis, float angle) {
    this->a = cos(angle / 2);
    this->v = axis;
    normalise();
    //std::cout << v.print() << std::endl;

    this->v *= sin(angle / 2);
}

void Quaternion::normalise() {
    v.normalise();
}

Quaternion Quaternion::inverse() {

    return {a, -v.getX(), -v.getY(), -v.getZ()};
}



std::string Quaternion::print() const {
    std::string s = "[ ";
    s += std::to_string(a) + ", ";
    s += std::to_string(v.getX()) + ", ";
    s += std::to_string(v.getY()) + ", ";
    s += std::to_string(v.getZ()) + "]";
    return s;
}

