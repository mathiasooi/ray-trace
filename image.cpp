#include <vector>
#include <string>
#include <fstream>

#include "color.h"
#include "image.h"

using namespace std;

Image::Image(int width, int height): w(width), h(height) {image.resize(w, vector<Color>(h));}

void Image::set_pixel(int x, int y, Color color) {image[x][y] = color;}
void Image::write_file(string file){
    ofstream fout(file, ofstream::out);
    fout << "P3" << ' ' << w << ' ' << h << ' ' << 255 << '\n';
    for (auto &i : image){
        for (Color &j : i){
            fout << j.to_string() << '\n';
        }
    }
}
