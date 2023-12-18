#include <cmath>
#include <iostream>

#include "Color.hpp"
#include "Ray.hpp"
#include "Vector3d.hpp"

double hit_sphere(const Point3d &center, const double radius, const Ray &r) {
  const Vector3d oc = r.origin() - center;
  const double a = r.direction().length_squared();
  const double half_b = dot(r.direction(), oc);
  const double c = oc.length_squared() - radius * radius;
  const double discriminant = half_b * half_b - a * c;

  if(discriminant < 0) {
    return -1.0;
  } else {
    return (-half_b - std::sqrt(discriminant)) / a;
  }
}

Color ray_color(const Ray &ray) {
  const double t = hit_sphere(Point3d(0, 0, -1), 0.5, ray);
  if (t > 0.0) {
    const Vector3d N = unit_vector(ray.at(t) - Vector3d(0, 0, -1));
    return 0.5 * Color(N.x() + 1, N.y() + 1, N.z() + 1);
  }
  const Vector3d unit_direction = unit_vector(ray.direction());
  const double a = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - a) * Color(1.0, 1.0, 1.0) + a * Color(0.5, 0.7, 1.0);
}

int main() {
  // Image setup
  const double aspect_ratio = 16.0 / 9.0;
  const int image_width = 400;
  const int temp_height = image_width / aspect_ratio;
  const int image_height = (temp_height < 1) ? 1 : temp_height;

  // Camera setup
  const double focal_length = 1.0;
  const double viewport_height = 2.0;
  const double real_ratio = static_cast<double>(image_width) / image_height;
  const double viewport_width = viewport_height * real_ratio;

  const Point3d camera_center(0, 0, 0);
  const Vector3d viewport_u(viewport_width, 0, 0);
  const Vector3d viewport_v(0, -viewport_height, 0);

  const Vector3d pixel_delta_u = viewport_u / image_width;
  const Vector3d pixel_delta_v = viewport_v / image_height;

  const Point3d viewport_upper_left = camera_center
                                    - Vector3d(0, 0, focal_length)
                                    - viewport_u / 2
                                    - viewport_v / 2;
  const Vector3d pixel_offest = 0.5 * (pixel_delta_u + pixel_delta_v);
  const Point3d pixel00_location = viewport_upper_left + pixel_offest;

  // Render image
  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  for (int j = 0; j < image_height; ++j) {
    std::clog << "\rScanlines remaining: " << (image_height - j) 
              << ' ' << std::flush;
    for (int i = 0; i < image_width; ++i) {
      const Point3d pixel_center = pixel00_location 
                                 + (i * pixel_delta_u) 
                                 + (j * pixel_delta_v);
      const Vector3d ray_direction = pixel_center - camera_center;
      const Ray ray(camera_center, ray_direction);

      Color pixel_color = ray_color(ray);
      write_color(std::cout, pixel_color);
    }
  }
  std::clog << "\rDone.                 \n";
}