#include <iostream>
#include "CountMoreThanPrevious.h"
#include "CountSameAsMin.h"
int main()
{
  int value = 0;
  int predv = 0;
  size_t compare_count = 0;
  int minv = 0;
  size_t min_count = 0;
  do
  {
    predv = value;
    std::cin >> value;
    if (minv == 0)
    {
      minv = value;
    }
    try
    {
      compare_count = countMoreThanPrevious(predv, value, compare_count);
      min_count = countSameAsMin(minv, value, min_count);
    }
    catch (const std::overflow_error &e)
    {
      std::cout << e.what() << "\n";
      return 2;
    }
  }
  while (value && std::cin);
  if (!std::cin)
  {
    std::cout << "Error\n";
  }
  std::cout << "compare count:" << compare_count - 1;
  std::cout << "\nmin count:" << min_count;
}
