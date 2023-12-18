#include "Camera.hpp"

#include <cassert>
#include <iostream>

#include "Color.hpp"
#include "Hittable.hpp"
#include "Interval.hpp"
#include "Ray.hpp"
#include "Vector3d.hpp"

// EFFECTS:  Initalize camera with default aspect ratio and image width
Camera::Camera()
  : aspect_ratio(1.0), image_width(100) { }

// REQUIRES: aspect_ratio_in > 0
// MODIFIES: aspect_ratio
// EFFECTS:  Set aspect_ratio to aspect_ratio_in
void Camera::set_aspect_ratio(const double aspect_ratio_in) {
  assert(aspect_ratio_in > 0);
  aspect_ratio = aspect_ratio_in;
}

// REQUIRES: image_width_in > 0
// MODIFIES: image_width
// EFFECTS:  Set image_width to image_width_in
void Camera::set_image_width(const int image_width_in) {
  assert(image_width_in > 0);
  image_width = image_width_in;
}

// EFFECTS:  Render world to terminal
void Camera::render(const Hittable &world) {
  initalize();

  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  for (int j = 0; j < image_height; ++j) {
    std::clog << "\rScanlines remaining: " << (image_height - j) 
              << ' ' << std::flush;
    for (int i = 0; i < image_width; ++i) {
      const Point3d pixel_center = pixel00_location 
                                 + (i * pixel_delta_u) 
                                 + (j * pixel_delta_v);
      const Vector3d ray_direction = pixel_center - center;
      const Ray ray(center, ray_direction);

      Color pixel_color = ray_color(ray, world);
      write_color(std::cout, pixel_color);
    }
  }
  std::clog << "\rDone.                 \n";
}

// EFFECTS:  Calculate camera parameters from aspect_ratio and image_width
void Camera::initalize() {
  // Determine image dimensions
  const int temp_height = image_width / aspect_ratio;
  image_height = (temp_height < 1) ? 1 : temp_height;

  // Determine viewport dimensions
  const double focal_length = 1.0;
  const double viewport_height = 2.0;
  const double real_ratio = static_cast<double>(image_width) / image_height;
  const double viewport_width = viewport_height * real_ratio;

  center = Point3d(0, 0, 0);

  // Determine pixel deltas
  const Vector3d viewport_u(viewport_width, 0, 0);
  const Vector3d viewport_v(0, -viewport_height, 0);
  pixel_delta_u = viewport_u / image_width;
  pixel_delta_v = viewport_v / image_height;

  // Determine pixel00 location
  const Point3d viewport_upper_left = center
                                    - Vector3d(0, 0, focal_length)
                                    - viewport_u / 2
                                    - viewport_v / 2;
  const Vector3d pixel_offest = 0.5 * (pixel_delta_u + pixel_delta_v);
  pixel00_location = viewport_upper_left + pixel_offest;
}

// EFFECTS:  Return color of ray
Color Camera::ray_color(const Ray &ray, const Hittable &world) const {
  HitRecord record;
  if(world.hit(ray, Interval(0, std::numeric_limits<double>::infinity()), 
              record)) {
      return 0.5 * (record.normal + Color(1, 1, 1));
  }
  const Vector3d unit_direction = unit_vector(ray.direction());
  const double a = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - a) * Color(1.0, 1.0, 1.0) + a * Color(0.5, 0.7, 1.0);
}