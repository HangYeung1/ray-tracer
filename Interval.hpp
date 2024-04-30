#ifndef INTERVAL_HPP
#define INTERVAL_HPP

#include <limits>

class Interval {
 public:
  // Initialize Interval to empty aka (inf, -inf)
  Interval();

  // Initialize Interval to minimum_in, max_in
  Interval(const double minimum_in, const double maximum_in);

  // Return minimum
  double min() const;

  // Return maximum
  double max() const;

  // Determine if val is within [minimum, maximum]
  bool contains(const double val) const;

  // Determine if val is within (minimum, maximum)
  bool surrounds(const double val) const;

  // Clamp val to [minimum, maximum]
  double clamp(const double val) const;

  static const Interval empty;
  static const Interval universe;

 private:
  double minimum;
  double maximum;
};

#endif