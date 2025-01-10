#ifndef ZADANIE1_CAMERA_H
#define ZADANIE1_CAMERA_H

#include <cstring>
#include "Vector.h"
#include "Surface.h"
#include "Cube.h"
#include "Matrix4x4.h"

#define SIZE 60

class Camera {

public:

    Vector position = Vector(0, 0, 0, 0);
    Vector direction = Vector(0, 0, 0, 1);
    Vector up = Vector(0, 0, 0, 1);

    float yaw = 0.0f;
    float pitch = 0.0f;
    float roll = 0.0f;

    Matrix4x4 rotationMatrix = Matrix4x4();

    bool isVisible[SIZE][SIZE];

    Surface viewPlane = Surface(0, 0, 0, 0);

    Camera(Vector _position, Vector _direction, Vector _up) {
        this->position = _position;
        this->direction = _direction;
        this->up = _up;
        std::memset(isVisible, false, sizeof(isVisible));
        viewPlane = Surface(_direction.getX(), _direction.getY(), _direction.getZ(), 0);
    }

    Camera(float px, float py, float pz, float dx, float dy, float dz, float ux, float uy, float uz) {
        this->position.x = px;
        this->position.y = py;
        this->position.z = pz;
        this->direction.x = dx;
        this->direction.y = dy;
        this->direction.z = dz;
        this->up.x = ux;
        this->up.y = uy;
        this->up.z = uz;
        std::memset(isVisible, false, sizeof(isVisible));
        viewPlane = Surface(dx, dy, dz, 0);
    }

    void rotato(float x, float y, float z);

    bool intersection(Line ray, Cube cube);

    void rayTrace(Cube cube);

    std::string render();

    void zoomo(float zoom);

};

#endif //ZADANIE1_CAMERA_H
