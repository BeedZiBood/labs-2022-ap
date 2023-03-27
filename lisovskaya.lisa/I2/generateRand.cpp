#include "generateRand.h"
#include <cstdlib>
#include <ctime>
int *generateRand(int *newarr, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    newarr[i] = std::rand();
  }
  return newarr;
}
