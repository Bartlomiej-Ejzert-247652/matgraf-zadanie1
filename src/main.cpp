#include <iostream>
#include "Vector.h"
#include "Matrix4x4.h"

using namespace std;

int main() {
    Vector v1 = Vector(1, 2, 3);
    Vector v2 = Vector(1, 2, 3);
    Vector v3 = Vector(5, 7, 8);
    Vector v4 = Vector(5, 7, 8);

    v1 += v3;
    cout << v1.print() << endl;
    v4 += v2;
    cout << v4.print() << endl;

    if (v1.equal(v4)) {
        cout << "Takie same." << endl;
    } else {
        cout << "Rozne." << endl;
    }

    v1 = Vector(0, 3, 0);
    v2 = Vector(5, 5, 0);

    cout << endl;
    cout << "Kat w radianach: " << v1.angleRad(v2) << endl;
    cout << "Kat w stopniach: " << v1.angleDegrees(v2) << endl;

    v1 = Vector(4, 5, 1);
    v2 = Vector(4, 1, 3);

    v3 = v1.crossProduct(v2);

    cout << endl;
    cout << "Wektor prostopadly do wektorow: " << v1.print() << " oraz " << v2.print() << " to: " << endl << v3.print() << endl;

    v3.normalise();
    cout << "Znormalizowany poprzedni wektor: " << v3.print() << endl;

    Matrix4x4 m = Matrix4x4(1, 2, 3, 4,
                            2, 3, 1, 2,
                            1, 1, 1, -1,
                            1, 0, -2, -6);

    cout << m.print() << endl;

    m.InvertMatrix();

    cout << m.print() << endl;

    return 0;
}
