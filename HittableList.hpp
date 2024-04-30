#ifndef HITTABLE_LIST_HPP
#define HITTABLE_LIST_HPP

#include <memory>
#include <vector>

#include "Hittable.hpp"
#include "Interval.hpp"

class HittableList : public Hittable {
 public:
  // Initalize empty HittableList
  HittableList();

  // Initalize HittableList with given object
  HittableList(std::shared_ptr<Hittable> object);

  // Clear all objects from HittableList
  void clear();

  // Add given object to objects
  void add(std::shared_ptr<Hittable> object);

  // Determine if ray hits any object within t_interval
  bool hit(const Ray &ray, const Interval &t_interval, 
           HitRecord &record) const override;

 private:
  std::vector<std::shared_ptr<Hittable>> objects;
};

#endif