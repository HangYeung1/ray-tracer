#include "Camera.hpp"
#include "HittableList.hpp"
#include "Material.hpp"
#include "Sphere.hpp"
#include "Vector3d.hpp"

int main() {
  // Create world
  HittableList world;

  world.add(std::make_shared<Sphere>(
    Point3d(-1, 0, -1), 
    0.5, 
    std::make_shared<Metal>(Color(0.8, 0.8, 0.8), 0.3)
  ));
  world.add(std::make_shared<Sphere>(
    Point3d(0, 0, -1), 
    0.5, 
    std::make_shared<Lambertian>(Color(0.7, 0.3, 0.3))
  ));
  world.add(std::make_shared<Sphere>(
    Point3d(1, 0, -1), 
    0.5, 
    std::make_shared<Metal>(Color(0.8, 0.6, 0.2), 1.0)
  ));
  world.add(std::make_shared<Sphere>(
    Point3d(0, -100.5, -1), 
    100, 
    std::make_shared<Lambertian>(Color(0.8, 0.8, 0.0))
  ));

  // Create camera
  Camera camera;
  camera.set_aspect_ratio(16.0 / 9.0);
  camera.set_image_width(400);
  camera.set_samples_per_pixel(100);
  camera.set_max_depth(50);
  camera.render(world);
}