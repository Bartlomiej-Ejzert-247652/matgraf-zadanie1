#include <cmath>
#include <iostream>
#include <cmath>
#include <string>
#include "Vector.h"

// Getters for all 3 vector coordinates

float Vector::getX() const {
    return x;
}

float Vector::getY() const {
    return y;
}

float Vector::getZ() const {
    return z;
}

// Constructor

Vector::Vector(float x, float y, float z) {
    this -> x = x;
    this -> y = y;
    this -> z = z;
}

Vector::Vector(float x, float y) {
    this -> x = x;
    this -> y = y;
    this -> z = 0;
}

// Addition, subtraction, multiplication and division operators

void Vector::operator+=(const Vector &v) {
    this -> x += v.getX();
    this -> y += v.getY();
    this -> z += v.getZ();
}

void Vector::operator-=(const Vector &v) {
    this -> x -= v.getX();
    this -> y -= v.getY();
    this -> z -= v.getZ();
}

void Vector::operator*=(float a) {
    this -> x *= a;
    this -> y *= a;
    this -> z *= a;
}

void Vector::operator/=(float a) {
    if (a != 0) {
        this -> x /= a;
        this -> y /= a;
        this -> z /= a;
    } else {
        std::cerr << "Cannot divide by 0!" << std::endl;
    }
}

// Printing vector to console for debugging

std::string Vector::print() const {
    std::string s = "[ ";
    s += std::to_string(x) + ", ";
    s += std::to_string(y) + ", ";
    s += std::to_string(z) + "]";
    return s;
}

// Dot and cross products (iloczyn skalarny i wektorowy)

float Vector::dotProduct(const Vector &v) const {
    float dot = 0;
    dot += this -> getX() * v.getX();
    dot += this -> getY() * v.getY();
    dot += this -> getZ() * v.getZ();
    return dot;
}

Vector Vector::crossProduct(const Vector &v) const {
    Vector cross(0, 0, 0);
    cross.x = this -> getY() * v.getZ() - this -> getZ() * v.getY();
    cross.y = this -> getZ() * v.getX() - this -> getX() * v.getZ();
    cross.z = this -> getX() * v.getY() - this -> getY() * v.getX();
    return cross;
}

// Vector length

float Vector::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

Vector Vector::normalise() {
    float len = length();
    if (len != 0 ) {
        this -> x /= len;
        this -> y /= len;
        this -> z /= len;
        std::cout << "bla bla" << std::endl;
    } else {
        std::cerr << "Cannot divide by 0!" << std::endl;
    }
}

// Calculating the angle between two vectors

float Vector::angleRad(Vector &v) const {
    float uv = dotProduct(v);

    return std::acos(uv / (length() * v.length()));
}

float Vector::angleDegrees(Vector &v) const {
    return angleRad(v) * 180 / M_PI;
}

// Checking if two vectors are equal (same x, y and z)

bool Vector::equal(Vector &v) const {
    if (x == v.getX() && y == v.getY() && z == v.getZ()) return true;
    else return false;
}
