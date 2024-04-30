#include "Random.hpp"

#include <cstdlib>

// Returns a random double in the range [0, 1)
double random_double() {
    return rand() / (RAND_MAX + 1.0);
}

// Returns a random double in the range [min, max)
double random_double(double min, double max) {
    return min + (max - min) * random_double();
}