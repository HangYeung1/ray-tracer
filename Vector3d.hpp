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

  // EFFECTS:  Return negative element-wise vector
  Vector3d operator-() const;

  // REQUIRES: 0 <= i <= 2
  // EFFECTS:  Return ith element
  double operator[](int i) const;

  // REQUIRES: 0 <= i <= 2
  // MODIFIES: e
  // EFFECTS:  Return reference ith element
  double & operator[](int i);

  // EFFECTS:  Add other to this element-wise
  //           Return new vector
  Vector3d operator+(const Vector3d &other) const;

  // EFFECTS:  Subtract other from this element-wise
  //           Return new vector
  Vector3d operator-(const Vector3d &other) const;

  // EFFECTS:  Scale this element-wise by scalar
  //           Return new vector
  Vector3d operator*(double scalar) const;

  // EFFECTS:  Scale this element-wise by elements of other
  //           Return new vector
  Vector3d operator*(const Vector3d &other) const;

  // REQUIRES: scalar != 0
  // EFFECTS:  Scale this element-wise by inverse of scalar
  //           Return new vector
  Vector3d operator/(double scalar) const;

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

  // EFFECTS:  Return squared magnitude of vector
  double length_squared() const;

  // EFFECTS:  Return magnitude of vector
  double length() const;

  // EFFECTS:  Return true if vector is close to 0 in all dimensions
  bool near_zero() const;

  // EFFECTS:  Return random vector with elements in [0, 1)
  static Vector3d random();

  // EFFECTS:  Return random vector with elements in [min, max)
  static Vector3d random(double min, double max);

 private:
  double e[3];
};

// Alias for geometric clarity
using Point3d = Vector3d;

// EFFECTS:  Scale this element-wise by scalar
//           Return new vector
// NOTE:     This enables communicativity
Vector3d operator*(double scalar, const Vector3d vec);

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

// EFFECTS:  Return random vector in unit sphere
Vector3d random_vector_in_unit_sphere();

// EFFECTS:  Return random unit vector
Vector3d random_unit_vector();

// EFFECTS:  Return random unit vector in the hemisphere of normal
Vector3d random_vector_on_hemisphere(const Vector3d &normal);

// EFFECTS:  Reflect vector about normal
Vector3d reflect(const Vector3d &vec, const Vector3d &normal);

#endif