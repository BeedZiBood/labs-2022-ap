#include "countmaxevenel.h"
#include <stdexcept>
#include <limits>

void CountMaxEvenEl::operator()(int el)
{
  const unsigned int maxUnsignedInt = std::numeric_limits< unsigned int >::max();
  if (!el)
  {
    return;
  }
  if (el % 2)
  {
    evenCount = 0;
  }
  else if (evenCount == maxUnsignedInt)
  {
    throw std::overflow_error("Overflow\n");
  }
  else
  {
    evenCount++;
    if (evenCount > maxEvenCount)
    {
      maxEvenCount = evenCount;
    }
  }
}
