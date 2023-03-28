#include <iostream>
#include "printTable.h"
#include "countArth.h"

int main()
{
  double left = 0.0;
  double right = 0.0;
  unsigned members = 0;
  const double absError = 0.0001;
  const double step = 0.1;

  std::cout << "Enter left and right border that is included in (-1, 1): ";
  std::cin >> left >> right;
  if (!std::cin)
  {
    std::cerr << "\nError!\n";
    return 1;
  }
  if (left >= right)
  {
    std::cerr << "\nError! Incorrect interval\n";
    return 1;
  }
  std::cout << "Enter the maximum number of variables: ";
  std::cin >> members;
  if (!std::cin)
  {
    std::cerr << "\nError!\n";
    return 1;
  }
  try
  {
    printTable(std::cout, left, right, members, absError, step);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    return 2;
  }
  return 0;
}
