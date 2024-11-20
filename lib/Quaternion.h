#ifndef ZADANIE1_QUATERNION_H
#define ZADANIE1_QUATERNION_H

#include "Vector.h"

class Quaternion {

public:

    float a;
    Vector v = Vector(0, 0, 0, 1);



    Quaternion(float _a, float _x, float _y, float _z);
    Quaternion(float _a, Vector v);

    void operator+=(const Quaternion &q);
    void operator-=(const Quaternion &q);
    void operator*=(const Quaternion &q);
    Quaternion operator*(const Quaternion &q);
    void operator/=(const Quaternion &q);

    Vector rotate(Vector& v);
    void prepareRotation(Vector& axis, float angle);
    void normalise();
    Quaternion inverse();

    std::string print() const;

    float getA() const;

    void setA(float a);

    const Vector &getV() const;

    void setV(const Vector &v);

};

#endif //ZADANIE1_QUATERNION_H
