#pragma once
#include <string>
#include <fstream>
#include <vector>

#include "color.h"

class Image {
    // Format ppm http://netpbm.sourceforge.net/doc/ppm.html
    public:
        Image(int width, int height);
        void set_pixel(int x, int y, Color color);
        void write_file(std::string file);
    private:
        int w, h;
        std::vector<std::vector<Color>> image;
};