#include <iostream>
#include "calculateAtanSum.h"
#include "printTable.h"

int main(int argc, const char* argv[])
{
  double start = 0.0;
  double end = 0.0;
  double abs_error = 0.0;
  size_t num_max = 0;
  double step = 0.0;
  std::cin >> abs_error >> num_max >> start >> end >> step;
  if (!std::cin)
  {
    std::cerr << "Wrong input\n";
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
  catch (std::logic_error& e)
  {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }
  return 0;
}
