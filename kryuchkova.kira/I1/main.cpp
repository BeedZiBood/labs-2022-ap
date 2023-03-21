#include <iostream>
#include "sequences.h"

int main()
{
  int current_value = 1;
  MaxCounter max_counter;
  MinCounter min_counter;

  while (std::cin >> current_value && current_value)
  {
    try
    {
      max_counter(current_value);
      min_counter(current_value);
    }
    catch (const std::overflow_error &e)
    {
      std::cout << "Error:" << e.what() << "\n";
      return 2;
    }
  }

  if (!std::cin)
  {
    std::cout << "Invalid input." << "\n";
    return 1;
  }

  if (max_counter.count_max == 0 && min_counter.count_min == 0)
  {
    std::cout << "Empty sequence." << '\n';
    return 1;
  }
  else
  {
    std::cout << "amount max = " << max_counter.count_max << '\n' << "amount min = " << min_counter.count_min << '\n';
  }

  return 0;
}
