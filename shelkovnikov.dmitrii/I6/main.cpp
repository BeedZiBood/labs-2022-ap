#include <iostream>
#include "sinh.h"
int main()
{
  double left = 0.0f, right = 0.0f;
  unsigned count = 0;
  std::cin >> left >> right >> count;
  if (!std::cin)
  {
    std::cout << "Error";
    return 1;
  }
  try
  {
    print_table(std::cout, left, right, 0.1f, 0.02f, count);
  }
  catch (const std::out_of_range &e)
  {
    std::cout << e.what();
    return 1;
  }
  return 0;
}
