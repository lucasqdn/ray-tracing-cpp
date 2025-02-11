#include <iostream>

using namespace std;

// Pixels are written out in rows, top to bottom, left to right.

int main() {
    int image_width = 256;
    int image_height = 256;

    cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        // Progress indicator using logging instead of outputting
        clog << "\rScanlines remaining: " << (image_height - j) << ' ' << flush;
        for (int i = 0; i < image_width; i++) {
            auto r = double(i) / (image_width - 1);
            auto g = double(j) / (image_height - 1);
            auto b = 0.0;

            // RGB value has to be scaled to 0-255
            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
    clog << "\rDone.        \n";
}