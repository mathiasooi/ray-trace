#pragma once
#include <string>

struct Color {
    double r, g, b;

    Color();
    Color(double rr, double gg, double bb);

    Color operator* (const double f) const;
    Color operator+ (const Color &c) const;

    std::string to_string();
};