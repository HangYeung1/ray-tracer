#include "Color.hpp"
#include "Vector3d.hpp"

#include <iostream>

int main() {
  // Create 256 by 256 image
  int image_width = 256;
  int image_height = 256;

  // Print ppm header
  std::cout << "P3\n" 
            << image_width << ' ' << image_height 
            << "\n255\n";

  // Write pixels left to right, row by row, top to bottom
  for (int j = 0; j < image_height; ++j) {
    // Log render process
    std::clog << "\rScanlines remaining: " << (image_height - j) 
              << ' ' << std::flush;
    
    for(int i = 0; i < image_width; ++i) {
      // Calculate rgb real values
      Color color(static_cast<double>(j) / (image_width - 1),
                  static_cast<double>(i) / (image_height - 1),
                  0);

      // Render pixel
      write_color(std::cout, color);
      std::cout << '\n';
    }
  }
  std::clog << "\rDone.                 \n";
}