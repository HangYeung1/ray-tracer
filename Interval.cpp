#include "Interval.hpp"

// EFFECTS:  Initialize Interval to empty aka (inf, -inf)
Interval::Interval()
  : minimum(std::numeric_limits<double>::infinity()),
    maximum(-std::numeric_limits<double>::infinity()) { }

// EFFECTS:  Initialize Interval to minimum_in, max_in
Interval::Interval(const double minimum_in, const double maximum_in)
  : minimum(minimum_in), maximum(maximum_in) { }

// EFFECTS:  Return minimum
double Interval::min() const {
  return minimum;
}

// EFFECTS:  Return maximum
double Interval::max() const {
  return maximum;
}

// EFFECTS:  Determine if val is within [minimum, maximum]
bool Interval::contains(const double val) const {
  return (minimum <= val) && (val <= maximum);
}

// EFFECTS:  Determine if val is within (minimum, maximum)
bool Interval::surrounds(const double val) const {
  return (minimum < val) && (val < maximum);
}

const Interval Interval::empty(std::numeric_limits<double>::infinity(),
                               -std::numeric_limits<double>::infinity());
const Interval Interval::universe(-std::numeric_limits<double>::infinity(),
                                  std::numeric_limits<double>::infinity());