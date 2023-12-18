#include "Camera.hpp"
#include "HittableList.hpp"
#include "Sphere.hpp"
#include "Vector3d.hpp"

int main() {
  // Create world
  HittableList world;
  world.add(std::make_shared<Sphere>(Point3d(0, 0, -1), 0.5));
  world.add(std::make_shared<Sphere>(Point3d(0, -100.5, -1), 100));

  // Create camera
  Camera camera;
  camera.set_aspect_ratio(16.0 / 9.0);
  camera.set_image_width(400);
  camera.set_samples_per_pixel(100);
  camera.render(world);
}