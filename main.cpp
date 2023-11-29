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
      double r = static_cast<double>(j) / (image_width - 1);
      double g = static_cast<double>(i) / (image_height - 1);
      double b = 0;

      // Scale rgb to integer value
      int ir = 255.999 * r;
      int ig = 255.999 * g;
      int ib = 255.999 * b;

      // Render pixel
      std::cout << ir << ' ' << ig << ' ' << ib << '\n';
    }
  }
}