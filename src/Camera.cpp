#include "Camera.h"

void Camera::rayTrace(Cube cube) {

    rotationMatrix.SetRotationX(yaw);
    position = rotationMatrix * position;
    direction = rotationMatrix * direction;

    rotationMatrix.SetRotationY(pitch);
    position = rotationMatrix * position;
    direction = rotationMatrix * direction;

    rotationMatrix.SetRotationZ(roll);
    position = rotationMatrix * position;
    direction = rotationMatrix * direction;

    for(int y = 0; y < SIZE; ++y) {
        for(int x = 0; x < SIZE; ++x) {

            double u = (x / (double)(SIZE - 1)) * 2 - 1; // Zakres od -1 do 1
            double v = (y / (double)(SIZE - 1)) * 2 - 1; // Zakres od -1 do 1
            Vector point_on_plane(u, v, 4000);
            rotationMatrix.SetRotationX(yaw);
            point_on_plane = rotationMatrix * point_on_plane;
            rotationMatrix.SetRotationY(pitch);
            point_on_plane = rotationMatrix * point_on_plane;
            rotationMatrix.SetRotationZ(roll);
            point_on_plane = rotationMatrix * point_on_plane;
            Line ray(this->position, point_on_plane, false);
            isVisible[x][y] = intersection(ray, cube);

        }
    }

}

bool Camera::intersection(Line ray, Cube cube) {

        double tmin = (cube.begin.x - position.x) / ray.v.x;
        double tmax = (cube.end.x - position.x) / ray.v.x;
        if (tmin > tmax) std::swap(tmin, tmax);

        double tymin = (cube.begin.y - position.y) / ray.v.y;
        double tymax = (cube.end.y - position.y) / ray.v.y;
        if (tymin > tymax) std::swap(tymin, tymax);

        if ((tmin > tymax) || (tymin > tmax)) return false;

        if (tymin > tmin) tmin = tymin;
        if (tymax < tmax) tmax = tymax;

        double tzmin = (cube.begin.z - position.z) / ray.v.z;
        double tzmax = (cube.end.z - position.z) / ray.v.z;
        if (tzmin > tzmax) std::swap(tzmin, tzmax);

        if ((tmin > tzmax) || (tzmin > tmax)) return false;

        return true;

}

std::string Camera::render() {

    std::string s = "";

    for(int y = 0; y < SIZE; ++y) {
        for (int x = 0; x < SIZE; ++x) {
            if(isVisible[x][y]) {
                s += "0 ";
            } else {
                s += ". ";
            }
        }
        s += '\n';
    }

    return s;

}

void Camera::rotato(float x, float y, float z) {
    yaw = x;
    pitch = y;
    roll = z;
}
