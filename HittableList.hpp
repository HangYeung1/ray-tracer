#ifndef HITTABLE_LIST_HPP
#define HITTABLE_LIST_HPP

#include <memory>
#include <vector>

#include "Hittable.hpp"
#include "Interval.hpp"

class HittableList : public Hittable {
 public:
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

  // EFFECTS:  Determine if ray hits any object within t_interval
  bool hit(const Ray &ray, const Interval &t_interval, 
           HitRecord &record) const override;

 private:
  std::vector<std::shared_ptr<Hittable>> objects;
};

#endif