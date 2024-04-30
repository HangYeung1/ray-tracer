#include "Ray.hpp"

// Initialize ray with 0 origin and 0 direction
Ray::Ray() = default;

// Initialize ray with origin and direction
Ray::Ray(const Point3d &orig_in, const Vector3d &dir_in)
  : orig(orig_in), dir(dir_in) { }

// Return origin
Point3d Ray::origin() const {
  return orig;
}

// Return direction
Vector3d Ray::direction() const {
  return dir;
}

// Return ray linear interpolation at t
Point3d Ray::at(double t) const {
  return orig + t * dir;
}