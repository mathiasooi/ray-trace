#pragma once
#include "vector3d.h"

struct Ray{
  Vector3D origin, direction;

  Ray(Vector3D o, Vector3D d);

  Vector3D location(double t) const;
};