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

    Vector w = Vector(l.p.x - p.x, l.p.y - p.y, l.p.z - p.z, 1);

    // Tworzymy macierz i obliczamy wyznaczniki
    float denom = v.x * l.v.y - v.y * l.v.x;
    float t = 0;
    // Sprawdzamy, czy prostą są równoległe (jeśli wyznacznik jest 0, prostą są równoległe)
    if (denom == 0) {

        float denomZ = v.x * l.v.z - v.z * l.v.x;
        t = (w.x * l.v.z - w.z * l.v.x) / denomZ;
          // Zwracamy pusty wektor (brak przecięcia)
    } else {
        t = (w.x * l.v.y - w.y * l.v.x) / denom;
    }
    return GetValue(t);

}

float Line::AngleLines(Line &l) {
    return v.angleDegrees(l.v);
}

std::string Line::print() {
    std::string s = "Line: ";


    s += "[ ";
    s += p.print();
    s += "\n";
    s += v.print();
    s += " ]";
    return s;
}


