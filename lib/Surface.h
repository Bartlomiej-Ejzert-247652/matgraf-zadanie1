//
// Created by 48725 on 12/4/2024.
//

#include "Vector.h"
#include "Line.h"

#ifndef ZADANIE1_SURFACE_H
#define ZADANIE1_SURFACE_H


class Surface {
public:
    float a, b, c, d;
    Vector n = Vector(0, 0, 0, 1);
    Surface(float a, float b, float c, float d);
    float AngleLineSurface(Line &l);
    Vector CrossPoint(Line &l);
    Vector CrossPointOnLine(Surface& s);
    Line CrossLine(Surface &s);
    float AngleSurfaceSurface(Surface &s);
};


#endif //ZADANIE1_SURFACE_H
