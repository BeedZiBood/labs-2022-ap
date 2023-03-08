#include <iostream>
#include "QuantityLocalMin.h"
#include "QuantitySignChange.h"

int main()
{
  int current_val = 0;
  QuantityLocalMin LocalMin;
  QuantitySignChange SignChange;

  do
  {
    std::cin >> current_val;
    if (!std::cin)
    {
      std::cout << "Incorrect input" << "\n";
      return 1;
    }

    try
    {
      SignChange(current_val);
      LocalMin(current_val);
    }
    catch (const std::overflow_error& e)
    {
      std::cout << "Error..." << "\n";
      std::cout << e.what() << "\n";
      return 1;
    }
  }
  while (std::cin && current_val != 0);

  std::cout << "Number of local min: " << LocalMin.local_min << "\n";
  std::cout << "Number of sign changed: " << SignChange.sign_change << "\n";
}
