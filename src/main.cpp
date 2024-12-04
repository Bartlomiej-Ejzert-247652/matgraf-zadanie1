#include <iostream>
#include "Vector.h"
#include "Matrix4x4.h"
#include "Quaternion.h"
#include "Line.h"
#include "Surface.h"

using namespace std;

int main() {
//    Vector v1 = Vector(1, 2, 3);
//    Vector v2 = Vector(1, 2, 3);
//    Vector v3 = Vector(5, 7, 8);
//    Vector v4 = Vector(5, 7, 8);
//
//    v1 += v3;
//    cout << v1.print() << endl;
//    v4 += v2;
//    cout << v4.print() << endl;
//
//    if (v1.equal(v4)) {
//        cout << "Takie same." << endl;
//    } else {
//        cout << "Rozne." << endl;
//    }
//
//    v1 = Vector(0, 3, 0);
//    v2 = Vector(5, 5, 0);
//
//    cout << endl;
//    cout << "Kat w radianach: " << v1.angleRad(v2) << endl;
//    cout << "Kat w stopniach: " << v1.angleDegrees(v2) << endl;
//
//    v1 = Vector(4, 5, 1);
//    v2 = Vector(4, 1, 3);
//
//    v3 = v1.crossProduct(v2);
//
//    cout << endl;
//    cout << "Wektor prostopadly do wektorow: " << v1.print() << " oraz " << v2.print() << " to: " << endl << v3.print() << endl;
//
//    //v3.normalise();
//    v2.normalise();
//    cout << "Znormalizowany poprzedni wektor: " << v3.print() << endl;
//
//    Matrix4x4 m = Matrix4x4(1, 2, 3, 4,
//                            2, 3, 1, 2,
//                            1, 1, 1, -1,
//                            1, 0, -2, -6);
//
//    cout<<m.determinant();
//
//    cout << m.print() << endl;
//
//    cout << endl;
//
//    m.InvertMatrix();
//
//    cout << m.print() << endl;
//
//    Matrix4x4 m1 = Matrix4x4(0, 0, 0, -3,
//                             0, 0, 1, 0,
//                             0, 1, 0, 1,
//                             1, 0, 0, 0);
//
//    Matrix4x4 m2 = Matrix4x4(1, 0, 0, -3,
//                             0, 2, 1, 0,
//                             0, 1, 3, 1,
//                             1, 0, 0, 4);
//
//    Matrix4x4 m3 = m1 + m2;
//
//    cout << m1.print() << endl;
//    cout << m2.print() << endl;
//    cout << "m1 + m2" << endl << m3.print() << endl;
//
//    float c = 2.0;
//
//    m2 = m3 * c;
//
//    cout << "m2 * 2 " << endl << m2.print() << endl;
//
//    m3.LoadIdentity();
//
//    Matrix4x4 m4 = m2 * m3;
//
//    cout << "m2 * m3" << endl << m4.print() << endl;
//
//    Matrix4x4 m5 = Matrix4x4(1, 2, 3, 4,
//                             0, 0, 0, 0,
//                             0, 0, 0, 0,
//                             0, 0, 0, 0);
//
//
//    cout << endl;
//    cout << "m5: " << endl << m5.print() << endl;
//    m3 = m5.Transpose();
//    cout << "transpozycja" << endl << m3.print() << endl;
//
//    Vector v = Vector(1, 0, 0, 1);
//
//    m5.SetRotationY(90);
//    Vector vO = m5 * v;
//
//    cout << "Wektor obrocony o 90 wzgledem osi Y " << endl << vO.print() << endl;
//
//    m5 = Matrix4x4(1, 2, 3, 4,
//                   0, 0, 0, 0,
//                   0, 0, 0, 0,
//                   0, 0, 0, 0);
//
//    Matrix4x4 m6 = Matrix4x4(3, 2, 3, 3,
//                               8, 0, 0, 0,
//                               0, 9, 0, 0,
//                               0, 0, 0, 11);
//
//    Matrix4x4 m7 = m5 * m6;
//    Matrix4x4 m8 = m6 * m5;
//    cout << "m5 * m6 " << endl << m7.print() << endl;
//    cout << "m6 * m5 " << endl << m8.print() << endl;

//    Quaternion a(1, 2, 3, 4);
//    Quaternion b(5, 6, 7, 8);
//
//    Quaternion addA(1, 2, 3, 4);
//    Quaternion addB(5, 6, 7, 8);
//    addA+=addB;
//
//    cout << "To jest [1, 2, 3, 4] + [5, 6, 7, 8]: " << addA.print() << endl;
//
//    Quaternion subtractA(1, 2, 3, 4);
//    Quaternion subtractB(5, 6, 7, 8);
//    subtractB -= subtractA;
//
//    cout << "To jest [5, 6, 7, 8] - [1, 2, 3, 4]: " << subtractB.print() << endl;
//
//    cout << "To jest a * b " << (a * b).print() << endl;
//
//    cout << "To jest b * a " << (b * a).print() << endl;
//
//    Quaternion q1(1, 0, 0, 0);
//
//
//    Quaternion divideA(1, 2, 3, 4);
//    Quaternion divideB(4, 4, 3, 4);
//    Quaternion resDiv = divideA/divideB;
//
//    cout << "To jest [1, 2, 3, 4] : [4, 4, 3, 4]: " << resDiv.print() << endl;
//
//    cout << endl;
//    cout << "========" << endl;
//    cout << endl;
//
//    for (int i = 0; i < 360; i+=90) {
//
//        Vector v1(-1, -1, -1);
//        Vector axis(1, 0, 0);
//
//        q1.prepareRotation(axis, float(i) * std::numbers::pi_v<float> / 180.0f);
//
//        Vector v = q1.rotate(v1);
//
//        cout << i << ": " << v.print() << endl;
//        cout << endl;
//    }

    Vector p0 = Vector(0, 0, 0, 0);
    Vector p1 = Vector(1, 1, 0, 0);

    Line line = Line(p0, p1, 0);

    std::cout << line.GetValue(2).print() << std::endl;

    Line line1 = Line( Vector(-2, 5, 0),Vector(3, 1, 5), 1);
    Line line2 = Line( Vector(-2, 4, 0),Vector(1, -5, 3), 1);

    std::cout << "Punkt przeciecia: " << line1.CrossPoint(line2).print() << std::endl;

    std::cout << "Kat w stopniach pomiedzy prostymi: " << line1.AngleLines(line2) << std::endl;

    Line linesurface = Line(Vector(-2, 2, -1, 0), Vector(3, -1, 2, 1), 1);
    Surface surface = Surface(2, 3, 3, -8);

    std::cout << surface.CrossPoint(linesurface).print() << endl;

    std::cout << "Kat w stopniach pomiedzy prosta a surface: " << surface.AngleLineSurface(linesurface) << std::endl;

    Surface s1 = Surface(2, -1, 1, -8);
    Surface s2 = Surface(4, 3, 1, 14);

    std::cout << "Linia przecinajacych plaszczyzn " << s1.CrossLine(s2).print()<< std::endl;
    std::cout << "Kat w stopniach pomiedzy surface a surface: " << s1.AngleSurfaceSurface(s2) << std::endl;

    Vector A = Vector(5, 5, 4, 0);
    Vector Aprim = Vector(10, 10, 6, 0);
    Vector B = Vector(5, 5, 5, 0);
    Vector Bprim = Vector(10, 10, 3, 0);

    Line odcinekA = Line(A, Aprim, 0);
    Line odcinekB = Line(B, Bprim, 0);

    std::cout << "Punkt przeciecia odcinkow " << odcinekB.CrossPoint(odcinekA).print() << std::endl;

    return 0;
}
