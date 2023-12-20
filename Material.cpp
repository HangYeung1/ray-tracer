#include "Material.hpp"

#include <memory>

#include "Color.hpp"
#include "Hittable.hpp"
#include "Ray.hpp"
#include "Vector3d.hpp"

// EFFECTS:  Initalize lambertian material to specified albedo
Lambertian::Lambertian(const Color &albedo_in)
  : albedo(albedo_in) { }

// EFFECTS:  Return true if ray is scattered, false otherwise
bool Lambertian::scatter(const Ray &ray_in, const HitRecord &record, 
                         Color &attenuation, Ray &scattered) const {
  Vector3d scatter_direction = record.normal + random_unit_vector();

  // Catch scatter direction decay
  if(scatter_direction.near_zero()) {
    scatter_direction = record.normal;
  }

  scattered = Ray(record.point, scatter_direction);
  attenuation = albedo;
  return true;
}
