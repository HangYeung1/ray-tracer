#include "Vector3d.hpp"

#include <cmath>
#include <iostream>

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

// EFFECTS:  Return magnitude of vector
double Vector3d::length() const {
  return sqrt(pow(e[0], 2) + pow(e[1], 2) + pow(e[2], 2));
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

// EFFECTS:  Scale this element-wise by inverse of scalar
//           Return new vector
Vector3d Vector3d::operator/(double scalar) const {
  return *this * (1 / scalar);
}

// EFFECTS:  Return negative element-wise vector
Vector3d Vector3d::operator-() const {
  return Vector3d(-e[0], -e[1], -e[2]);
}

// REQUIRES: 0 <= i <= 2
// EFFECTS:  Return ith element
double Vector3d::operator[](int i) const {
  return e[i];
}

// REQUIRES: 0 <= i <= 2
// MODIFIES: e
// EFFECTS:  Return reference ith element
double & Vector3d::operator[](int i) {
  return e[i];
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

// MODIFIES: e
// EFFECTS:  Scale this element-wise by inverse of scalar
//           Return reference to self 
Vector3d & Vector3d::operator/=(double scalar) {
  return *this *= (1 / scalar);
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