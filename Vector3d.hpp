#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

#include <iostream>

class Vector3d {
 public:
  // EFFECTS:  Initalize vector to 0
  Vector3d();

  // EFFECTS:  Initalize vector to specified x, y, z
  Vector3d(double x, double y, double z);

  // EFFECTS:  Return x element
  double x() const;

  // EFFECTS:  Return y element
  double y() const;
 
  // EFFECTS:  Return z element
  double z() const;

  // EFFECTS:  Return magnitude of vector
  double length() const;

  // EFFECTS:  Add other to this element-wise
  //           Return new vector
  Vector3d operator+(const Vector3d &other) const;

  // EFFECTS:  Subtract other from this element-wise
  //           Return new vector
  Vector3d operator-(const Vector3d &other) const;

  // EFFECTS:  Scale this element-wise by scalar
  //           Return new vector
  Vector3d operator*(double scalar) const;

  // REQUIRES: scalar != 0
  // EFFECTS:  Scale this element-wise by inverse of scalar
  //           Return new vector
  Vector3d operator/(double scalar) const;

  // EFFECTS:  Return negative element-wise vector
  Vector3d operator-() const;

  // REQUIRES: 0 <= i <= 2
  // EFFECTS:  Return ith element
  double operator[](int i) const;

  // REQUIRES: 0 <= i <= 2
  // MODIFIES: e
  // EFFECTS:  Return reference ith element
  double & operator[](int i);

  // MODIFIES: e
  // EFFECTS:  Add other to this element-wise
  //           Return reference to self
  Vector3d & operator+=(const Vector3d &other);

  // MODIFIES: e
  // EFFECTS:  Subtract other from this element-wise
  //           Return reference to self
  Vector3d & operator-=(const Vector3d &other);

  // MODIFIES: e
  // EFFECTS:  Scale this element-wise by scalar
  //           Return reference to self 
  Vector3d & operator*=(double scalar);

  // REQUIRES: scalar != 0
  // MODIFIES: e
  // EFFECTS:  Scale this element-wise by inverse of scalar
  //           Return reference to self 
  Vector3d & operator/=(double scalar);

 private:
  double e[3];
};

// Alias for geometric clarity
using Point3d = Vector3d;

// EFFECTS:  Return true if lhs == rhs element-wise
bool operator==(const Vector3d &lhs, const Vector3d &rhs);

// EFFECTS:  Return true if lhs != rhs element-wise
bool operator!=(const Vector3d &lhs, const Vector3d &rhs);

// MODIFIES: os
// EFFECTS:  Print vec element-wise to os
// EXAMPLE:  Vector3d(1, 2, 3) -> "1 2 3"
std::ostream& operator<<(std::ostream &os, const Vector3d &vec);

// EFFECTS:  Return u dot v
double dot(const Vector3d &u, const Vector3d &v);

// EFFECTS:  Return u cross v
Vector3d cross(const Vector3d &u, const Vector3d &v);

// EFFECTS:  Return unit vector of vec
Vector3d unit_vector(const Vector3d &vec);

#endif