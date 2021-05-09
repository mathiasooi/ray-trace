#include <string>
#include <sstream>

#include "color.h"

using namespace std;

Color::Color(): r(0.0), g(0.0), b(0.0) {}
Color::Color(double rr, double gg, double bb): r(rr), g(gg), b(bb) {}

Color Color::operator* (const double f) const {return Color(f * r, f * g, f * b);}
Color Color::operator+ (const Color &c) const {return Color(c.r * r, c.g * g, c.b * b);}

string Color::to_string(){
    ostringstream oss;
    oss << int(r) << ' ' << int(g) << ' ' << int(b);
    return oss.str();
}
