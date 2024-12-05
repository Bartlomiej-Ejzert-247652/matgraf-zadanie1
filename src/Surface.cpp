//
// Created by 48725 on 12/4/2024.
//

#include "Surface.h"
#include <iostream>

Surface::Surface(float a, float b, float c, float d) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    n = Vector(a, b, c, 1);
}

Vector Surface::CrossPoint(Line &l) {

    float mianownik = a * l.v.x + b * l.v.y + c * l.v.z;

    float t = 0;



    if (fabs(mianownik) > 0.00001) {
        t = - (a * l.p.x + b * l.p.y + c * l.p.z + d) / mianownik;
    } else {
        std::cerr << "Linia sie nie przecina z plaszczyzna lub jest nieskonczenie wiele przeciec" << std::endl;
        return {0, 0, 0, 0};
    }

    return l.GetValue(t);
}

float Surface::AngleLineSurface(Line &l) {
    return 90 - n.angleDegrees(l.v);
}

Vector Surface::CrossPointOnLine(Surface& s) {
    // Równania dwóch płaszczyzn:
    // A1x + B1y + C1z + D1 = 0
    // A2x + B2y + C2z + D2 = 0

    float a1 = a, b1 = b, c1 = c, d1 = d;
    float a2 = s.a, b2 = s.b, c2 = s.c, d2 = s.d;

    float z = 0;

    // Układ równań:
    // A1x + B1y = -C1z - D1
    // A2x + B2y = -C2z - D2

    float c1_prime = -c1 * z - d1;
    float c2_prime = -c2 * z - d2;

    float detXY = a1 * b2 - a2 * b1;

    if (fabs(detXY) < 0.000001) {

        float y = 0;

        // Układ równań:
        // A1x + C1z = -B1y - D1
        // A2x + C2z = -B2y - D2

        float b1_prime = -b1 * y - d1;
        float b2_prime = -b2 * y - d2;

        float detXZ = a1 * c2 - a2 * c1;
        float x = (b1_prime * c2 - b2_prime * c1) / detXZ;
        float z = (a1 * b2_prime - a2 * b1_prime) / detXZ;

        return Vector(x, y, z);
    } else {

        float x = (c1_prime * b2 - c2_prime * b1) / detXY;
        float y = (a1 * c2_prime - a2 * c1_prime) / detXY;

        return Vector(x, y, z);
    }


}

Line Surface::CrossLine(Surface &s) {
    Vector direction = n.crossProduct(s.n);
    direction.w = 1;
    Vector p = CrossPointOnLine(s);

    return {p, direction, 1};
}

float Surface::AngleSurfaceSurface(Surface &s) {

    return n.angleDegrees(s.n);
}
