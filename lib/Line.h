//
// Created by 48725 on 12/4/2024.
//

#include "Vector.h"
#include <cmath>

#ifndef ZADANIE1_LINE_H
#define ZADANIE1_LINE_H


class Line {
public:
    Vector v = Vector(0, 0, 0, 1);
    Vector p = Vector(0, 0, 0, 0);

    Line(Vector punkt0, Vector punkt1, bool flaga);

    Vector CrossPoint(Line& l);
    float AngleLines(Line& l);

    Vector GetValue(float t);

    std::string print();
};


#endif //ZADANIE1_LINE_H
