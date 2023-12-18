#include "Color.hpp"

#include <iostream>

// MODIFIES: os
// EFFECTS:  Print color converted to 8 bit numbers 
// EXAMPLE:  Vector3d(1, 1, 1) -> "255 255 255"
void write_color(std::ostream &os, const Color &color) {
  os << static_cast<int>(255.999 * color.x()) << ' '
     << static_cast<int>(255.999 * color.y()) << ' '
     << static_cast<int>(255.999 * color.z()) << '\n';
}