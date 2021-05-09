#pragma once
#include "ray.h"
#include "vector3d.h"

struct Camera {
    Ray ray;
    Vector3D left, right;

    Camera(Ray r, Vector3D l, Vector3D rr);

    Ray get_ray();
};