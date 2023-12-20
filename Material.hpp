#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "Color.hpp"
#include "Hittable.hpp"
#include "Ray.hpp"
#include "Vector3d.hpp"

class Material {
 public:
  // EFFECTS:  Return true if ray is scattered, false otherwise
  virtual bool scatter(const Ray &ray_in, const HitRecord &record, 
                       Color &attenuation, Ray &scattered) const = 0;
};

class Lambertian : public Material {
 public:
  // EFFECTS:  Initalize lambertian material to specified albedo
  Lambertian(const Color &albedo_in);

  // EFFECTS:  Return true if ray is scattered, false otherwise
  bool scatter(const Ray &ray_in, const HitRecord &record, 
               Color &attenuation, Ray &scattered) const override;

 private:
  Color albedo;
};

#endif