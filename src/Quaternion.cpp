#include "Quaternion.h"

Quaternion::Quaternion(float _a, float _x, float _y, float _z) {

    this -> a = _a;
    this -> v = Vector(_x, _y, _z);

}

Quaternion::Quaternion(float _a, Vector _v) {

    this -> a = _a;
    this -> v = _v;

}

