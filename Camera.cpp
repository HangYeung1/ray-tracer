#include "Camera.hpp"

#include <cassert>
#include <iostream>

#include "Color.hpp"
#include "Hittable.hpp"
#include "Interval.hpp"
#include "Material.hpp"
#include "Random.hpp"
#include "Ray.hpp"
#include "Vector3d.hpp"

// Initalize camera with default aspect ratio and image width
Camera::Camera()
  : aspect_ratio(1.0), image_width(100), samples_per_pixel(10), 
    max_depth(10) { }

// Set aspect_ratio to aspect_ratio_in
void Camera::set_aspect_ratio(const double aspect_ratio_in) {
  assert(aspect_ratio_in > 0);
  aspect_ratio = aspect_ratio_in;
}

// Set image_width to image_width_in
void Camera::set_image_width(const int image_width_in) {
  assert(image_width_in > 0);
  image_width = image_width_in;
}

// Set samples_per_pixel to samples_per_pixel_in
void Camera::set_samples_per_pixel(const int samples_per_pixel_in) {
  assert(samples_per_pixel_in > 0);
  samples_per_pixel = samples_per_pixel_in;
}

// Set max_depth to max_depth_in
void Camera::set_max_depth(const int max_depth_in) {
  assert(max_depth_in > 0);
  max_depth = max_depth_in;
}

// Render world to terminal
void Camera::render(const Hittable &world) {
  initalize();

  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  for (int j = 0; j < image_height; ++j) {
    std::clog << "\rScanlines remaining: " << (image_height - j) 
              << ' ' << std::flush;
    for (int i = 0; i < image_width; ++i) {
      Color pixel_color(0, 0, 0);
      for (int k = 0; k < samples_per_pixel; ++k) {
        const Ray ray = sample_pixel(i, j);
        pixel_color += ray_color(ray, max_depth, world);
      }
      write_color(std::cout, pixel_color, samples_per_pixel);
    }
  }
  std::clog << "\rDone.                 \n";
}

// Return random offest in pixel area
Vector3d Camera::sample_pixel_offest() const {
  double x_offest = -0.5 + random_double();
  double y_offest = -0.5 + random_double();
  return (x_offest * pixel_delta_u) + (y_offest* pixel_delta_v);
}

// Return random ray from camera to pixel
Ray Camera::sample_pixel(const int i, const int j) const {
  const Point3d pixel_center = pixel00_location 
                             + (i * pixel_delta_u) 
                             + (j * pixel_delta_v);
  const Point3d sample_point = pixel_center + sample_pixel_offest();
  return Ray(center, sample_point - center);
}

// Calculate camera parameters from aspect_ratio and image_width
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

// Return color of ray
Color Camera::ray_color(const Ray &ray, const int depth, 
                        const Hittable &world) const {
  HitRecord record;

  // If ray bounce limit reached, ray is black
  if(depth <= 0) {
    return Color(0, 0, 0);
  }

  // If ray hits something, reflect it
  if(world.hit(ray, Interval(0.001, std::numeric_limits<double>::infinity()), 
              record)) {
      Ray scattered;
      Color attenuation;
      if(record.material->scatter(ray, record, attenuation, scattered)) {
        return attenuation * ray_color(scattered, depth - 1, world);
      }
      return Color(0, 0, 0);
  }

  const Vector3d unit_direction = unit_vector(ray.direction());
  const double a = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - a) * Color(1.0, 1.0, 1.0) + a * Color(0.5, 0.7, 1.0);
}