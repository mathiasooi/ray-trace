#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Vector3D {
    double x, y, z;

    Vector3D(double xx, double yy, double zz): x(xx), y(yy), z(zz) {}

    Vector3D operator* (const double &k) const {return Vector3D(k * x, k * y, k * z);}
    Vector3D operator/ (const double &k) const {return Vector3D(x / k, y / k, z / k);}
    Vector3D operator+ (const Vector3D &v) const {return Vector3D(x + v.x, y + v.y, z + v.z);}
    Vector3D operator- (const Vector3D &v) const {return Vector3D(x - v.x, y - v.y, z - v.z);}

    double dot_prod(const Vector3D &v) const {return x * v.x + y * v.y + z * v.z;}
    double length() const {return sqrt(x * x + y * y + z * z);}
    Vector3D cross_prod(const Vector3D &v) const {return Vector3D(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);}

    friend ostream &operator<<(ostream &os, const Vector3D &v){
        return os << "(" << v.x << " " << v.y << " " << v.z << ")";
    }
};

struct Color {
    double r, g, b;

    Color(): r(255.0), g(0.0), b(0.0) {}
    Color(double rr, double gg, double bb): r(rr), g(gg), b(bb) {}

    Color operator* (const float f) const {return Color(f * r, f * g, f * b);}
    Color operator+ (const Color &c) const {return Color(c.r * r, c.g * g, c.b * b);}

    string to_string(){
        ostringstream oss;
        oss << int(r) << ' ' << int(g) << ' ' << int(b);
        return oss.str();
    }
};

class Image {
    // Format ppm http://netpbm.sourceforge.net/doc/ppm.html
    private:
        int w, h;
        vector<vector<Color>> image;
    public:
        Image(int width, int height): w(width), h(height) {image.resize(w, vector<Color>(h));}

        void set_pixel(int x, int y, Color color) {image[x][y] = color;}
        void write_file(string file){
            // Follow format to write file
            ofstream fout(file, ofstream::out);
            // Header "P3 width height maxval"
            fout << "P3" << ' ' << w << ' ' << h << ' ' << 255 << '\n';
            fout << to_string();
        }

    string to_string(){
        ostringstream oss;
        for (auto i : image){
            for (Color k : i){
                oss << k.to_string() << '\n';
            }
        }
        return oss.str();
    }
};

int main(){
    Vector3D v1(1, 1, 1), v2(1, 2, 3);
    cout << v1 << ' ' << v2 << endl;
    Vector3D v3 = (v1 + v2) / 2.0;
    cout << v3 << endl;
    // Image image(100, 50);
    // image.write_file("test.ppm");
}