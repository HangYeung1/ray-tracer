#include "Interval.hpp"

const Interval Interval::empty(std::numeric_limits<double>::infinity(),
                               -std::numeric_limits<double>::infinity());
const Interval Interval::universe(-std::numeric_limits<double>::infinity(),
                                  std::numeric_limits<double>::infinity());