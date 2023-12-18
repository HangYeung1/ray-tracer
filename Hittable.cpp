#include "Hittable.hpp"

#include "Ray.hpp"

// REQUIRES: outward_normal is a unit vector
// MODIFIES: front_face, normal
// EFFECTS:  Set front_face and normal relative to outward_normal
void HitRecord::set_face_normal(const Ray &ray, 
                                const Vector3d &outward_normal) {
    front_face = dot(ray.direction(), outward_normal) < 0;
    normal = front_face ? outward_normal : -outward_normal;
}