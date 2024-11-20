#include "Quaternion.h"

Quaternion::Quaternion(float _a, float _x, float _y, float _z) {

    this -> a = _a;
    this -> x = _x;
    this -> y = _y;
    this -> z = _z;

}

Quaternion::Quaternion(float _a, Vector v) {

    this -> a = _a;
    this -> x = v.getX();
    this -> y = v.getY();
    this -> z = v.getZ();

}

