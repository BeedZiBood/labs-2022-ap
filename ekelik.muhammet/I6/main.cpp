#include <iostream>
#include <cmath>
#include <limits>
#include <stdexcept>
#include "printtable.h"

int main()
{
  const double absError = 0.0001;
  const double mStep = 0.1;
  double m1 = 0.0;
  double m2 = 0.0;
  size_t maxNumber = 0;

  std::cin >> m1 >> m2 >> maxNumber;
  if (!std::cin || m1 < -1.0 || m2 > 1.0 || m1 > m2)
  {
    std::cout << "Incorrect input\n";
    return 1;
  }
  try
  {
    printTable(std::cout, m1, m2, mStep, maxNumber, absError);
  }
  catch (const std::exception &e)
  {
    std::cout << e.what() << "\n";
    return 1;
  }
  return 0;
}
