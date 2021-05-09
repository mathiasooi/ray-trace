#pragma once
#include <cmath>
#include <iostream>



struct Vector3D {
    double x, y, z;

    Vector3D(double xx, double yy, double zz);

    Vector3D operator* (double k) const;
    Vector3D operator/ (double k) const;
    Vector3D operator+ (const Vector3D &v) const;
    Vector3D operator- (const Vector3D &v) const;

    double dot_prod(const Vector3D &v) const;
    double length() const;
    Vector3D cross_prod(const Vector3D &v) const;

    friend std::ostream &operator<<(std::ostream &os, const Vector3D &v);
};

