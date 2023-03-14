#include <iostream>
#include <stdexcept>
#include "printtable.h"

int main()
{
  double rb = 0.0;
  double lb = 0.0;
  unsigned nummax = 0;
  const double step = 0.2;
  const double error = 0.00001;
  std::cin >> lb >> rb >> nummax;
  if (!std::cin)
  {
    std::cout << "Error while writing\n";
    return 1;
  }
  if (lb >= rb)
  {
    std::cout << "Error\n";
    return 1;
  }
  try
  {
    printTable(std::cout, lb, rb, step, error, nummax);
  }
  catch (const std::invalid_argument& e)
  {
    std::cout << "Error: " << e.what() << "\n";
    return 1;
  }
}
