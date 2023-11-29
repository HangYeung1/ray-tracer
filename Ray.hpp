#ifndef RAY_H
#define RAY_H

#include "Vector3d.hpp"

class Ray {
 public:
  // EFFECTS:  Initialize ray with 0 origin and 0 direction
  Ray();

  // EFFECTS:  Initialize ray with origin and direction
  Ray(const Point3d &origin_in, const Vector3d &direction_in);

  // EFFECTS:  Return origin
  Point3d origin() const;

  // EFFECTS:  Return direction
  Vector3d direction() const;

  // EFFECTS:  Return ray linear interpolation at t
  Point3d at(double t);

 private:
  Point3d orig;
  Vector3d dir;
};

#endif