#include <iostream>
#include <limits>
#include "CountLarge.h"
#include "LengthEvenCount.h"

int main()
{
  int curr_val = 0;
  const int min = std::numeric_limits< int >::min();
  CountLargest count_largest{ min, 0 };
  LenEvenCounter len_even_count{ 0, 0 };

  do
  {
    std::cin >> curr_val;
    if (!std::cin)
    {
      std::cout << "Invailed Input" << "\n";
      return 1;
    }
    if (curr_val == 0)
    {
      break;
    }
    try
    {
      count_largest(curr_val);
      len_even_count(curr_val);
    }
    catch (const std::overflow_error& e)
    {
      std::cout << e.what() << '\n';
      return 1;
    }
  }
  while (curr_val && std::cin);

  std::cout << "amount of elements: " << count_largest.count_amount << '\n';
  std::cout << "length even elements: " << len_even_count.count_len_even << "\n";
}
