#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

#include <iostream>

class Vector3d {
 public:
  // Initalize vector to 0
  Vector3d();

  // Initalize vector to specified x, y, z
  Vector3d(double x, double y, double z);

  // Return x element
  double x() const;

  // Return y element
  double y() const;
 
  // Return z element
  double z() const;

  // Return negative element-wise vector
  Vector3d operator-() const;

  // REQUIRES: 0 <= i <= 2
  // Return ith element
  double operator[](int i) const;

  // REQUIRES: 0 <= i <= 2
  // MODIFIES: e
  // Return reference ith element
  double & operator[](int i);

  // Add other to this element-wise
  //           Return new vector
  Vector3d operator+(const Vector3d &other) const;

  // Subtract other from this element-wise
  //           Return new vector
  Vector3d operator-(const Vector3d &other) const;

  // Scale this element-wise by scalar
  //           Return new vector
  Vector3d operator*(double scalar) const;

  // Scale this element-wise by elements of other
  //           Return new vector
  Vector3d operator*(const Vector3d &other) const;

  // REQUIRES: scalar != 0
  // Scale this element-wise by inverse of scalar
  //           Return new vector
  Vector3d operator/(double scalar) const;

  // MODIFIES: e
  // Add other to this element-wise
  //           Return reference to self
  Vector3d & operator+=(const Vector3d &other);

  // MODIFIES: e
  // Subtract other from this element-wise
  //           Return reference to self
  Vector3d & operator-=(const Vector3d &other);

  // MODIFIES: e
  // Scale this element-wise by scalar
  //           Return reference to self 
  Vector3d & operator*=(double scalar);

  // REQUIRES: scalar != 0
  // MODIFIES: e
  // Scale this element-wise by inverse of scalar
  //           Return reference to self 
  Vector3d & operator/=(double scalar);

  // Return squared magnitude of vector
  double length_squared() const;

  // Return magnitude of vector
  double length() const;

  // Return true if vector is close to 0 in all dimensions
  bool near_zero() const;

  // Return random vector with elements in [0, 1)
  static Vector3d random();

  // Return random vector with elements in [min, max)
  static Vector3d random(double min, double max);

 private:
  double e[3];
};

// Alias for geometric clarity
using Point3d = Vector3d;

// Scale this element-wise by scalar
//           Return new vector
// NOTE:     This enables communicativity
Vector3d operator*(double scalar, const Vector3d vec);

// Return true if lhs == rhs element-wise
bool operator==(const Vector3d &lhs, const Vector3d &rhs);

// Return true if lhs != rhs element-wise
bool operator!=(const Vector3d &lhs, const Vector3d &rhs);

// MODIFIES: os
// Print vec element-wise to os
// EXAMPLE:  Vector3d(1, 2, 3) -> "1 2 3"
std::ostream& operator<<(std::ostream &os, const Vector3d &vec);

// Return u dot v
double dot(const Vector3d &u, const Vector3d &v);

// Return u cross v
Vector3d cross(const Vector3d &u, const Vector3d &v);

// Return unit vector of vec
Vector3d unit_vector(const Vector3d &vec);

// Return random vector in unit sphere
Vector3d random_vector_in_unit_sphere();

// Return random unit vector
Vector3d random_unit_vector();

// Return random unit vector in the hemisphere of normal
Vector3d random_vector_on_hemisphere(const Vector3d &normal);

// Reflect vector about normal
Vector3d reflect(const Vector3d &vec, const Vector3d &normal);

#endif