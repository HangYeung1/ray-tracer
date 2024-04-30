#ifndef RAY_HPP
#define RAY_HPP

#include "Vector3d.hpp"

class Ray {
 public:
  // Initialize ray with 0 origin and 0 direction
  Ray();

  // Initialize ray with origin and direction
  Ray(const Point3d &origin_in, const Vector3d &direction_in);

  // Return origin
  Point3d origin() const;

  // Return direction
  Vector3d direction() const;

  // Return ray linear interpolation at t
  Point3d at(double t) const;

 private:
  Point3d orig;
  Vector3d dir;
};

#endif