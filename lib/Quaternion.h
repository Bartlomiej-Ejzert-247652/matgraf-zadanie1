#ifndef ZADANIE1_QUATERNION_H
#define ZADANIE1_QUATERNION_H

#include "Vector.h"

class Quaternion {

private:

    float a, x, y, z;

public:

    Quaternion(float _a, float _x, float _y, float _z);
    Quaternion(float _a, Vector v);

    void operator+=(const Quaternion &q);
    void operator-=(const Quaternion &q);

};

#endif //ZADANIE1_QUATERNION_H
