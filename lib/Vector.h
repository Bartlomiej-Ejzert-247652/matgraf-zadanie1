#ifndef ZAD1_VECTOR_H
#define ZAD1_VECTOR_H

#include <string>

class Vector {
private:

    float x, y, z;

public:

    Vector(float x, float y, float z);
    Vector(float x, float y);

    float getX() const;
    float getY() const;
    float getZ() const;

    void operator+=(const Vector &v);
    void operator-=(const Vector &v);
    void operator*=(float a);
    void operator/=(float a);

    float dotProduct(const Vector &v) const;
    Vector crossProduct(const Vector &v) const;
    float length() const;
    Vector normalise();

    float angleRad(Vector &v) const;
    float angleDegrees(Vector &v) const;
    bool equal(Vector &v) const;
    std::string print() const;
};

#endif //ZAD1_VECTOR_H
