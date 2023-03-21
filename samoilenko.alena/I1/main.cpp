#include <iostream>
#include "LengthSame.h"
#include "LengthDecr.h"

int main()
{
  int maxLengthSame = 0;
  int maxLengthDecr = 0;
  int lengthSame = 1;
  int lengthDecr = 1;
  int predV = 0;
  int value = 0;

  do
  {
    std::cin >> value;
    lengthSame = lengthSameF(predV, value, lengthSame);
    if (lengthSame > maxLengthSame)
    {
      maxLengthSame = lengthSame;
    }

    lengthDecr = lengthDecrF (predV, value, lengthDecr);
    if (lengthDecr > maxLengthDecr)
    {
      maxLengthDecr = lengthDecr;
    }

    predV = value;
  }
  while (value && std::cin);
  std::cout << maxLengthDecr << "\n";
  std::cout << maxLengthSame << "\n";
}
