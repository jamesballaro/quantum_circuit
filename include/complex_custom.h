#ifndef COMPLEX_CUSTOM_H
#define COMPLEX_CUSTOM_H

#include <iostream>
#include <complex>

namespace complex_custom
{
  // Function to overload << operator for complex numbers
  std::ostream & operator<<(std::ostream &output, const std::complex<double> number);
}

#endif