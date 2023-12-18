#ifndef INTERVAL_HPP
#define INTERVAL_HPP

#include <limits>

class Interval {
 public:
  // EFFECTS:  Initialize Interval to empty aka (inf, -inf)
  Interval()
    : minimum(std::numeric_limits<double>::infinity()),
      maximum(-std::numeric_limits<double>::infinity()) { }

  // EFFECTS:  Initialize Interval to minimum_in, max_in
  Interval(const double minimum_in, const double maximum_in)
    : minimum(minimum_in), maximum(maximum_in) { }

  // EFFECTS:  Return minimum
  double min() const {
    return minimum;
  }

  // EFFECTS:  Return maximum
  double max() const {
    return maximum;
  }

  // EFFECTS:  Determine if val is within [minimum, maximum]
  bool contains(const double val) const {
    return (minimum <= val) && (val <= maximum);
  }

  // EFFECTS:  Determine if val is within (minimum, maximum)
  bool surrounds(const double val) const {
    return (minimum < val) && (val < maximum);
  }

  static const Interval empty;
  static const Interval universe;

 private:
  double minimum;
  double maximum;
};

#endif