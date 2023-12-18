#ifndef INTERVAL_HPP
#define INTERVAL_HPP

#include <limits>

class Interval {
 public:
  // EFFECTS:  Initialize Interval to empty aka (inf, -inf)
  Interval();

  // EFFECTS:  Initialize Interval to minimum_in, max_in
  Interval(const double minimum_in, const double maximum_in);

  // EFFECTS:  Return minimum
  double min() const;

  // EFFECTS:  Return maximum
  double max() const;

  // EFFECTS:  Determine if val is within [minimum, maximum]
  bool contains(const double val) const;

  // EFFECTS:  Determine if val is within (minimum, maximum)
  bool surrounds(const double val) const;

  // EFFECTS:  Clamp val to [minimum, maximum]
  double clamp(const double val) const;

  static const Interval empty;
  static const Interval universe;

 private:
  double minimum;
  double maximum;
};

#endif