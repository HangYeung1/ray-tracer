#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "Color.hpp"
#include "Hittable.hpp"
#include "Ray.hpp"
#include "Vector3d.hpp"

class Material {
 public:
  // Return true if ray is scattered, false otherwise
  virtual bool scatter(const Ray &ray_in, const HitRecord &record, 
                       Color &attenuation, Ray &scattered) const = 0;
};

class Lambertian : public Material {
 public:
  // Initalize lambertian material to specified albedo
  Lambertian(const Color &albedo_in);

  // Return true if ray is scattered, false otherwise
  bool scatter(const Ray &ray_in, const HitRecord &record, 
               Color &attenuation, Ray &scattered) const override;

 private:
  Color albedo;
};

class Metal : public Material {
 public:
  // Initalize metal material to specified albedo and fuzz
  Metal(const Color &albedo_in, const double fuzz_in);

  // Return true if ray is scattered, false otherwise
  bool scatter(const Ray &ray_in, const HitRecord &record, 
               Color &attenuation, Ray &scattered) const override;

 private:
  Color albedo;
  double fuzz;
};

#endif