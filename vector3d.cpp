#include <cmath>
#include <iostream>

#include "Vector3D.h"

using namespace std;

Vector3D::Vector3D(double xx, double yy, double zz): x(xx), y(yy), z(zz) {}

Vector3D Vector3D::operator* (double k) const {return Vector3D(k * x, k * y, k * z);}
Vector3D Vector3D::operator/ (double k) const {return Vector3D(x / k, y / k, z / k);}
Vector3D Vector3D::operator+ (const Vector3D &v) const {return Vector3D(x + v.x, y + v.y, z + v.z);}
Vector3D Vector3D::operator- (const Vector3D &v) const {return Vector3D(x - v.x, y - v.y, z - v.z);}

double Vector3D::dot_prod(const Vector3D &v) const {return x * v.x + y * v.y + z * v.z;}
double Vector3D::length() const {return sqrt(x * x + y * y + z * z);}
Vector3D Vector3D::cross_prod(const Vector3D &v) const {return Vector3D(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);}

ostream &operator<<(ostream &os, const Vector3D &v) {return os << "(" << v.x << " " << v.y << " " << v.z << ")";}