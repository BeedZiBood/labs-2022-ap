#include <iostream>
#include <limits>
#include <cstddef>
int main()
{
  int n = 0;
  int numberBefore = 0;
  int currentNumber = 0;
  int numberAfter = 0;
  size_t smallerThanPrevBiggerThanNextCount = 0;
  int smallestNumber = std::numeric_limits< int >::max();
  size_t counter = 0;
  while (std::cin >> n && n != 0)
  {
    numberBefore = currentNumber;
    currentNumber = numberAfter;
    numberAfter = n;
    if (numberAfter == 0)
    {
      continue;
    }
    else
    {
      if (currentNumber < numberBefore && currentNumber > numberAfter)
      {
        ++smallerThanPrevBiggerThanNextCount;
      }
    }

    if (counter == 0)
    {
      counter++;
      continue;
    }
    else
    {
      if (currentNumber < smallestNumber)
      {
        smallestNumber = currentNumber;
      }
    }
  }
  std::cout << "Amount of numbers that are smaller than the previous one but bigger:  "
            << smallerThanPrevBiggerThanNextCount << std::endl;
  std::cout << "The smallest number (Excluding first and last): "
            << smallestNumber << std::endl;
  return 0;
}
