#include <iostream>
#include <limits>
#include <cstddef>
#include "maxLengthAfterMaxValue.h"
#include "maxLengthDescSeq.h"

int main()
{
  int value = 0;
  int maxValue = std::numeric_limits< int >::min();
  std::cin >> value;
  if (!std::cin)
  {
    std::cout << "Inp error" << "\n";
    return 1;
  }
  int predValue = value;
  size_t count = 0;
  size_t maxCount = 0;
  size_t length = 1;
  size_t maxlength = 1;
  do
  {
    countMaxLengthAfterMaxValue(value, maxValue, count, maxCount);
    countMaxLengthDescSeq(value, predValue, length, maxlength);
    std::cin >> value;
  }
  while (value && std::cin);
  if (!std::cin)
  {
    std::cout << "Inp error" << "\n";
    return 1;
  }
  std::cout << maxlength << "\n" << maxCount;
}
