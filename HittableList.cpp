#include "HittableList.hpp"

#include <memory>
#include <vector>

#include "Interval.hpp"

// Initalize empty HittableList
HittableList::HittableList() = default;

// Initalize HittableList with given object
HittableList::HittableList(std::shared_ptr<Hittable> object)
  : objects{object} { }

// Clear all objects from HittableList
void HittableList::clear() {
  objects.clear();
}

// Add given object to objects
void HittableList::add(std::shared_ptr<Hittable> object) {
  objects.push_back(object);
}

// Determine if ray hits this any object within t_interval
bool HittableList::hit(const Ray &ray, const Interval &t_interval, 
                       HitRecord &record) const {
  HitRecord temp_record;
  bool hit_detected = false;
  double closest_hit = t_interval.max();

  for(const std::shared_ptr<Hittable> &object : objects) {
    if(object->hit(ray, Interval(t_interval.min(), closest_hit), temp_record)) {
      hit_detected = true;
      closest_hit = temp_record.t;
      record = temp_record;
    }
  }

  return hit_detected;
}