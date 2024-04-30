#ifndef HITTABLE_HPP
#define HITTABLE_HPP

#include <memory>

#include "Interval.hpp"
#include "Ray.hpp"

// Forward declaration for circular dependency
class Material;

class HitRecord {
 public:
  Point3d point;
  Vector3d normal;
  double t;
  bool front_face;
  std::shared_ptr<Material> material;

  // Set front_face and normal relative to outward_normal
  // Outward_normal should be a unit vector
  void set_face_normal(const Ray &ray, const Vector3d &outward_normal);
};

class Hittable {
 public:
  // Determine if ray hits this object within t_interval
  virtual bool hit(const Ray &ray, const Interval &t_interval, 
                   HitRecord &record) const = 0;
};

#endif