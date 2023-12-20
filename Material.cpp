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

// EFFECTS:  Initalize metal material to specified albedo and fuzz
Metal::Metal(const Color &albedo_in, const double fuzz_in)
  : albedo(albedo_in), fuzz(fuzz_in < 1 ? fuzz_in : 1) { }

// EFFECTS:  Return true if ray is scattered, false otherwise
bool Metal::scatter(const Ray &ray_in, const HitRecord &record, 
                    Color &attenuation, Ray &scattered) const {
  const Vector3d reflected = reflect(unit_vector(ray_in.direction()), 
                                     record.normal);
  scattered = Ray(record.point, reflected + fuzz * random_unit_vector());
  attenuation = albedo;
  return (dot(scattered.direction(), record.normal) > 0); // For subsurface fuzz
}