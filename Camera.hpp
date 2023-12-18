#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Color.hpp"
#include "Hittable.hpp"

class Camera {
 public:
  // EFFECTS:  Initalize camera with default aspect ratio and image width
  Camera();

  // EFFECTS:  Render world to standard terminal
  void render(const Hittable &world);

 private:
  double aspect_ratio;
  int image_width;

  int image_height;
  Point3d center;
  Point3d pixel00_location;
  Vector3d pixel_delta_u;
  Vector3d pixel_delta_v;

  // REQUIRES: aspect_ratio_in > 0
  // MODIFIES: aspect_ratio
  // EFFECTS:  Set aspect_ratio to aspect_ratio_in
  void set_aspect_ratio(const double aspect_ratio_in);

  // REQUIRES: image_width_in > 0
  // MODIFIES: image_width
  // EFFECTS:  Set image_width to image_width_in
  void set_image_width(const int image_width_in);

  // EFFECTS:  Calculate camera parameters from aspect_ratio and image_width
  void initalize();

  // EFFECTS:  Return color of ray
  Color ray_color(const Ray &ray, const Hittable &world) const;
};

#endif