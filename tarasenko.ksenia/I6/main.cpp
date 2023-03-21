#include <iostream>
#include "printtable.hpp"

int main()
{
  double rightBorder = 0.0;
  double leftBorder = 0.0;
  unsigned numberMax = 0;
  const double step = 0.2;
  const double absError = 0.00001;
  std::cin >> leftBorder >> rightBorder >> numberMax;
  if (!std::cin)
  {
    std::cout << "Error\n";
    return 1;
  }
  if (leftBorder >= rightBorder)
  {
    std::cout << "Error: the interval is set incorrectly\n";
    return 1;
  }
  try
  {
    printTable(std::cout, leftBorder, rightBorder, step, absError, numberMax);
  }
  catch (const std::invalid_argument & e)
  {
    std::cout << "Error: ";
    std::cout << e.what() << "\n";
    return 1;
  }
}
