#include <iostream>
#include "LengthMax.h"
#include "CountAfterMax.h"

int main()
{
  int value = 0;
  LengthMax max_length;
  CountAfterMax after_max_count;

  do
  {
    std::cin >> value;
    if (!std::cin)
    {
      std::cout << "input error" << "\n";
      return 1;
    }
    if (value == 0)
    {
      break;
    }
    max_length(value);
    after_max_count(value);
  }
  while (value && std::cin);

  std::cout << "LengthMax-" << max_length.length_max << '\n';
  std::cout << "CountAfterMax-" << after_max_count.count_after_max << '\n';
}
