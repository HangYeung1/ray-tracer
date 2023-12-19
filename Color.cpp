#include "Color.hpp"

#include <cmath>
#include <iostream>

#include "Interval.hpp"

// EFFECTS:  Convert linear color component to gamma 2 color
double linear_to_gamma(double linear) {
  return std::sqrt(linear);
}

// REQUIRES: samples > 0
// MODIFIES: os
// EFFECTS:  Print color converted to 8 bit numbers 
// EXAMPLE:  Vector3d(1, 1, 1) -> "255 255 255"
void write_color(std::ostream &os, const Color &color, int samples) {
  double r = color.x();
  double g = color.y();
  double b = color.z();

  // Divide color by number of samples
  const double scale = 1.0 / samples;
  r *= scale;
  g *= scale;
  b *= scale;

  // Convert linear color to gamma 2 color
  r = linear_to_gamma(r);
  g = linear_to_gamma(g);
  b = linear_to_gamma(b);

  static const Interval intensity(0.000, 0.999);
  os << static_cast<int>(256 * intensity.clamp(r)) << ' '
     << static_cast<int>(256 * intensity.clamp(g)) << ' '
     << static_cast<int>(256 * intensity.clamp(b)) << '\n';
}