#include "Vector3d.hpp"

#include <cassert>
#include <cmath>
#include <iostream>

#include "Random.hpp"

// EFFECTS:  Initalize vector to 0
Vector3d::Vector3d()
  : Vector3d(0, 0, 0) { }

// EFFECTS:  Initalize vector to specified x, y, z
Vector3d::Vector3d(double x, double y, double z)
  : e{x, y, z} { }

// EFFECTS:  Return x element
double Vector3d::x() const {
  return e[0];
}

// EFFECTS:  Return y element
double Vector3d::y() const {
  return e[1];
}

// EFFECTS:  Return z element
double Vector3d::z() const {
  return e[2];
}

// EFFECTS:  Return negative element-wise vector
Vector3d Vector3d::operator-() const {
  return Vector3d(-e[0], -e[1], -e[2]);
}

// REQUIRES: 0 <= i <= 2
// EFFECTS:  Return ith element
double Vector3d::operator[](int i) const {
  assert(i >= 0 && i <= 2);
  return e[i];
}

// REQUIRES: 0 <= i <= 2
// MODIFIES: e
// EFFECTS:  Return reference ith element
double & Vector3d::operator[](int i) {
  assert(i >= 0 && i <= 2);
  return e[i];
}

// EFFECTS:  Add other to this element-wise
//           Return new vector
Vector3d Vector3d::operator+(const Vector3d &other) const {
  return Vector3d(e[0] + other.e[0], e[1] + other.e[1], e[2] + other.e[2]);
}

// EFFECTS:  Subtract other from this element-wise
//           Return new vector
Vector3d Vector3d::operator-(const Vector3d &other) const {
  return Vector3d(e[0] - other.e[0], e[1] - other.e[1], e[2] - other.e[2]);
}

// EFFECTS:  Scale this element-wise by scalar
//           Return new vector
Vector3d Vector3d::operator*(double scalar) const {
  return Vector3d(e[0] * scalar, e[1] * scalar, e[2] * scalar);
}

// REQUIRES: scalar != 0
// EFFECTS:  Scale this element-wise by inverse of scalar
//           Return new vector
Vector3d Vector3d::operator/(double scalar) const {
  assert(scalar != 0);
  return *this * (1 / scalar);
}

// MODIFIES: e
// EFFECTS:  Add other to this element-wise
//           Return reference to self
Vector3d & Vector3d::operator+=(const Vector3d &other) {
  e[0] += other.e[0];
  e[1] += other.e[1];
  e[2] += other.e[2];
  return *this;
}

// MODIFIES: e
// EFFECTS:  Subtract other from this element-wise
//           Return reference to self
Vector3d & Vector3d::operator-=(const Vector3d &other) {
  return *this += -other;
}

// MODIFIES: e
// EFFECTS:  Scale this element-wise by scalar
//           Return reference to self 
Vector3d & Vector3d::operator*=(double scalar) {
  e[0] *= scalar;
  e[1] *= scalar;
  e[2] *= scalar;
  return *this;
}

// REQUIRES: scalar != 0
// MODIFIES: e
// EFFECTS:  Scale this element-wise by inverse of scalar
//           Return reference to self 
Vector3d & Vector3d::operator/=(double scalar) {
  assert(scalar != 0);
  return *this *= (1 / scalar);
}

// EFFECTS:  Return squared magnitude of vector
double Vector3d::length_squared() const {
  return pow(e[0], 2) + pow(e[1], 2) + pow(e[2], 2);
}

// EFFECTS:  Return magnitude of vector
double Vector3d::length() const {
  return sqrt(length_squared());
}

// EFFECTS:  Return random vector with elements in [0, 1)
Vector3d Vector3d::random() {
  return Vector3d(random_double(), random_double(), random_double());
}

// EFFECTS:  Return random vector with elements in [min, max)
Vector3d Vector3d::random(double min, double max) {
  return Vector3d(random_double(min, max),
                  random_double(min, max),
                  random_double(min, max));

}

// EFFECTS:  Scale this element-wise by scalar
//           Return new vector
// NOTE:     This enables communicativity
Vector3d operator*(double scalar, const Vector3d vec) {
  return vec * scalar;
}

// EFFECTS:  Return true if lhs == rhs element-wise
bool operator==(const Vector3d &lhs, const Vector3d &rhs) {
  return lhs.x() == rhs.x() && lhs.y() == rhs.y() && lhs.z() == rhs.z();
}

// EFFECTS:  Return true if lhs != rhs element-wise
bool operator!=(const Vector3d &lhs, const Vector3d &rhs) {
  return !(lhs == rhs);
}

// MODIFIES: os
// EFFECTS:  Print vec element-wise to os
// EXAMPLE:  Vector3d(1, 2, 3) -> "1 2 3"
std::ostream& operator<<(std::ostream &os, const Vector3d &vec) {
  return os << vec.x() << ' ' << vec.y() << ' ' << vec.z();
}

// EFFECTS:  Return u dot v
double dot(const Vector3d &u, const Vector3d &v) {
  return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}

// EFFECTS:  Return u cross v
Vector3d cross(const Vector3d &u, const Vector3d &v) {
  return Vector3d(u.y() * v.z() - u.z() * v.y(),
                  u.z() * v.x() - u.x() * v.z(),
                  u.x() * v.y() - u.y() * v.x());
}

// EFFECTS:  Return unit vector of vec
Vector3d unit_vector(const Vector3d &vec) {
  return vec / vec.length();
}

// EFFECTS:  Return random vector in the unit sphere
Vector3d random_vector_in_unit_sphere() {
  Vector3d point = Vector3d::random(-1, 1);
  while (point.length_squared() > 1) {
    point = Vector3d::random(-1, 1);
  }
  return point;
}

// EFFECTS:  Return random unit vector
Vector3d random_unit_vector() {
  return unit_vector(random_vector_in_unit_sphere());
}

// EFFECTS:  Return random unit vector in the hemisphere of normal
Vector3d random_vector_on_hemisphere(const Vector3d &normal) {
  Vector3d on_unit_sphere = random_unit_vector();
  return (dot(on_unit_sphere, normal) > 0.0) ? on_unit_sphere : -on_unit_sphere;
}