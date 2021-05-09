#include "ray.h"
#include "vector3d.h"
#include "camera.h"

Camera::Camera(Ray r, Vector3D l, Vector3D rr): ray(r), left(l), right(rr) {}

Ray Camera::get_ray() {return ray;}