#include "vector3d.h"
#include "ray.h"

Ray::Ray(Vector3D o, Vector3D d): origin(o), direction(d) {}

Vector3D Ray::location(double t) const {return origin + direction * t;}