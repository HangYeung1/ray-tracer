#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Color.hpp"
#include "Hittable.hpp"

class Camera {
 public:
  // Initalize camera with default aspect ratio and image width
  Camera();

  // Set aspect_ratio to aspect_ratio_in
  void set_aspect_ratio(const double aspect_ratio_in);

  // Set image_width to image_width_in
  void set_image_width(const int image_width_in);

  // Set samples_per_pixel to samples_per_pixel_in
  void set_samples_per_pixel(const int samples_per_pixel_in);

  // Set max_depth to max_depth_in
  void set_max_depth(const int max_depth_in);

  // Render world to standard terminal
  void render(const Hittable &world);

 private:
  double aspect_ratio;
  int image_width;
  int samples_per_pixel;
  int max_depth;

  int image_height;
  Point3d center;
  Point3d pixel00_location;
  Vector3d pixel_delta_u;
  Vector3d pixel_delta_v;

  // Calculate camera parameters from aspect_ratio and image_width
  void initalize();
  
  // Return random offest in pixel area
  Vector3d sample_pixel_offest() const;

  // Return random ray from camera to pixel
  Ray sample_pixel(const int i, const int j) const;

  // Return color of ray
  Color ray_color(const Ray &ray, const int depth, const Hittable &world) const;
};

#endif