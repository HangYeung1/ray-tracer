#ifndef HITTABLE_LIST_HPP
#define HITTABLE_LIST_HPP

#include <memory>
#include <vector>

#include "Hittable.hpp"

class HittableList : public Hittable {
 public:
  std::vector<std::shared_ptr<Hittable>> objects;

  // EFFECTS:  Initalize empty HittableList
  HittableList();

  // EFFECTS:  Initalize HittableList with given object
  HittableList(std::shared_ptr<Hittable> object);

  // MODIFIES: objects
  // EFFECTS:  Clear all objects from HittableList
  void clear();

  // MODIFIES: objects
  // EFFECTS:  Add given object to objects
  void add(std::shared_ptr<Hittable> object);

  // EFFECTS:  Determine if ray hits any object within (t_min, t_max)
  bool hit(const Ray &ray, const double t_min, const double t_max, 
           HitRecord &record) const override;
};

#endif