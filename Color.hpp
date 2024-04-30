#ifndef COLOR_HPP
#define COLOR_HPP

#include "Vector3d.hpp"

#include <iostream>

// Alias for clarity
using Color = Vector3d;

// Convert linear color component to gamma 2 color
double linear_to_gamma(double linear);

// Print color converted to 8 bit numbers 
// EXAMPLE:  Vector3d(1, 1, 1) -> "255 255 255"
void write_color(std::ostream &os, const Color &color, int samples);

#endif