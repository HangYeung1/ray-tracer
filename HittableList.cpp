#include "HittableList.hpp"

#include <memory>
#include <vector>

// EFFECTS:  Initalize empty HittableList
HittableList::HittableList() = default;

// EFFECTS:  Initalize HittableList with given object
HittableList::HittableList(std::shared_ptr<Hittable> object)
  : objects{object} { }

// MODIFIES: objects
// EFFECTS:  Clear all objects from HittableList
void HittableList::clear() {
  objects.clear();
}

// MODIFIES: objects
// EFFECTS:  Add given object to objects
void HittableList::add(std::shared_ptr<Hittable> object) {
  objects.push_back(object);
}

// EFFECTS:  Determine if ray hits this any object within (t_min, t_max)
bool HittableList::hit(const Ray &ray, const double t_min, const double t_max, 
                       HitRecord &record) const {
  HitRecord temp_record;
  bool hit_detected = false;
  double closest_hit = t_max;

  for(const std::shared_ptr<Hittable> &object : objects) {
    if(object->hit(ray, t_min, closest_hit, temp_record)) {
      hit_detected = true;
      closest_hit = temp_record.t;
      record = temp_record;
    }
  }

  return hit_detected;
}