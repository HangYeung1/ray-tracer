#ifndef RANDOM_HPP
#define RANDOM_HPP

// EFFECTS: Returns a random double in the range [0, 1)
double random_double();

// REQUIRES: min <= max
// EFFECTS: Returns a random double in the range [min, max)
double random_double(double min, double max);

#endif 