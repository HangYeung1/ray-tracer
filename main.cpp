#include <cmath>
#include <iostream>
#include <limits>
#include <memory>

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
  camera.render(world);
}