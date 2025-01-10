#ifndef ZADANIE1_CUBE_H
#define ZADANIE1_CUBE_H

#include "Vector.h"

class Cube {

public:

    Vector begin = Vector(-1, -1, -1, 0);
    Vector end = Vector(1, 1, 1, 0);

    Cube(float sizeMultiplier) {
        sizeMultiplier *= 0.5;
        begin.x *= sizeMultiplier;
        begin.y *= sizeMultiplier;
        begin.z *= sizeMultiplier;
        end.x *= sizeMultiplier;
        end.y *= sizeMultiplier;
        end.z *= sizeMultiplier;
    }

};

#endif //ZADANIE1_CUBE_H
