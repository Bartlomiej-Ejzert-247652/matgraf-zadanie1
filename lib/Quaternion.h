#ifndef ZADANIE1_QUATERNION_H
#define ZADANIE1_QUATERNION_H

#include "Vector.h"

class Quaternion {

private:

    float a;
    Vector v = Vector(0, 0, 0, 1);

public:

    Quaternion(float _a, float _x, float _y, float _z);
    Quaternion(float _a, Vector v);

    void operator+=(const Vector &v);
    void operator-=(const Vector &v);

};

#endif //ZADANIE1_QUATERNION_H
