#include "Hittable.hpp"

#include "Ray.hpp"

// Set front_face and normal relative to outward_normal
// Outward_normal should be a unit vector
void HitRecord::set_face_normal(const Ray &ray, 
                                const Vector3d &outward_normal) {
    front_face = dot(ray.direction(), outward_normal) < 0;
    normal = front_face ? outward_normal : -outward_normal;
}