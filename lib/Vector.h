#ifndef ZAD1_VECTOR_H
#define ZAD1_VECTOR_H

#include <string>

class Vector {

public:
    float x, y, z, w;



    Vector(float x, float y, float z, float w);
    Vector(float x, float y, float z);
    Vector(float x, float y);
    //Vector() {}

    float getX() const;
    float getY() const;
    float getZ() const;
    float getW() const;

    void operator+=(const Vector &v);
    void operator-=(const Vector &v);

    void operator*=(float a);
    Vector operator*(float a) const;
    Vector operator+(Vector v) const;
    Vector operator-(Vector v) const;
    void operator/=(float a);

    float dotProduct(const Vector &v) const;
    Vector crossProduct(const Vector &v) const;
    float length() const;
    void normalise();

    float angleRad(Vector &v) const;
    float angleDegrees(Vector &v) const;
    bool equal(Vector &v) const;
    std::string print() const;



};

#endif //ZAD1_VECTOR_H
