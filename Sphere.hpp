#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "Hittable.hpp"
#include "Vector3d.hpp"

class Sphere : public Hittable {
 public:
  // EFFECTS:  Initalize sphere to specified center and radius
  Sphere(const Point3d &center_in, const double radius_in);

  // EFFECTS:  Determine if ray hits this sphere within (t_min, t_max)
  bool hit(const Ray &ray, const double t_min, const double t_max, 
           HitRecord &record) const override;

 private:
  Point3d center;
  double radius;
};

#endif