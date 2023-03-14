#include "shenanigans.h"

int main()
{
  const double error = 0.0001;
  const double step = 0.01;
  double lb = 0;
  double rb = 0;
  size_t maxNum = 0;

  std::cin >> lb >> rb >> maxNum;
  if (!std::cin || lb <= -1 || rb >= 1 || rb < lb) {
    std::cerr << "Error: incorrect arguments";
    return 1;
  }

  try {
    printTable(std::cout, lb, rb, error, maxNum, step);
  }
  catch (const std::runtime_error & err) {
    std::cerr << "Error: " << err.what();
    return 2;
  }
}
