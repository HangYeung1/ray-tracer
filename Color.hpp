#ifndef COLOR_HPP
#define COLOR_HPP

#include "Vector3d.hpp"

#include <iostream>

// Alias for clarity
using Color = Vector3d;

// MODIFIES: os
// EFFECTS:  Print color converted to 8 bit numbers 
// EXAMPLE:  Vector3d(1, 1, 1) -> "255 255 255"
void write_color(std::ostream &os, const Color &color);

#endif