//
// Created by 48725 on 12/4/2024.
//

#include <iostream>
#include "Line.h"

Line::Line(Vector punkt0, Vector punkt1, bool flaga) {
    if (flaga == 0) {
        v = Vector(punkt1.x - punkt0.x, punkt1.y - punkt0.y, punkt1.z - punkt0.z, 1);
        p = punkt0;
    } else {
        v = punkt1;
        p = punkt0;
    }

}



Vector Line::GetValue(float t) {
    return p + v * t;
}

Vector Line::CrossPoint(Line& l) {
    // Układ równań parametrycznych:
    // p1 + t1 * v1 = p2 + t2 * v2
    // Rozpisz to na komponenty
    float a1 = v.x, b1 = -l.v.x, c1 = l.p.x - p.x;
    float a2 = v.y, b2 = -l.v.y, c2 = l.p.y - p.y;
    float a3 = v.z, b3 = -l.v.z, c3 = l.p.z - p.z;

    // Rozwiąż układ równań dla t1 i t2
    float detXY = a1 * b2 - a2 * b1;

    if (fabs(detXY) < 1e-6) {
        std::cerr << "Blad" << std::endl;
        return Vector(0, 0, 0, 0);
    }

    float t1 = (c1 * b2 - c2 * b1) / detXY;
    float t2 = (a1 * c2 - a2 * c1) / detXY;



    // Zwróć punkt przecięcia (używając dowolnej z prostych)
    return GetValue(t1);
}

float Line::AngleLines(Line &l) {
    return v.angleDegrees(l.v);
}


