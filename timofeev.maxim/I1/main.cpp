#include <iostream>
#include "amountofavr.hpp"
#include "amountofmin.hpp"

int main()
{
  MinValue mv{0};
  Average av{0};
  int value = 0;
  do
  {
    std::cin >> value;
    if (!std::cin)
    {
      std::cerr << "Error incorrect input \n";
    }
    try
    {
      mv(value);
      av(value);
    }
    catch (const std::overflow_error & e)
    {
      std::cout << e.what() << "\n";
      return 1;
    }
  }
  while (value && std::cin);
  std::cout << "Amount of number equal to minimum :" << mv.counter << "\n";
  std::cout << "Amount of number more than prev and less than next :" << av.counter1 << "\n";
}
