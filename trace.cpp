#include <iostream>

#include "vector3d.h"
#include "image.h" 
#include "ray.h"

using namespace std;

int main(){
    Vector3D v1(1, 1, 1), v2(1, 2, 3);
    cout << v1 << ' ' << v2 << endl;
    Vector3D v3 = (v1 + v2) / 2.0;
    cout << v3 << endl;
    Image image(100, 50);
    image.write_file("test.ppm");
}