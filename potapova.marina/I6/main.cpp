#include <iostream>
#include <iomanip>
#include "calculateAtanSum.h"
#include "printTable.h"

int main()
{
  stdout;
  double start = 0.0;
  double end = 0.0;
  double abs_error = 0.0;
  size_t num_max = 0;
  double step = 0.0;
  if (!(std::cin >> abs_error >> num_max >> start >> end >> step))
  {
    std::cerr << "Input error\n";
    return 1;
  }
  if (start > end || step <= 0)
  {
    std::cerr << "Wrong interval\n";
    return 1;
  }
  try
  {
    printTable(abs_error, num_max, start, end, step);
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }
  return 0;
}
