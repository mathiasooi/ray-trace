#include <vector>

#include "ray.h"
#include "vector3d.h"
#include "color.h"

class Shape{
    public:
        virtual std::vector<Ray> intersections();
        virtual Color get_color();
    private:
        Color color;
};

class Sphere: public Shape{

};

class Plane: public Shape {

};