//
// Created by 48725 on 12/4/2024.
//

#include "Vector.h"

#ifndef ZADANIE1_SPHERE_H
#define ZADANIE1_SPHERE_H


class Sphere {
public:

    Sphere(float r, Vector c) : radius(r), centre(c) {}

    float radius;
    Vector centre;
};


#endif //ZADANIE1_SPHERE_H
