#ifndef HITTABLE_HPP
#define HITTABLE_HPP

#include "Ray.hpp"

class HitRecord {
 public:
  Point3d point;
  Vector3d normal;
  double t;
  bool front_face;

  // REQUIRES: outward_normal is a unit vector
  // MODIFIES: front_face, normal
  // EFFECTS:  Set front_face and normal relative to outward_normal
  void set_face_normal(const Ray &ray, const Vector3d &outward_normal) {
    front_face = dot(ray.direction(), outward_normal) < 0;
    normal = front_face ? outward_normal : -outward_normal;
  }
};

class Hittable {
 public:
  // EFFECTS:  Determine if ray hits this object within (t_min, t_max)
  virtual bool hit(const Ray &ray, const double t_min, const double t_max, 
                   HitRecord &record) const = 0;
};

#endif