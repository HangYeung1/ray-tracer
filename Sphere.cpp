#include "Sphere.hpp"

#include <cmath>
#include <memory>

#include "Hittable.hpp"
#include "Interval.hpp"
#include "Material.hpp"
#include "Vector3d.hpp"

// Initalize sphere to specified center, radius, and material
Sphere::Sphere(const Point3d &center_in, const double radius_in, 
               const std::shared_ptr<Material> &material_in)
  : center(center_in), radius(radius_in), material(material_in) { }

// Determine if ray hits this sphere within t-interval
bool Sphere::hit(const Ray &ray, const Interval &t_interval, 
                 HitRecord &record) const {
  // Calculate discriminant of collision equation
  const Vector3d oc = ray.origin() - center;
  const double a = ray.direction().length_squared();
  const double half_b = dot(ray.direction(), oc);
  const double c = oc.length_squared() - radius * radius;
  const double discriminant = half_b * half_b - a * c;

  // If discriminant is negative, there are no real roots
  if(discriminant < 0) {
    return false;
  }
  
  // Calculate the smallest root that is within t_interval
  const double discriminant_sqrt = std::sqrt(discriminant);
  double root = (-half_b - discriminant_sqrt) / a;
  if(!t_interval.surrounds(root)) {
    root = (-half_b + discriminant_sqrt) / a;
    if(!t_interval.surrounds(root)) {
      return false;
    }
  }

  // Record collision information
  record.t = root;
  record.point = ray.at(record.t);
  const Vector3d outward_normal = (record.point - center) / radius;
  record.set_face_normal(ray, outward_normal);
  record.material = material;

  return true;
}