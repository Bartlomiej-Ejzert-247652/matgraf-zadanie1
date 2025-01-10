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


    float denom = v.x * l.v.y - v.y * l.v.x;
    float t = 0;

    if (denom == 0) {

        float denomZ = v.x * l.v.z - v.z * l.v.x;
        t = (w.x * l.v.z - w.z * l.v.x) / denomZ;
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

std::vector<Vector> Line::CrossSphere(Sphere& sphere) {

    Vector w = Vector(p.x - sphere.centre.x, p.y - sphere.centre.y, p.z - sphere.centre.z, 1);

    float A = v.x * v.x + v.y * v.y + v.z * v.z;
    float B = 2 * (w.x * v.x + w.y * v.y + w.z * v.z);
    float C = w.x * w.x + w.y * w.y + w.z * w.z - sphere.radius * sphere.radius;

    // delta
    float discriminant = B * B - 4 * A * C;

    std::vector<Vector> crossPoints;

    if (discriminant < 0) {
        // Brak punktów przecięcia
        return crossPoints;
    }

    float sqrtDiscriminant = std::sqrt(discriminant);
    float t1 = (-B - sqrtDiscriminant) / (2 * A);
    float t2 = (-B + sqrtDiscriminant) / (2 * A);

    crossPoints.push_back(GetValue(t1));
    if (discriminant > 0) {
        crossPoints.push_back(GetValue(t2));
    }

    return crossPoints;
}
