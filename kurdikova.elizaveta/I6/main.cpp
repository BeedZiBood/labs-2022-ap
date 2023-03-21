#include <iostream>
#include "resultTable.h"

int main()
{
  // Входные данные
  double absError = 0.1E-5; // Погрешность
  size_t numberMax = 0; // Макс. число слагаемых
  double left = 0;  // Интервал
  double right = 0; //
  double step = 0.01; // Шаг

  std::cout << "Enter the left and right boundaries of the interval that is included in (2, 3): ";
  std::cin >> left >> right;
  if (!std::cin)
  {
    std::cerr << "\nError! Failed to read parameter 'X'\n";
    return 1;
  }
  if (left >= right)
  {
    std::cerr << "\nError! Incorrect interval\n";
    return 1;
  }
  if (left <= 2 || right >= 3)
  {
    std::cerr << "Error! The entered interval is not included in the interval (2, 3)\n";
    return 1;
  }
  std::cout << "\nEnter the max number of terms of the Taylor's row:\n";
  std::cin >> numberMax;
  if (!std::cin)
  {
    std::cerr << "Error! Failed to read max terms count\n";
    return 1;
  }
  try
  {
    printTable(std::cout, left, right, step, numberMax, absError);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    return 2;
  }
  return 0;
}
