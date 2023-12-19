#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Color.hpp"
#include "Hittable.hpp"

class Camera {
 public:
  // EFFECTS:  Initalize camera with default aspect ratio and image width
  Camera();

  // REQUIRES: aspect_ratio_in > 0
  // MODIFIES: aspect_ratio
  // EFFECTS:  Set aspect_ratio to aspect_ratio_in
  void set_aspect_ratio(const double aspect_ratio_in);

  // REQUIRES: image_width_in > 0
  // MODIFIES: image_width
  // EFFECTS:  Set image_width to image_width_in
  void set_image_width(const int image_width_in);

  // REQUIRES: samples_per_pixel_in > 0
  // MODIFIES: samples_per_pixel
  // EFFECTS:  Set samples_per_pixel to samples_per_pixel_in
  void set_samples_per_pixel(const int samples_per_pixel_in);

  // REQUIRES: max_depth_in > 0
  // MODIFIES: max_depth
  // EFFECTS:  Set max_depth to max_depth_in
  void set_max_depth(const int max_depth_in);

  // EFFECTS:  Render world to standard terminal
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

  // EFFECTS:  Calculate camera parameters from aspect_ratio and image_width
  void initalize();
  
  // EFFECTS:  Return random offest in pixel area
  Vector3d sample_pixel_offest() const;

  // EFFECTS:  Return random ray from camera to pixel
  Ray sample_pixel(const int i, const int j) const;

  // EFFECTS:  Return color of ray
  Color ray_color(const Ray &ray, const int depth, const Hittable &world) const;
};

#endif