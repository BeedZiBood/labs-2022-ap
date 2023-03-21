#include <iostream>
#include "defineArcSin.h"
#include "printTable.h"

int main()
{
  const double step = 0.001;
  const double absError = 0.000001;
  double leftBorder = 0.0;
  double rightBorder = 0.0;
  unsigned numberMax = 0;

  std::cin >> leftBorder >> rightBorder >> numberMax;

  if (!std::cin)
  {
    std::cout << "incorrect input" << '\n';
    return 1;
  }

  try
  {
    printTable(std::cout, leftBorder, rightBorder, step, numberMax, absError);
  }
  catch (const std::exception& e)
  {
    std::cout << e.what() << '\n';
    return 1;
  }

  return 0;
}
